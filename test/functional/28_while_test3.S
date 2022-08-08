.data
.globl	e
.type	e, %object
e:
	.word	0x0

.data
.globl	f
.type	f, %object
f:
	.word	0x0

.data
.globl	h
.type	h, %object
h:
	.word	0x0

.data
.globl	g
.type	g, %object
g:
	.word	0x0

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =1
	ldr	v1, =g
	str	v2, [v1]
	ldr	v2, =2
	ldr	v1, =h
	str	v2, [v1]
	ldr	v2, =4
	ldr	v1, =e
	str	v2, [v1]
	ldr	v2, =6
	ldr	v1, =f
	str	v2, [v1]
	add	sp, sp, #-16
	bl	EightWhile
	add	sp, sp, #16
	str	a1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
	pop	{pc}
.text
.align 1
.globl	EightWhile
.type	EightWhile, %function
EightWhile:
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
L_1_EightWhile:
	ldr	v1, [sp, #-24]
	ldr	v3, =20
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-108]
	ldr	v1, [sp, #-108]
	cmp	v1, #0
	beq	L_0_EightWhile
	ldr	v2, [sp, #-24]
	add	v1, v2, #3
	str	v1, [sp, #-104]
	ldr	v1, [sp, #-104]
	str	v1, [sp, #-24]
L_3_EightWhile:
	ldr	v1, [sp, #-20]
	ldr	v3, =10
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-84]
	ldr	v1, [sp, #-84]
	cmp	v1, #0
	beq	L_2_EightWhile
	ldr	v2, [sp, #-20]
	add	v1, v2, #1
	str	v1, [sp, #-76]
	ldr	v1, [sp, #-76]
	str	v1, [sp, #-20]
L_5_EightWhile:
	ldr	v1, [sp, #-16]
	ldr	v3, =7
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-132]
	ldr	v1, [sp, #-132]
	cmp	v1, #0
	beq	L_4_EightWhile
	ldr	v1, [sp, #-16]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-144]
	ldr	v1, [sp, #-144]
	str	v1, [sp, #-16]
L_7_EightWhile:
	ldr	v1, [sp, #-12]
	ldr	v3, =20
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-64]
	ldr	v1, [sp, #-64]
	cmp	v1, #0
	beq	L_6_EightWhile
	ldr	v2, [sp, #-12]
	add	v1, v2, #3
	str	v1, [sp, #-128]
	ldr	v1, [sp, #-128]
	str	v1, [sp, #-12]
L_9_EightWhile:
	ldr	v2, =e
	ldr	v1, [v2]
	ldr	v3, =1
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	v2, [sp, #-96]
	ldr	v1, [sp, #-96]
	cmp	v1, #0
	beq	L_8_EightWhile
	ldr	v2, =e
	ldr	v1, [v2]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-124]
	ldr	v1, [sp, #-124]
	ldr	v2, =e
	str	v1, [v2]
L_11_EightWhile:
	ldr	v2, =f
	ldr	v1, [v2]
	ldr	v3, =2
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	v2, [sp, #-60]
	ldr	v1, [sp, #-60]
	cmp	v1, #0
	beq	L_10_EightWhile
	ldr	v2, =f
	ldr	v1, [v2]
	ldr	v3, =2
	sub	v2, v1, v3
	str	v2, [sp, #-116]
	ldr	v1, [sp, #-116]
	ldr	v2, =f
	str	v1, [v2]
L_13_EightWhile:
	ldr	v2, =g
	ldr	v1, [v2]
	ldr	v3, =3
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-52]
	ldr	v1, [sp, #-52]
	cmp	v1, #0
	beq	L_12_EightWhile
	ldr	v3, =g
	ldr	v2, [v3]
	add	v1, v2, #10
	str	v1, [sp, #-88]
	ldr	v1, [sp, #-88]
	ldr	v2, =g
	str	v1, [v2]
L_15_EightWhile:
	ldr	v2, =h
	ldr	v1, [v2]
	ldr	v3, =10
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-80]
	ldr	v1, [sp, #-80]
	cmp	v1, #0
	beq	L_14_EightWhile
	ldr	v3, =h
	ldr	v2, [v3]
	add	v1, v2, #8
	str	v1, [sp, #-92]
	ldr	v1, [sp, #-92]
	ldr	v2, =h
	str	v1, [v2]
	b	L_15_EightWhile
L_14_EightWhile:
	ldr	v2, =h
	ldr	v1, [v2]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-48]
	ldr	v1, [sp, #-48]
	ldr	v2, =h
	str	v1, [v2]
	b	L_13_EightWhile
L_12_EightWhile:
	ldr	v2, =g
	ldr	v1, [v2]
	ldr	v3, =8
	sub	v2, v1, v3
	str	v2, [sp, #-120]
	ldr	v1, [sp, #-120]
	ldr	v2, =g
	str	v1, [v2]
	b	L_11_EightWhile
L_10_EightWhile:
	ldr	v3, =f
	ldr	v2, [v3]
	add	v1, v2, #1
	str	v1, [sp, #-100]
	ldr	v1, [sp, #-100]
	ldr	v2, =f
	str	v1, [v2]
	b	L_9_EightWhile
L_8_EightWhile:
	ldr	v3, =e
	ldr	v2, [v3]
	add	v1, v2, #1
	str	v1, [sp, #-136]
	ldr	v1, [sp, #-136]
	ldr	v2, =e
	str	v1, [v2]
	b	L_7_EightWhile
L_6_EightWhile:
	ldr	v1, [sp, #-12]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-44]
	ldr	v1, [sp, #-44]
	str	v1, [sp, #-12]
	b	L_5_EightWhile
L_4_EightWhile:
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-40]
	ldr	v1, [sp, #-40]
	str	v1, [sp, #-16]
	b	L_3_EightWhile
L_2_EightWhile:
	ldr	v1, [sp, #-20]
	ldr	v3, =2
	sub	v2, v1, v3
	str	v2, [sp, #-56]
	ldr	v1, [sp, #-56]
	str	v1, [sp, #-20]
	b	L_1_EightWhile
L_0_EightWhile:
	ldr	v2, [sp, #-20]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-112]
	ldr	v2, [sp, #-24]
	ldr	v3, [sp, #-112]
	add	v1, v2, v3
	str	v1, [sp, #-36]
	ldr	v2, [sp, #-36]
	ldr	v3, [sp, #-16]
	add	v1, v2, v3
	str	v1, [sp, #-140]
	ldr	v3, =e
	ldr	v2, [v3]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-32]
	ldr	v1, [sp, #-32]
	ldr	v3, =g
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-72]
	ldr	v2, [sp, #-72]
	ldr	v4, =h
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-68]
	ldr	v1, [sp, #-140]
	ldr	v2, [sp, #-68]
	sub	v3, v1, v2
	str	v3, [sp, #-28]
	ldr	a1, [sp, #-28]
	pop	{pc}
