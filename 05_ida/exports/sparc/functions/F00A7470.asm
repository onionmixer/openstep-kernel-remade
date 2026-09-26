F00A7470: 9de3bf70                 save    %sp, -0x90, %sp
F00A7474: c027bfd4                 clr     [%fp+var_2C]
F00A7478: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F00A747C: d0022070                 ld      [%o0+%lo(_in_ifaddr)], %o0
F00A7480: 80a22000                 cmp     %o0, 0
F00A7484: 02800009                 be      loc_F00A74A8
F00A7488: a2102000                 mov     0, %l1
F00A748C: d0022020                 ld      [%o0+0x20], %o0
F00A7490: d012200c                 lduh    [%o0+0xC], %o0
F00A7494: 808a2008                 btst    8, %o0
F00A7498: 12800005                 bne     loc_F00A74AC
F00A749C: 113c04c5                 sethi   -0xFECEC00, %o0
F00A74A0: 1080005e                 ba      locret_F00A7618
F00A74A4: b0102000                 mov     0, %i0
F00A74A8: 113c04c5                 sethi   -0xFECEC00, %o0
F00A74AC: d4022160                 ld      [%o0+0x160], %o2
F00A74B0: d052a004                 ldsh    [%o2+4], %o0
F00A74B4: 80a23fff                 cmp     %o0, -1
F00A74B8: 02800016                 be      loc_F00A7510
F00A74BC: 113c046c                 sethi   %hi(off_F011B108), %o0
F00A74C0: d2022108                 ld      [%o0+%lo(off_F011B108)], %o1
F00A74C4: 80a26000                 cmp     %o1, 0
F00A74C8: 02800013                 be      loc_F00A7514
F00A74CC: a0122108                 or      %o0, %lo(off_F011B108), %l0
F00A74D0: 313c04fb                 sethi   -0xFEC1400, %i0
F00A74D4: d0542004                 ldsh    [%l0+4], %o0
F00A74D8: 80a23fff                 cmp     %o0, -1
F00A74DC: 32800007                 bne,a   loc_F00A74F8
F00A74E0: a0042008                 inc     8, %l0
F00A74E4: d0040000                 ld      [%l0], %o0
F00A74E8: d4062088                 ld      [%i0+0x88], %o2
F00A74EC: 40002f31                 call    _path_findnodebyname
F00A74F0: 92102000                 mov     0, %o1
F00A74F4: a0042008                 inc     8, %l0
F00A74F8: d0040000                 ld      [%l0], %o0
F00A74FC: 80a22000                 cmp     %o0, 0
F00A7500: 32bffff6                 bne,a   loc_F00A74D8
F00A7504: d0542004                 ldsh    [%l0+4], %o0
F00A7508: 10800005                 ba      loc_F00A751C
F00A750C: d20a0000                 ldub    [%o0], %o1
F00A7510: a010000a                 mov     %o2, %l0
F00A7514: d0040000                 ld      [%l0], %o0
F00A7518: d20a0000                 ldub    [%o0], %o1
F00A751C: d22fbfd8                 stb     %o1, [%fp+var_28]
F00A7520: d4040000                 ld      [%l0], %o2
F00A7524: 90102002                 mov     2, %o0
F00A7528: d60aa001                 ldub    [%o2+1], %o3
F00A752C: 9207bfd4                 add     %fp, var_2C, %o1
F00A7530: 94102002                 mov     2, %o2
F00A7534: d62fbfd9                 stb     %o3, [%fp+var_27]
F00A7538: 96102030                 mov     0x30, %o3 ! '0'
F00A753C: d62fbfda                 stb     %o3, [%fp+var_26]
F00A7540: c02fbfdb                 clrb    [%fp+var_25]
F00A7544: 7ffddc2a                 call    _socreate
F00A7548: 96102000                 mov     0, %o3
F00A754C: b0920000                 orcc    %o0, %g0, %i0
F00A7550: 02800006                 be      loc_F00A7568
F00A7554: 113c046c                 sethi   %hi(aInitrootnetSoc), %o0! "initrootnet: socreate failed\n"
F00A7558: 7ffdb440                 call    _printf
F00A755C: 901222a8                 bset    %lo(aInitrootnetSoc), %o0! "initrootnet: socreate failed\n"
F00A7560: 10800029                 ba      loc_F00A7604
F00A7564: d007bfd4                 ld      [%fp+var_2C], %o0
F00A7568: 90102002                 mov     2, %o0
F00A756C: d037bfe8                 sth     %o0, [%fp+var_18]
F00A7570: 2730081a                 sethi   -0x3FDF9800, %l3
F00A7574: 213c046c                 sethi   -0xFEE5000, %l0
F00A7578: 253c046c                 sethi   -0xFEE5000, %l2
F00A757C: d007bfd4                 ld      [%fp+var_2C], %o0
F00A7580: 9214e121                 or      %l3, 0x121, %o1
F00A7584: 7ffe09b6                 call    _ifioctl
F00A7588: 9407bfd8                 add     %fp, var_28, %o2
F00A758C: b0920000                 orcc    %o0, %g0, %i0
F00A7590: 0280000e                 be      loc_F00A75C8
F00A7594: 80a6203c                 cmp     %i0, 0x3C ! '<'
F00A7598: 12800008                 bne     loc_F00A75B8
F00A759C: 80a46000                 cmp     %l1, 0
F00A75A0: 12bffff8                 bne     loc_F00A7580
F00A75A4: d007bfd4                 ld      [%fp+var_2C], %o0! char *
F00A75A8: 7ffdb42c                 call    _printf
F00A75AC: 901422c8                 or      %l0, 0x2C8, %o0! char *
F00A75B0: 10bffff3                 ba      loc_F00A757C
F00A75B4: a2102001                 mov     1, %l1
F00A75B8: 7ffdb428                 call    _printf
F00A75BC: 9014a2f8                 or      %l2, 0x2F8, %o0
F00A75C0: 10800011                 ba      loc_F00A7604
F00A75C4: d007bfd4                 ld      [%fp+var_2C], %o0
F00A75C8: 80a46000                 cmp     %l1, 0
F00A75CC: 02800004                 be      loc_F00A75DC
F00A75D0: 113c046c                 sethi   %hi(aInitrootnetBoo), %o0! "initrootnet: BOOTP [OK].\n"
F00A75D4: 7ffdb421                 call    _printf
F00A75D8: 90122318                 bset    %lo(aInitrootnetBoo), %o0! "initrootnet: BOOTP [OK].\n"
F00A75DC: 9007bfec                 add     %fp, var_14, %o0! in_addr
F00A75E0: 213c046ca0142338         set     aPrimaryNetwork, %l0! "primary network interface: %s [%s]\n"
F00A75E8: 7ffe1f6b                 call    _inet_ntoa
F00A75EC: a207bfd8                 add     %fp, var_28, %l1
F00A75F0: 94100008                 mov     %o0, %o2
F00A75F4: 90100010                 mov     %l0, %o0! char *
F00A75F8: 7ffdb418                 call    _printf
F00A75FC: 92100011                 mov     %l1, %o1
F00A7600: d007bfd4                 ld      [%fp+var_2C], %o0
F00A7604: 80a22000                 cmp     %o0, 0
F00A7608: 02800004                 be      locret_F00A7618
F00A760C: 01000000                 nop
F00A7610: 7ffddc8d                 call    _soclose
F00A7614: 01000000                 nop
F00A7618: 81c7e008                 ret
F00A761C: 81e80000                 restore
