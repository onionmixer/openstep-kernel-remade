F00DEB30: 9de3bf98                 save    %sp, -0x68, %sp
F00DEB34: 80a62000                 cmp     %i0, 0
F00DEB38: 02800011                 be      loc_F00DEB7C
F00DEB3C: 113c0505                 sethi   %hi(paChannel), %o0! id
F00DEB40: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DEB44: 40004b4b                 call    _objc_msgSend
F00DEB48: 90100018                 mov     %i0, %o0! id
F00DEB4C: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DEB50: 40004b48                 call    _objc_msgSend
F00DEB54: d2026224                 ld      [%o1+%lo(paAudiodevice)], %o1
F00DEB58: 80a00019                 cmp     %g0, %i1
F00DEB5C: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DEB60: 94102197                 mov     0x197, %o2
F00DEB64: 96402000                 addc    %g0, 0, %o3
F00DEB68: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1! SEL
F00DEB6C: 40004b41                 call    _objc_msgSend
F00DEB70: 98100018                 mov     %i0, %o4
F00DEB74: 10800003                 ba      locret_F00DEB80
F00DEB78: b0102000                 mov     0, %i0
F00DEB7C: b01020ca                 mov     0xCA, %i0
F00DEB80: 81c7e008                 ret
F00DEB84: 81e80000                 restore
