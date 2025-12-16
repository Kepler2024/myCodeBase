# ex 8.6
def city_country(city,country):
    format = f'{city},{country}'
    return format

#ex 8.7 8.8
def make_album(name,singer,num=None):
    album = {'n':name,'s':singer}
    if num:
        album['nm'] = num
    return album

albums = []

while True:
    in_n = input('type name')
    if in_n == 'q':
        break
    in_s = input('type singer')
    if in_s == 'q':
        break
    album = make_album(in_n,in_s)
    albums.append(album)

print (albums)