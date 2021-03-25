section .text
global _ft_write
_ft_write:
	mov rcx, 0
_copy_bytes:
	mov rdi,