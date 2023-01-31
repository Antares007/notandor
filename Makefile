CC|=clang
CFLAGS+=-std=gnu99 -Wall -Wno-multichar -fno-stack-clash-protection -fno-stack-protector -Wno-int-conversion
OBJCOPY=objcopy

src/nn.out: src/nn.c
	${CC}    $^ -o $@ ${CFLAGS} -lm
src/nn_xor.out: src/nn_xor.c
	${CC}    $^ -o $@ ${CFLAGS} -lm

src/word.out: src/word.c
	${CC}    $^ -o $@ ${CFLAGS}
	
src/gui.out: src/gui.c
	${CC}    $^ -o $@ ${CFLAGS} -lraylib

src/samples.out: src/samples.c src/oars_log.o
	${CC}    $^ -o $@ ${CFLAGS} -luv
src/oars.out: src/oars.c src/oars_log.o
	${CC}    $^ -o $@ ${CFLAGS} -luv

%.out: %.c
	${CC}    $^ -o $@ ${CFLAGS} -luv

%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
%.bin: %.asm
	nasm -f bin $^ -o $@
%.ring: %.c
	${CC} -c $^ -o $@ ${CFLAGS} -DPITH -ffreestanding -O3
	@${LD} -T pith.ld $@ -o $@.elf
	@${OBJCOPY} -O binary -j .text.* -j .text -j .data $@.elf $@.binp
	@head -c -1 $@.binp > $@
	@rm $@.binp $@.elf 
%.pith: %.ring src/goto.bin
	cat $^ > $@
clean:
	rm -f **/*.o **/*.out **/*.pith **/*.ring **/*.bin

.PHONY: clean
