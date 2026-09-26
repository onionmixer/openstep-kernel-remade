F00B5E1C: 9de3bf98                 save    %sp, -0x68, %sp
F00B5E20: a0100018                 mov     %i0, %l0
F00B5E24: d00c2044                 ldub    [%l0+0x44], %o0
F00B5E28: 808a2010                 btst    0x10, %o0
F00B5E2C: 22800017                 be,a    loc_F00B5E88
F00B5E30: d00c2041                 ldub    [%l0+0x41], %o0
F00B5E34: d00c2043                 ldub    [%l0+0x43], %o0
F00B5E38: 900a2007                 and     %o0, 7, %o0
F00B5E3C: 80a22007                 cmp     %o0, 7
F00B5E40: 3280000a                 bne,a   loc_F00B5E68
F00B5E44: d00c205c                 ldub    [%l0+0x5C], %o0
F00B5E48: d204209c                 ld      [%l0+0x9C], %o1
F00B5E4C: 90102010                 mov     0x10, %o0
F00B5E50: d02a600c                 stb     %o0, [%o1+0xC]
F00B5E54: d00c2041                 ldub    [%l0+0x41], %o0
F00B5E58: b0103fff                 mov     -1, %i0
F00B5E5C: d02c2042                 stb     %o0, [%l0+0x42]
F00B5E60: 1080000d                 ba      loc_F00B5E94
F00B5E64: 90102007                 mov     7, %o0
F00B5E68: 80a22000                 cmp     %o0, 0
F00B5E6C: 02800006                 be      loc_F00B5E84
F00B5E70: 90100010                 mov     %l0, %o0
F00B5E74: 153c0479                 sethi   %hi(aPrematureEndOf), %o2! "Premature end of extended message"
F00B5E78: 92102004                 mov     4, %o1
F00B5E7C: 4000075c                 call    _esplog
F00B5E80: 9412a370                 bset    %lo(aPrematureEndOf), %o2! "Premature end of extended message"
F00B5E84: d00c2041                 ldub    [%l0+0x41], %o0
F00B5E88: b0102002                 mov     2, %i0
F00B5E8C: d02c2042                 stb     %o0, [%l0+0x42]
F00B5E90: 9010201a                 mov     0x1A, %o0
F00B5E94: d02c2041                 stb     %o0, [%l0+0x41]
F00B5E98: 81c7e008                 ret
F00B5E9C: 81e80000                 restore
