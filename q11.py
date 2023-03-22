from decimal import Decimal


def gcd(m, n):
    if n == 0:
        return m
    else:
        return gcd(n, m % n)


# input variables
p = input()
q = input()
no = input()
# calculate n
n = p*q
# calculate totient
totient = (p-1)*(q-1)
# calculate K
for k in range(2, totient):
    if gcd(k, totient) == 1:
        break


for i in range(1, 10):
    x = 1 + i*totient
    if x % k == 0:
        d = int(x/k)
        break
local_cipher = Decimal(0)
local_cipher = pow(message, k)
cipher_text = ctt % n

decrypt_t = Decimal(0)
decrypt_t = pow(cipher_text, d)
decrpyted_text = decrypt_t % n

print('n = '+str(n))
print(' k = '+str(k))
print(' totient = '+str(t))
print(' d = '+str(d))
print('cipher text = '+str(ct))
print(' decrypted text = '+str(dt))
