import random 
def gen_test():
	a = []
	for i in range(1000000):
		a.append(round(random.uniform(10, 100000), 4))
	return a
def write(filename, arr):
    	f = open(filename, "w")
    	print(*arr, file = f)
    	f.close()
for i in range(0, 10):
    	a = gen_test()
    	if i == 0:
        	a.sort()
    	elif i == 1:
        	a.sort()
        	a.reverse()
    	write("testcase{}.txt".format(i + 1), a)
