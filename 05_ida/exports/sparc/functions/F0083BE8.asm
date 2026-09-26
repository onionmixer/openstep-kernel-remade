F0083BE8: 9de3bf90                 save    %sp, -0x70, %sp
F0083BEC: 113c04d1                 sethi   %hi(_mb_map), %o0
F0083BF0: d0022380                 ld      [%o0+%lo(_mb_map)], %o0
F0083BF4: 80a60008                 cmp     %i0, %o0
F0083BF8: 22800006                 be,a    loc_F0083C10
F0083BFC: 113c04d0                 sethi   -0xFECC000, %o0
F0083C00: 113c0446                 sethi   %hi(aYouFool), %o0! "You fool!"
F0083C04: 7ffe455b                 call    _panic
F0083C08: 901221f0                 bset    %lo(aYouFool), %o0! "You fool!"
F0083C0C: 113c04d0                 sethi   -0xFECC000, %o0
F0083C10: d20220d8                 ld      [%o0+0xD8], %o1
F0083C14: 90064009                 add     %i1, %o1, %o0
F0083C18: b22a0009                 andn    %o0, %o1, %i1
F0083C1C: 7fff946a                 call    _lock_write
F0083C20: 90100018                 mov     %i0, %o0
F0083C24: d006204c                 ld      [%i0+0x4C], %o0
F0083C28: 90022001                 inc     %o0
F0083C2C: d026204c                 st      %o0, [%i0+0x4C]
F0083C30: e6062010                 ld      [%i0+0x10], %l3
F0083C34: 9006200c                 add     %i0, 0xC, %o0
F0083C38: 80a4c008                 cmp     %l3, %o0
F0083C3C: 32800018                 bne,a   loc_F0083C9C
F0083C40: d006200c                 ld      [%i0+0xC], %o0
F0083C44: 7fff94fc                 call    _lock_done
F0083C48: 90100018                 mov     %i0, %o0
F0083C4C: 90100018                 mov     %i0, %o0
F0083C50: 92102000                 mov     0, %o1
F0083C54: 94102000                 mov     0, %o2
F0083C58: 9607bff4                 add     %fp, var_C, %o3
F0083C5C: da062014                 ld      [%i0+0x14], %o5
F0083C60: 98100019                 mov     %i1, %o4
F0083C64: da27bff4                 st      %o5, [%fp+var_C]
F0083C68: 4000025a                 call    _vm_map_find
F0083C6C: 9a102001                 mov     1, %o5
F0083C70: 80a22000                 cmp     %o0, 0
F0083C74: 02800004                 be      loc_F0083C84
F0083C78: 90100018                 mov     %i0, %o0
F0083C7C: 10800090                 ba      locret_F0083EBC
F0083C80: b0102000                 mov     0, %i0
F0083C84: d207bff4                 ld      [%fp+var_C], %o1
F0083C88: 96102000                 mov     0, %o3
F0083C8C: 40000458                 call    _vm_map_pageable
F0083C90: 94024019                 add     %o1, %i1, %o2
F0083C94: 1080008a                 ba      locret_F0083EBC
F0083C98: f007bff4                 ld      [%fp+var_C], %i0
F0083C9C: 80a4c008                 cmp     %l3, %o0
F0083CA0: 1280001c                 bne     loc_F0083D10
F0083CA4: 113c0446                 sethi   -0xFEEE800, %o0
F0083CA8: d004e018                 ld      [%l3+0x18], %o0
F0083CAC: 80a22000                 cmp     %o0, 0
F0083CB0: 06800018                 bl      loc_F0083D10
F0083CB4: 113c0446                 sethi   -0xFEEE800, %o0
F0083CB8: d204e008                 ld      [%l3+8], %o1
F0083CBC: d0062014                 ld      [%i0+0x14], %o0
F0083CC0: 80a24008                 cmp     %o1, %o0
F0083CC4: 12800013                 bne     loc_F0083D10
F0083CC8: 113c0446                 sethi   -0xFEEE800, %o0
F0083CCC: d004e020                 ld      [%l3+0x20], %o0
F0083CD0: 80a22007                 cmp     %o0, 7
F0083CD4: 1280000f                 bne     loc_F0083D10
F0083CD8: 113c0446                 sethi   -0xFEEE800, %o0
F0083CDC: d004e01c                 ld      [%l3+0x1C], %o0
F0083CE0: 80a22003                 cmp     %o0, 3
F0083CE4: 1280000b                 bne     loc_F0083D10
F0083CE8: 113c0446                 sethi   -0xFEEE800, %o0
F0083CEC: d004e024                 ld      [%l3+0x24], %o0
F0083CF0: 80a22001                 cmp     %o0, 1
F0083CF4: 12800007                 bne     loc_F0083D10
F0083CF8: 113c0446                 sethi   -0xFEEE800, %o0
F0083CFC: d014e028                 lduh    [%l3+0x28], %o0
F0083D00: 80a22000                 cmp     %o0, 0
F0083D04: 32800006                 bne,a   loc_F0083D1C
F0083D08: d0062018                 ld      [%i0+0x18], %o0
F0083D0C: 113c0446                 sethi   -0xFEEE800, %o0! char *
F0083D10: 7ffe4518                 call    _panic
F0083D14: 90122200                 bset    0x200, %o0
F0083D18: d0062018                 ld      [%i0+0x18], %o0
F0083D1C: d204e00c                 ld      [%l3+0xC], %o1
F0083D20: 90220019                 sub     %o0, %i1, %o0
F0083D24: 80a20009                 cmp     %o0, %o1
F0083D28: 0a800034                 bcs     loc_F0083DF8
F0083D2C: 90100018                 mov     %i0, %o0
F0083D30: d004e008                 ld      [%l3+8], %o0
F0083D34: d404e014                 ld      [%l3+0x14], %o2
F0083D38: d227bff4                 st      %o1, [%fp+var_C]
F0083D3C: e804e010                 ld      [%l3+0x10], %l4
F0083D40: 90224008                 sub     %o1, %o0, %o0
F0083D44: aa02000a                 add     %o0, %o2, %l5
F0083D48: d204e00c                 ld      [%l3+0xC], %o1
F0083D4C: a0052010                 add     %l4, 0x10, %l0
F0083D50: 92024019                 add     %o1, %i1, %o1
F0083D54: d224e00c                 st      %o1, [%l3+0xC]
F0083D58: d0040000                 ld      [%l0], %o0
F0083D5C: 80a22000                 cmp     %o0, 0
F0083D60: 12bffffe                 bne     loc_F0083D58
F0083D64: 01000000                 nop
F0083D68: 40004c50                 call    _simple_lock_try
F0083D6C: 90100010                 mov     %l0, %o0
F0083D70: 80a22000                 cmp     %o0, 0
F0083D74: 02bffff9                 be      loc_F0083D58
F0083D78: 113c04f4                 sethi   %hi(_page_shift), %o0
F0083D7C: d0022348                 ld      [%o0+%lo(_page_shift)], %o0
F0083D80: a5364008                 srl     %i1, %o0, %l2
F0083D84: 80a4a000                 cmp     %l2, 0
F0083D88: 02800028                 be      loc_F0083E28
F0083D8C: a2100015                 mov     %l5, %l1
F0083D90: 2d3c0447                 sethi   -0xFEEE400, %l6
F0083D94: 111fffffae1223ff         set     0x7FFFFFFF, %l7
F0083D9C: 90100014                 mov     %l4, %o0
F0083DA0: 92100011                 mov     %l1, %o1
F0083DA4: 400014e2                 call    _vm_page_alloc_sequential
F0083DA8: 94102000                 mov     0, %o2
F0083DAC: a0920000                 orcc    %o0, %g0, %l0
F0083DB0: 12800015                 bne     loc_F0083E04
F0083DB4: 80a44015                 cmp     %l1, %l5
F0083DB8: 0880000b                 bleu    loc_F0083DE4
F0083DBC: d205a13c                 ld      [%l6+0x13C], %o1
F0083DC0: 90100014                 mov     %l4, %o0
F0083DC4: a2244009                 sub     %l1, %o1, %l1
F0083DC8: 40001474                 call    _vm_page_lookup
F0083DCC: 92100011                 mov     %l1, %o1
F0083DD0: 4000156a                 call    _vm_page_free
F0083DD4: 01000000                 nop
F0083DD8: 80a44015                 cmp     %l1, %l5
F0083DDC: 18bffff9                 bgu     loc_F0083DC0
F0083DE0: d205a13c                 ld      [%l6+0x13C], %o1
F0083DE4: c0252010                 clr     [%l4+0x10]
F0083DE8: d204e00c                 ld      [%l3+0xC], %o1
F0083DEC: 90100018                 mov     %i0, %o0
F0083DF0: 92224019                 sub     %o1, %i1, %o1
F0083DF4: d224e00c                 st      %o1, [%l3+0xC]
F0083DF8: 7fff948f                 call    _lock_done
F0083DFC: b0102000                 mov     0, %i0
F0083E00: 3080002f                 ba,a    locret_F0083EBC
F0083E04: 400016c6                 call    _vm_page_zero_fill
F0083E08: 90100010                 mov     %l0, %o0
F0083E0C: d0042020                 ld      [%l0+0x20], %o0
F0083E10: a484bfff                 inccc   -1, %l2
F0083E14: d205a13c                 ld      [%l6+0x13C], %o1
F0083E18: 900a0017                 and     %o0, %l7, %o0
F0083E1C: d0242020                 st      %o0, [%l0+0x20]
F0083E20: 12bfffdf                 bne     loc_F0083D9C
F0083E24: a2044009                 add     %l1, %o1, %l1
F0083E28: f207bff4                 ld      [%fp+var_C], %i1
F0083E2C: c0252010                 clr     [%l4+0x10]
F0083E30: d004e00c                 ld      [%l3+0xC], %o0
F0083E34: 80a64008                 cmp     %i1, %o0
F0083E38: 1a80001e                 bcc     loc_F0083EB0
F0083E3C: a2100015                 mov     %l5, %l1
F0083E40: a4052010                 add     %l4, 0x10, %l2
F0083E44: 2b3c0447                 sethi   -0xFEEE400, %l5
F0083E48: d0048000                 ld      [%l2], %o0
F0083E4C: 80a22000                 cmp     %o0, 0
F0083E50: 12bffffe                 bne     loc_F0083E48
F0083E54: 01000000                 nop
F0083E58: 40004c14                 call    _simple_lock_try
F0083E5C: 90100012                 mov     %l2, %o0
F0083E60: 80a22000                 cmp     %o0, 0
F0083E64: 02bffff9                 be      loc_F0083E48
F0083E68: 90100014                 mov     %l4, %o0
F0083E6C: 4000144b                 call    _vm_page_lookup
F0083E70: 92100011                 mov     %l1, %o1
F0083E74: 400015a7                 call    _vm_page_wire
F0083E78: a0100008                 mov     %o0, %l0
F0083E7C: c0252010                 clr     [%l4+0x10]
F0083E80: d0062024                 ld      [%i0+0x24], %o0
F0083E84: d4042024                 ld      [%l0+0x24], %o2
F0083E88: 92100019                 mov     %i1, %o1
F0083E8C: d604e01c                 ld      [%l3+0x1C], %o3
F0083E90: 40006987                 call    _pmap_enter
F0083E94: 98102001                 mov     1, %o4
F0083E98: d005613c                 ld      [%l5+0x13C], %o0
F0083E9C: d204e00c                 ld      [%l3+0xC], %o1
F0083EA0: b2064008                 add     %i1, %o0, %i1
F0083EA4: 80a64009                 cmp     %i1, %o1
F0083EA8: 0abfffe8                 bcs     loc_F0083E48
F0083EAC: a2044008                 add     %l1, %o0, %l1
F0083EB0: 7fff9461                 call    _lock_done
F0083EB4: 90100018                 mov     %i0, %o0
F0083EB8: f007bff4                 ld      [%fp+var_C], %i0
F0083EBC: 81c7e008                 ret
F0083EC0: 81e80000                 restore
