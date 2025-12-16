#exercise 6.1
kimi = {
    'first_name' : 'Kimi',
    'last_name' : 'Kepler',
    'middle_name' : 'Cui',
    'fav_jobs' : 'Rider',
    }
print (kimi)
print ('\n')

fav_num = {
    'Sarah' : 1,
    'Kimi' : 2,
    'qappo' : 37,
    'luna' : 666,
    'Jensen' : 91,
}
for num in fav_num:
    print (f'{num}:\n\t{fav_num[num]}')