import socket
import select 
import sys 
from thread import *

s= socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port = 8000
s.connect((sys.argv[1],port))
def sendMessage(so):
    while True:
        message=raw_input()
        so.send(message)

start_new_thread(sendMessage,(s,))
while True:  
    data = s.recv(1024)
    if data:
        print data


s.close()