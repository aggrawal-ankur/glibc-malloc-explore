# Macros Resolved

| Macro | Definition | x86 | x64 | INTERNAL_SIZE_T(4) (ptr:8 bytes) |
| :---- | :--------- | :-- | :-- | :------------------------------------- |
| INTERNAL_SIZE_T | `size_t`                  | 4 bytes | 8 bytes  | 4 bytes |
| SIZE_SZ         | `sizeof(INTERNAL_SIZE_T)` | 4 bytes | 8 bytes  | 4 bytes |
| CHUNK_HDR_SZ    | `(2 * SIZE_SZ)`           | 8 bytes | 16 bytes | 8 bytes |
| MIN_CHUNK_SIZE  | `(offsetof(struct malloc_chunk, fd_nextsize))` | 16 bytes | 32 bytes | 24 bytes |
| MALLOC_ALIGNMENT  | `2 * SIZE_SZ` | 8 bytes | 16 bytes | 8 bytes |
| MALLOC_ALIGN_MASK | `(MALLOC_ALIGNMENT - 1)` | 7 bytes | 15 bytes | 7 bytes |
| MINSIZE | | 16 bytes | 32 bytes |