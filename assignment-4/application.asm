.cpu cortex-m0
.align 2
.global application
.text

application:
	push { r5, lr }
	ldr r0, =[wilhelmus]
	bl decoder
	pop { r5, pc } 