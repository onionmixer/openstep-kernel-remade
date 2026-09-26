F009B8B4: 9de3bf90                 save    %sp, -0x70, %sp
F009B8B8: 113c045d                 sethi   %hi(_do_work_arounds), %o0
F009B8BC: d00222dc                 ld      [%o0+%lo(_do_work_arounds)], %o0
F009B8C0: 80a22000                 cmp     %o0, 0
F009B8C4: 0280002c                 be      locret_F009B974
F009B8C8: 113c045d                 sethi   %hi(_vik_rev_level), %o0
F009B8CC: d00222d8                 ld      [%o0+%lo(_vik_rev_level)], %o0
F009B8D0: 80a22001                 cmp     %o0, 1
F009B8D4: 12800014                 bne     loc_F009B924
F009B8D8: 9136e002                 srl     %i3, 2, %o0
F009B8DC: 80a6a002                 cmp     %i2, 2
F009B8E0: 12800012                 bne     loc_F009B928
F009B8E4: 900a2007                 and     %o0, 7, %o0
F009B8E8: 7fffe749                 call    _mmu_probe
F009B8EC: d0060000                 ld      [%i0], %o0
F009B8F0: d027bff4                 st      %o0, [%fp+var_C]
F009B8F4: 900a2047                 and     %o0, 0x47, %o0
F009B8F8: 80a22042                 cmp     %o0, 0x42 ! 'B'
F009B8FC: 3280000a                 bne,a   loc_F009B924
F009B900: 9136e002                 srl     %i3, 2, %o0
F009B904: 113c04d0                 sethi   %hi(_active_threads), %o0
F009B908: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F009B90C: d2060000                 ld      [%i0], %o1
F009B910: d002200c                 ld      [%o0+0xC], %o0
F009B914: d002200c                 ld      [%o0+0xC], %o0
F009B918: 40000ee6                 call    _pmap_clear_modify
F009B91C: d0022024                 ld      [%o0+0x24], %o0
F009B920: 9136e002                 srl     %i3, 2, %o0
F009B924: 900a2007                 and     %o0, 7, %o0
F009B928: 90023ffe                 inc     -2, %o0
F009B92C: 80a22001                 cmp     %o0, 1
F009B930: 18800011                 bgu     locret_F009B974
F009B934: 01000000                 nop
F009B938: d2060000                 ld      [%i0], %o1
F009B93C: d0066008                 ld      [%i1+8], %o0
F009B940: 80a24008                 cmp     %o1, %o0
F009B944: 02800007                 be      loc_F009B960
F009B948: 90100019                 mov     %i1, %o0
F009B94C: d0066004                 ld      [%i1+4], %o0
F009B950: 900a2fff                 and     %o0, 0xFFF, %o0
F009B954: 80a22fdf                 cmp     %o0, 0xFDF
F009B958: 04800007                 ble     locret_F009B974
F009B95C: 90100019                 mov     %i1, %o0
F009B960: 40003961                 call    _fix_addr
F009B964: 9210001b                 mov     %i3, %o1
F009B968: 80a23fff                 cmp     %o0, -1
F009B96C: 32800002                 bne,a   locret_F009B974
F009B970: d0260000                 st      %o0, [%i0]
F009B974: 81c7e008                 ret
F009B978: 81e80000                 restore
