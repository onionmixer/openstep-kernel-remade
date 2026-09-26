F009A684: 9de3bf98                 save    %sp, -0x68, %sp
F009A688: 113c045d                 sethi   %hi(_module_info_size), %o0
F009A68C: e002215c                 ld      [%o0+%lo(_module_info_size)], %l0
F009A690: a4102000                 mov     0, %l2
F009A694: 113c045d                 sethi   %hi(_module_info), %o0
F009A698: 1080000e                 ba      loc_F009A6D0
F009A69C: a212214c                 or      %o0, %lo(_module_info), %l1
F009A6A0: d2044000                 ld      [%l1], %o1
F009A6A4: 9fc24000                 call    %o1
F009A6A8: 90100018                 mov     %i0, %o0
F009A6AC: 80a22001                 cmp     %o0, 1
F009A6B0: 32800008                 bne,a   loc_F009A6D0
F009A6B4: a2046008                 inc     8, %l1
F009A6B8: 90100018                 mov     %i0, %o0
F009A6BC: d2046004                 ld      [%l1+4], %o1
F009A6C0: 9fc24000                 call    %o1
F009A6C4: a4102001                 mov     1, %l2
F009A6C8: 10800006                 ba      loc_F009A6E0
F009A6CC: 80a4a000                 cmp     %l2, 0
F009A6D0: 90940000                 orcc    %l0, %g0, %o0
F009A6D4: 14bffff3                 bg      loc_F009A6A0
F009A6D8: a0043fff                 inc     -1, %l0
F009A6DC: 80a4a000                 cmp     %l2, 0
F009A6E0: 12800009                 bne     locret_F009A704
F009A6E4: 113c045c                 sethi   %hi(aUnsupportedMod), %o0! "Unsupported module type: IMPL=0x%x VERS"...
F009A6E8: 90122338                 bset    %lo(aUnsupportedMod), %o0! "Unsupported module type: IMPL=0x%x VERS"...
F009A6EC: 953e2018                 sra     %i0, 24, %o2
F009A6F0: 933e201c                 sra     %i0, 28, %o1
F009A6F4: 40005421                 call    _prom_printf
F009A6F8: 940aa00f                 and     %o2, 0xF, %o2
F009A6FC: 40005203                 call    _prom_exit_to_mon
F009A700: 01000000                 nop
F009A704: 81c7e008                 ret
F009A708: 81e80000                 restore
