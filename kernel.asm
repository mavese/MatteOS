bits		32
section	.text
	align	4
	dd		0x1BADB002 				; This is the magic number required by GRUB
	dd 		0x00 	   				; Flags
	dd		- (0x1BADB002 + 0x00)	; Checksum should be zero

	global _start
	extern kmain

	_start:
		cli
		mov esp, stackBuffer
		call kmain
		hlt



section	.bss
	resb 20480			; Declaring space for a the stack currently only 20KB
	stackBuffer: