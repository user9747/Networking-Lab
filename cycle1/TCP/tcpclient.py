import socket

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port = 8080

s.connect(('127.0.0.1',port))
s.send('Hai from client')
print s.recv(1024)

s.close()