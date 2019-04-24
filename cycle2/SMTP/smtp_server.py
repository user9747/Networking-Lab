import socket
import datetime
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("127.0.0.1",8080))
x=["albin@gmail.com","hello@gmail.com","jhondoe@gmail.com"]
s.listen(5)
conn,addr=s.accept()
while 1:
        mail=conn.recv(1024)
        tok=mail.split()
        print(mail)
        if tok[0]=='HELO':
                conn.send("250 mail.example.org")
        elif tok[0]=='MAILFROM:':
                flag1=0
                for i in x: #checking if mail is in the list
                        if tok[1]=="<"+i+">":
                                conn.send("250 Sender "+tok[1]+" OK")
                                flag1=1
                                break
                if flag1==0:
                        conn.send("421 Service Unavailable")
        elif tok[0]=='RCPTTO:':
                flag2=0
                for i in x: #checking if mail is in the list
                        if tok[1]=="<"+i+">":
                                conn.send("250 Recipient "+tok[1]+" OK")
                                flag2=1
                                break
                if flag2==0:
                        conn.send("421 Service Unavailable")
        elif tok[0]=='DATA':
                flag3=0
                if flag1==1 and flag2==1:
                        flag3=1
                        conn.send("354 Go Ahead, Enter data ending with <CRLF>.<CRLF>")
                        break
                else:
                        conn.send("421 Service Unavailable")




if flag3==1:
        buff=conn.recv(2048)
        print("Message: "+buff)
        conn.send("250 OK; Message Accepted")
mail=conn.recv(1024)
tok=mail.split()
if tok[0]=='QUIT':
        conn.send("221 mail.example.org")