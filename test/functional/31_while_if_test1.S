.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-16
	bl	whileIf
	add	sp, sp, #16
	str	a1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
.text
.align 1
.globl	whileIf
.type	whileIf, %function
whileIf:
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
L_1_whileIf:
	ldr	v1, [sp, #-16]
	ldr	v3, =100
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-24]
	ldr	v1, [sp, #-24]
	cmp	v1, #0
	beq	L_0_whileIf
	ldr	v1, [sp, #-16]
	ldr	v3, =5
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-28]
	ldr	v1, [sp, #-28]
	cmp	v1, #0
	beq	L_2_whileIf
	ldr	v2, =25
	str	v2, [sp, #-12]
	b	L_3_whileIf
L_2_whileIf:
	ldr	v1, [sp, #-16]
	ldr	v3, =10
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-32]
	cmp	v1, #0
	beq	L_4_whileIf
	ldr	v2, =42
	str	v2, [sp, #-12]
	b	L_5_whileIf
L_4_whileIf:
	ldr	v1, [sp, #-16]
	ldr	v3, =2
	mul	v2, v1, v3
	str	v2, [sp, #-36]
	ldr	v1, [sp, #-36]
	str	v1, [sp, #-12]
L_5_whileIf:
L_3_whileIf:
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-20]
	ldr	v1, [sp, #-20]
	str	v1, [sp, #-16]
	b	L_1_whileIf
L_0_whileIf:
	ldr	a1, [sp, #-12]
	pop	{pc}
