import socket

msgFromClient       = "Hello UDP Server\n"

bytesToSend         = str.encode(msgFromClient)

s= socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

port = 8080

s.sendto(bytesToSend,('127.0.0.1',port))
msgFromServer=s.recvfrom(1024)
# msg = "Message from Server:  {}".format(msgFromServer[0])
print"Message from Server: ",msgFromServer[0]
s.close()