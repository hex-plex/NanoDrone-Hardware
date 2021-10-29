from time import sleep

i =0
while False:
    print("hello"+str(i)+"\n\rbye"+str(i),end='\r')
    i+=1
    sleep(0.1)
import curses
import time

def report_progress(filename, progress):
    """progress: 0-10"""
    stdscr.addstr(10, 0, "Moving file: {0}".format(filename), curses.color_pair(1))
    stdscr.addstr(12, 2, "Total progress: [{1:10}] {0}%".format(progress * 10, "#" * progress), curses.color_pair(2))
    stdscr.refresh()

if __name__ == "__main__":
    stdscr = curses.initscr()
    curses.start_color()
    curses.init_pair(1, curses.COLOR_RED, curses.COLOR_WHITE)
    curses.init_pair(2, curses.COLOR_GREEN, curses.COLOR_BLACK)
    curses.noecho()
    curses.cbreak()

    try:
        stdscr.addstr(0,0,"         w              i\n       a s d   f g    j k l\n         x              m\nhold the following keys :\nw : throttle up      s : throttle zero        x : throttle up\na : yaw left         d : yaw right\ni : pitch forward    k : pitch backward\nj : roll left        l : roll right\nf : arm drone        g : disarm\n")
        for i in range(10):
            report_progress("file_{0}.txt".format(i), i+1)
            time.sleep(0.5)
    finally:
        curses.echo()
        curses.nocbreak()
        curses.endwin()
        print(curses.has_colors())
