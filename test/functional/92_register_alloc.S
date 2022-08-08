.data
.globl	a32
.type	a32, %object
a32:
	.word	0x10

.data
.globl	a31
.type	a31, %object
a31:
	.word	0xf

.data
.globl	a30
.type	a30, %object
a30:
	.word	0xe

.data
.globl	a5
.type	a5, %object
a5:
	.word	0x5

.data
.globl	a4
.type	a4, %object
a4:
	.word	0x4

.data
.globl	a6
.type	a6, %object
a6:
	.word	0x6

.data
.globl	a3
.type	a3, %object
a3:
	.word	0x3

.data
.globl	a2
.type	a2, %object
a2:
	.word	0x2

.data
.globl	a12
.type	a12, %object
a12:
	.word	0xc

.data
.globl	a13
.type	a13, %object
a13:
	.word	0xd

.data
.globl	a24
.type	a24, %object
a24:
	.word	0x8

.data
.globl	a11
.type	a11, %object
a11:
	.word	0xb

.data
.globl	a26
.type	a26, %object
a26:
	.word	0xa

.data
.globl	a10
.type	a10, %object
a10:
	.word	0xa

.data
.globl	a1
.type	a1, %object
a1:
	.word	0x1

.data
.globl	a8
.type	a8, %object
a8:
	.word	0x8

.data
.globl	a17
.type	a17, %object
a17:
	.word	0x1

.data
.globl	a9
.type	a9, %object
a9:
	.word	0x9

.data
.globl	a14
.type	a14, %object
a14:
	.word	0xe

.data
.globl	a16
.type	a16, %object
a16:
	.word	0x10

.data
.globl	a7
.type	a7, %object
a7:
	.word	0x7

.data
.globl	a15
.type	a15, %object
a15:
	.word	0xf

.data
.globl	a25
.type	a25, %object
a25:
	.word	0x9

.data
.globl	a21
.type	a21, %object
a21:
	.word	0x5

.data
.globl	a18
.type	a18, %object
a18:
	.word	0x2

.data
.globl	a19
.type	a19, %object
a19:
	.word	0x3

.data
.globl	a27
.type	a27, %object
a27:
	.word	0xb

.data
.globl	a20
.type	a20, %object
a20:
	.word	0x4

.data
.globl	a22
.type	a22, %object
a22:
	.word	0x6

.data
.globl	a29
.type	a29, %object
a29:
	.word	0xd

.data
.globl	a23
.type	a23, %object
a23:
	.word	0x7

