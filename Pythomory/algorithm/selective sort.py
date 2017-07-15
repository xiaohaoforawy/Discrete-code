# coding=utf-8
# selection_sort
from __future__ import print_function



def selection_sort(n, ):
    length=len(n)
    for i in range(length):
        least =i
        for k in range(i+1,length):
            if n[k]<n[least]:
                least=k
        n[least],n[i]=(
            n[i],n[least]
        )
    return n
if __name__=='__main__':
    import sys
    if sys.version_info.major<3:
        input_function = raw_input
    else:
        input_function = input

    user_input=input_function('enter numbers separated by a comma:')
    unsorted=[int(item) for item in user_input.split(',')]
    print(selection_sort(unsorted))
