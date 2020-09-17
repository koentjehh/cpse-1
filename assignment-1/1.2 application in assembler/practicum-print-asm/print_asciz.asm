.cpu cortex-m0 			@ de CPU van de Arduino Due
.align 2				@ zorgt dat adres altijd veelvoud van 2^2 is
.global print_asciz		@ functienaam extern beschikbaar stellen

print_asciz:			@ functie met naam 'print_asciz'
	push { r5, lr }		@ push genoemde reg r5 en lr op de stack, krulhaakjes = push alles
	mov  r5 ,r0			@ kopieer inhoud van r0 naar r5
loop:					@ functie met naam 'loop'
	ldrb r0, [ r5 ]		@ ?
	add r0, r0, #0		@ register r0 = r0 + immed0 (immed = const getal dat in ingebed zit in de instructie)
	beq done			@ als (r0 en 0) waar is dan naar functie 'done'
	bl uart_put_char	@ roept C functie 'uart_put_char' aan
	add r5, r5, #1		@ register r5 = r5 + immed1
	b loop				@ start de 'loop' functie (soort jump commando)
done:					@ functie 'done'
	pop { r5, pc }		@ pop (return waarde van deze subroutine) r5 en pc van de stack