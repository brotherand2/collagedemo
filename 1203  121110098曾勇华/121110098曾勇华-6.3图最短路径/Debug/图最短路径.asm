	TITLE	F:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\图最短路径.cpp
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
;	COMDAT ??_C@_03OALE@?$CF4d?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_02HKEJ@?$KB?$NO?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03BMCB@?$CF4s?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_01BJG@?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05MHPM@?$CF?910d?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_08PBJI@?$CFd?$CI?$CFd?$CJ?5?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05NJKD@?$LN?a?$LJ?$PL?3?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03IBOB@?$CF3d?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BN@HPFP@?$CFd?$LF?$LN?$CFd?$LF?D?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?B?$LH?$LO?$LG?N?$KK?3?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04KLBH@?$CF3d?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_06GENM@path?3?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BK@FGLI@?$CFd?$LF?$LN?$CFd?$LF?D?W?n?$LG?L?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_07CIOD@?B?$LH?$LO?$LG?N?$KK?3?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@HGDP@?$LB?$NP?$CI?$CFd?0?$CFd?$CJ?$LF?D?H?$KI?V?$LF?$CFd?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09PMFM@?$CI?$CFd?0?$CFd?$CJ?5?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@FFAH@?5?5?5?5?5?5?5?$KJ?$LD?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@BOFH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM0?$DO?9?9?9?9?9?9?$CI?M?K?$LD?v?$CJExit?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@EIH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM1?$DO?9?9?9?9?9?9?$CI?M?$LM?$LB?i?$MA?z?$CJTRA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@IKLD@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM2?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?H?N?R?b?A?$LN@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@BDAG@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM3?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?R?$LL?$LI?v?$LD?G@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@KDDO@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM4?$DO?9?9?9?9?9?9?$CI?W?n?P?$KB?I?z?$LD?I?J?w@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@GFPL@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM5?$DO?9?9?9?9?9?9?$CI?O?T?J?$LO?M?$LM?P?E?O?$KC@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@HCEG@?5?5?5?5?5?5?5?$KJ?$LL?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@JFAH@121110098?5?5?5?T?x?S?B?$LL?$KK?5?5?5?M?$LM?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@JPPG@?J?d?H?k?D?c?$LF?D?Q?$KB?T?q?$CI0?$HO5?$CJ?3?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_02MECO@?$CFd?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09NNIN@?J?d?H?k?F?p?$LF?c?3?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CF@FIBK@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LH?G?$LF?$NN?$LJ?i?K?c?$LH@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CD@NBJD@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LF?$NN?$LJ?i?K?c?$LH?$KI?$CJ@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@GDAP@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?$LJ?c?$LG?H?S?E?O?HBFS?3?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BN@EHOI@?6?J?d?$LD?v?H?N?R?b?A?$LN?$LI?v?$LD?G?J?P?W?n?$LG?L?B?$LH?$LO?$LG?$KD?$LK?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@DKOB@?F?U?$MA?o?D?$LH?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@JFPN@?$LP?K?B?$LD?K?$LJ?$LP?$KI?$LG?$PL?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@BOPH@?S?P?O?r?M?$LM?$LF?D?A?Z?$LN?S?$LO?X?U?s?3?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@DABI@?6?A?Z?$LN?S?$LO?X?U?s?W?$KK?A?Z?$LN?S?$LB?m?3?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CN@PPOB@?J?d?H?k?$LE?m?N?s?$KD?$KM?$LC?$LL?D?$NM?J?d?H?k?$LH?G?J?$PN?W?V?W?V?$LH?$PL?$KD?$KM?J?d@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ?DispMat1@@YAXUMGraph@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?MatToList1@@YAXUMGraph@@AAPAUALGraph@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DispAdj1@@YAXPAUALGraph@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?ListToMat1@@YAXAAUMGraph@@PAUALGraph@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DFS@@YAXPAUALGraph@@H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DFSAll@@YAXPAUALGraph@@QAHHH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DFS1@@YAXPAUALGraph@@H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DFS2@@YAXPAUALGraph@@H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?BFS1@@YAXPAUALGraph@@H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?ppath@@YAXQAY06HHH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DisPath@@YAXQAY06H0H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?floyd@@YAXUMGraph@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DisPath@@YAXQAH0HH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Dijkstra@@YAXUMGraph@@H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Prim@@YAXUMGraph@@H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SortEdge@@YAXUMGraph@@QAUEdge@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Kruskal@@YAXQAUEdge@@HH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?boot@@YAXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _main
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?visit@@3PAHA					; visit
_BSS	SEGMENT
?visit@@3PAHA DD 064H DUP (?)				; visit
_BSS	ENDS
PUBLIC	?boot@@YAXXZ					; boot
PUBLIC	??_C@_0EF@FFAH@?5?5?5?5?5?5?5?$KJ?$LD?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@ ; `string'
PUBLIC	??_C@_0EF@BOFH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM0?$DO?9?9?9?9?9?9?$CI?M?K?$LD?v?$CJExit?5@ ; `string'
PUBLIC	??_C@_0EF@EIH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM1?$DO?9?9?9?9?9?9?$CI?M?$LM?$LB?i?$MA?z?$CJTRA@ ; `string'
PUBLIC	??_C@_0EF@IKLD@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM2?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?H?N?R?b?A?$LN@ ; `string'
PUBLIC	??_C@_0EF@BDAG@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM3?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?R?$LL?$LI?v?$LD?G@ ; `string'
PUBLIC	??_C@_0EF@KDDO@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM4?$DO?9?9?9?9?9?9?$CI?W?n?P?$KB?I?z?$LD?I?J?w@ ; `string'
PUBLIC	??_C@_0EF@GFPL@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM5?$DO?9?9?9?9?9?9?$CI?O?T?J?$LO?M?$LM?P?E?O?$KC@ ; `string'
PUBLIC	??_C@_0EF@HCEG@?5?5?5?5?5?5?5?$KJ?$LL?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@ ; `string'
EXTRN	__chkesp:NEAR
EXTRN	_printf:NEAR
;	COMDAT ??_C@_0EF@FFAH@?5?5?5?5?5?5?5?$KJ?$LD?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@
; File F:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\图最短路径.cpp
CONST	SEGMENT
??_C@_0EF@FFAH@?5?5?5?5?5?5?5?$KJ?$LD?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@ DB ' '
	DB	'      ', 0a9H, 0b3H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H
	DB	0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H
	DB	0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H
	DB	0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H
	DB	0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H
	DB	0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0b7H, 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0EF@BOFH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM0?$DO?9?9?9?9?9?9?$CI?M?K?$LD?v?$CJExit?5@
CONST	SEGMENT
??_C@_0EF@BOFH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM0?$DO?9?9?9?9?9?9?$CI?M?K?$LD?v?$CJExit?5@ DB ' '
	DB	'      ', 0a9H, 0a7H, '   <0>------(', 0cdH, 0cbH, 0b3H, 0f6H, ')'
	DB	'Exit                                  ', 0a9H, 0a7H, 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0EF@EIH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM1?$DO?9?9?9?9?9?9?$CI?M?$LM?$LB?i?$MA?z?$CJTRA@
CONST	SEGMENT
??_C@_0EF@EIH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM1?$DO?9?9?9?9?9?9?$CI?M?$LM?$LB?i?$MA?z?$CJTRA@ DB ' '
	DB	'      ', 0a9H, 0a7H, '   <1>------(', 0cdH, 0bcH, 0b1H, 0e9H, 0c0H
	DB	0faH, ')TRAVEL                              ', 0a9H, 0a7H, 0aH
	DB	00H						; `string'
CONST	ENDS
;	COMDAT ??_C@_0EF@IKLD@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM2?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?H?N?R?b?A?$LN@
CONST	SEGMENT
??_C@_0EF@IKLD@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM2?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?H?N?R?b?A?$LN@ DB ' '
	DB	'      ', 0a9H, 0a7H, '   <2>------(', 0caH, 0e4H, 0b3H, 0f6H, 0c8H
	DB	0ceH, 0d2H, 0e2H, 0c1H, 0bdH, 0b8H, 0f6H, 0b3H, 0c7H, 0caH, 0d0H
	DB	0d7H, 0eeH, 0b6H, 0ccH, 0c2H, 0b7H, 0beH, 0b6H, ')PATH        '
	DB	'      ', 0a9H, 0a7H, 0aH, 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0EF@BDAG@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM3?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?R?$LL?$LI?v?$LD?G@
CONST	SEGMENT
??_C@_0EF@BDAG@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM3?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?R?$LL?$LI?v?$LD?G@ DB ' '
	DB	'      ', 0a9H, 0a7H, '   <3>------(', 0caH, 0e4H, 0b3H, 0f6H, 0d2H
	DB	0bbH, 0b8H, 0f6H, 0b3H, 0c7H, 0caH, 0d0H, 0b5H, 0bdH, 0cbH, 0f9H
	DB	0d3H, 0d0H, 0b3H, 0c7H, 0caH, 0d0H, 0b5H, 0c4H, 0d7H, 0eeH, 0b6H
	DB	0ccH, 0c2H, 0b7H, 0beH, 0b6H, ')PATH      ', 0a9H, 0a7H, 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0EF@KDDO@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM4?$DO?9?9?9?9?9?9?$CI?W?n?P?$KB?I?z?$LD?I?J?w@
CONST	SEGMENT
??_C@_0EF@KDDO@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM4?$DO?9?9?9?9?9?9?$CI?W?n?P?$KB?I?z?$LD?I?J?w@ DB ' '
	DB	'      ', 0a9H, 0a7H, '   <4>------(', 0d7H, 0eeH, 0d0H, 0a1H, 0c9H
	DB	0faH, 0b3H, 0c9H, 0caH, 0f7H, ')SHORTEST TREE                 '
	DB	'  ', 0a9H, 0a7H, 0aH, 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0EF@GFPL@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM5?$DO?9?9?9?9?9?9?$CI?O?T?J?$LO?M?$LM?P?E?O?$KC@
CONST	SEGMENT
??_C@_0EF@GFPL@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM5?$DO?9?9?9?9?9?9?$CI?O?T?J?$LO?M?$LM?P?E?O?$KC@ DB ' '
	DB	'      ', 0a9H, 0a7H, '   <5>------(', 0cfH, 0d4H, 0caH, 0beH, 0cdH
	DB	0bcH, 0d0H, 0c5H, 0cfH, 0a2H, ')SHOW                          '
	DB	'  ', 0a9H, 0a7H, 0aH, 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0EF@HCEG@?5?5?5?5?5?5?5?$KJ?$LL?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@
CONST	SEGMENT
??_C@_0EF@HCEG@?5?5?5?5?5?5?5?$KJ?$LL?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@ DB ' '
	DB	'      ', 0a9H, 0bbH, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H
	DB	0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H
	DB	0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H
	DB	0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H
	DB	0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H
	DB	0a5H, 0a9H, 0a5H, 0a9H, 0a5H, 0a9H, 0bfH, 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ?boot@@YAXXZ
_TEXT	SEGMENT
?boot@@YAXXZ PROC NEAR					; boot, COMDAT

; 4    : {

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-64]
	mov	ecx, 16					; 00000010H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 5    :     printf("       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");

	push	OFFSET FLAT:??_C@_0EF@FFAH@?5?5?5?5?5?5?5?$KJ?$LD?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@ ; `string'
	call	_printf
	add	esp, 4

; 6    : 	printf("       ┃   <0>------(退出)Exit                                  ┃\n");

	push	OFFSET FLAT:??_C@_0EF@BOFH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM0?$DO?9?9?9?9?9?9?$CI?M?K?$LD?v?$CJExit?5@ ; `string'
	call	_printf
	add	esp, 4

; 7    : 	printf("       ┃   <1>------(图遍历)TRAVEL                              ┃\n");

	push	OFFSET FLAT:??_C@_0EF@EIH@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM1?$DO?9?9?9?9?9?9?$CI?M?$LM?$LB?i?$MA?z?$CJTRA@ ; `string'
	call	_printf
	add	esp, 4

; 8    : 	printf("       ┃   <2>------(输出任意两个城市最短路径)PATH              ┃\n");

	push	OFFSET FLAT:??_C@_0EF@IKLD@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM2?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?H?N?R?b?A?$LN@ ; `string'
	call	_printf
	add	esp, 4

; 9    : 	printf("       ┃   <3>------(输出一个城市到所有城市的最短路径)PATH      ┃\n");

	push	OFFSET FLAT:??_C@_0EF@BDAG@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM3?$DO?9?9?9?9?9?9?$CI?J?d?$LD?v?R?$LL?$LI?v?$LD?G@ ; `string'
	call	_printf
	add	esp, 4

; 10   : 	printf("       ┃   <4>------(最小生成树)SHORTEST TREE                   ┃\n");

	push	OFFSET FLAT:??_C@_0EF@KDDO@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM4?$DO?9?9?9?9?9?9?$CI?W?n?P?$KB?I?z?$LD?I?J?w@ ; `string'
	call	_printf
	add	esp, 4

; 11   : 	printf("       ┃   <5>------(显示图信息)SHOW                            ┃\n");

	push	OFFSET FLAT:??_C@_0EF@GFPL@?5?5?5?5?5?5?5?$KJ?$KH?5?5?5?$DM5?$DO?9?9?9?9?9?9?$CI?O?T?J?$LO?M?$LM?P?E?O?$KC@ ; `string'
	call	_printf
	add	esp, 4

