.data
.globl	e
.type	e, %object
e:
	.word	0x4

.data
.globl	c
.type	c, %object
c:
	.word	0x1

.data
.globl	b
.type	b, %object
b:
	.word	0x0

.data
.globl	d
.type	d, %object
d:
	.word	0x2

.data
.globl	a
.type	a, %object
a:
	.word	0x1

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v2, =a
	ldr	v1, [v2]
	ldr	v3, =b
	ldr	v2, [v3]
	mul	v3, v1, v2
	str	v3, [sp, #-28]
	ldr	a1, [sp, #-28]
	ldr	v1, =c
	ldr	a2, [v1]
	sub	sp, sp, #80
	bl	__aeabi_idiv
	add	sp, sp, #80
	mov	v1, a1
	ldr	v3, =e
	ldr	v2, [v3]
	ldr	v4, =d
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-48]
	ldr	v1, [sp, #-44]
	ldr	v2, [sp, #-48]
	cmp	v1, v2
	ldreq	v3, =1
	ldrne	v3, =0
	str	v3, [sp, #-56]
	ldr	v3, =a
	ldr	v2, [v3]
	ldr	v4, =b
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-64]
	ldr	v2, =a
	ldr	v1, [v2]
	ldr	v2, [sp, #-64]
	mul	v3, v1, v2
	str	v3, [sp, #-68]
	ldr	v2, [sp, #-68]
	ldr	v4, =c
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-72]
	ldr	v3, =d
	ldr	v2, [v3]
	ldr	v4, =e
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-76]
	ldr	v1, [sp, #-72]
	ldr	v2, [sp, #-76]
	cmp	v1, v2
	ldrle	v3, =1
	ldrgt	v3, =0
	str	v3, [sp, #-32]
	ldr	v1, [sp, #-56]
	ldr	v2, [sp, #-32]
	and	v3, v1, v2
	str	v3, [sp, #-52]
	ldr	v2, =b
	ldr	v1, [v2]
	ldr	v3, =c
	ldr	v2, [v3]
	mul	v3, v1, v2
	str	v3, [sp, #-60]
	ldr	v2, =a
	ldr	v1, [v2]
	ldr	v2, [sp, #-60]
	sub	v3, v1, v2
	str	v3, [sp, #-36]
	ldr	v1, =a
	ldr	a1, [v1]
	ldr	v1, =c
	ldr	a2, [v1]
	sub	sp, sp, #80
	bl	__aeabi_idiv
	add	sp, sp, #80
	mov	v1, a1
	ldr	v2, =d
	ldr	v1, [v2]
	ldr	v2, [sp, #-40]
	sub	v3, v1, v2
	str	v3, [sp, #-24]
	ldr	v1, [sp, #-36]
	ldr	v2, [sp, #-24]
	cmp	v1, v2
	ldreq	v3, =1
	ldrne	v3, =0
	str	v3, [sp, #-20]
	ldr	v1, [sp, #-52]
	ldr	v2, [sp, #-20]
	orr	v3, v1, v2
	str	v3, [sp, #-16]
	ldr	v1, [sp, #-16]
	cmp	v1, #0
	beq	L_0_main
	ldr	v2, =1
	str	v2, [sp, #-12]
L_0_main:
	ldr	a1, [sp, #-12]
	add	sp, sp, #-80
	bl	putint
	add	sp, sp, #80
	ldr	a1, [sp, #-12]
	pop	{pc}
