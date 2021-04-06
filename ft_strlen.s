section .text
global _ft_strlen
_ft_strlen:
	mov rcx, 0 ; inicializo rcx a 0(será mi contador)
_lenloop:
	cmp BYTE[rdi + rcx], 0 ; comparo las dos, 0 y el byte en rdi(el comienzo del string que me pasan) + rcx(el contador que llevo)
	jz end ; jz indica si la comparacion anterior da 0(cuando se haya alcanzado el final del string ya que es un nulo) me realize algo, en este caso saltarme a end
	add rcx, 1 ; aumento en contador en 1
	jmp _lenloop ; jmp salta directamente a la funcion que le diga
end:
	mov rax, rcx ; pongo en rax(mi valor de retorno) el contador, el numero de caracteres que he contado
	ret ; retorno rax, (numero de caracteres)