; 12   : 	printf("       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	push	OFFSET FLAT:??_C@_0EF@HCEG@?5?5?5?5?5?5?5?$KJ?$LL?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ?$KF?$KJ@ ; `string'
	call	_printf
	add	esp, 4

; 13   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 64					; 00000040H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?boot@@YAXXZ ENDP					; boot
_TEXT	ENDS
PUBLIC	?DispMat1@@YAXUMGraph@@@Z			; DispMat1
PUBLIC	??_C@_03OALE@?$CF4d?$AA@			; `string'
PUBLIC	??_C@_02HKEJ@?$KB?$NO?$AA@			; `string'
PUBLIC	??_C@_03BMCB@?$CF4s?$AA@			; `string'
PUBLIC	??_C@_01BJG@?6?$AA@				; `string'
;	COMDAT ??_C@_03OALE@?$CF4d?$AA@
; File f:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\graph.h
CONST	SEGMENT
??_C@_03OALE@?$CF4d?$AA@ DB '%4d', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_02HKEJ@?$KB?$NO?$AA@
CONST	SEGMENT
??_C@_02HKEJ@?$KB?$NO?$AA@ DB 0a1H, 0deH, 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_03BMCB@?$CF4s?$AA@
CONST	SEGMENT
??_C@_03BMCB@?$CF4s?$AA@ DB '%4s', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_01BJG@?6?$AA@
CONST	SEGMENT
??_C@_01BJG@?6?$AA@ DB 0aH, 00H				; `string'
CONST	ENDS
;	COMDAT ?DispMat1@@YAXUMGraph@@@Z
_TEXT	SEGMENT
_g$ = 8
_i$ = -4
_j$ = -8
?DispMat1@@YAXUMGraph@@@Z PROC NEAR			; DispMat1, COMDAT

; 42   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-72]
	mov	ecx, 18					; 00000012H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 43   : 	int i,j;
; 44   : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L653
$L654:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L653:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L655

; 46   : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L656
$L657:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L656:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L658

; 48   : 			if(g.edges[i][j]!=INF)

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	lea	edx, DWORD PTR _g$[ebp+ecx]
	mov	eax, DWORD PTR _j$[ebp]
	cmp	DWORD PTR [edx+eax*4], 32767		; 00007fffH
	je	SHORT $L659

; 49   : 				printf("%4d",g.edges[i][j]);

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	lea	edx, DWORD PTR _g$[ebp+ecx]
	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	push	ecx
	push	OFFSET FLAT:??_C@_03OALE@?$CF4d?$AA@	; `string'
	call	_printf
	add	esp, 8

; 50   : 			else

	jmp	SHORT $L661
$L659:

; 51   : 				printf("%4s","∞");

	push	OFFSET FLAT:??_C@_02HKEJ@?$KB?$NO?$AA@	; `string'
	push	OFFSET FLAT:??_C@_03BMCB@?$CF4s?$AA@	; `string'
	call	_printf
	add	esp, 8
$L661:

; 52   : 		}

	jmp	SHORT $L657
$L658:

; 53   : 		printf("\n");

	push	OFFSET FLAT:??_C@_01BJG@?6?$AA@		; `string'
	call	_printf
	add	esp, 4

; 54   : 	}

	jmp	$L654
$L655:

; 55   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 72					; 00000048H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?DispMat1@@YAXUMGraph@@@Z ENDP				; DispMat1
_TEXT	ENDS
PUBLIC	??_C@_0BD@BOPH@?S?P?O?r?M?$LM?$LF?D?A?Z?$LN?S?$LO?X?U?s?3?6?$AA@ ; `string'
PUBLIC	??_C@_0BE@DABI@?6?A?Z?$LN?S?$LO?X?U?s?W?$KK?A?Z?$LN?S?$LB?m?3?6?$AA@ ; `string'
PUBLIC	??_C@_0CN@PPOB@?J?d?H?k?$LE?m?N?s?$KD?$KM?$LC?$LL?D?$NM?J?d?H?k?$LH?G?J?$PN?W?V?W?V?$LH?$PL?$KD?$KM?J?d@ ; `string'
PUBLIC	?MatToList1@@YAXUMGraph@@AAPAUALGraph@@@Z	; MatToList1
PUBLIC	?DispAdj1@@YAXPAUALGraph@@@Z			; DispAdj1
PUBLIC	?DFS@@YAXPAUALGraph@@H@Z			; DFS
PUBLIC	?DFS2@@YAXPAUALGraph@@H@Z			; DFS2
PUBLIC	?BFS1@@YAXPAUALGraph@@H@Z			; BFS1
PUBLIC	?floyd@@YAXUMGraph@@@Z				; floyd
PUBLIC	?Dijkstra@@YAXUMGraph@@H@Z			; Dijkstra
PUBLIC	?Prim@@YAXUMGraph@@H@Z				; Prim
PUBLIC	?SortEdge@@YAXUMGraph@@QAUEdge@@@Z		; SortEdge
PUBLIC	?Kruskal@@YAXQAUEdge@@HH@Z			; Kruskal
PUBLIC	_main
PUBLIC	??_C@_0BJ@JFAH@121110098?5?5?5?T?x?S?B?$LL?$KK?5?5?5?M?$LM?6?$AA@ ; `string'
PUBLIC	??_C@_0BD@JPPG@?J?d?H?k?D?c?$LF?D?Q?$KB?T?q?$CI0?$HO5?$CJ?3?$AA@ ; `string'
PUBLIC	??_C@_02MECO@?$CFd?$AA@				; `string'
PUBLIC	??_C@_09NNIN@?J?d?H?k?F?p?$LF?c?3?$AA@		; `string'
PUBLIC	??_C@_0CF@FIBK@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LH?G?$LF?$NN?$LJ?i?K?c?$LH@ ; `string'
PUBLIC	??_C@_0CD@NBJD@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LF?$NN?$LJ?i?K?c?$LH?$KI?$CJ@ ; `string'
PUBLIC	??_C@_0BJ@GDAP@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?$LJ?c?$LG?H?S?E?O?HBFS?3?6?$AA@ ; `string'
PUBLIC	??_C@_0BN@EHOI@?6?J?d?$LD?v?H?N?R?b?A?$LN?$LI?v?$LD?G?J?P?W?n?$LG?L?B?$LH?$LO?$LG?$KD?$LK?6?$AA@ ; `string'
PUBLIC	??_C@_0BF@DKOB@?F?U?$MA?o?D?$LH?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@ ; `string'
PUBLIC	??_C@_0BJ@JFPN@?$LP?K?B?$LD?K?$LJ?$LP?$KI?$LG?$PL?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@ ; `string'
EXTRN	__chkstk:NEAR
EXTRN	__iob:BYTE
EXTRN	__filbuf:NEAR
EXTRN	_scanf:NEAR
;	COMDAT ??_C@_0BJ@JFAH@121110098?5?5?5?T?x?S?B?$LL?$KK?5?5?5?M?$LM?6?$AA@
; File F:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\图最短路径.cpp
CONST	SEGMENT
??_C@_0BJ@JFAH@121110098?5?5?5?T?x?S?B?$LL?$KK?5?5?5?M?$LM?6?$AA@ DB '121'
	DB	'110098   ', 0d4H, 0f8H, 0d3H, 0c2H, 0bbH, 0aaH, '   ', 0cdH, 0bcH
	DB	0aH, 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@JPPG@?J?d?H?k?D?c?$LF?D?Q?$KB?T?q?$CI0?$HO5?$CJ?3?$AA@
CONST	SEGMENT
??_C@_0BD@JPPG@?J?d?H?k?D?c?$LF?D?Q?$KB?T?q?$CI0?$HO5?$CJ?3?$AA@ DB 0caH, 0e4H
	DB	0c8H, 0ebH, 0c4H, 0e3H, 0b5H, 0c4H, 0d1H, 0a1H, 0d4H, 0f1H, '('
	DB	'0~5):', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_02MECO@?$CFd?$AA@
CONST	SEGMENT
??_C@_02MECO@?$CFd?$AA@ DB '%d', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_09NNIN@?J?d?H?k?F?p?$LF?c?3?$AA@
CONST	SEGMENT
??_C@_09NNIN@?J?d?H?k?F?p?$LF?c?3?$AA@ DB 0caH, 0e4H, 0c8H, 0ebH, 0c6H, 0f0H
	DB	0b5H, 0e3H, ':', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0CF@FIBK@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LH?G?$LF?$NN?$LJ?i?K?c?$LH@
CONST	SEGMENT
??_C@_0CF@FIBK@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LH?G?$LF?$NN?$LJ?i?K?c?$LH@ DB 0aH
	DB	0b4H, 0d3H, '%d', 0bfH, 0aaH, 0caH, 0bcH, 0b5H, 0c4H, 0c9H, 0eeH
	DB	0b6H, 0c8H, 0d3H, 0c5H, 0cfH, 0c8H, 'DFS(', 0b7H, 0c7H, 0b5H, 0ddH
	DB	0b9H, 0e9H, 0cbH, 0e3H, 0b7H, 0a8H, '):', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0CD@NBJD@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LF?$NN?$LJ?i?K?c?$LH?$KI?$CJ@
CONST	SEGMENT
??_C@_0CD@NBJD@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LF?$NN?$LJ?i?K?c?$LH?$KI?$CJ@ DB 0aH
	DB	0b4H, 0d3H, '%d', 0bfH, 0aaH, 0caH, 0bcH, 0b5H, 0c4H, 0c9H, 0eeH
	DB	0b6H, 0c8H, 0d3H, 0c5H, 0cfH, 0c8H, 'DFS(', 0b5H, 0ddH, 0b9H, 0e9H
	DB	0cbH, 0e3H, 0b7H, 0a8H, '):', 0aH, 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@GDAP@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?$LJ?c?$LG?H?S?E?O?HBFS?3?6?$AA@
CONST	SEGMENT
??_C@_0BJ@GDAP@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?$LJ?c?$LG?H?S?E?O?HBFS?3?6?$AA@ DB 0aH
	DB	0b4H, 0d3H, '%d', 0bfH, 0aaH, 0caH, 0bcH, 0b5H, 0c4H, 0b9H, 0e3H
	DB	0b6H, 0c8H, 0d3H, 0c5H, 0cfH, 0c8H, 'BFS:', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BN@EHOI@?6?J?d?$LD?v?H?N?R?b?A?$LN?$LI?v?$LD?G?J?P?W?n?$LG?L?B?$LH?$LO?$LG?$KD?$LK?6?$AA@
CONST	SEGMENT
??_C@_0BN@EHOI@?6?J?d?$LD?v?H?N?R?b?A?$LN?$LI?v?$LD?G?J?P?W?n?$LG?L?B?$LH?$LO?$LG?$KD?$LK?6?$AA@ DB 0aH
	DB	0caH, 0e4H, 0b3H, 0f6H, 0c8H, 0ceH, 0d2H, 0e2H, 0c1H, 0bdH, 0b8H
	DB	0f6H, 0b3H, 0c7H, 0caH, 0d0H, 0d7H, 0eeH, 0b6H, 0ccH, 0c2H, 0b7H
	DB	0beH, 0b6H, 0a3H, 0baH, 0aH, 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@DKOB@?F?U?$MA?o?D?$LH?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@
CONST	SEGMENT
??_C@_0BF@DKOB@?F?U?$MA?o?D?$LH?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@ DB 0c6H
	DB	0d5H, 0c0H, 0efH, 0c4H, 0b7H, 0cbH, 0e3H, 0b7H, 0a8H, 0c7H, 0f3H
	DB	0bdH, 0e2H, 0bdH, 0e1H, 0b9H, 0fbH, ':', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@JFPN@?$LP?K?B?$LD?K?$LJ?$LP?$KI?$LG?$PL?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@
CONST	SEGMENT
??_C@_0BJ@JFPN@?$LP?K?B?$LD?K?$LJ?$LP?$KI?$LG?$PL?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@ DB 0bfH
	DB	0cbH, 0c2H, 0b3H, 0cbH, 0b9H, 0bfH, 0a8H, 0b6H, 0fbH, 0cbH, 0e3H
	DB	0b7H, 0a8H, 0c7H, 0f3H, 0bdH, 0e2H, 0bdH, 0e1H, 0b9H, 0fbH, ':'
	DB	0aH, 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@BOPH@?S?P?O?r?M?$LM?$LF?D?A?Z?$LN?S?$LO?X?U?s?3?6?$AA@
CONST	SEGMENT
??_C@_0BD@BOPH@?S?P?O?r?M?$LM?$LF?D?A?Z?$LN?S?$LO?X?U?s?3?6?$AA@ DB 0d3H, 0d0H
	DB	0cfH, 0f2H, 0cdH, 0bcH, 0b5H, 0c4H, 0c1H, 0daH, 0bdH, 0d3H, 0beH
	DB	0d8H, 0d5H, 0f3H, ':', 0aH, 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@DABI@?6?A?Z?$LN?S?$LO?X?U?s?W?$KK?A?Z?$LN?S?$LB?m?3?6?$AA@
