.data
.globl	a
.type	a, %object
a:
	.word	0x5

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =a
	ldr	v1, [v2]
	ldr	v3, =5
	mul	v2, v1, v3
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
