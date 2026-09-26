F00921D0: 9de3bf98                 save    %sp, -0x68, %sp
F00921D4: a32e2010                 sll     %i0, 16, %l1
F00921D8: 40000317                 call    sub_F0092E34
F00921DC: 913c6010                 sra     %l1, 16, %o0
F00921E0: a0920000                 orcc    %o0, %g0, %l0
F00921E4: 0280000c                 be      loc_F0092214
F00921E8: 900e2007                 and     %i0, 7, %o0
F00921EC: 80a22007                 cmp     %o0, 7
F00921F0: 02800017                 be      loc_F009224C
F00921F4: 113c0504                 sethi   %hi(paIsinstanceopen), %o0! id
F00921F8: d2022174                 ld      [%o0+%lo(paIsinstanceopen)], %o1! SEL
F00921FC: 40017d9d                 call    _objc_msgSend
F0092200: 90100010                 mov     %l0, %o0
F0092204: 912a2018                 sll     %o0, 24, %o0
F0092208: 80a22000                 cmp     %o0, 0
F009220C: 12800004                 bne     loc_F009221C
F0092210: 113c04c4                 sethi   -0xFECF000, %o0
F0092214: 1080000f                 ba      locret_F0092250
F0092218: b0102006                 mov     6, %i0
F009221C: d2022240                 ld      [%o0+0x240], %o1
F0092220: 91346018                 srl     %l1, 24, %o0
F0092224: 80a20009                 cmp     %o0, %o1
F0092228: 12800005                 bne     loc_F009223C
F009222C: 90100010                 mov     %l0, %o0! id
F0092230: 133c0504                 sethi   %hi(paSetblockdevice), %o1
F0092234: 10800004                 ba      loc_F0092244
F0092238: d202616c                 ld      [%o1+%lo(paSetblockdevice)], %o1
F009223C: 133c0504                 sethi   %hi(paSetrawdeviceop), %o1
F0092240: d2026170                 ld      [%o1+%lo(paSetrawdeviceop)], %o1! SEL
F0092244: 40017d8b                 call    _objc_msgSend
F0092248: 94102000                 mov     0, %o2
F009224C: b0102000                 mov     0, %i0
F0092250: 81c7e008                 ret
F0092254: 81e80000                 restore
