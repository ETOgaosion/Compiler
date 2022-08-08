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
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =2
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v3, =a
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-16]
	ldr	a1, [sp, #-16]
	pop	{pc}
