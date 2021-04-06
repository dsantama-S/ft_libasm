section .text
global _ft_read
_ft_read:
	mov rax, 0x2000003
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