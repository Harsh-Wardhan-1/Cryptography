from hashlib import sha1


def sxor(s1, s2):
    return ''.join(chr(ord(a) ^ ord(b)) for a, b, in zip(s1, s2))


def hmac(key, msg):
    blocksize = 160
    k = sha1(key.encode()).hexdigest()
    ipad = '4545454545454545134289771802437014237031'
    opad = 'QIEF342JL31J4L23KH4L412H4LK1H34HL123H44H'
    s1 = sxor(k, ipad)
    msg = msg+s1
    h = sha1(msg.encode()).hexdigest()
    s2 = sxor(k, opad)
    h = h+s2
    hmac = sha1(h.encode()).hexdigest()
    return(hmac)


if __name__ == '__main__':
    key = input("Enter the secret key: ")
    msg = input("Enter the msg to be transmitted: ")
    msg1 = input("Enter msg recived:")
    if(hmac(key, msg) == hmac(key, msg1)):
        print("Transmitted data is authentic ")
        print("HMAC value is: "+hmac(key, msg))
    else:
        print("Msg recived differs")
        print("HMAC of transmitted data is :"+hmac(key, msg))
        print("HMAC of recived data is :"+hmac(key, msg1))
