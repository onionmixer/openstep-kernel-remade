F00B0734: 9de3bf98                 save    %sp, -0x68, %sp
F00B0738: 80a66000                 cmp     %i1, 0
F00B073C: 04800028                 ble     locret_F00B07DC
F00B0740: 9010001b                 mov     %i3, %o0
F00B0744: 80a22000                 cmp     %o0, 0
F00B0748: 04800025                 ble     locret_F00B07DC
F00B074C: b606ffff                 inc     -1, %i3
F00B0750: 233c0471                 sethi   -0xFEE3C00, %l1
F00B0754: 213c0471                 sethi   -0xFEE3C00, %l0
F00B0758: b8072008                 inc     8, %i4
F00B075C: 92102000                 mov     0, %o1
F00B0760: 80a24019                 cmp     %o1, %i1
F00B0764: 1680000c                 bge     loc_F00B0794
F00B0768: 9410001a                 mov     %i2, %o2
F00B076C: d6070000                 ld      [%i4], %o3
F00B0770: d0028000                 ld      [%o2], %o0
F00B0774: 80a2c008                 cmp     %o3, %o0
F00B0778: 02800007                 be      loc_F00B0794
F00B077C: 80a24019                 cmp     %o1, %i1
F00B0780: 92026001                 inc     %o1
F00B0784: 80a24019                 cmp     %o1, %i1
F00B0788: 06bffffa                 bl      loc_F00B0770
F00B078C: 9402a014                 inc     0x14, %o2
F00B0790: 80a24019                 cmp     %o1, %i1
F00B0794: 32800008                 bne,a   loc_F00B07B4
F00B0798: d0072004                 ld      [%i4+4], %o0
F00B079C: d004605c                 ld      [%l1+0x5C], %o0! char *
F00B07A0: 92142070                 or      %l0, 0x70, %o1
F00B07A4: 7ffd8fad                 call    _printf
F00B07A8: 94100018                 mov     %i0, %o2
F00B07AC: 10800009                 ba      loc_F00B07D0
F00B07B0: 9010001b                 mov     %i3, %o0
F00B07B4: d202a00c                 ld      [%o2+0xC], %o1
F00B07B8: 90020009                 add     %o0, %o1, %o0
F00B07BC: d0272004                 st      %o0, [%i4+4]
F00B07C0: d002a008                 ld      [%o2+8], %o0
F00B07C4: d0270000                 st      %o0, [%i4]
F00B07C8: b8072014                 inc     0x14, %i4
F00B07CC: 9010001b                 mov     %i3, %o0
F00B07D0: 80a22000                 cmp     %o0, 0
F00B07D4: 14bfffe2                 bg      loc_F00B075C
F00B07D8: b606ffff                 inc     -1, %i3
F00B07DC: 81c7e008                 ret
F00B07E0: 81e80000                 restore
