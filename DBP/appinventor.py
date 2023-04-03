import time as t

time = int(t.time())
new_time = time + 5

for i in range(1000000):
    print(time)
    print(new_time)

    # while t.time() < new_time:
    #     print(int(t.time()))