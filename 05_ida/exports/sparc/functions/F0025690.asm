F0025690: 9de3bf98                 save    %sp, -0x68, %sp
F0025694: d0062040                 ld      [%i0+0x40], %o0
F0025698: 80a22000                 cmp     %o0, 0
F002569C: 02800004                 be      locret_F00256AC
F00256A0: 01000000                 nop
F00256A4: 40000d30                 call    _vn_rele
F00256A8: c0262040                 clr     [%i0+0x40]
F00256AC: 81c7e008                 ret
F00256B0: 81e80000                 restore
