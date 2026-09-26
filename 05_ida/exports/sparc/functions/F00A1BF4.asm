F00A1BF4: 9de3bf90                 save    %sp, -0x70, %sp
F00A1BF8: 133c04f792126270         set     _pmap_info, %o1
F00A1C00: f227a048                 st      %i1, [%fp+arg_48]
F00A1C04: d00260dc                 ld      [%o1+0xDC], %o0
F00A1C08: a2100018                 mov     %i0, %l1
F00A1C0C: 90022001                 inc     %o0
F00A1C10: d02260dc                 st      %o0, [%o1+0xDC]
F00A1C14: d00c600d                 ldub    [%l1+0xD], %o0
F00A1C18: 80a22003                 cmp     %o0, 3
F00A1C1C: 12800006                 bne     loc_F00A1C34
F00A1C20: 80a22002                 cmp     %o0, 2
F00A1C24: 9136600a                 srl     %i1, 10, %o0
F00A1C28: d2044000                 ld      [%l1], %o1
F00A1C2C: 1080000a                 ba      loc_F00A1C54
F00A1C30: 900a20fc                 and     %o0, 0xFC, %o0
F00A1C34: 32800006                 bne,a   loc_F00A1C4C
F00A1C38: d00fa048                 ldub    [%fp+arg_48], %o0
F00A1C3C: 91366010                 srl     %i1, 16, %o0
F00A1C40: d2044000                 ld      [%l1], %o1
F00A1C44: 10800004                 ba      loc_F00A1C54
F00A1C48: 900a20fc                 and     %o0, 0xFC, %o0
F00A1C4C: d2044000                 ld      [%l1], %o1
F00A1C50: 912a2002                 sll     %o0, 2, %o0
F00A1C54: b2024008                 add     %o1, %o0, %i1
F00A1C58: d00e200f                 ldub    [%i0+0xF], %o0
F00A1C5C: 90023fff                 inc     -1, %o0
F00A1C60: d02e200f                 stb     %o0, [%i0+0xF]
F00A1C64: d00c600d                 ldub    [%l1+0xD], %o0
F00A1C68: 80a22003                 cmp     %o0, 3
F00A1C6C: 12800007                 bne     loc_F00A1C88
F00A1C70: 80a22002                 cmp     %o0, 2
F00A1C74: 113c04d0                 sethi   %hi(_page_mask), %o0
F00A1C78: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F00A1C7C: d007a048                 ld      [%fp+arg_48], %o0
F00A1C80: 10800008                 ba      loc_F00A1CA0
F00A1C84: 922a0009                 andn    %o0, %o1, %o1
F00A1C88: 12800004                 bne     loc_F00A1C98
F00A1C8C: d207a048                 ld      [%fp+arg_48], %o1
F00A1C90: 10800003                 ba      loc_F00A1C9C
F00A1C94: 113fff00                 sethi   -0x40000, %o0
F00A1C98: 113fc000                 sethi   -0x1000000, %o0
F00A1C9C: 920a4008                 and     %o1, %o0, %o1
F00A1CA0: d0046008                 ld      [%l1+8], %o0
F00A1CA4: 7ffffd6b                 call    _get_context
F00A1CA8: d227a048                 st      %o1, [%fp+arg_48]
F00A1CAC: a0100008                 mov     %o0, %l0
F00A1CB0: 7fffefe9                 call    _check_pmap
F00A1CB4: 90100011                 mov     %l1, %o0
F00A1CB8: c027bff4                 clr     [%fp+var_C]
F00A1CBC: 90102000                 mov     0, %o0
F00A1CC0: d407a048                 ld      [%fp+arg_48], %o2
F00A1CC4: 92100019                 mov     %i1, %o1
F00A1CC8: d60c600d                 ldub    [%l1+0xD], %o3
F00A1CCC: 7fffceb3                 call    _mmu_writeptp
F00A1CD0: 98100010                 mov     %l0, %o4
F00A1CD4: 81c7e008                 ret
F00A1CD8: 81e80000                 restore
