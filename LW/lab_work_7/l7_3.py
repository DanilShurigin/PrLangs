import http.client

connection = http.client.HTTPSConnection("beda.pnzgu.ru")

connection.request(
  'GET', '/anatoly/',
  headers={'Host': 'beda.pnzgu.ru',
           'User-agent': 'Python lab program'}
)

r = connection.getresponse()

print('Proto: ', r.version)
print('Code: ', r.status)
print('Status: ', r.reason)

print('------ HEADERS ------')
print(r.headers)

print('------- BODY --------')
print(r.read().decode())
connection.close()