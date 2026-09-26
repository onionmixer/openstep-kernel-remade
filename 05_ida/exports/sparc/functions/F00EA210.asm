F00EA210: 9de3bf98                 save    %sp, -0x68, %sp
F00EA214: d04e0000                 ldsb    [%i0], %o0
F00EA218: 80a2202a                 cmp     %o0, 0x2A ! '*'
F00EA21C: 22800010                 be,a    loc_F00EA25C
F00EA220: 80a66000                 cmp     %i1, 0
F00EA224: 14800007                 bg      loc_F00EA240
F00EA228: 80a22040                 cmp     %o0, 0x40 ! '@'
F00EA22C: 80a22025                 cmp     %o0, 0x25 ! '%'
F00EA230: 0280000b                 be      loc_F00EA25C
F00EA234: 80a66000                 cmp     %i1, 0
F00EA238: 10800027                 ba      loc_F00EA2D4
F00EA23C: 91366010                 srl     %i1, 16, %o0
F00EA240: 12800025                 bne     loc_F00EA2D4
F00EA244: 91366010                 srl     %i1, 16, %o0
F00EA248: 133c0506                 sethi   %hi(paHash), %o1! SEL
F00EA24C: 90100019                 mov     %i1, %o0! id
F00EA250: 40001d88                 call    _objc_msgSend
F00EA254: d2026268                 ld      [%o1+%lo(paHash)], %o1
F00EA258: 30800020                 ba,a    loc_F00EA2D8
F00EA25C: 0280001c                 be      loc_F00EA2CC
F00EA260: 92102000                 mov     0, %o1
F00EA264: d00e4000                 ldub    [%i1], %o0
F00EA268: 80a22000                 cmp     %o0, 0
F00EA26C: 02800016                 be      loc_F00EA2C4
F00EA270: b2066001                 inc     %i1
F00EA274: 921a4008                 btog    %o0, %o1
F00EA278: d00e4000                 ldub    [%i1], %o0
F00EA27C: 80a22000                 cmp     %o0, 0
F00EA280: 02800011                 be      loc_F00EA2C4
F00EA284: 912a2008                 sll     %o0, 8, %o0
F00EA288: 921a4008                 btog    %o0, %o1
F00EA28C: b2066001                 inc     %i1
F00EA290: d00e4000                 ldub    [%i1], %o0
F00EA294: 80a22000                 cmp     %o0, 0
F00EA298: 0280000b                 be      loc_F00EA2C4
F00EA29C: 912a2010                 sll     %o0, 16, %o0
F00EA2A0: 921a4008                 btog    %o0, %o1
F00EA2A4: b2066001                 inc     %i1
F00EA2A8: d00e4000                 ldub    [%i1], %o0
F00EA2AC: 80a22000                 cmp     %o0, 0
F00EA2B0: 02800005                 be      loc_F00EA2C4
F00EA2B4: 912a2018                 sll     %o0, 24, %o0
F00EA2B8: 921a4008                 btog    %o0, %o1
F00EA2BC: 10bfffea                 ba      loc_F00EA264
F00EA2C0: b2066001                 inc     %i1
F00EA2C4: 10800005                 ba      loc_F00EA2D8
F00EA2C8: 90100009                 mov     %o1, %o0
F00EA2CC: 10800005                 ba      locret_F00EA2E0
F00EA2D0: 90102000                 mov     0, %o0
F00EA2D4: 901a0019                 btog    %i1, %o0
F00EA2D8: 7ffc7172                 call    _urem
F00EA2DC: 9210001a                 mov     %i2, %o1
F00EA2E0: 81c7e008                 ret
F00EA2E4: 91e80008                 restore %g0, %o0, %o0
