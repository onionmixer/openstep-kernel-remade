F00DE698: 9de3bf98                 save    %sp, -0x68, %sp
F00DE69C: 80a62000                 cmp     %i0, 0
F00DE6A0: 02800017                 be      loc_F00DE6FC
F00DE6A4: 113c0505                 sethi   %hi(paAudiodevice), %o0
F00DE6A8: e2022224                 ld      [%o0+%lo(paAudiodevice)], %l1
F00DE6AC: 90100018                 mov     %i0, %o0! id
F00DE6B0: 40004c70                 call    _objc_msgSend
F00DE6B4: 92100011                 mov     %l1, %o1
F00DE6B8: 9410200c                 mov     0xC, %o2
F00DE6BC: 133c0505                 sethi   %hi(paIntvalueforpar), %o1! SEL
F00DE6C0: e00260f8                 ld      [%o1+%lo(paIntvalueforpar)], %l0
F00DE6C4: 96100018                 mov     %i0, %o3
F00DE6C8: 40004c6a                 call    _objc_msgSend
F00DE6CC: 92100010                 mov     %l0, %o1! SEL
F00DE6D0: d0264000                 st      %o0, [%i1]
F00DE6D4: 90100018                 mov     %i0, %o0! id
F00DE6D8: 40004c66                 call    _objc_msgSend
F00DE6DC: 92100011                 mov     %l1, %o1
F00DE6E0: 92100010                 mov     %l0, %o1! SEL
F00DE6E4: 9410200d                 mov     0xD, %o2
F00DE6E8: 40004c62                 call    _objc_msgSend
F00DE6EC: 96100018                 mov     %i0, %o3
F00DE6F0: d0268000                 st      %o0, [%i2]
F00DE6F4: 10800003                 ba      locret_F00DE700
F00DE6F8: b0102000                 mov     0, %i0
F00DE6FC: b01020ca                 mov     0xCA, %i0
F00DE700: 81c7e008                 ret
F00DE704: 81e80000                 restore
