.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =200
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-16
	bl	reverse
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	reverse
.type	reverse, %function
reverse:
	push	{lr}
	str	a1, [sp, #-12]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	ldr	v1, [sp, #-12]
	ldr	v3, =1
	cmp	v1, v3
	ldrle	v2, =1
	ldrgt	v2, =0
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-32]
	cmp	v1, #0
	beq	L_0_reverse
	add	sp, sp, #-32
	bl	getint
	add	sp, sp, #32
	str	a1, [sp, #-28]
	ldr	v1, [sp, #-28]
	str	v1, [sp, #-16]
	ldr	a1, [sp, #-16]
	add	sp, sp, #-32
	bl	putint
	add	sp, sp, #32
	b	L_1_reverse
L_0_reverse:
	add	sp, sp, #-32
	bl	getint
	add	sp, sp, #32
	str	a1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-16]
	ldr	v1, [sp, #-12]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-20]
	ldr	a1, [sp, #-20]
	add	sp, sp, #-32
	bl	reverse
	add	sp, sp, #32
	ldr	a1, [sp, #-16]
	add	sp, sp, #-32
	bl	putint
	add	sp, sp, #32
L_1_reverse:
	pop	{pc}
