.cpu cortex-m0
.align 2
.global decoder

.data
buffer:
	.skip 100 
	
.text
decoder:
    push { r5, lr }			@ push r5 en lr op stack
    ldr r0, =[wilhelmus]    @ laad gecodeerde asciz uit compressed.asm
    mov r5, r0				@ kopieer inhoud r0 naar r5
loop_decoder:
    ldrb r0, [ r5 ]			@ laad (zero-extended) byte uit r5 in r0
    cmp r0, #0         		
	beq done_decoder		@ als r0 == 0 waar is roep done_decoder aan (einde van asciz) 	
    cmp r0, #'@'      		
    beq match				@ als r0 == '@' codering gevonden
    bl add            
    add r5, r5, #1			@ tel 1 op bij r5
	b loop_decoder
match:
    add r5, r5, #1			@ tel 1 op bij r5
    ldrb r7, [ r5 ]   		@ laad (zero-extended) byte uit r5 in r7 (int offset)
    add r5, r5, #1			@ tel 1 op bij r5
	sub r7, r7, #'0'  		@ haal '0' weg van r7 (offset)
    ldrb r4, [ r5 ]			@ laad (zero-extended) byte uit r5 in r7 (int length)   
    add r5, r5, #1    		@ tel 1 op bij r5
    sub r4, r4, #'0'  		@ haal '0' weg van r7 (length)
    ldr r6, =[buffer]   
loop_match:
    ldrb r0, [ r6, r7 ]   	@ laad (zero-extended) byte uit r6/7 in r0
    bl add            
    sub r4, r4, #1      	@ haal 1 af van r4 (length)
    cmp r4, #0          	
    beq loop_decoder		@ als r4 == 0 (dus als 'lenght' 0 is)
    b loop_match
add:
    push {r4, lr}			@ plaats r4 (length) en lr op de stack
    mov r4, r0				@ kopieer inhoud r0 naar r4
    ldr r3, =[buffer]   
    mov r1, #99  			@ de buffer - 1     
    add r1, r3, r1    		@ tel r3 en r1 bij elkaar op
loop_add:
    ldrb r2, [ r1 ]     	@
    strb r2, [ r1, #1 ]  	@
    cmp r1, r3        
    beq add_write			@ als r1 == r3   
    sub r1, r1, #1 			   
    b loop_add     
add_write:
    strb r4, [ r3 ]
	bl print_char 			@ print chars 	
    pop { r4, pc }			@ pop r4 (length) en pc van de stack   		
done_decoder:
	pop { r5, pc }			@ pop r5 (reg met asciz inhoud) en pc van de stack   	