.data
.globl	a
.type	a, %object
a:
	.word	0x1

	.equ	ImmValue_1, 0x1

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v1, =ImmValue_1
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
