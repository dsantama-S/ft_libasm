section .text
global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
_ft_strdup:
	push	rdi ; reservo rdi para que no sea alterado
	call	_ft_strlen
	inc		rax
	mov		rdi, rax
	call	_malloc
	pop		rdi
	mov		rsi, rdi ; coloco mi string en el 2 argumento
	mov		rdi, rax ; coloco mi reserva de memoria en el primero
	call	_ft_strcpy ; copio rsi en rdi
	ret