import socket
import sys

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port = 8080
s.connect(('localhost',port))
s.send(sys.argv[1])
response = s.recv(1024)
print response
if(response =='Found'):
    file = open('recieve_'+ sys.argv[1] ,'wb')
    print "Recieving File......"
    while True:
        data = s.recv(1024)
        if not data:
            break
        file.write(data)
    file.close()
    print "File written at recieve_"+sys.argv[1]
else:
    print "File Not Found" 

s.close()