.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-32
	bl	getint
	add	sp, sp, #32
	str	a1, [sp, #-28]
	ldr	v1, [sp, #-28]
	str	v1, [sp, #-12]
L_1_main:
	ldr	v1, [sp, #-12]
	eor	v2, v2, v2
	mov	v3, v2
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	v2, [sp, #-24]
	ldr	v1, [sp, #-24]
	cmp	v1, #0
	beq	L_0_main
	add	sp, sp, #-32
	bl	getint
	add	sp, sp, #32
	str	a1, [sp, #-20]
	ldr	a1, [sp, #-20]
	eor	v1, v1, v1
	add	a2, v1, #1
	eor	v1, v1, v1
	add	a3, v1, #2
	eor	v1, v1, v1
	add	a4, v1, #3
	add	sp, sp, #-32
	bl	hanoi
	add	sp, sp, #32
	eor	v1, v1, v1
	add	a1, v1, #10
	add	sp, sp, #-32
	bl	putch
	add	sp, sp, #32
	ldr	v1, [sp, #-12]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-16]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-12]
	b	L_1_main
L_0_main:
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	move
.type	move, %function
move:
	push	{lr}
	str	a1, [sp, #-16]
	str	a2, [sp, #-12]
	ldr	a1, [sp, #-16]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	add	a1, v1, #32
	add	sp, sp, #-16
	bl	putch
	add	sp, sp, #16
	ldr	a1, [sp, #-12]
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	eor	v1, v1, v1
	add	a1, v1, #44
	add	sp, sp, #-16
	bl	putch
	add	sp, sp, #16
	eor	v1, v1, v1
	add	a1, v1, #32
	add	sp, sp, #-16
	bl	putch
	add	sp, sp, #16
	pop	{pc}
.text
.align 1
.globl	hanoi
.type	hanoi, %function
hanoi:
	push	{lr}
	str	a1, [sp, #-24]
	str	a2, [sp, #-20]
	str	a3, [sp, #-16]
	str	a4, [sp, #-12]
	ldr	v1, [sp, #-24]
	ldr	v3, =1
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-36]
	ldr	v1, [sp, #-36]
	cmp	v1, #0
	beq	L_0_hanoi
	ldr	a1, [sp, #-20]
	ldr	a2, [sp, #-12]
	add	sp, sp, #-40
	bl	move
	add	sp, sp, #40
	b	L_1_hanoi
L_0_hanoi:
	ldr	v1, [sp, #-24]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-32]
	ldr	a1, [sp, #-32]
	ldr	a2, [sp, #-20]
	ldr	a3, [sp, #-12]
	ldr	a4, [sp, #-16]
	add	sp, sp, #-40
	bl	hanoi
	add	sp, sp, #40
	ldr	a1, [sp, #-20]
	ldr	a2, [sp, #-12]
	add	sp, sp, #-40
	bl	move
	add	sp, sp, #40
	ldr	v1, [sp, #-24]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-28]
	ldr	a1, [sp, #-28]
	ldr	a2, [sp, #-16]
	ldr	a3, [sp, #-20]
	ldr	a4, [sp, #-12]
	add	sp, sp, #-40
	bl	hanoi
	add	sp, sp, #40
L_1_hanoi:
	pop	{pc}
