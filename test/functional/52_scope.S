.data
.globl	a
.type	a, %object
a:
	.word	0x7

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
L_1_main:
	ldr	v1, [sp, #-12]
	ldr	v3, =100
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-40]
	ldr	v1, [sp, #-40]
	cmp	v1, #0
	beq	L_0_main
	add	sp, sp, #-40
	bl	func
	add	sp, sp, #40
	str	a1, [sp, #-32]
	ldr	v1, [sp, #-32]
	ldr	v3, =1
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-28]
	ldr	v1, [sp, #-28]
	cmp	v1, #0
	beq	L_2_main
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-16]
L_2_main:
	ldr	v2, [sp, #-12]
	add	v1, v2, #1
	str	v1, [sp, #-20]
	ldr	v1, [sp, #-20]
	str	v1, [sp, #-12]
	b	L_1_main
L_0_main:
	ldr	v1, [sp, #-16]
	ldr	v3, =100
	cmp	v1, v3
	ldrlt	v2, =1
	ldrge	v2, =0
	str	v2, [sp, #-36]
	ldr	v1, [sp, #-36]
	cmp	v1, #0
	beq	L_3_main
	eor	v1, v1, v1
	add	a1, v1, #1
	add	sp, sp, #-40
	bl	putint
	add	sp, sp, #40
	b	L_4_main
L_3_main:
	eor	v1, v1, v1
	mov	a1, v1
	add	sp, sp, #-40
	bl	putint
	add	sp, sp, #40
L_4_main:
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	func
.type	func, %function
func:
	push	{lr}
	ldr	v2, =a
	ldr	v1, [v2]
	str	v1, [sp, #-16]
	ldr	v2, =1
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v2, [sp, #-16]
	cmp	v1, v2
	ldreq	v3, =1
	ldrne	v3, =0
	str	v3, [sp, #-24]
	ldr	v1, [sp, #-24]
	cmp	v1, #0
	beq	L_0_func
	ldr	v2, [sp, #-12]
	add	v1, v2, #1
	str	v1, [sp, #-20]
	ldr	v1, [sp, #-20]
	str	v1, [sp, #-12]
	eor	v1, v1, v1
	add	a1, v1, #1
	pop	{pc}
	b	L_1_func
L_0_func:
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
L_1_func:
	pop	{pc}
