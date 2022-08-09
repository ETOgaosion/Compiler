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
	ldr	v2, =1
	rsb	v1, v2, #0
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-12]
	ldr	v2, [sp, #-16]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-20]
	ldr	a1, [sp, #-20]
	add	sp, sp, #-24
	bl	putint
	add	sp, sp, #24
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
