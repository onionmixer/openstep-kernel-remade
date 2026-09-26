F00BEC08: 9de3bf98                 save    %sp, -0x68, %sp
F00BEC0C: 1300199992126266         set     0x666666, %o1
F00BEC14: 11003fff                 sethi   0xFFFC00, %o0
F00BEC18: f006201c                 ld      [%i0+0x1C], %i0
F00BEC1C: 901223ff                 bset    0x3FF, %o0
F00BEC20: d226202c                 st      %o1, [%i0+0x2C]
F00BEC24: d0262030                 st      %o0, [%i0+0x30]
F00BEC28: c0262034                 clr     [%i0+0x34]
F00BEC2C: d2262038                 st      %o1, [%i0+0x38]
F00BEC30: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00BEC34: 1100266690122199         set     0x999999, %o0
F00BEC3C: d2026364                 ld      [%o1+%lo(_sparcfbs)], %o1
F00BEC40: d026203c                 st      %o0, [%i0+0x3C]
F00BEC44: d0026028                 ld      [%o1+0x28], %o0
F00BEC48: d0260000                 st      %o0, [%i0]
F00BEC4C: d002602c                 ld      [%o1+0x2C], %o0
F00BEC50: 94062002                 add     %i0, 2, %o2
F00BEC54: 92100018                 mov     %i0, %o1
F00BEC58: d0262004                 st      %o0, [%i0+4]
F00BEC5C: c0262044                 clr     [%i0+0x44]
F00BEC60: c02aa048                 clrb    [%o2+0x48]
F00BEC64: 9402bfff                 inc     -1, %o2
F00BEC68: 80a28009                 cmp     %o2, %o1
F00BEC6C: 36bffffe                 bge,a   loc_F00BEC64
F00BEC70: c02aa048                 clrb    [%o2+0x48]
F00BEC74: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BEC78: 80a6a000                 cmp     %i2, 0
F00BEC7C: 0280000b                 be      loc_F00BECA8
F00BEC80: d026204c                 st      %o0, [%i0+0x4C]
F00BEC84: d0062008                 ld      [%i0+8], %o0
F00BEC88: 80a22003                 cmp     %o0, 3
F00BEC8C: 02800008                 be      loc_F00BECAC
F00BEC90: 80a66002                 cmp     %i1, 2
F00BEC94: 40009ed0                 call    _sparcfbRestoreMode
F00BEC98: 90102000                 mov     0, %o0
F00BEC9C: d206202c                 ld      [%i0+0x2C], %o1
F00BECA0: 7ffffce0                 call    sub_F00BE020
F00BECA4: 90100018                 mov     %i0, %o0
F00BECA8: 80a66002                 cmp     %i1, 2
F00BECAC: 02800020                 be      locret_F00BED2C
F00BECB0: f2262008                 st      %i1, [%i0+8]
F00BECB4: 80a66002                 cmp     %i1, 2
F00BECB8: 18800005                 bgu     loc_F00BECCC
F00BECBC: 80a66001                 cmp     %i1, 1
F00BECC0: 02800008                 be      loc_F00BECE0
F00BECC4: 113c0482                 sethi   -0xFEDF800, %o0
F00BECC8: 30800017                 ba,a    loc_F00BED24
F00BECCC: 80a66003                 cmp     %i1, 3
F00BECD0: 2280000e                 be,a    loc_F00BED08
F00BECD4: 90100018                 mov     %i0, %o0
F00BECD8: 10800013                 ba      loc_F00BED24
F00BECDC: 113c0482                 sethi   -0xFEDF800, %o0
F00BECE0: 40009ebd                 call    _sparcfbRestoreMode
F00BECE4: 90102000                 mov     0, %o0
F00BECE8: 90100018                 mov     %i0, %o0! char *
F00BECEC: 92102280                 mov     0x280, %o1
F00BECF0: 941021e0                 mov     0x1E0, %o2
F00BECF4: 9610001c                 mov     %i4, %o3
F00BECF8: 9810001b                 mov     %i3, %o4
F00BECFC: 7fffff1d                 call    sub_F00BE970
F00BED00: 9a102000                 mov     0, %o5
F00BED04: 3080000a                 ba,a    locret_F00BED2C
F00BED08: 92102140                 mov     0x140, %o1
F00BED0C: 941020c8                 mov     0xC8, %o2
F00BED10: 9610001c                 mov     %i4, %o3
F00BED14: 9810001b                 mov     %i3, %o4
F00BED18: 7fffff16                 call    sub_F00BE970
F00BED1C: 9a102001                 mov     1, %o5
F00BED20: 30800003                 ba,a    locret_F00BED2C
F00BED24: 7ffd5913                 call    _panic
F00BED28: 901221f8                 bset    0x1F8, %o0
F00BED2C: 81c7e008                 ret
F00BED30: 81e80000                 restore
