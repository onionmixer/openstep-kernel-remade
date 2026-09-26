F0086FB8: 9de3bf98                 save    %sp, -0x68, %sp
F0086FBC: 80a62000                 cmp     %i0, 0
F0086FC0: 0280001c                 be      locret_F0087030
F0086FC4: a0062010                 add     %i0, 0x10, %l0
F0086FC8: d0040000                 ld      [%l0], %o0
F0086FCC: 80a22000                 cmp     %o0, 0
F0086FD0: 12bffffe                 bne     loc_F0086FC8
F0086FD4: 01000000                 nop
F0086FD8: 40003fb4                 call    _simple_lock_try
F0086FDC: 90100010                 mov     %l0, %o0
F0086FE0: 80a22000                 cmp     %o0, 0
F0086FE4: 02bffff9                 be      loc_F0086FC8
F0086FE8: 01000000                 nop
F0086FEC: e0060000                 ld      [%i0], %l0
F0086FF0: 80a60010                 cmp     %i0, %l0
F0086FF4: 0280000e                 be      loc_F008702C
F0086FF8: 01000000                 nop
F0086FFC: d0042018                 ld      [%l0+0x18], %o0
F0087000: 80a64008                 cmp     %i1, %o0
F0087004: 18800006                 bgu     loc_F008701C
F0087008: 80a2001a                 cmp     %o0, %i2
F008700C: 3a800005                 bcc,a   loc_F0087020
F0087010: e0042008                 ld      [%l0+8], %l0
F0087014: 400059f9                 call    _pmap_remove_all
F0087018: d0042024                 ld      [%l0+0x24], %o0
F008701C: e0042008                 ld      [%l0+8], %l0
F0087020: 80a60010                 cmp     %i0, %l0
F0087024: 32bffff7                 bne,a   loc_F0087000
F0087028: d0042018                 ld      [%l0+0x18], %o0
F008702C: c0262010                 clr     [%i0+0x10]
F0087030: 81c7e008                 ret
F0087034: 81e80000                 restore
