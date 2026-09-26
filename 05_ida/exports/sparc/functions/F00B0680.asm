F00B0680: 9de3bf98                 save    %sp, -0x68, %sp
F00B0684: 80a66000                 cmp     %i1, 0
F00B0688: 04800029                 ble     locret_F00B072C
F00B068C: a010001c                 mov     %i4, %l0
F00B0690: 9096c000                 orcc    %i3, %g0, %o0
F00B0694: 04800026                 ble     locret_F00B072C
F00B0698: b606ffff                 inc     -1, %i3
F00B069C: 253c0471                 sethi   -0xFEE3C00, %l2
F00B06A0: 233c0471                 sethi   -0xFEE3C00, %l1
F00B06A4: b8072004                 inc     4, %i4
F00B06A8: 92102000                 mov     0, %o1
F00B06AC: 80a24019                 cmp     %o1, %i1
F00B06B0: 1680000c                 bge     loc_F00B06E0
F00B06B4: 9410001a                 mov     %i2, %o2
F00B06B8: d6040000                 ld      [%l0], %o3
F00B06BC: d0028000                 ld      [%o2], %o0
F00B06C0: 80a2c008                 cmp     %o3, %o0
F00B06C4: 02800007                 be      loc_F00B06E0
F00B06C8: 80a24019                 cmp     %o1, %i1
F00B06CC: 92026001                 inc     %o1
F00B06D0: 80a24019                 cmp     %o1, %i1
F00B06D4: 06bffffa                 bl      loc_F00B06BC
F00B06D8: 9402a014                 inc     0x14, %o2
F00B06DC: 80a24019                 cmp     %o1, %i1
F00B06E0: 32800008                 bne,a   loc_F00B0700
F00B06E4: d0070000                 ld      [%i4], %o0
F00B06E8: d004a05c                 ld      [%l2+0x5C], %o0! char *
F00B06EC: 92146060                 or      %l1, 0x60, %o1
F00B06F0: 7ffd8fda                 call    _printf
F00B06F4: 94100018                 mov     %i0, %o2
F00B06F8: 1080000a                 ba      loc_F00B0720
F00B06FC: 9010001b                 mov     %i3, %o0
F00B0700: d202a00c                 ld      [%o2+0xC], %o1
F00B0704: 90020009                 add     %o0, %o1, %o0
F00B0708: d0270000                 st      %o0, [%i4]
F00B070C: d002a008                 ld      [%o2+8], %o0
F00B0710: b807200c                 inc     0xC, %i4
F00B0714: d0240000                 st      %o0, [%l0]
F00B0718: a004200c                 inc     0xC, %l0
F00B071C: 9010001b                 mov     %i3, %o0
F00B0720: 80a22000                 cmp     %o0, 0
F00B0724: 14bfffe1                 bg      loc_F00B06A8
F00B0728: b606ffff                 inc     -1, %i3
F00B072C: 81c7e008                 ret
F00B0730: 81e80000                 restore
