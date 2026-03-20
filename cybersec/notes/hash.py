import hashlib

string = "This is a secret message which contains classified intel"
hashed = hashlib.sha256(string.encode()).hexdigest()

print(hashed)