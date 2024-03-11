import socket
import math
import time

teleplotAddr = ("127.0.0.1",47269)
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def sendTelemetry(name, value):
    now = time.time() * 1000
    msg = name+":"+str(now)+":"+str(value)+"|g"
    sock.sendto(msg.encode(), teleplotAddr)

i=0
while i < 1000:
    
    sendTelemetry("sin", math.sin(i))
    sendTelemetry("cos", math.cos(i))
    # msg= 
    sock.sendto("gorets:1|c|@0.1".encode(), teleplotAddr)
    sock.sendto("trajectoryTimestamped:1:1:1627551892437;2:2:1627551892448;3:3:1627551892459|xy".encode(), teleplotAddr)
    sock.sendto("motor_4_state:Turned On|t".encode(), teleplotAddr)
    sock.sendto("3D|mySimpleCube:S:cube:P:1:1:1:R:0:0:0:W:2:H:2:D:2:C:#2ecc71".encode(), teleplotAddr)
    i+=0.1
    time.sleep(0.01)