	.file	"b1_pointer1.c"
	.text
	.section	.rodata
.LC0:
	.string	"\nStart new ..."
.LC1:
	.string	"value at index 0: %d\n"
	.align 8
.LC2:
	.string	"In new array, index [%d] value: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$99, -64(%rbp)
	movl	$1, -60(%rbp)
	movl	$2, -56(%rbp)
	movl	$3, -52(%rbp)
	movl	$4, -48(%rbp)
	movl	$5, -44(%rbp)
	movl	$6, -40(%rbp)
	movl	$7, -36(%rbp)
	movl	$8, -32(%rbp)
	movl	$9, -28(%rbp)
	movl	$10, -24(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-80(%rbp), %rax
	addq	$12, %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-72(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	%rdx, -72(%rbp)
	movl	$200, (%rax)
	movl	$0, -92(%rbp)
	jmp	.L2
.L3:
	movq	-88(%rbp), %rax
	movl	(%rax), %edx
	movl	-92(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$4, -88(%rbp)
	addl	$1, -92(%rbp)
.L2:
	cmpl	$10, -92(%rbp)
	jle	.L3
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
