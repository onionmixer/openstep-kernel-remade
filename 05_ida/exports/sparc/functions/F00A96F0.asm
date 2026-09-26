F00A96F0: 9de3bf98                 save    %sp, -0x68, %sp
F00A96F4: 80a6a000                 cmp     %i2, 0
F00A96F8: 12800004                 bne     loc_F00A9708
F00A96FC: 80a6a00f                 cmp     %i2, 0xF
F00A9700: 10800014                 ba      loc_F00A9750
F00A9704: c026c000                 clr     [%i3]
F00A9708: 08800010                 bleu    loc_F00A9748
F00A970C: 912ea002                 sll     %i2, 2, %o0
F00A9710: 90023fc0                 inc     -0x40, %o0
F00A9714: b2064008                 add     %i1, %o0, %i1
F00A9718: 7fff8237                 call    _fuword
F00A971C: 90100019                 mov     %i1, %o0
F00A9720: 80a23fff                 cmp     %o0, -1
F00A9724: 1280000b                 bne     loc_F00A9750
F00A9728: d026c000                 st      %o0, [%i3]
F00A972C: 7fff8212                 call    _fubyte
F00A9730: 90100019                 mov     %i1, %o0
F00A9734: 80a23fff                 cmp     %o0, -1
F00A9738: 12800007                 bne     locret_F00A9754
F00A973C: b0102000                 mov     0, %i0
F00A9740: 10800005                 ba      locret_F00A9754
F00A9744: b0103fff                 mov     -1, %i0
F00A9748: d0060008                 ld      [%i0+%o0], %o0
F00A974C: d026c000                 st      %o0, [%i3]
F00A9750: b0102000                 mov     0, %i0
F00A9754: 81c7e008                 ret
F00A9758: 81e80000                 restore
