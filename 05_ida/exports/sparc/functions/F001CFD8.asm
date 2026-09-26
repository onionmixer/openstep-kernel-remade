F001CFD8: 9de3bf98                 save    %sp, -0x68, %sp
F001CFDC: 4001e6f7                 call    _spltty
F001CFE0: 01000000                 nop
F001CFE4: d2064000                 ld      [%i1], %o1
F001CFE8: 80a26000                 cmp     %o1, 0
F001CFEC: 1280000e                 bne     loc_F001D024
F001CFF0: 94100008                 mov     %o0, %o2
F001CFF4: d0060000                 ld      [%i0], %o0
F001CFF8: d0264000                 st      %o0, [%i1]
F001CFFC: d0062004                 ld      [%i0+4], %o0
F001D000: d0266004                 st      %o0, [%i1+4]
F001D004: d2062008                 ld      [%i0+8], %o1! FILE *
F001D008: 9010000a                 mov     %o2, %o0
F001D00C: d2266008                 st      %o1, [%i1+8]
F001D010: c0260000                 clr     [%i0]
F001D014: c0262004                 clr     [%i0+4]
F001D018: 4001e743                 call    _splx
F001D01C: c0262008                 clr     [%i0+8]
F001D020: 3080000b                 ba,a    locret_F001D04C
F001D024: 4001e740                 call    _splx
F001D028: 9010000a                 mov     %o2, %o0! FILE *
F001D02C: 7ffffda7                 call    _getc
F001D030: 90100018                 mov     %i0, %o0! int
F001D034: 80a22000                 cmp     %o0, 0
F001D038: 06800005                 bl      locret_F001D04C
F001D03C: 01000000                 nop
F001D040: 7ffffec4                 call    _putc
F001D044: 92100019                 mov     %i1, %o1
F001D048: 30bffff9                 ba,a    loc_F001D02C
F001D04C: 81c7e008                 ret
F001D050: 81e80000                 restore
