import time
import datetime as dt
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii
from cryptography.hazmat.primitives import hashes

keyPair = RSA.generate(3072)
pubKey = keyPair.publickey()
pubKeyPEM = pubKey.exportKey()
privKeyPEM = keyPair.exportKey()


def validate(date_text):
    try:
        dt.datetime.strptime(date_text, '%Y/%m/%d')
    except Exception:
        exit("Incorrect data format, should be YYYY/MM/DD")


def processing():
    print("Processing")


def ask(value):
    print("Enter the following details:-")
    cc = str(input(f"{value} Number: "))
    if (len(cc) != 16):
        exit(f"[-] Invalid {value} Number")
    cvv = int(input("CVV: "))
    if cvv not in range(100, 1000):
        exit("[-] Invalid CVV")
    expiry = str(input("Expiry (YYYY/MM/DD) : "))
    validate(expiry)
    processing()
    lst = {}
    lst["CC"] = cc
    lst["CVV"] = cvv
    lst["Expiry"] = expiry
    return lst


def genDS(value):
    digitalSignature = []
    special = ["/", ",", "{", "}"]
    val = value
    val2 = ""
    for i in val:
        if i in special:
            val2 += "A"
            continue
        val2 += i
    val3 = hashes.SHA256()
    digitalSignature.append(str(val3))
    digitalSignature.append(str(val))
    print("\n\nDS: ", digitalSignature)
    return str(digitalSignature)


print("Select ")
print("1: Credit Card")
print("2: Debit Card")
print("Type 'Quit' for exiting")
response = ""

try:
    while(response != "quit"):
        response = str(input("Your Response: ")).lower()
        if(response == "1"):
            enc_msg333 = genDS(ask("Credit Card"))
            msg = b'enc_msg333'
            encryptor = PKCS1_OAEP.new(pubKey)
            encrypted = encryptor.encrypt(msg)
            print("\n\n")
            print("Encrypted:", binascii.hexlify(encrypted))
            exit()
        elif(response == "2"):
            enc_msg333 = genDS(ask("Debit Card"))
            msg = b'enc_msg333'
            encryptor = PKCS1_OAEP.new(pubKey)
            encrypted = encryptor.encrypt(msg)
            print("\n\n")
            print("Encrypted:", binascii.hexlify(encrypted))
            exit()
except FileNotFoundError:
    print("Invalid Input")
    exit()
