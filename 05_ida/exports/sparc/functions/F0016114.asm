F0016114: 9de3bf98                 save    %sp, -0x68, %sp
F0016118: 80a66000                 cmp     %i1, 0
F001611C: 02800008                 be      loc_F001613C
F0016120: 133c04d4                 sethi   %hi(_nselcoll), %o1
F0016124: d4026230                 ld      [%o1+%lo(_nselcoll)], %o2
F0016128: 113c04d490122238         set     _selwait, %o0
F0016130: 9402a001                 inc     %o2
F0016134: 7ffff32d                 call    _wakeup
F0016138: d4226230                 st      %o2, [%o1+%lo(_nselcoll)]
F001613C: 80a62000                 cmp     %i0, 0
F0016140: 0280001c                 be      locret_F00161B0
F0016144: 01000000                 nop
F0016148: d0062188                 ld      [%i0+0x188], %o0
F001614C: 80a22000                 cmp     %o0, 0
F0016150: 02800018                 be      locret_F00161B0
F0016154: 01000000                 nop
F0016158: 4002028c                 call    _splusclock
F001615C: 01000000                 nop
F0016160: d406203c                 ld      [%i0+0x3C], %o2
F0016164: 133c04d492126238         set     _selwait, %o1
F001616C: 80a28009                 cmp     %o2, %o1
F0016170: 12800006                 bne     loc_F0016188
F0016174: b2100008                 mov     %o0, %i1
F0016178: 90100018                 mov     %i0, %o0
F001617C: 92102000                 mov     0, %o1
F0016180: 40016b2c                 call    _clear_wait
F0016184: 94102001                 mov     1, %o2
F0016188: d006200c                 ld      [%i0+0xC], %o0
F001618C: d402203c                 ld      [%o0+0x3C], %o2
F0016190: 80a2a000                 cmp     %o2, 0
F0016194: 02800005                 be      loc_F00161A8
F0016198: 11001000                 sethi   0x400000, %o0
F001619C: d202a028                 ld      [%o2+0x28], %o1
F00161A0: 902a4008                 andn    %o1, %o0, %o0
F00161A4: d022a028                 st      %o0, [%o2+0x28]
F00161A8: 400202df                 call    _splx
F00161AC: 90100019                 mov     %i1, %o0
F00161B0: 81c7e008                 ret
F00161B4: 81e80000                 restore
