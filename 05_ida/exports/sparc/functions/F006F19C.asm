F006F19C: 9de3bf98                 save    %sp, -0x68, %sp
F006F1A0: a0062148                 add     %i0, 0x148, %l0
F006F1A4: d0040000                 ld      [%l0], %o0
F006F1A8: 80a22000                 cmp     %o0, 0
F006F1AC: 12bffffe                 bne     loc_F006F1A4
F006F1B0: 01000000                 nop
F006F1B4: 40009f3d                 call    _simple_lock_try
F006F1B8: 90100010                 mov     %l0, %o0
F006F1BC: 80a22000                 cmp     %o0, 0
F006F1C0: 02bffff9                 be      loc_F006F1A4
F006F1C4: 01000000                 nop
F006F1C8: d0062144                 ld      [%i0+0x144], %o0
F006F1CC: c0262148                 clr     [%i0+0x148]
F006F1D0: 90022001                 inc     %o0
F006F1D4: d0262144                 st      %o0, [%i0+0x144]
F006F1D8: 81c7e008                 ret
F006F1DC: 81e80000                 restore
