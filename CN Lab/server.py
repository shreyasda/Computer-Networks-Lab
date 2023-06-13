import socket

SERVER_HOST = socket.gethostname()
SERVER_PORT = 8080
BUFFER_SIZE = 1024

def convert_to_uppercase(message):
    return message.upper()

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((SERVER_HOST, SERVER_PORT))
    server_socket.listen(1)
    print(f"Server listening on {SERVER_HOST}:{SERVER_PORT}")

    client_socket, client_address = server_socket.accept()
    print(f"Accepted connection from {client_address[0]}:{client_address[1]}")

    while True:
        data = client_socket.recv(BUFFER_SIZE)
        if not data:
            break
        message = data.decode()
        converted_message = convert_to_uppercase(message)
        client_socket.send(converted_message.encode())
        #client_socket.send(client_socket.recv(BUFFER_SIZE).decode().upper().encode())

    client_socket.close()
    server_socket.close()

if __name__ == "__main__":
    start_server()
