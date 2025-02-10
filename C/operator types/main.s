	.file	"main.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Duplicar numero\0"
.LC1:
	.ascii "--------\0"
.LC2:
	.ascii "Ingresa un numero\12 > \0"
.LC3:
	.ascii "%d\0"
.LC4:
	.ascii "Resultado: %d\12\12...\0"
	.text
	.globl	DuplicateNumber
	.def	DuplicateNumber;	.scl	2;	.type	32;	.endef
	.seh_proc	DuplicateNumber
DuplicateNumber:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$0, -4(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	-4(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, %edx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getch
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC5:
	.ascii "Raiz de un numero\0"
	.align 8
.LC6:
	.ascii "No es posible calcular para negativos.\12\12...\0"
.LC9:
	.ascii "Resultado: %0.5f\12\12...\0"
	.text
	.globl	SquareRootNumber
	.def	SquareRootNumber;	.scl	2;	.type	32;	.endef
	.seh_proc	SquareRootNumber
SquareRootNumber:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$0, -12(%rbp)
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-12(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	-12(%rbp), %eax
	testl	%eax, %eax
	jns	.L4
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getch
	jmp	.L3
.L4:
	movl	-12(%rbp), %eax
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%eax, %xmm0
	movss	%xmm0, -4(%rbp)
	movss	.LC7(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	jmp	.L6
.L7:
	movl	-12(%rbp), %eax
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%eax, %xmm0
	divss	-4(%rbp), %xmm0
	addss	-4(%rbp), %xmm0
	movss	.LC8(%rip), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, -4(%rbp)
.L6:
	movss	-4(%rbp), %xmm0
	mulss	%xmm0, %xmm0
	movl	-12(%rbp), %eax
	pxor	%xmm1, %xmm1
	cvtsi2ssl	%eax, %xmm1
	subss	%xmm1, %xmm0
	comiss	-8(%rbp), %xmm0
	ja	.L7
	movl	-12(%rbp), %eax
	pxor	%xmm1, %xmm1
	cvtsi2ssl	%eax, %xmm1
	movss	-4(%rbp), %xmm0
	movaps	%xmm0, %xmm2
	mulss	%xmm0, %xmm2
	subss	%xmm2, %xmm1
	movaps	%xmm1, %xmm0
	comiss	-8(%rbp), %xmm0
	ja	.L7
	pxor	%xmm0, %xmm0
	cvtss2sd	-4(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movq	%xmm1, %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %rdx
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getch
	nop
.L3:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC10:
	.ascii "Es par\0"
.LC11:
	.ascii "Es impar\0"
.LC12:
	.ascii "\12\12...\0"
	.text
	.globl	OddOrEven
	.def	OddOrEven;	.scl	2;	.type	32;	.endef
	.seh_proc	OddOrEven
OddOrEven:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, -4(%rbp)
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$31, %eax
	addl	%eax, %edx
	andl	$1, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	$1, %eax
	je	.L10
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L11
.L10:
	leaq	.LC11(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L11:
	leaq	.LC12(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getch
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC13:
	.ascii "Cuadrado de un numero\0"
	.text
	.globl	SquareNumber
	.def	SquareNumber;	.scl	2;	.type	32;	.endef
	.seh_proc	SquareNumber
SquareNumber:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$0, -16(%rbp)
	leaq	.LC13(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, -4(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L13
.L15:
	movl	-8(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L14
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	addl	%eax, -4(%rbp)
.L14:
	addl	$1, -12(%rbp)
	sarl	-8(%rbp)
.L13:
	cmpl	$0, -8(%rbp)
	jne	.L15
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getch
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC14:
	.ascii "CLS\0"
.LC15:
	.ascii "Elige una opcion:\0"
	.align 8
.LC16:
	.ascii "  [1] Calcular el doble de un numero.\0"
.LC17:
	.ascii "  [2] Calcular raiz cuadrada.\0"
	.align 8
.LC18:
	.ascii "  [3] Verificar numero par o impar.\0"
	.align 8
.LC19:
	.ascii "  [4] Calcular cuadrado de un numero.\0"
.LC20:
	.ascii "  ---------------\0"
.LC21:
	.ascii "  [5] Salir.\0"
.LC22:
	.ascii "> \0"
.LC23:
	.ascii "Saliendo\12\12...\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movb	$0, -1(%rbp)
.L26:
	leaq	.LC14(%rip), %rax
	movq	%rax, %rcx
	call	system
	leaq	.LC15(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC16(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC17(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC18(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC19(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC20(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC21(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC22(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getch
	movb	%al, -1(%rbp)
	leaq	.LC14(%rip), %rax
	movq	%rax, %rcx
	call	system
	movsbl	-1(%rbp), %eax
	subl	$49, %eax
	cmpl	$4, %eax
	ja	.L28
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L20(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L20(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L20:
	.long	.L24-.L20
	.long	.L23-.L20
	.long	.L22-.L20
	.long	.L21-.L20
	.long	.L19-.L20
	.text
.L24:
	call	DuplicateNumber
	jmp	.L25
.L23:
	call	SquareRootNumber
	jmp	.L25
.L22:
	call	OddOrEven
	jmp	.L25
.L21:
	call	SquareNumber
	jmp	.L25
.L19:
	leaq	.LC23(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getch
	jmp	.L25
.L28:
	nop
.L25:
	cmpb	$53, -1(%rbp)
	jne	.L26
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC7:
	.long	925353388
	.align 4
.LC8:
	.long	1073741824
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev3, Built by MSYS2 project) 14.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	getch;	.scl	2;	.type	32;	.endef
	.def	system;	.scl	2;	.type	32;	.endef
