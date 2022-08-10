.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-16
	bl	ifElseIf
	add	sp, sp, #16
	str	a1, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	ifElseIf
.type	ifElseIf, %function
ifElseIf:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	ldr	v2, =5
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =10
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-16]
	ldr	v3, =6
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-36]
	ldr	v1, [sp, #-12]
	ldr	v3, =0
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-44]
	ldr	v1, [sp, #-36]
	ldr	v2, [sp, #-44]
	orr	v3, v1, v2
	str	v3, [sp, #-56]
	ldr	v1, [sp, #-56]
	cmp	v1, #0
	beq	L_0_ifElseIf
	ldr	a1, [sp, #-16]
	pop	{pc}
	b	L_1_ifElseIf
L_0_ifElseIf:
	ldr	v1, [sp, #-12]
	ldr	v3, =10
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-60]
	ldr	v1, [sp, #-16]
	ldr	v3, =1
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-64]
	ldr	v1, [sp, #-60]
	ldr	v2, [sp, #-64]
	and	v3, v1, v2
	str	v3, [sp, #-68]
	ldr	v1, [sp, #-68]
	cmp	v1, #0
	beq	L_2_ifElseIf
	ldr	v2, =25
	str	v2, [sp, #-16]
	b	L_3_ifElseIf
L_2_ifElseIf:
	ldr	v1, [sp, #-12]
	ldr	v3, =10
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-40]
	ldr	v2, =5
	rsb	v1, v2, #0
	str	v1, [sp, #-52]
	ldr	v1, [sp, #-16]
	ldr	v2, [sp, #-52]
	cmp	v1, v2
	ldreq	v3, =1
	ldrne	v3, =0
	str	v3, [sp, #-28]
	ldr	v1, [sp, #-40]
	ldr	v2, [sp, #-28]
	and	v3, v1, v2
	str	v3, [sp, #-32]
	ldr	v1, [sp, #-32]
	cmp	v1, #0
	beq	L_4_ifElseIf
	ldr	v2, [sp, #-16]
	add	v1, v2, #15
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-16]
	b	L_5_ifElseIf
L_4_ifElseIf:
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-20]
	ldr	v1, [sp, #-20]
	rsb	v2, v1, #0
	str	v2, [sp, #-48]
	ldr	v1, [sp, #-48]
	str	v1, [sp, #-16]
L_5_ifElseIf:
L_3_ifElseIf:
L_1_ifElseIf:
	ldr	a1, [sp, #-16]
	pop	{pc}
