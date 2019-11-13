from socket import *

serverPort = 12000
serverName = "10.124.6.63"
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
filename = input("Enter the name of the file ")
clientSocket.send(filename.encode())
message = clientSocket.recv(1024)
print(message.decode())
clientSocket.close()

