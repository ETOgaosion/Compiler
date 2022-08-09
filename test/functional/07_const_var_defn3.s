.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =10
	str	v2, [sp, #-16]
	ldr	v2, =5
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
