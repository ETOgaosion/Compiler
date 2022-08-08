.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =2
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	ldr	a2, [sp, #-12]
	add	sp, sp, #-16
	bl	deepWhileBr
	add	sp, sp, #16
	str	a1, [sp, #-16]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
	pop	{pc}
.text
.align 1
.globl	deepWhileBr
.type	deepWhileBr, %function
deepWhileBr:
	push	{lr}
	str	a1, [sp, #-16]
	str	a2, [sp, #-12]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-28]
	ldr	v2, [sp, #-16]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-32]
	ldr	v1, [sp, #-32]
	str	v1, [sp, #-28]
L_1_deepWhileBr:
	ldr	v1, [sp, #-28]
	ldr	v3, =75
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-48]
	ldr	v1, [sp, #-48]
	cmp	v1, #0
	beq	L_0_deepWhileBr
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-24]
	ldr	v2, =42
	str	v2, [sp, #-24]
	ldr	v1, [sp, #-28]
	ldr	v3, =100
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-56]
	ldr	v1, [sp, #-56]
	cmp	v1, #0
	beq	L_2_deepWhileBr
	ldr	v2, [sp, #-28]
	ldr	v3, [sp, #-24]
	add	v1, v2, v3
	str	v1, [sp, #-60]
	ldr	v1, [sp, #-60]
	str	v1, [sp, #-28]
	ldr	v1, [sp, #-28]
	ldr	v3, =99
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	v2, [sp, #-64]
	ldr	v1, [sp, #-64]
	cmp	v1, #0
	beq	L_3_deepWhileBr
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
	ldr	v1, [sp, #-24]
	ldr	v3, =2
	mul	v2, v1, v3
	str	v2, [sp, #-36]
	ldr	v1, [sp, #-36]
	str	v1, [sp, #-20]
	eor	v1, v1, v1
	mov	a1, v1
	add	sp, sp, #-64
	bl	get_one
	add	sp, sp, #64
	str	a1, [sp, #-52]
	ldr	v1, [sp, #-52]
	ldr	v3, =1
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-40]
	ldr	v1, [sp, #-40]
	cmp	v1, #0
	beq	L_4_deepWhileBr
	ldr	v1, [sp, #-20]
	ldr	v3, =2
	mul	v2, v1, v3
	str	v2, [sp, #-44]
	ldr	v1, [sp, #-44]
	str	v1, [sp, #-28]
L_4_deepWhileBr:
L_3_deepWhileBr:
L_2_deepWhileBr:
	b	L_1_deepWhileBr
L_0_deepWhileBr:
	ldr	a1, [sp, #-28]
	pop	{pc}
.text
.align 1
.globl	get_one
.type	get_one, %function
get_one:
	push	{lr}
	str	a1, [sp, #-12]
	eor	v1, v1, v1
	add	a1, v1, #1
	pop	{pc}
