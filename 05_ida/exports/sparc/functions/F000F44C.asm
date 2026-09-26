F000F44C: 9de3bf98                 save    %sp, -0x68, %sp
F000F450: 293c04cf901521dc         set     dword_F0133DDC, %o0
F000F458: d2023ffc                 ld      [%o0-4], %o1
F000F45C: d002601c                 ld      [%o1+0x1C], %o0
F000F460: e6122008                 lduh    [%o0+8], %l3
F000F464: d0024000                 ld      [%o1], %o0
F000F468: d20521dc                 ld      [%l4+0x1DC], %o1
F000F46C: d0522030                 ldsh    [%o0+0x30], %o0
F000F470: d2026024                 ld      [%o1+0x24], %o1
F000F474: 7ffffdab                 call    _get_posix_proc
F000F478: e0024000                 ld      [%o1], %l0
F000F47C: 932c2010                 sll     %l0, 16, %o1
F000F480: a33a6010                 sra     %o1, 16, %l1
F000F484: 80a46000                 cmp     %l1, 0
F000F488: 16800006                 bge     loc_F000F4A0
F000F48C: aa100008                 mov     %o0, %l5
F000F490: d20521dc                 ld      [%l4+0x1DC], %o1
F000F494: 90102016                 mov     0x16, %o0
F000F498: 1080002f                 ba      locret_F000F554
F000F49C: d02a6038                 stb     %o0, [%o1+0x38]
F000F4A0: 40000133                 call    _suser
F000F4A4: e4156008                 lduh    [%l5+8], %l2
F000F4A8: 80a22000                 cmp     %o0, 0
F000F4AC: 22800006                 be,a    loc_F000F4C4
F000F4B0: 912ce010                 sll     %l3, 16, %o0
F000F4B4: a4100010                 mov     %l0, %l2
F000F4B8: a2100010                 mov     %l0, %l1
F000F4BC: 10800010                 ba      loc_F000F4FC
F000F4C0: a6100012                 mov     %l2, %l3
F000F4C4: 913a2010                 sra     %o0, 16, %o0
F000F4C8: 80a44008                 cmp     %l1, %o0
F000F4CC: 2280000c                 be,a    loc_F000F4FC
F000F4D0: a2100010                 mov     %l0, %l1
F000F4D4: 912ca010                 sll     %l2, 16, %o0
F000F4D8: 913a2010                 sra     %o0, 16, %o0
F000F4DC: 80a44008                 cmp     %l1, %o0
F000F4E0: 12800004                 bne     loc_F000F4F0
F000F4E4: d20521dc                 ld      [%l4+0x1DC], %o1
F000F4E8: 10800005                 ba      loc_F000F4FC
F000F4EC: a2100010                 mov     %l0, %l1
F000F4F0: 90102001                 mov     1, %o0
F000F4F4: 10800018                 ba      locret_F000F554
F000F4F8: d02a6038                 stb     %o0, [%o1+0x38]
F000F4FC: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000F500: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F000F504: c02a2038                 clrb    [%o0+0x38]
F000F508: a01421dc                 bset    %lo(dword_F0133DDC), %l0
F000F50C: d0043ffc                 ld      [%l0-4], %o0
F000F510: 4001662d                 call    _lock_write
F000F514: 90022020                 inc     0x20, %o0 ! ' '
F000F518: d0043ffc                 ld      [%l0-4], %o0
F000F51C: 40000155                 call    _crcopy
F000F520: d002201c                 ld      [%o0+0x1C], %o0
F000F524: d2043ffc                 ld      [%l0-4], %o1
F000F528: d022601c                 st      %o0, [%o1+0x1C]
F000F52C: d0043ffc                 ld      [%l0-4], %o0
F000F530: d002201c                 ld      [%o0+0x1C], %o0
F000F534: e6322008                 sth     %l3, [%o0+8]
F000F538: d0043ffc                 ld      [%l0-4], %o0
F000F53C: d002201c                 ld      [%o0+0x1C], %o0
F000F540: e2322004                 sth     %l1, [%o0+4]
F000F544: d0043ffc                 ld      [%l0-4], %o0
F000F548: 400166bb                 call    _lock_done
F000F54C: 90022020                 inc     0x20, %o0 ! ' '
F000F550: e4356008                 sth     %l2, [%l5+8]
F000F554: 81c7e008                 ret
F000F558: 81e80000                 restore
