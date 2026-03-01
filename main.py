for i in range(1, 64):
  print(f'fd_{i*8}, bk_{i*8}')

x = 512
for i in range(1, 32+1):
  print(f'fd_{x}, bk_{x}')
  x = x + 64

x = 2560
for i in range(1, 16+1):
  print(f'fd_{x}, bk_{x}')
  x = x + 512

x = 10752
for i in range(1, 8+1):
  print(f'fd_{x}, bk_{x}')
  x = x + 4096

x = 43520
for i in range(1, 4+1):
  print(f'fd_{x}, bk_{x}')
  x = x + 32768

x = 174592
for i in range(1, 2+1):
  print(f'fd_{x}, bk_{x}')
  x = x + 262144
