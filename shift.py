message='PXPXKXENVDRUXVTNLXHYMXGMAXYKXJNXGVRFXMAHWGXXWLEHGZXKVBIAXKMXQM'
LETTERS='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
FREQ='ETAOINSHRLDCUMWFGYPBVKJXQZ'
box=''
box2=[]
j=0
for q in FREQ:
    w=LETTERS.find(q)
    key=0
    box2.append(w)
    w=key
    print('KEYS:-'+str(box2)+'\n\n\n DECRYPTION:-')
    for key in box2:
        if len(box)==len(message):
            j=j+1
            print('***'*10)
            print(box)
    box=''
    for x in message:
        y=LETTERS.find(x)
        d=(y-key)%26
        a=LETTERS[d]
    box=box+str(a)