.data
.globl	a28
.type	a28, %object
a28:
	.word	0xc

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
	add	sp, sp, #-32
	bl	getint
	add	sp, sp, #32
	str	a1, [sp, #-32]
	ldr	v1, [sp, #-32]
	str	v1, [sp, #-16]
	ldr	v2, =2
	ldr	v3, =9
	mul	v1, v2, v3
	str	v1, [sp, #-28]
	ldr	v2, [sp, #-16]
	ldr	v3, [sp, #-28]
	add	v1, v2, v3
	str	v1, [sp, #-24]
	ldr	v1, [sp, #-24]
	str	v1, [sp, #-12]
	ldr	a1, [sp, #-16]
	ldr	a2, [sp, #-12]
	add	sp, sp, #-32
	bl	func
	add	sp, sp, #32
	str	a1, [sp, #-20]
	ldr	v1, [sp, #-20]
	str	v1, [sp, #-16]
	ldr	a1, [sp, #-16]
	add	sp, sp, #-32
	bl	putint
	add	sp, sp, #32
	ldr	a1, [sp, #-16]
	pop	{pc}
.text
.align 1
.globl	func
.type	func, %function
func:
	push	{lr}
	str	a1, [sp, #-16]
	str	a2, [sp, #-12]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-96]
	ldr	v2, [sp, #-16]
	ldr	v3, [sp, #-12]
	add	v1, v2, v3
	str	v1, [sp, #-524]
	ldr	v1, [sp, #-524]
	str	v1, [sp, #-96]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-92]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-88]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-76]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-72]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-48]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-52]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-64]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-160]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-152]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-124]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-44]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-40]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-84]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-104]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-120]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-60]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-108]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-128]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-136]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-144]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-148]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-132]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-112]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-56]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-156]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-68]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-164]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-80]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-36]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-32]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-140]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-28]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-24]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-116]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-20]
	eor	v1, v1, v1
	mov	v2, v1
	str	v2, [sp, #-100]
	add	sp, sp, #-1008
	bl	getint
	add	sp, sp, #1008
	str	a1, [sp, #-532]
	ldr	v1, [sp, #-532]
	str	v1, [sp, #-92]
	add	sp, sp, #-1008
	bl	getint
	add	sp, sp, #1008
	str	a1, [sp, #-604]
	ldr	v1, [sp, #-604]
	str	v1, [sp, #-88]
	add	sp, sp, #-1008
	bl	getint
	add	sp, sp, #1008
	str	a1, [sp, #-608]
	ldr	v1, [sp, #-608]
	str	v1, [sp, #-76]
	add	sp, sp, #-1008
	bl	getint
	add	sp, sp, #1008
	str	a1, [sp, #-408]
	ldr	v1, [sp, #-408]
	str	v1, [sp, #-72]
	ldr	v2, [sp, #-92]
	add	v1, v2, #1
	str	v1, [sp, #-672]
	ldr	v2, [sp, #-672]
	ldr	v4, =a1
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-456]
	ldr	v1, [sp, #-456]
	str	v1, [sp, #-48]
	ldr	v2, [sp, #-88]
	add	v1, v2, #2
	str	v1, [sp, #-848]
	ldr	v2, [sp, #-848]
	ldr	v4, =a2
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-624]
	ldr	v1, [sp, #-624]
	str	v1, [sp, #-52]
	ldr	v2, [sp, #-76]
	add	v1, v2, #3
	str	v1, [sp, #-572]
	ldr	v2, [sp, #-572]
	ldr	v4, =a3
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-656]
	ldr	v1, [sp, #-656]
	str	v1, [sp, #-64]
	ldr	v2, [sp, #-72]
	add	v1, v2, #4
	str	v1, [sp, #-616]
	ldr	v2, [sp, #-616]
	ldr	v4, =a4
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-452]
	ldr	v1, [sp, #-452]
	str	v1, [sp, #-160]
	ldr	v2, [sp, #-48]
	add	v1, v2, #1
	str	v1, [sp, #-488]
	ldr	v2, [sp, #-488]
	ldr	v4, =a5
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-700]
	ldr	v1, [sp, #-700]
	str	v1, [sp, #-152]
	ldr	v2, [sp, #-52]
	add	v1, v2, #2
	str	v1, [sp, #-424]
	ldr	v2, [sp, #-424]
	ldr	v4, =a6
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-520]
	ldr	v1, [sp, #-520]
	str	v1, [sp, #-124]
	ldr	v2, [sp, #-64]
	add	v1, v2, #3
	str	v1, [sp, #-584]
	ldr	v2, [sp, #-584]
	ldr	v4, =a7
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-448]
	ldr	v1, [sp, #-448]
	str	v1, [sp, #-44]
	ldr	v2, [sp, #-160]
	add	v1, v2, #4
	str	v1, [sp, #-648]
	ldr	v2, [sp, #-648]
	ldr	v4, =a8
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-632]
	ldr	v1, [sp, #-632]
	str	v1, [sp, #-40]
	ldr	v2, [sp, #-152]
	add	v1, v2, #1
	str	v1, [sp, #-980]
	ldr	v2, [sp, #-980]
	ldr	v4, =a9
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-472]
	ldr	v1, [sp, #-472]
	str	v1, [sp, #-84]
	ldr	v2, [sp, #-124]
	add	v1, v2, #2
	str	v1, [sp, #-792]
	ldr	v2, [sp, #-792]
	ldr	v4, =a10
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-300]
	ldr	v1, [sp, #-300]
	str	v1, [sp, #-104]
	ldr	v2, [sp, #-44]
	add	v1, v2, #3
	str	v1, [sp, #-592]
	ldr	v2, [sp, #-592]
	ldr	v4, =a11
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-680]
	ldr	v1, [sp, #-680]
	str	v1, [sp, #-120]
	ldr	v2, [sp, #-40]
	add	v1, v2, #4
	str	v1, [sp, #-688]
	ldr	v2, [sp, #-688]
	ldr	v4, =a12
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-600]
	ldr	v1, [sp, #-600]
	str	v1, [sp, #-60]
	ldr	v2, [sp, #-84]
	add	v1, v2, #1
	str	v1, [sp, #-576]
	ldr	v2, [sp, #-576]
	ldr	v4, =a13
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-612]
	ldr	v1, [sp, #-612]
	str	v1, [sp, #-108]
	ldr	v2, [sp, #-104]
	add	v1, v2, #2
	str	v1, [sp, #-692]
	ldr	v2, [sp, #-692]
	ldr	v4, =a14
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-956]
	ldr	v1, [sp, #-956]
	str	v1, [sp, #-128]
	ldr	v2, [sp, #-120]
	add	v1, v2, #3
	str	v1, [sp, #-304]
	ldr	v2, [sp, #-304]
	ldr	v4, =a15
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-696]
	ldr	v1, [sp, #-696]
	str	v1, [sp, #-136]
	ldr	v2, [sp, #-60]
	add	v1, v2, #4
	str	v1, [sp, #-620]
	ldr	v2, [sp, #-620]
	ldr	v4, =a16
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-416]
	ldr	v1, [sp, #-416]
	str	v1, [sp, #-144]
	ldr	v2, [sp, #-108]
	add	v1, v2, #1
	str	v1, [sp, #-428]
	ldr	v2, [sp, #-428]
	ldr	v4, =a17
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-512]
	ldr	v1, [sp, #-512]
	str	v1, [sp, #-148]
	ldr	v2, [sp, #-128]
	add	v1, v2, #2
	str	v1, [sp, #-484]
	ldr	v2, [sp, #-484]
	ldr	v4, =a18
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-392]
	ldr	v1, [sp, #-392]
	str	v1, [sp, #-132]
	ldr	v2, [sp, #-136]
	add	v1, v2, #3
	str	v1, [sp, #-872]
	ldr	v2, [sp, #-872]
	ldr	v4, =a19
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-436]
	ldr	v1, [sp, #-436]
	str	v1, [sp, #-112]
	ldr	v2, [sp, #-144]
	add	v1, v2, #4
	str	v1, [sp, #-384]
	ldr	v2, [sp, #-384]
	ldr	v4, =a20
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-380]
	ldr	v1, [sp, #-380]
	str	v1, [sp, #-56]
	ldr	v2, [sp, #-148]
	add	v1, v2, #1
	str	v1, [sp, #-920]
	ldr	v2, [sp, #-920]
	ldr	v4, =a21
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-636]
	ldr	v1, [sp, #-636]
	str	v1, [sp, #-156]
	ldr	v2, [sp, #-132]
	add	v1, v2, #2
	str	v1, [sp, #-328]
	ldr	v2, [sp, #-328]
	ldr	v4, =a22
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-492]
	ldr	v1, [sp, #-492]
	str	v1, [sp, #-68]
	ldr	v2, [sp, #-112]
	add	v1, v2, #3
	str	v1, [sp, #-340]
	ldr	v2, [sp, #-340]
	ldr	v4, =a23
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-344]
	ldr	v1, [sp, #-344]
	str	v1, [sp, #-164]
	ldr	v2, [sp, #-56]
	add	v1, v2, #4
	str	v1, [sp, #-360]
	ldr	v2, [sp, #-360]
	ldr	v4, =a24
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-364]
	ldr	v1, [sp, #-364]
	str	v1, [sp, #-80]
	ldr	v2, [sp, #-156]
	add	v1, v2, #1
	str	v1, [sp, #-312]
	ldr	v2, [sp, #-312]
	ldr	v4, =a25
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-752]
	ldr	v1, [sp, #-752]
	str	v1, [sp, #-36]
	ldr	v2, [sp, #-68]
	add	v1, v2, #2
	str	v1, [sp, #-440]
	ldr	v2, [sp, #-440]
	ldr	v4, =a26
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-296]
	ldr	v1, [sp, #-296]
	str	v1, [sp, #-32]
	ldr	v2, [sp, #-164]
	add	v1, v2, #3
	str	v1, [sp, #-776]
	ldr	v2, [sp, #-776]
	ldr	v4, =a27
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-880]
	ldr	v1, [sp, #-880]
	str	v1, [sp, #-140]
	ldr	v2, [sp, #-80]
	add	v1, v2, #4
	str	v1, [sp, #-568]
	ldr	v2, [sp, #-568]
	ldr	v4, =a28
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-292]
	ldr	v1, [sp, #-292]
	str	v1, [sp, #-28]
	ldr	v2, [sp, #-36]
	add	v1, v2, #1
	str	v1, [sp, #-356]
	ldr	v2, [sp, #-356]
	ldr	v4, =a29
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-288]
	ldr	v1, [sp, #-288]
	str	v1, [sp, #-24]
	ldr	v2, [sp, #-32]
	add	v1, v2, #2
	str	v1, [sp, #-668]
	ldr	v2, [sp, #-668]
	ldr	v4, =a30
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-348]
	ldr	v1, [sp, #-348]
	str	v1, [sp, #-116]
	ldr	v2, [sp, #-140]
	add	v1, v2, #3
	str	v1, [sp, #-324]
	ldr	v2, [sp, #-324]
	ldr	v4, =a31
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-736]
	ldr	v1, [sp, #-736]
	str	v1, [sp, #-20]
	ldr	v2, [sp, #-28]
	add	v1, v2, #4
	str	v1, [sp, #-280]
	ldr	v2, [sp, #-280]
	ldr	v4, =a32
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-268]
	ldr	v1, [sp, #-268]
	str	v1, [sp, #-100]
	ldr	v1, [sp, #-16]
	ldr	v2, [sp, #-12]
	sub	v3, v1, v2
	str	v3, [sp, #-720]
	ldr	v2, [sp, #-720]
	add	v1, v2, #10
	str	v1, [sp, #-508]
	ldr	v1, [sp, #-508]
	str	v1, [sp, #-96]
	ldr	v2, [sp, #-36]
	add	v1, v2, #1
	str	v1, [sp, #-864]
	ldr	v2, [sp, #-864]
	ldr	v4, =a29
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-564]
	ldr	v1, [sp, #-564]
	str	v1, [sp, #-24]
	ldr	v2, [sp, #-32]
	add	v1, v2, #2
	str	v1, [sp, #-652]
	ldr	v2, [sp, #-652]
	ldr	v4, =a30
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-256]
	ldr	v1, [sp, #-256]
	str	v1, [sp, #-116]
	ldr	v2, [sp, #-140]
	add	v1, v2, #3
	str	v1, [sp, #-376]
	ldr	v2, [sp, #-376]
	ldr	v4, =a31
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-252]
	ldr	v1, [sp, #-252]
	str	v1, [sp, #-20]
	ldr	v2, [sp, #-28]
	add	v1, v2, #4
	str	v1, [sp, #-316]
	ldr	v2, [sp, #-316]
	ldr	v4, =a32
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-244]
	ldr	v1, [sp, #-244]
	str	v1, [sp, #-100]
	ldr	v2, [sp, #-156]
	add	v1, v2, #1
	str	v1, [sp, #-560]
	ldr	v2, [sp, #-560]
	ldr	v4, =a25
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-240]
	ldr	v1, [sp, #-240]
	str	v1, [sp, #-36]
	ldr	v2, [sp, #-68]
	add	v1, v2, #2
	str	v1, [sp, #-768]
	ldr	v2, [sp, #-768]
	ldr	v4, =a26
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-404]
	ldr	v1, [sp, #-404]
	str	v1, [sp, #-32]
	ldr	v2, [sp, #-164]
	add	v1, v2, #3
	str	v1, [sp, #-708]
	ldr	v2, [sp, #-708]
	ldr	v4, =a27
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-824]
	ldr	v1, [sp, #-824]
	str	v1, [sp, #-140]
	ldr	v2, [sp, #-80]
	add	v1, v2, #4
	str	v1, [sp, #-388]
	ldr	v2, [sp, #-388]
	ldr	v4, =a28
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-724]
	ldr	v1, [sp, #-724]
	str	v1, [sp, #-28]
	ldr	v2, [sp, #-148]
	add	v1, v2, #1
	str	v1, [sp, #-732]
	ldr	v2, [sp, #-732]
	ldr	v4, =a21
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-588]
	ldr	v1, [sp, #-588]
	str	v1, [sp, #-156]
	ldr	v2, [sp, #-132]
	add	v1, v2, #2
	str	v1, [sp, #-740]
	ldr	v2, [sp, #-740]
	ldr	v4, =a22
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-556]
	ldr	v1, [sp, #-556]
	str	v1, [sp, #-68]
	ldr	v2, [sp, #-112]
	add	v1, v2, #3
	str	v1, [sp, #-748]
	ldr	v2, [sp, #-748]
	ldr	v4, =a23
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-764]
	ldr	v1, [sp, #-764]
	str	v1, [sp, #-164]
	ldr	v2, [sp, #-56]
	add	v1, v2, #4
	str	v1, [sp, #-756]
	ldr	v2, [sp, #-756]
	ldr	v4, =a24
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-772]
	ldr	v1, [sp, #-772]
	str	v1, [sp, #-80]
	ldr	v2, [sp, #-108]
	add	v1, v2, #1
	str	v1, [sp, #-728]
	ldr	v2, [sp, #-728]
	ldr	v4, =a17
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-784]
	ldr	v1, [sp, #-784]
	str	v1, [sp, #-148]
	ldr	v2, [sp, #-128]
	add	v1, v2, #2
	str	v1, [sp, #-800]
	ldr	v2, [sp, #-800]
	ldr	v4, =a18
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-412]
	ldr	v1, [sp, #-412]
	str	v1, [sp, #-132]
	ldr	v2, [sp, #-136]
	add	v1, v2, #3
	str	v1, [sp, #-640]
	ldr	v2, [sp, #-640]
	ldr	v4, =a19
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-500]
	ldr	v1, [sp, #-500]
	str	v1, [sp, #-112]
	ldr	v2, [sp, #-144]
	add	v1, v2, #4
	str	v1, [sp, #-660]
	ldr	v2, [sp, #-660]
	ldr	v4, =a20
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-804]
	ldr	v1, [sp, #-804]
	str	v1, [sp, #-56]
	ldr	v2, [sp, #-84]
	add	v1, v2, #1
	str	v1, [sp, #-812]
	ldr	v2, [sp, #-812]
	ldr	v4, =a13
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-760]
	ldr	v1, [sp, #-760]
	str	v1, [sp, #-108]
	ldr	v2, [sp, #-104]
	add	v1, v2, #2
	str	v1, [sp, #-816]
	ldr	v2, [sp, #-816]
	ldr	v4, =a14
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-264]
	ldr	v1, [sp, #-264]
	str	v1, [sp, #-128]
	ldr	v2, [sp, #-120]
	add	v1, v2, #3
	str	v1, [sp, #-828]
	ldr	v2, [sp, #-828]
	ldr	v4, =a15
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-272]
	ldr	v1, [sp, #-272]
	str	v1, [sp, #-136]
	ldr	v2, [sp, #-60]
	add	v1, v2, #4
	str	v1, [sp, #-832]
	ldr	v2, [sp, #-832]
	ldr	v4, =a16
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-836]
	ldr	v1, [sp, #-836]
	str	v1, [sp, #-144]
	ldr	v2, [sp, #-152]
	add	v1, v2, #1
	str	v1, [sp, #-840]
	ldr	v2, [sp, #-840]
	ldr	v4, =a9
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-844]
	ldr	v1, [sp, #-844]
	str	v1, [sp, #-84]
	ldr	v2, [sp, #-124]
	add	v1, v2, #2
	str	v1, [sp, #-684]
	ldr	v2, [sp, #-684]
	ldr	v4, =a10
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-504]
	ldr	v1, [sp, #-504]
	str	v1, [sp, #-104]
	ldr	v2, [sp, #-44]
	add	v1, v2, #3
	str	v1, [sp, #-368]
	ldr	v2, [sp, #-368]
	ldr	v4, =a11
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-528]
	ldr	v1, [sp, #-528]
	str	v1, [sp, #-120]
	ldr	v2, [sp, #-40]
	add	v1, v2, #4
	str	v1, [sp, #-860]
	ldr	v2, [sp, #-860]
	ldr	v4, =a12
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-744]
	ldr	v1, [sp, #-744]
	str	v1, [sp, #-60]
	ldr	v2, [sp, #-48]
	add	v1, v2, #1
	str	v1, [sp, #-468]
	ldr	v2, [sp, #-468]
	ldr	v4, =a5
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-868]
	ldr	v1, [sp, #-868]
	str	v1, [sp, #-152]
	ldr	v2, [sp, #-52]
	add	v1, v2, #2
	str	v1, [sp, #-552]
	ldr	v2, [sp, #-552]
	ldr	v4, =a6
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-900]
	ldr	v1, [sp, #-900]
	str	v1, [sp, #-124]
	ldr	v2, [sp, #-64]
	add	v1, v2, #3
	str	v1, [sp, #-432]
	ldr	v2, [sp, #-432]
	ldr	v4, =a7
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-896]
	ldr	v1, [sp, #-896]
	str	v1, [sp, #-44]
	ldr	v2, [sp, #-160]
	add	v1, v2, #4
	str	v1, [sp, #-876]
	ldr	v2, [sp, #-876]
	ldr	v4, =a8
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-808]
	ldr	v1, [sp, #-808]
	str	v1, [sp, #-40]
	ldr	v2, [sp, #-92]
	add	v1, v2, #1
	str	v1, [sp, #-856]
	ldr	v2, [sp, #-856]
	ldr	v4, =a1
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-476]
	ldr	v1, [sp, #-476]
	str	v1, [sp, #-48]
	ldr	v2, [sp, #-88]
	add	v1, v2, #2
	str	v1, [sp, #-260]
	ldr	v2, [sp, #-260]
	ldr	v4, =a2
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-284]
	ldr	v1, [sp, #-284]
	str	v1, [sp, #-52]
	ldr	v2, [sp, #-76]
	add	v1, v2, #3
	str	v1, [sp, #-820]
	ldr	v2, [sp, #-820]
	ldr	v4, =a3
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-892]
	ldr	v1, [sp, #-892]
	str	v1, [sp, #-64]
	ldr	v2, [sp, #-72]
	add	v1, v2, #4
	str	v1, [sp, #-712]
	ldr	v2, [sp, #-712]
	ldr	v4, =a4
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-852]
	ldr	v1, [sp, #-852]
	str	v1, [sp, #-160]
	ldr	v2, [sp, #-92]
	add	v1, v2, #1
	str	v1, [sp, #-536]
	ldr	v2, [sp, #-536]
	ldr	v4, =a1
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-480]
	ldr	v1, [sp, #-480]
	str	v1, [sp, #-48]
	ldr	v2, [sp, #-88]
	add	v1, v2, #2
	str	v1, [sp, #-884]
	ldr	v2, [sp, #-884]
	ldr	v4, =a2
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-396]
	ldr	v1, [sp, #-396]
	str	v1, [sp, #-52]
	ldr	v2, [sp, #-76]
	add	v1, v2, #3
	str	v1, [sp, #-904]
	ldr	v2, [sp, #-904]
	ldr	v4, =a3
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-984]
	ldr	v1, [sp, #-984]
	str	v1, [sp, #-64]
	ldr	v2, [sp, #-72]
	add	v1, v2, #4
	str	v1, [sp, #-916]
	ldr	v2, [sp, #-916]
	ldr	v4, =a4
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-924]
	ldr	v1, [sp, #-924]
	str	v1, [sp, #-160]
	ldr	v2, [sp, #-96]
	ldr	v3, [sp, #-92]
	add	v1, v2, v3
	str	v1, [sp, #-308]
	ldr	v2, [sp, #-308]
	ldr	v3, [sp, #-88]
	add	v1, v2, v3
	str	v1, [sp, #-464]
	ldr	v2, [sp, #-464]
	ldr	v3, [sp, #-76]
	add	v1, v2, v3
	str	v1, [sp, #-400]
	ldr	v2, [sp, #-400]
	ldr	v3, [sp, #-72]
	add	v1, v2, v3
	str	v1, [sp, #-248]
	ldr	v1, [sp, #-248]
	ldr	v2, [sp, #-48]
	sub	v3, v1, v2
	str	v3, [sp, #-928]
	ldr	v1, [sp, #-928]
	ldr	v2, [sp, #-52]
	sub	v3, v1, v2
	str	v3, [sp, #-888]
	ldr	v1, [sp, #-888]
	ldr	v2, [sp, #-64]
	sub	v3, v1, v2
	str	v3, [sp, #-932]
	ldr	v1, [sp, #-932]
	ldr	v2, [sp, #-160]
	sub	v3, v1, v2
	str	v3, [sp, #-936]
	ldr	v2, [sp, #-936]
	ldr	v3, [sp, #-152]
	add	v1, v2, v3
	str	v1, [sp, #-320]
	ldr	v2, [sp, #-320]
	ldr	v3, [sp, #-124]
	add	v1, v2, v3
	str	v1, [sp, #-944]
	ldr	v2, [sp, #-944]
	ldr	v3, [sp, #-44]
	add	v1, v2, v3
	str	v1, [sp, #-948]
	ldr	v2, [sp, #-948]
	ldr	v3, [sp, #-40]
	add	v1, v2, v3
	str	v1, [sp, #-460]
	ldr	v1, [sp, #-460]
	ldr	v2, [sp, #-84]
	sub	v3, v1, v2
	str	v3, [sp, #-952]
	ldr	v1, [sp, #-952]
	ldr	v2, [sp, #-104]
	sub	v3, v1, v2
	str	v3, [sp, #-780]
	ldr	v1, [sp, #-780]
	ldr	v2, [sp, #-120]
	sub	v3, v1, v2
	str	v3, [sp, #-716]
	ldr	v1, [sp, #-716]
	ldr	v2, [sp, #-60]
	sub	v3, v1, v2
	str	v3, [sp, #-960]
	ldr	v2, [sp, #-960]
	ldr	v3, [sp, #-108]
	add	v1, v2, v3
	str	v1, [sp, #-540]
	ldr	v2, [sp, #-540]
	ldr	v3, [sp, #-128]
	add	v1, v2, v3
	str	v1, [sp, #-704]
	ldr	v2, [sp, #-704]
	ldr	v3, [sp, #-136]
	add	v1, v2, v3
	str	v1, [sp, #-964]
	ldr	v2, [sp, #-964]
	ldr	v3, [sp, #-144]
	add	v1, v2, v3
	str	v1, [sp, #-676]
	ldr	v1, [sp, #-676]
	ldr	v2, [sp, #-148]
	sub	v3, v1, v2
	str	v3, [sp, #-968]
	ldr	v1, [sp, #-968]
	ldr	v2, [sp, #-132]
	sub	v3, v1, v2
	str	v3, [sp, #-972]
	ldr	v1, [sp, #-972]
	ldr	v2, [sp, #-112]
	sub	v3, v1, v2
	str	v3, [sp, #-976]
	ldr	v1, [sp, #-976]
	ldr	v2, [sp, #-56]
	sub	v3, v1, v2
	str	v3, [sp, #-336]
	ldr	v2, [sp, #-336]
	ldr	v3, [sp, #-156]
	add	v1, v2, v3
	str	v1, [sp, #-988]
	ldr	v2, [sp, #-988]
	ldr	v3, [sp, #-68]
	add	v1, v2, v3
	str	v1, [sp, #-664]
	ldr	v2, [sp, #-664]
	ldr	v3, [sp, #-164]
	add	v1, v2, v3
	str	v1, [sp, #-992]
	ldr	v2, [sp, #-992]
	ldr	v3, [sp, #-80]
	add	v1, v2, v3
	str	v1, [sp, #-996]
	ldr	v1, [sp, #-996]
	ldr	v2, [sp, #-36]
	sub	v3, v1, v2
	str	v3, [sp, #-1000]
	ldr	v1, [sp, #-1000]
	ldr	v2, [sp, #-32]
	sub	v3, v1, v2
	str	v3, [sp, #-908]
	ldr	v1, [sp, #-908]
	ldr	v2, [sp, #-140]
	sub	v3, v1, v2
	str	v3, [sp, #-580]
	ldr	v1, [sp, #-580]
	ldr	v2, [sp, #-28]
	sub	v3, v1, v2
	str	v3, [sp, #-372]
	ldr	v2, [sp, #-372]
	ldr	v3, [sp, #-24]
	add	v1, v2, v3
	str	v1, [sp, #-352]
	ldr	v2, [sp, #-352]
	ldr	v3, [sp, #-116]
	add	v1, v2, v3
	str	v1, [sp, #-1004]
	ldr	v2, [sp, #-1004]
	ldr	v3, [sp, #-20]
	add	v1, v2, v3
	str	v1, [sp, #-796]
	ldr	v2, [sp, #-796]
	ldr	v3, [sp, #-100]
	add	v1, v2, v3
	str	v1, [sp, #-1008]
	ldr	v2, [sp, #-1008]
	ldr	v4, =a1
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-596]
	ldr	v1, [sp, #-596]
	ldr	v3, =a2
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-628]
	ldr	v2, [sp, #-628]
	ldr	v4, =a3
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-496]
	ldr	v1, [sp, #-496]
	ldr	v3, =a4
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-544]
	ldr	v2, [sp, #-544]
	ldr	v4, =a5
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-444]
	ldr	v1, [sp, #-444]
	ldr	v3, =a6
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-236]
	ldr	v2, [sp, #-236]
	ldr	v4, =a7
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-232]
	ldr	v1, [sp, #-232]
	ldr	v3, =a8
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-224]
	ldr	v2, [sp, #-224]
	ldr	v4, =a9
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-220]
	ldr	v1, [sp, #-220]
	ldr	v3, =a10
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-216]
	ldr	v2, [sp, #-216]
	ldr	v4, =a11
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-212]
	ldr	v1, [sp, #-212]
	ldr	v3, =a12
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-548]
	ldr	v2, [sp, #-548]
	ldr	v4, =a13
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-208]
	ldr	v1, [sp, #-208]
	ldr	v3, =a14
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-204]
	ldr	v2, [sp, #-204]
	ldr	v4, =a15
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-332]
	ldr	v1, [sp, #-332]
	ldr	v3, =a16
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-200]
	ldr	v2, [sp, #-200]
	ldr	v4, =a17
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-196]
	ldr	v1, [sp, #-196]
	ldr	v3, =a18
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-644]
	ldr	v2, [sp, #-644]
	ldr	v4, =a19
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-192]
	ldr	v1, [sp, #-192]
	ldr	v3, =a20
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-420]
	ldr	v2, [sp, #-420]
	ldr	v4, =a21
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-788]
	ldr	v1, [sp, #-788]
	ldr	v3, =a22
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-276]
	ldr	v2, [sp, #-276]
	ldr	v4, =a23
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-188]
	ldr	v1, [sp, #-188]
	ldr	v3, =a24
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-184]
	ldr	v2, [sp, #-184]
	ldr	v4, =a25
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-180]
	ldr	v1, [sp, #-180]
	ldr	v3, =a26
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-940]
	ldr	v2, [sp, #-940]
	ldr	v4, =a27
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-228]
	ldr	v1, [sp, #-228]
	ldr	v3, =a28
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-176]
	ldr	v2, [sp, #-176]
	ldr	v4, =a29
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-172]
	ldr	v1, [sp, #-172]
	ldr	v3, =a30
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-516]
	ldr	v2, [sp, #-516]
	ldr	v4, =a31
	ldr	v3, [v4]
	add	v1, v2, v3
	str	v1, [sp, #-168]
	ldr	v1, [sp, #-168]
	ldr	v3, =a32
	ldr	v2, [v3]
	sub	v3, v1, v2
	str	v3, [sp, #-912]
	ldr	a1, [sp, #-912]
	pop	{pc}
	pop	{pc}
