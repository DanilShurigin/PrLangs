import http.client
from html.parser import HTMLParser
import os

def get_charset(content_type):
  for content in content_type.split(','):
    _, _, param = content.strip().partition(';')
    if param:
      attr, value = param.strip().split('=')
      if (attr == 'charset'):
        return value
  return 'ISO-8859-1'

def download_img(href, path, conn):
  conn.request('GET', href)
  img_page = conn.getresponse()
  with open(path, 'bw') as img:
    img.write(img_page.read())
  print(f"Image '{href}' successfully downloaded.")

class ListingParser(HTMLParser):
  def __init__(self) -> None:
    HTMLParser.__init__(self)
    self.imgs = set()
    self.pages = set()

  def handle_starttag(self, tag, attrs) -> None:
    if (tag == 'img'):
      for key, value in attrs:
        if (key == 'src'):
          self.imgs.add(value)
          break
    elif (tag == 'a'):
      for key, value in attrs:
        if (key == 'href'):
          self.pages.add(value)
          break

def get_all_from_page(item:str, page_content:str) -> list:
  parser = ListingParser()
  parser.feed(page_content)

  if (item == 'img'):
    items = [img for img in parser.imgs]
  elif (item == 'page'):
    items = [page for page in parser.pages]
  else:
    items = []
  
  parser.close()
  return items

def read_page(conn, url) -> str:
  #print(f"Start reading {url} page.")
  conn.request('GET', url)
  page = conn.getresponse()
  
  charset = get_charset(page.getheader('Content-Type'))

  return page.read().decode(charset)

def download(url:str, path:str, only_here=True)->None:
  host = url.replace('//', '/').split('/')[1]

  connection = http.client.HTTPSConnection(host)

  pages = ['']
  if( not only_here ):
    pages += get_all_from_page('page', read_page(connection, url))
  
  print('Pages:', pages)
  images = list()

  for page in pages:
    images += get_all_from_page('img', read_page(connection, url+page))

  print(images)

  try:
    os.mkdir(path)
  except FileExistsError:
    print("Writing on already existing folder")
  
  for img in set(images):
    download_img(url+img, os.path.join(path, img), connection)

  connection.close()

if __name__ == '__main__':
  download('https://beda.pnzgu.ru/anatoly/', 'lab7_imgs', False)
  
