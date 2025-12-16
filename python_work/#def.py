#def
def print_twice(text):
    print (text)
    print (text)

def cat_twice(part1,part2):
    cat = part1 + part2
    print_twice (cat)

line_1 = 'I Love'
line_2 = ' Rimjob'
cat_twice(line_1,line_2)

#ex 8.2
def fav_book(book):
    print (f'My favourite book is {book.upper()}.')

rimjob = 'rimjob'
fav_book (rimjob)
