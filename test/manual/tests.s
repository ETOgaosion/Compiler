.data
.globl	n
.type	n, %object
n:
	.word	0x0

.data
.globl	ImmValue_0
.type	ImmValue_0, %object
ImmValue_0:
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0
	.word	0x0

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	ldr	v2, =10
	ldr	v1, =n
	str	v2, [v1]
	ldr	v1, =ImmValue_0
	str	v1, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-116]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-76]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-76]
	ldr	v4, =4
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =1
	str	v2, [sp, #-64]
	ldr	v2, =1
	str	v2, [sp, #-48]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-48]
	ldr	v4, =3
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =2
	str	v2, [sp, #-36]
	ldr	v2, =2
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-32]
	ldr	v4, =9
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =3
	str	v2, [sp, #-28]
	ldr	v2, =3
	str	v2, [sp, #-68]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-68]
	ldr	v4, =2
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =4
	str	v2, [sp, #-88]
	ldr	v2, =4
	str	v2, [sp, #-60]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-60]
	eor	v3, v3, v3
	mov	v4, v3
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =5
	str	v2, [sp, #-52]
	ldr	v2, =5
	str	v2, [sp, #-84]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-84]
	ldr	v4, =1
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =6
	str	v2, [sp, #-80]
	ldr	v2, =6
	str	v2, [sp, #-96]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-96]
	ldr	v4, =6
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =7
	str	v2, [sp, #-92]
	ldr	v2, =7
	str	v2, [sp, #-100]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-100]
	ldr	v4, =5
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =8
	str	v2, [sp, #-44]
	ldr	v2, =8
	str	v2, [sp, #-104]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-104]
	ldr	v4, =7
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	ldr	v2, =9
	str	v2, [sp, #-108]
	ldr	v2, =9
	str	v2, [sp, #-24]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-24]
	ldr	v4, =8
	lsl	v2, v2, #2
	add	v1, v1, v2
	str	v4, [v1]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	ldr	a1, =ImmValue_0
	add	sp, sp, #-128
	bl	bubblesort
	add	sp, sp, #128
	str	a1, [sp, #-120]
	ldr	v1, [sp, #-120]
	str	v1, [sp, #-16]
L_1_main:
	ldr	v1, [sp, #-16]
	ldr	v3, =n
	ldr	v2, [v3]
	cmp	v1, v2
	ldrlt	v3, =1
	ldrge	v3, =0
	str	v3, [sp, #-72]
	ldr	v1, [sp, #-72]
	cmp	v1, #0
	beq	L_0_main
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-56]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-112]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-112]
	lsl	v2, v2, #2
	add	v1, v1, v2
	ldr	v1, [v1]
	str	v1, [sp, #-124]
	ldr	v1, [sp, #-124]
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-128
	bl	putint
	add	sp, sp, #128
	ldr	v2, =10
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-12]
	add	sp, sp, #-128
	bl	putch
	add	sp, sp, #128
	ldr	v2, [sp, #-16]
	add	v1, v2, #1
	str	v1, [sp, #-40]
	ldr	v1, [sp, #-40]
	str	v1, [sp, #-16]
	b	L_1_main
L_0_main:
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	bubblesort
.type	bubblesort, %function
bubblesort:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-24]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-24]
L_1_bubblesort:
	ldr	v2, =n
	ldr	v1, [v2]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-56]
	ldr	v1, [sp, #-24]
	ldr	v2, [sp, #-56]
	cmp	v1, v2
	ldrlt	v3, =1
	ldrge	v3, =0
	str	v3, [sp, #-48]
	ldr	v1, [sp, #-48]
	cmp	v1, #0
	beq	L_0_bubblesort
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
L_3_bubblesort:
	ldr	v2, =n
	ldr	v1, [v2]
	ldr	v2, [sp, #-24]
	sub	v3, v1, v2
	str	v3, [sp, #-36]
	ldr	v1, [sp, #-36]
	ldr	v3, =1
	sub	v2, v1, v3
	str	v2, [sp, #-32]
	ldr	v1, [sp, #-20]
	ldr	v2, [sp, #-32]
	cmp	v1, v2
	ldrlt	v3, =1
	ldrge	v3, =0
	str	v3, [sp, #-28]
	ldr	v1, [sp, #-28]
	cmp	v1, #0
	beq	L_2_bubblesort
	ldr	v2, [sp, #-20]
	add	v1, v2, #1
	str	v1, [sp, #-52]
	ldr	v1, [sp, #-12]
	ldr	v2, [sp, #-12]
	cmp	v1, v2
	ldrgt	v3, =1
	ldrle	v3, =0
	str	v3, [sp, #-64]
	ldr	v1, [sp, #-64]
	cmp	v1, #0
	beq	L_4_bubblesort
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	ldr	v2, [sp, #-20]
	add	v1, v2, #1
	str	v1, [sp, #-44]
	ldr	v1, [sp, #-12]
	str	v1, [sp, #-16]
	ldr	v2, [sp, #-20]
	add	v1, v2, #1
	str	v1, [sp, #-60]
	ldr	v1, [sp, #-12]
	str	v1, [sp, #-12]
	ldr	v1, [sp, #-16]
	str	v1, [sp, #-12]
L_4_bubblesort:
	ldr	v2, [sp, #-20]
	add	v1, v2, #1
	str	v1, [sp, #-68]
	ldr	v1, [sp, #-68]
	str	v1, [sp, #-20]
	b	L_3_bubblesort
L_2_bubblesort:
	ldr	v2, [sp, #-24]
	add	v1, v2, #1
	str	v1, [sp, #-40]
	ldr	v1, [sp, #-40]
	str	v1, [sp, #-24]
	b	L_1_bubblesort
L_0_bubblesort:
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
