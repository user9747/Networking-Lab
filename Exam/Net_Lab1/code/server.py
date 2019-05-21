################Calender-Server
#Python2.7

###AUTHOR: Albin Antony
###Roll No:TVE16CS010

import socket

s=socket.socket()

s.bind(('',8080))

s.listen(5)
cal=[]
flag=0
while True:
	c,addr=s.accept()
	print "Connected" 
	str=c.recv(1024) 
	tok=str.split()
	
	
        if(tok[1]=='add'):   #Checking which method is used
		print "Adding Event "+tok[5]
		for event in cal:
                        if tok[2] in event and tok[0] in event :  #checking for duplicate entry
				flag=1
				break
		if(flag==1):
			c.send("Duplicate entry")
		else:
			cal.append(tok)              #adding event to the list
			c.send(tok[5]+" added to calender")
		
		flag=0		
                print cal
	elif(tok[1]=='remove'):
		print "Removing Event "+tok[2]
		for event in cal:
                        if tok[2] in event and tok[0] in event: #remove only if username and date match
				cal.remove(event)
				c.send(tok[2]+" removed")
				break		
                print cal
	elif(tok[1]=='update'):
		print "Updating Event "+tok[5]
		for event in cal:
                        if tok[2] in event and tok[0] in event: #update only if username and date match
				flag=1
 				cal.remove(event)
				break
		if(flag==1):
			cal.append(tok)
                   	c.send(tok[5]+" updated")
		else:
			print "No found"
		
		flag=0		
                print cal
	elif(tok[1]=='get'):
		print "Getting Event "+tok[2]
		for event in cal:
                        if tok[2] in event and tok[0] in event:  #get only if username and date match
				str=''
				for i in event:
					str=str+ " "+i
				c.send(str)
				break
		print cal

        if(str=='quit'):
		s.close()
		break
	c.close()  
