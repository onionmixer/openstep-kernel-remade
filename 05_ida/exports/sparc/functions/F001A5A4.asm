F001A5A4: 9de3bf98                 save    %sp, -0x68, %sp
F001A5A8: 4001f184                 call    _spltty
F001A5AC: 01000000                 nop
F001A5B0: d4062028                 ld      [%i0+0x28], %o2
F001A5B4: 80a2a000                 cmp     %o2, 0
F001A5B8: 0280000b                 be      loc_F001A5E4
F001A5BC: a0100008                 mov     %o0, %l0
F001A5C0: d2062040                 ld      [%i0+0x40], %o1
F001A5C4: 9010000a                 mov     %o2, %o0
F001A5C8: 7fffeed3                 call    _selwakeup
F001A5CC: 920a6800                 and     %o1, 0x800, %o1
F001A5D0: 7fffeec1                 call    _selthreadclear
F001A5D4: 90062028                 add     %i0, 0x28, %o0 ! '('
F001A5D8: d0062040                 ld      [%i0+0x40], %o0
F001A5DC: 900a37ff                 and     %o0, -0x801, %o0
F001A5E0: d0262040                 st      %o0, [%i0+0x40]
F001A5E4: 4001f1d0                 call    _splx
F001A5E8: 90100010                 mov     %l0, %o0
F001A5EC: d2062040                 ld      [%i0+0x40], %o1
F001A5F0: 11000010                 sethi   0x4000, %o0
F001A5F4: 808a4008                 btst    %o0, %o1
F001A5F8: 02800005                 be      loc_F001A60C
F001A5FC: 01000000                 nop
F001A600: d0562044                 ldsh    [%i0+0x44], %o0
F001A604: 7fffdbb6                 call    _gsignal
F001A608: 92102017                 mov     0x17, %o1
F001A60C: 7fffe1f7                 call    _wakeup
F001A610: 90100018                 mov     %i0, %o0
F001A614: 81c7e008                 ret
F001A618: 81e80000                 restore
