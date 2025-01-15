//section
//this places variables or functions in a custom section of memory

#include <stdio.h>

int foo __attribute__((section(".my_section"))) = 42;

int main()
{
    printf("Address of foo: %p\n", (void*)&foo);
    return 0;
}

/*
	.file	"c_attributes_ex11.c"
	.text
	.globl	foo
	.section	.my_section,"aw" -------------->  Hey,,,, this is our guy here. :)
	.align 4
	.type	foo, @object
	.size	foo, 4
foo:
	.long	42
	.section	.rodata
.LC0:
	.string	"Address of foo: %p\n"
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
	leaq	foo(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:



*/