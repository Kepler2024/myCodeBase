#ex 8.9
msgs1 = ['1','2']
sent1 = []
def show_msg():
    for msg in msgs:
        print (msg)

def send_mesagage(msgs,sent_msgs):
    for msg in msgs:
        print (f'sending {msg}')
    while msgs:
        sent = msgs.pop()
        sent_msgs.append(sent)

send_mesagage(msgs1[:],sent1)
print(msgs1)
print(sent1)