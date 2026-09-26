F0070944: 9de3bf90                 save    %sp, -0x70, %sp
F0070948: a210212c                 mov     0x12C, %l1
F007094C: 113c04bea0122130         set     unk_F012F930, %l0
F0070954: a810202a                 mov     0x2A, %l4 ! '*'
F0070958: 253c04f1                 sethi   -0xFEC3C00, %l2
F007095C: 27000061                 sethi   0x18400, %l3
F0070960: e82425ec                 st      %l4, [%l0+0x5EC]
F0070964: 9004202a                 add     %l0, 0x2A, %o0 ! '*'
F0070968: 920425f0                 add     %l0, 0x5F0, %o1
F007096C: 9407bff6                 add     %fp, var_A, %o2
F0070970: 96100018                 mov     %i0, %o3
F0070974: 98100019                 mov     %i1, %o4
F0070978: 40008e66                 call    _kdp_exception
F007097C: 9a10001a                 mov     %i2, %o5
F0070980: 7ffffe80                 call    sub_F0070380
F0070984: d017bff6                 lduh    [%fp+var_A], %o0
F0070988: 7fffff0f                 call    sub_F00705C4
F007098C: 01000000                 nop
F0070990: d00425f4                 ld      [%l0+0x5F4], %o0
F0070994: 80a22000                 cmp     %o0, 0
F0070998: 22800007                 be,a    loc_F00709B4
F007099C: d004a018                 ld      [%l2+0x18], %o0
F00709A0: d00425ec                 ld      [%l0+0x5EC], %o0
F00709A4: d20425f0                 ld      [%l0+0x5F0], %o1
F00709A8: 40008e86                 call    _kdp_exception_ack
F00709AC: 90020010                 add     %o0, %l0, %o0
F00709B0: d004a018                 ld      [%l2+0x18], %o0
F00709B4: 80a22000                 cmp     %o0, 0
F00709B8: 02800004                 be      loc_F00709C8
F00709BC: c02425f4                 clr     [%l0+0x5F4]
F00709C0: 40008f79                 call    _kdp_us_spin
F00709C4: 9014e2a0                 or      %l3, 0x2A0, %o0
F00709C8: d004a018                 ld      [%l2+0x18], %o0
F00709CC: 80a22000                 cmp     %o0, 0
F00709D0: 2280000d                 be,a    locret_F0070A04
F00709D4: 113c0440                 sethi   -0xFEF0000, %o0
F00709D8: a2047fff                 inc     -1, %l1
F00709DC: 80a47fff                 cmp     %l1, -1
F00709E0: 32bfffe1                 bne,a   loc_F0070964
F00709E4: e82425ec                 st      %l4, [%l0+0x5EC]
F00709E8: 80a22000                 cmp     %o0, 0
F00709EC: 02800006                 be      locret_F0070A04
F00709F0: 113c0440                 sethi   %hi(aKdpExceptionAc), %o0! "kdp: exception ack timeout\n"
F00709F4: 7ffff581                 call    _safe_prf
F00709F8: 90122328                 bset    %lo(aKdpExceptionAc), %o0! "kdp: exception ack timeout\n"
F00709FC: 4000004c                 call    _kdp_reset
F0070A00: 01000000                 nop
F0070A04: 81c7e008                 ret
F0070A08: 81e80000                 restore
