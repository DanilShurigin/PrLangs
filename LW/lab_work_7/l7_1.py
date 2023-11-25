import socketserver
import socket

students = (
  "TestStudent",
  "anotherStudent"
)

class TCPNameSearcher(socketserver.StreamRequestHandler):
  def handle(self) -> None:
    self.data = self.rfile.readline()
    print(f"{self.client_address} wrote:")

    name = self.data.decode()[:-1]

    if( name in students ):
      request = f"Hello, {name}!"
    else:
      request = "Who are you?"
    
    bytes_obj = bytes(request, encoding='utf-8')

    self.wfile.write(bytes_obj)

with socketserver.TCPServer(('', 7777), TCPNameSearcher) as server:
  server.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
  server.serve_forever()
