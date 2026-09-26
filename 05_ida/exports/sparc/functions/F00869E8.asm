F00869E8: 9de3bf98                 save    %sp, -0x68, %sp
F00869EC: e2062020                 ld      [%i0+0x20], %l1
F00869F0: 80a46000                 cmp     %l1, 0
F00869F4: 02800016                 be      loc_F0086A4C
F00869F8: a0046010                 add     %l1, 0x10, %l0
F00869FC: d0040000                 ld      [%l0], %o0
F0086A00: 80a22000                 cmp     %o0, 0
F0086A04: 12bffffe                 bne     loc_F00869FC
F0086A08: 01000000                 nop
F0086A0C: 40004127                 call    _simple_lock_try
F0086A10: 90100010                 mov     %l0, %o0
F0086A14: 80a22000                 cmp     %o0, 0
F0086A18: 02bffff9                 be      loc_F00869FC
F0086A1C: 01000000                 nop
F0086A20: d004601c                 ld      [%l1+0x1C], %o0
F0086A24: 80a20018                 cmp     %o0, %i0
F0086A28: 12800004                 bne     loc_F0086A38
F0086A2C: 80a22000                 cmp     %o0, 0
F0086A30: 10800006                 ba      loc_F0086A48
F0086A34: c024601c                 clr     [%l1+0x1C]
F0086A38: 02800004                 be      loc_F0086A48
F0086A3C: 113c0446                 sethi   %hi(aVmObjectTermin), %o0! "vm_object_terminate: copy/shadow incons"...
F0086A40: 7ffe39cc                 call    _panic
F0086A44: 90122360                 bset    %lo(aVmObjectTermin), %o0! "vm_object_terminate: copy/shadow incons"...
F0086A48: c0246010                 clr     [%l1+0x10]
F0086A4C: d0162044                 lduh    [%i0+0x44], %o0
F0086A50: 80a22000                 cmp     %o0, 0
F0086A54: 02800013                 be      loc_F0086AA0
F0086A58: a0062010                 add     %i0, 0x10, %l0
F0086A5C: 90100018                 mov     %i0, %o0
F0086A60: 92100010                 mov     %l0, %o1
F0086A64: 7fffa9d6                 call    _thread_sleep
F0086A68: 94102000                 mov     0, %o2
F0086A6C: d0040000                 ld      [%l0], %o0
F0086A70: 80a22000                 cmp     %o0, 0
F0086A74: 12bffffe                 bne     loc_F0086A6C
F0086A78: 01000000                 nop
F0086A7C: 4000410b                 call    _simple_lock_try
F0086A80: 90100010                 mov     %l0, %o0
F0086A84: 80a22000                 cmp     %o0, 0
F0086A88: 02bffff9                 be      loc_F0086A6C
F0086A8C: 01000000                 nop
F0086A90: d0162044                 lduh    [%i0+0x44], %o0
F0086A94: 80a22000                 cmp     %o0, 0
F0086A98: 12bffff2                 bne     loc_F0086A60
F0086A9C: 90100018                 mov     %i0, %o0
F0086AA0: e0060000                 ld      [%i0], %l0
F0086AA4: 80a60010                 cmp     %i0, %l0
F0086AA8: 02800047                 be      loc_F0086BC4
F0086AAC: 113fffef                 sethi   -0x4400, %o0
F0086AB0: 333c04f0a4166230         set     _vm_page_queue_lock, %l2
F0086AB8: 2f3c04f3a815e008         set     _vm_page_queue_active, %l4
F0086AC0: b61223ff                 or      %o0, 0x3FF, %i3
F0086AC4: 2d3c04f2                 sethi   -0xFEC3800, %l6
F0086AC8: 2b3c04f0a6156228         set     _vm_page_queue_inactive, %l3
F0086AD0: 113fffdfb41223ff         set     -0x8001, %i2
F0086AD8: d0048000                 ld      [%l2], %o0
F0086ADC: 80a22000                 cmp     %o0, 0
F0086AE0: 12bffffe                 bne     loc_F0086AD8
F0086AE4: 01000000                 nop
F0086AE8: 400040f0                 call    _simple_lock_try
F0086AEC: 90100012                 mov     %l2, %o0
F0086AF0: 80a22000                 cmp     %o0, 0
F0086AF4: 02bffff9                 be      loc_F0086AD8
F0086AF8: 11000010                 sethi   0x4000, %o0
F0086AFC: d204201c                 ld      [%l0+0x1C], %o1
F0086B00: 808a4008                 btst    %o0, %o1
F0086B04: 02800012                 be      loc_F0086B4C
F0086B08: 11000020                 sethi   0x8000, %o0
F0086B0C: d0040000                 ld      [%l0], %o0
F0086B10: d2042004                 ld      [%l0+4], %o1
F0086B14: 80a24014                 cmp     %o1, %l4
F0086B18: 12800004                 bne     loc_F0086B28
F0086B1C: d2222004                 st      %o1, [%o0+4]
F0086B20: 10800003                 ba      loc_F0086B2C
F0086B24: d025e008                 st      %o0, [%l7+8]
F0086B28: d0224000                 st      %o0, [%o1]
F0086B2C: d004201c                 ld      [%l0+0x1C], %o0
F0086B30: d205a3f8                 ld      [%l6+0x3F8], %o1
F0086B34: 900a001b                 and     %o0, %i3, %o0
F0086B38: d024201c                 st      %o0, [%l0+0x1C]
F0086B3C: 92027fff                 inc     -1, %o1
F0086B40: d225a3f8                 st      %o1, [%l6+0x3F8]
F0086B44: d204201c                 ld      [%l0+0x1C], %o1
F0086B48: 11000020                 sethi   0x8000, %o0
F0086B4C: 808a4008                 btst    %o0, %o1
F0086B50: 22800012                 be,a    loc_F0086B98
F0086B54: d204201c                 ld      [%l0+0x1C], %o1
F0086B58: d0040000                 ld      [%l0], %o0
F0086B5C: d2042004                 ld      [%l0+4], %o1
F0086B60: 80a24013                 cmp     %o1, %l3
F0086B64: 12800004                 bne     loc_F0086B74
F0086B68: d2222004                 st      %o1, [%o0+4]
F0086B6C: 10800003                 ba      loc_F0086B78
F0086B70: d0256228                 st      %o0, [%l5+0x228]
F0086B74: d0224000                 st      %o0, [%o1]
F0086B78: d004201c                 ld      [%l0+0x1C], %o0
F0086B7C: 153c04f0                 sethi   %hi(_vm_page_inactive_count), %o2
F0086B80: d202a220                 ld      [%o2+%lo(_vm_page_inactive_count)], %o1
F0086B84: 900a001a                 and     %o0, %i2, %o0
F0086B88: d024201c                 st      %o0, [%l0+0x1C]
F0086B8C: 92027fff                 inc     -1, %o1
F0086B90: d222a220                 st      %o1, [%o2+%lo(_vm_page_inactive_count)]
F0086B94: d204201c                 ld      [%l0+0x1C], %o1
F0086B98: 11000004                 sethi   0x1000, %o0
F0086B9C: 808a4008                 btst    %o0, %o1
F0086BA0: 02800004                 be      loc_F0086BB0
F0086BA4: e2042008                 ld      [%l0+8], %l1
F0086BA8: 400009f4                 call    _vm_page_free
F0086BAC: 90100010                 mov     %l0, %o0
F0086BB0: c0266230                 clr     [%i1+0x230]
F0086BB4: a0100011                 mov     %l1, %l0
F0086BB8: 80a60010                 cmp     %i0, %l0
F0086BBC: 12bfffc7                 bne     loc_F0086AD8
F0086BC0: 01000000                 nop
F0086BC4: d0062028                 ld      [%i0+0x28], %o0
F0086BC8: c0262010                 clr     [%i0+0x10]
F0086BCC: 80a22000                 cmp     %o0, 0
F0086BD0: 22800005                 be,a    loc_F0086BE4
F0086BD4: d0162044                 lduh    [%i0+0x44], %o0
F0086BD8: 400005a7                 call    _vm_pager_deallocate
F0086BDC: 01000000                 nop
F0086BE0: d0162044                 lduh    [%i0+0x44], %o0
F0086BE4: 80a22000                 cmp     %o0, 0
F0086BE8: 02800004                 be      loc_F0086BF8
F0086BEC: 113c0446                 sethi   %hi(aVmObjectDeallo), %o0! "vm_object_deallocate: pageout in progre"...
F0086BF0: 7ffe3960                 call    _panic
F0086BF4: 90122390                 bset    %lo(aVmObjectDeallo), %o0! "vm_object_deallocate: pageout in progre"...
F0086BF8: d0060000                 ld      [%i0], %o0
F0086BFC: 80a60008                 cmp     %i0, %o0
F0086C00: 02800016                 be      loc_F0086C58
F0086C04: 113c04f6                 sethi   -0xFEC2800, %o0
F0086C08: 253c04f0a214a230         set     _vm_page_queue_lock, %l1
F0086C10: e0060000                 ld      [%i0], %l0
F0086C14: d0044000                 ld      [%l1], %o0
F0086C18: 80a22000                 cmp     %o0, 0
F0086C1C: 12bffffe                 bne     loc_F0086C14
F0086C20: 01000000                 nop
F0086C24: 400040a1                 call    _simple_lock_try
F0086C28: 90100011                 mov     %l1, %o0
F0086C2C: 80a22000                 cmp     %o0, 0
F0086C30: 02bffff9                 be      loc_F0086C14
F0086C34: 01000000                 nop
F0086C38: 400009d0                 call    _vm_page_free
F0086C3C: 90100010                 mov     %l0, %o0
F0086C40: c024a230                 clr     [%l2+0x230]
F0086C44: d0060000                 ld      [%i0], %o0
F0086C48: 80a60008                 cmp     %i0, %o0
F0086C4C: 32bffff2                 bne,a   loc_F0086C14
F0086C50: e0060000                 ld      [%i0], %l0
F0086C54: 113c04f6                 sethi   -0xFEC2800, %o0
F0086C58: a0122038                 or      %o0, 0x38, %l0
F0086C5C: d0040000                 ld      [%l0], %o0
F0086C60: 80a22000                 cmp     %o0, 0
F0086C64: 12bffffe                 bne     loc_F0086C5C
F0086C68: 01000000                 nop
F0086C6C: 4000408f                 call    _simple_lock_try
F0086C70: 90100010                 mov     %l0, %o0
F0086C74: 80a22000                 cmp     %o0, 0
F0086C78: 02bffff9                 be      loc_F0086C5C
F0086C7C: 113c04f6                 sethi   %hi(_vm_object_list), %o0
F0086C80: d4062008                 ld      [%i0+8], %o2
F0086C84: 90122030                 bset    %lo(_vm_object_list), %o0
F0086C88: 80a28008                 cmp     %o2, %o0
F0086C8C: 12800004                 bne     loc_F0086C9C
F0086C90: d206200c                 ld      [%i0+0xC], %o1
F0086C94: 10800003                 ba      loc_F0086CA0
F0086C98: d222a004                 st      %o1, [%o2+4]
F0086C9C: d222a00c                 st      %o1, [%o2+0xC]
F0086CA0: 173c04f69012e030         set     _vm_object_list, %o0
F0086CA8: 80a24008                 cmp     %o1, %o0
F0086CAC: 22800003                 be,a    loc_F0086CB8
F0086CB0: d422e030                 st      %o2, [%o3+0x30]
F0086CB4: d4226008                 st      %o2, [%o1+8]
F0086CB8: 113c04f6                 sethi   %hi(_vm_object_list_lock), %o0
F0086CBC: c0222038                 clr     [%o0+%lo(_vm_object_list_lock)]
F0086CC0: 92100018                 mov     %i0, %o1
F0086CC4: 173c04f5                 sethi   %hi(_vm_object_count), %o3
F0086CC8: d402e020                 ld      [%o3+%lo(_vm_object_count)], %o2
F0086CCC: 113c04f6                 sethi   %hi(_vm_object_zone), %o0
F0086CD0: d0022098                 ld      [%o0+%lo(_vm_object_zone)], %o0
F0086CD4: 9402bfff                 inc     -1, %o2
F0086CD8: 7fffc93e                 call    _zfree
F0086CDC: d422e020                 st      %o2, [%o3+%lo(_vm_object_count)]
F0086CE0: 81c7e008                 ret
F0086CE4: 81e80000                 restore
