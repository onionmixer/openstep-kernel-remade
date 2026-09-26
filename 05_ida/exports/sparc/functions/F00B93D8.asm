F00B93D8: 9de3bf98                 save    %sp, -0x68, %sp
F00B93DC: 940e20ff                 and     %i0, 0xFF, %o2
F00B93E0: 80a2a011                 cmp     %o2, 0x11
F00B93E4: 18800006                 bgu     loc_F00B93FC
F00B93E8: 113c047d                 sethi   %hi(unk_F011F760), %o0
F00B93EC: 90122360                 bset    %lo(unk_F011F760), %o0
F00B93F0: 932aa002                 sll     %o2, 2, %o1
F00B93F4: 1080000e                 ba      locret_F00B942C
F00B93F8: f0024008                 ld      [%o1+%o0], %i0
F00B93FC: 900e2098                 and     %i0, 0x98, %o0
F00B9400: 80a22080                 cmp     %o0, 0x80
F00B9404: 32800005                 bne,a   loc_F00B9418
F00B9408: 313c04c6                 sethi   -0xFECE800, %i0
F00B940C: 313c047e                 sethi   %hi(aIdentify_0), %i0! "IDENTIFY"
F00B9410: 10800007                 ba      locret_F00B942C
F00B9414: b0162188                 bset    %lo(aIdentify_0), %i0! "IDENTIFY"
F00B9418: b0162008                 bset    8, %i0
F00B941C: 90100018                 mov     %i0, %o0! char *
F00B9420: 133c047e                 sethi   %hi(aUnknownMsg0xX), %o1! "<unknown msg 0x%x>"
F00B9424: 7ffd6cd1                 call    _sprintf
F00B9428: 92126198                 bset    %lo(aUnknownMsg0xX), %o1! "<unknown msg 0x%x>"
F00B942C: 81c7e008                 ret
F00B9430: 81e80000                 restore
