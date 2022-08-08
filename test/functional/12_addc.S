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
	ldr	v3, =a
	ldr	v2, [v3]
	add	v1, v2, #5
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
