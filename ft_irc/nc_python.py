import socket
import time

def send_message(sock, message):
    sock.sendall((message + "\r\n").encode())

def main():
    HOST = '127.0.0.1'  # The server's hostname or IP address
    PORT = 4444         # The port used by the server
    NICK = 'any_nick'
    TARGET_NICK = NICK
    MESSAGE = "any"
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        
        # Send password
        send_message(s, "PASS 123")
        time.sleep(1)  # Give the server a moment to process
        
        # Set user
        send_message(s, "USER 1 1 1 1")
        time.sleep(1)  # Give the server a moment to process
        
        # Set nick
        send_message(s, f"NICK {NICK}")
        time.sleep(1)  # Give the server a moment to process
        
        # Send private message
        send_message(s, f"PRIVMSG {TARGET_NICK} :{MESSAGE}")
        time.sleep(1)  # Give the server a moment to process
        
        # Close connection
        s.close()

if __name__ == "__main__":
    main()