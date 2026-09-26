F00C9AF4: 9de3bf90                 save    %sp, -0x70, %sp
F00C9AF8: d0062108                 ld      [%i0+0x108], %o0! id
F00C9AFC: 133c0506                 sethi   %hi(paNummemoryrange), %o1
F00C9B00: d20260b8                 ld      [%o1+%lo(paNummemoryrange)], %o1! SEL
F00C9B04: 40009f5b                 call    _objc_msgSend
F00C9B08: e406211c                 ld      [%i0+0x11C], %l2
F00C9B0C: 80a68008                 cmp     %i2, %o0
F00C9B10: 0a800004                 bcs     loc_F00C9B20
F00C9B14: 133c0504                 sethi   -0xFEBF000, %o1
F00C9B18: 10800043                 ba      locret_F00C9C24
F00C9B1C: b0103d3e                 mov     -0x2C2, %i0
F00C9B20: d0062114                 ld      [%i0+0x114], %o0! id
F00C9B24: 153c03eb                 sethi   %hi(aMemoryMaps), %o2! "Memory Maps"
F00C9B28: d2026124                 ld      [%o1+0x124], %o1! SEL
F00C9B2C: 40009f51                 call    _objc_msgSend
F00C9B30: 9412a3e8                 bset    %lo(aMemoryMaps), %o2! "Memory Maps"
F00C9B34: 133c0504                 sethi   %hi(paObjectat), %o1
F00C9B38: d20260c8                 ld      [%o1+%lo(paObjectat)], %o1! SEL
F00C9B3C: 40009f4d                 call    _objc_msgSend
F00C9B40: 9410001a                 mov     %i2, %o2
F00C9B44: 932f2018                 sll     %i4, 24, %o1
F00C9B48: 80a26000                 cmp     %o1, 0
F00C9B4C: 0280000c                 be      loc_F00C9B7C
F00C9B50: b0100008                 mov     %o0, %i0
F00C9B54: 113c0506                 sethi   %hi(paMapintargetCac), %o0
F00C9B58: 7ffea909                 call    _current_task_EXTERNAL
F00C9B5C: e00220b4                 ld      [%o0+%lo(paMapintargetCac)], %l0
F00C9B60: 94100008                 mov     %o0, %o2
F00C9B64: 90100018                 mov     %i0, %o0! id
F00C9B68: 92100010                 mov     %l0, %o1! SEL
F00C9B6C: 40009f41                 call    _objc_msgSend
F00C9B70: 9610001d                 mov     %i5, %o3
F00C9B74: 1080000d                 ba      loc_F00C9BA8
F00C9B78: a0100008                 mov     %o0, %l0
F00C9B7C: 113c0506                 sethi   %hi(paMaptoaddressIn), %o0
F00C9B80: e00220b0                 ld      [%o0+%lo(paMaptoaddressIn)], %l0
F00C9B84: 7ffea8fe                 call    _current_task_EXTERNAL
F00C9B88: e206c000                 ld      [%i3], %l1
F00C9B8C: 96100008                 mov     %o0, %o3
F00C9B90: 90100018                 mov     %i0, %o0! id
F00C9B94: 92100010                 mov     %l0, %o1! SEL
F00C9B98: 94100011                 mov     %l1, %o2
F00C9B9C: 40009f35                 call    _objc_msgSend
F00C9BA0: 9810001d                 mov     %i5, %o4
F00C9BA4: a0100008                 mov     %o0, %l0
F00C9BA8: 80a42000                 cmp     %l0, 0
F00C9BAC: 12800004                 bne     loc_F00C9BBC
F00C9BB0: 113c0506                 sethi   -0xFEBE800, %o0! id
F00C9BB4: 1080001c                 ba      locret_F00C9C24
F00C9BB8: b0103d43                 mov     -0x2BD, %i0
F00C9BBC: d20220ac                 ld      [%o0+0xAC], %o1! SEL
F00C9BC0: 40009f2c                 call    _objc_msgSend
F00C9BC4: 90100010                 mov     %l0, %o0
F00C9BC8: d026c000                 st      %o0, [%i3]
F00C9BCC: d0048000                 ld      [%l2], %o0
F00C9BD0: 80a22000                 cmp     %o0, 0
F00C9BD4: 3280000f                 bne,a   loc_F00C9C10
F00C9BD8: 133c0504                 sethi   -0xFEBF000, %o1
F00C9BDC: 113c0506                 sethi   %hi(paHashtable), %o0
F00C9BE0: d002227c                 ld      [%o0+%lo(paHashtable)], %o0! id
F00C9BE4: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00C9BE8: 40009f22                 call    _objc_msgSend
F00C9BEC: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00C9BF0: 133c0504                 sethi   %hi(paInitkeydesc), %o1
F00C9BF4: 153c03ec                 sethi   %hi(aI), %o2! "i"
F00C9BF8: d2026064                 ld      [%o1+%lo(paInitkeydesc)], %o1! SEL
F00C9BFC: 40009f1d                 call    _objc_msgSend
F00C9C00: 9412a030                 bset    %lo(aI), %o2! "i"
F00C9C04: d0248000                 st      %o0, [%l2]
F00C9C08: d0048000                 ld      [%l2], %o0! id
F00C9C0C: 133c0504                 sethi   -0xFEBF000, %o1
F00C9C10: d2026068                 ld      [%o1+0x68], %o1! SEL
F00C9C14: d406c000                 ld      [%i3], %o2
F00C9C18: 40009f16                 call    _objc_msgSend
F00C9C1C: 96100010                 mov     %l0, %o3
F00C9C20: b0102000                 mov     0, %i0
F00C9C24: 81c7e008                 ret
F00C9C28: 81e80000                 restore
