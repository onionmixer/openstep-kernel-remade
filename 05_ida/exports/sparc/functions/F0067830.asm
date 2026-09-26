F0067830: 9de3bf98                 save    %sp, -0x68, %sp
F0067834: 80a62000                 cmp     %i0, 0
F0067838: 12800004                 bne     loc_F0067848
F006783C: 01000000                 nop
F0067840: 1080002b                 ba      locret_F00678EC
F0067844: b0102004                 mov     4, %i0
F0067848: 4000020a                 call    _kalloc
F006784C: 90102010                 mov     0x10, %o0
F0067850: a2920000                 orcc    %o0, %g0, %l1
F0067854: 12800004                 bne     loc_F0067864
F0067858: a0062064                 add     %i0, 0x64, %l0 ! 'd'
F006785C: 10800024                 ba      locret_F00678EC
F0067860: b0102006                 mov     6, %i0
F0067864: d0040000                 ld      [%l0], %o0
F0067868: 80a22000                 cmp     %o0, 0
F006786C: 12bffffe                 bne     loc_F0067864
F0067870: 01000000                 nop
F0067874: 4000bd8d                 call    _simple_lock_try
F0067878: 90100010                 mov     %l0, %o0
F006787C: 80a22000                 cmp     %o0, 0
F0067880: 02bffff9                 be      loc_F0067864
F0067884: 01000000                 nop
F0067888: d0062068                 ld      [%i0+0x68], %o0
F006788C: 80a22000                 cmp     %o0, 0
F0067890: 12800008                 bne     loc_F00678B0
F0067894: a4100011                 mov     %l1, %l2
F0067898: c0262064                 clr     [%i0+0x64]
F006789C: 90100011                 mov     %l1, %o0
F00678A0: 40000240                 call    _kfree
F00678A4: 92102010                 mov     0x10, %o1
F00678A8: 10800011                 ba      locret_F00678EC
F00678AC: b0102004                 mov     4, %i0
F00678B0: a0100018                 mov     %i0, %l0
F00678B4: a2102000                 mov     0, %l1
F00678B8: a606200c                 add     %i0, 0xC, %l3
F00678BC: 7fffcde0                 call    _ipc_port_copy_send
F00678C0: d0042078                 ld      [%l0+0x78], %o0
F00678C4: d0244012                 st      %o0, [%l1+%l2]
F00678C8: a0042004                 inc     4, %l0
F00678CC: 80a40013                 cmp     %l0, %l3
F00678D0: 04bffffb                 ble     loc_F00678BC
F00678D4: a2046004                 inc     4, %l1
F00678D8: c0262064                 clr     [%i0+0x64]
F00678DC: e4264000                 st      %l2, [%i1]
F00678E0: 90102004                 mov     4, %o0
F00678E4: d0268000                 st      %o0, [%i2]
F00678E8: b0102000                 mov     0, %i0
F00678EC: 81c7e008                 ret
F00678F0: 81e80000                 restore
