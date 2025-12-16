#ex 7.5
prompt = 'How old are you?'
prompt += '\n'

active = True

while active:
    age = input(prompt)
    age = int(age)
    if age < 3:
        print ('free')
    elif age < 12:
        print ('10 dollar')
    else:
        print ('15 dollar')