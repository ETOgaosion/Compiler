.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-16
	bl	doubleWhile
	add	sp, sp, #16
	str	a1, [sp, #-12]
	ldr	a1, [sp, #-12]
	pop	{pc}
.text
.align 1
.globl	doubleWhile
.type	doubleWhile, %function
doubleWhile:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	ldr	v2, =5
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =7
	str	v2, [sp, #-12]
L_1_doubleWhile:
	ldr	v1, [sp, #-16]
	ldr	v3, =100
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-20]
	ldr	v1, [sp, #-20]
	cmp	v1, #0
	beq	L_0_doubleWhile
	ldr	v2, [sp, #-16]
	add	v1, v2, #30
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-16]
L_3_doubleWhile:
	ldr	v1, [sp, #-12]
	ldr	v3, =100
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-32]
	cmp	v1, #0
	beq	L_2_doubleWhile
	ldr	v2, [sp, #-12]
	add	v1, v2, #6
	str	v1, [sp, #-36]
	ldr	v1, [sp, #-36]
	str	v1, [sp, #-12]
	b	L_3_doubleWhile
L_2_doubleWhile:
	ldr	v1, [sp, #-12]
	ldr	v3, =100
	sub	v2, v1, v3
	str	v2, [sp, #-28]
	ldr	v1, [sp, #-28]
	str	v1, [sp, #-12]
	b	L_1_doubleWhile
L_0_doubleWhile:
	ldr	a1, [sp, #-12]
	pop	{pc}
