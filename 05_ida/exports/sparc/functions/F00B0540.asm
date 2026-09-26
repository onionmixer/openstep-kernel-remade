F00B0540: 9de3bf98                 save    %sp, -0x68, %sp
F00B0544: 92960000                 orcc    %i0, %g0, %o1
F00B0548: 32800005                 bne,a   loc_F00B055C
F00B054C: 113c0470                 sethi   -0xFEE4000, %o0
F00B0550: 113c0470921223b0         set     aUnknownPanic, %o1! "unknown panic"
F00B0558: 113c0470                 sethi   -0xFEE4000, %o0
F00B055C: 7ffffc87                 call    _prom_printf
F00B0560: 901223c0                 bset    0x3C0, %o0
F00B0564: 7ffffa58                 call    _prom_enter_mon
F00B0568: 01000000                 nop
F00B056C: 81c7e008                 ret
F00B0570: 81e80000                 restore
