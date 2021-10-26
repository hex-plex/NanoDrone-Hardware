import socket
import keyboard
import time

def server_program():
    # get the hostname
     host = '192.168.1.5'
     port = 9999  # initiate port no above 1024
    
     server_socket = socket.socket()  # get instance
    # # look closely. The bind() function takes tuple as argument
     server_socket.bind((host, port))  # bind host address and port together
    #
    # # configure how many client the server can listen simultaneously
     server_socket.listen(2)
     conn, address = server_socket.accept()  # accept new connection
     print("Connection from: " + str(address))
     print("\n\n\n\n")
     print("         w           i")
     print("       a s d       j k l")
     print("         x")
     print("hold the following keys :")
     print("w : throttle up      s : throttle zero        x : throttle up")
     print("a : yaw left         d : yaw right")
     print("i : pitch forward    k : pitch backward")
     print("j : roll left        l : roll right")
     array =[500, 500, 500, 0, 500, 500]
     while True:
        # receive data stream. it won't accept data packet greater than 1024 bytes
#        data = conn.recv(1024).decode()
#        if not data:
#            # if data is not received break
#            break
#        print("from connected user: " + str(data))

      
        while keyboard.is_pressed("i"):
            if 0 <= array[1] < 1000:
                array[1] += 50
                print("pitch -> ")
                print(array[1])
                print("\n")
                break
            # print("pitch up")
            # data = "pitch up"
            # #data+='\r\n'
            #conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("k"):
            if 0 < array[1] <= 1000:
                array[1] -= 50
                print("pitch -> ")
                print(array[1])
                print("\n")
                break
            # print("pitch down")
            # data = "pitch down"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("j"):
            if 0 <= array[0] < 1000:
                array[0] += 50
                print("roll -> ")
                print(array[0])
                print("\n")
                break
            # print("roll left")
            # data = "roll left"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("l"):
            if 0 < array[0] <= 1000:
                array[0] -= 50
                print("roll -> ")
                print(array[0])
                print("\n")
                break

            # print("roll right")
            # data = "roll right"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
            
        while keyboard.is_pressed("w"):
            if 0 <= array[3] < 700:
                array[3] += 50
                print("throttle -> ")
                print(array[3]/10)
                print("%")
                print("\n")
                break
            # print("throttle up")
            # data = "throttle up"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("s"):
            array[3] = 0
            print("throttle -> ")
            print(array[3]/10)
            print("%")
            print("\n")
                
        while keyboard.is_pressed("x"):
            if 0 < array[3] <= 1000:
                array[3] -= 50
                print("throttle -> ")
                print(array[3]/10)
                print("%")
                print("\n")
                break
            # print("throttle down")
            # data = "throttle down"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("a"):
            if 0 <= array[2] < 1000:
                array[2] += 50
                print("yaw -> ")
                print(array[2]/10)
                print("%")
                print("\n")
                break
            # print("yaw left")
            # data = "yaw left"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("d"):
            if 0 < array[2] <= 1000:
                array[2] -= 50
                print("yaw -> ")
                print(array[2]/10)
                print("%")
                print("\n")
                break
            # print("yaw right")
            # data = "yaw right"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        # if keyboard.is_pressed("x"):
        #     conn.close()

        data = str()
        data += "$"
        for i in range(6):
            data += '-' + str(array[i])
        data+='-'
        data += '\r\n'
        conn.send(data.encode())
        # print(data)
        # print("\n")
        time.sleep(0.1)



    # conn.close()  # close the connection


if __name__ == '__main__':
    server_program()
