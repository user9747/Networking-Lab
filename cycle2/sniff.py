

import socket, sys
from struct import *

if(sys.argv[1]=="tcp"):
	try:
		s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_TCP)
	except socket.error , msg:
		print 'Socket could not be created. Error Code : ' + str(msg[0]) + ' Message ' + msg[1]
		sys.exit()
elif(sys.argv[1]=="udp"):
	try:
		s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_UDP)
	except socket.error , msg:
		print 'Socket could not be created. Error Code : ' + str(msg[0]) + ' Message ' + msg[1]
		sys.exit()
else:
	print "Specify protocol"


# receive a packet
while True:
	packet = s.recvfrom(65565)
	
	packet = packet[0]
	
	ip_header = packet[0:20]
	
	iph = unpack('!BBHHHBBH4s4s' , ip_header)
	
	version_ihl = iph[0]
	ihl = version_ihl & 0xF
	
	iph_length = ihl * 4
	

	s_addr = socket.inet_ntoa(iph[8]);
	d_addr = socket.inet_ntoa(iph[9]);
	
	print  ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr)
	
	tcp_header = packet[iph_length:iph_length+20]
	
	tcph = unpack('!HHLLBBHHH' , tcp_header)
	
	source_port = tcph[0]
	dest_port = tcph[1]
	acknowledgement = tcph[3]
	doff_reserved = tcph[4]
	tcph_length = doff_reserved >> 4
	
	print 'Source Port : ' + str(source_port) + ' Dest Port : ' + str(dest_port) + ' Acknowledgement : ' + str(acknowledgement)
	
	h_size = iph_length + tcph_length * 4
	data_size = len(packet) - h_size
	
	#get data from the packet
	data = packet[h_size:]
	
	print 'Data : ' + data
	print
