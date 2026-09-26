F00B1410: 9de3bf78                 save    %sp, -0x88, %sp
F00B1414: 213c04f8                 sethi   %hi(_cpu), %l0
F00B1418: 90103fff                 mov     -1, %o0
F00B141C: d0242120                 st      %o0, [%l0+%lo(_cpu)]
F00B1420: 9007bfd8                 add     %fp, var_28, %o0
F00B1424: 7ffff73b                 call    _prom_getidprom
F00B1428: 92102020                 mov     0x20, %o1 ! ' '
F00B142C: d20fbfd8                 ldub    [%fp+var_28], %o1
F00B1430: 80a26001                 cmp     %o1, 1
F00B1434: 12800005                 bne     loc_F00B1448
F00B1438: 80a26080                 cmp     %o1, 0x80
F00B143C: d00fbfd9                 ldub    [%fp+var_27], %o0
F00B1440: 10800008                 ba      loc_F00B1460
F00B1444: d0242120                 st      %o0, [%l0+%lo(_cpu)]
F00B1448: 12800004                 bne     loc_F00B1458
F00B144C: 113c0471                 sethi   -0xFEE3C00, %o0! char *
F00B1450: 10800004                 ba      loc_F00B1460
F00B1454: d2242120                 st      %o1, [%l0+0x120]
F00B1458: 7ffd8c80                 call    _printf
F00B145C: 90122308                 bset    0x308, %o0
F00B1460: 113c04f8                 sethi   %hi(_cpu), %o0
F00B1464: d0022120                 ld      [%o0+%lo(_cpu)], %o0
F00B1468: 80a22072                 cmp     %o0, 0x72 ! 'r'
F00B146C: 2280000f                 be,a    loc_F00B14A8
F00B1470: 113c04f8                 sethi   -0xFEC2000, %o0
F00B1474: 04800004                 ble     loc_F00B1484
F00B1478: 80a22080                 cmp     %o0, 0x80
F00B147C: 2280000b                 be,a    loc_F00B14A8
F00B1480: 113c04f8                 sethi   -0xFEC2000, %o0
F00B1484: 113c04f8                 sethi   %hi(_cpu), %o0
F00B1488: d2022120                 ld      [%o0+%lo(_cpu)], %o1
F00B148C: 113c0471                 sethi   %hi(aMachineType0xX), %o0! "machine type 0x%x in NVRAM\n"
F00B1490: 7ffd8c72                 call    _printf
F00B1494: 90122330                 bset    %lo(aMachineType0xX), %o0! "machine type 0x%x in NVRAM\n"
F00B1498: 113c0471                 sethi   %hi(aNoKnownMachine), %o0! "No known machine types configured in!\n"
F00B149C: 7ffd8f35                 call    _panic
F00B14A0: 90122350                 bset    %lo(aNoKnownMachine), %o0! "No known machine types configured in!\n"
F00B14A4: 113c04f8                 sethi   -0xFEC2000, %o0
F00B14A8: d2022120                 ld      [%o0+0x120], %o1
F00B14AC: 113c044a                 sethi   %hi(_mach_info), %o0
F00B14B0: d2222238                 st      %o1, [%o0+%lo(_mach_info)]
F00B14B4: 81c7e008                 ret
F00B14B8: 81e80000                 restore
