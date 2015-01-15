#! /usr/bin/python3
import socket
import time
port = 8888
s=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(("",port))
while 1:
	s.sendto(b"b",("192.168.0.177",8888))
	data, addr = s.recvfrom(1024)
	f = open("test","w")
	f.write(str(int(data.decode())/9.31)[:5])
	f.close()
	time.sleep(2)
