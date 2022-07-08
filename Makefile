CC|=clang
CFLAGS+=-std=gnu99 -Wall -Wno-multichar -fno-stack-clash-protection -fno-stack-protector

src/main: src/main.c
	${CC}    $^ -o $@ ${CFLAGS}

%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}

clean:
	rm -f src/*.o src/main

.PHONY: clean
