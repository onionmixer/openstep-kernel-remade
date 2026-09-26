F00CD82C: 9de3bf90                 save    %sp, -0x70, %sp
F00CD830: 9496c000                 orcc    %i3, %g0, %o2
F00CD834: 02800005                 be      loc_F00CD848
F00CD838: 133c0504                 sethi   -0xFEBF000, %o1
F00CD83C: d0068000                 ld      [%i2], %o0
F00CD840: 90122004                 bset    4, %o0! id
F00CD844: d0268000                 st      %o0, [%i2]
F00CD848: d2026194                 ld      [%o1+0x194], %o1! SEL
F00CD84C: 40009009                 call    _objc_msgSend
F00CD850: 90100018                 mov     %i0, %o0
F00CD854: d036a01c                 sth     %o0, [%i2+0x1C]
F00CD858: d206a014                 ld      [%i2+0x14], %o1
F00CD85C: 9010001a                 mov     %i2, %o0
F00CD860: 9222401c                 sub     %o1, %i4, %o1
F00CD864: 7ffd5e1b                 call    _biodone
F00CD868: d2222028                 st      %o1, [%o0+0x28]
F00CD86C: 81c7e008                 ret
F00CD870: 81e80000                 restore
