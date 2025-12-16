#exercise 5.11
numbers = list(range(1,10))
for n in numbers:
    if n == 1:
        print ('1st')
    elif n == 2:
        print ('2nd')
    elif n == 3:
        print ('3rd')
    elif n > 3:
        print (f'{n}th')