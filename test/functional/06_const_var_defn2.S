.data
.globl	b
.type	b, %object
b:
	.word	0x5

.data
.globl	a
.type	a, %object
a:
	.word	0xa

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	a1, =b
	pop	{pc}
