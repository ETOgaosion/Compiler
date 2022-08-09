.data
.globl	n
.type	n, %object
n:
	.word	0x0

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-92]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-24]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-108]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-72]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-64]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-80]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-60]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-40]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-48]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-36]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-76]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-56]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-104]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-28]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-112]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-96]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-124]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-128]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-116]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-100]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-44]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-32]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-52]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-120]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-136]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-88]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-140]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-68]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-84]
	add	sp, sp, #-272
	bl	getint
	add	sp, sp, #272
	str	a1, [sp, #-168]
	ldr	v1, [sp, #-168]
	str	v1, [sp, #-84]
L_1_main:
	ldr	v1, [sp, #-84]
	ldr	v3, =5
	cmp	v1, v3
	ldreq	v2, =1
	ldrne	v2, =0
	str	v2, [sp, #-200]
	ldr	v1, [sp, #-200]
	cmp	v1, #0
	beq	L_0_main
	ldr	v2, [sp, #-84]
	add	v1, v2, #1
	str	v1, [sp, #-204]
	ldr	v1, [sp, #-204]
	str	v1, [sp, #-84]
	b	L_1_main
L_0_main:
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-92]
	ldr	v2, [sp, #-92]
	add	v1, v2, #1
	str	v1, [sp, #-180]
	ldr	v1, [sp, #-180]
	str	v1, [sp, #-24]
	ldr	v2, [sp, #-24]
	add	v1, v2, #1
	str	v1, [sp, #-252]
	ldr	v1, [sp, #-252]
	str	v1, [sp, #-108]
	ldr	v2, [sp, #-108]
	add	v1, v2, #1
	str	v1, [sp, #-188]
	ldr	v1, [sp, #-188]
	str	v1, [sp, #-72]
	ldr	v2, [sp, #-72]
	add	v1, v2, #1
	str	v1, [sp, #-248]
	ldr	v1, [sp, #-248]
	str	v1, [sp, #-64]
	ldr	v2, [sp, #-64]
	add	v1, v2, #1
	str	v1, [sp, #-208]
	ldr	v1, [sp, #-208]
	str	v1, [sp, #-80]
	ldr	v2, [sp, #-80]
	add	v1, v2, #1
	str	v1, [sp, #-176]
	ldr	v1, [sp, #-176]
	str	v1, [sp, #-60]
	ldr	v2, [sp, #-60]
	add	v1, v2, #1
	str	v1, [sp, #-164]
	ldr	v1, [sp, #-164]
	str	v1, [sp, #-40]
	ldr	v2, [sp, #-40]
	add	v1, v2, #1
	str	v1, [sp, #-192]
	ldr	v1, [sp, #-192]
	str	v1, [sp, #-48]
	ldr	v2, [sp, #-48]
	add	v1, v2, #1
	str	v1, [sp, #-172]
	ldr	v1, [sp, #-172]
	str	v1, [sp, #-36]
	ldr	v2, [sp, #-36]
	add	v1, v2, #1
	str	v1, [sp, #-156]
	ldr	v1, [sp, #-156]
	str	v1, [sp, #-20]
	ldr	v2, [sp, #-20]
	add	v1, v2, #1
	str	v1, [sp, #-216]
	ldr	v1, [sp, #-216]
	str	v1, [sp, #-76]
	ldr	v2, [sp, #-76]
	add	v1, v2, #1
	str	v1, [sp, #-196]
	ldr	v1, [sp, #-196]
	str	v1, [sp, #-56]
	ldr	v2, [sp, #-56]
	add	v1, v2, #1
	str	v1, [sp, #-232]
	ldr	v1, [sp, #-232]
	str	v1, [sp, #-104]
	ldr	v2, [sp, #-104]
	add	v1, v2, #1
	str	v1, [sp, #-240]
	ldr	v1, [sp, #-240]
	str	v1, [sp, #-28]
	ldr	v2, [sp, #-28]
	add	v1, v2, #1
	str	v1, [sp, #-236]
	ldr	v1, [sp, #-236]
	str	v1, [sp, #-112]
	ldr	v2, [sp, #-112]
	add	v1, v2, #1
	str	v1, [sp, #-244]
	ldr	v1, [sp, #-244]
	str	v1, [sp, #-96]
	ldr	v2, [sp, #-96]
	add	v1, v2, #1
	str	v1, [sp, #-220]
	ldr	v1, [sp, #-220]
	str	v1, [sp, #-124]
	ldr	v2, [sp, #-124]
	add	v1, v2, #1
	str	v1, [sp, #-260]
	ldr	v1, [sp, #-260]
	str	v1, [sp, #-128]
	ldr	v2, [sp, #-128]
	add	v1, v2, #1
	str	v1, [sp, #-228]
	ldr	v1, [sp, #-228]
	str	v1, [sp, #-116]
	ldr	v2, [sp, #-116]
	add	v1, v2, #1
	str	v1, [sp, #-212]
	ldr	v1, [sp, #-212]
	str	v1, [sp, #-100]
	ldr	v2, [sp, #-100]
	add	v1, v2, #1
	str	v1, [sp, #-160]
	ldr	v1, [sp, #-160]
	str	v1, [sp, #-44]
	ldr	v2, [sp, #-44]
	add	v1, v2, #1
	str	v1, [sp, #-264]
	ldr	v1, [sp, #-264]
	str	v1, [sp, #-32]
	ldr	v2, [sp, #-32]
	add	v1, v2, #1
	str	v1, [sp, #-256]
	ldr	v1, [sp, #-256]
	str	v1, [sp, #-52]
	ldr	v2, [sp, #-52]
	add	v1, v2, #1
	str	v1, [sp, #-224]
	ldr	v1, [sp, #-224]
	str	v1, [sp, #-120]
	ldr	v2, [sp, #-120]
	add	v1, v2, #1
	str	v1, [sp, #-184]
	ldr	v1, [sp, #-184]
	str	v1, [sp, #-136]
	ldr	v2, [sp, #-136]
	add	v1, v2, #1
	str	v1, [sp, #-268]
	ldr	v1, [sp, #-268]
	str	v1, [sp, #-88]
	ldr	v2, [sp, #-88]
	add	v1, v2, #1
	str	v1, [sp, #-152]
	ldr	v1, [sp, #-152]
	str	v1, [sp, #-140]
	ldr	v2, [sp, #-140]
	add	v1, v2, #1
	str	v1, [sp, #-148]
	ldr	v1, [sp, #-148]
	str	v1, [sp, #-68]
	ldr	v2, [sp, #-68]
	add	v1, v2, #1
	str	v1, [sp, #-144]
	ldr	v1, [sp, #-144]
	str	v1, [sp, #-16]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-12]
	ldr	a1, [sp, #-92]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-24]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-108]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-72]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-64]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-80]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-60]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-40]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-48]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-36]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-20]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-76]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-56]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-104]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-28]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-112]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-96]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-124]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-128]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-116]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-100]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-44]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-32]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-52]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-120]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-136]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-88]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-140]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-68]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-16]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-132]
	ldr	v2, =10
	str	v2, [sp, #-132]
	ldr	a1, [sp, #-132]
	add	sp, sp, #-272
	bl	putch
	add	sp, sp, #272
	ldr	a1, [sp, #-84]
	add	sp, sp, #-272
	bl	putint
	add	sp, sp, #272
	ldr	a1, [sp, #-132]
	add	sp, sp, #-272
	bl	putch
	add	sp, sp, #272
	ldr	a1, [sp, #-136]
	pop	{pc}
