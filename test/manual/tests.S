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
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-16]
	ldr	v3, =1
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	v2, [sp, #-20]
	ldr	v1, [sp, #-20]
	cmp	v1, #0
	beq	L_0_main
	ldr	v2, =999
	ldr	v3, =2000
	mul	v1, v2, v3
	str	v1, [sp, #-28]
	ldr	v1, [sp, #-28]
	str	v1, [sp, #-12]
	b	L_1_main
L_0_main:
	ldr	v2, =2
	ldr	v3, =8
	mul	v1, v2, v3
	str	v1, [sp, #-32]
	ldr	v2, [sp, #-32]
	add	v1, v2, #1
	str	v1, [sp, #-40]
	ldr	v2, [sp, #-40]
	add	v1, v2, #100
	str	v1, [sp, #-44]
	ldr	v1, [sp, #-44]
	ldr	v3, =9999
	sub	v2, v1, v3
	str	v2, [sp, #-48]
	ldr	a1, =10000
	ldr	a2, =5
	sub	sp, sp, #56
	bl	__aeabi_idiv
	add	sp, sp, #56
	mov	v1, a1
	ldr	v2, [sp, #-48]
	ldr	v3, [sp, #-52]
	add	v1, v2, v3
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-12]
	ldr	v2, [sp, #-12]
	add	v1, v2, #1000
	str	v1, [sp, #-36]
	ldr	v1, [sp, #-36]
	str	v1, [sp, #-16]
L_1_main:
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
