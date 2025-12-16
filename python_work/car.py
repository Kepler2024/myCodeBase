#ex 8.14
def make_car(brand,model,**car_info):
    car_info['brand'] = brand
    car_info['model'] = model
    return car_info

car = make_car('BMW','M4',color = 'black')
print(car)