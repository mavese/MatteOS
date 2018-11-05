rm -f *.o kernel
nasm -f elf32 kernel.asm -o asmkernel.o
gcc -m32 -c kernel.c -o ckernel.o -ffreestanding
ld -m elf_i386 -T link.ld -o kernel asmkernel.o ckernel.o
qemu-system-i386 -kernel kernel -d guest_errors