CONST	SEGMENT
??_C@_0BE@DABI@?6?A?Z?$LN?S?$LO?X?U?s?W?$KK?A?Z?$LN?S?$LB?m?3?6?$AA@ DB 0aH
	DB	0c1H, 0daH, 0bdH, 0d3H, 0beH, 0d8H, 0d5H, 0f3H, 0d7H, 0aaH, 0c1H
	DB	0daH, 0bdH, 0d3H, 0b1H, 0edH, ':', 0aH, 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0CN@PPOB@?J?d?H?k?$LE?m?N?s?$KD?$KM?$LC?$LL?D?$NM?J?d?H?k?$LH?G?J?$PN?W?V?W?V?$LH?$PL?$KD?$KM?J?d@
CONST	SEGMENT
??_C@_0CN@PPOB@?J?d?H?k?$LE?m?N?s?$KD?$KM?$LC?$LL?D?$NM?J?d?H?k?$LH?G?J?$PN?W?V?W?V?$LH?$PL?$KD?$KM?J?d@ DB 0caH
	DB	0e4H, 0c8H, 0ebH, 0b4H, 0edH, 0ceH, 0f3H, 0a3H, 0acH, 0b2H, 0bbH
	DB	0c4H, 0dcH, 0caH, 0e4H, 0c8H, 0ebH, 0b7H, 0c7H, 0caH, 0fdH, 0d7H
	DB	0d6H, 0d7H, 0d6H, 0b7H, 0fbH, 0a3H, 0acH, 0caH, 0e4H, 0c8H, 0ebH
	DB	'0~5', 0a3H, 0a1H, 0a3H, 0a1H, 0a3H, 0a1H, 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT _main
_TEXT	SEGMENT
_G$ = -4
_g$ = -40812
_E$ = -82820
_i$ = -82824
_j$ = -82828
_flag$ = -82832
_number$ = -82836
_start$ = -82840
_A$ = -85244
_main	PROC NEAR					; COMDAT

; 15   : {

	push	ebp
	mov	ebp, esp
	mov	eax, 85316				; 00014d44H
	call	__chkstk
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-85316]
	mov	ecx, 21329				; 00005351H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 16   : 	ALGraph *G;
; 17   : 	MGraph g,g1;
; 18   : 	Edge E[MAX];
; 19   : 	int i,j;
; 20   :     bool flag=true;//循环标志   

	mov	BYTE PTR _flag$[ebp], 1

; 21   : 	int number;
; 22   : 	int start,end;///起点、终点
; 23   : 	int A[MAX][6]={
; 24   : 		{0,5,INF,7,INF,INF},

	mov	DWORD PTR _A$[ebp], 0
	mov	DWORD PTR _A$[ebp+4], 5
	mov	DWORD PTR _A$[ebp+8], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+12], 7
	mov	DWORD PTR _A$[ebp+16], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+20], 32767		; 00007fffH

; 25   : 		{INF,0,4,INF,INF,INF},

	mov	DWORD PTR _A$[ebp+24], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+28], 0
	mov	DWORD PTR _A$[ebp+32], 4
	mov	DWORD PTR _A$[ebp+36], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+40], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+44], 32767		; 00007fffH

; 26   : 		{8,INF,0,INF,INF,9},

	mov	DWORD PTR _A$[ebp+48], 8
	mov	DWORD PTR _A$[ebp+52], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+56], 0
	mov	DWORD PTR _A$[ebp+60], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+64], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+68], 9

; 27   : 		{INF,INF,5,0,INF,6},

	mov	DWORD PTR _A$[ebp+72], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+76], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+80], 5
	mov	DWORD PTR _A$[ebp+84], 0
	mov	DWORD PTR _A$[ebp+88], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+92], 6

; 28   : 		{INF,INF,INF,5,0,INF},

	mov	DWORD PTR _A$[ebp+96], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+100], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+104], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+108], 5
	mov	DWORD PTR _A$[ebp+112], 0
	mov	DWORD PTR _A$[ebp+116], 32767		; 00007fffH

; 29   : 		{3,INF,INF,INF,1,0}};

	mov	DWORD PTR _A$[ebp+120], 3
	mov	DWORD PTR _A$[ebp+124], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+128], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+132], 32767		; 00007fffH
	mov	DWORD PTR _A$[ebp+136], 1
	mov	DWORD PTR _A$[ebp+140], 0
	mov	ecx, 564				; 00000234H
	xor	eax, eax
	lea	edi, DWORD PTR _A$[ebp+144]
	rep stosd

; 30   : 		g.n=6;

	mov	DWORD PTR _g$[ebp+40000], 6

; 31   : 		g.e=10;

	mov	DWORD PTR _g$[ebp+40004], 10		; 0000000aH

; 32   : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L989
$L990:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L989:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L991

; 33   : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L992
$L993:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L992:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L994

; 34   : 			g.edges[i][j]=A[i][j];

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 24					; 00000018H
	lea	edx, DWORD PTR _A$[ebp+ecx]
	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 400				; 00000190H
	lea	ecx, DWORD PTR _g$[ebp+eax]
	mov	eax, DWORD PTR _j$[ebp]
	mov	esi, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR [edx+esi*4]
	mov	DWORD PTR [ecx+eax*4], edx
	jmp	SHORT $L993
$L994:
	jmp	SHORT $L990
$L991:

; 35   : 			printf("121110098   曾勇华   图\n");

	push	OFFSET FLAT:??_C@_0BJ@JFAH@121110098?5?5?5?T?x?S?B?$LL?$KK?5?5?5?M?$LM?6?$AA@ ; `string'
	call	_printf
	add	esp, 4
$L997:

; 36   : 				
; 37   : 	while(flag)

	mov	eax, DWORD PTR _flag$[ebp]
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	$L998

; 39   : 		boot();

	call	?boot@@YAXXZ				; boot

; 40   : 		number=-1;//初始化

	mov	DWORD PTR _number$[ebp], -1

; 41   : 		printf("输入你的选择(0~5):");

	push	OFFSET FLAT:??_C@_0BD@JPPG@?J?d?H?k?D?c?$LF?D?Q?$KB?T?q?$CI0?$HO5?$CJ?3?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 42   : 		scanf("%d",&number);//若输入abc错误，不能读取,则返回number原地址垃圾值，若输入6abc则abc被过滤

	lea	ecx, DWORD PTR _number$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_02MECO@?$CFd?$AA@	; `string'
	call	_scanf
	add	esp, 8
$L1002:

; 43   : 		while(getchar()!='\n')//过滤非数字的字符

	mov	edx, DWORD PTR __iob+4
	sub	edx, 1
	mov	DWORD PTR __iob+4, edx
	cmp	DWORD PTR __iob+4, 0
	jl	SHORT $L1091
	mov	eax, DWORD PTR __iob
	movsx	ecx, BYTE PTR [eax]
	and	ecx, 255				; 000000ffH
	mov	DWORD PTR -85248+[ebp], ecx
	mov	edx, DWORD PTR __iob
	add	edx, 1
	mov	DWORD PTR __iob, edx
	jmp	SHORT $L1092
$L1091:
	push	OFFSET FLAT:__iob
	call	__filbuf
	add	esp, 4
	mov	DWORD PTR -85248+[ebp], eax
$L1092:
	cmp	DWORD PTR -85248+[ebp], 10		; 0000000aH
	je	SHORT $L1003

; 44   : 			;

	jmp	SHORT $L1002
$L1003:

; 46   : 		{

	mov	eax, DWORD PTR _number$[ebp]
	mov	DWORD PTR -85252+[ebp], eax
	cmp	DWORD PTR -85252+[ebp], 5
	ja	$L1026
	mov	ecx, DWORD PTR -85252+[ebp]
	jmp	DWORD PTR $L1094[ecx*4]
$L1008:

; 47   : 		case 0:
; 48   : 			flag=0;

	mov	BYTE PTR _flag$[ebp], 0

; 49   : 			break;

	jmp	$L1005
$L1009:

; 50   : 		case 1:
; 51   : 			printf("输入起点:");

	push	OFFSET FLAT:??_C@_09NNIN@?J?d?H?k?F?p?$LF?c?3?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 52   : 			scanf("%d",&start);

	lea	edx, DWORD PTR _start$[ebp]
	push	edx
	push	OFFSET FLAT:??_C@_02MECO@?$CFd?$AA@	; `string'
	call	_scanf
	add	esp, 8

; 53   : 			MatToList1(g,G);

	lea	eax, DWORD PTR _G$[ebp]
	push	eax
	lea	esi, DWORD PTR _g$[ebp]
	mov	eax, 40808				; 00009f68H
	call	__chkstk
	mov	ecx, 10202				; 000027daH
	mov	edi, esp
	rep movsd
	call	?MatToList1@@YAXUMGraph@@AAPAUALGraph@@@Z ; MatToList1
	add	esp, 40812				; 00009f6cH

; 54   : 			printf("\n从%d开始的深度优先DFS(非递归算法):\n",start);

	mov	ecx, DWORD PTR _start$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_0CF@FIBK@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LH?G?$LF?$NN?$LJ?i?K?c?$LH@ ; `string'
	call	_printf
	add	esp, 8

; 55   : 			DFS2(G,start);

	mov	edx, DWORD PTR _start$[ebp]
	push	edx
	mov	eax, DWORD PTR _G$[ebp]
	push	eax
	call	?DFS2@@YAXPAUALGraph@@H@Z		; DFS2
	add	esp, 8

; 56   : 			for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L1012
$L1013:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L1012:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L1014

; 57   : 		    visit[i]=0;

	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 0
	jmp	SHORT $L1013
$L1014:

; 58   : 			printf("\n从%d开始的深度优先DFS(递归算法):\n",start);

	mov	ecx, DWORD PTR _start$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_0CD@NBJD@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?I?n?$LG?H?S?E?O?HDFS?$CI?$LF?$NN?$LJ?i?K?c?$LH?$KI?$CJ@ ; `string'
	call	_printf
	add	esp, 8

; 59   : 			DFS(G,start);

	mov	edx, DWORD PTR _start$[ebp]
	push	edx
	mov	eax, DWORD PTR _G$[ebp]
	push	eax
	call	?DFS@@YAXPAUALGraph@@H@Z		; DFS
	add	esp, 8

; 60   : 			printf("\n从%d开始的广度优先BFS:\n",start);

	mov	ecx, DWORD PTR _start$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_0BJ@GDAP@?6?$LE?S?$CFd?$LP?$KK?J?$LM?$LF?D?$LJ?c?$LG?H?S?E?O?HBFS?3?6?$AA@ ; `string'
	call	_printf
	add	esp, 8

; 61   : 			BFS1(G,start);

	mov	edx, DWORD PTR _start$[ebp]
	push	edx
	mov	eax, DWORD PTR _G$[ebp]
	push	eax
	call	?BFS1@@YAXPAUALGraph@@H@Z		; BFS1
	add	esp, 8

; 62   : 			printf("\n");

	push	OFFSET FLAT:??_C@_01BJG@?6?$AA@		; `string'
	call	_printf
	add	esp, 4

; 63   : 			break;

	jmp	$L1005
$L1017:

; 64   : 		case 2:
; 65   :              printf("\n输出任意两个城市最短路径：\n");

	push	OFFSET FLAT:??_C@_0BN@EHOI@?6?J?d?$LD?v?H?N?R?b?A?$LN?$LI?v?$LD?G?J?P?W?n?$LG?L?B?$LH?$LO?$LG?$KD?$LK?6?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 66   :              floyd(g);//输出所有相邻顶点间的距离、路径

	lea	esi, DWORD PTR _g$[ebp]
	mov	eax, 40808				; 00009f68H
	call	__chkstk
	mov	ecx, 10202				; 000027daH
	mov	edi, esp
	rep movsd
	call	?floyd@@YAXUMGraph@@@Z			; floyd
	add	esp, 40808				; 00009f68H

; 67   : 			 break;

	jmp	$L1005
$L1019:

; 68   : 		case 3:
; 69   : 			printf("输入起点:");

	push	OFFSET FLAT:??_C@_09NNIN@?J?d?H?k?F?p?$LF?c?3?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 70   : 			scanf("%d",&start);

	lea	ecx, DWORD PTR _start$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_02MECO@?$CFd?$AA@	; `string'
	call	_scanf
	add	esp, 8

; 71   :             Dijkstra(g,start);

	mov	edx, DWORD PTR _start$[ebp]
	push	edx
	lea	esi, DWORD PTR _g$[ebp]
	mov	eax, 40808				; 00009f68H
	call	__chkstk
	mov	ecx, 10202				; 000027daH
	mov	edi, esp
	rep movsd
	call	?Dijkstra@@YAXUMGraph@@H@Z		; Dijkstra
	add	esp, 40812				; 00009f6cH

; 72   : 			break;

	jmp	$L1005
$L1020:

; 73   : 		case 4:
; 74   : 			printf("普里姆算法求解结果:\n");

	push	OFFSET FLAT:??_C@_0BF@DKOB@?F?U?$MA?o?D?$LH?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 75   : 	        Prim(g,0);

	push	0
	lea	esi, DWORD PTR _g$[ebp]
	mov	eax, 40808				; 00009f68H
	call	__chkstk
	mov	ecx, 10202				; 000027daH
	mov	edi, esp
	rep movsd
	call	?Prim@@YAXUMGraph@@H@Z			; Prim
	add	esp, 40812				; 00009f6cH

; 76   : 		    printf("克鲁斯卡尔算法求解结果:\n");

	push	OFFSET FLAT:??_C@_0BJ@JFPN@?$LP?K?B?$LD?K?$LJ?$LP?$KI?$LG?$PL?K?c?$LH?$KI?G?s?$LN?b?$LN?a?$LJ?$PL?3?6?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 77   : 			SortEdge(g,E);

	lea	eax, DWORD PTR _E$[ebp]
	push	eax
	lea	esi, DWORD PTR _g$[ebp]
	mov	eax, 40808				; 00009f68H
	call	__chkstk
	mov	ecx, 10202				; 000027daH
	mov	edi, esp
	rep movsd
	call	?SortEdge@@YAXUMGraph@@QAUEdge@@@Z	; SortEdge
	add	esp, 40812				; 00009f6cH

; 78   : 	        Kruskal(E,g.n,g.e);

	mov	ecx, DWORD PTR _g$[ebp+40004]
	push	ecx
	mov	edx, DWORD PTR _g$[ebp+40000]
	push	edx
	lea	eax, DWORD PTR _E$[ebp]
	push	eax
	call	?Kruskal@@YAXQAUEdge@@HH@Z		; Kruskal
	add	esp, 12					; 0000000cH

; 79   : 			printf("\n");

	push	OFFSET FLAT:??_C@_01BJG@?6?$AA@		; `string'
	call	_printf
	add	esp, 4

; 80   : 			break;

	jmp	$L1005
$L1023:

; 81   : 		case 5:
; 82   : 			printf("有向图的邻接矩阵:\n");

	push	OFFSET FLAT:??_C@_0BD@BOPH@?S?P?O?r?M?$LM?$LF?D?A?Z?$LN?S?$LO?X?U?s?3?6?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 83   : 			DispMat1(g);

	lea	esi, DWORD PTR _g$[ebp]
	mov	eax, 40808				; 00009f68H
	call	__chkstk
	mov	ecx, 10202				; 000027daH
	mov	edi, esp
	rep movsd
	call	?DispMat1@@YAXUMGraph@@@Z		; DispMat1
	add	esp, 40808				; 00009f68H

; 84   : 			printf("\n邻接矩阵转邻接表:\n");

	push	OFFSET FLAT:??_C@_0BE@DABI@?6?A?Z?$LN?S?$LO?X?U?s?W?$KK?A?Z?$LN?S?$LB?m?3?6?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 85   : 			MatToList1(g,G);

	lea	ecx, DWORD PTR _G$[ebp]
	push	ecx
	lea	esi, DWORD PTR _g$[ebp]
	mov	eax, 40808				; 00009f68H
	call	__chkstk
	mov	ecx, 10202				; 000027daH
	mov	edi, esp
	rep movsd
	call	?MatToList1@@YAXUMGraph@@AAPAUALGraph@@@Z ; MatToList1
	add	esp, 40812				; 00009f6cH

; 86   : 			DispAdj1(G);

	mov	edx, DWORD PTR _G$[ebp]
	push	edx
	call	?DispAdj1@@YAXPAUALGraph@@@Z		; DispAdj1
	add	esp, 4

; 87   : 			break;

	jmp	SHORT $L1005
$L1026:

; 88   : 		default:
; 89   : 			printf("输入错误，不能输入非数字字符，输入0~5！！！\n");

	push	OFFSET FLAT:??_C@_0CN@PPOB@?J?d?H?k?$LE?m?N?s?$KD?$KM?$LC?$LL?D?$NM?J?d?H?k?$LH?G?J?$PN?W?V?W?V?$LH?$PL?$KD?$KM?J?d@ ; `string'
	call	_printf
	add	esp, 4
$L1005:

; 92   : 	}

	jmp	$L997
