#exercise 7.4 条件测试2
prompt = 'Type what you want.'
prompt += '\nType "quit" to quit.'
prompt += '\n'

while True:
    topping = input(prompt)
    if topping == 'quit':
        print ('Process ended.')
        break
    else:
        print (f'You added {topping}.')
        print (f'\n')
