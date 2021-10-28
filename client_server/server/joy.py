"""Simple example showing how to get gamepad events."""

from __future__ import print_function
import time
import socket
from inputs import get_gamepad


def main():
    
    host = '192.168.43.18'
    port = 1715  # initiate port no above 1024

    server_socket = socket.socket()  # get instance
# # look closely. The bind() function takes tuple as argument
    server_socket.bind((host, port))  # bind host address and port together
#
# # configure how many client the server can listen simultaneously
    server_socket.listen(2)
    conn, address = server_socket.accept()  # accept new connection
    print("Connection from: " + str(address))
    array =[500, 500, 0, 500, 0, 0]
    """Just print out some event infomation when the gamepad is used."""
    while 1:
        events = get_gamepad()
        for event in events:
            if event.ev_type != 'Sync':
            #     if(event.code == 'ABS_Z'):
            #         print(event.ev_type, event.code, event.state)
                # while keyboard.is_pressed("i"):
                if event.code == "ABS_RY":
                    if 0 <= array[1] < 1000:
                        array[1] = (event.state * 1000)/256  #changing range from 256 to 1000
                        # print("pitch -> ")
                        # print(array[1])
                        # print("\n")
                
                if event.code == "ABS_RX":
                    if 0 <= array[0] < 1000:
                        array[0] = (event.state * 1000)/256  #changing range from 256 to 1000
                        # print("roll -> ")
                        # print(array[0])
                        # print("\n")
                
                if event.code == "ABS_X":
                    if 0 <= array[3] < 1000:
                        array[3] = (event.state * 1000)/256 #changing range from 256 to 1000
                        # print("yaw -> ")
                        # print(array[3])
                        # print("\n")
                
                if event.code == "ABS_Y":
                    if 0 <= array[2] < 700:
                        array[2] = (event.state * 1000)/256 #changing range from 256 to 1000
                        # print("throttel -> ")
                        # print(array[2])
                        # print("\n")

                if event.code == "BTN_START":
                    if 0 <= array[4] <= 500:
                        array[4] = 1000
                        print("Armed !")
                        print("\n")
                    else :
                        array[4] = 0
                        print("disarmed !")
                        print("\n")


                data = str()
                data += "$"
                for i in range(6):
                    data += '-' + str(array[i])
                data+='-'
                data += '\r\n'
                # print(data)
                conn.send(data.encode())
                # print(data)
                # print("\n")
                time.sleep(0.01)


if __name__ == "__main__":
    main()

