F008FC60: 9de3bf10                 save    %sp, -0xF0, %sp
F008FC64: a007bf70                 add     %fp, var_90, %l0
F008FC68: 90100010                 mov     %l0, %o0! char *
F008FC6C: 133c0448921260b8         set     aShareS, %o1! "Share %s"
F008FC74: 7ffe12bd                 call    _sprintf
F008FC78: 9410001a                 mov     %i2, %o2
F008FC7C: 90100018                 mov     %i0, %o0! id
F008FC80: 133c0504                 sethi   %hi(paStringforkey), %o1
F008FC84: d202610c                 ld      [%o1+%lo(paStringforkey)], %o1! SEL
F008FC88: 400186fa                 call    _objc_msgSend
F008FC8C: 94100010                 mov     %l0, %o2
F008FC90: 80a22000                 cmp     %o0, 0
F008FC94: 22800009                 be,a    locret_F008FCB8
F008FC98: b0102000                 mov     0, %i0
F008FC9C: d04a0000                 ldsb    [%o0], %o0
F008FCA0: 80a22079                 cmp     %o0, 0x79 ! 'y'
F008FCA4: 02800004                 be      loc_F008FCB4
F008FCA8: 80a22059                 cmp     %o0, 0x59 ! 'Y'
F008FCAC: 12800003                 bne     locret_F008FCB8
F008FCB0: b0102000                 mov     0, %i0
F008FCB4: b0102001                 mov     1, %i0
F008FCB8: 81c7e008                 ret
F008FCBC: 81e80000                 restore
