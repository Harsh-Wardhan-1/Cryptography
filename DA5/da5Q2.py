from tinyec import registry
from Crypto.Cipher import AES
import hashlib
import secrets
import binascii


def ecc_point_to_256_bit_key(point):
    sha = hashlib.sha256(int.to_bytes(point.x, 32, 'big'))
    sha.update(int.to_bytes(point.y, 32, 'big'))
    return sha.digest()


curve = registry.get_curve('brainpoolP256r1')
privateKey = secrets.randbelow(curve.field.n)
publicKey = privateKey * curve.g
print("Public Key: ")
print(publicKey)
print("\nPrivate Key: ")
print(privateKey)
