CC|=clang
CFLAGS+=-std=gnu99 -Wall -Wno-multichar -fno-stack-clash-protection -fno-stack-protector -Wno-int-conversion

src/oars.out: src/oars.c src/oars_log.o
	${CC}    $^ -o $@ ${CFLAGS} -luv

%.out: %.c
	${CC}    $^ -o $@ ${CFLAGS} -luv

%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}

clean:
	rm -f **/*.o **/*.out

.PHONY: clean
