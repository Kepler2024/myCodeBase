#3.4
dinner = ["Elon","Lucy","SSYY"]
print (f"you are invited:{dinner[0]}, {dinner[1]}, {dinner[2]}.")

#3.5
print (f"{dinner[0]} can not come.")
dinner[0] = "BIG BOOB"
print (f"you are invited:{dinner[0]}, {dinner[1]}, {dinner[2]}.")

#3.6
dinner.append("LLX")
dinner.insert(2,"FJY")
dinner.insert(0,"LWJ")
print (
    f"you are invited:{dinner[0]}, {dinner[1]}, {dinner[2]}, {dinner[3]}," 
    f"{dinner[4]}, {dinner[5]}."
)

#3.7
print ("Sorry, only two of you will come.")
print (f"Sorry, {dinner.pop(0)}, you can not come.")
print (f"Sorry, {dinner.pop(0)}, you can not come.")
print (f"Sorry, {dinner.pop(1)}, you can not come.")
print (f"Sorry, {dinner.pop(2)}, you can not come.")
print (f"Congrats, {dinner[0]}, you are still invited.")
print (f"Congrats, {dinner[1]}, you are still invited.")
print(len(dinner))
del dinner[0]
del dinner[0]
print (dinner)