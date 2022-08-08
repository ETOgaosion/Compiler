.data
.globl	g
.type	g, %object
g:
	.word	0x0

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	add	sp, sp, #-96
	bl	getint
	add	sp, sp, #96
	str	a1, [sp, #-80]
	ldr	v1, [sp, #-80]
	str	v1, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v3, =10
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	v2, [sp, #-56]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-96
	bl	func
	add	sp, sp, #96
	str	a1, [sp, #-48]
	ldr	v1, [sp, #-56]
	ldr	v2, [sp, #-48]
	and	v3, v1, v2
	str	v3, [sp, #-36]
	ldr	v1, [sp, #-36]
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
	add	sp, sp, #-96
	bl	getint
	add	sp, sp, #96
	str	a1, [sp, #-68]
	ldr	v1, [sp, #-68]
	str	v1, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v3, =11
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	v2, [sp, #-52]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-96
	bl	func
	add	sp, sp, #96
	str	a1, [sp, #-64]
	ldr	v1, [sp, #-52]
	ldr	v2, [sp, #-64]
	and	v3, v1, v2
	str	v3, [sp, #-60]
	ldr	v1, [sp, #-60]
	cmp	v1, #0
	beq	L_2_main
	ldr	v2, =1
	str	v2, [sp, #-12]
	b	L_3_main
L_2_main:
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_3_main:
	add	sp, sp, #-96
	bl	getint
	add	sp, sp, #96
	str	a1, [sp, #-44]
	ldr	v1, [sp, #-44]
	str	v1, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v3, =99
	cmp	v1, v3
	ldrle	v2, =1
	ldrgt	v2, =0
	str	v2, [sp, #-72]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-96
	bl	func
	add	sp, sp, #96
	str	a1, [sp, #-28]
	ldr	v1, [sp, #-72]
	ldr	v2, [sp, #-28]
	orr	v3, v1, v2
	str	v3, [sp, #-84]
	ldr	v1, [sp, #-84]
	cmp	v1, #0
	beq	L_4_main
	ldr	v2, =1
	str	v2, [sp, #-12]
	b	L_5_main
L_4_main:
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_5_main:
	add	sp, sp, #-96
	bl	getint
	add	sp, sp, #96
	str	a1, [sp, #-76]
	ldr	v1, [sp, #-76]
	str	v1, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v3, =100
	cmp	v1, v3
	ldrle	v2, =1
	ldrgt	v2, =0
	str	v2, [sp, #-92]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-96
	bl	func
	add	sp, sp, #96
	str	a1, [sp, #-88]
	ldr	v1, [sp, #-92]
	ldr	v2, [sp, #-88]
	orr	v3, v1, v2
	str	v3, [sp, #-40]
	ldr	v1, [sp, #-40]
	cmp	v1, #0
	beq	L_6_main
	ldr	v2, =1
	str	v2, [sp, #-12]
	b	L_7_main
L_6_main:
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_7_main:
	eor	v1, v1, v1
	add	a1, v1, #99
	add	sp, sp, #-96
	bl	func
	add	sp, sp, #96
	str	a1, [sp, #-24]
	ldr	v1, [sp, #-24]
	eor	v2, v1, #1
	str	v2, [sp, #-20]
	eor	v1, v1, v1
	add	a1, v1, #100
	add	sp, sp, #-96
	bl	func
	add	sp, sp, #96
	str	a1, [sp, #-16]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-16]
	and	v3, v1, v2
	str	v3, [sp, #-32]
	ldr	v1, [sp, #-32]
	cmp	v1, #0
	beq	L_8_main
	ldr	v2, =1
	str	v2, [sp, #-12]
	b	L_9_main
L_8_main:
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
L_9_main:
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	func
.type	func, %function
func:
	push	{lr}
	str	a1, [sp, #-12]
	ldr	v3, =g
	ldr	v2, [v3]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-16]
	ldr	v1, [sp, #-16]
	ldr	v2, =g
	str	v1, [v2]
	ldr	a1, =g
	add	sp, sp, #-16
	bl	putint
	add	sp, sp, #16
	ldr	a1, =g
	pop	{pc}
