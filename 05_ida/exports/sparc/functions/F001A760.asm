F001A760: 9de3bf98                 save    %sp, -0x68, %sp
F001A764: 80a62000                 cmp     %i0, 0
F001A768: 0680001b                 bl      locret_F001A7D4
F001A76C: 113c042e                 sethi   %hi(_nldisp), %o0
F001A770: d00222ac                 ld      [%o0+%lo(_nldisp)], %o0
F001A774: 80a60008                 cmp     %i0, %o0
F001A778: 16800017                 bge     locret_F001A7D4
F001A77C: 01000000                 nop
F001A780: 4001f10e                 call    _spltty
F001A784: 01000000                 nop
F001A788: 133c042e921260cc         set     _linesw, %o1
F001A790: 952e2001                 sll     %i0, 1, %o2
F001A794: 94028018                 add     %o2, %i0, %o2
F001A798: 952aa004                 sll     %o2, 4, %o2
F001A79C: 173c00559612e040         set     _nodev, %o3
F001A7A4: d6228009                 st      %o3, [%o2+%o1]
F001A7A8: 94028009                 add     %o2, %o1, %o2
F001A7AC: d622a004                 st      %o3, [%o2+4]
F001A7B0: d622a008                 st      %o3, [%o2+8]
F001A7B4: d622a00c                 st      %o3, [%o2+0xC]
F001A7B8: d622a010                 st      %o3, [%o2+0x10]
F001A7BC: d622a014                 st      %o3, [%o2+0x14]
F001A7C0: d622a018                 st      %o3, [%o2+0x18]
F001A7C4: d622a020                 st      %o3, [%o2+0x20]
F001A7C8: d622a024                 st      %o3, [%o2+0x24]
F001A7CC: 4001f156                 call    _splx
F001A7D0: d622a028                 st      %o3, [%o2+0x28]
F001A7D4: 81c7e008                 ret
F001A7D8: 81e80000                 restore
