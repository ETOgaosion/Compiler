.data
.globl	k
.type	k, %object
k:
	.word	0x0

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =3389
	ldr	v1, =k
	str	v2, [v1]
	ldr	v2, =k
	ldr	v1, [v2]
	ldr	v3, =10000
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-28]
	ldr	v1, [sp, #-28]
	cmp	v1, #0
	beq	L_0_main
	ldr	v3, =k
	ldr	v2, [v3]
	add	v1, v2, #1
	str	v1, [sp, #-40]
	ldr	v1, [sp, #-40]
	ldr	v2, =k
	str	v1, [v2]
	ldr	v2, =112
	str	v2, [sp, #-24]
L_2_main:
	ldr	v1, [sp, #-24]
	ldr	v3, =10
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	v2, [sp, #-44]
	ldr	v1, [sp, #-44]
	cmp	v1, #0
	beq	L_1_main
	ldr	v1, [sp, #-24]
	ldr	v3, =88
	sub	v2, v1, v3
	str	v2, [sp, #-52]
	ldr	v1, [sp, #-52]
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	ldr	v3, =1000
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-56]
	ldr	v1, [sp, #-56]
	cmp	v1, #0
	beq	L_3_main
	ldr	v2, =9
	str	v2, [sp, #-16]
	ldr	v2, =11
	str	v2, [sp, #-12]
	ldr	v2, =10
	str	v2, [sp, #-16]
	ldr	v1, [sp, #-24]
	ldr	v2, [sp, #-16]
	sub	v3, v1, v2
	str	v3, [sp, #-32]
	ldr	v1, [sp, #-32]
	str	v1, [sp, #-24]
	ldr	v2, =11
	str	v2, [sp, #-20]
	ldr	v2, [sp, #-24]
	ldr	v3, [sp, #-20]
	add	v1, v2, v3
	str	v1, [sp, #-48]
	ldr	v2, [sp, #-48]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-36]
	ldr	v1, [sp, #-36]
	str	v1, [sp, #-24]
L_3_main:
	b	L_2_main
L_1_main:
	ldr	a1, [sp, #-24]
	add	sp, sp, #-56
	bl	putint
	add	sp, sp, #56
L_0_main:
	ldr	a1, [sp, #-24]
	pop	{pc}
