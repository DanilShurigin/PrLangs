import socket

students = (
  "test", "first"
)

with socket.create_server(('', 7777)) as serversocket:
  while True:
    conn, addr = serversocket.accept()
    print('Client addr: ', addr)

    data = conn.recv(4096)
    name = data.decode()[:-1]
    print('Client sent: ', name)

    if (name in students):
      message = bytes(f"Hello, {name}\n".encode())
      print(f"{name} is present in students")
    else:
      message = bytes(b"Who are you?\n")
      print("Unknown name")
    
    print('-'*10)
    conn.send(message)
    conn.close()
