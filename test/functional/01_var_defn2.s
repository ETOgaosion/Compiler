.data
.globl	b
.type	b, %object
b:
	.word	0x5

.data
.globl	a
.type	a, %object
a:
	.word	0x3

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =5
	str	v2, [sp, #-12]
	ldr	v2, [sp, #-12]
	ldr	v4, =b
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-16]
	ldr	a1, [sp, #-16]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
