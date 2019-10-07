import os 
import secket 
import threading 
import socketserver 

SERVER_HOST = 'localhost'
SERVER_PORT = 0 # tells the kernel to pickup a port dynamically
BUF_SIZE = 1024

def client(ip, port, message):
    ''' A client to test threading mixin server '''
    # Connect to the server 
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((ip, port))
    try:
        sock.sendall(bytes(message, 'utf-8'))
        response = sock.recv(BUF_SIZE)
        print('Client received: %s' % reponse)
    finally:
        sock.close()

