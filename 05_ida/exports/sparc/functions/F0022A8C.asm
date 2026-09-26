F0022A8C: 9de3bf98                 save    %sp, -0x68, %sp
F0022A90: d0062004                 ld      [%i0+4], %o0
F0022A94: 80a22000                 cmp     %o0, 0
F0022A98: 22800007                 be,a    loc_F0022AB4
F0022A9C: d006200c                 ld      [%i0+0xC], %o0
F0022AA0: c0222020                 clr     [%o0+0x20]
F0022AA4: 40001830                 call    _vn_rele
F0022AA8: d0062004                 ld      [%i0+4], %o0
F0022AAC: c0262004                 clr     [%i0+4]
F0022AB0: d006200c                 ld      [%i0+0xC], %o0
F0022AB4: 80a22000                 cmp     %o0, 0
F0022AB8: 22800009                 be,a    loc_F0022ADC
F0022ABC: d0062010                 ld      [%i0+0x10], %o0
F0022AC0: 400000a6                 call    _unp_disconnect
F0022AC4: 90100018                 mov     %i0, %o0
F0022AC8: 10800005                 ba      loc_F0022ADC
F0022ACC: d0062010                 ld      [%i0+0x10], %o0
F0022AD0: 400000d3                 call    _unp_drop
F0022AD4: 92102036                 mov     0x36, %o1 ! '6'
F0022AD8: d0062010                 ld      [%i0+0x10], %o0
F0022ADC: 80a22000                 cmp     %o0, 0
F0022AE0: 32bffffc                 bne,a   loc_F0022AD0
F0022AE4: d0062010                 ld      [%i0+0x10], %o0
F0022AE8: 7ffff56c                 call    _soisdisconnected
F0022AEC: d0060000                 ld      [%i0], %o0
F0022AF0: d0060000                 ld      [%i0], %o0
F0022AF4: c0222008                 clr     [%o0+8]
F0022AF8: 7fffec5b                 call    _m_freem
F0022AFC: d0062018                 ld      [%i0+0x18], %o0
F0022B00: 90100018                 mov     %i0, %o0
F0022B04: 400115a7                 call    _kfree
F0022B08: 92102024                 mov     0x24, %o1 ! '$'
F0022B0C: 113c04d4                 sethi   %hi(_unp_rights), %o0
F0022B10: d00222d0                 ld      [%o0+%lo(_unp_rights)], %o0
F0022B14: 80a22000                 cmp     %o0, 0
F0022B18: 02800004                 be      locret_F0022B28
F0022B1C: 01000000                 nop
F0022B20: 40000133                 call    _unp_gc
F0022B24: 01000000                 nop
F0022B28: 81c7e008                 ret
F0022B2C: 81e80000                 restore
