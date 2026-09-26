F00C2120: 9de3bf90                 save    %sp, -0x70, %sp
F00C2124: d0062128                 ld      [%i0+0x128], %o0! id
F00C2128: 80a22000                 cmp     %o0, 0
F00C212C: 02800006                 be      loc_F00C2144
F00C2130: 133c0504                 sethi   %hi(paDispatchpointe), %o1
F00C2134: 153c04cc                 sethi   %hi(qword_F0133008), %o2
F00C2138: d2026324                 ld      [%o1+%lo(paDispatchpointe)], %o1! SEL
F00C213C: 4000bdcd                 call    _objc_msgSend
F00C2140: 9412a008                 bset    %lo(qword_F0133008), %o2
F00C2144: 113c04cc                 sethi   %hi(dword_F0133028), %o0
F00C2148: c0222028                 clr     [%o0+%lo(dword_F0133028)]
F00C214C: 81c7e008                 ret
F00C2150: 81e80000                 restore
