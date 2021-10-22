import socket
import keyboard
import time

def server_program():
    # get the hostname
    host = '192.168.43.18'
    port = 9999  # initiate port no above 1024

    server_socket = socket.socket()  # get instance
    # look closely. The bind() function takes tuple as argument
    server_socket.bind((host, port))  # bind host address and port together

    # configure how many client the server can listen simultaneously
    server_socket.listen(2)
    conn, address = server_socket.accept()  # accept new connection
    print("Connection from: " + str(address))
    
    while True:
        # receive data stream. it won't accept data packet greater than 1024 bytes
        data = conn.recv(1024).decode()
        if not data:
            # if data is not received break
            break
        print("from connected user: " + str(data))
        while True:
            array =[500,500,500,500,500,500]
            # data = input(' -> ')
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client

            if keyboard.is_pressed("up"):
                array[0]+=200
                # print("pitch up")
                # data = "pitch up"
                # #data+='\r\n'
                #conn.send(data.encode())  # send data to the client
                # time.sleep(0.05)
            if keyboard.is_pressed("down"):
                array[0]-=200
                # print("pitch down")
                # data = "pitch down"
                # #data+='\r\n'
                # conn.send(data.encode())  # send data to the client
                # time.sleep(0.05)
            if keyboard.is_pressed("left"):
                array[1]+=200
                # print("roll left")
                # data = "roll left"
                # #data+='\r\n'
                # conn.send(data.encode())  # send data to the client
                # time.sleep(0.05)
            if keyboard.is_pressed("right"):
                array[1]-=200

                # print("roll right")
                # data = "roll right"
                # #data+='\r\n'
                # conn.send(data.encode())  # send data to the client
                # time.sleep(0.05)
            if keyboard.is_pressed("w"):
                array[2]+=200
                # print("throttle up")
                # data = "throttle up"
                # #data+='\r\n'
                # conn.send(data.encode())  # send data to the client
                # time.sleep(0.05)
            if keyboard.is_pressed("s"):
                array[2]-=200
                # print("throttle down")
                # data = "throttle down"
                # #data+='\r\n'
                # conn.send(data.encode())  # send data to the client
                # time.sleep(0.05)
            if keyboard.is_pressed("a"):
                array[3]+=200
                # print("yaw left")
                # data = "yaw left"
                # #data+='\r\n'
                # conn.send(data.encode())  # send data to the client
                # time.sleep(0.05)
            if keyboard.is_pressed("d"):
                array[3]-=200
                # print("yaw right")
                # data = "yaw right"
                # #data+='\r\n'
                # conn.send(data.encode())  # send data to the client
                # time.sleep(0.05)
            if keyboard.is_pressed("x"):
                conn.close()

            data =str()
            for i in range(6):
                data+=str(array[i])
            data+='\r\n'
            conn.send(data.encode())
            print(data)
            print("\n")
            time.sleep(0.3)



    conn.close()  # close the connection


if __name__ == '__main__':
    server_program()
