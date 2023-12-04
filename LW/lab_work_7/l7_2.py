import socket

students = (
  "test", "first"
)

with socket.socket(type=socket.SOCK_DGRAM) as serversocket:
  serversocket.bind(('', 7777))
  while True:
    data, addr = serversocket.recvfrom(4096)
    print('Client addr: ', addr)

    name = data.decode()[:-1]
    print('Client sent: ', name)

    if (name in students):
      message = bytes(f"Hello, {name}!\n".encode())
      print(f"{name} is present in students")
    else:
      message = bytes(b"Who are you?\n")
      print("Unknown name")
    
    print('-'*10)
    serversocket.sendto(message, addr)

