.data
.globl	a36
.type	a36, %object
a36:
	.word	0x0

.data
.globl	a32
.type	a32, %object
a32:
	.word	0x0

.data
.globl	a31
.type	a31, %object
a31:
	.word	0x0

.data
.globl	a30
.type	a30, %object
a30:
	.word	0x0

.data
.globl	a39
.type	a39, %object
a39:
	.word	0x0

.data
.globl	a29
.type	a29, %object
a29:
	.word	0x0

.data
.globl	a5
.type	a5, %object
a5:
	.word	0x0

.data
.globl	a4
.type	a4, %object
a4:
	.word	0x0

.data
.globl	a38
.type	a38, %object
a38:
	.word	0x0

.data
.globl	a6
.type	a6, %object
a6:
	.word	0x0

.data
.globl	a0
.type	a0, %object
a0:
	.word	0x0

.data
.globl	a3
.type	a3, %object
a3:
	.word	0x0

.data
.globl	a33
.type	a33, %object
a33:
	.word	0x0

.data
.globl	a2
.type	a2, %object
a2:
	.word	0x0

.data
.globl	a12
.type	a12, %object
a12:
	.word	0x0

.data
.globl	a11
.type	a11, %object
a11:
	.word	0x0

.data
.globl	a26
.type	a26, %object
a26:
	.word	0x0

.data
.globl	a10
.type	a10, %object
a10:
	.word	0x0

.data
.globl	a37
.type	a37, %object
a37:
	.word	0x0

.data
.globl	a1
.type	a1, %object
a1:
	.word	0x0

.data
.globl	a8
.type	a8, %object
a8:
	.word	0x0

.data
.globl	a17
.type	a17, %object
a17:
	.word	0x0

.data
.globl	a35
.type	a35, %object
a35:
	.word	0x0

.data
.globl	a24
.type	a24, %object
a24:
	.word	0x0

.data
.globl	a13
.type	a13, %object
a13:
	.word	0x0

.data
.globl	a9
.type	a9, %object
a9:
	.word	0x0

.data
.globl	a14
.type	a14, %object
a14:
	.word	0x0

.data
.globl	a16
.type	a16, %object
a16:
	.word	0x0

.data
.globl	a34
.type	a34, %object
a34:
	.word	0x0

.data
.globl	a7
.type	a7, %object
a7:
	.word	0x0

.data
.globl	a15
.type	a15, %object
a15:
	.word	0x0

.data
.globl	a25
.type	a25, %object
a25:
	.word	0x0

.data
.globl	a21
.type	a21, %object
a21:
	.word	0x0

.data
.globl	a18
.type	a18, %object
a18:
	.word	0x0

.data
.globl	a19
.type	a19, %object
a19:
	.word	0x0

.data
.globl	a27
.type	a27, %object
a27:
	.word	0x0

.data
.globl	a20
.type	a20, %object
a20:
	.word	0x0

.data
.globl	a22
.type	a22, %object
a22:
	.word	0x0

.data
.globl	a23
.type	a23, %object
a23:
	.word	0x0

.data
.globl	a28
.type	a28, %object
a28:
	.word	0x0

