#ex 7.9
name_prompt = "What's your name?"
name_prompt += '\n'
prompt = 'What kind of jobs do you want?'
prompt += '\n'

Jobs = {}

active = True

while active:
    name = input(name_prompt)
    job = input(prompt)
    Jobs[name] = job
    repeat = input('Do you or anybody want something else?')
    if repeat == 'no':
        active = False
    
for name,job in Jobs.items():
    print (f'{name.title()} wants {job.lower()}.')