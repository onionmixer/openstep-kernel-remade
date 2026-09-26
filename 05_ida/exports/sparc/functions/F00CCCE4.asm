F00CCCE4: 9de3bf90                 save    %sp, -0x70, %sp
F00CCCE8: d0062128                 ld      [%i0+0x128], %o0
F00CCCEC: 80a22000                 cmp     %o0, 0
F00CCCF0: 06800008                 bl      locret_F00CCD10
F00CCCF4: 92102000                 mov     0, %o1
F00CCCF8: d0062154                 ld      [%i0+0x154], %o0! id
F00CCCFC: 133c0506                 sethi   %hi(paSend), %o1
F00CCD00: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00CCD04: 400092db                 call    _objc_msgSend
F00CCD08: 94102001                 mov     1, %o2
F00CCD0C: 92100008                 mov     %o0, %o1
F00CCD10: 81c7e008                 ret
F00CCD14: 91e80009                 restore %g0, %o1, %o0
