''' For record the GSR and skine resistance value   '''
'''
This Code works with Arduino part code to record GSR (0-1023) and Skin Resistance value

Created by Clark wang
Date: 2017.8.29
Email: wxiguang@gmail.com

Version: 0.1
 '''
import serial
import datetime
import time

f=serial.Serial("/dev/cu.usbmodem14131",baudrate= 57600)
''' change to you device  when you use this one '''

filename1="WithGround_lab"+str(datetime.datetime.now().strftime("%Y%m%d-%H%M%S"))+".csv"


print datetime.datetime.now().ctime()



FILE1= open(filename1,"w")

while True:

  result=f.readline()
  #line = ("%.3f"%time.time()) + "," + result.replace(' ', '').replace(":", ",")
  line = ("%.3f"%time.time()) + "," + result.replace(' ', ',').replace("\n","")
  print line
  FILE1.write(line)
  FILE1.flush()
	
FILE1.close()
