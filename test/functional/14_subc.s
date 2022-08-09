.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =10
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v3, =2
	sub	v2, v1, v3
	str	v2, [sp, #-16]
	ldr	a1, [sp, #-16]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
