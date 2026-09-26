F00C4898: 9de3bf90                 save    %sp, -0x70, %sp
F00C489C: 113c03ea                 sethi   %hi(aIodevice), %o0! "IODevice"
F00C48A0: 4000b519                 call    _objc_getClass
F00C48A4: 90122038                 bset    %lo(aIodevice), %o0! "IODevice"
F00C48A8: 80a60008                 cmp     %i0, %o0
F00C48AC: 02800007                 be      loc_F00C48C8
F00C48B0: 113c0506                 sethi   %hi(paIodevice_0), %o0
F00C48B4: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F00C48B8: 133c0506                 sethi   %hi(paRegisterclass), %o1
F00C48BC: d20261f0                 ld      [%o1+%lo(paRegisterclass)], %o1! SEL
F00C48C0: 4000b3ec                 call    _objc_msgSend
F00C48C4: 94100018                 mov     %i0, %o2
F00C48C8: 253c04bb                 sethi   %hi(byte_F012EC30), %l2
F00C48CC: d04ca030                 ldsb    [%l2+%lo(byte_F012EC30)], %o0
F00C48D0: 80a22000                 cmp     %o0, 0
F00C48D4: 1280001b                 bne     locret_F00C4940
F00C48D8: 113c0506                 sethi   %hi(paNxlock), %o0
F00C48DC: e20222a0                 ld      [%o0+%lo(paNxlock)], %l1
F00C48E0: 113c0504                 sethi   %hi(paNew), %o0
F00C48E4: e0022238                 ld      [%o0+%lo(paNew)], %l0
F00C48E8: 90100011                 mov     %l1, %o0! id
F00C48EC: 4000b3e1                 call    _objc_msgSend
F00C48F0: 92100010                 mov     %l0, %o1
F00C48F4: 133c04cc                 sethi   %hi(dword_F013303C), %o1! SEL
F00C48F8: d022603c                 st      %o0, [%o1+%lo(dword_F013303C)]
F00C48FC: 113c04cc                 sethi   %hi(dword_F0133030), %o0
F00C4900: c0222030                 clr     [%o0+%lo(dword_F0133030)]
F00C4904: 133c04cc90126034         set     dword_F0133034, %o0
F00C490C: d0222004                 st      %o0, [%o0+4]
F00C4910: d0226034                 st      %o0, [%o1+%lo(dword_F0133034)]
F00C4914: 133c04cc90126044         set     dword_F0133044, %o0
F00C491C: d0222004                 st      %o0, [%o0+4]
F00C4920: d0226044                 st      %o0, [%o1+%lo(dword_F0133044)]
F00C4924: 90100011                 mov     %l1, %o0! id
F00C4928: 4000b3d2                 call    _objc_msgSend
F00C492C: 92100010                 mov     %l0, %o1
F00C4930: 133c04cc                 sethi   %hi(dword_F013304C), %o1
F00C4934: d022604c                 st      %o0, [%o1+%lo(dword_F013304C)]
F00C4938: 90102001                 mov     1, %o0
F00C493C: d02ca030                 stb     %o0, [%l2+0x30]
F00C4940: 81c7e008                 ret
F00C4944: 81e80000                 restore
