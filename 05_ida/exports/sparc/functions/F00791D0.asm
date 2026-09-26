F00791D0: 9de3bf98                 save    %sp, -0x68, %sp
F00791D4: d006202c                 ld      [%i0+0x2C], %o0
F00791D8: 80a22000                 cmp     %o0, 0
F00791DC: 16800006                 bge     loc_F00791F4
F00791E0: 01000000                 nop
F00791E4: 7fffbef8                 call    _lock_write
F00791E8: 90062030                 add     %i0, 0x30, %o0 ! '0'
F00791EC: 1080000f                 ba      loc_F0079228
F00791F0: 113c0443                 sethi   -0xFEEF400, %o0
F00791F4: 40007665                 call    _splusclock
F00791F8: 01000000                 nop
F00791FC: a0100008                 mov     %o0, %l0
F0079200: d0060000                 ld      [%i0], %o0
F0079204: 80a22000                 cmp     %o0, 0
F0079208: 12bffffe                 bne     loc_F0079200
F007920C: 01000000                 nop
F0079210: 40007726                 call    _simple_lock_try
F0079214: 90100018                 mov     %i0, %o0
F0079218: 80a22000                 cmp     %o0, 0
F007921C: 02bffff9                 be      loc_F0079200
F0079220: 113c0443                 sethi   -0xFEEF400, %o0
F0079224: e0262004                 st      %l0, [%i0+4]
F0079228: d002208c                 ld      [%o0+0x8C], %o0
F007922C: 80a22000                 cmp     %o0, 0
F0079230: 22800011                 be,a    loc_F0079274
F0079234: d006200c                 ld      [%i0+0xC], %o0
F0079238: e0062010                 ld      [%i0+0x10], %l0
F007923C: 80a42000                 cmp     %l0, 0
F0079240: 2280000d                 be,a    loc_F0079274
F0079244: d006200c                 ld      [%i0+0xC], %o0! char *
F0079248: 233c0443                 sethi   %hi(aZfree), %l1! "zfree"
F007924C: 80a40019                 cmp     %l0, %i1
F0079250: 32800005                 bne,a   loc_F0079264
F0079254: e0040000                 ld      [%l0], %l0
F0079258: 7ffe6fc6                 call    _panic
F007925C: 90146090                 or      %l1, %lo(aZfree), %o0! "zfree"
F0079260: e0040000                 ld      [%l0], %l0
F0079264: 80a42000                 cmp     %l0, 0
F0079268: 12bffffa                 bne     loc_F0079250
F007926C: 80a40019                 cmp     %l0, %i1
F0079270: d006200c                 ld      [%i0+0xC], %o0
F0079274: 80a22000                 cmp     %o0, 0
F0079278: 02800004                 be      loc_F0079288
F007927C: 80a64008                 cmp     %i1, %o0
F0079280: 18800007                 bgu     loc_F007929C
F0079284: 92100008                 mov     %o0, %o1
F0079288: 10800005                 ba      loc_F007929C
F007928C: 92062010                 add     %i0, 0x10, %o1
F0079290: 28800008                 bleu,a  loc_F00792B0
F0079294: d0264000                 st      %o0, [%i1]
F0079298: 92100008                 mov     %o0, %o1
F007929C: d0024000                 ld      [%o1], %o0
F00792A0: 80a22000                 cmp     %o0, 0
F00792A4: 12bffffb                 bne     loc_F0079290
F00792A8: 80a64008                 cmp     %i1, %o0
F00792AC: d0264000                 st      %o0, [%i1]
F00792B0: f2224000                 st      %i1, [%o1]
F00792B4: d0062008                 ld      [%i0+8], %o0
F00792B8: f226200c                 st      %i1, [%i0+0xC]
F00792BC: 90023fff                 inc     -1, %o0
F00792C0: d0262008                 st      %o0, [%i0+8]
F00792C4: d006202c                 ld      [%i0+0x2C], %o0
F00792C8: 80a22000                 cmp     %o0, 0
F00792CC: 36800005                 bge,a   loc_F00792E0
F00792D0: d0062004                 ld      [%i0+4], %o0
F00792D4: 7fffbf58                 call    _lock_done
F00792D8: 90062030                 add     %i0, 0x30, %o0 ! '0'
F00792DC: 30800004                 ba,a    locret_F00792EC
F00792E0: c0260000                 clr     [%i0]
F00792E4: 40007690                 call    _splx
F00792E8: 01000000                 nop
F00792EC: 81c7e008                 ret
F00792F0: 81e80000                 restore
