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
	ldr	v1, =a
	ldr	a1, [v1]
	ldr	a2, =5
	sub	sp, sp, #16
	bl	__aeabi_idiv
	add	sp, sp, #16
	mov	v1, a1
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
