F00AA060: 9de3bf98                 save    %sp, -0x68, %sp
F00AA064: 113c04cf                 sethi   -0xFECC400, %o0
F00AA068: aa100008                 mov     %o0, %l5
F00AA06C: 113ff7ffae1223ff         set     -0x200001, %l7
F00AA074: 113c04d0                 sethi   %hi(_active_threads), %o0
F00AA078: 2d3c04cf                 sethi   %hi(_need_ast), %l6
F00AA07C: e4022260                 ld      [%o0+%lo(_active_threads)], %l2
F00AA080: a615a160                 or      %l6, %lo(_need_ast), %l3
F00AA084: d00561d8                 ld      [%l5+0x1D8], %o0
F00AA088: a2102000                 mov     0, %l1
F00AA08C: e0020000                 ld      [%o0], %l0
F00AA090: e805a160                 ld      [%l6+0x160], %l4
F00AA094: 80a42000                 cmp     %l0, 0
F00AA098: 02800037                 be      loc_F00AA174
F00AA09C: 11000800                 sethi   0x200000, %o0
F00AA0A0: d2042028                 ld      [%l0+0x28], %o1
F00AA0A4: 808a4008                 btst    %o0, %o1
F00AA0A8: 0280000c                 be      loc_F00AA0D8
F00AA0AC: d20561d8                 ld      [%l5+0x1D8], %o1
F00AA0B0: d0026258                 ld      [%o1+0x258], %o0
F00AA0B4: 80a22000                 cmp     %o0, 0
F00AA0B8: 02800008                 be      loc_F00AA0D8
F00AA0BC: 92026244                 inc     0x244, %o1
F00AA0C0: d0062004                 ld      [%i0+4], %o0
F00AA0C4: 7fffbf45                 call    _addupc
F00AA0C8: 94102001                 mov     1, %o2
F00AA0CC: d0042028                 ld      [%l0+0x28], %o0
F00AA0D0: 900a0017                 and     %o0, %l7, %o0
F00AA0D4: d0242028                 st      %o0, [%l0+0x28]
F00AA0D8: d0044013                 ld      [%l1+%l3], %o0
F00AA0DC: 900a3fdf                 and     %o0, -0x21, %o0
F00AA0E0: d0244013                 st      %o0, [%l1+%l3]
F00AA0E4: d0044013                 ld      [%l1+%l3], %o0
F00AA0E8: d004a18c                 ld      [%l2+0x18C], %o0
F00AA0EC: 808a2003                 btst    3, %o0
F00AA0F0: 12800021                 bne     loc_F00AA174
F00AA0F4: 01000000                 nop
F00AA0F8: d04c2017                 ldsb    [%l0+0x17], %o0
F00AA0FC: 80a22000                 cmp     %o0, 0
F00AA100: 12800014                 bne     loc_F00AA150
F00AA104: 01000000                 nop
F00AA108: d004a084                 ld      [%l2+0x84], %o0
F00AA10C: d2042018                 ld      [%l0+0x18], %o1
F00AA110: d002204c                 ld      [%o0+0x4C], %o0
F00AA114: 94924008                 orcc    %o1, %o0, %o2
F00AA118: 02800017                 be      loc_F00AA174
F00AA11C: 01000000                 nop
F00AA120: d0042028                 ld      [%l0+0x28], %o0
F00AA124: 808a2010                 btst    0x10, %o0
F00AA128: 32800009                 bne,a   loc_F00AA14C
F00AA12C: d04c2017                 ldsb    [%l0+0x17], %o0
F00AA130: d0042020                 ld      [%l0+0x20], %o0
F00AA134: d204201c                 ld      [%l0+0x1C], %o1
F00AA138: 90120009                 bset    %o1, %o0
F00AA13C: 80aa8008                 andncc  %o2, %o0, %g0
F00AA140: 0280000d                 be      loc_F00AA174
F00AA144: 01000000                 nop
F00AA148: d04c2017                 ldsb    [%l0+0x17], %o0
F00AA14C: 80a22000                 cmp     %o0, 0
F00AA150: 12800007                 bne     loc_F00AA16C
F00AA154: 01000000                 nop
F00AA158: 7ffd9e16                 call    _issig
F00AA15C: 90102000                 mov     0, %o0
F00AA160: 80a22000                 cmp     %o0, 0
F00AA164: 02800004                 be      loc_F00AA174
F00AA168: 01000000                 nop
F00AA16C: 7ffd9f78                 call    _psig
F00AA170: 01000000                 nop
F00AA174: d0044013                 ld      [%l1+%l3], %o0
F00AA178: 902a0014                 bclr    %l4, %o0
F00AA17C: d0244013                 st      %o0, [%l1+%l3]
F00AA180: d0044013                 ld      [%l1+%l3], %o0
F00AA184: d004a18c                 ld      [%l2+0x18C], %o0
F00AA188: 808a2003                 btst    3, %o0
F00AA18C: 02800004                 be      loc_F00AA19C
F00AA190: 808d2004                 btst    4, %l4
F00AA194: 7fff2bde                 call    _thread_halt_self
F00AA198: 9e03fef4                 inc     -0x10C, %o7
F00AA19C: 12800032                 bne     loc_F00AA264
F00AA1A0: d40561d8                 ld      [%l5+0x1D8], %o2
F00AA1A4: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F00AA1A8: d00221b0                 ld      [%o0+%lo(_processor_ptr)], %o0
F00AA1AC: d404a04c                 ld      [%l2+0x4C], %o2
F00AA1B0: d202212c                 ld      [%o0+0x12C], %o1
F00AA1B4: d8022108                 ld      [%o0+0x108], %o4
F00AA1B8: c4022124                 ld      [%o0+0x124], %g2
F00AA1BC: da026108                 ld      [%o1+0x108], %o5
F00AA1C0: d6026104                 ld      [%o1+0x104], %o3
F00AA1C4: d004a060                 ld      [%l2+0x60], %o0
F00AA1C8: 808aa002                 btst    2, %o2
F00AA1CC: 12800020                 bne     loc_F00AA24C
F00AA1D0: d204a058                 ld      [%l2+0x58], %o1
F00AA1D4: 80a32000                 cmp     %o4, 0
F00AA1D8: 34800020                 bg,a    loc_F00AA258
F00AA1DC: 90102001                 mov     1, %o0
F00AA1E0: 80a22002                 cmp     %o0, 2
F00AA1E4: 22800007                 be,a    loc_F00AA200
F00AA1E8: 80a36000                 cmp     %o5, 0
F00AA1EC: 14800005                 bg      loc_F00AA200
F00AA1F0: 80a36000                 cmp     %o5, 0
F00AA1F4: 80a22001                 cmp     %o0, 1
F00AA1F8: 0280000d                 be      loc_F00AA22C
F00AA1FC: 80a36000                 cmp     %o5, 0
F00AA200: 02800015                 be      loc_F00AA254
F00AA204: 80a2c009                 cmp     %o3, %o1
F00AA208: 06800014                 bl      loc_F00AA258
F00AA20C: 90102000                 mov     0, %o0
F00AA210: 14800012                 bg      loc_F00AA258
F00AA214: 90102001                 mov     1, %o0
F00AA218: 80a0a000                 cmp     %g2, 0
F00AA21C: 1280000f                 bne     loc_F00AA258
F00AA220: 90102000                 mov     0, %o0
F00AA224: 1080000d                 ba      loc_F00AA258
F00AA228: 90102001                 mov     1, %o0
F00AA22C: 80a0a000                 cmp     %g2, 0
F00AA230: 1280000a                 bne     loc_F00AA258
F00AA234: 90102000                 mov     0, %o0
F00AA238: 80a36000                 cmp     %o5, 0
F00AA23C: 04800007                 ble     loc_F00AA258
F00AA240: 80a2c009                 cmp     %o3, %o1
F00AA244: 06800006                 bl      loc_F00AA25C
F00AA248: 80a22000                 cmp     %o0, 0
F00AA24C: 10800003                 ba      loc_F00AA258
F00AA250: 90102001                 mov     1, %o0
F00AA254: 90102000                 mov     0, %o0
F00AA258: 80a22000                 cmp     %o0, 0
F00AA25C: 02800009                 be      locret_F00AA280
F00AA260: d40561d8                 ld      [%l5+0x1D8], %o2
F00AA264: 113c026f                 sethi   %hi(_thread_exception_return), %o0
F00AA268: d202a1b0                 ld      [%o2+0x1B0], %o1
F00AA26C: 901223e4                 bset    %lo(_thread_exception_return), %o0
F00AA270: 92026001                 inc     %o1
F00AA274: 7fff1d33                 call    _thread_block_with_continuation
F00AA278: d222a1b0                 st      %o1, [%o2+0x1B0]
F00AA27C: 30bfff85                 ba,a    loc_F00AA090
F00AA280: 81c7e008                 ret
F00AA284: 81e80000                 restore
