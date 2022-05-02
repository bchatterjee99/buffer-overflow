.global _start
	.text
_start:
	movq $0xaabbccdd, %rbx


	# /bin/echo [file name]
	movl $0xffffff6f, %eax
	shlq $56, %rax
	shrq $56, %rax
	pushq %rax
	movl $0x6863652f, %eax
	shlq $32, %rax
	orq $0x6e69622f, %rax
	pushq %rax
	movq %rsp, %rdi

	# hoe geche
	movl $0xffffff65, %eax
	shlq $56, %rax
	shrq $56, %rax
	pushq %rax
	movl $0x68636567, %eax
	shlq $32, %rax
	orq $0x20656f68, %rax
	pushq %rax
	movq %rsp, %rbx # save string location

	## arg array ----------
	xorq %rax, %rax
	pushq %rax # null
	pushq %rbx # hoe geche
	pushq %rdi # /bin/echo
	movq %rsp, %rsi

	# print check
	# movq %rsp, %rsi
	# movq $1, %rax
	# movq $1, %rdi
	# movq $9, %rdx
	# syscall


	# envp argument: rdx
	xorq %rdx, %rdx

	# rax e 0x3b rakhte hobe code e 0 na kore
	movl $0xffffff3b, %eax  # sys_execve
	shlq $56, %rax
	shrq $56, %rax
	syscall
	movq $0xaabbccdd, %rbx
	nop 			# 0x90 ?
	nop
	nop 			
	movq $0xaabbccdd, %rbx


	# exit
	# movq $60, %rax
	# syscall