$L998:

; 93   : 	return 0;

	xor	eax, eax

; 94   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 85316				; 00014d44H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
$L1094:
	DD	$L1008
	DD	$L1009
	DD	$L1017
	DD	$L1019
	DD	$L1020
	DD	$L1023
_main	ENDP
_TEXT	ENDS
EXTRN	_malloc:NEAR
;	COMDAT ?MatToList1@@YAXUMGraph@@AAPAUALGraph@@@Z
_TEXT	SEGMENT
_g$ = 8
_G$ = 40816
_i$ = -4
_j$ = -8
_p$ = -12
?MatToList1@@YAXUMGraph@@AAPAUALGraph@@@Z PROC NEAR	; MatToList1, COMDAT

; 57   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-76]
	mov	ecx, 19					; 00000013H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 58   : 	int i,j;
; 59   : 	ArcNode *p;
; 60   : 	G=(ALGraph*)malloc(sizeof(ALGraph));

	push	808					; 00000328H
	call	_malloc
	add	esp, 4
	mov	ecx, DWORD PTR _G$[ebp]
	mov	DWORD PTR [ecx], eax

; 61   : 	G->n=g.n;

	mov	edx, DWORD PTR _G$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp+40000]
	mov	DWORD PTR [eax+800], ecx

; 62   : 	G->e=g.e;

	mov	edx, DWORD PTR _G$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp+40004]
	mov	DWORD PTR [eax+804], ecx

; 63   : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L674
$L675:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L674:
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L676

; 65   : 		G->adjlist[i].data=i;

	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	DWORD PTR [edx+eax*8], ecx

; 66   : 		G->adjlist[i].firstarc=NULL;

	mov	edx, DWORD PTR _G$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	DWORD PTR [eax+ecx*8+4], 0

; 67   : 	}

	jmp	SHORT $L675
$L676:

; 68   : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L677
$L678:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L677:
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	$L679

; 70   : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L680
$L681:
	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
$L680:
	mov	edx, DWORD PTR _j$[ebp]
	cmp	edx, DWORD PTR _g$[ebp+40000]
	jge	$L682

; 72   : 			if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)

	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 400				; 00000190H
	lea	ecx, DWORD PTR _g$[ebp+eax]
	mov	edx, DWORD PTR _j$[ebp]
	cmp	DWORD PTR [ecx+edx*4], 0
	je	SHORT $L683
	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 400				; 00000190H
	lea	ecx, DWORD PTR _g$[ebp+eax]
	mov	edx, DWORD PTR _j$[ebp]
	cmp	DWORD PTR [ecx+edx*4], 32767		; 00007fffH
	je	SHORT $L683

; 74   : 				p=(ArcNode*)malloc(sizeof(ArcNode));

	push	12					; 0000000cH
	call	_malloc
	add	esp, 4
	mov	DWORD PTR _p$[ebp], eax

; 75   : 				p->info=g.edges[i][j];

	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 400				; 00000190H
	lea	ecx, DWORD PTR _g$[ebp+eax]
	mov	edx, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR [edx+8], ecx

; 76   : 				p->adjvex=j;

	mov	edx, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR _j$[ebp]
	mov	DWORD PTR [edx], eax

; 77   : 				p->nextarc=G->adjlist[i].firstarc;

	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR [edx+ecx*8+4]
	mov	DWORD PTR [eax+4], edx

; 78   : 				G->adjlist[i].firstarc=p;

	mov	eax, DWORD PTR _G$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx+edx*8+4], eax
$L683:

; 80   : 		}

	jmp	$L681
$L682:

; 81   : 	}

	jmp	$L678
$L679:

; 82   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 76					; 0000004cH
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?MatToList1@@YAXUMGraph@@AAPAUALGraph@@@Z ENDP		; MatToList1
_TEXT	ENDS
PUBLIC	??_C@_05MHPM@?$CF?910d?$AA@			; `string'
PUBLIC	??_C@_08PBJI@?$CFd?$CI?$CFd?$CJ?5?5?$AA@	; `string'
;	COMDAT ??_C@_05MHPM@?$CF?910d?$AA@
; File f:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\graph.h
CONST	SEGMENT
??_C@_05MHPM@?$CF?910d?$AA@ DB '%-10d', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_08PBJI@?$CFd?$CI?$CFd?$CJ?5?5?$AA@
CONST	SEGMENT
??_C@_08PBJI@?$CFd?$CI?$CFd?$CJ?5?5?$AA@ DB '%d(%d)  ', 00H ; `string'
CONST	ENDS
;	COMDAT ?DispAdj1@@YAXPAUALGraph@@@Z
_TEXT	SEGMENT
_G$ = 8
_i$ = -4
_p$ = -8
?DispAdj1@@YAXPAUALGraph@@@Z PROC NEAR			; DispAdj1, COMDAT

; 84   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-72]
	mov	ecx, 18					; 00000012H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 85   : 	int i;
; 86   : 	ArcNode *p;
; 87   : 	for(i=0;i<G->n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L691
$L692:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L691:
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR [ecx+800]
	jge	SHORT $L693

; 89   : 		p=G->adjlist[i].firstarc;

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [ecx+eax*8+4]
	mov	DWORD PTR _p$[ebp], edx

; 90   : 		printf("%-10d",G->adjlist[i].data);

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [ecx+eax*8]
	push	edx
	push	OFFSET FLAT:??_C@_05MHPM@?$CF?910d?$AA@	; `string'
	call	_printf
	add	esp, 8
$L696:

; 91   : 		while(p)

	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L697

; 93   : 			printf("%d(%d)  ",p->adjvex,p->info);

	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	mov	edx, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:??_C@_08PBJI@?$CFd?$CI?$CFd?$CJ?5?5?$AA@ ; `string'
	call	_printf
	add	esp, 12					; 0000000cH

; 94   : 			p=p->nextarc;

	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _p$[ebp], edx

; 95   : 		}

	jmp	SHORT $L696
$L697:

; 96   : 		printf("\n");

	push	OFFSET FLAT:??_C@_01BJG@?6?$AA@		; `string'
	call	_printf
	add	esp, 4

; 97   : 	}

	jmp	SHORT $L692
$L693:

; 98   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 72					; 00000048H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?DispAdj1@@YAXPAUALGraph@@@Z ENDP			; DispAdj1
_TEXT	ENDS
PUBLIC	?ListToMat1@@YAXAAUMGraph@@PAUALGraph@@@Z	; ListToMat1
;	COMDAT ?ListToMat1@@YAXAAUMGraph@@PAUALGraph@@@Z
_TEXT	SEGMENT
_g$ = 8
_G$ = 12
_i$ = -4
_j$ = -8
_p$ = -12
?ListToMat1@@YAXAAUMGraph@@PAUALGraph@@@Z PROC NEAR	; ListToMat1, COMDAT

; 100  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-76]
	mov	ecx, 19					; 00000013H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 101  : 	int i,j;
; 102  : 	ArcNode *p;
; 103  : 	g.n=G->n;

	mov	eax, DWORD PTR _g$[ebp]
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [ecx+800]
	mov	DWORD PTR [eax+40000], edx

; 104  : 	g.e=G->e;

	mov	eax, DWORD PTR _g$[ebp]
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [ecx+804]
	mov	DWORD PTR [eax+40004], edx

; 105  : 	for(i=0;i<G->n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L706
$L707:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L706:
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR [ecx+800]
	jge	$L708

; 107  : 		for(j=0;j<G->n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L709
$L710:
	mov	eax, DWORD PTR _j$[ebp]
	add	eax, 1
	mov	DWORD PTR _j$[ebp], eax
$L709:
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR _j$[ebp]
	cmp	edx, DWORD PTR [ecx+800]
	jge	SHORT $L711

; 109  : 			if(i!=j)

	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _j$[ebp]
	je	SHORT $L712

; 110  : 			g.edges[i][j]=INF;

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR _j$[ebp]
	mov	DWORD PTR [edx+eax*4], 32767		; 00007fffH

; 111  : 			else

	jmp	SHORT $L713
$L712:

; 112  : 			g.edges[i][j]=0;

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR _j$[ebp]
	mov	DWORD PTR [edx+eax*4], 0
$L713:

; 113  : 		}

	jmp	SHORT $L710
$L711:

; 114  : 		p=G->adjlist[i].firstarc;

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _G$[ebp]
	mov	eax, DWORD PTR [edx+ecx*8+4]
	mov	DWORD PTR _p$[ebp], eax
$L715:

; 115  : 		while(p)

	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L716

; 117  : 			g.edges[i][p->adjvex]=p->info;

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	eax, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+ecx*4], eax

; 118  : 			p=p->nextarc;

	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _p$[ebp], edx

; 119  : 		}

	jmp	SHORT $L715
$L716:

; 120  : 	}

	jmp	$L707
$L708:

