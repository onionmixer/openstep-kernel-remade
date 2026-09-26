F007D44C: 9de3bf90                 save    %sp, -0x70, %sp
F007D450: d0062004                 ld      [%i0+4], %o0
F007D454: 80a22018                 cmp     %o0, 0x18
F007D458: 12800008                 bne     loc_F007D478
F007D45C: 90103ed0                 mov     -0x130, %o0
F007D460: d0060000                 ld      [%i0], %o0
F007D464: 23200000                 sethi   0x80000000, %l1
F007D468: 808a0011                 btst    %l1, %o0
F007D46C: 02800005                 be      loc_F007D480
F007D470: 01000000                 nop
F007D474: 90103ed0                 mov     -0x130, %o0
F007D478: 10800029                 ba      locret_F007D51C
F007D47C: d026601c                 st      %o0, [%i1+0x1C]
F007D480: 7fffa93d                 call    _convert_port_to_space
F007D484: d0062008                 ld      [%i0+8], %o0! task
F007D488: a0100008                 mov     %o0, %l0
F007D48C: 9206602c                 add     %i1, 0x2C, %o1 ! ','! names
F007D490: 9407bff4                 add     %fp, var_C, %o2! namesCnt
F007D494: 9606603c                 add     %i1, 0x3C, %o3 ! '<'! types
F007D498: 7fff929b                 call    _mach_port_names
F007D49C: 9807bff0                 add     %fp, var_10, %o4
F007D4A0: d026601c                 st      %o0, [%i1+0x1C]
F007D4A4: 7fffa9c4                 call    _space_deallocate
F007D4A8: 90100010                 mov     %l0, %o0
F007D4AC: d006601c                 ld      [%i1+0x1C], %o0
F007D4B0: 80a22000                 cmp     %o0, 0
F007D4B4: 1280001a                 bne     locret_F007D51C
F007D4B8: 92102040                 mov     0x40, %o1 ! '@'
F007D4BC: d0064000                 ld      [%i1], %o0
F007D4C0: d2266004                 st      %o1, [%i1+4]
F007D4C4: 90120011                 bset    %l1, %o0
F007D4C8: d0264000                 st      %o0, [%i1]
F007D4CC: 113c0444                 sethi   %hi(dword_F01111E4), %o0
F007D4D0: d20221e4                 ld      [%o0+%lo(dword_F01111E4)], %o1
F007D4D4: d2266020                 st      %o1, [%i1+0x20]
F007D4D8: 901221e4                 bset    %lo(dword_F01111E4), %o0
F007D4DC: d2022004                 ld      [%o0+4], %o1
F007D4E0: d2266024                 st      %o1, [%i1+0x24]
F007D4E4: d0022008                 ld      [%o0+8], %o0
F007D4E8: d207bff4                 ld      [%fp+var_C], %o1
F007D4EC: d0266028                 st      %o0, [%i1+0x28]
F007D4F0: d2266028                 st      %o1, [%i1+0x28]
F007D4F4: 113c0444                 sethi   %hi(dword_F01111F0), %o0
F007D4F8: d20221f0                 ld      [%o0+%lo(dword_F01111F0)], %o1
F007D4FC: d2266030                 st      %o1, [%i1+0x30]
F007D500: 901221f0                 bset    %lo(dword_F01111F0), %o0
F007D504: d2022004                 ld      [%o0+4], %o1
F007D508: d2266034                 st      %o1, [%i1+0x34]
F007D50C: d0022008                 ld      [%o0+8], %o0
F007D510: d207bff0                 ld      [%fp+var_10], %o1
F007D514: d0266038                 st      %o0, [%i1+0x38]
F007D518: d2266038                 st      %o1, [%i1+0x38]
F007D51C: 81c7e008                 ret
F007D520: 81e80000                 restore
