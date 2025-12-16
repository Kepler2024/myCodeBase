#def2
def print_twice(bruce):
    print(cat)      # ❌ 这里直接访问 cat，但 cat 对它来说是“陌生人”
    print(cat)

def cat_twice(part1, part2):
    cat = part1 + part2
    print_twice(cat)   # ❌ 直接调用，没有给参数，也没有传 cat

line1 = "Hello, "
line2 = "world!"

cat_twice(line1, line2)