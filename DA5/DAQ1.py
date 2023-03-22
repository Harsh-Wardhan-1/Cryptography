from hashlib import sha1
from Crypto.Util.number import *
from random import *


def mod_inverse(a, m):
    a = a % m
    for x in range(1, m):
        if((a*x) % m == 1):
            return(x)
    return(1)


def hash_function(message):
    hashed = sha1(message.encode("UTF-8")).hexdigest()
    return hashed


def parameter_generation():
    q = getPrime(5)
    # p is prime modulus
    p = getPrime(10)
    while((p-1) % q != 0):
        p = getPrime(10)
        q = getPrime(5)
    print("p is: ", p)
    print("q is: ", q)
    h = int(input("Enter integer between 1 and p-1(h): "))
    g = pow(h, int((p-1)/q)) % p
    print("Value of g is : ", g)
    return(p, q, g)


def per_user_key(p, q, g):
    x = randint(1, q-1)
    y = pow(g, x) % p
    return(x, y)


def signature(name, p, q, g, x):
    with open(name) as file:
        text = file.read()
    hash_component = hash_function(text)
    print("Hash of document sent is: ", hash_component)
    r = 0
    s = 0
    while(s == 0 or r == 0):
        k = randint(1, q-1)
        r = ((pow(g, k)) % p) % q
        i = mod_inverse(k, q)
        hashed = int(hash_component, 16)
        s = (i*(hashed+(x*r))) % q
    return(r, s, k)


def verification(name, p, q, g, r, s, y):
    with open(name) as file:
        text = file.read()
        hash_component = hash_function(text)
        print("Hash of document received is: ", hash_component)

    w = mod_inverse(s, q)
    hashed = int(hash_component, 16)
    u1 = (hashed*w) % q
    u2 = (r*w) % q
    v = ((pow(g, u1)*pow(y, u2)) % p) % q

    if(v == r):
        print("V is equal to r")
        print("The signature is valid!")
    else:
        print("V is not equal to r")
        print("The signature is invalid!")


global_var = parameter_generation()
keys = per_user_key(global_var[0], global_var[1], global_var[2])
# Sender's side (signing the document):
print()
file_name = input("Enter the name of document to sign: ")
components = signature(
    file_name, global_var[0], global_var[1], global_var[2], keys[0])
# Receiver's side (verifying the sign):
print()
file_name = input("Enter the name of document to verify: ")
verification(file_name, global_var[0], global_var[1],
             global_var[2], components[0], components[1], keys[1])
