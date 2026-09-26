F00AB068: 9de3bf98                 save    %sp, -0x68, %sp
F00AB06C: d2066004                 ld      [%i1+4], %o1
F00AB070: d006a004                 ld      [%i2+4], %o0
F00AB074: 80a24008                 cmp     %o1, %o0
F00AB078: 36800006                 bge,a   loc_F00AB090
F00AB07C: d0066004                 ld      [%i1+4], %o0
F00AB080: 9010001a                 mov     %i2, %o0
F00AB084: b4100019                 mov     %i1, %i2
F00AB088: b2100008                 mov     %o0, %i1
F00AB08C: d0066004                 ld      [%i1+4], %o0
F00AB090: 80a22002                 cmp     %o0, 2
F00AB094: 22800012                 be,a    loc_F00AB0DC
F00AB098: d0064000                 ld      [%i1], %o0
F00AB09C: 18800006                 bgu     loc_F00AB0B4
F00AB0A0: 80a22000                 cmp     %o0, 0
F00AB0A4: 2280000e                 be,a    loc_F00AB0DC
F00AB0A8: d0064000                 ld      [%i1], %o0
F00AB0AC: 10800008                 ba      loc_F00AB0CC
F00AB0B0: d006a004                 ld      [%i2+4], %o0
F00AB0B4: 80a22005                 cmp     %o0, 5
F00AB0B8: 18800004                 bgu     loc_F00AB0C8
F00AB0BC: 80a22004                 cmp     %o0, 4
F00AB0C0: 3a800007                 bcc,a   loc_F00AB0DC
F00AB0C4: d0064000                 ld      [%i1], %o0
F00AB0C8: d006a004                 ld      [%i2+4], %o0
F00AB0CC: 80a22000                 cmp     %o0, 0
F00AB0D0: 32800015                 bne,a   loc_F00AB124
F00AB0D4: d2066008                 ld      [%i1+8], %o1
F00AB0D8: d0064000                 ld      [%i1], %o0
F00AB0DC: d026c000                 st      %o0, [%i3]
F00AB0E0: d0066004                 ld      [%i1+4], %o0
F00AB0E4: d026e004                 st      %o0, [%i3+4]
F00AB0E8: d0066008                 ld      [%i1+8], %o0
F00AB0EC: d026e008                 st      %o0, [%i3+8]
F00AB0F0: d006600c                 ld      [%i1+0xC], %o0
F00AB0F4: d026e00c                 st      %o0, [%i3+0xC]
F00AB0F8: d0066010                 ld      [%i1+0x10], %o0
F00AB0FC: d026e010                 st      %o0, [%i3+0x10]
F00AB100: d0066014                 ld      [%i1+0x14], %o0
F00AB104: d026e014                 st      %o0, [%i3+0x14]
F00AB108: d0066018                 ld      [%i1+0x18], %o0
F00AB10C: d026e018                 st      %o0, [%i3+0x18]
F00AB110: d006601c                 ld      [%i1+0x1C], %o0
F00AB114: d026e01c                 st      %o0, [%i3+0x1C]
F00AB118: d0066020                 ld      [%i1+0x20], %o0
F00AB11C: 1080003d                 ba      locret_F00AB210
F00AB120: d026e020                 st      %o0, [%i3+0x20]
F00AB124: d006a008                 ld      [%i2+8], %o0
F00AB128: 80a24008                 cmp     %o1, %o0
F00AB12C: 36800006                 bge,a   loc_F00AB144
F00AB130: d0066004                 ld      [%i1+4], %o0
F00AB134: 9010001a                 mov     %i2, %o0
F00AB138: b4100019                 mov     %i1, %i2
F00AB13C: b2100008                 mov     %o0, %i1
F00AB140: d0066004                 ld      [%i1+4], %o0
F00AB144: d026e004                 st      %o0, [%i3+4]
F00AB148: d0064000                 ld      [%i1], %o0
F00AB14C: d026c000                 st      %o0, [%i3]
F00AB150: d0066008                 ld      [%i1+8], %o0
F00AB154: d026e008                 st      %o0, [%i3+8]
F00AB158: c026e020                 clr     [%i3+0x20]
F00AB15C: c026e01c                 clr     [%i3+0x1C]
F00AB160: d0066008                 ld      [%i1+8], %o0
F00AB164: d406a008                 ld      [%i2+8], %o2
F00AB168: 80a2000a                 cmp     %o0, %o2
F00AB16C: 2280000b                 be,a    loc_F00AB198
F00AB170: d2066018                 ld      [%i1+0x18], %o1
F00AB174: d206e008                 ld      [%i3+8], %o1
F00AB178: 9010001a                 mov     %i2, %o0
F00AB17C: 40000df9                 call    _fpu_rightshift
F00AB180: 9222400a                 sub     %o1, %o2, %o1
F00AB184: d006a01c                 ld      [%i2+0x1C], %o0
F00AB188: d026e01c                 st      %o0, [%i3+0x1C]
F00AB18C: d006a020                 ld      [%i2+0x20], %o0
F00AB190: d026e020                 st      %o0, [%i3+0x20]
F00AB194: d2066018                 ld      [%i1+0x18], %o1
F00AB198: 9006e018                 add     %i3, 0x18, %o0
F00AB19C: d406a018                 ld      [%i2+0x18], %o2
F00AB1A0: 40000e5f                 call    _fpu_add3wc
F00AB1A4: 96102000                 mov     0, %o3
F00AB1A8: d2066014                 ld      [%i1+0x14], %o1
F00AB1AC: 96100008                 mov     %o0, %o3
F00AB1B0: d406a014                 ld      [%i2+0x14], %o2
F00AB1B4: 40000e5a                 call    _fpu_add3wc
F00AB1B8: 9006e014                 add     %i3, 0x14, %o0
F00AB1BC: d2066010                 ld      [%i1+0x10], %o1
F00AB1C0: 96100008                 mov     %o0, %o3
F00AB1C4: d406a010                 ld      [%i2+0x10], %o2
F00AB1C8: 40000e55                 call    _fpu_add3wc
F00AB1CC: 9006e010                 add     %i3, 0x10, %o0
F00AB1D0: d206600c                 ld      [%i1+0xC], %o1
F00AB1D4: 96100008                 mov     %o0, %o3
F00AB1D8: d406a00c                 ld      [%i2+0xC], %o2
F00AB1DC: 40000e50                 call    _fpu_add3wc
F00AB1E0: 9006e00c                 add     %i3, 0xC, %o0
F00AB1E4: 1100007f                 sethi   0x1FC00, %o0
F00AB1E8: d206e00c                 ld      [%i3+0xC], %o1
F00AB1EC: 901223ff                 bset    0x3FF, %o0
F00AB1F0: 80a24008                 cmp     %o1, %o0
F00AB1F4: 08800007                 bleu    locret_F00AB210
F00AB1F8: 9010001b                 mov     %i3, %o0
F00AB1FC: 40000dd9                 call    _fpu_rightshift
F00AB200: 92102001                 mov     1, %o1
F00AB204: d006e008                 ld      [%i3+8], %o0
F00AB208: 90022001                 inc     %o0
F00AB20C: d026e008                 st      %o0, [%i3+8]
F00AB210: 81c7e008                 ret
F00AB214: 81e80000                 restore
