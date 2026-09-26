F00BBC70: 9de3bf98                 save    %sp, -0x68, %sp
F00BBC74: 313c04fd                 sethi   %hi(_kmId), %i0
F00BBC78: d0062240                 ld      [%i0+%lo(_kmId)], %o0! id
F00BBC7C: 80a22000                 cmp     %o0, 0
F00BBC80: 0280000e                 be      loc_F00BBCB8
F00BBC84: 80a6600a                 cmp     %i1, 0xA
F00BBC88: 12800007                 bne     loc_F00BBCA4
F00BBC8C: 133c0504                 sethi   %hi(paKmputc), %o1
F00BBC90: d2026228                 ld      [%o1+%lo(paKmputc)], %o1! SEL
F00BBC94: 4000d6f7                 call    _objc_msgSend
F00BBC98: 9410200d                 mov     0xD, %o2
F00BBC9C: d0062240                 ld      [%i0+%lo(_kmId)], %o0! id
F00BBCA0: 133c0504                 sethi   -0xFEBF000, %o1
F00BBCA4: d2026228                 ld      [%o1+0x228], %o1! SEL
F00BBCA8: 4000d6f2                 call    _objc_msgSend
F00BBCAC: 94100019                 mov     %i1, %o2
F00BBCB0: 10800019                 ba      locret_F00BBD14
F00BBCB4: b0100008                 mov     %o0, %i0
F00BBCB8: 113c04fd                 sethi   %hi(_kmAlertConsole), %o0
F00BBCBC: f0022238                 ld      [%o0+%lo(_kmAlertConsole)], %i0
F00BBCC0: 80a62000                 cmp     %i0, 0
F00BBCC4: 12800005                 bne     loc_F00BBCD8
F00BBCC8: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BBCCC: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BBCD0: f0022228                 ld      [%o0+%lo(_basicConsole)], %i0
F00BBCD4: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BBCD8: d0022230                 ld      [%o0+0x230], %o0
F00BBCDC: 80a22002                 cmp     %o0, 2
F00BBCE0: 0280000d                 be      locret_F00BBD14
F00BBCE4: 80a6600a                 cmp     %i1, 0xA
F00BBCE8: 12800006                 bne     loc_F00BBD00
F00BBCEC: 90100018                 mov     %i0, %o0
F00BBCF0: d4062014                 ld      [%i0+0x14], %o2
F00BBCF4: 9fc28000                 call    %o2
F00BBCF8: 9210200d                 mov     0xD, %o1
F00BBCFC: 90100018                 mov     %i0, %o0
F00BBD00: 932e6018                 sll     %i1, 24, %o1
F00BBD04: d4022014                 ld      [%o0+0x14], %o2
F00BBD08: 9fc28000                 call    %o2
F00BBD0C: 933a6018                 sra     %o1, 24, %o1
F00BBD10: b0102000                 mov     0, %i0
F00BBD14: 81c7e008                 ret
F00BBD18: 81e80000                 restore
