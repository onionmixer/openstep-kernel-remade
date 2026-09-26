F00C2BC4: 9de3bf98                 save    %sp, -0x68, %sp
F00C2BC8: 92100018                 mov     %i0, %o1
F00C2BCC: 94102000                 mov     0, %o2
F00C2BD0: 113c04fdb0122350         set     _msdata, %i0
F00C2BD8: d0062018                 ld      [%i0+0x18], %o0
F00C2BDC: 80a20009                 cmp     %o0, %o1
F00C2BE0: 02800009                 be      locret_F00C2C04
F00C2BE4: 9402a001                 inc     %o2
F00C2BE8: 80a2a000                 cmp     %o2, 0
F00C2BEC: 04bffffb                 ble     loc_F00C2BD8
F00C2BF0: b0062034                 inc     0x34, %i0 ! '4'
F00C2BF4: 113c0484                 sethi   %hi(aMstptomsdCalle), %o0! "mstptomsd called with unknown tp %X\n"
F00C2BF8: 7ffd4698                 call    _printf
F00C2BFC: 901222b0                 bset    %lo(aMstptomsdCalle), %o0! "mstptomsd called with unknown tp %X\n"
F00C2C00: b0102000                 mov     0, %i0
F00C2C04: 81c7e008                 ret
F00C2C08: 81e80000                 restore
