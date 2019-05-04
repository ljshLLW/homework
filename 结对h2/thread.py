from elevator import *

import threading

e1 = Elevator(1, 0, 10, 800)
e2 = Elevator(2, 1, 10, 800)
e3 = Elevator(3, 2, 10, 800)
e4 = Elevator(4, 0, 20, 2000)

elevators = [e1,e2,e3,e4]
# 创建线程
for e in elevators:
    t = threading.Thread(target=e.run)
    t.start()