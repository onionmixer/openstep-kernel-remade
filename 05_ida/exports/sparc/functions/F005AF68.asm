F005AF68: 9de3bf98                 save    %sp, -0x68, %sp
F005AF6C: 90100018                 mov     %i0, %o0
F005AF70: 7fffe2b3                 call    _ipc_entry_lookup
F005AF74: 92100019                 mov     %i1, %o1
F005AF78: b0920000                 orcc    %o0, %g0, %i0
F005AF7C: 02800006                 be      loc_F005AF94
F005AF80: 11000080                 sethi   0x20000, %o0
F005AF84: d2060000                 ld      [%i0], %o1
F005AF88: 808a4008                 btst    %o0, %o1
F005AF8C: 32800004                 bne,a   loc_F005AF9C
F005AF90: f0062004                 ld      [%i0+4], %i0
F005AF94: 10800012                 ba      locret_F005AFDC
F005AF98: b0102000                 mov     0, %i0
F005AF9C: d0060000                 ld      [%i0], %o0
F005AFA0: 80a22000                 cmp     %o0, 0
F005AFA4: 12bffffe                 bne     loc_F005AF9C
F005AFA8: 01000000                 nop
F005AFAC: 4000efbf                 call    _simple_lock_try
F005AFB0: 90100018                 mov     %i0, %o0
F005AFB4: 80a22000                 cmp     %o0, 0
F005AFB8: 02bffff9                 be      loc_F005AF9C
F005AFBC: 01000000                 nop
F005AFC0: d0062004                 ld      [%i0+4], %o0
F005AFC4: 90022001                 inc     %o0
F005AFC8: d0262004                 st      %o0, [%i0+4]
F005AFCC: d0062020                 ld      [%i0+0x20], %o0
F005AFD0: 90022001                 inc     %o0
F005AFD4: d0262020                 st      %o0, [%i0+0x20]
F005AFD8: c0260000                 clr     [%i0]
F005AFDC: 81c7e008                 ret
F005AFE0: 81e80000                 restore
