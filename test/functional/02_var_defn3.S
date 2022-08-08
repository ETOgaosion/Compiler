.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =1
	str	v2, [sp, #-20]
	ldr	v2, =2
	str	v2, [sp, #-16]
	ldr	v2, =3
	str	v2, [sp, #-12]
	ldr	v2, [sp, #-16]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-24]
	ldr	a1, [sp, #-24]
	add	sp, sp, #-24
	bl	putint
	add	sp, sp, #24
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
