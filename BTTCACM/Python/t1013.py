import sys
while True:
    try:
        n, m = map(int, sys.stdin.readline().split())
        t1, t2, t3, t4 = map(int, sys.stdin.readline().split())
        '''电梯在上面或者在同一层'''
        if(m >= n):
            time1 = (m - 1) * t1 + t2 * 2 + t3  #两次开门一次关门
            time2 = (n - 1) * t4
            if(time1 > time2):
                print(time2)
            else:
                print(time1)
        else:
            time1 = (n - m) * t1 + (n - 1) * t1 + t2 * 2 + t3
            time2 = (n - 1) * t4
            if(time1 > time2):
                print(time2)
            else:
                print(time1)
    except:
        break