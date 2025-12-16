#exercise 7.4 条件测试
prompt = 'Type what you want.'
prompt += '\nType "quit" to quit.'
prompt += '\n'

topping = ''
while topping != 'quit':
    topping = input(prompt)
    if topping == 'quit':
        print ('Process ended.')
    else:
        print (f'You added {topping}.')
        print (f'\n')