.text
.align 1
.globl	main
.type	main, %function
main:
	push	{lr}
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v1, =a0
	str	v2, [v1]
	ldr	v2, =1
	ldr	v1, =a1
	str	v2, [v1]
	ldr	v2, =2
	ldr	v1, =a2
	str	v2, [v1]
	ldr	v2, =3
	ldr	v1, =a3
	str	v2, [v1]
	ldr	v2, =4
	ldr	v1, =a4
	str	v2, [v1]
	ldr	v2, =5
	ldr	v1, =a5
	str	v2, [v1]
	ldr	v2, =6
	ldr	v1, =a6
	str	v2, [v1]
	ldr	v2, =7
	ldr	v1, =a7
	str	v2, [v1]
	ldr	v2, =8
	ldr	v1, =a8
	str	v2, [v1]
	ldr	v2, =9
	ldr	v1, =a9
	str	v2, [v1]
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v1, =a10
	str	v2, [v1]
	ldr	v2, =1
	ldr	v1, =a11
	str	v2, [v1]
	ldr	v2, =2
	ldr	v1, =a12
	str	v2, [v1]
	ldr	v2, =3
	ldr	v1, =a13
	str	v2, [v1]
	ldr	v2, =4
	ldr	v1, =a14
	str	v2, [v1]
	ldr	v2, =5
	ldr	v1, =a15
	str	v2, [v1]
	ldr	v2, =6
	ldr	v1, =a16
	str	v2, [v1]
	ldr	v2, =7
	ldr	v1, =a17
	str	v2, [v1]
	ldr	v2, =8
	ldr	v1, =a18
	str	v2, [v1]
	ldr	v2, =9
	ldr	v1, =a19
	str	v2, [v1]
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v1, =a20
	str	v2, [v1]
	ldr	v2, =1
	ldr	v1, =a21
	str	v2, [v1]
	ldr	v2, =2
	ldr	v1, =a22
	str	v2, [v1]
	ldr	v2, =3
	ldr	v1, =a23
	str	v2, [v1]
	ldr	v2, =4
	ldr	v1, =a24
	str	v2, [v1]
	ldr	v2, =5
	ldr	v1, =a25
	str	v2, [v1]
	ldr	v2, =6
	ldr	v1, =a26
	str	v2, [v1]
	ldr	v2, =7
	ldr	v1, =a27
	str	v2, [v1]
	ldr	v2, =8
	ldr	v1, =a28
	str	v2, [v1]
	ldr	v2, =9
	ldr	v1, =a29
	str	v2, [v1]
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v1, =a30
	str	v2, [v1]
	ldr	v2, =1
	ldr	v1, =a31
	str	v2, [v1]
	ldr	v2, =4
	ldr	v1, =a32
	str	v2, [v1]
	ldr	v2, =5
	ldr	v1, =a33
	str	v2, [v1]
	ldr	v2, =6
	ldr	v1, =a34
	str	v2, [v1]
	ldr	v2, =7
	ldr	v1, =a35
	str	v2, [v1]
	ldr	v2, =8
	ldr	v1, =a36
	str	v2, [v1]
	ldr	v2, =9
	ldr	v1, =a37
	str	v2, [v1]
	eor	v1, v1, v1
	mov	v2, v1
	ldr	v1, =a38
	str	v2, [v1]
	ldr	v2, =1
	ldr	v1, =a39
	str	v2, [v1]
	ldr	a1, =a0
	ldr	a2, =a1
	ldr	a3, =a2
	ldr	a4, =a3
	ldr	v1, =a4
	str	v1, [sp, #-56]
	ldr	v1, =a5
	str	v1, [sp, #-52]
	ldr	v1, =a6
	str	v1, [sp, #-48]
	ldr	v1, =a7
	str	v1, [sp, #-44]
	add	sp, sp, #-56
	bl	testParam8
	add	sp, sp, #56
	str	a1, [sp, #-20]
	ldr	v1, [sp, #-20]
	ldr	v2, =a0
	str	v1, [v2]
	ldr	a1, =a0
	add	sp, sp, #-56
	bl	putint
	add	sp, sp, #56
	ldr	a1, =a32
	ldr	a2, =a33
	ldr	a3, =a34
	ldr	a4, =a35
	ldr	v1, =a36
	str	v1, [sp, #-120]
	ldr	v1, =a37
	str	v1, [sp, #-116]
	ldr	v1, =a38
	str	v1, [sp, #-112]
	ldr	v1, =a39
	str	v1, [sp, #-108]
	ldr	v1, =a8
	str	v1, [sp, #-104]
	ldr	v1, =a9
	str	v1, [sp, #-100]
	ldr	v1, =a10
	str	v1, [sp, #-96]
	ldr	v1, =a11
	str	v1, [sp, #-92]
	ldr	v1, =a12
	str	v1, [sp, #-88]
	ldr	v1, =a13
	str	v1, [sp, #-84]
	ldr	v1, =a14
	str	v1, [sp, #-80]
	ldr	v1, =a15
	str	v1, [sp, #-76]
	add	sp, sp, #-120
	bl	testParam16
	add	sp, sp, #120
	str	a1, [sp, #-16]
	ldr	v1, [sp, #-16]
	ldr	v2, =a0
	str	v1, [v2]
	ldr	a1, =a0
	add	sp, sp, #-120
	bl	putint
	add	sp, sp, #120
	ldr	a1, =a0
	ldr	a2, =a1
	ldr	a3, =a2
	ldr	a4, =a3
	ldr	v1, =a4
	str	v1, [sp, #-248]
	ldr	v1, =a5
	str	v1, [sp, #-244]
	ldr	v1, =a6
	str	v1, [sp, #-240]
	ldr	v1, =a7
	str	v1, [sp, #-236]
	ldr	v1, =a8
	str	v1, [sp, #-232]
	ldr	v1, =a9
	str	v1, [sp, #-228]
	ldr	v1, =a10
	str	v1, [sp, #-224]
	ldr	v1, =a11
	str	v1, [sp, #-220]
	ldr	v1, =a12
	str	v1, [sp, #-216]
	ldr	v1, =a13
	str	v1, [sp, #-212]
	ldr	v1, =a14
	str	v1, [sp, #-208]
	ldr	v1, =a15
	str	v1, [sp, #-204]
	ldr	v1, =a16
	str	v1, [sp, #-200]
	ldr	v1, =a17
	str	v1, [sp, #-196]
	ldr	v1, =a18
	str	v1, [sp, #-192]
	ldr	v1, =a19
	str	v1, [sp, #-188]
	ldr	v1, =a20
	str	v1, [sp, #-184]
	ldr	v1, =a21
	str	v1, [sp, #-180]
	ldr	v1, =a22
	str	v1, [sp, #-176]
	ldr	v1, =a23
	str	v1, [sp, #-172]
	ldr	v1, =a24
	str	v1, [sp, #-168]
	ldr	v1, =a25
	str	v1, [sp, #-164]
	ldr	v1, =a26
	str	v1, [sp, #-160]
	ldr	v1, =a27
	str	v1, [sp, #-156]
	ldr	v1, =a28
	str	v1, [sp, #-152]
	ldr	v1, =a29
	str	v1, [sp, #-148]
	ldr	v1, =a30
	str	v1, [sp, #-144]
	ldr	v1, =a31
	str	v1, [sp, #-140]
	add	sp, sp, #-248
	bl	testParam32
	add	sp, sp, #248
	str	a1, [sp, #-12]
	ldr	v1, [sp, #-12]
	ldr	v2, =a0
	str	v1, [v2]
	ldr	a1, =a0
	add	sp, sp, #-248
	bl	putint
	add	sp, sp, #248
	eor	v1, v1, v1
	mov	a1, v1
	pop	{pc}
.text
.align 1
.globl	testParam16
.type	testParam16, %function
testParam16:
	push	{lr}
	str	a1, [sp, #-48]
	str	a2, [sp, #-28]
	str	a3, [sp, #-40]
	str	a4, [sp, #-44]
	ldr	v1, [sp]
	str	v1, [sp, #-60]
	ldr	v1, [sp, #4]
	str	v1, [sp, #-68]
	ldr	v1, [sp, #8]
	str	v1, [sp, #-56]
	ldr	v1, [sp, #12]
	str	v1, [sp, #-24]
	ldr	v1, [sp, #16]
	str	v1, [sp, #-52]
	ldr	v1, [sp, #20]
	str	v1, [sp, #-72]
	ldr	v1, [sp, #24]
	str	v1, [sp, #-32]
	ldr	v1, [sp, #28]
	str	v1, [sp, #-64]
	ldr	v1, [sp, #32]
	str	v1, [sp, #-36]
	ldr	v1, [sp, #36]
	str	v1, [sp, #-20]
	ldr	v1, [sp, #40]
	str	v1, [sp, #-16]
	ldr	v1, [sp, #44]
	str	v1, [sp, #-12]
	ldr	v2, [sp, #-48]
	ldr	v3, [sp, #-28]
	add	v1, v2, v3
	str	v1, [sp, #-84]
	ldr	v2, [sp, #-84]
	ldr	v3, [sp, #-40]
	add	v1, v2, v3
	str	v1, [sp, #-100]
	ldr	v1, [sp, #-100]
	ldr	v2, [sp, #-44]
	sub	v3, v1, v2
	str	v3, [sp, #-104]
	ldr	v1, [sp, #-104]
	ldr	v2, [sp, #-60]
	sub	v3, v1, v2
	str	v3, [sp, #-112]
	ldr	v1, [sp, #-112]
	ldr	v2, [sp, #-68]
	sub	v3, v1, v2
	str	v3, [sp, #-120]
	ldr	v1, [sp, #-120]
	ldr	v2, [sp, #-56]
	sub	v3, v1, v2
	str	v3, [sp, #-124]
	ldr	v1, [sp, #-124]
	ldr	v2, [sp, #-24]
	sub	v3, v1, v2
	str	v3, [sp, #-128]
	ldr	v2, [sp, #-128]
	ldr	v3, [sp, #-52]
	add	v1, v2, v3
	str	v1, [sp, #-132]
	ldr	v2, [sp, #-132]
	ldr	v3, [sp, #-72]
	add	v1, v2, v3
	str	v1, [sp, #-88]
	ldr	v2, [sp, #-88]
	ldr	v3, [sp, #-32]
	add	v1, v2, v3
	str	v1, [sp, #-108]
	ldr	v2, [sp, #-108]
	ldr	v3, [sp, #-64]
	add	v1, v2, v3
	str	v1, [sp, #-116]
	ldr	v2, [sp, #-116]
	ldr	v3, [sp, #-36]
	add	v1, v2, v3
	str	v1, [sp, #-92]
	ldr	v2, [sp, #-92]
	ldr	v3, [sp, #-20]
	add	v1, v2, v3
	str	v1, [sp, #-96]
	ldr	v2, [sp, #-96]
	ldr	v3, [sp, #-16]
	add	v1, v2, v3
	str	v1, [sp, #-80]
	ldr	v2, [sp, #-80]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-76]
	ldr	a1, [sp, #-76]
	pop	{pc}
.text
.align 1
.globl	testParam8
.type	testParam8, %function
testParam8:
	push	{lr}
	str	a1, [sp, #-40]
	str	a2, [sp, #-32]
	str	a3, [sp, #-28]
	str	a4, [sp, #-20]
	ldr	v1, [sp]
	str	v1, [sp, #-16]
	ldr	v1, [sp, #4]
	str	v1, [sp, #-12]
	ldr	v1, [sp, #8]
	str	v1, [sp, #-24]
	ldr	v1, [sp, #12]
	str	v1, [sp, #-36]
	ldr	v2, [sp, #-40]
	ldr	v3, [sp, #-32]
	add	v1, v2, v3
	str	v1, [sp, #-68]
	ldr	v2, [sp, #-68]
	ldr	v3, [sp, #-28]
	add	v1, v2, v3
	str	v1, [sp, #-64]
	ldr	v2, [sp, #-64]
	ldr	v3, [sp, #-20]
	add	v1, v2, v3
	str	v1, [sp, #-60]
	ldr	v2, [sp, #-60]
	ldr	v3, [sp, #-16]
	add	v1, v2, v3
	str	v1, [sp, #-56]
	ldr	v2, [sp, #-56]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-52]
	ldr	v2, [sp, #-52]
	ldr	v3, [sp, #-24]
	add	v1, v2, v3
	str	v1, [sp, #-48]
	ldr	v2, [sp, #-48]
	ldr	v3, [sp, #-36]
	add	v1, v2, v3
	str	v1, [sp, #-44]
	ldr	a1, [sp, #-44]
	pop	{pc}
	pop	{pc}
.text
.align 1
.globl	testParam32
.type	testParam32, %function
testParam32:
	push	{lr}
	str	a1, [sp, #-36]
	str	a2, [sp, #-64]
	str	a3, [sp, #-44]
	str	a4, [sp, #-40]
	ldr	v1, [sp]
	str	v1, [sp, #-28]
	ldr	v1, [sp, #4]
	str	v1, [sp, #-24]
	ldr	v1, [sp, #8]
	str	v1, [sp, #-32]
	ldr	v1, [sp, #12]
	str	v1, [sp, #-96]
	ldr	v1, [sp, #16]
	str	v1, [sp, #-68]
	ldr	v1, [sp, #20]
	str	v1, [sp, #-84]
	ldr	v1, [sp, #24]
	str	v1, [sp, #-60]
	ldr	v1, [sp, #28]
	str	v1, [sp, #-52]
	ldr	v1, [sp, #32]
	str	v1, [sp, #-48]
	ldr	v1, [sp, #36]
	str	v1, [sp, #-80]
	ldr	v1, [sp, #40]
	str	v1, [sp, #-88]
	ldr	v1, [sp, #44]
	str	v1, [sp, #-100]
	ldr	v1, [sp, #48]
	str	v1, [sp, #-92]
	ldr	v1, [sp, #52]
	str	v1, [sp, #-72]
	ldr	v1, [sp, #56]
	str	v1, [sp, #-112]
	ldr	v1, [sp, #60]
	str	v1, [sp, #-116]
	ldr	v1, [sp, #64]
	str	v1, [sp, #-124]
	ldr	v1, [sp, #68]
	str	v1, [sp, #-108]
	ldr	v1, [sp, #72]
	str	v1, [sp, #-128]
	ldr	v1, [sp, #76]
	str	v1, [sp, #-132]
	ldr	v1, [sp, #80]
	str	v1, [sp, #-76]
	ldr	v1, [sp, #84]
	str	v1, [sp, #-104]
	ldr	v1, [sp, #88]
	str	v1, [sp, #-56]
	ldr	v1, [sp, #92]
	str	v1, [sp, #-120]
	ldr	v1, [sp, #96]
	str	v1, [sp, #-136]
	ldr	v1, [sp, #100]
	str	v1, [sp, #-20]
	ldr	v1, [sp, #104]
	str	v1, [sp, #-16]
	ldr	v1, [sp, #108]
	str	v1, [sp, #-12]
	ldr	v2, [sp, #-36]
	ldr	v3, [sp, #-64]
	add	v1, v2, v3
	str	v1, [sp, #-240]
	ldr	v2, [sp, #-240]
	ldr	v3, [sp, #-44]
	add	v1, v2, v3
	str	v1, [sp, #-200]
	ldr	v2, [sp, #-200]
	ldr	v3, [sp, #-40]
	add	v1, v2, v3
	str	v1, [sp, #-184]
	ldr	v2, [sp, #-184]
	ldr	v3, [sp, #-28]
	add	v1, v2, v3
	str	v1, [sp, #-168]
	ldr	v2, [sp, #-168]
	ldr	v3, [sp, #-24]
	add	v1, v2, v3
	str	v1, [sp, #-152]
	ldr	v2, [sp, #-152]
	ldr	v3, [sp, #-32]
	add	v1, v2, v3
	str	v1, [sp, #-148]
	ldr	v2, [sp, #-148]
	ldr	v3, [sp, #-96]
	add	v1, v2, v3
	str	v1, [sp, #-144]
	ldr	v2, [sp, #-144]
	ldr	v3, [sp, #-68]
	add	v1, v2, v3
	str	v1, [sp, #-192]
	ldr	v2, [sp, #-192]
	ldr	v3, [sp, #-84]
	add	v1, v2, v3
	str	v1, [sp, #-212]
	ldr	v2, [sp, #-212]
	ldr	v3, [sp, #-60]
	add	v1, v2, v3
	str	v1, [sp, #-180]
	ldr	v2, [sp, #-180]
	ldr	v3, [sp, #-52]
	add	v1, v2, v3
	str	v1, [sp, #-172]
	ldr	v2, [sp, #-172]
	ldr	v3, [sp, #-48]
	add	v1, v2, v3
	str	v1, [sp, #-208]
	ldr	v2, [sp, #-208]
	ldr	v3, [sp, #-80]
	add	v1, v2, v3
	str	v1, [sp, #-204]
	ldr	v2, [sp, #-204]
	ldr	v3, [sp, #-88]
	add	v1, v2, v3
	str	v1, [sp, #-220]
	ldr	v2, [sp, #-220]
	ldr	v3, [sp, #-100]
	add	v1, v2, v3
	str	v1, [sp, #-216]
	ldr	v2, [sp, #-216]
	ldr	v3, [sp, #-92]
	add	v1, v2, v3
	str	v1, [sp, #-224]
	ldr	v2, [sp, #-224]
	ldr	v3, [sp, #-72]
	add	v1, v2, v3
	str	v1, [sp, #-164]
	ldr	v1, [sp, #-164]
	ldr	v2, [sp, #-112]
	sub	v3, v1, v2
	str	v3, [sp, #-228]
	ldr	v1, [sp, #-228]
	ldr	v2, [sp, #-116]
	sub	v3, v1, v2
	str	v3, [sp, #-232]
	ldr	v1, [sp, #-232]
	ldr	v2, [sp, #-124]
	sub	v3, v1, v2
	str	v3, [sp, #-140]
	ldr	v1, [sp, #-140]
	ldr	v2, [sp, #-108]
	sub	v3, v1, v2
	str	v3, [sp, #-244]
	ldr	v1, [sp, #-244]
	ldr	v2, [sp, #-128]
	sub	v3, v1, v2
	str	v3, [sp, #-248]
	ldr	v2, [sp, #-248]
	ldr	v3, [sp, #-132]
	add	v1, v2, v3
	str	v1, [sp, #-196]
	ldr	v2, [sp, #-196]
	ldr	v3, [sp, #-76]
	add	v1, v2, v3
	str	v1, [sp, #-176]
	ldr	v2, [sp, #-176]
	ldr	v3, [sp, #-104]
	add	v1, v2, v3
	str	v1, [sp, #-236]
	ldr	v2, [sp, #-236]
	ldr	v3, [sp, #-56]
	add	v1, v2, v3
	str	v1, [sp, #-252]
	ldr	v2, [sp, #-252]
	ldr	v3, [sp, #-120]
	add	v1, v2, v3
	str	v1, [sp, #-260]
	ldr	v2, [sp, #-260]
	ldr	v3, [sp, #-136]
	add	v1, v2, v3
	str	v1, [sp, #-256]
	ldr	v2, [sp, #-256]
	ldr	v3, [sp, #-20]
	add	v1, v2, v3
	str	v1, [sp, #-156]
	ldr	v2, [sp, #-156]
	ldr	v3, [sp, #-16]
	add	v1, v2, v3
	str	v1, [sp, #-160]
	ldr	v2, [sp, #-160]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-188]
	ldr	a1, [sp, #-188]
	pop	{pc}
