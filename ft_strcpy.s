section .text
global _ft_strcpy
_ft_strcpy:
	mov rcx, 0
_copy_bytes:
	mov rdi + rcx, rsi + rcx
	cmp BYTE[rdi + rcx], 0
	jz end
	inc rcx
	jmp _copy_bytes
end:
	mov rax, rdi
	ret