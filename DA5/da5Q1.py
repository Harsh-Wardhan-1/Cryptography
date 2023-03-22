from Crypto.PublicKey import RSA
from Crypto.Signature.pkcs1_15 import PKCS115_SigScheme
from Crypto.Hash import SHA256
import binascii


keyPair = RSA.generate(bits=1024)
pubKey = keyPair.publickey()


def Signature_verification():
    verifier = PKCS115_SigScheme(pubKey)
    try:
        verifier.verify(hash, signature)
        print("Signature is valid.")
    except:
        print("Signature is invalid.")


# Making a Signature For the text File

with open(r'E:\Cryptography\DA5\text.txt', 'rb') as f:
    msg = f.read()
f.close()
hash = SHA256.new(msg)
signer = PKCS115_SigScheme(keyPair)
signature = signer.sign(hash)
print("Signature:", binascii.hexlify(signature))
# Checking the non altered file initially
with open(r'E:\Cryptography\DA5\text.txt', 'rb') as f:
    msg = f.read()
f.close()
hash = SHA256.new(msg)
Signature_verification()


t = input("Once the file has been altered,press enter: ")
# Checking After the file alteration
with open(r'E:\Cryptography\DA5\text.txt', 'rb') as f:
    msg = f.read()
f.close()
hash = SHA256.new(msg)
Signature_verification()
input()
