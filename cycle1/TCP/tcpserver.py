import socket

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.bind(('localhost',8080))

s.listen(5)

c,addr=s.accept()

print addr

msg = c.recv(1024)

print msg
c.send("poda")

c.close()
s.close()

