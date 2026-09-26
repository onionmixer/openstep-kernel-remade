F003D02C: 9de3bf98                 save    %sp, -0x68, %sp
F003D030: b6100018                 mov     %i0, %i3
F003D034: c40ee04a                 ldub    [%i3+0x4A], %g2
F003D038: f00ee04b                 ldub    [%i3+0x4B], %i0
F003D03C: c60ee04c                 ldub    [%i3+0x4C], %g3
F003D040: f20ee059                 ldub    [%i3+0x59], %i1
F003D044: 84188018                 btog    %i0, %g2
F003D048: f00ee04d                 ldub    [%i3+0x4D], %i0
F003D04C: 8618c002                 btog    %g2, %g3
F003D050: c40ee04e                 ldub    [%i3+0x4E], %g2
F003D054: b01e0003                 btog    %g3, %i0
F003D058: c60ee04f                 ldub    [%i3+0x4F], %g3
F003D05C: 84188018                 btog    %i0, %g2
F003D060: f00ee050                 ldub    [%i3+0x50], %i0
F003D064: 8618c002                 btog    %g2, %g3
F003D068: c40ee051                 ldub    [%i3+0x51], %g2
F003D06C: b01e0003                 btog    %g3, %i0
F003D070: c60ee054                 ldub    [%i3+0x54], %g3
F003D074: 84188018                 btog    %i0, %g2
F003D078: f00ee055                 ldub    [%i3+0x55], %i0
F003D07C: 8618c002                 btog    %g2, %g3
F003D080: c40ee056                 ldub    [%i3+0x56], %g2
F003D084: b01e0003                 btog    %g3, %i0
F003D088: c60ee057                 ldub    [%i3+0x57], %g3
F003D08C: 84188018                 btog    %i0, %g2
F003D090: f00ee058                 ldub    [%i3+0x58], %i0
F003D094: 8618c002                 btog    %g2, %g3
F003D098: b01e0003                 btog    %g3, %i0
F003D09C: c60ee05a                 ldub    [%i3+0x5A], %g3
F003D0A0: b21e4018                 btog    %i0, %i1
F003D0A4: c40ee05b                 ldub    [%i3+0x5B], %g2
F003D0A8: 8618c019                 btog    %i1, %g3
F003D0AC: 84188003                 btog    %g3, %g2
F003D0B0: 8408a03f                 and     %g2, 0x3F, %g2
F003D0B4: 073c04ea8610e2a0         set     _rtable, %g3
F003D0BC: 8528a002                 sll     %g2, 2, %g2
F003D0C0: f4008003                 ld      [%g2+%g3], %i2
F003D0C4: 80a6a000                 cmp     %i2, 0
F003D0C8: 02800037                 be      locret_F003D1A4
F003D0CC: b0102000                 mov     0, %i0
F003D0D0: ba100003                 mov     %g3, %i5
F003D0D4: 393c04ea                 sethi   -0xFEC5800, %i4
F003D0D8: 80a6801b                 cmp     %i2, %i3
F003D0DC: 3280002e                 bne,a   loc_F003D194
F003D0E0: b010001a                 mov     %i2, %i0
F003D0E4: 80a62000                 cmp     %i0, 0
F003D0E8: 32800026                 bne,a   loc_F003D180
F003D0EC: c406a008                 ld      [%i2+8], %g2
F003D0F0: c40ea04a                 ldub    [%i2+0x4A], %g2
F003D0F4: f00ea04b                 ldub    [%i2+0x4B], %i0
F003D0F8: c60ea04c                 ldub    [%i2+0x4C], %g3
F003D0FC: f20ea059                 ldub    [%i2+0x59], %i1
F003D100: 84188018                 btog    %i0, %g2
F003D104: f00ea04d                 ldub    [%i2+0x4D], %i0
F003D108: 8618c002                 btog    %g2, %g3
F003D10C: c40ea04e                 ldub    [%i2+0x4E], %g2
F003D110: b01e0003                 btog    %g3, %i0
F003D114: c60ea04f                 ldub    [%i2+0x4F], %g3
F003D118: 84188018                 btog    %i0, %g2
F003D11C: f00ea050                 ldub    [%i2+0x50], %i0
F003D120: 8618c002                 btog    %g2, %g3
F003D124: c40ea051                 ldub    [%i2+0x51], %g2
F003D128: b01e0003                 btog    %g3, %i0
F003D12C: c60ea054                 ldub    [%i2+0x54], %g3
F003D130: 84188018                 btog    %i0, %g2
F003D134: f00ea055                 ldub    [%i2+0x55], %i0
F003D138: 8618c002                 btog    %g2, %g3
F003D13C: c40ea056                 ldub    [%i2+0x56], %g2
F003D140: b01e0003                 btog    %g3, %i0
F003D144: c60ea057                 ldub    [%i2+0x57], %g3
F003D148: 84188018                 btog    %i0, %g2
F003D14C: f00ea058                 ldub    [%i2+0x58], %i0
F003D150: 8618c002                 btog    %g2, %g3
F003D154: b01e0003                 btog    %g3, %i0
F003D158: c60ea05a                 ldub    [%i2+0x5A], %g3
F003D15C: b21e4018                 btog    %i0, %i1
F003D160: c40ea05b                 ldub    [%i2+0x5B], %g2
F003D164: 8618c019                 btog    %i1, %g3
F003D168: 84188003                 btog    %g3, %g2
F003D16C: 8408a03f                 and     %g2, 0x3F, %g2
F003D170: c606a008                 ld      [%i2+8], %g3
F003D174: 8528a002                 sll     %g2, 2, %g2
F003D178: 10800003                 ba      loc_F003D184
F003D17C: c620801d                 st      %g3, [%g2+%i5]
F003D180: c4262008                 st      %g2, [%i0+8]
F003D184: c4072278                 ld      [%i4+0x278], %g2
F003D188: 8400bfff                 inc     -1, %g2
F003D18C: 10800006                 ba      locret_F003D1A4
F003D190: c4272278                 st      %g2, [%i4+0x278]
F003D194: f406a008                 ld      [%i2+8], %i2
F003D198: 80a6a000                 cmp     %i2, 0
F003D19C: 12bfffd0                 bne     loc_F003D0DC
F003D1A0: 80a6801b                 cmp     %i2, %i3
F003D1A4: 81c7e008                 ret
F003D1A8: 81e80000                 restore
