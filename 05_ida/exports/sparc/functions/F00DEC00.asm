F00DEC00: 9de3b798                 save    %sp, -0x868, %sp
F00DEC04: 80a62000                 cmp     %i0, 0
F00DEC08: 12800004                 bne     loc_F00DEC18
F00DEC0C: 113c0505                 sethi   -0xFEBEC00, %o0
F00DEC10: 10800039                 ba      locret_F00DECF4
F00DEC14: b01020ca                 mov     0xCA, %i0
F00DEC18: e4022058                 ld      [%o0+0x58], %l2
F00DEC1C: 90100018                 mov     %i0, %o0! id
F00DEC20: 40004b14                 call    _objc_msgSend
F00DEC24: 92100012                 mov     %l2, %o1
F00DEC28: a2100008                 mov     %o0, %l1
F00DEC2C: 113c0505                 sethi   %hi(paCheckowner), %o0! id
F00DEC30: e0022018                 ld      [%o0+%lo(paCheckowner)], %l0
F00DEC34: 133c0505                 sethi   %hi(paOwnerport), %o1
F00DEC38: d20260b0                 ld      [%o1+%lo(paOwnerport)], %o1! SEL
F00DEC3C: 40004b0d                 call    _objc_msgSend
F00DEC40: 90100018                 mov     %i0, %o0
F00DEC44: 94100008                 mov     %o0, %o2
F00DEC48: 90100011                 mov     %l1, %o0! id
F00DEC4C: 40004b09                 call    _objc_msgSend
F00DEC50: 92100010                 mov     %l0, %o1! SEL
F00DEC54: 912a2018                 sll     %o0, 24, %o0
F00DEC58: 80a22000                 cmp     %o0, 0
F00DEC5C: 12800004                 bne     loc_F00DEC6C
F00DEC60: 80a66000                 cmp     %i1, 0
F00DEC64: 10800024                 ba      locret_F00DECF4
F00DEC68: b01020c8                 mov     0xC8, %i0
F00DEC6C: 12800004                 bne     loc_F00DEC7C
F00DEC70: 90102194                 mov     0x194, %o0
F00DEC74: 10800020                 ba      locret_F00DECF4
F00DEC78: b01020cc                 mov     0xCC, %i0
F00DEC7C: d027bbf8                 st      %o0, [%fp+var_408]
F00DEC80: f627b7f8                 st      %i3, [%fp+var_808]
F00DEC84: 90102193                 mov     0x193, %o0
F00DEC88: d027bbfc                 st      %o0, [%fp+var_404]
F00DEC8C: f827b7fc                 st      %i4, [%fp+var_804]
F00DEC90: 90100018                 mov     %i0, %o0! id
F00DEC94: 40004af7                 call    _objc_msgSend
F00DEC98: 92100012                 mov     %l2, %o1
F00DEC9C: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DECA0: 40004af4                 call    _objc_msgSend
F00DECA4: d2026224                 ld      [%o1+%lo(paAudiodevice)], %o1
F00DECA8: 9407bbf8                 add     %fp, var_408, %o2
F00DECAC: 9607b7f8                 add     %fp, var_808, %o3
F00DECB0: 98102002                 mov     2, %o4
F00DECB4: 133c0504                 sethi   %hi(paSetparametersT), %o1
F00DECB8: d20263fc                 ld      [%o1+%lo(paSetparametersT)], %o1! SEL
F00DECBC: 40004aed                 call    _objc_msgSend
F00DECC0: 9a100018                 mov     %i0, %o5
F00DECC4: 90100018                 mov     %i0, %o0! id
F00DECC8: 94100019                 mov     %i1, %o2
F00DECCC: 133c0504                 sethi   %hi(paRecordsizeTagR), %o1
F00DECD0: d20263f4                 ld      [%o1+%lo(paRecordsizeTagR)], %o1! SEL
F00DECD4: 9610001a                 mov     %i2, %o3
F00DECD8: da07a05c                 ld      [%fp+arg_5C], %o5
F00DECDC: 40004ae5                 call    _objc_msgSend
F00DECE0: 9810001d                 mov     %i5, %o4
F00DECE4: 912a2018                 sll     %o0, 24, %o0
F00DECE8: 80a00008                 cmp     %g0, %o0
F00DECEC: b0403fff                 addc    %g0, -1, %i0
F00DECF0: b00e20cc                 and     %i0, 0xCC, %i0
F00DECF4: 81c7e008                 ret
F00DECF8: 81e80000                 restore
