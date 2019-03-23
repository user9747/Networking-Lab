import socket
import sys

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port = 8080

s.connect((sys.argv[1],port))
s.send('Hai from client')
print s.recv(1024)

s.close()