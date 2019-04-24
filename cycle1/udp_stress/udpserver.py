import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

port=8080

s.bind(('',port))


msgFromServer       = "Hello UDP Client\n"

bytesToSend         = str.encode(msgFromServer)
total = 0
while True:
    msg,addr=s.recvfrom(1024000)
    # print ('Got Connection from',addr)
    # print'Message from Client: ',msg
    total= total + len(msg)
    print len(msg),total
    s.sendto(bytesToSend,addr)
