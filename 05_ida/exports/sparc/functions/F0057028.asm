F0057028: 9de3bf98                 save    %sp, -0x68, %sp
F005702C: a0100018                 mov     %i0, %l0
F0057030: 90042014                 add     %l0, 0x14, %o0
F0057034: 92100019                 mov     %i1, %o1
F0057038: e2042014                 ld      [%l0+0x14], %l1
F005703C: 7ffffcf5                 call    _ipc_kmsg_copyout_header
F0057040: 9410001b                 mov     %i3, %o2
F0057044: b0920000                 orcc    %o0, %g0, %i0
F0057048: 1280000f                 bne     locret_F0057084
F005704C: 80a46000                 cmp     %l1, 0
F0057050: 1680000d                 bge     locret_F0057084
F0057054: 9004202c                 add     %l0, 0x2C, %o0 ! ','
F0057058: d2042018                 ld      [%l0+0x18], %o1
F005705C: 94100019                 mov     %i1, %o2
F0057060: 9610001a                 mov     %i2, %o3
F0057064: 92026014                 inc     0x14, %o1
F0057068: 7fffff69                 call    _ipc_kmsg_copyout_body
F005706C: 92040009                 add     %l0, %o1, %o1
F0057070: b0920000                 orcc    %o0, %g0, %i0
F0057074: 02800004                 be      locret_F0057084
F0057078: 11040010                 sethi   0x10004000, %o0
F005707C: 9012200c                 bset    0xC, %o0
F0057080: b0160008                 bset    %o0, %i0
F0057084: 81c7e008                 ret
F0057088: 81e80000                 restore
