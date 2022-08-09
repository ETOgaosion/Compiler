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
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_1_main:
	ldr	v1, [sp, #-16]
	ldr	v3, =100
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-32]
	cmp	v1, #0
	beq	L_0_main
	ldr	v1, [sp, #-16]
	ldr	v3, =50
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-28]
	ldr	v1, [sp, #-28]
	cmp	v1, #0
	beq	L_2_main
	b	L_0_main
L_2_main:
	ldr	v2, [sp, #-12]
	ldr	v3, [sp, #-16]
	add	v1, v2, v3
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-12]
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-20]
	ldr	v1, [sp, #-20]
	str	v1, [sp, #-16]
	b	L_1_main
L_0_main:
	ldr	a1, [sp, #-12]
	add	sp, sp, #-32
	bl	putint
	add	sp, sp, #32
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
