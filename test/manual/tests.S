.text
.align 1
.globl	main
.type	main, %function
main:
	eor	v1, v1, v1
	mov	v2, v1
	str	sp, [v2, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	sp, [v2, #-12]
	ldr	v1, [sp, #-16]
	eor	v2, v2, v2
	ldr	v3, 1
	cmp	v1, v3
	ldrgt	v2, =1
	ldrle	v2, =0
	str	sp, [v2, #-20]
	ldr	v1, [sp, #-20]
	cmp	v1, #0
	beq	L_0_main
	eor	v1, v1, v1
	ldr	v2, 999
	eor	v1, v1, v1
	ldr	v3, 2000
	mul	v1, v2, v3
	str	sp, [v1, #-28]
	ldr	v1, [sp, #-28]
	str	sp, [v1, #-12]
	b	L_1_main
L_0_main:
	eor	v1, v1, v1
	ldr	v2, 2
	eor	v1, v1, v1
	ldr	v3, 8
	mul	v1, v2, v3
	str	sp, [v1, #-32]
	ldr	v2, [sp, #-32]
	add	v1, v2, #1
	str	sp, [v1, #-40]
	ldr	v2, [sp, #-40]
	add	v1, v2, #100
	str	sp, [v1, #-44]
	ldr	v1, [sp, #-44]
	eor	v2, v2, v2
	ldr	v3, 9999
	rsb	v2, v1, #0
	str	sp, [v2, #-48]
	eor	v1, v1, v1
	ldr	v2, 10000
	eor	v1, v1, v1
	ldr	v3, 5
	sdiv	v1, v2, v3
	str	sp, [v1, #-52]
	ldr	v2, [sp, #-48]
	ldr	v3, [sp, #-52]
	add	v1, v2, v3
	str	sp, [v1, #-24]
	ldr	v1, [sp, #-24]
	str	sp, [v1, #-12]
	ldr	v2, [sp, #-12]
	add	v1, v2, #1000
	str	sp, [v1, #-36]
	ldr	v1, [sp, #-36]
	str	sp, [v1, #-16]
L_1_main:
	eor	v1, v1, v1
	mov	a1, v1
	mov	pc, lr
.text
.align 1
.globl	getfarray
.type	getfarray, %function
getfarray:
	mov	pc, lr
.text
.align 1
.globl	getarray
.type	getarray, %function
getarray:
	mov	pc, lr
.text
.align 1
.globl	getint
.type	getint, %function
getint:
	mov	pc, lr
.text
.align 1
.globl	putfarray
.type	putfarray, %function
putfarray:
	mov	pc, lr
.text
.align 1
.globl	putarray
.type	putarray, %function
putarray:
	mov	pc, lr
.text
.align 1
.globl	putfloat
.type	putfloat, %function
putfloat:
	mov	pc, lr
.text
.align 1
.globl	getfloat
.type	getfloat, %function
getfloat:
	mov	pc, lr
.text
.align 1
.globl	putint
.type	putint, %function
putint:
	mov	pc, lr
