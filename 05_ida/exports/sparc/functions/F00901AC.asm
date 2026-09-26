F00901AC: 9de3bf90                 save    %sp, -0x70, %sp
F00901B0: d0062008                 ld      [%i0+8], %o0
F00901B4: a2102000                 mov     0, %l1
F00901B8: 80a44008                 cmp     %l1, %o0
F00901BC: 3a800010                 bcc,a   loc_F00901FC
F00901C0: d2062008                 ld      [%i0+8], %o1
F00901C4: d2062004                 ld      [%i0+4], %o1
F00901C8: 912c6002                 sll     %l1, 2, %o0! __s
F00901CC: e0024008                 ld      [%o1+%o0], %l0
F00901D0: 7ffddc9a                 call    _strlen
F00901D4: 90100010                 mov     %l0, %o0
F00901D8: 92022001                 add     %o0, 1, %o1
F00901DC: 7fffff69                 call    sub_F008FF80
F00901E0: 90100010                 mov     %l0, %o0
F00901E4: d0062008                 ld      [%i0+8], %o0
F00901E8: a2046001                 inc     %l1
F00901EC: 80a44008                 cmp     %l1, %o0
F00901F0: 2abffff6                 bcs,a   loc_F00901C8
F00901F4: d2062004                 ld      [%i0+4], %o1
F00901F8: d2062008                 ld      [%i0+8], %o1
F00901FC: d0062004                 ld      [%i0+4], %o0
F0090200: 7fffff60                 call    sub_F008FF80
F0090204: 932a6002                 sll     %o1, 2, %o1
F0090208: f027bff0                 st      %i0, [%fp+var_10]
F009020C: 133c0507                 sethi   %hi(stru_F0141CDC.ext), %o1
F0090210: d4026108                 ld      [%o1+%lo(stru_F0141CDC.ext)], %o2
F0090214: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F0090218: 133c0503                 sethi   %hi(paFree), %o1
F009021C: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F0090220: 400185d7                 call    _objc_msgSendSuper
F0090224: d427bff4                 st      %o2, [%fp+var_C]
F0090228: 81c7e008                 ret
F009022C: 91e80008                 restore %g0, %o0, %o0
