#exercise 7.4
prompt = 'Type what you want.'
prompt += '\nType "quit" to quit.'
prompt += '\n'
active = True
while active:
    topping = input (prompt)
    if topping == 'quit':
        active = False
    else:
        print (f'You added {topping}.')
        print ('\n')