F00BED34: 9de3bf98                 save    %sp, -0x68, %sp
F00BED38: d006201c                 ld      [%i0+0x1C], %o0
F00BED3C: d2022008                 ld      [%o0+8], %o1
F00BED40: 80a26003                 cmp     %o1, 3
F00BED44: 32800007                 bne,a   loc_F00BED60
F00BED48: 113c0482                 sethi   -0xFEDF800, %o0
F00BED4C: d2022050                 ld      [%o0+0x50], %o1
F00BED50: 40009cb5                 call    _sparcfbRestoreRect
F00BED54: 90102000                 mov     0, %o0
F00BED58: 10800005                 ba      locret_F00BED6C
F00BED5C: b0100008                 mov     %o0, %i0
F00BED60: 40001ce5                 call    _IOLog
F00BED64: 90122220                 bset    0x220, %o0
F00BED68: b0103fff                 mov     -1, %i0
F00BED6C: 81c7e008                 ret
F00BED70: 81e80000                 restore
