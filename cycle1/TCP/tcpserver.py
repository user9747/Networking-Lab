import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port=8080

s.bind(('',port))

s.listen(5) 

while True:
    c,addr=s.accept()
    message=c.recv(1024)
    print ('Got Connection from',addr)
    print message
    c.send('Thanks for connecting')
    c.close()