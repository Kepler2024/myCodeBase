# exercise 4.3
numbers = list(range(1,1_000_001))
print (min(numbers))
print (max(numbers))
print (sum(numbers))

# exercise 4.6
odds = list(range(1,20,2))
for odd in odds:
    print (odd)

#exercise 4.7
divides = list(range(3,30,3))
for divide in divides:
    print (divide)

#exercise 4.8
cubes = [cube**3 for cube in range(1,11)]
print (cubes)

#exercise 4.9
cubes_1=[]
for value_1 in range(1,11):
    value_2 = value_1**3
    cubes_1.append(value_2)
print (cubes_1)

#exercise 4.10
print(f"\nThe first three elements in this lists are:{cubes[0:3]}")
print(f"The three elements in the middle of this lists are:{cubes[4:7]}")
print(f"The last three elements in this lists are:{cubes[-3:]}")