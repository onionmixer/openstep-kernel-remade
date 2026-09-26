F00A12B0: 9de3bf98                 save    %sp, -0x68, %sp
F00A12B4: 213c04f794142270         set     _pmap_info, %o2
F00A12BC: d002a030                 ld      [%o2+0x30], %o0
F00A12C0: 133c0464                 sethi   %hi(_vac), %o1
F00A12C4: d2026334                 ld      [%o1+%lo(_vac)], %o1
F00A12C8: 90022001                 inc     %o0
F00A12CC: 80a26000                 cmp     %o1, 0
F00A12D0: 02800039                 be      locret_F00A13B4
F00A12D4: d022a030                 st      %o0, [%o2+0x30]
F00A12D8: 113c0464                 sethi   %hi(_physmaxpfn), %o0
F00A12DC: d002238c                 ld      [%o0+%lo(_physmaxpfn)], %o0
F00A12E0: 80a60008                 cmp     %i0, %o0
F00A12E4: 1a800034                 bcc     locret_F00A13B4
F00A12E8: b12e200c                 sll     %i0, 12, %i0
F00A12EC: 7fff9439                 call    _vm_valid_page
F00A12F0: 90100018                 mov     %i0, %o0
F00A12F4: 80a22000                 cmp     %o0, 0
F00A12F8: 0280002f                 be      locret_F00A13B4
F00A12FC: 01000000                 nop
F00A1300: 7fffd67f                 call    _splvm
F00A1304: 01000000                 nop
F00A1308: aa100008                 mov     %o0, %l5
F00A130C: 7fff940b                 call    _vm_mem_ppi
F00A1310: 90100018                 mov     %i0, %o0
F00A1314: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F00A1318: 932a2002                 sll     %o0, 2, %o1
F00A131C: 92024008                 add     %o1, %o0, %o1
F00A1320: d002a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o0
F00A1324: 932a6002                 sll     %o1, 2, %o1
F00A1328: a4020009                 add     %o0, %o1, %l2
F00A132C: d004a004                 ld      [%l2+4], %o0
F00A1330: 80a22000                 cmp     %o0, 0
F00A1334: 0280001e                 be      loc_F00A13AC
F00A1338: 80a4a000                 cmp     %l2, 0
F00A133C: 0280001c                 be      loc_F00A13AC
F00A1340: 01000000                 nop
F00A1344: a8100010                 mov     %l0, %l4
F00A1348: 27000004                 sethi   0x1000, %l3
F00A134C: d204a008                 ld      [%l2+8], %o1
F00A1350: a2102000                 mov     0, %l1
F00A1354: d004a004                 ld      [%l2+4], %o0
F00A1358: 93326008                 srl     %o1, 8, %o1
F00A135C: 7fffffbd                 call    _get_context
F00A1360: a12a600c                 sll     %o1, 12, %l0
F00A1364: b0100008                 mov     %o0, %i0
F00A1368: 80a63fff                 cmp     %i0, -1
F00A136C: 2280000d                 be,a    loc_F00A13A0
F00A1370: e4048000                 ld      [%l2], %l2
F00A1374: d0152270                 lduh    [%l4+0x270], %o0
F00A1378: 80a44008                 cmp     %l1, %o0
F00A137C: 16800008                 bge     loc_F00A139C
F00A1380: 90100010                 mov     %l0, %o0
F00A1384: 7fffd178                 call    _vac_pagectxflush
F00A1388: 92100018                 mov     %i0, %o1
F00A138C: a0040013                 add     %l0, %l3, %l0
F00A1390: 80a63fff                 cmp     %i0, -1
F00A1394: 12bffff8                 bne     loc_F00A1374
F00A1398: a2046001                 inc     %l1
F00A139C: e4048000                 ld      [%l2], %l2
F00A13A0: 80a4a000                 cmp     %l2, 0
F00A13A4: 32bfffeb                 bne,a   loc_F00A1350
F00A13A8: d204a008                 ld      [%l2+8], %o1
F00A13AC: 7fffd65e                 call    _splx
F00A13B0: 90100015                 mov     %l5, %o0
F00A13B4: 81c7e008                 ret
F00A13B8: 81e80000                 restore
