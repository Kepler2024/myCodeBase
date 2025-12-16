#ex 7.8
fuck_order = ['blowjob','rimjob','nipple play','rimjob','rimjob']
finished_order = []

print ('Rimming is not possible.')

active = True

while 'rimjob' in fuck_order:
    fuck_order.remove('rimjob')

while active:
    if fuck_order:
        pop_job = fuck_order.pop()
        finished_order.append(pop_job)
        print (f'I am doing a {pop_job} for you.')
    else:
        active = False

print(fuck_order)
print(finished_order)