import socket

SERVER_HOST = socket.gethostname()
SERVER_PORT = 8080
BUFFER_SIZE = 1024

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((SERVER_HOST, SERVER_PORT))

    message = input("Enter a message: ")
    client_socket.send(message.encode())

    converted_message = client_socket.recv(BUFFER_SIZE).decode()
    print(f"Uppercase message received: {converted_message}")

    client_socket.close()

if __name__ == "__main__":
    start_client()
