.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-24]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =10
	str	v2, [sp, #-24]
	ldr	v2, =4
	str	v2, [sp, #-20]
	ldr	v2, =2
	str	v2, [sp, #-16]
	ldr	v2, =2
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-24]
	ldr	v2, [sp, #-20]
	mul	v3, v1, v2
	str	v3, [sp, #-36]
	ldr	v2, [sp, #-16]
	ldr	v3, [sp, #-36]
	add	v1, v2, v3
	str	v1, [sp, #-32]
	ldr	v1, [sp, #-32]
	ldr	v2, [sp, #-12]
	sub	v3, v1, v2
	str	v3, [sp, #-28]
	ldr	a1, [sp, #-28]
	add	sp, sp, #-40
	bl	putint
	add	sp, sp, #40
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
