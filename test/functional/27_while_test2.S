.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-16
	bl	FourWhile
	add	sp, sp, #16
	str	a1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
.text
.align 1
.globl	FourWhile
.type	FourWhile, %function
FourWhile:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-24]
	ldr	v2, =5
	str	v2, [sp, #-24]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	ldr	v2, =6
	str	v2, [sp, #-20]
	ldr	v2, =7
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =10
	str	v2, [sp, #-12]
L_1_FourWhile:
	ldr	v1, [sp, #-24]
	ldr	v3, =20
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-44]
	ldr	v1, [sp, #-44]
	cmp	v1, #0
	beq	L_0_FourWhile
	ldr	v2, [sp, #-24]
	add	v1, v2, #3
	str	v1, [sp, #-40]
	ldr	v1, [sp, #-40]
	str	v1, [sp, #-24]
L_3_FourWhile:
	ldr	v1, [sp, #-20]
	ldr	v3, =10
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-52]
	ldr	v1, [sp, #-52]
	cmp	v1, #0
	beq	L_2_FourWhile
	ldr	v2, [sp, #-20]
	add	v1, v2, #1
	str	v1, [sp, #-60]
	ldr	v1, [sp, #-60]
	str	v1, [sp, #-20]
L_5_FourWhile:
	ldr	v1, [sp, #-16]
	ldr	v3, =7
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-48]
	ldr	v1, [sp, #-48]
	cmp	v1, #0
	beq	L_4_FourWhile
	ldr	v1, [sp, #-16]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-56]
	ldr	v1, [sp, #-56]
	str	v1, [sp, #-16]
L_7_FourWhile:
	ldr	v1, [sp, #-12]
	ldr	v3, =20
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-68]
	ldr	v1, [sp, #-68]
	cmp	v1, #0
	beq	L_6_FourWhile
	ldr	v2, [sp, #-12]
	add	v1, v2, #3
	str	v1, [sp, #-64]
	ldr	v1, [sp, #-64]
	str	v1, [sp, #-12]
	b	L_7_FourWhile
L_6_FourWhile:
	ldr	v1, [sp, #-12]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-72]
	ldr	v1, [sp, #-72]
	str	v1, [sp, #-12]
	b	L_5_FourWhile
L_4_FourWhile:
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-76]
	ldr	v1, [sp, #-76]
	str	v1, [sp, #-16]
	b	L_3_FourWhile
L_2_FourWhile:
	ldr	v1, [sp, #-20]
	ldr	v3, =2
	sub	v2, v1, v3
	str	v2, [sp, #-36]
	ldr	v1, [sp, #-36]
	str	v1, [sp, #-20]
	b	L_1_FourWhile
L_0_FourWhile:
	ldr	v2, [sp, #-20]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-32]
	ldr	v2, [sp, #-24]
	ldr	v3, [sp, #-32]
	add	v1, v2, v3
	str	v1, [sp, #-28]
	ldr	v2, [sp, #-28]
	ldr	v3, [sp, #-16]
	add	v1, v2, v3
	str	v1, [sp, #-80]
	ldr	a1, [sp, #-80]
	pop	{pc}
