F00BC1A4: 9de3bf98                 save    %sp, -0x68, %sp
F00BC1A8: 113c04fd                 sethi   %hi(_kmId), %o0
F00BC1AC: d4022240                 ld      [%o0+%lo(_kmId)], %o2
F00BC1B0: 80a2a000                 cmp     %o2, 0
F00BC1B4: 02800005                 be      locret_F00BC1C8
F00BC1B8: 113c0504                 sethi   %hi(paDumpmsgbuf), %o0! id
F00BC1BC: d2022218                 ld      [%o0+%lo(paDumpmsgbuf)], %o1! SEL
F00BC1C0: 4000d5ac                 call    _objc_msgSend
F00BC1C4: 9010000a                 mov     %o2, %o0
F00BC1C8: 81c7e008                 ret
F00BC1CC: 81e80000                 restore
