	TITLE	E:\学习\121110098 曾勇华\test2.c
	.386P
include listing.inc
if @Version gt 510
.model FLAT
else
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS	ENDS
$$SYMBOLS	SEGMENT BYTE USE32 'DEBSYM'
$$SYMBOLS	ENDS
$$TYPES	SEGMENT BYTE USE32 'DEBTYP'
$$TYPES	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
;	COMDAT ??_C@_09ILDJ@hello?5?$CFd?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT _main
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	_main
PUBLIC	??_C@_09ILDJ@hello?5?$CFd?6?$AA@		; `string'
EXTRN	_printf:NEAR
EXTRN	__chkesp:NEAR
;	COMDAT ??_C@_09ILDJ@hello?5?$CFd?6?$AA@
; File e:\学习\121110098 曾勇华\test2.c
CONST	SEGMENT
??_C@_09ILDJ@hello?5?$CFd?6?$AA@ DB 'hello %d', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT _main
_TEXT	SEGMENT
_c$ = -4
_main	PROC NEAR					; COMDAT

; 3    : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-68]
	mov	ecx, 17					; 00000011H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 4    : 	int c;
; 5    : 	c=3+4;

	mov	DWORD PTR _c$[ebp], 7

; 6    : 	printf("hello %d\n",c);

	mov	eax, DWORD PTR _c$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_09ILDJ@hello?5?$CFd?6?$AA@ ; `string'
	call	_printf
	add	esp, 8

; 7    : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 68					; 00000044H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
END
