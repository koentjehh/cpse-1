.cpu cortex-m0
.align 2
.global invert_char

invert_char:
	push { r5, lr }
	mov r5 ,r0
	cmp	 r0, #97
	bgt is_klein
	bl is_groot
is_klein:
	cmp r0, #122
	ble klein_naar_groot
	bl is_groot
is_groot:
	cmp r0, #65
	bge groot_naar_klein
	bl done
klein_naar_groot:
	sub r0, r0, #32
	bl done
groot_naar_klein:
	cmp r0, #90
	bgt done
	add r0, r0, #32
	bl done
done:
	pop { r5, pc }