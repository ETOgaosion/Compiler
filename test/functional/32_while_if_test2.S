.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-16
	bl	ifWhile
	add	sp, sp, #16
	str	a1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
.text
.align 1
.globl	ifWhile
.type	ifWhile, %function
ifWhile:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =3
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-16]
	ldr	v3, =5
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-32]
	cmp	v1, #0
	beq	L_0_ifWhile
L_3_ifWhile:
	ldr	v1, [sp, #-12]
	ldr	v3, =2
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-36]
	ldr	v1, [sp, #-36]
	cmp	v1, #0
	beq	L_2_ifWhile
	ldr	v2, [sp, #-12]
	add	v1, v2, #2
	str	v1, [sp, #-44]
	ldr	v1, [sp, #-44]
	str	v1, [sp, #-12]
	b	L_3_ifWhile
L_2_ifWhile:
	ldr	v2, [sp, #-12]
	add	v1, v2, #25
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-12]
	b	L_1_ifWhile
L_0_ifWhile:
L_5_ifWhile:
	ldr	v1, [sp, #-16]
	ldr	v3, =5
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-40]
	ldr	v1, [sp, #-40]
	cmp	v1, #0
	beq	L_4_ifWhile
	ldr	v1, [sp, #-12]
	ldr	v3, =2
	mul	v2, v1, v3
	str	v2, [sp, #-28]
	ldr	v1, [sp, #-28]
	str	v1, [sp, #-12]
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-20]
	ldr	v1, [sp, #-20]
	str	v1, [sp, #-16]
	b	L_5_ifWhile
L_4_ifWhile:
L_1_ifWhile:
	ldr	a1, [sp, #-12]
	pop	{pc}
