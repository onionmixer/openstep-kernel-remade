F00DE9C4: 9de3b790                 save    %sp, -0x870, %sp
F00DE9C8: e407a064                 ld      [%fp+arg_64], %l2
F00DE9CC: e607a068                 ld      [%fp+arg_68], %l3
F00DE9D0: 80a62000                 cmp     %i0, 0
F00DE9D4: 12800004                 bne     loc_F00DE9E4
F00DE9D8: e807a070                 ld      [%fp+arg_70], %l4
F00DE9DC: 10800053                 ba      locret_F00DEB28
F00DE9E0: b01020ca                 mov     0xCA, %i0
F00DE9E4: 113c0505                 sethi   %hi(paChannel), %o0! id
F00DE9E8: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DE9EC: 40004ba1                 call    _objc_msgSend
F00DE9F0: 90100018                 mov     %i0, %o0
F00DE9F4: a2100008                 mov     %o0, %l1
F00DE9F8: 113c0505                 sethi   %hi(paCheckowner), %o0! id
F00DE9FC: e0022018                 ld      [%o0+%lo(paCheckowner)], %l0
F00DEA00: 133c0505                 sethi   %hi(paOwnerport), %o1
F00DEA04: d20260b0                 ld      [%o1+%lo(paOwnerport)], %o1! SEL
F00DEA08: 40004b9a                 call    _objc_msgSend
F00DEA0C: 90100018                 mov     %i0, %o0
F00DEA10: 94100008                 mov     %o0, %o2
F00DEA14: 90100011                 mov     %l1, %o0! id
F00DEA18: 40004b96                 call    _objc_msgSend
F00DEA1C: 92100010                 mov     %l0, %o1
F00DEA20: 912a2018                 sll     %o0, 24, %o0
F00DEA24: 80a22000                 cmp     %o0, 0
F00DEA28: 12800004                 bne     loc_F00DEA38
F00DEA2C: 80a6a000                 cmp     %i2, 0
F00DEA30: 10800032                 ba      loc_F00DEAF8
F00DEA34: b01020c8                 mov     0xC8, %i0
F00DEA38: 0280002f                 be      loc_F00DEAF4
F00DEA3C: 90102192                 mov     0x192, %o0
F00DEA40: d027bbf8                 st      %o0, [%fp+var_408]
F00DEA44: f827b7f8                 st      %i4, [%fp+var_808]
F00DEA48: 90102191                 mov     0x191, %o0
F00DEA4C: 80a76001                 cmp     %i5, 1
F00DEA50: 12800005                 bne     loc_F00DEA64
F00DEA54: d027bbfc                 st      %o0, [%fp+var_404]
F00DEA58: 11000015                 sethi   0x5400, %o0
F00DEA5C: 10800004                 ba      loc_F00DEA6C
F00DEA60: 90122222                 bset    0x222, %o0
F00DEA64: 1100002b90122044         set     0xAC44, %o0
F00DEA6C: d027b7fc                 st      %o0, [%fp+var_804]
F00DEA70: 90102194                 mov     0x194, %o0
F00DEA74: d027bc00                 st      %o0, [%fp+var_400]
F00DEA78: e427b800                 st      %l2, [%fp+var_800]
F00DEA7C: 90102193                 mov     0x193, %o0
F00DEA80: d027bc04                 st      %o0, [%fp+var_3FC]
F00DEA84: 113c0505                 sethi   %hi(paChannel), %o0! id
F00DEA88: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DEA8C: e627b804                 st      %l3, [%fp+var_7FC]
F00DEA90: 40004b78                 call    _objc_msgSend
F00DEA94: 90100018                 mov     %i0, %o0! id
F00DEA98: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DEA9C: 40004b75                 call    _objc_msgSend
F00DEAA0: d2026224                 ld      [%o1+%lo(paAudiodevice)], %o1
F00DEAA4: 9407bbf8                 add     %fp, var_408, %o2
F00DEAA8: 9607b7f8                 add     %fp, var_808, %o3
F00DEAAC: 98102004                 mov     4, %o4
F00DEAB0: 133c0504                 sethi   %hi(paSetparametersT), %o1
F00DEAB4: d20263fc                 ld      [%o1+%lo(paSetparametersT)], %o1! SEL
F00DEAB8: 40004b6e                 call    _objc_msgSend
F00DEABC: 9a100018                 mov     %i0, %o5
F00DEAC0: e823a05c                 st      %l4, [%sp+0x870+var_814]
F00DEAC4: 90100018                 mov     %i0, %o0! id
F00DEAC8: 94100019                 mov     %i1, %o2
F00DEACC: 133c0504                 sethi   %hi(paPlaybufferSize), %o1
F00DEAD0: d20263f8                 ld      [%o1+%lo(paPlaybufferSize)], %o1! SEL
F00DEAD4: 9610001a                 mov     %i2, %o3
F00DEAD8: da07a06c                 ld      [%fp+arg_6C], %o5
F00DEADC: 40004b65                 call    _objc_msgSend
F00DEAE0: 9810001b                 mov     %i3, %o4
F00DEAE4: 912a2018                 sll     %o0, 24, %o0
F00DEAE8: 80a22000                 cmp     %o0, 0
F00DEAEC: 1280000f                 bne     locret_F00DEB28
F00DEAF0: b0102000                 mov     0, %i0
F00DEAF4: b01020cc                 mov     0xCC, %i0
F00DEAF8: 7ffe21ee                 call    _task_self
F00DEAFC: 01000000                 nop
F00DEB00: 92100019                 mov     %i1, %o1
F00DEB04: 40005629                 call    _vm_deallocate_EXTERNAL
F00DEB08: 9410001a                 mov     %i2, %o2
F00DEB0C: 94920000                 orcc    %o0, %g0, %o2
F00DEB10: 02800006                 be      locret_F00DEB28
F00DEB14: 113c03f2                 sethi   %hi(aAudioAudioServ), %o0! "Audio: audio server vm_deallocate error"...
F00DEB18: 901220b8                 bset    %lo(aAudioAudioServ), %o0! "Audio: audio server vm_deallocate error"...
F00DEB1C: 133c03f1                 sethi   %hi(aMachErr), %o1! "MACH ERR"
F00DEB20: 7fff9d75                 call    _IOLog
F00DEB24: 92126020                 bset    %lo(aMachErr), %o1! "MACH ERR"
F00DEB28: 81c7e008                 ret
F00DEB2C: 81e80000                 restore
