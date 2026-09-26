F00A4BF4: 9de3bf90                 save    %sp, -0x70, %sp
F00A4BF8: 250003c0                 sethi   0xF0000, %l2
F00A4BFC: 113bffffaa1223ff         set     -0x10000001, %l5
F00A4C04: 110003ffac1223fe         set     0xFFFFE, %l6
F00A4C0C: a12ca00c                 sll     %l2, 12, %l0
F00A4C10: 90100010                 mov     %l0, %o0
F00A4C14: 7fffc27e                 call    _mmu_probe
F00A4C18: 92102000                 mov     0, %o1
F00A4C1C: a6920000                 orcc    %o0, %g0, %l3
F00A4C20: 22800030                 be,a    loc_F00A4CE0
F00A4C24: a404a001                 inc     %l2
F00A4C28: 900ce003                 and     %l3, 3, %o0
F00A4C2C: 80a22002                 cmp     %o0, 2
F00A4C30: 3280002c                 bne,a   loc_F00A4CE0
F00A4C34: a404a001                 inc     %l2
F00A4C38: a8102007                 mov     7, %l4
F00A4C3C: a334e007                 srl     %l3, 7, %l1
F00A4C40: 80a40015                 cmp     %l0, %l5
F00A4C44: 08800008                 bleu    loc_F00A4C64
F00A4C48: a20c6001                 and     %l1, 1, %l1
F00A4C4C: 113c04f6                 sethi   %hi(_etext), %o0
F00A4C50: d00221e0                 ld      [%o0+%lo(_etext)], %o0
F00A4C54: 80a40008                 cmp     %l0, %o0
F00A4C58: 28800002                 bleu,a  loc_F00A4C60
F00A4C5C: a8102005                 mov     5, %l4
F00A4C60: 80a40015                 cmp     %l0, %l5
F00A4C64: 08800009                 bleu    loc_F00A4C88
F00A4C68: 113c04f4                 sethi   %hi(_econtig), %o0
F00A4C6C: d0022390                 ld      [%o0+%lo(_econtig)], %o0
F00A4C70: 80a40008                 cmp     %l0, %o0
F00A4C74: 18800006                 bgu     loc_F00A4C8C
F00A4C78: 90100010                 mov     %l0, %o0
F00A4C7C: 7fffffbe                 call    _is_cacheable
F00A4C80: 90100010                 mov     %l0, %o0
F00A4C84: a2100008                 mov     %o0, %l1
F00A4C88: 90100010                 mov     %l0, %o0
F00A4C8C: a134e008                 srl     %l3, 8, %l0
F00A4C90: 932c200c                 sll     %l0, 12, %o1
F00A4C94: 95342014                 srl     %l0, 20, %o2
F00A4C98: 17000004                 sethi   0x1000, %o3
F00A4C9C: 98100014                 mov     %l4, %o4
F00A4CA0: 7fffdd9c                 call    _pmap_map
F00A4CA4: 9a100011                 mov     %l1, %o5
F00A4CA8: 113c045d                 sethi   %hi(_viking), %o0
F00A4CAC: d00222d0                 ld      [%o0+%lo(_viking)], %o0
F00A4CB0: 80a22000                 cmp     %o0, 0
F00A4CB4: 2280000b                 be,a    loc_F00A4CE0
F00A4CB8: a404a001                 inc     %l2
F00A4CBC: 808ce080                 btst    0x80, %l3
F00A4CC0: 22800008                 be,a    loc_F00A4CE0
F00A4CC4: a404a001                 inc     %l2
F00A4CC8: 80a46000                 cmp     %l1, 0
F00A4CCC: 32800005                 bne,a   loc_F00A4CE0
F00A4CD0: a404a001                 inc     %l2
F00A4CD4: 7fffc350                 call    _pac_pageflush
F00A4CD8: 90100010                 mov     %l0, %o0
F00A4CDC: a404a001                 inc     %l2
F00A4CE0: 80a48016                 cmp     %l2, %l6
F00A4CE4: 08bfffcb                 bleu    loc_F00A4C10
F00A4CE8: a12ca00c                 sll     %l2, 12, %l0
F00A4CEC: 250003c0                 sethi   0xF0000, %l2
F00A4CF0: 293c04f8                 sethi   -0xFEC2000, %l4
F00A4CF4: 273c04f0                 sethi   -0xFEC4000, %l3
F00A4CF8: 23000004                 sethi   0x1000, %l1
F00A4CFC: 110003ffa01223ff         set     0xFFFFF, %l0
F00A4D04: 952ca00c                 sll     %l2, 12, %o2
F00A4D08: d427bff4                 st      %o2, [%fp+var_C]
F00A4D0C: d00fbff4                 ldub    [%fp+var_C], %o0
F00A4D10: d20520c8                 ld      [%l4+0xC8], %o1
F00A4D14: 912a2002                 sll     %o0, 2, %o0
F00A4D18: d0024008                 ld      [%o1+%o0], %o0
F00A4D1C: 80a22000                 cmp     %o0, 0
F00A4D20: 32800007                 bne,a   loc_F00A4D3C
F00A4D24: a4048011                 add     %l2, %l1, %l2
F00A4D28: d004e100                 ld      [%l3+0x100], %o0
F00A4D2C: 9210000a                 mov     %o2, %o1
F00A4D30: 7fffe3d2                 call    _pmap_expand
F00A4D34: 94102002                 mov     2, %o2
F00A4D38: a4048011                 add     %l2, %l1, %l2
F00A4D3C: 80a48010                 cmp     %l2, %l0
F00A4D40: 08bffff2                 bleu    loc_F00A4D08
F00A4D44: 952ca00c                 sll     %l2, 12, %o2
F00A4D48: a4102000                 mov     0, %l2
F00A4D4C: 113c04f6                 sethi   %hi(_contexts), %o0
F00A4D50: d40221d8                 ld      [%o0+%lo(_contexts)], %o2
F00A4D54: 173c0464                 sethi   %hi(_nctxs), %o3
F00A4D58: d202e310                 ld      [%o3+%lo(_nctxs)], %o1
F00A4D5C: 113c04f8                 sethi   %hi(_Nl1ptbl_addr), %o0
F00A4D60: d0022160                 ld      [%o0+%lo(_Nl1ptbl_addr)], %o0
F00A4D64: 80a48009                 cmp     %l2, %o1
F00A4D68: 91322006                 srl     %o0, 6, %o0
F00A4D6C: 912a2002                 sll     %o0, 2, %o0
F00A4D70: 1a800008                 bcc     loc_F00A4D90
F00A4D74: 92122001                 or      %o0, 1, %o1
F00A4D78: d2228000                 st      %o1, [%o2]
F00A4D7C: d002e310                 ld      [%o3+0x310], %o0
F00A4D80: a404a001                 inc     %l2
F00A4D84: 80a48008                 cmp     %l2, %o0
F00A4D88: 0abffffc                 bcs     loc_F00A4D78
F00A4D8C: 9402a004                 inc     4, %o2
F00A4D90: 113c0464                 sethi   %hi(_vac), %o0
F00A4D94: d0022334                 ld      [%o0+%lo(_vac)], %o0
F00A4D98: 80a22000                 cmp     %o0, 0
F00A4D9C: 02800007                 be      loc_F00A4DB8
F00A4DA0: 133c04f4                 sethi   %hi(_econtig), %o1
F00A4DA4: 113c04f6                 sethi   %hi(_contexts), %o0
F00A4DA8: d00221d8                 ld      [%o0+%lo(_contexts)], %o0
F00A4DAC: d2026390                 ld      [%o1+%lo(_econtig)], %o1
F00A4DB0: 7fffc2fe                 call    _vac_flush
F00A4DB4: 92224008                 sub     %o1, %o0, %o1
F00A4DB8: 113c04f9                 sethi   %hi(_pcontexts), %o0
F00A4DBC: d0022250                 ld      [%o0+%lo(_pcontexts)], %o0
F00A4DC0: 91322006                 srl     %o0, 6, %o0
F00A4DC4: 7fffc21a                 call    _mmu_setctp
F00A4DC8: 912a2002                 sll     %o0, 2, %o0
F00A4DCC: 7fffc220                 call    _mmu_flushall
F00A4DD0: 01000000                 nop
F00A4DD4: 7fffc285                 call    _vac_flushall
F00A4DD8: 01000000                 nop
F00A4DDC: 81c7e008                 ret
F00A4DE0: 81e80000                 restore
