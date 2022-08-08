.data
.globl	b
.type	b, %object
b:
	.word	0x0

.data
.globl	a
.type	a, %object
a:
	.word	0x0

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	add	sp, sp, #-32
	bl	getint
	add	sp, sp, #32
	str	a1, [sp, #-32]
	ldr	v1, [sp, #-32]
	ldr	v2, =a
	str	v1, [v2]
	add	sp, sp, #-32
	bl	getint
	add	sp, sp, #32
	str	a1, [sp, #-28]
	ldr	v1, [sp, #-28]
	ldr	v2, =b
	str	v1, [v2]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =a
	ldr	v1, [v2]
	ldr	v3, =b
	ldr	v2, [v3]
	cmp	v1, v2
	ldreq	v3, =1
	ldrne	v3, =0
	str	v3, [sp, #-24]
	ldr	v2, =a
	ldr	v1, [v2]
	ldr	v3, =3
	cmp	v1, v3
	ldrne	v2, =1
	ldreq	v2, =0
	str	v2, [sp, #-20]
	ldr	v1, [sp, #-24]
	ldr	v2, [sp, #-20]
	and	v3, v1, v2
	str	v3, [sp, #-16]
	ldr	v1, [sp, #-16]
	cmp	v1, #0
	beq	L_0_main
	ldr	v2, =1
	str	v2, [sp, #-12]
	b	L_1_main
L_0_main:
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_1_main:
	ldr	a1, [sp, #-12]
	pop	{pc}
