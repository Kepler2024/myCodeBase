#exercise 5.10
current_users = ['sk','luna','harry','John','Dick']
new_users = ['Bily','Kay','Dulan','HARRY','Dick']
new_user_copy = []
current_users_copy = []
for users in current_users:
    current_users_copy.append(users.lower())
for user in new_users:
    new_user_copy.append(user.lower())
for user_lower in new_user_copy:
    if user_lower not in current_users_copy:
        print ('This user name is allowed to use.')
    elif user_lower in current_users_copy:
        print ('This user name is occupied.')
