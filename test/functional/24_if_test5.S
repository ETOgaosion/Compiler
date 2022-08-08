.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-16
	bl	if_if_Else
	add	sp, sp, #16
	str	a1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
.text
.align 1
.globl	if_if_Else
.type	if_if_Else, %function
if_if_Else:
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
	ldr	v3, =5
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-28]
	ldr	v1, [sp, #-28]
	cmp	v1, #0
	beq	L_0_if_if_Else
	ldr	v1, [sp, #-12]
	ldr	v3, =10
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-24]
	ldr	v1, [sp, #-24]
	cmp	v1, #0
	beq	L_2_if_if_Else
	ldr	v2, =25
	str	v2, [sp, #-16]
L_2_if_if_Else:
	b	L_1_if_if_Else
L_0_if_if_Else:
	ldr	v2, [sp, #-16]
	add	v1, v2, #15
	str	v1, [sp, #-20]
	ldr	v1, [sp, #-20]
	str	v1, [sp, #-16]
L_1_if_if_Else:
	ldr	a1, [sp, #-16]
	pop	{pc}
