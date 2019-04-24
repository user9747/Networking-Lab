import socket
import sys
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1",8080))
print("Waiting to connect...")
while 1:
        comm=raw_input()
        s.send(comm)
        print("Server: "+s.recv(1024))
        if comm=='QUIT':
                s.close()
                break