; 121  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?ListToMat1@@YAXAAUMGraph@@PAUALGraph@@@Z ENDP		; ListToMat1
_TEXT	ENDS
;	COMDAT ?DFS@@YAXPAUALGraph@@H@Z
_TEXT	SEGMENT
_G$ = 8
_u$ = 12
_p$ = -4
?DFS@@YAXPAUALGraph@@H@Z PROC NEAR			; DFS, COMDAT

; 123  : {

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

; 124  : 	ArcNode *p;
; 125  : 	p=G->adjlist[u].firstarc;

	mov	eax, DWORD PTR _u$[ebp]
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [ecx+eax*8+4]
	mov	DWORD PTR _p$[ebp], edx

; 126  : 	visit[u]=1;

	mov	eax, DWORD PTR _u$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 1

; 127  : 	printf("%4d",u);

	mov	ecx, DWORD PTR _u$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_03OALE@?$CF4d?$AA@	; `string'
	call	_printf
	add	esp, 8
$L723:

; 128  : 	while(p)

	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L724

; 130  : 		if(visit[p->adjvex]==0)

	mov	edx, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR [edx]
	cmp	DWORD PTR ?visit@@3PAHA[eax*4], 0
	jne	SHORT $L725

; 132  : 			DFS(G,p->adjvex);

	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _G$[ebp]
	push	eax
	call	?DFS@@YAXPAUALGraph@@H@Z		; DFS
	add	esp, 8
$L725:

; 134  : 		p=p->nextarc;

	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _p$[ebp], edx

; 135  : 	}

	jmp	SHORT $L723
$L724:

; 136  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 68					; 00000044H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?DFS@@YAXPAUALGraph@@H@Z ENDP				; DFS
_TEXT	ENDS
PUBLIC	?DFSAll@@YAXPAUALGraph@@QAHHH@Z			; DFSAll
PUBLIC	??_C@_05NJKD@?$LN?a?$LJ?$PL?3?$AA@		; `string'
;	COMDAT ??_C@_05NJKD@?$LN?a?$LJ?$PL?3?$AA@
; File f:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\graph.h
CONST	SEGMENT
??_C@_05NJKD@?$LN?a?$LJ?$PL?3?$AA@ DB 0bdH, 0e1H, 0b9H, 0fbH, ':', 00H ; `string'
CONST	ENDS
;	COMDAT ?DFSAll@@YAXPAUALGraph@@QAHHH@Z
_TEXT	SEGMENT
_G$ = 8
_path$ = 12
_u$ = 16
_d$ = 20
_i$ = -4
_p$ = -8
?DFSAll@@YAXPAUALGraph@@QAHHH@Z PROC NEAR		; DFSAll, COMDAT

; 138  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-72]
	mov	ecx, 18					; 00000012H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 139  : 	int i;
; 140  : 	ArcNode *p;
; 141  : 	p=G->adjlist[u].firstarc;

	mov	eax, DWORD PTR _u$[ebp]
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [ecx+eax*8+4]
	mov	DWORD PTR _p$[ebp], edx

; 142  : 	visit[u]=1;

	mov	eax, DWORD PTR _u$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 1

; 143  : 	path[d]=u;

	mov	ecx, DWORD PTR _d$[ebp]
	mov	edx, DWORD PTR _path$[ebp]
	mov	eax, DWORD PTR _u$[ebp]
	mov	DWORD PTR [edx+ecx*4], eax

; 144  : 	d++;

	mov	ecx, DWORD PTR _d$[ebp]
	add	ecx, 1
	mov	DWORD PTR _d$[ebp], ecx

; 145  :     if(d==G->n)

	mov	edx, DWORD PTR _G$[ebp]
	mov	eax, DWORD PTR _d$[ebp]
	cmp	eax, DWORD PTR [edx+800]
	jne	SHORT $L734

; 147  : 		printf("结果:");

	push	OFFSET FLAT:??_C@_05NJKD@?$LN?a?$LJ?$PL?3?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 148  : 		for(i=0;i<d;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L736
$L737:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L736:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _d$[ebp]
	jge	SHORT $L738

; 149  : 			printf("%4d",path[i]);

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _path$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	push	OFFSET FLAT:??_C@_03OALE@?$CF4d?$AA@	; `string'
	call	_printf
	add	esp, 8
	jmp	SHORT $L737
$L738:

; 150  : 		printf("\n");

	push	OFFSET FLAT:??_C@_01BJG@?6?$AA@		; `string'
	call	_printf
	add	esp, 4
$L734:

; 152  : 	while(p)

	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L741

; 154  : 		if(visit[p->adjvex]==0)

	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR [eax]
	cmp	DWORD PTR ?visit@@3PAHA[ecx*4], 0
	jne	SHORT $L742

; 156  : 			DFSAll(G,path,p->adjvex,d);

	mov	edx, DWORD PTR _d$[ebp]
	push	edx
	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _path$[ebp]
	push	edx
	mov	eax, DWORD PTR _G$[ebp]
	push	eax
	call	?DFSAll@@YAXPAUALGraph@@QAHHH@Z		; DFSAll
	add	esp, 16					; 00000010H
$L742:

; 158  : 		p=p->nextarc;

	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _p$[ebp], edx

; 159  : 	}

	jmp	SHORT $L734
$L741:

; 160  : 	visit[u]=0;

	mov	eax, DWORD PTR _u$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 0

; 161  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 72					; 00000048H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?DFSAll@@YAXPAUALGraph@@QAHHH@Z ENDP			; DFSAll
_TEXT	ENDS
PUBLIC	?DFS1@@YAXPAUALGraph@@H@Z			; DFS1
;	COMDAT ?DFS1@@YAXPAUALGraph@@H@Z
_TEXT	SEGMENT
_G$ = 8
_u$ = 12
_i$ = -4
_st$ = -404
_top$ = -408
_p$ = -412
?DFS1@@YAXPAUALGraph@@H@Z PROC NEAR			; DFS1, COMDAT

; 163  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 476				; 000001dcH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-476]
	mov	ecx, 119				; 00000077H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 164  : 	int i;
; 165  : 	int st[MAX];
; 166  : 	int top=-1;

	mov	DWORD PTR _top$[ebp], -1

; 167  : 	ArcNode *p;
; 168  : 	for(i=0;i<G->n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L751
$L752:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L751:
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR [ecx+800]
	jge	SHORT $L753

; 169  : 		visit[i]=0;

	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 0
	jmp	SHORT $L752
$L753:

; 170  : 	visit[u]=1;

	mov	ecx, DWORD PTR _u$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[ecx*4], 1

; 171  : 	top++;

	mov	edx, DWORD PTR _top$[ebp]
	add	edx, 1
	mov	DWORD PTR _top$[ebp], edx

; 172  : 	st[top]=u;

	mov	eax, DWORD PTR _top$[ebp]
	mov	ecx, DWORD PTR _u$[ebp]
	mov	DWORD PTR _st$[ebp+eax*4], ecx

; 173  : 	printf("%4d",u);

	mov	edx, DWORD PTR _u$[ebp]
	push	edx
	push	OFFSET FLAT:??_C@_03OALE@?$CF4d?$AA@	; `string'
	call	_printf
	add	esp, 8
$L755:

; 174  : 	while(top>-1)

	cmp	DWORD PTR _top$[ebp], -1
	jle	$L756

; 176  : 		i=st[top];

	mov	eax, DWORD PTR _top$[ebp]
	mov	ecx, DWORD PTR _st$[ebp+eax*4]
	mov	DWORD PTR _i$[ebp], ecx

; 177  : 	    p=G->adjlist[i].firstarc;

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _G$[ebp]
	mov	ecx, DWORD PTR [eax+edx*8+4]
	mov	DWORD PTR _p$[ebp], ecx
$L758:

; 178  : 		while(p)

	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L759

; 180  : 			if(visit[p->adjvex]==0)

	mov	edx, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR [edx]
	cmp	DWORD PTR ?visit@@3PAHA[eax*4], 0
	jne	SHORT $L760

; 182  : 				printf("%4d",p->adjvex);

	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:??_C@_03OALE@?$CF4d?$AA@	; `string'
	call	_printf
	add	esp, 8

; 183  : 				visit[p->adjvex]=1;

	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR ?visit@@3PAHA[ecx*4], 1

; 184  : 				top++;

	mov	edx, DWORD PTR _top$[ebp]
	add	edx, 1
	mov	DWORD PTR _top$[ebp], edx

; 185  : 				st[top]=p->adjvex;

	mov	eax, DWORD PTR _top$[ebp]
	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _st$[ebp+eax*4], edx

; 186  : 				break;

	jmp	SHORT $L759
$L760:

; 188  : 			p=p->nextarc;

	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _p$[ebp], ecx

; 189  : 		}

	jmp	SHORT $L758
$L759:

; 190  : 		if(!p)

	cmp	DWORD PTR _p$[ebp], 0
	jne	SHORT $L761

; 191  :             top--;

	mov	edx, DWORD PTR _top$[ebp]
	sub	edx, 1
	mov	DWORD PTR _top$[ebp], edx
$L761:

; 192  : 	}

	jmp	$L755
$L756:

; 193  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 476				; 000001dcH
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?DFS1@@YAXPAUALGraph@@H@Z ENDP				; DFS1
_TEXT	ENDS
PUBLIC	??_C@_03IBOB@?$CF3d?$AA@			; `string'
;	COMDAT ??_C@_03IBOB@?$CF3d?$AA@
; File f:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\graph.h
CONST	SEGMENT
??_C@_03IBOB@?$CF3d?$AA@ DB '%3d', 00H			; `string'
CONST	ENDS
;	COMDAT ?DFS2@@YAXPAUALGraph@@H@Z
_TEXT	SEGMENT
_G$ = 8
_v$ = 12
_p$ = -4
_St$ = -404
_top$ = -408
_w$ = -412
_i$ = -416
?DFS2@@YAXPAUALGraph@@H@Z PROC NEAR			; DFS2, COMDAT

; 195  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 480				; 000001e0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-480]
	mov	ecx, 120				; 00000078H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 196  : 	ArcNode *p;
; 197  : 	ArcNode *St[MAX];
; 198  : 	int top=-1,w,i;

	mov	DWORD PTR _top$[ebp], -1

; 199  :     for (i=0;i<G->n;i++) 

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L771
$L772:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L771:
	mov	ecx, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR [ecx+800]
	jge	SHORT $L773

; 200  : 		visit[i]=0;		//顶点访问标志均置成0

	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 0
	jmp	SHORT $L772
$L773:

; 201  : 	printf("%3d",v);        //访问顶点v

	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_03IBOB@?$CF3d?$AA@	; `string'
	call	_printf
	add	esp, 8

; 202  : 	visit[v]=1;

	mov	edx, DWORD PTR _v$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[edx*4], 1

; 203  : 	top++;                  //将顶点v的第一个相邻顶点进栈

	mov	eax, DWORD PTR _top$[ebp]
	add	eax, 1
	mov	DWORD PTR _top$[ebp], eax

; 204  : 	St[top]=G->adjlist[v].firstarc;

	mov	ecx, DWORD PTR _top$[ebp]
	mov	edx, DWORD PTR _v$[ebp]
	mov	eax, DWORD PTR _G$[ebp]
	mov	edx, DWORD PTR [eax+edx*8+4]
	mov	DWORD PTR _St$[ebp+ecx*4], edx
$L776:

; 205  : 	while (top>-1)          //栈不空循环

	cmp	DWORD PTR _top$[ebp], -1
	jle	$L777

; 207  : 		p=St[top];  //出栈一个顶点作为当前顶点

	mov	eax, DWORD PTR _top$[ebp]
	mov	ecx, DWORD PTR _St$[ebp+eax*4]
	mov	DWORD PTR _p$[ebp], ecx
$L779:

; 208  : 		while (p!=NULL)     //查找当前顶点的第一个未访问的顶点

	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L780

; 210  : 			w=p->adjvex;

	mov	edx, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _w$[ebp], eax

; 211  : 			if (visit[w]==0)

	mov	ecx, DWORD PTR _w$[ebp]
	cmp	DWORD PTR ?visit@@3PAHA[ecx*4], 0
	jne	SHORT $L781

; 213  : 				printf("%3d",w); //访问w

	mov	edx, DWORD PTR _w$[ebp]
	push	edx
	push	OFFSET FLAT:??_C@_03IBOB@?$CF3d?$AA@	; `string'
	call	_printf
	add	esp, 8

; 214  : 				visit[w]=1;

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 1

; 215  : 				top++;           //将顶点w的第一个顶点进栈

	mov	ecx, DWORD PTR _top$[ebp]
	add	ecx, 1
	mov	DWORD PTR _top$[ebp], ecx

; 216  : 				St[top]=G->adjlist[w].firstarc;

	mov	edx, DWORD PTR _top$[ebp]
	mov	eax, DWORD PTR _w$[ebp]
	mov	ecx, DWORD PTR _G$[ebp]
	mov	eax, DWORD PTR [ecx+eax*8+4]
	mov	DWORD PTR _St$[ebp+edx*4], eax

; 217  : 				break;           //退出循环

	jmp	SHORT $L780
$L781:

; 219  : 			p=p->nextarc;        //找下一个相邻顶点

	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _p$[ebp], edx

; 220  : 		}

	jmp	SHORT $L779
$L780:

; 221  : 		if(!p)

	cmp	DWORD PTR _p$[ebp], 0
	jne	SHORT $L782

; 222  : 			top--;  

	mov	eax, DWORD PTR _top$[ebp]
	sub	eax, 1
	mov	DWORD PTR _top$[ebp], eax
$L782:

; 223  : 	}

	jmp	$L776
$L777:

; 224  : 	printf("\n");

	push	OFFSET FLAT:??_C@_01BJG@?6?$AA@		; `string'
	call	_printf
	add	esp, 4

; 225  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 480				; 000001e0H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?DFS2@@YAXPAUALGraph@@H@Z ENDP				; DFS2
_TEXT	ENDS
;	COMDAT ?BFS1@@YAXPAUALGraph@@H@Z
_TEXT	SEGMENT
_G$ = 8
_u$ = 12
_i$ = -4
_qu$ = -404
_front$ = -408
_rear$ = -412
_p$ = -416
?BFS1@@YAXPAUALGraph@@H@Z PROC NEAR			; BFS1, COMDAT

; 227  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 480				; 000001e0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-480]
	mov	ecx, 120				; 00000078H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 228  : 	int i;
