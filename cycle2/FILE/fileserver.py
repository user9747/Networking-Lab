import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port=8080

s.bind(('',port))

s.listen(5) 

while True:
    c,addr=s.accept()
    filename=c.recv(1024)
    print "Finding file : "+filename+"......"
    print ('Got Connection from',addr)
    try:
        file = open(filename,'rb')
        c.send('Found')
        print "File Found"
        data = file.read(1024)
        print "Reading File...."
        print "Sending..."
        while(data):
            c.send(data)
            data = file.read(1024)
        file.close()
        print "File closed"
        break
    except:
        c.send('No File')
        print "No file found"
        break
c.close()