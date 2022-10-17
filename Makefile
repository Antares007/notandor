CC|=clang
CFLAGS+=-std=gnu99 -Wall -Wno-multichar -fno-stack-clash-protection -fno-stack-protector

src/echo.out: src/echo.c src/β.o
	${CC}    $^ -o $@ ${CFLAGS} -luv
src/main.out: src/main.c src/β.o
	${CC}    $^ -o $@ ${CFLAGS} -luv
src/main4.out: src/main4.c src/β4.o
	${CC}    $^ -o $@ ${CFLAGS} -luv

%.out: %.c
	${CC}    $^ -o $@ ${CFLAGS} -luv

%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}

clean:
	rm -f **/*.o **/*.out

.PHONY: clean