; 229  : 	int qu[MAX];
; 230  : 	int front,rear;
; 231  : 	ArcNode *p;
; 232  : 	front=rear=0;

	mov	DWORD PTR _rear$[ebp], 0
	mov	eax, DWORD PTR _rear$[ebp]
	mov	DWORD PTR _front$[ebp], eax

; 233  : 	rear++;

	mov	ecx, DWORD PTR _rear$[ebp]
	add	ecx, 1
	mov	DWORD PTR _rear$[ebp], ecx

; 234  : 	qu[rear]=u;

	mov	edx, DWORD PTR _rear$[ebp]
	mov	eax, DWORD PTR _u$[ebp]
	mov	DWORD PTR _qu$[ebp+edx*4], eax

; 235  : 	for (i=0;i<G->n;i++) 

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L792
$L793:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L792:
	mov	edx, DWORD PTR _G$[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR [edx+800]
	jge	SHORT $L794

; 236  : 	visit[i]=0;		//顶点访问标志均置成0

	mov	ecx, DWORD PTR _i$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[ecx*4], 0
	jmp	SHORT $L793
$L794:

; 237  :     visit[u]=1;

	mov	edx, DWORD PTR _u$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[edx*4], 1

; 238  : 	printf("%4d",u);

	mov	eax, DWORD PTR _u$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_03OALE@?$CF4d?$AA@	; `string'
	call	_printf
	add	esp, 8
$L796:

; 239  : 	while(front!=rear)

	mov	ecx, DWORD PTR _front$[ebp]
	cmp	ecx, DWORD PTR _rear$[ebp]
	je	$L797

; 241  : 		front++;

	mov	edx, DWORD PTR _front$[ebp]
	add	edx, 1
	mov	DWORD PTR _front$[ebp], edx

; 242  : 		i=qu[front];

	mov	eax, DWORD PTR _front$[ebp]
	mov	ecx, DWORD PTR _qu$[ebp+eax*4]
	mov	DWORD PTR _i$[ebp], ecx

; 243  : 		p=G->adjlist[i].firstarc;

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _G$[ebp]
	mov	ecx, DWORD PTR [eax+edx*8+4]
	mov	DWORD PTR _p$[ebp], ecx
$L799:

; 244  : 		while(p)

	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L800

; 246  : 			if(visit[p->adjvex]==0)

	mov	edx, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR [edx]
	cmp	DWORD PTR ?visit@@3PAHA[eax*4], 0
	jne	SHORT $L801

; 248  : 				rear++;

	mov	ecx, DWORD PTR _rear$[ebp]
	add	ecx, 1
	mov	DWORD PTR _rear$[ebp], ecx

; 249  : 				qu[rear]=p->adjvex;

	mov	edx, DWORD PTR _rear$[ebp]
	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _qu$[ebp+edx*4], ecx

; 250  : 				visit[p->adjvex]=1;

	mov	edx, DWORD PTR _p$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 1

; 251  : 				printf("%4d",p->adjvex);

	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:??_C@_03OALE@?$CF4d?$AA@	; `string'
	call	_printf
	add	esp, 8
$L801:

; 253  : 			p=p->nextarc;

	mov	eax, DWORD PTR _p$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _p$[ebp], ecx

; 254  : 		}

	jmp	SHORT $L799
$L800:

; 255  : 	}

	jmp	$L796
$L797:

; 256  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 480				; 000001e0H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?BFS1@@YAXPAUALGraph@@H@Z ENDP				; BFS1
_TEXT	ENDS
PUBLIC	?ppath@@YAXQAY06HHH@Z				; ppath
;	COMDAT ?ppath@@YAXQAY06HHH@Z
_TEXT	SEGMENT
_path$ = 8
_i$ = 12
_j$ = 16
_k$ = -4
?ppath@@YAXQAY06HHH@Z PROC NEAR				; ppath, COMDAT

