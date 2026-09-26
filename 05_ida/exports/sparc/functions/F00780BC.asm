F00780BC: 9de3bf98                 save    %sp, -0x68, %sp
F00780C0: 80a66000                 cmp     %i1, 0
F00780C4: 32800006                 bne,a   loc_F00780DC
F00780C8: d006202c                 ld      [%i0+0x2C], %o0
F00780CC: 113c0443                 sethi   %hi(aZcramMemoryAtZ), %o0! "zcram - memory at zero"
F00780D0: 7ffe7428                 call    _panic
F00780D4: 90122000                 bset    %lo(aZcramMemoryAtZ), %o0! "zcram - memory at zero"
F00780D8: d006202c                 ld      [%i0+0x2C], %o0
F00780DC: 80a22000                 cmp     %o0, 0
F00780E0: 16800006                 bge     loc_F00780F8
F00780E4: e206201c                 ld      [%i0+0x1C], %l1
F00780E8: 7fffc337                 call    _lock_write
F00780EC: 90062030                 add     %i0, 0x30, %o0 ! '0'
F00780F0: 1080000f                 ba      loc_F007812C
F00780F4: 80a68011                 cmp     %i2, %l1
F00780F8: 40007aa4                 call    _splusclock
F00780FC: 01000000                 nop
F0078100: a0100008                 mov     %o0, %l0
F0078104: d0060000                 ld      [%i0], %o0
F0078108: 80a22000                 cmp     %o0, 0
F007810C: 12bffffe                 bne     loc_F0078104
F0078110: 01000000                 nop
F0078114: 40007b65                 call    _simple_lock_try
F0078118: 90100018                 mov     %i0, %o0
F007811C: 80a22000                 cmp     %o0, 0
F0078120: 02bffff9                 be      loc_F0078104
F0078124: 80a68011                 cmp     %i2, %l1
F0078128: e0262004                 st      %l0, [%i0+4]
F007812C: 2a80001e                 bcs,a   loc_F00781A4
F0078130: d006202c                 ld      [%i0+0x2C], %o0
F0078134: d006200c                 ld      [%i0+0xC], %o0
F0078138: 80a22000                 cmp     %o0, 0
F007813C: 02800004                 be      loc_F007814C
F0078140: 80a64008                 cmp     %i1, %o0
F0078144: 18800007                 bgu     loc_F0078160
F0078148: 92100008                 mov     %o0, %o1
F007814C: 10800005                 ba      loc_F0078160
F0078150: 92062010                 add     %i0, 0x10, %o1
F0078154: 28800008                 bleu,a  loc_F0078174
F0078158: d0264000                 st      %o0, [%i1]
F007815C: 92100008                 mov     %o0, %o1
F0078160: d0024000                 ld      [%o1], %o0
F0078164: 80a22000                 cmp     %o0, 0
F0078168: 12bffffb                 bne     loc_F0078154
F007816C: 80a64008                 cmp     %i1, %o0
F0078170: d0264000                 st      %o0, [%i1]
F0078174: f2224000                 st      %i1, [%o1]
F0078178: d0062008                 ld      [%i0+8], %o0
F007817C: f226200c                 st      %i1, [%i0+0xC]
F0078180: d0262008                 st      %o0, [%i0+8]
F0078184: b4268011                 sub     %i2, %l1, %i2
F0078188: b2064011                 add     %i1, %l1, %i1
F007818C: d0062014                 ld      [%i0+0x14], %o0
F0078190: 80a68011                 cmp     %i2, %l1
F0078194: 90020011                 add     %o0, %l1, %o0
F0078198: 1abfffe7                 bcc     loc_F0078134
F007819C: d0262014                 st      %o0, [%i0+0x14]
F00781A0: d006202c                 ld      [%i0+0x2C], %o0
F00781A4: 80a22000                 cmp     %o0, 0
F00781A8: 36800005                 bge,a   loc_F00781BC
F00781AC: d0062004                 ld      [%i0+4], %o0
F00781B0: 7fffc3a1                 call    _lock_done
F00781B4: 90062030                 add     %i0, 0x30, %o0 ! '0'
F00781B8: 30800004                 ba,a    locret_F00781C8
F00781BC: c0260000                 clr     [%i0]
F00781C0: 40007ad9                 call    _splx
F00781C4: 01000000                 nop
F00781C8: 81c7e008                 ret
F00781CC: 81e80000                 restore
