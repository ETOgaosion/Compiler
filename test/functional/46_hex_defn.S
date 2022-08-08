.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =0
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
