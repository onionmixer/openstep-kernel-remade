F0038300: 9de3bf98                 save    %sp, -0x68, %sp
F0038304: d0062020                 ld      [%i0+0x20], %o0
F0038308: d2562008                 ldsh    [%i0+8], %o1
F003830C: 80a26003                 cmp     %o1, 3
F0038310: 14800006                 bg      loc_F0038328
F0038314: e002201c                 ld      [%o0+0x1C], %l0
F0038318: 7ffffca5                 call    _tcp_close
F003831C: 90100018                 mov     %i0, %o0
F0038320: 10800019                 ba      locret_F0038384
F0038324: b0100008                 mov     %o0, %i0
F0038328: d0142002                 lduh    [%l0+2], %o0
F003832C: 808a2080                 btst    0x80, %o0
F0038330: 0280000a                 be      loc_F0038358
F0038334: 01000000                 nop
F0038338: d0542004                 ldsh    [%l0+4], %o0
F003833C: 80a22000                 cmp     %o0, 0
F0038340: 12800006                 bne     loc_F0038358
F0038344: 90100018                 mov     %i0, %o0
F0038348: 7ffffc79                 call    _tcp_drop
F003834C: 92102000                 mov     0, %o1
F0038350: 1080000d                 ba      locret_F0038384
F0038354: b0100008                 mov     %o0, %i0
F0038358: 7fff9f41                 call    _soisdisconnecting
F003835C: 90100010                 mov     %l0, %o0
F0038360: 7fffa1d1                 call    _sbflush
F0038364: 90042024                 add     %l0, 0x24, %o0 ! '$'
F0038368: 40000009                 call    _tcp_usrclosed
F003836C: 90100018                 mov     %i0, %o0
F0038370: b0920000                 orcc    %o0, %g0, %i0
F0038374: 02800004                 be      locret_F0038384
F0038378: 01000000                 nop
F003837C: 7ffff981                 call    _tcp_output
F0038380: 01000000                 nop
F0038384: 81c7e008                 ret
F0038388: 81e80000                 restore
