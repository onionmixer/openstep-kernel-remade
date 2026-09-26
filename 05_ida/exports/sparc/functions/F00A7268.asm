F00A7268: 9de3bf98                 save    %sp, -0x68, %sp
F00A726C: 40002a5c                 call    _cngetc
F00A7270: 01000000                 nop
F00A7274: 900a207f                 and     %o0, 0x7F, %o0
F00A7278: 80a2200d                 cmp     %o0, 0xD
F00A727C: 22800030                 be,a    locret_F00A733C
F00A7280: c02e4000                 clrb    [%i1]
F00A7284: 14800009                 bg      loc_F00A72A8
F00A7288: 80a22040                 cmp     %o0, 0x40 ! '@'
F00A728C: 80a22008                 cmp     %o0, 8
F00A7290: 02800019                 be      loc_F00A72F4
F00A7294: 80a2200a                 cmp     %o0, 0xA
F00A7298: 22800029                 be,a    locret_F00A733C
F00A729C: c02e4000                 clrb    [%i1]
F00A72A0: 10800025                 ba      loc_F00A7334
F00A72A4: d02e4000                 stb     %o0, [%i1]
F00A72A8: 0280001f                 be      loc_F00A7324
F00A72AC: 80a22040                 cmp     %o0, 0x40 ! '@'
F00A72B0: 14800007                 bg      loc_F00A72CC
F00A72B4: 80a2207f                 cmp     %o0, 0x7F
F00A72B8: 80a22015                 cmp     %o0, 0x15
F00A72BC: 2280001b                 be,a    loc_F00A7328
F00A72C0: b2100018                 mov     %i0, %i1
F00A72C4: 1080001c                 ba      loc_F00A7334
F00A72C8: d02e4000                 stb     %o0, [%i1]
F00A72CC: 02800004                 be      loc_F00A72DC
F00A72D0: 80a64018                 cmp     %i1, %i0
F00A72D4: 10800018                 ba      loc_F00A7334
F00A72D8: d02e4000                 stb     %o0, [%i1]
F00A72DC: 02800009                 be      loc_F00A7300
F00A72E0: 01000000                 nop
F00A72E4: 40002a43                 call    _cnputc
F00A72E8: 90102008                 mov     8, %o0
F00A72EC: 40002a41                 call    _cnputc
F00A72F0: 90102008                 mov     8, %o0
F00A72F4: 80a64018                 cmp     %i1, %i0
F00A72F8: 12800005                 bne     loc_F00A730C
F00A72FC: 01000000                 nop
F00A7300: 40002a3c                 call    _cnputc
F00A7304: 90102008                 mov     8, %o0
F00A7308: 30bfffd9                 ba,a    loc_F00A726C
F00A730C: 40002a39                 call    _cnputc
F00A7310: 90102020                 mov     0x20, %o0 ! ' '
F00A7314: 40002a37                 call    _cnputc
F00A7318: 90102008                 mov     8, %o0
F00A731C: 10bfffd4                 ba      loc_F00A726C
F00A7320: b2067fff                 inc     -1, %i1
F00A7324: b2100018                 mov     %i0, %i1
F00A7328: 40002a32                 call    _cnputc
F00A732C: 9010200a                 mov     0xA, %o0
F00A7330: 30bfffcf                 ba,a    loc_F00A726C
F00A7334: 10bfffce                 ba      loc_F00A726C
F00A7338: b2066001                 inc     %i1
F00A733C: 81c7e008                 ret
F00A7340: 81e80000                 restore
