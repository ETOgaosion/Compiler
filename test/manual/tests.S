.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_1_main:
	ldr	v1, [sp, #-20]
	ldr	v3, =10
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-28]
	ldr	v1, [sp, #-16]
	ldr	v3, =1
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-28]
	ldr	v2, [sp, #-32]
	and	v3, v1, v2
	str	v3, [sp, #-36]
	ldr	v1, [sp, #-36]
	cmp	v1, #0
	beq	L_0_main
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-44]
	ldr	v1, [sp, #-44]
	str	v1, [sp, #-16]
L_3_main:
	ldr	v1, [sp, #-16]
	ldr	v3, =1
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-48]
	ldr	v1, [sp, #-48]
	cmp	v1, #0
	beq	L_2_main
	ldr	v1, [sp, #-20]
	ldr	v3, =5
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-52]
	ldr	v1, [sp, #-52]
	cmp	v1, #0
	beq	L_4_main
	ldr	a1, [sp, #-12]
	add	sp, sp, #-56
	bl	putint
	add	sp, sp, #56
	b	L_5_main
L_4_main:
	ldr	v2, =1
	str	v2, [sp, #-12]
L_5_main:
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-40]
	ldr	v1, [sp, #-40]
	str	v1, [sp, #-16]
	b	L_3_main
L_2_main:
	ldr	v2, [sp, #-20]
	add	v1, v2, #2
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-20]
	b	L_1_main
L_0_main:
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
