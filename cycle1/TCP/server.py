import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port=8080

s.bind(('',port))

s.listen(5) 

while True:
    c,addr=s.accept()
    print ('Got Connection from',addr)
    c.send('Thanks for connecting')
    c.close()