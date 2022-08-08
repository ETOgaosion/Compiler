.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =10
	str	v2, [sp, #-16]
	ldr	v2, =5
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-16]
	ldr	a2, [sp, #-12]
	sub	sp, sp, #24
	bl	__aeabi_idiv
	add	sp, sp, #24
	mov	v1, a1
	ldr	a1, [sp, #-20]
	add	sp, sp, #-24
	bl	putint
	add	sp, sp, #24
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
