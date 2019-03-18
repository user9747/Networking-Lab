import socket
import select 
import sys 
from thread import *

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port=8000

s.bind(('',port))

s.listen(5) 
list_of_clients = []
def clientThread(conn,addr):
    conn.send('Welcome')
    while True:
        message=conn.recv(1024)
        if message:
            print"[ "+ addr[0]+":"+str(addr[1]) +"  ] : "+message
            message_to_send = "<" + addr[0] +" : "+ str(addr[1]) + "> :" + message
            broadcast(message_to_send,conn)
        else:
            remove(conn)

def broadcast(message,conn):
    for client in list_of_clients:
        if client!=conn:
            client.send(message)

def remove(conn):
    if conn in list_of_clients:
        list_of_clients.remove(conn)

while True:
    conn,addr=s.accept()
    print ('Got Connection from',addr)
    list_of_clients.append(conn)
    start_new_thread(clientThread,(conn,addr))
    
    
conn.close()