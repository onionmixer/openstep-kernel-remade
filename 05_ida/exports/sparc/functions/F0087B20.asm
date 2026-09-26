F0087B20: 9de3bf98                 save    %sp, -0x68, %sp
F0087B24: 40003c25                 call    _spltty
F0087B28: b0102000                 mov     0, %i0
F0087B2C: a4100008                 mov     %o0, %l2
F0087B30: 113c04f6a01220f8         set     _vm_page_queue_free_lock, %l0
F0087B38: d0040000                 ld      [%l0], %o0
F0087B3C: 80a22000                 cmp     %o0, 0
F0087B40: 12bffffe                 bne     loc_F0087B38
F0087B44: 01000000                 nop
F0087B48: 40003cd8                 call    _simple_lock_try
F0087B4C: 90100010                 mov     %l0, %o0
F0087B50: 80a22000                 cmp     %o0, 0
F0087B54: 02bffff9                 be      loc_F0087B38
F0087B58: 113c04f3                 sethi   %hi(_vm_page_free_count), %o0
F0087B5C: d2022000                 ld      [%o0+%lo(_vm_page_free_count)], %o1
F0087B60: 113c0447                 sethi   %hi(_vm_page_free_min), %o0
F0087B64: d0022144                 ld      [%o0+%lo(_vm_page_free_min)], %o0
F0087B68: 80a24008                 cmp     %o1, %o0
F0087B6C: 14800010                 bg      loc_F0087BAC
F0087B70: ae102000                 mov     0, %l7
F0087B74: ae102001                 mov     1, %l7
F0087B78: 113c04f6                 sethi   %hi(_vm_page_queue_free_lock), %o0
F0087B7C: c02220f8                 clr     [%o0+%lo(_vm_page_queue_free_lock)]
F0087B80: 40003c69                 call    _splx
F0087B84: 90100012                 mov     %l2, %o0
F0087B88: 40006000                 call    _pmap_update
F0087B8C: 01000000                 nop
F0087B90: 1080000c                 ba      loc_F0087BC0
F0087B94: 113c04f0                 sethi   -0xFEC4000, %o0
F0087B98: c02220f8                 clr     [%o0+0xF8]
F0087B9C: 40003c62                 call    _splx
F0087BA0: 90100012                 mov     %l2, %o0
F0087BA4: 108000e1                 ba      loc_F0087F28
F0087BA8: 113c0447                 sethi   -0xFEEE400, %o0
F0087BAC: 113c04f6                 sethi   %hi(_vm_page_queue_free_lock), %o0
F0087BB0: c02220f8                 clr     [%o0+%lo(_vm_page_queue_free_lock)]
F0087BB4: 40003c5c                 call    _splx
F0087BB8: 90100012                 mov     %l2, %o0
F0087BBC: 113c04f0                 sethi   -0xFEC4000, %o0
F0087BC0: a0122230                 or      %o0, 0x230, %l0
F0087BC4: d0040000                 ld      [%l0], %o0
F0087BC8: 80a22000                 cmp     %o0, 0
F0087BCC: 12bffffe                 bne     loc_F0087BC4
F0087BD0: 01000000                 nop
F0087BD4: 40003cb5                 call    _simple_lock_try
F0087BD8: 90100010                 mov     %l0, %o0
F0087BDC: 80a22000                 cmp     %o0, 0
F0087BE0: 02bffff9                 be      loc_F0087BC4
F0087BE4: 113c04f0                 sethi   %hi(_vm_page_queue_inactive), %o0
F0087BE8: 80a5e000                 cmp     %l7, 0
F0087BEC: 028000ce                 be      loc_F0087F24
F0087BF0: e2022228                 ld      [%o0+%lo(_vm_page_queue_inactive)], %l1
F0087BF4: 113c04f3b4122000         set     _vm_page_free_count, %i2
F0087BFC: 113c04f0ac122240         set     _vm_stat, %l6
F0087C04: 2b3c04f0                 sethi   -0xFEC4000, %l5
F0087C08: 111fffffa81223ff         set     0x7FFFFFFF, %l4
F0087C10: 112fffffb21223ff         set     -0x40000001, %i1
F0087C18: 113c04f0                 sethi   -0xFEC4000, %o0
F0087C1C: 90122228                 bset    0x228, %o0
F0087C20: 80a44008                 cmp     %l1, %o0
F0087C24: 028000c1                 be      loc_F0087F28
F0087C28: 113c0447                 sethi   -0xFEEE400, %o0
F0087C2C: 40003be3                 call    _spltty
F0087C30: 01000000                 nop
F0087C34: a4100008                 mov     %o0, %l2
F0087C38: 113c04f6a01220f8         set     _vm_page_queue_free_lock, %l0
F0087C40: d0040000                 ld      [%l0], %o0
F0087C44: 80a22000                 cmp     %o0, 0
F0087C48: 12bffffe                 bne     loc_F0087C40
F0087C4C: 01000000                 nop
F0087C50: 40003c96                 call    _simple_lock_try
F0087C54: 90100010                 mov     %l0, %o0
F0087C58: 80a22000                 cmp     %o0, 0
F0087C5C: 02bffff9                 be      loc_F0087C40
F0087C60: 113c04f3                 sethi   %hi(_vm_page_free_count), %o0
F0087C64: d2022000                 ld      [%o0+%lo(_vm_page_free_count)], %o1
F0087C68: 113c0447                 sethi   %hi(_vm_page_free_target), %o0
F0087C6C: d0022140                 ld      [%o0+%lo(_vm_page_free_target)], %o0
F0087C70: 80a24008                 cmp     %o1, %o0
F0087C74: 16bfffc9                 bge     loc_F0087B98
F0087C78: 113c04f6                 sethi   %hi(_vm_page_queue_free_lock), %o0
F0087C7C: c02220f8                 clr     [%o0+%lo(_vm_page_queue_free_lock)]
F0087C80: 40003c29                 call    _splx
F0087C84: 90100012                 mov     %l2, %o0
F0087C88: 40005e39                 call    _pmap_is_referenced
F0087C8C: d0046024                 ld      [%l1+0x24], %o0
F0087C90: 80a22000                 cmp     %o0, 0
F0087C94: 2280000a                 be,a    loc_F0087CBC
F0087C98: d204601c                 ld      [%l1+0x1C], %o1
F0087C9C: e0044000                 ld      [%l1], %l0
F0087CA0: 400006d1                 call    _vm_page_activate
F0087CA4: 90100011                 mov     %l1, %o0
F0087CA8: d005a018                 ld      [%l6+0x18], %o0
F0087CAC: a2100010                 mov     %l0, %l1
F0087CB0: 90022001                 inc     %o0
F0087CB4: 10800099                 ba      loc_F0087F18
F0087CB8: d025a018                 st      %o0, [%l6+0x18]
F0087CBC: 808a6400                 btst    0x400, %o1
F0087CC0: 0280002e                 be      loc_F0087D78
F0087CC4: 11000008                 sethi   0x2000, %o0
F0087CC8: e4046014                 ld      [%l1+0x14], %l2
F0087CCC: e0044000                 ld      [%l1], %l0
F0087CD0: 40003c76                 call    _simple_lock_try
F0087CD4: 9004a010                 add     %l2, 0x10, %o0
F0087CD8: 80a22000                 cmp     %o0, 0
F0087CDC: 32800004                 bne,a   loc_F0087CEC
F0087CE0: b0102001                 mov     1, %i0
F0087CE4: 1080008d                 ba      loc_F0087F18
F0087CE8: a2100010                 mov     %l0, %l1
F0087CEC: d0046020                 ld      [%l1+0x20], %o0
F0087CF0: 13200000                 sethi   0x80000000, %o1
F0087CF4: 90120009                 bset    %o1, %o0
F0087CF8: d0246020                 st      %o0, [%l1+0x20]
F0087CFC: c0256230                 clr     [%l5+0x230]
F0087D00: d0046024                 ld      [%l1+0x24], %o0
F0087D04: 400056bd                 call    _pmap_remove_all
F0087D08: a0156230                 or      %l5, 0x230, %l0
F0087D0C: d0040000                 ld      [%l0], %o0
F0087D10: 80a22000                 cmp     %o0, 0
F0087D14: 12bffffe                 bne     loc_F0087D0C
F0087D18: 01000000                 nop
F0087D1C: 40003c63                 call    _simple_lock_try
F0087D20: 90100010                 mov     %l0, %o0
F0087D24: 80a22000                 cmp     %o0, 0
F0087D28: 02bffff9                 be      loc_F0087D0C
F0087D2C: 01000000                 nop
F0087D30: d0046020                 ld      [%l1+0x20], %o0
F0087D34: 920a0014                 and     %o0, %l4, %o1
F0087D38: 11100000                 sethi   0x40000000, %o0
F0087D3C: 808a4008                 btst    %o0, %o1
F0087D40: 02800008                 be      loc_F0087D60
F0087D44: d2246020                 st      %o1, [%l1+0x20]
F0087D48: 900a4019                 and     %o1, %i1, %o0
F0087D4C: d0246020                 st      %o0, [%l1+0x20]
F0087D50: 90100011                 mov     %l1, %o0
F0087D54: 92102000                 mov     0, %o1
F0087D58: 7fffa4a9                 call    _thread_wakeup_prim
F0087D5C: 94102000                 mov     0, %o2
F0087D60: e0044000                 ld      [%l1], %l0
F0087D64: 40000591                 call    _vm_page_addfree
F0087D68: 90100011                 mov     %l1, %o0
F0087D6C: c024a010                 clr     [%l2+0x10]
F0087D70: 1080006a                 ba      loc_F0087F18
F0087D74: a2100010                 mov     %l0, %l1
F0087D78: 808a4008                 btst    %o0, %o1
F0087D7C: 22800067                 be,a    loc_F0087F18
F0087D80: e2044000                 ld      [%l1], %l1
F0087D84: e4046014                 ld      [%l1+0x14], %l2
F0087D88: 40003c48                 call    _simple_lock_try
F0087D8C: 9004a010                 add     %l2, 0x10, %o0
F0087D90: 80a22000                 cmp     %o0, 0
F0087D94: 02800060                 be      loc_F0087F14
F0087D98: 13200000                 sethi   0x80000000, %o1
F0087D9C: d0046020                 ld      [%l1+0x20], %o0
F0087DA0: 90120009                 bset    %o1, %o0
F0087DA4: d0246020                 st      %o0, [%l1+0x20]
F0087DA8: d005a020                 ld      [%l6+0x20], %o0
F0087DAC: c0256230                 clr     [%l5+0x230]
F0087DB0: 90022001                 inc     %o0
F0087DB4: d025a020                 st      %o0, [%l6+0x20]
F0087DB8: 40005690                 call    _pmap_remove_all
F0087DBC: d0046024                 ld      [%l1+0x24], %o0
F0087DC0: 7ffffe30                 call    _vm_object_collapse
F0087DC4: 90100012                 mov     %l2, %o0
F0087DC8: c024a010                 clr     [%l2+0x10]
F0087DCC: 9010001a                 mov     %i2, %o0
F0087DD0: 92102000                 mov     0, %o1
F0087DD4: d614a044                 lduh    [%l2+0x44], %o3
F0087DD8: 94102000                 mov     0, %o2
F0087DDC: 9602e001                 inc     %o3
F0087DE0: 7fffa487                 call    _thread_wakeup_prim
F0087DE4: d634a044                 sth     %o3, [%l2+0x44]
F0087DE8: e004a028                 ld      [%l2+0x28], %l0
F0087DEC: 80a42000                 cmp     %l0, 0
F0087DF0: 1280000c                 bne     loc_F0087E20
F0087DF4: b0102001                 mov     1, %i0
F0087DF8: 40000131                 call    _vm_pager_allocate
F0087DFC: d004a014                 ld      [%l2+0x14], %o0
F0087E00: a0920000                 orcc    %o0, %g0, %l0
F0087E04: 02800007                 be      loc_F0087E20
F0087E08: 90100012                 mov     %l2, %o0
F0087E0C: 92100010                 mov     %l0, %o1
F0087E10: 94102000                 mov     0, %o2
F0087E14: 7ffffd41                 call    _vm_object_setpager
F0087E18: 96102000                 mov     0, %o3
F0087E1C: 80a42000                 cmp     %l0, 0
F0087E20: 02800007                 be      loc_F0087E3C
F0087E24: a6102000                 mov     0, %l3
F0087E28: 90100010                 mov     %l0, %o0
F0087E2C: 40000100                 call    _vm_pager_put
F0087E30: 92100011                 mov     %l1, %o1
F0087E34: 80a00008                 cmp     %g0, %o0
F0087E38: a6603fff                 subc    %g0, -1, %l3
F0087E3C: a004a010                 add     %l2, 0x10, %l0
F0087E40: d0040000                 ld      [%l0], %o0
F0087E44: 80a22000                 cmp     %o0, 0
F0087E48: 12bffffe                 bne     loc_F0087E40
F0087E4C: 01000000                 nop
F0087E50: 40003c16                 call    _simple_lock_try
F0087E54: 90100010                 mov     %l0, %o0
F0087E58: 80a22000                 cmp     %o0, 0
F0087E5C: 02bffff9                 be      loc_F0087E40
F0087E60: 01000000                 nop
F0087E64: a0156230                 or      %l5, 0x230, %l0
F0087E68: d0040000                 ld      [%l0], %o0
F0087E6C: 80a22000                 cmp     %o0, 0
F0087E70: 12bffffe                 bne     loc_F0087E68
F0087E74: 01000000                 nop
F0087E78: 40003c0c                 call    _simple_lock_try
F0087E7C: 90100010                 mov     %l0, %o0
F0087E80: 80a22000                 cmp     %o0, 0
F0087E84: 02bffff9                 be      loc_F0087E68
F0087E88: 80a4e000                 cmp     %l3, 0
F0087E8C: 02800007                 be      loc_F0087EA8
F0087E90: e0044000                 ld      [%l1], %l0
F0087E94: d204601c                 ld      [%l1+0x1C], %o1
F0087E98: 11000008                 sethi   0x2000, %o0
F0087E9C: 902a4008                 andn    %o1, %o0, %o0
F0087EA0: 10800004                 ba      loc_F0087EB0
F0087EA4: d024601c                 st      %o0, [%l1+0x1C]
F0087EA8: 4000064f                 call    _vm_page_activate
F0087EAC: 90100011                 mov     %l1, %o0
F0087EB0: 40005da0                 call    _pmap_clear_reference
F0087EB4: d0046024                 ld      [%l1+0x24], %o0
F0087EB8: d0046020                 ld      [%l1+0x20], %o0
F0087EBC: 920a0014                 and     %o0, %l4, %o1
F0087EC0: 11100000                 sethi   0x40000000, %o0
F0087EC4: 808a4008                 btst    %o0, %o1
F0087EC8: 02800008                 be      loc_F0087EE8
F0087ECC: d2246020                 st      %o1, [%l1+0x20]
F0087ED0: 900a4019                 and     %o1, %i1, %o0
F0087ED4: d0246020                 st      %o0, [%l1+0x20]
F0087ED8: 90100011                 mov     %l1, %o0
F0087EDC: 92102000                 mov     0, %o1
F0087EE0: 7fffa447                 call    _thread_wakeup_prim
F0087EE4: 94102000                 mov     0, %o2
F0087EE8: 90100012                 mov     %l2, %o0
F0087EEC: 92102000                 mov     0, %o1
F0087EF0: 94102000                 mov     0, %o2
F0087EF4: d614a044                 lduh    [%l2+0x44], %o3
F0087EF8: a2100010                 mov     %l0, %l1
F0087EFC: 9602ffff                 inc     -1, %o3
F0087F00: 7fffa43f                 call    _thread_wakeup_prim
F0087F04: d634a044                 sth     %o3, [%l2+0x44]
F0087F08: c024a010                 clr     [%l2+0x10]
F0087F0C: 10800004                 ba      loc_F0087F1C
F0087F10: 80a5e000                 cmp     %l7, 0
F0087F14: e2044000                 ld      [%l1], %l1
F0087F18: 80a5e000                 cmp     %l7, 0
F0087F1C: 12bfff40                 bne     loc_F0087C1C
F0087F20: 113c04f0                 sethi   -0xFEC4000, %o0
F0087F24: 113c0447                 sethi   -0xFEEE400, %o0
F0087F28: d4022148                 ld      [%o0+0x148], %o2
F0087F2C: 113c04f0                 sethi   %hi(_vm_page_inactive_count), %o0
F0087F30: d2022220                 ld      [%o0+%lo(_vm_page_inactive_count)], %o1
F0087F34: 113c04f3                 sethi   %hi(_vm_page_free_count), %o0
F0087F38: d0022000                 ld      [%o0+%lo(_vm_page_free_count)], %o0
F0087F3C: a0228009                 sub     %o2, %o1, %l0
F0087F40: a0240008                 sub     %l0, %o0, %l0
F0087F44: 80a42000                 cmp     %l0, 0
F0087F48: 0480000f                 ble     loc_F0087F84
F0087F4C: 113c04f0                 sethi   -0xFEC4000, %o0
F0087F50: 233c04f3a4146008         set     _vm_page_queue_active, %l2
F0087F58: d0046008                 ld      [%l1+8], %o0
F0087F5C: 80a20012                 cmp     %o0, %l2
F0087F60: 22800009                 be,a    loc_F0087F84
F0087F64: 113c04f0                 sethi   -0xFEC4000, %o0
F0087F68: 400005dd                 call    _vm_page_deactivate
F0087F6C: b0102001                 mov     1, %i0
F0087F70: a0043fff                 inc     -1, %l0
F0087F74: 80a42000                 cmp     %l0, 0
F0087F78: 14bffff9                 bg      loc_F0087F5C
F0087F7C: d0046008                 ld      [%l1+8], %o0
F0087F80: 113c04f0                 sethi   -0xFEC4000, %o0
F0087F84: c0222230                 clr     [%o0+0x230]
F0087F88: 81c7e008                 ret
F0087F8C: 81e80000                 restore
