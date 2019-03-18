import socket
import datetime


s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

port=8080

s.bind(('',port))
while True:
    msg,addr=s.recvfrom(1024)
    print ('Got Connection from',addr)
    print'Message from Client: ',msg
    now = datetime.datetime.now()
    time = now.strftime("%H:%M:%S")
    bytesToSend   = str.encode(time)
    s.sendto(bytesToSend,addr)
