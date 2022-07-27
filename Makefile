CC|=clang
CFLAGS+=-std=gnu99 -Wall -Wno-multichar -fno-stack-clash-protection -fno-stack-protector

src/echo: src/echo.c src/goan.o
	${CC}    $^ -o $@ ${CFLAGS} -luv

%: %.c
	${CC}    $^ -o $@ ${CFLAGS} -luv

%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}

clean:
	rm -f src/*.o src/main src/echo

.PHONY: clean
