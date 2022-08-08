.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	add	a1, v1, #3
	add	sp, sp, #-8
	bl	putint
	add	sp, sp, #8
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
