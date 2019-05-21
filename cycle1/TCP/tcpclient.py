
import socket

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.connect(('localhost',8080))

s.send("hello")

msg = s.recv(1024)
print msg
s.close()