FROM debian:trixie

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
  build-essential \
  gawk bison \
  texinfo sed \
  gcc gdb \
  git python3 \
  vim nano

RUN git clone --shallow-since=2025-12-01 https://sourceware.org/git/glibc.git /glibc && \
  cd /glibc && \
  git checkout glibc-2.43

RUN mkdir /glibc-build && cd /glibc-build && \
  /glibc/configure \
    --prefix=/opt/glibc-2.43 \
    --disable-werror && \
    make -j$(nproc) && \
    make install

RUN mkdir /experiment-dir && cd /experiment-dir && \
  echo '#!/bin/bash' > build && chmod u+x build && \ 
  echo  "gcc \$1 -o run    -Wl,--rpath=/opt/glibc-2.43/lib    -Wl,--dynamic-linker=/opt/glibc-2.43/lib/ld-linux-x86-64.so.2" >> build && \
  echo "GLIBC_TUNABLES=glibc.malloc.tcache_count=0 gdb ./\$2" >> build

