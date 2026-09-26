F0099134: 9de3bf98                 save    %sp, -0x68, %sp
F0099138: 80a66000                 cmp     %i1, 0
F009913C: 0280002c                 be      loc_F00991EC
F0099140: 80a6204f                 cmp     %i0, 0x4F ! 'O'
F0099144: 08800004                 bleu    loc_F0099154
F0099148: 113c045b                 sethi   %hi(aRemintrVectorN), %o0! "remintr: vector number out of range"
F009914C: 7ffdf009                 call    _panic
F0099150: 901222b8                 bset    %lo(aRemintrVectorN), %o0! "remintr: vector number out of range"
F0099154: 113c045b901220d4         set     _vectorlist, %o0
F009915C: 932e2002                 sll     %i0, 2, %o1
F0099160: e0024008                 ld      [%o1+%o0], %l0
F0099164: 80a42000                 cmp     %l0, 0
F0099168: 12800006                 bne     loc_F0099180
F009916C: 96102000                 mov     0, %o3
F0099170: 113c045b                 sethi   %hi(aRemintrSpecifi), %o0! "remintr: specified vector can not be po"...
F0099174: 7ffdefff                 call    _panic
F0099178: 901222e0                 bset    %lo(aRemintrSpecifi), %o0! "remintr: specified vector can not be po"...
F009917C: 96102000                 mov     0, %o3
F0099180: d0040000                 ld      [%l0], %o0
F0099184: 80a22000                 cmp     %o0, 0
F0099188: 0280001e                 be      loc_F0099200
F009918C: 80a20019                 cmp     %o0, %i1
F0099190: 12800019                 bne     loc_F00991F4
F0099194: 9602e001                 inc     %o3
F0099198: 80a2e009                 cmp     %o3, 9
F009919C: 3480001e                 bg,a    locret_F0099214
F00991A0: b0102000                 mov     0, %i0
F00991A4: 94042014                 add     %l0, 0x14, %o2
F00991A8: 9602e001                 inc     %o3
F00991AC: d002a004                 ld      [%o2+4], %o0
F00991B0: 80a2e009                 cmp     %o3, 9
F00991B4: d0240000                 st      %o0, [%l0]
F00991B8: d002a008                 ld      [%o2+8], %o0
F00991BC: a0042018                 inc     0x18, %l0
F00991C0: d202a00c                 ld      [%o2+0xC], %o1
F00991C4: d022bff0                 st      %o0, [%o2-0x10]
F00991C8: d002a010                 ld      [%o2+0x10], %o0
F00991CC: d222bff4                 st      %o1, [%o2-0xC]
F00991D0: d202a014                 ld      [%o2+0x14], %o1
F00991D4: d022bff8                 st      %o0, [%o2-8]
F00991D8: d002a018                 ld      [%o2+0x18], %o0
F00991DC: d222bffc                 st      %o1, [%o2-4]
F00991E0: d0228000                 st      %o0, [%o2]
F00991E4: 04bffff1                 ble     loc_F00991A8
F00991E8: 9402a018                 inc     0x18, %o2
F00991EC: 1080000a                 ba      locret_F0099214
F00991F0: b0102000                 mov     0, %i0
F00991F4: 80a2e009                 cmp     %o3, 9
F00991F8: 04bfffe2                 ble     loc_F0099180
F00991FC: a0042018                 inc     0x18, %l0
F0099200: 113c045b90122310         set     aRemintrDriverN, %o0! "remintr: driver not installed on level "...
F0099208: 7ffded14                 call    _printf
F009920C: 92100018                 mov     %i0, %o1
F0099210: b0103fff                 mov     -1, %i0
F0099214: 81c7e008                 ret
F0099218: 81e80000                 restore
