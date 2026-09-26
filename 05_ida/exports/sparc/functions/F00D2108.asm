F00D2108: 9de3bf90                 save    %sp, -0x70, %sp
F00D210C: 113c0505                 sethi   %hi(paEvcloseToken), %o0! id
F00D2110: d2022358                 ld      [%o0+%lo(paEvcloseToken)], %o1! SEL
F00D2114: d4062134                 ld      [%i0+0x134], %o2
F00D2118: d6062114                 ld      [%i0+0x114], %o3
F00D211C: 40007dd5                 call    _objc_msgSend
F00D2120: 90100018                 mov     %i0, %o0
F00D2124: 7ffe5463                 call    _task_self
F00D2128: 01000000                 nop
F00D212C: 400086d0                 call    _port_deallocate_EXTERNAL
F00D2130: d2062134                 ld      [%i0+0x134], %o1
F00D2134: 7ffe545f                 call    _task_self
F00D2138: 01000000                 nop
F00D213C: 400086cc                 call    _port_deallocate_EXTERNAL
F00D2140: d2062138                 ld      [%i0+0x138], %o1
F00D2144: 7ffe545b                 call    _task_self
F00D2148: 01000000                 nop
F00D214C: 400086c8                 call    _port_deallocate_EXTERNAL
F00D2150: d206213c                 ld      [%i0+0x13C], %o1
F00D2154: 7ffe5457                 call    _task_self
F00D2158: 01000000                 nop
F00D215C: 40008789                 call    _port_set_deallocate_EXTERNAL
F00D2160: d2062148                 ld      [%i0+0x148], %o1! SEL
F00D2164: 113c0503                 sethi   %hi(paFree), %o0
F00D2168: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00D216C: d0062170                 ld      [%i0+0x170], %o0! id
F00D2170: 40007dc0                 call    _objc_msgSend
F00D2174: 92100010                 mov     %l0, %o1! SEL
F00D2178: d0062110                 ld      [%i0+0x110], %o0! id
F00D217C: 40007dbd                 call    _objc_msgSend
F00D2180: 92100010                 mov     %l0, %o1
F00D2184: f027bff0                 st      %i0, [%fp+var_10]
F00D2188: 133c0508                 sethi   %hi(stru_F01421DC.super_class), %o1
F00D218C: d40261e0                 ld      [%o1+%lo(stru_F01421DC.super_class)], %o2
F00D2190: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D2194: 92100010                 mov     %l0, %o1! SEL
F00D2198: 40007df9                 call    _objc_msgSendSuper
F00D219C: d427bff4                 st      %o2, [%fp+var_C]
F00D21A0: 81c7e008                 ret
F00D21A4: 91e80008                 restore %g0, %o0, %o0
