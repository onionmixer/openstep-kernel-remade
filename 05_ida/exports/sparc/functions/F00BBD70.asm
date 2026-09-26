F00BBD70: 9de3bf98                 save    %sp, -0x68, %sp
F00BBD74: 113c04fd                 sethi   %hi(_kmId), %o0
F00BBD78: d4022240                 ld      [%o0+%lo(_kmId)], %o2
F00BBD7C: 80a2a000                 cmp     %o2, 0
F00BBD80: 12800004                 bne     loc_F00BBD90
F00BBD84: 113c0504                 sethi   -0xFEBF000, %o0! id
F00BBD88: 10800009                 ba      locret_F00BBDAC
F00BBD8C: b0102000                 mov     0, %i0
F00BBD90: d202222c                 ld      [%o0+0x22C], %o1! SEL
F00BBD94: 4000d6b7                 call    _objc_msgSend
F00BBD98: 9010000a                 mov     %o2, %o0
F00BBD9C: 80a2200d                 cmp     %o0, 0xD
F00BBDA0: 22800002                 be,a    loc_F00BBDA8
F00BBDA4: 9010200a                 mov     0xA, %o0
F00BBDA8: b0100008                 mov     %o0, %i0
F00BBDAC: 81c7e008                 ret
F00BBDB0: 81e80000                 restore
