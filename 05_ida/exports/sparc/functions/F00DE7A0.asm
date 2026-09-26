F00DE7A0: 9de3bf98                 save    %sp, -0x68, %sp
F00DE7A4: 113c0505                 sethi   %hi(paChannel), %o0
F00DE7A8: e4022058                 ld      [%o0+%lo(paChannel)], %l2
F00DE7AC: 90100018                 mov     %i0, %o0! id
F00DE7B0: 40004c30                 call    _objc_msgSend
F00DE7B4: 92100012                 mov     %l2, %o1
F00DE7B8: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DE7BC: e2026224                 ld      [%o1+%lo(paAudiodevice)], %l1
F00DE7C0: 40004c2c                 call    _objc_msgSend
F00DE7C4: 92100011                 mov     %l1, %o1
F00DE7C8: 94102199                 mov     0x199, %o2
F00DE7CC: 96100019                 mov     %i1, %o3
F00DE7D0: 133c0505                 sethi   %hi(paSetparameterTo), %o1! SEL
F00DE7D4: e00260fc                 ld      [%o1+%lo(paSetparameterTo)], %l0
F00DE7D8: 98100018                 mov     %i0, %o4
F00DE7DC: 40004c25                 call    _objc_msgSend
F00DE7E0: 92100010                 mov     %l0, %o1! SEL
F00DE7E4: 90100018                 mov     %i0, %o0! id
F00DE7E8: 40004c22                 call    _objc_msgSend
F00DE7EC: 92100012                 mov     %l2, %o1! SEL
F00DE7F0: 40004c20                 call    _objc_msgSend
F00DE7F4: 92100011                 mov     %l1, %o1
F00DE7F8: 92100010                 mov     %l0, %o1! SEL
F00DE7FC: 9410219a                 mov     0x19A, %o2
F00DE800: 9610001a                 mov     %i2, %o3
F00DE804: 40004c1b                 call    _objc_msgSend
F00DE808: 98100018                 mov     %i0, %o4
F00DE80C: 81c7e008                 ret
F00DE810: 91e82000                 restore %g0, 0, %o0
