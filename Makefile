CC|=clang
CFLAGS+=-std=gnu99 -Wall -Wno-multichar -fno-stack-clash-protection -fno-stack-protector

src/echo.out: src/echo.c src/oan.o
	${CC}    $^ -o $@ ${CFLAGS} -luv
src/main.out: src/main.c src/oan.o
	${CC}    $^ -o $@ ${CFLAGS} -luv

%: %.c
	${CC}    $^ -o $@ ${CFLAGS} -luv

%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}

clean:
	rm -f **/*.o **/*.out

.PHONY: clean
