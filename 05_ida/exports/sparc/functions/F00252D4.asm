F00252D4: 9de3bf98                 save    %sp, -0x68, %sp
F00252D8: 4001c62c                 call    _splusclock
F00252DC: 01000000                 nop
F00252E0: 133c04cf921261e0         set     _bfreelist, %o1
F00252E8: 940260cc                 add     %o1, 0xCC, %o2
F00252EC: 80a2400a                 cmp     %o1, %o2
F00252F0: 1a800036                 bcc     loc_F00253C8
F00252F4: a2100008                 mov     %o0, %l1
F00252F8: 912e6010                 sll     %i1, 16, %o0
F00252FC: 973a2010                 sra     %o0, 16, %o3
F0025300: 9810000a                 mov     %o2, %o4
F0025304: e002600c                 ld      [%o1+0xC], %l0
F0025308: 80a40009                 cmp     %l0, %o1
F002530C: 2280002c                 be,a    loc_F00253BC
F0025310: 92026044                 inc     0x44, %o1 ! 'D'
F0025314: 80a2ffff                 cmp     %o3, -1
F0025318: 2280000a                 be,a    loc_F0025340
F002531C: d4040000                 ld      [%l0], %o2
F0025320: d014201e                 lduh    [%l0+0x1E], %o0
F0025324: 900a001a                 and     %o0, %i2, %o0
F0025328: 912a2010                 sll     %o0, 16, %o0
F002532C: 913a2010                 sra     %o0, 16, %o0
F0025330: 80a2c008                 cmp     %o3, %o0
F0025334: 3280001e                 bne,a   loc_F00253AC
F0025338: e004200c                 ld      [%l0+0xC], %l0
F002533C: d4040000                 ld      [%l0], %o2
F0025340: 808aa200                 btst    0x200, %o2
F0025344: 2280001a                 be,a    loc_F00253AC
F0025348: e004200c                 ld      [%l0+0xC], %l0
F002534C: d0042040                 ld      [%l0+0x40], %o0
F0025350: 80a60008                 cmp     %i0, %o0
F0025354: 02800004                 be      loc_F0025364
F0025358: 80a62000                 cmp     %i0, 0
F002535C: 32800014                 bne,a   loc_F00253AC
F0025360: e004200c                 ld      [%l0+0xC], %l0
F0025364: 9012a100                 or      %o2, 0x100, %o0
F0025368: 4001c614                 call    _spltty
F002536C: d0240000                 st      %o0, [%l0]
F0025370: d4042010                 ld      [%l0+0x10], %o2
F0025374: d204200c                 ld      [%l0+0xC], %o1
F0025378: d222a00c                 st      %o1, [%o2+0xC]
F002537C: d404200c                 ld      [%l0+0xC], %o2
F0025380: d2042010                 ld      [%l0+0x10], %o1
F0025384: d222a010                 st      %o1, [%o2+0x10]
F0025388: d2040000                 ld      [%l0], %o1
F002538C: 92126008                 bset    8, %o1
F0025390: 4001c665                 call    _splx
F0025394: d2240000                 st      %o1, [%l0]
F0025398: 4001c663                 call    _splx
F002539C: 90100011                 mov     %l1, %o0
F00253A0: 7ffffcf2                 call    _bwrite
F00253A4: 90100010                 mov     %l0, %o0
F00253A8: 30bfffcc                 ba,a    loc_F00252D8
F00253AC: 80a40009                 cmp     %l0, %o1
F00253B0: 12bfffda                 bne     loc_F0025318
F00253B4: 80a2ffff                 cmp     %o3, -1
F00253B8: 92026044                 inc     0x44, %o1 ! 'D'
F00253BC: 80a2400c                 cmp     %o1, %o4
F00253C0: 2abfffd2                 bcs,a   loc_F0025308
F00253C4: e002600c                 ld      [%o1+0xC], %l0
F00253C8: 4001c657                 call    _splx
F00253CC: 90100011                 mov     %l1, %o0
F00253D0: 81c7e008                 ret
F00253D4: 81e80000                 restore
