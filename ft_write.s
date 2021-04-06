section .text
global _ft_write
_ft_write:
	mov rax, 0x2000004
	mov r8, rdx
	syscall
	jb error
	jmp end
error:
	mov rax, -1
	ret
end:
	mov rax, r8
	ret