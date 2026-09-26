F00A9FDC: 9de3bf98                 save    %sp, -0x68, %sp
F00A9FE0: 80a6a000                 cmp     %i2, 0
F00A9FE4: 12800004                 bne     loc_F00A9FF4
F00A9FE8: 80a6a00f                 cmp     %i2, 0xF
F00A9FEC: 1080001a                 ba      loc_F00AA054
F00A9FF0: c026c000                 clr     [%i3]
F00A9FF4: 18800004                 bgu     loc_F00AA004
F00A9FF8: 912ea002                 sll     %i2, 2, %o0
F00A9FFC: 10800015                 ba      loc_F00AA050
F00AA000: d0060008                 ld      [%i0+%o0], %o0
F00AA004: 80a72000                 cmp     %i4, 0
F00AA008: 12800010                 bne     loc_F00AA048
F00AA00C: 01000000                 nop
F00AA010: 90023fc0                 inc     -0x40, %o0
F00AA014: b2064008                 add     %i1, %o0, %i1
F00AA018: 7fff7ff7                 call    _fuword
F00AA01C: 90100019                 mov     %i1, %o0
F00AA020: 80a23fff                 cmp     %o0, -1
F00AA024: 1280000c                 bne     loc_F00AA054
F00AA028: d026c000                 st      %o0, [%i3]
F00AA02C: 7fff7fd2                 call    _fubyte
F00AA030: 90100019                 mov     %i1, %o0
F00AA034: 80a23fff                 cmp     %o0, -1
F00AA038: 12800008                 bne     locret_F00AA058
F00AA03C: b0102000                 mov     0, %i0
F00AA040: 10800006                 ba      locret_F00AA058
F00AA044: b0103fff                 mov     -1, %i0
F00AA048: 90020019                 add     %o0, %i1, %o0
F00AA04C: d0023fc0                 ld      [%o0-0x40], %o0
F00AA050: d026c000                 st      %o0, [%i3]
F00AA054: b0102000                 mov     0, %i0
F00AA058: 81c7e008                 ret
F00AA05C: 81e80000                 restore
