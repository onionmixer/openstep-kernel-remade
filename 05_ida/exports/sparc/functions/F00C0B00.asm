F00C0B00: 9de3bf78                 save    %sp, -0x88, %sp
F00C0B04: 113c0503                 sethi   %hi(paAlloc), %o0! id
F00C0B08: d20223f0                 ld      [%o0+%lo(paAlloc)], %o1! SEL
F00C0B0C: 4000c359                 call    _objc_msgSend
F00C0B10: 90100018                 mov     %i0, %o0! id
F00C0B14: 133c0504                 sethi   %hi(paInitfromdevice), %o1
F00C0B18: d20262fc                 ld      [%o1+%lo(paInitfromdevice)], %o1! SEL
F00C0B1C: 4000c355                 call    _objc_msgSend
F00C0B20: 9410001a                 mov     %i2, %o2
F00C0B24: b0100008                 mov     %o0, %i0
F00C0B28: c0262128                 clr     [%i0+0x128]
F00C0B2C: 133c0504                 sethi   %hi(paMouseinit), %o1
F00C0B30: d2026300                 ld      [%o1+%lo(paMouseinit)], %o1! SEL
F00C0B34: 4000c34f                 call    _objc_msgSend
F00C0B38: 9410001a                 mov     %i2, %o2
F00C0B3C: 912a2018                 sll     %o0, 24, %o0
F00C0B40: 80a22000                 cmp     %o0, 0
F00C0B44: 0280001c                 be      loc_F00C0BB4
F00C0B48: a207bfd8                 add     %fp, var_28, %l1
F00C0B4C: 90100011                 mov     %l1, %o0! char *
F00C0B50: 213c04cb                 sethi   %hi(dword_F0132F7C), %l0
F00C0B54: 133c0483                 sethi   %hi(aPcpointerD), %o1! "PCPointer%d"
F00C0B58: d404237c                 ld      [%l0+%lo(dword_F0132F7C)], %o2
F00C0B5C: 7ffd4f03                 call    _sprintf
F00C0B60: 92126210                 bset    %lo(aPcpointerD), %o1! "PCPointer%d"
F00C0B64: 90100018                 mov     %i0, %o0! id
F00C0B68: d404237c                 ld      [%l0+%lo(dword_F0132F7C)], %o2
F00C0B6C: 133c0504                 sethi   %hi(paSetunit), %o1
F00C0B70: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00C0B74: 9602a001                 add     %o2, 1, %o3
F00C0B78: 4000c33e                 call    _objc_msgSend
F00C0B7C: d624237c                 st      %o3, [%l0+%lo(dword_F0132F7C)]
F00C0B80: 90100018                 mov     %i0, %o0! id
F00C0B84: 133c0504                 sethi   %hi(paSetname), %o1
F00C0B88: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00C0B8C: 4000c339                 call    _objc_msgSend
F00C0B90: 94100011                 mov     %l1, %o2
F00C0B94: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00C0B98: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00C0B9C: 4000c335                 call    _objc_msgSend
F00C0BA0: 90100018                 mov     %i0, %o0
F00C0BA4: 113c04cb                 sethi   %hi(dword_F0132F80), %o0
F00C0BA8: f0222380                 st      %i0, [%o0+%lo(dword_F0132F80)]
F00C0BAC: 1080000a                 ba      locret_F00C0BD4
F00C0BB0: b0102001                 mov     1, %i0
F00C0BB4: 113c0483                 sethi   %hi(aPcpointerProbe), %o0! "PCPointer probe: mouseInit failure\n"
F00C0BB8: 4000154f                 call    _IOLog
F00C0BBC: 901221e8                 bset    %lo(aPcpointerProbe), %o0! "PCPointer probe: mouseInit failure\n"
F00C0BC0: 113c0503                 sethi   %hi(paFree), %o0! id
F00C0BC4: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C0BC8: 4000c32a                 call    _objc_msgSend
F00C0BCC: 90100018                 mov     %i0, %o0
F00C0BD0: b0102000                 mov     0, %i0
F00C0BD4: 81c7e008                 ret
F00C0BD8: 81e80000                 restore
