F008E68C: 9de3bf90                 save    %sp, -0x70, %sp
F008E690: d4062008                 ld      [%i0+8], %o2
F008E694: 80a2a000                 cmp     %o2, 0
F008E698: 02800009                 be      locret_F008E6BC
F008E69C: 113c0504                 sethi   %hi(paFreeobjects), %o0! id
F008E6A0: d20220cc                 ld      [%o0+%lo(paFreeobjects)], %o1! SEL
F008E6A4: 40018c73                 call    _objc_msgSend
F008E6A8: 9010000a                 mov     %o2, %o0! id
F008E6AC: 133c0503                 sethi   %hi(paFree), %o1! SEL
F008E6B0: 40018c70                 call    _objc_msgSend
F008E6B4: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F008E6B8: c0262008                 clr     [%i0+8]
F008E6BC: 81c7e008                 ret
F008E6C0: 81e80000                 restore
