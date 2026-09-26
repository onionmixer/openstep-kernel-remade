F0045FA8: 9de3bf90                 save    %sp, -0x70, %sp
F0045FAC: a0100018                 mov     %i0, %l0
F0045FB0: 808ea003                 btst    3, %i2
F0045FB4: 1280001c                 bne     loc_F0046024
F0045FB8: f427bff4                 st      %i2, [%fp+var_C]
F0045FBC: 90100010                 mov     %l0, %o0
F0045FC0: 7fffff57                 call    _xdrmbuf_putlong
F0045FC4: 9207bff4                 add     %fp, var_C, %o1
F0045FC8: 80a22000                 cmp     %o0, 0
F0045FCC: 02800016                 be      loc_F0046024
F0045FD0: 9210001c                 mov     %i4, %o1
F0045FD4: d4042010                 ld      [%l0+0x10], %o2
F0045FD8: d8042014                 ld      [%l0+0x14], %o4
F0045FDC: 9010001b                 mov     %i3, %o0
F0045FE0: d612a008                 lduh    [%o2+8], %o3
F0045FE4: 9622c00c                 sub     %o3, %o4, %o3
F0045FE8: d632a008                 sth     %o3, [%o2+8]
F0045FEC: 94100019                 mov     %i1, %o2
F0045FF0: 9610001a                 mov     %i2, %o3
F0045FF4: 7fff60d3                 call    _mclgetx
F0045FF8: 98102001                 mov     1, %o4
F0045FFC: 92920000                 orcc    %o0, %g0, %o1
F0046000: 02800006                 be      loc_F0046018
F0046004: b0102001                 mov     1, %i0
F0046008: d0042010                 ld      [%l0+0x10], %o0
F004600C: d2220000                 st      %o1, [%o0]
F0046010: 10800006                 ba      locret_F0046028
F0046014: c0242014                 clr     [%l0+0x14]
F0046018: 113c0438                 sethi   %hi(aXdrmbufPutbufM), %o0! "xdrmbuf_putbuf: mclgetx failed\n"
F004601C: 7fff398f                 call    _printf
F0046020: 90122130                 bset    %lo(aXdrmbufPutbufM), %o0! "xdrmbuf_putbuf: mclgetx failed\n"
F0046024: b0102000                 mov     0, %i0
F0046028: 81c7e008                 ret
F004602C: 81e80000                 restore
