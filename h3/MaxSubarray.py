
func = lambda x: x>0 and x or 0

# author: Ljsh
# parms : array 传入的数组
# date  : 2019/4/14
# PyVersion 3.6

def MaxSubArray(array):
    maxSum = 0
    thisSum = 0
    for i in range(len(array)):
        thisSum = func(thisSum+array[i])
        maxSum = max(thisSum,maxSum)
    return maxSum






