F0017FD8: 9de3bf98                 save    %sp, -0x68, %sp
F0017FDC: 40000c43                 call    _ttynty
F0017FE0: 90100018                 mov     %i0, %o0
F0017FE4: 80a66000                 cmp     %i1, 0
F0017FE8: 1280000c                 bne     loc_F0018018
F0017FEC: 92100008                 mov     %o0, %o1
F0017FF0: d0062040                 ld      [%i0+0x40], %o0
F0017FF4: 900a3fef                 and     %o0, -0x11, %o0
F0017FF8: d0262040                 st      %o0, [%i0+0x40]
F0017FFC: d2026010                 ld      [%o1+0x10], %o1
F0018000: 11000020                 sethi   0x8000, %o0
F0018004: 808a4008                 btst    %o0, %o1
F0018008: 12800008                 bne     locret_F0018028
F001800C: b0100019                 mov     %i1, %i0
F0018010: 10800006                 ba      locret_F0018028
F0018014: b0102000                 mov     0, %i0
F0018018: d0062040                 ld      [%i0+0x40], %o0
F001801C: 90122010                 bset    0x10, %o0
F0018020: d0262040                 st      %o0, [%i0+0x40]
F0018024: b0100019                 mov     %i1, %i0
F0018028: 81c7e008                 ret
F001802C: 81e80000                 restore
