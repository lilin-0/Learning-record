import sys
Step = 0
while True:
    try:
        n = map(int, sys.stdin.readline().split())
        print("NNNN %d" % n)
        for i in range(n):
            print("IIIIII %d" % i)
            x = input()
            if i % 2 is True:
                if x % 2 is True:
                    Step += 1
            print(x)
    except:
        break
