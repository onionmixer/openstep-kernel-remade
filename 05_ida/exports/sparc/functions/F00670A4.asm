F00670A4: 9de3bf98                 save    %sp, -0x68, %sp
F00670A8: a2100018                 mov     %i0, %l1
F00670AC: a00460a8                 add     %l1, 0xA8, %l0
F00670B0: d0040000                 ld      [%l0], %o0
F00670B4: 80a22000                 cmp     %o0, 0
F00670B8: 12bffffe                 bne     loc_F00670B0
F00670BC: 01000000                 nop
F00670C0: 4000bf7a                 call    _simple_lock_try
F00670C4: 90100010                 mov     %l0, %o0
F00670C8: 80a22000                 cmp     %o0, 0
F00670CC: 02bffff9                 be      loc_F00670B0
F00670D0: 01000000                 nop
F00670D4: f00460b0                 ld      [%l1+0xB0], %i0
F00670D8: d00460ac                 ld      [%l1+0xAC], %o0
F00670DC: 80a60008                 cmp     %i0, %o0
F00670E0: 12800013                 bne     loc_F006712C
F00670E4: 01000000                 nop
F00670E8: d0060000                 ld      [%i0], %o0
F00670EC: 80a22000                 cmp     %o0, 0
F00670F0: 12bffffe                 bne     loc_F00670E8
F00670F4: 01000000                 nop
F00670F8: 4000bf6c                 call    _simple_lock_try
F00670FC: 90100018                 mov     %i0, %o0
F0067100: 80a22000                 cmp     %o0, 0
F0067104: 02bffff9                 be      loc_F00670E8
F0067108: 01000000                 nop
F006710C: d0062004                 ld      [%i0+4], %o0
F0067110: 90022001                 inc     %o0
F0067114: d0262004                 st      %o0, [%i0+4]
F0067118: d006201c                 ld      [%i0+0x1C], %o0
F006711C: 90022001                 inc     %o0
F0067120: d026201c                 st      %o0, [%i0+0x1C]
F0067124: c0260000                 clr     [%i0]
F0067128: 30800004                 ba,a    loc_F0067138
F006712C: 7fffcfc4                 call    _ipc_port_copy_send
F0067130: 90100018                 mov     %i0, %o0
F0067134: b0100008                 mov     %o0, %i0
F0067138: c02460a8                 clr     [%l1+0xA8]
F006713C: 81c7e008                 ret
F0067140: 81e80000                 restore