; 258  : {

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

; 259  : 	int k;
; 260  : 	k=path[i][j];

	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 28					; 0000001cH
	mov	ecx, DWORD PTR _path$[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _j$[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR _k$[ebp], eax

; 261  : 	if(k==-1)

	cmp	DWORD PTR _k$[ebp], -1
	jne	SHORT $L808

; 262  : 		return;

	jmp	SHORT $L806
$L808:

; 263  : 	ppath(path,i,k);

	mov	ecx, DWORD PTR _k$[ebp]
	push	ecx
	mov	edx, DWORD PTR _i$[ebp]
	push	edx
	mov	eax, DWORD PTR _path$[ebp]
	push	eax
	call	?ppath@@YAXQAY06HHH@Z			; ppath
	add	esp, 12					; 0000000cH

; 264  : 	printf("%3d",k);

	mov	ecx, DWORD PTR _k$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_03IBOB@?$CF3d?$AA@	; `string'
	call	_printf
	add	esp, 8

; 265  : 	ppath(path,k,j);

	mov	edx, DWORD PTR _j$[ebp]
	push	edx
	mov	eax, DWORD PTR _k$[ebp]
	push	eax
	mov	ecx, DWORD PTR _path$[ebp]
	push	ecx
	call	?ppath@@YAXQAY06HHH@Z			; ppath
	add	esp, 12					; 0000000cH
$L806:

; 266  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 68					; 00000044H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?ppath@@YAXQAY06HHH@Z ENDP				; ppath
_TEXT	ENDS
PUBLIC	?DisPath@@YAXQAY06H0H@Z				; DisPath
PUBLIC	??_C@_0BN@HPFP@?$CFd?$LF?$LN?$CFd?$LF?D?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?B?$LH?$LO?$LG?N?$KK?3?5?$AA@ ; `string'
PUBLIC	??_C@_04KLBH@?$CF3d?6?$AA@			; `string'
;	COMDAT ??_C@_0BN@HPFP@?$CFd?$LF?$LN?$CFd?$LF?D?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?B?$LH?$LO?$LG?N?$KK?3?5?$AA@
; File f:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\graph.h
CONST	SEGMENT
??_C@_0BN@HPFP@?$CFd?$LF?$LN?$CFd?$LF?D?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?B?$LH?$LO?$LG?N?$KK?3?5?$AA@ DB '%'
	DB	'd', 0b5H, 0bdH, '%d', 0b5H, 0c4H, 0beH, 0e0H, 0c0H, 0ebH, 0ceH
	DB	0aaH, ':%d   ', 0c2H, 0b7H, 0beH, 0b6H, 0ceH, 0aaH, ': ', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_04KLBH@?$CF3d?6?$AA@
CONST	SEGMENT
??_C@_04KLBH@?$CF3d?6?$AA@ DB '%3d', 0aH, 00H		; `string'
CONST	ENDS
;	COMDAT ?DisPath@@YAXQAY06H0H@Z
_TEXT	SEGMENT
_A$ = 8
_path$ = 12
_n$ = 16
_i$ = -4
_j$ = -8
?DisPath@@YAXQAY06H0H@Z PROC NEAR			; DisPath, COMDAT

; 268  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-72]
	mov	ecx, 18					; 00000012H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 269  : 	int i,j;
; 270  : 	for(i=0;i<n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L816
$L817:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L816:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	$L818

; 272  : 		for(j=0;j<n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L819
$L820:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L819:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _n$[ebp]
	jge	SHORT $L821

; 274  : 			if(i!=j)

	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _j$[ebp]
	je	SHORT $L822

; 276  : 				printf("%d到%d的距离为:%d   路径为: ",i,j,A[i][j]);

	mov	edx, DWORD PTR _i$[ebp]
	imul	edx, 28					; 0000001cH
	mov	eax, DWORD PTR _A$[ebp]
	add	eax, edx
	mov	ecx, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR [eax+ecx*4]
	push	edx
	mov	eax, DWORD PTR _j$[ebp]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_0BN@HPFP@?$CFd?$LF?$LN?$CFd?$LF?D?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?B?$LH?$LO?$LG?N?$KK?3?5?$AA@ ; `string'
	call	_printf
	add	esp, 16					; 00000010H

; 277  : 				printf("%3d",i);

	mov	edx, DWORD PTR _i$[ebp]
	push	edx
	push	OFFSET FLAT:??_C@_03IBOB@?$CF3d?$AA@	; `string'
	call	_printf
	add	esp, 8

; 278  : 				ppath(path,i,j);

	mov	eax, DWORD PTR _j$[ebp]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	push	ecx
	mov	edx, DWORD PTR _path$[ebp]
	push	edx
	call	?ppath@@YAXQAY06HHH@Z			; ppath
	add	esp, 12					; 0000000cH

; 279  : 				printf("%3d\n",j);

	mov	eax, DWORD PTR _j$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_04KLBH@?$CF3d?6?$AA@	; `string'
	call	_printf
	add	esp, 8
$L822:

; 281  : 		}

	jmp	SHORT $L820
$L821:

; 282  : 	}

	jmp	$L817
$L818:

; 283  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 72					; 00000048H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?DisPath@@YAXQAY06H0H@Z ENDP				; DisPath
_TEXT	ENDS
;	COMDAT ?floyd@@YAXUMGraph@@@Z
_TEXT	SEGMENT
_g$ = 8
_i$ = -4
_j$ = -8
_k$ = -12
_A$ = -208
_path$ = -404
?floyd@@YAXUMGraph@@@Z PROC NEAR			; floyd, COMDAT

; 285  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 468				; 000001d4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-468]
	mov	ecx, 117				; 00000075H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 286  : 	int i,j,k;
; 287  : 	int A[7][7],path[7][7];
; 288  : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L833
$L834:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L833:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L835

; 290  : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L836
$L837:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L836:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L838

; 292  : 			A[i][j]=g.edges[i][j];

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	lea	edx, DWORD PTR _g$[ebp+ecx]
	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 28					; 0000001cH
	lea	ecx, DWORD PTR _A$[ebp+eax]
	mov	eax, DWORD PTR _j$[ebp]
	mov	esi, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR [edx+esi*4]
	mov	DWORD PTR [ecx+eax*4], edx

; 293  : 			path[i][j]=-1;

	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 28					; 0000001cH
	lea	ecx, DWORD PTR _path$[ebp+eax]
	mov	edx, DWORD PTR _j$[ebp]
	mov	DWORD PTR [ecx+edx*4], -1

; 294  : 		}

	jmp	SHORT $L837
$L838:

; 295  : 	}

	jmp	SHORT $L834
$L835:

; 296  : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L839
$L840:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L839:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _g$[ebp+40000]
	jge	$L841

; 298  : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L842
$L843:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L842:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	$L844

; 300  : 			for(k=0;k<g.n;k++)

	mov	DWORD PTR _k$[ebp], 0
	jmp	SHORT $L845
$L846:
	mov	ecx, DWORD PTR _k$[ebp]
	add	ecx, 1
	mov	DWORD PTR _k$[ebp], ecx
$L845:
	mov	edx, DWORD PTR _k$[ebp]
	cmp	edx, DWORD PTR _g$[ebp+40000]
	jge	$L847

; 302  : 				if(A[i][k]+A[k][j]<A[i][j])

	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 28					; 0000001cH
	lea	ecx, DWORD PTR _A$[ebp+eax]
	mov	edx, DWORD PTR _k$[ebp]
	imul	edx, 28					; 0000001cH
	lea	eax, DWORD PTR _A$[ebp+edx]
	mov	edx, DWORD PTR _k$[ebp]
	mov	ecx, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _j$[ebp]
	add	ecx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _i$[ebp]
	imul	eax, 28					; 0000001cH
	lea	edx, DWORD PTR _A$[ebp+eax]
	mov	eax, DWORD PTR _j$[ebp]
	cmp	ecx, DWORD PTR [edx+eax*4]
	jge	SHORT $L848

; 304  : 					A[i][j]=A[i][k]+A[k][j];

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 28					; 0000001cH
	lea	edx, DWORD PTR _A$[ebp+ecx]
	mov	eax, DWORD PTR _k$[ebp]
	imul	eax, 28					; 0000001cH
	lea	ecx, DWORD PTR _A$[ebp+eax]
	mov	eax, DWORD PTR _k$[ebp]
	mov	edx, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _j$[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 28					; 0000001cH
	lea	eax, DWORD PTR _A$[ebp+ecx]
	mov	ecx, DWORD PTR _j$[ebp]
	mov	DWORD PTR [eax+ecx*4], edx

; 305  : 					path[i][j]=k;

	mov	edx, DWORD PTR _i$[ebp]
	imul	edx, 28					; 0000001cH
	lea	eax, DWORD PTR _path$[ebp+edx]
	mov	ecx, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR _k$[ebp]
	mov	DWORD PTR [eax+ecx*4], edx
$L848:

; 307  : 			}

	jmp	$L846
$L847:

; 308  : 		}

	jmp	$L843
$L844:

; 309  : 	}

	jmp	$L840
$L841:

; 310  : 	DisPath(A,path,g.n);

	mov	eax, DWORD PTR _g$[ebp+40000]
	push	eax
	lea	ecx, DWORD PTR _path$[ebp]
	push	ecx
	lea	edx, DWORD PTR _A$[ebp]
	push	edx
	call	?DisPath@@YAXQAY06H0H@Z			; DisPath
	add	esp, 12					; 0000000cH

; 311  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 468				; 000001d4H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?floyd@@YAXUMGraph@@@Z ENDP				; floyd
_TEXT	ENDS
PUBLIC	?DisPath@@YAXQAH0HH@Z				; DisPath
PUBLIC	??_C@_06GENM@path?3?6?$AA@			; `string'
PUBLIC	??_C@_0BK@FGLI@?$CFd?$LF?$LN?$CFd?$LF?D?W?n?$LG?L?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?5?$AA@ ; `string'
PUBLIC	??_C@_07CIOD@?B?$LH?$LO?$LG?N?$KK?3?$AA@	; `string'
;	COMDAT ??_C@_06GENM@path?3?6?$AA@
; File f:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\graph.h
CONST	SEGMENT
??_C@_06GENM@path?3?6?$AA@ DB 'path:', 0aH, 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BK@FGLI@?$CFd?$LF?$LN?$CFd?$LF?D?W?n?$LG?L?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?5?$AA@
CONST	SEGMENT
??_C@_0BK@FGLI@?$CFd?$LF?$LN?$CFd?$LF?D?W?n?$LG?L?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?5?$AA@ DB '%'
	DB	'd', 0b5H, 0bdH, '%d', 0b5H, 0c4H, 0d7H, 0eeH, 0b6H, 0ccH, 0beH
	DB	0e0H, 0c0H, 0ebH, 0ceH, 0aaH, ':%d    ', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_07CIOD@?B?$LH?$LO?$LG?N?$KK?3?$AA@
CONST	SEGMENT
??_C@_07CIOD@?B?$LH?$LO?$LG?N?$KK?3?$AA@ DB 0c2H, 0b7H, 0beH, 0b6H, 0ceH, 0aaH
	DB	':', 00H					; `string'
CONST	ENDS
;	COMDAT ?DisPath@@YAXQAH0HH@Z
_TEXT	SEGMENT
_dist$ = 8
_path$ = 12
_u$ = 16
_n$ = 20
_i$ = -4
_k$ = -8
?DisPath@@YAXQAH0HH@Z PROC NEAR				; DisPath, COMDAT

; 313  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-72]
	mov	ecx, 18					; 00000012H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 314  : 	int i,k;
; 315  : 	printf("path:\n");

	push	OFFSET FLAT:??_C@_06GENM@path?3?6?$AA@	; `string'
	call	_printf
	add	esp, 4

; 316  : 	for(i=0;i<n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L859
$L860:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L859:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L861

; 317  : 		printf("%3d",path[i]);

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _path$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	push	ecx
	push	OFFSET FLAT:??_C@_03IBOB@?$CF3d?$AA@	; `string'
	call	_printf
	add	esp, 8
	jmp	SHORT $L860
$L861:

; 318  : 	printf("\n");

	push	OFFSET FLAT:??_C@_01BJG@?6?$AA@		; `string'
	call	_printf
	add	esp, 4

; 319  : 	for(i=0;i<n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L862
$L863:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L862:
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _n$[ebp]
	jge	$L864

; 321  : 		if(i!=u)

	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _u$[ebp]
	je	$L865

; 323  : 			printf("%d到%d的最短距离为:%d    ",u,i,dist[i]);

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _dist$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	push	ecx
	mov	edx, DWORD PTR _i$[ebp]
	push	edx
	mov	eax, DWORD PTR _u$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_0BK@FGLI@?$CFd?$LF?$LN?$CFd?$LF?D?W?n?$LG?L?$LO?$OA?$MA?k?N?$KK?3?$CFd?5?5?5?5?$AA@ ; `string'
	call	_printf
	add	esp, 16					; 00000010H

; 324  : 			printf("路径为:");

	push	OFFSET FLAT:??_C@_07CIOD@?B?$LH?$LO?$LG?N?$KK?3?$AA@ ; `string'
	call	_printf
	add	esp, 4

; 325  : 			printf("%3d",i);

	mov	ecx, DWORD PTR _i$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_03IBOB@?$CF3d?$AA@	; `string'
	call	_printf
	add	esp, 8

; 326  : 			k=path[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _path$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _k$[ebp], ecx
$L869:

; 327  : 			while(k!=u)

	mov	edx, DWORD PTR _k$[ebp]
	cmp	edx, DWORD PTR _u$[ebp]
	je	SHORT $L870

; 329  : 				printf("%3d",k);

	mov	eax, DWORD PTR _k$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_03IBOB@?$CF3d?$AA@	; `string'
	call	_printf
	add	esp, 8

; 330  : 				k=path[k];

	mov	ecx, DWORD PTR _k$[ebp]
	mov	edx, DWORD PTR _path$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _k$[ebp], eax

; 331  : 			}

	jmp	SHORT $L869
$L870:

; 332  : 			printf("%3d\n",u);

	mov	ecx, DWORD PTR _u$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_04KLBH@?$CF3d?6?$AA@	; `string'
	call	_printf
	add	esp, 8
$L865:

; 334  : 	}

	jmp	$L863
$L864:

; 335  : 
; 336  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 72					; 00000048H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?DisPath@@YAXQAH0HH@Z ENDP				; DisPath
_TEXT	ENDS
;	COMDAT ?Dijkstra@@YAXUMGraph@@H@Z
_TEXT	SEGMENT
_g$ = 8
_u$ = 40816
_dist$ = -400
_path$ = -800
_i$ = -804
_j$ = -808
_min$ = -812
_k$ = -816
?Dijkstra@@YAXUMGraph@@H@Z PROC NEAR			; Dijkstra, COMDAT

; 338  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 880				; 00000370H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-880]
	mov	ecx, 220				; 000000dcH
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 339  : 	int dist[MAX],path[MAX];
; 340  : 	int i,j,min,k;
; 341  : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L881
$L882:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L881:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L883

; 343  : 		dist[i]=g.edges[u][i];

	mov	edx, DWORD PTR _u$[ebp]
	imul	edx, 400				; 00000190H
	lea	eax, DWORD PTR _g$[ebp+edx]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _dist$[ebp+ecx*4], eax

; 344  : 		path[i]=u;

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _u$[ebp]
	mov	DWORD PTR _path$[ebp+ecx*4], edx

; 345  : 		visit[i]=0;

	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 0

; 346  : 	}

	jmp	SHORT $L882
$L883:

; 347  : 	visit[u]=1;

	mov	ecx, DWORD PTR _u$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[ecx*4], 1

; 348  : 	for(i=1;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 1
	jmp	SHORT $L884
$L885:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L884:
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	$L886

; 350  : 		min=INF;

	mov	DWORD PTR _min$[ebp], 32767		; 00007fffH

; 351  : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L887
$L888:
	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
$L887:
	mov	edx, DWORD PTR _j$[ebp]
	cmp	edx, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L889

; 353  : 			if(visit[j]==0&&dist[j]<min)

	mov	eax, DWORD PTR _j$[ebp]
	cmp	DWORD PTR ?visit@@3PAHA[eax*4], 0
	jne	SHORT $L890
	mov	ecx, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR _dist$[ebp+ecx*4]
	cmp	edx, DWORD PTR _min$[ebp]
	jge	SHORT $L890

; 355  : 				min=dist[j];

	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR _dist$[ebp+eax*4]
	mov	DWORD PTR _min$[ebp], ecx

; 356  : 				k=j;

	mov	edx, DWORD PTR _j$[ebp]
	mov	DWORD PTR _k$[ebp], edx
$L890:

; 358  : 		}

	jmp	SHORT $L888
$L889:

; 359  : 		visit[k]=1;

	mov	eax, DWORD PTR _k$[ebp]
	mov	DWORD PTR ?visit@@3PAHA[eax*4], 1

; 360  : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L891
$L892:
	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
$L891:
	mov	edx, DWORD PTR _j$[ebp]
	cmp	edx, DWORD PTR _g$[ebp+40000]
	jge	$L893

; 362  : 			if(visit[j]==0&&min+g.edges[k][j]<dist[j])

	mov	eax, DWORD PTR _j$[ebp]
	cmp	DWORD PTR ?visit@@3PAHA[eax*4], 0
	jne	SHORT $L894
	mov	ecx, DWORD PTR _k$[ebp]
	imul	ecx, 400				; 00000190H
	lea	edx, DWORD PTR _g$[ebp+ecx]
	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR _min$[ebp]
	add	ecx, DWORD PTR [edx+eax*4]
	mov	edx, DWORD PTR _j$[ebp]
	cmp	ecx, DWORD PTR _dist$[ebp+edx*4]
	jge	SHORT $L894

; 364  : 				dist[j]=min+g.edges[k][j];

	mov	eax, DWORD PTR _k$[ebp]
	imul	eax, 400				; 00000190H
	lea	ecx, DWORD PTR _g$[ebp+eax]
	mov	edx, DWORD PTR _j$[ebp]
	mov	eax, DWORD PTR _min$[ebp]
	add	eax, DWORD PTR [ecx+edx*4]
	mov	ecx, DWORD PTR _j$[ebp]
	mov	DWORD PTR _dist$[ebp+ecx*4], eax

; 365  : 				path[j]=k;

	mov	edx, DWORD PTR _j$[ebp]
	mov	eax, DWORD PTR _k$[ebp]
	mov	DWORD PTR _path$[ebp+edx*4], eax
$L894:

; 367  : 		}

	jmp	$L892
$L893:

; 368  : 	}

	jmp	$L885
$L886:

; 369  : 	DisPath(dist,path,u,g.n);

	mov	ecx, DWORD PTR _g$[ebp+40000]
	push	ecx
	mov	edx, DWORD PTR _u$[ebp]
	push	edx
	lea	eax, DWORD PTR _path$[ebp]
	push	eax
	lea	ecx, DWORD PTR _dist$[ebp]
	push	ecx
	call	?DisPath@@YAXQAH0HH@Z			; DisPath
	add	esp, 16					; 00000010H

; 370  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 880				; 00000370H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?Dijkstra@@YAXUMGraph@@H@Z ENDP				; Dijkstra
_TEXT	ENDS
PUBLIC	??_C@_0BD@HGDP@?$LB?$NP?$CI?$CFd?0?$CFd?$CJ?$LF?D?H?$KI?V?$LF?$CFd?6?$AA@ ; `string'
;	COMDAT ??_C@_0BD@HGDP@?$LB?$NP?$CI?$CFd?0?$CFd?$CJ?$LF?D?H?$KI?V?$LF?$CFd?6?$AA@
; File f:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\graph.h
CONST	SEGMENT
??_C@_0BD@HGDP@?$LB?$NP?$CI?$CFd?0?$CFd?$CJ?$LF?D?H?$KI?V?$LF?$CFd?6?$AA@ DB 0b1H
	DB	0dfH, '(%d,%d)', 0b5H, 0c4H, 0c8H, 0a8H, 0d6H, 0b5H, '%d', 0aH
	DB	00H						; `string'
CONST	ENDS
;	COMDAT ?Prim@@YAXUMGraph@@H@Z
_TEXT	SEGMENT
_g$ = 8
_v$ = 40816
_i$ = -4
_j$ = -8
_k$ = -12
_min$ = -16
_lowcost$ = -416
_closet$ = -816
?Prim@@YAXUMGraph@@H@Z PROC NEAR			; Prim, COMDAT

; 372  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 880				; 00000370H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-880]
	mov	ecx, 220				; 000000dcH
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 373  : 	int i,j,k,min;
; 374  : 	int lowcost[MAX],closet[MAX];
; 375  : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L905
$L906:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L905:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L907

; 377  : 		lowcost[i]=g.edges[v][i];

	mov	edx, DWORD PTR _v$[ebp]
	imul	edx, 400				; 00000190H
	lea	eax, DWORD PTR _g$[ebp+edx]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _lowcost$[ebp+ecx*4], eax

; 378  : 		closet[i]=v;

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _v$[ebp]
	mov	DWORD PTR _closet$[ebp+ecx*4], edx

; 379  : 	}

	jmp	SHORT $L906
$L907:

; 380  : 	for(i=1;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 1
	jmp	SHORT $L908
$L909:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L908:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _g$[ebp+40000]
	jge	$L910

; 382  : 		min=INF;

	mov	DWORD PTR _min$[ebp], 32767		; 00007fffH

; 383  : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L911
$L912:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L911:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L913

; 385  : 			if(lowcost[j]!=0&&lowcost[j]!=INF)

	mov	ecx, DWORD PTR _j$[ebp]
	cmp	DWORD PTR _lowcost$[ebp+ecx*4], 0
	je	SHORT $L915
	mov	edx, DWORD PTR _j$[ebp]
	cmp	DWORD PTR _lowcost$[ebp+edx*4], 32767	; 00007fffH
	je	SHORT $L915

; 387  : 				if(lowcost[j]<min)

	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR _lowcost$[ebp+eax*4]
	cmp	ecx, DWORD PTR _min$[ebp]
	jge	SHORT $L915

; 389  : 					k=j;

	mov	edx, DWORD PTR _j$[ebp]
	mov	DWORD PTR _k$[ebp], edx

; 390  : 					min=lowcost[j];

	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR _lowcost$[ebp+eax*4]
	mov	DWORD PTR _min$[ebp], ecx
$L915:

; 393  : 		}

	jmp	SHORT $L912
$L913:

; 394  : 		printf("边(%d,%d)的权值%d\n",closet[k],k,lowcost[k]);

	mov	edx, DWORD PTR _k$[ebp]
	mov	eax, DWORD PTR _lowcost$[ebp+edx*4]
	push	eax
	mov	ecx, DWORD PTR _k$[ebp]
	push	ecx
	mov	edx, DWORD PTR _k$[ebp]
	mov	eax, DWORD PTR _closet$[ebp+edx*4]
	push	eax
	push	OFFSET FLAT:??_C@_0BD@HGDP@?$LB?$NP?$CI?$CFd?0?$CFd?$CJ?$LF?D?H?$KI?V?$LF?$CFd?6?$AA@ ; `string'
	call	_printf
	add	esp, 16					; 00000010H

; 395  : 		lowcost[k]=0;

	mov	ecx, DWORD PTR _k$[ebp]
	mov	DWORD PTR _lowcost$[ebp+ecx*4], 0

; 396  : 		for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L917
$L918:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L917:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	SHORT $L919

; 398  : 			if(j!=k&&g.edges[k][j]<lowcost[j])

	mov	ecx, DWORD PTR _j$[ebp]
	cmp	ecx, DWORD PTR _k$[ebp]
	je	SHORT $L920
	mov	edx, DWORD PTR _k$[ebp]
	imul	edx, 400				; 00000190H
	lea	eax, DWORD PTR _g$[ebp+edx]
	mov	ecx, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR _j$[ebp]
	mov	eax, DWORD PTR [eax+ecx*4]
	cmp	eax, DWORD PTR _lowcost$[ebp+edx*4]
	jge	SHORT $L920

; 400  : 				closet[j]=k;

	mov	ecx, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR _k$[ebp]
	mov	DWORD PTR _closet$[ebp+ecx*4], edx

; 401  : 				lowcost[j]=g.edges[k][j];

	mov	eax, DWORD PTR _k$[ebp]
	imul	eax, 400				; 00000190H
	lea	ecx, DWORD PTR _g$[ebp+eax]
	mov	edx, DWORD PTR _j$[ebp]
	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _lowcost$[ebp+edx*4], ecx
$L920:

; 403  : 		}

	jmp	SHORT $L918
$L919:

; 404  : 	}

	jmp	$L909
$L910:

; 405  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 880				; 00000370H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?Prim@@YAXUMGraph@@H@Z ENDP				; Prim
_TEXT	ENDS
;	COMDAT ?SortEdge@@YAXUMGraph@@QAUEdge@@@Z
_TEXT	SEGMENT
_g$ = 8
_E$ = 40816
_i$ = -4
_j$ = -8
_k$ = -12
_temp$ = -24
?SortEdge@@YAXUMGraph@@QAUEdge@@@Z PROC NEAR		; SortEdge, COMDAT

; 407  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 88					; 00000058H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-88]
	mov	ecx, 22					; 00000016H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 408  : 	int i,j,k=0;

	mov	DWORD PTR _k$[ebp], 0

; 409  : 	Edge temp;
; 410  : 	for(i=0;i<g.n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L929
$L930:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L929:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _g$[ebp+40000]
	jge	$L931

; 412  :        for(j=0;j<g.n;j++)

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L932
$L933:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L932:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _g$[ebp+40000]
	jge	$L934

; 414  : 		   if(g.edges[i][j]!=0&&g.edges[i][j]<INF)

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	lea	edx, DWORD PTR _g$[ebp+ecx]
	mov	eax, DWORD PTR _j$[ebp]
	cmp	DWORD PTR [edx+eax*4], 0
	je	SHORT $L935
	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	lea	edx, DWORD PTR _g$[ebp+ecx]
	mov	eax, DWORD PTR _j$[ebp]
	cmp	DWORD PTR [edx+eax*4], 32767		; 00007fffH
	jge	SHORT $L935

; 416  : 			   E[k].i=i;

	mov	ecx, DWORD PTR _k$[ebp]
	imul	ecx, 12					; 0000000cH
	mov	edx, DWORD PTR _E$[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR [edx+ecx], eax

; 417  : 			   E[k].j=j;

	mov	ecx, DWORD PTR _k$[ebp]
	imul	ecx, 12					; 0000000cH
	mov	edx, DWORD PTR _E$[ebp]
	mov	eax, DWORD PTR _j$[ebp]
	mov	DWORD PTR [edx+ecx+4], eax

; 418  : 			   E[k].weight=g.edges[i][j];

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 400				; 00000190H
	lea	edx, DWORD PTR _g$[ebp+ecx]
	mov	eax, DWORD PTR _k$[ebp]
	imul	eax, 12					; 0000000cH
	mov	ecx, DWORD PTR _E$[ebp]
	mov	esi, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR [edx+esi*4]
	mov	DWORD PTR [ecx+eax+8], edx

; 419  : 			   k++;

	mov	eax, DWORD PTR _k$[ebp]
	add	eax, 1
	mov	DWORD PTR _k$[ebp], eax
$L935:

; 421  : 	   }

	jmp	$L933
$L934:

; 422  : 	}

	jmp	$L930
$L931:

; 423  : 	for(i=1;i<k;i++)

	mov	DWORD PTR _i$[ebp], 1
	jmp	SHORT $L936
$L937:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L936:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _k$[ebp]
	jge	$L938

; 425  :        j=i-1;

	mov	eax, DWORD PTR _i$[ebp]
	sub	eax, 1
	mov	DWORD PTR _j$[ebp], eax

; 426  : 	   temp=E[i];

	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 12					; 0000000cH
	mov	edx, DWORD PTR _E$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _temp$[ebp], eax
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR _temp$[ebp+4], ecx
	mov	edx, DWORD PTR [edx+8]
	mov	DWORD PTR _temp$[ebp+8], edx
$L940:

; 427  : 	   while(j>=0&&E[j].weight>temp.weight)

	cmp	DWORD PTR _j$[ebp], 0
	jl	SHORT $L941
	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 12					; 0000000cH
	mov	ecx, DWORD PTR _E$[ebp]
	mov	edx, DWORD PTR [ecx+eax+8]
	cmp	edx, DWORD PTR _temp$[ebp+8]
	jle	SHORT $L941

; 429  : 		   E[j+1]=E[j];

	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 12					; 0000000cH
	mov	ecx, DWORD PTR _E$[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	imul	edx, 12					; 0000000cH
	mov	eax, DWORD PTR _E$[ebp]
	add	eax, edx
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	ecx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], ecx

; 430  : 		   j--;

	mov	edx, DWORD PTR _j$[ebp]
	sub	edx, 1
	mov	DWORD PTR _j$[ebp], edx

; 431  : 	   }

	jmp	SHORT $L940
$L941:

; 432  : 	   E[j+1]=temp;

	mov	eax, DWORD PTR _j$[ebp]
	add	eax, 1
	imul	eax, 12					; 0000000cH
	mov	ecx, DWORD PTR _E$[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _temp$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _temp$[ebp+4]
	mov	DWORD PTR [ecx+4], eax
	mov	edx, DWORD PTR _temp$[ebp+8]
	mov	DWORD PTR [ecx+8], edx

; 433  : 	}

	jmp	$L937
$L938:

; 434  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?SortEdge@@YAXUMGraph@@QAUEdge@@@Z ENDP			; SortEdge
_TEXT	ENDS
PUBLIC	??_C@_09PMFM@?$CI?$CFd?0?$CFd?$CJ?5?5?$AA@	; `string'
;	COMDAT ??_C@_09PMFM@?$CI?$CFd?0?$CFd?$CJ?5?5?$AA@
; File f:\学习\1203  121110098曾勇华\121110098曾勇华-6.3图最短路径\graph.h
CONST	SEGMENT
??_C@_09PMFM@?$CI?$CFd?0?$CFd?$CJ?5?5?$AA@ DB '(%d,%d)  ', 00H ; `string'
CONST	ENDS
;	COMDAT ?Kruskal@@YAXQAUEdge@@HH@Z
_TEXT	SEGMENT
_E$ = 8
_n$ = 12
_i$ = -4
_k$ = -8
_j$ = -12
_sn1$ = -16
_sn2$ = -20
_vset$ = -420
?Kruskal@@YAXQAUEdge@@HH@Z PROC NEAR			; Kruskal, COMDAT

; 436  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 484				; 000001e4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-484]
	mov	ecx, 121				; 00000079H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 437  : 	int i,k=1,j=0,sn1,sn2;

	mov	DWORD PTR _k$[ebp], 1
	mov	DWORD PTR _j$[ebp], 0

