import socket

s = socket.socket()
print ("Socket successfully created")

port = 6969

s.bind(('', port))
print ("socket binded to %s" %(port))

s.listen(5)
print ("socket is listening")

while True:

        conn, addr = s.accept()
        while True:
                data = conn.recv(128)
                if not data:
                        break
                print(data)
