F0067004: 9de3bf98                 save    %sp, -0x68, %sp
F0067008: a2100018                 mov     %i0, %l1
F006700C: a0046064                 add     %l1, 0x64, %l0 ! 'd'
F0067010: d0040000                 ld      [%l0], %o0
F0067014: 80a22000                 cmp     %o0, 0
F0067018: 12bffffe                 bne     loc_F0067010
F006701C: 01000000                 nop
F0067020: 4000bfa2                 call    _simple_lock_try
F0067024: 90100010                 mov     %l0, %o0
F0067028: 80a22000                 cmp     %o0, 0
F006702C: 02bffff9                 be      loc_F0067010
F0067030: 01000000                 nop
F0067034: f004606c                 ld      [%l1+0x6C], %i0
F0067038: d0046068                 ld      [%l1+0x68], %o0
F006703C: 80a60008                 cmp     %i0, %o0
F0067040: 12800013                 bne     loc_F006708C
F0067044: 01000000                 nop
F0067048: d0060000                 ld      [%i0], %o0
F006704C: 80a22000                 cmp     %o0, 0
F0067050: 12bffffe                 bne     loc_F0067048
F0067054: 01000000                 nop
F0067058: 4000bf94                 call    _simple_lock_try
F006705C: 90100018                 mov     %i0, %o0
F0067060: 80a22000                 cmp     %o0, 0
F0067064: 02bffff9                 be      loc_F0067048
F0067068: 01000000                 nop
F006706C: d0062004                 ld      [%i0+4], %o0
F0067070: 90022001                 inc     %o0
F0067074: d0262004                 st      %o0, [%i0+4]
F0067078: d006201c                 ld      [%i0+0x1C], %o0
F006707C: 90022001                 inc     %o0
F0067080: d026201c                 st      %o0, [%i0+0x1C]
F0067084: c0260000                 clr     [%i0]
F0067088: 30800004                 ba,a    loc_F0067098
F006708C: 7fffcfec                 call    _ipc_port_copy_send
F0067090: 90100018                 mov     %i0, %o0
F0067094: b0100008                 mov     %o0, %i0
F0067098: c0246064                 clr     [%l1+0x64]
F006709C: 81c7e008                 ret
F00670A0: 81e80000                 restore
