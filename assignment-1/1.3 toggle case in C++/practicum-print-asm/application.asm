.cpu cortex-m0
.align 2
.global application

hello:
	.asciz "Hello world, the ANSWER is 42! @[]`{}~\n"
application:
	push { r5, lr }
	ldr r0, =[hello]
	bl print_asciz
	pop { r5, pc } 