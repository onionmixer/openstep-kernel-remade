F00B7080: 9de3bf98                 save    %sp, -0x68, %sp
F00B7084: d00e2041                 ldub    [%i0+0x41], %o0
F00B7088: 80a22000                 cmp     %o0, 0
F00B708C: 1280000e                 bne     locret_F00B70C4
F00B7090: 01000000                 nop
F00B7094: d0062080                 ld      [%i0+0x80], %o0
F00B7098: 80a22000                 cmp     %o0, 0
F00B709C: 1280000a                 bne     locret_F00B70C4
F00B70A0: 01000000                 nop
F00B70A4: d2062084                 ld      [%i0+0x84], %o1
F00B70A8: d0062088                 ld      [%i0+0x88], %o0
F00B70AC: 80a24008                 cmp     %o1, %o0
F00B70B0: 08800005                 bleu    locret_F00B70C4
F00B70B4: 01000000                 nop
F00B70B8: d25620b0                 ldsh    [%i0+0xB0], %o1
F00B70BC: 7ffff50e                 call    _esp_ustart
F00B70C0: 90100018                 mov     %i0, %o0
F00B70C4: 81c7e008                 ret
F00B70C8: 91e83fff                 restore %g0, -1, %o0
