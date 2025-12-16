#exercise 5.8
names = ['admin','esther','luna','harry','yasuke']
if names:
    for name in names:
        if name == 'admin':
            print ('Hello, my master, please let me to lick you dick and' 
                    ' asshole.'
                   )
        else:
            print (f'Hello,{name.title()}.')
else:
    print ('No slaves to fuck.')
