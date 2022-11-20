AREA Ram, DATA, NOINIT, READWRITE
; RAM Entrada	
s DCD 0 
t DCD 0 
u DCD 0 
v DCD 0 
; RAM Salida	
XL DCD 0 
XH DCD 0
Y DCD 0
Z DCD 0
	
	AREA Trabajo, CODE, READONLY
	ENTRY
	EXPORT __main

g		DCD -40000			;0xFFFF63C0		
h		DCD 500				;0x1F4
k		DCD 80				;0x50		
p		DCD 123456789		;0x75BCD15		

__main

CONST_A EQU 100
CONST_G EQU 5
	
	LDR R0, =g
	
	LDR R1, [R0]		; valor de g
	LDR R2, [R0, #4]		; valor de h
	LDR R3, [R0, #8]		; valor de k
	LDR R4, [R0, #12]		; valor de p
	
	LDR R0, =s				
		
	STR R1, [R0]		; s = g		
	STR R2, [R0, #4]		; t = h
	STR R3, [R0, #8]		; u = k
	STR R4, [R0, #12]		; v = p
	
	MOV R5, #CONST_A	; A
	MOV R6, #CONST_G	; G

; X=[s*(t/g) + (s-t)/(A-u)] *v

	SUB R7, R1, R2		; (s-t)
	SUB R5, R5, R3		; (A-u)
	SDIV R5, R7, R5		; (s-t)/(A-u)
	SDIV R7, R2, R6		; (t/g)
	MLA R7, R1, R7, R5 		; [s*(t/g) + (s-t)/(A-u)]
	SMULL R8, R9, R7, R4 	; [s*(t/g) + (s-t)/(A-u)] *v
							; R8 = XL, R9 = XH
	
	ASR R10, R9, #2					; Y= (XH >> 2^34)
		
	USAT R11, #9, R2, ASR #1	; Z
	
	LDR R0, =XL
	STR R8, [R0]			; XL LSB
	STR R9, [R0, #4]			; XH MSB
	STR R10, [R0, #8]			; Y
	STR R11, [R0, #12]			; Z
	
STOP	B STOP
		END
