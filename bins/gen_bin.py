print("bins_x86[256] = {")
print("// 1 unsorted bin + 62 small bins (total:63)")
print("  i_0:fd_unsb, i_1:bk_unsb,")

i = 2
for j in range(2, 64):
  print(f'  i_{i}:fd_{j*8}, i_{i+1}:bk_{j*8},')
  i += 2

x = 512
print("// 32 large bins of size 64 bytes")
for _ in range(1, 32+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 64
  i += 2

print("// 16 large bins of size 512 bytes")
for _ in range(1, 16+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 512
  i += 2

print("// 8 large bins of size 4096 bytes")
for _ in range(1, 8+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 4096
  i += 2

print("// 4 large bins of size 32768 bytes")
for _ in range(1, 4+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 32768
  i += 2

print("// 2 large bins of size 262144 bytes")
for _ in range(1, 2+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 262144
  i += 2

print("// 1 large bin of whatever size left")
print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
print("}\n\n")


print("bins_x64[256] = {")
print("// 1 unsorted bin + 62 small bins (total:63)")
print("  i_0:fd_unsb, i_1:bk_unsb,")

i = 2
for j in range(2, 64):
  print(f'  i_{i}:fd_{j*16}, i_{i+1}:bk_{j*16},')
  i += 2

x = 1024
print("// 32 large bins of size 64 bytes")
for _ in range(1, 32+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 64
  i += 2

print("// 16 large bins of size 512 bytes")
for _ in range(1, 16+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 512
  i += 2

print("// 8 large bins of size 4096 bytes")
for _ in range(1, 8+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 4096
  i += 2

print("// 4 large bins of size 32768 bytes")
for _ in range(1, 4+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 32768
  i += 2

print("// 2 large bins of size 262144 bytes")
for _ in range(1, 2+1):
  print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
  x = x + 262144
  i += 2

print("// 1 large bin of whatever size left")
print(f'  i_{i}:fd_{x}, i_{i+1}:bk_{x},')
print("}")
