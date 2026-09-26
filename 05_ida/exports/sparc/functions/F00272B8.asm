F00272B8: 9de3bf98                 save    %sp, -0x68, %sp
F00272BC: 7ffffff7                 call    _pn_alloc
F00272C0: 9010001a                 mov     %i2, %o0
F00272C4: 80a66000                 cmp     %i1, 0
F00272C8: 12800008                 bne     loc_F00272E8
F00272CC: 90100018                 mov     %i0, %o0
F00272D0: d206a004                 ld      [%i2+4], %o1
F00272D4: 94102400                 mov     0x400, %o2
F00272D8: 4001c293                 call    _copyinstr
F00272DC: 9606a008                 add     %i2, 8, %o3
F00272E0: 10800007                 ba      loc_F00272FC
F00272E4: b0100008                 mov     %o0, %i0
F00272E8: d206a004                 ld      [%i2+4], %o1
F00272EC: 94102400                 mov     0x400, %o2
F00272F0: 4001c2f5                 call    _copystr
F00272F4: 9606a008                 add     %i2, 8, %o3
F00272F8: b0100008                 mov     %o0, %i0
F00272FC: 80a62000                 cmp     %i0, 0
F0027300: 1280000c                 bne     loc_F0027330
F0027304: d006a008                 ld      [%i2+8], %o0
F0027308: 80a22400                 cmp     %o0, 0x400
F002730C: 12800009                 bne     loc_F0027330
F0027310: 80a62000                 cmp     %i0, 0
F0027314: d006a004                 ld      [%i2+4], %o0
F0027318: d04a23ff                 ldsb    [%o0+0x3FF], %o0
F002731C: 80a22000                 cmp     %o0, 0
F0027320: 32800002                 bne,a   loc_F0027328
F0027324: b010203f                 mov     0x3F, %i0 ! '?'
F0027328: d006a008                 ld      [%i2+8], %o0
F002732C: 80a62000                 cmp     %i0, 0
F0027330: 90023fff                 inc     -1, %o0
F0027334: 02800004                 be      locret_F0027344
F0027338: d026a008                 st      %o0, [%i2+8]
F002733C: 4000006b                 call    _pn_free
F0027340: 9010001a                 mov     %i2, %o0
F0027344: 81c7e008                 ret
F0027348: 81e80000                 restore
