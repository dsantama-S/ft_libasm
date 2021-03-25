section .text
global _ft_strcmp
_ft_strcmp:
	mov rcx, 0
_compare_bytes:
	mov al, BYTE[rsi + rcx]
	cmp BYTE[rdi + rcx], al
	ja byte_h
	jnae byte_l
	cmp BYTE[rdi + rcx], 0
	jz equal
	inc rcx
	jmp _compare_bytes
equal:
	mov rax, 0
	ret
byte_l:
	mov rax, -1
	ret
byte_h:
	mov rax, 1
	ret