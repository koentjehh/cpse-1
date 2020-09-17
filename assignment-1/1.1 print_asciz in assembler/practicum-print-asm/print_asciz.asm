.cpu cortex-m0 			@ de CPU van de Arduino Due
.align 2				@ zorgt dat adres altijd veelvoud van 2^2 is
.global print_asciz		@ functienaam extern beschikbaar stellen

print_asciz:
	push { r5, lr }
	mov  r5 ,r0
loop:
	ldrb r0, [ r5 ]
	add r0, r0, #0
	beq done
	bl uart_put_char
	add r5, r5, #1
	b loop
done:
	pop { r5, pc }