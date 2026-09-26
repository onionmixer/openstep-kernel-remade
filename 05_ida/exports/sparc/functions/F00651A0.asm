F00651A0: 9de3bf98                 save    %sp, -0x68, %sp
F00651A4: 92102000                 mov     0, %o1
F00651A8: 94102000                 mov     0, %o2
F00651AC: d006215c                 ld      [%i0+0x15C], %o0
F00651B0: 4000019c                 call    _ipc_kobject_set
F00651B4: a0062148                 add     %i0, 0x148, %l0
F00651B8: 92102000                 mov     0, %o1
F00651BC: d0062160                 ld      [%i0+0x160], %o0
F00651C0: 40000198                 call    _ipc_kobject_set
F00651C4: 94102000                 mov     0, %o2
F00651C8: d0040000                 ld      [%l0], %o0
F00651CC: 80a22000                 cmp     %o0, 0
F00651D0: 12bffffe                 bne     loc_F00651C8
F00651D4: 01000000                 nop
F00651D8: 4000c734                 call    _simple_lock_try
F00651DC: 90100010                 mov     %l0, %o0
F00651E0: 80a22000                 cmp     %o0, 0
F00651E4: 02bffff9                 be      loc_F00651C8
F00651E8: 01000000                 nop
F00651EC: d0062144                 ld      [%i0+0x144], %o0
F00651F0: c0262148                 clr     [%i0+0x148]
F00651F4: 90023ffe                 inc     -2, %o0
F00651F8: d0262144                 st      %o0, [%i0+0x144]
F00651FC: 81c7e008                 ret
F0065200: 81e80000                 restore
