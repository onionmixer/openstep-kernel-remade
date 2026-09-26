F0090344: 9de3bf98                 save    %sp, -0x68, %sp
F0090348: 90960000                 orcc    %i0, %g0, %o0
F009034C: 02800010                 be      locret_F009038C
F0090350: 92102001                 mov     1, %o1
F0090354: 4000e7d5                 call    _IOConvertPort
F0090358: 94102000                 mov     0, %o2
F009035C: b0100008                 mov     %o0, %i0
F0090360: d0060000                 ld      [%i0], %o0
F0090364: 80a22000                 cmp     %o0, 0
F0090368: 12bffffe                 bne     loc_F0090360
F009036C: 01000000                 nop
F0090370: 40001ace                 call    _simple_lock_try
F0090374: 90100018                 mov     %i0, %o0
F0090378: 80a22000                 cmp     %o0, 0
F009037C: 02bffff9                 be      loc_F0090360
F0090380: 01000000                 nop
F0090384: 7fff2a04                 call    _ipc_port_destroy
F0090388: 90100018                 mov     %i0, %o0
F009038C: 81c7e008                 ret
F0090390: 81e80000                 restore