; 438  : 	int vset[MAX];
; 439  : 	for(i=0;i<n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L953
$L954:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L953:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L955

; 440  : 		vset[i]=i;

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR _vset$[ebp+edx*4], eax
	jmp	SHORT $L954
$L955:

; 441  : 	for(k=1;k<n;i++)

	mov	DWORD PTR _k$[ebp], 1
	jmp	SHORT $L956
$L957:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L956:
	mov	edx, DWORD PTR _k$[ebp]
	cmp	edx, DWORD PTR _n$[ebp]
	jge	$L958

; 443  : 		sn1=vset[E[j].i];

	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 12					; 0000000cH
	mov	ecx, DWORD PTR _E$[ebp]
	mov	edx, DWORD PTR [ecx+eax]
	mov	eax, DWORD PTR _vset$[ebp+edx*4]
	mov	DWORD PTR _sn1$[ebp], eax

; 444  : 		sn2=vset[E[j].j];

	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 12					; 0000000cH
	mov	edx, DWORD PTR _E$[ebp]
	mov	eax, DWORD PTR [edx+ecx+4]
	mov	ecx, DWORD PTR _vset$[ebp+eax*4]
	mov	DWORD PTR _sn2$[ebp], ecx

; 445  : 		if(sn1!=sn2)

	mov	edx, DWORD PTR _sn1$[ebp]
	cmp	edx, DWORD PTR _sn2$[ebp]
	je	SHORT $L963

; 447  : 			k++;

	mov	eax, DWORD PTR _k$[ebp]
	add	eax, 1
	mov	DWORD PTR _k$[ebp], eax

; 448  : 			printf("(%d,%d)  ",E[j].i,E[j].j);

	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 12					; 0000000cH
	mov	edx, DWORD PTR _E$[ebp]
	mov	eax, DWORD PTR [edx+ecx+4]
	push	eax
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 12					; 0000000cH
	mov	edx, DWORD PTR _E$[ebp]
	mov	eax, DWORD PTR [edx+ecx]
	push	eax
	push	OFFSET FLAT:??_C@_09PMFM@?$CI?$CFd?0?$CFd?$CJ?5?5?$AA@ ; `string'
	call	_printf
	add	esp, 12					; 0000000cH

; 449  : 			for(i=0;i<n;i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L961
$L962:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L961:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _n$[ebp]
	jge	SHORT $L963

; 451  : 				if(vset[i]==sn2)

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _vset$[ebp+eax*4]
	cmp	ecx, DWORD PTR _sn2$[ebp]
	jne	SHORT $L964

; 452  : 					vset[i]=sn1;

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _sn1$[ebp]
	mov	DWORD PTR _vset$[ebp+edx*4], eax
$L964:

; 453  : 			}

	jmp	SHORT $L962
$L963:

; 455  : 		j++;

	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx

; 456  : 	}

	jmp	$L957
$L958:

; 457  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 484				; 000001e4H
	cmp	ebp, esp
	call	__chkesp
	mov	esp, ebp
	pop	ebp
	ret	0
?Kruskal@@YAXQAUEdge@@HH@Z ENDP				; Kruskal
_TEXT	ENDS
END
