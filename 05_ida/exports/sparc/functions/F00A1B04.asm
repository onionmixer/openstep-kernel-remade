F00A1B04: 9de3bf90                 save    %sp, -0x70, %sp
F00A1B08: 133c04f792126270         set     _pmap_info, %o1
F00A1B10: d00260d8                 ld      [%o1+0xD8], %o0
F00A1B14: f227a048                 st      %i1, [%fp+arg_48]
F00A1B18: 90022001                 inc     %o0
F00A1B1C: d02260d8                 st      %o0, [%o1+0xD8]
F00A1B20: d00e200d                 ldub    [%i0+0xD], %o0
F00A1B24: 80a22003                 cmp     %o0, 3
F00A1B28: 12800006                 bne     loc_F00A1B40
F00A1B2C: 80a22002                 cmp     %o0, 2
F00A1B30: 9136600a                 srl     %i1, 10, %o0
F00A1B34: d2060000                 ld      [%i0], %o1
F00A1B38: 1080000a                 ba      loc_F00A1B60
F00A1B3C: 900a20fc                 and     %o0, 0xFC, %o0
F00A1B40: 32800006                 bne,a   loc_F00A1B58
F00A1B44: d00fa048                 ldub    [%fp+arg_48], %o0
F00A1B48: 91366010                 srl     %i1, 16, %o0
F00A1B4C: d2060000                 ld      [%i0], %o1
F00A1B50: 10800004                 ba      loc_F00A1B60
F00A1B54: 900a20fc                 and     %o0, 0xFC, %o0
F00A1B58: d2060000                 ld      [%i0], %o1
F00A1B5C: 912a2002                 sll     %o0, 2, %o0
F00A1B60: b2024008                 add     %o1, %o0, %i1
F00A1B64: d00e200f                 ldub    [%i0+0xF], %o0
F00A1B68: 90022001                 inc     %o0
F00A1B6C: d02e200f                 stb     %o0, [%i0+0xF]
F00A1B70: 9136a006                 srl     %i2, 6, %o0
F00A1B74: 912a2002                 sll     %o0, 2, %o0
F00A1B78: 90122001                 bset    1, %o0
F00A1B7C: d027bff4                 st      %o0, [%fp+var_C]
F00A1B80: d00e200d                 ldub    [%i0+0xD], %o0
F00A1B84: 80a22003                 cmp     %o0, 3
F00A1B88: 12800007                 bne     loc_F00A1BA4
F00A1B8C: 80a22002                 cmp     %o0, 2
F00A1B90: 113c04d0                 sethi   %hi(_page_mask), %o0
F00A1B94: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F00A1B98: d007a048                 ld      [%fp+arg_48], %o0
F00A1B9C: 10800008                 ba      loc_F00A1BBC
F00A1BA0: 922a0009                 andn    %o0, %o1, %o1
F00A1BA4: 12800004                 bne     loc_F00A1BB4
F00A1BA8: d207a048                 ld      [%fp+arg_48], %o1
F00A1BAC: 10800003                 ba      loc_F00A1BB8
F00A1BB0: 113fff00                 sethi   -0x40000, %o0
F00A1BB4: 113fc000                 sethi   -0x1000000, %o0
F00A1BB8: 920a4008                 and     %o1, %o0, %o1
F00A1BBC: d0062008                 ld      [%i0+8], %o0
F00A1BC0: 7ffffda4                 call    _get_context
F00A1BC4: d227a048                 st      %o1, [%fp+arg_48]
F00A1BC8: a0100008                 mov     %o0, %l0
F00A1BCC: 7ffff022                 call    _check_pmap
F00A1BD0: 90100018                 mov     %i0, %o0
F00A1BD4: d007bff4                 ld      [%fp+var_C], %o0
F00A1BD8: d407a048                 ld      [%fp+arg_48], %o2
F00A1BDC: 92100019                 mov     %i1, %o1
F00A1BE0: d60e200d                 ldub    [%i0+0xD], %o3
F00A1BE4: 7fffceed                 call    _mmu_writeptp
F00A1BE8: 98100010                 mov     %l0, %o4
F00A1BEC: 81c7e008                 ret
F00A1BF0: 81e80000                 restore
