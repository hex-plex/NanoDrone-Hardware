import socket
import keyboard
import time
import curses
def server_program():
    # get the hostname
     host = '192.168.43.18'
     port = 1715  # initiate port no above 1024
    
     server_socket = socket.socket()  # get instance
    # # look closely. The bind() function takes tuple as argument
     server_socket.bind((host, port))  # bind host address and port together
    #
    # # configure how many client the server can listen simultaneously
     server_socket.listen(2)
     conn, address = server_socket.accept()  # accept new connection
    #  print("Connection from: " + str(address))
    #  print("\n\n\n\n")
    #  print("         w              i")
    #  print("       a s d   f g    j k l")
    #  print("         x              m")
    #  print("hold the following keys :")
    #  print("w : throttle up      s : throttle zero        x : throttle up")
    #  print("a : yaw left         d : yaw right")
    #  print("i : pitch forward    k : pitch backward")
    #  print("j : roll left        l : roll right")
    #  print("f : arm drone        g : disarm")
     stdscr.addstr(0,0,"\t\tConnection from: " + str(address) + "\n\n\n\n\t\t         w              i\n\t\t       a s d   f g    j k l\n\t\t         x              m\n\t\thold the following keys :\n\t\tw : throttle up      s : throttle zero        x : throttle up\n\t\ta : yaw left         d : yaw right\n\t\ti : pitch forward    k : pitch backward\n\t\tj : roll left        l : roll right\n\t\tf : arm drone        g : disarm\n\t\t")
     shift_x = 1+4+10   
     array =[500, 500, 0, 500, 0, 0]
     first = True
     while True:
        # receive data stream. it won't accept data packet greater than 1024 bytes
#        data = conn.recv(1024).decode()
#        if not data:
#            # if data is not received break
#            break
#        print("from connected user: " + str(data))

        change = False
        while keyboard.is_pressed("i"):
            if 0 <= array[1] < 1000:
                change = True
                array[1] += 50
                # print("pitch -> ")
                # print(array[1])
                # print("\n")
                break
            # print("pitch up")
            # data = "pitch up"
            # #data+='\r\n'
            #conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("m"):
            if 0 < array[1] <= 1000:
                change = True
                array[1] -= 50
                # print("pitch -> ")
                # print(array[1])
                # print("\n")
                break
            # print("pitch down")
            # data = "pitch down"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("l"):
            if 0 <= array[0] < 1000:
                change = True
                array[0] += 50
                # print("roll -> ")
                # print(array[0])
                # print("\n")
                break
            # print("roll left")
            # data = "roll left"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("j"):
            if 0 < array[0] <= 1000:
                change = True
                array[0] -= 50
                # print("roll -> ")
                # print(array[0])
                # print("\n")
                break

            # print("roll right")
            # data = "roll right"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
            
        while keyboard.is_pressed("w"):
            if 0 <= array[2] < 1000:
                change = True
                array[2] += 50
                # print("throttle -> ")
                # print(array[2]/10)
                # print("%")
                # print("\n")
                break
            # print("throttle up")
            # data = "throttle up"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("s"):
            change = True
            array[2] = 0
            # print("throttle -> ")
            # print(array[2]/10)
            # print("%")
            # print("\n")
                
        while keyboard.is_pressed("x"):
            if 0 < array[2] <= 1000:
                change = True
                array[2] -= 50
                # print("throttle -> ")
                # print(array[2]/10)
                # print("%")
                # print("\n")
                break
            # print("throttle down")
            # data = "throttle down"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("a"):
            if 0 <= array[3] < 1000:
                change = True
                array[3] += 50
                # print("yaw -> ")
                # print(array[3]/10)
                # print("%")
                # print("\n")
                break
            # print("yaw left")
            # data = "yaw left"
            # #data+='\r\n'
            # conn.send(data.encode())  # send data to the client
            # time.sleep(0.05)
        while keyboard.is_pressed("d"):
            if 0 < array[3] <= 1000:
                change = True
                array[3] -= 50
                # print("yaw -> ")
                # print(array[3]/10)
                # print("%")
                # print("\n")
                break

        while keyboard.is_pressed("f"):
            if 0 <= array[4] <= 500:
                change = True
                array[4] = 1000
                # print("Armed !")
                # print("\n")
                break

        while keyboard.is_pressed("g"):
            if 1000 >= array[4] > 500:
                change = True
                array[4] = 0
                # print("disarmed !")
                # print("\n")
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
        if change or first:
            cp = 1
            if(array[4]>500):
                cp = 2
            stdscr.addstr(shift_x+0,0, "\t\t\tArmed!!!!" if array[4]>500 else "\t\t\tDisarmed..", curses.color_pair(cp))
            stdscr.addstr(shift_x+1,0, "\t\t\tThrottle : "+str(array[2]//10), curses.color_pair(cp))
            stdscr.addstr(shift_x+1,55,"Roll  : "+str(int((array[0]-500)/10)), curses.color_pair(cp))
            stdscr.addstr(shift_x+2,0, "\t\t\tYaw      : "+str(array[2]//10), curses.color_pair(cp))
            stdscr.addstr(shift_x+2,55,"Pitch : "+str(int((array[1]-500)/10)),curses.color_pair(cp))
            stdscr.refresh()
        first = False
        # print(data)
        conn.send(data.encode())
        # print(data)
        # print("\n")
        time.sleep(0.1)



    # conn.close()  # close the connection


if __name__ == '__main__':
    try:
        stdscr = curses.initscr()
        curses.start_color()
        curses.init_pair(1, curses.COLOR_RED, curses.COLOR_WHITE)
        curses.init_pair(2, curses.COLOR_GREEN, curses.COLOR_BLACK)
        curses.noecho()
        curses.cbreak()
    
        server_program()
    finally:
        curses.echo()
        curses.nocbreak()
        curses.endwin()


