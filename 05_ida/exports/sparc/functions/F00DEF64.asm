F00DEF64: 9de3bf98                 save    %sp, -0x68, %sp
F00DEF68: 80a62000                 cmp     %i0, 0
F00DEF6C: 0280000e                 be      loc_F00DEFA4
F00DEF70: c0268000                 clr     [%i2]
F00DEF74: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00DEF78: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00DEF7C: 40004a3d                 call    _objc_msgSend
F00DEF80: 90100018                 mov     %i0, %o0! id
F00DEF84: 133c0504                 sethi   %hi(paGetsupportedpa), %o1
F00DEF88: 94100019                 mov     %i1, %o2
F00DEF8C: 9610001a                 mov     %i2, %o3
F00DEF90: d20263e4                 ld      [%o1+%lo(paGetsupportedpa)], %o1! SEL
F00DEF94: 40004a37                 call    _objc_msgSend
F00DEF98: 98100018                 mov     %i0, %o4
F00DEF9C: 10800003                 ba      locret_F00DEFA8
F00DEFA0: b0102000                 mov     0, %i0
F00DEFA4: b01020ca                 mov     0xCA, %i0
F00DEFA8: 81c7e008                 ret
F00DEFAC: 81e80000                 restore
