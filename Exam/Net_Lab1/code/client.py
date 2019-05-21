################Calender-Client
#Python2.7

###AUTHOR: Albin Antony
###Roll No:TVE16CS010

import socket
import sys
s=socket.socket()

s.connect((sys.argv[1],int(sys.argv[2])))



#Below code sends data to server based on the arguments got

if(sys.argv[4]== 'add'):
	s.send(sys.argv[3]+" "+sys.argv[4]+" "+sys.argv[5]+" "+sys.argv[6]+" "+sys.argv[7]+" "+sys.argv[8])
elif(sys.argv[4]== 'remove'):
	s.send(sys.argv[3]+" "+sys.argv[4]+" "+sys.argv[5])
if(sys.argv[4]== 'update'):
	s.send(sys.argv[3]+" "+sys.argv[4]+" "+sys.argv[5]+" "+sys.argv[6]+" "+sys.argv[7]+" "+sys.argv[8])
if(sys.argv[4]== 'get'):
	s.send(sys.argv[3]+" "+sys.argv[4]+" "+sys.argv[5])

print s.recv(1024)
s.close
