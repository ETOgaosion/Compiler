.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	add	a1, v1, #1
	eor	v1, v1, v1
	add	a2, v1, #2
	eor	v1, v1, v1
	add	a3, v1, #3
	eor	v1, v1, v1
	add	a4, v1, #4
	eor	v2, v2, v2
	add	v1, v2, #5
	str	v1, [sp, #-44]
	eor	v2, v2, v2
	add	v1, v2, #6
	str	v1, [sp, #-40]
	eor	v2, v2, v2
	add	v1, v2, #7
	str	v1, [sp, #-36]
	add	sp, sp, #-44
	bl	loop3
	add	sp, sp, #44
	str	a1, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-44
	bl	putint
	add	sp, sp, #44
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	loop3
.type	loop3, %function
loop3:
	push	{lr}
	str	a1, [sp, #-36]
	str	a2, [sp, #-28]
	str	a3, [sp, #-20]
	str	a4, [sp, #-32]
	ldr	v1, [sp]
	str	v1, [sp, #-16]
	ldr	v1, [sp, #4]
	str	v1, [sp, #-12]
	ldr	v1, [sp, #8]
	str	v1, [sp, #-24]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-68]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-64]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-56]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-52]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-48]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-44]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-60]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-40]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-68]
	ldr	a1, [sp, #-68]
	pop	{pc}
