F0073164: 9de3bf98                 save    %sp, -0x68, %sp
F0073168: 80a62000                 cmp     %i0, 0
F007316C: 0280000f                 be      locret_F00731A8
F0073170: 01000000                 nop
F0073174: d0060000                 ld      [%i0], %o0
F0073178: 80a22000                 cmp     %o0, 0
F007317C: 12bffffe                 bne     loc_F0073174
F0073180: 01000000                 nop
F0073184: 40008f49                 call    _simple_lock_try
F0073188: 90100018                 mov     %i0, %o0
F007318C: 80a22000                 cmp     %o0, 0
F0073190: 02bffff9                 be      loc_F0073174
F0073194: 01000000                 nop
F0073198: d0062004                 ld      [%i0+4], %o0
F007319C: c0260000                 clr     [%i0]
F00731A0: 90022001                 inc     %o0
F00731A4: d0262004                 st      %o0, [%i0+4]
F00731A8: 81c7e008                 ret
F00731AC: 81e80000                 restore
