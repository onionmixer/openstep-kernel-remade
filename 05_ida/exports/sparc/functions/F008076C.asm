F008076C: 9de3bf90                 save    %sp, -0x70, %sp
F0080770: d0062004                 ld      [%i0+4], %o0
F0080774: 80a22020                 cmp     %o0, 0x20 ! ' '
F0080778: 1280000c                 bne     loc_F00807A8
F008077C: 90103ed0                 mov     -0x130, %o0
F0080780: d0060000                 ld      [%i0], %o0
F0080784: 80a22000                 cmp     %o0, 0
F0080788: 06800007                 bl      loc_F00807A4
F008078C: 133c0445                 sethi   %hi(dword_F01116B8), %o1
F0080790: d0062018                 ld      [%i0+0x18], %o0
F0080794: d20262b8                 ld      [%o1+%lo(dword_F01116B8)], %o1
F0080798: 80a20009                 cmp     %o0, %o1
F008079C: 02800005                 be      loc_F00807B0
F00807A0: a006602c                 add     %i1, 0x2C, %l0 ! ','
F00807A4: 90103ed0                 mov     -0x130, %o0
F00807A8: 10800033                 ba      locret_F0080874
F00807AC: d026601c                 st      %o0, [%i1+0x1C]
F00807B0: e027bff4                 st      %l0, [%fp+var_C]
F00807B4: 90102200                 mov     0x200, %o0
F00807B8: d206201c                 ld      [%i0+0x1C], %o1
F00807BC: 80a26200                 cmp     %o1, 0x200
F00807C0: 1a800003                 bcc     loc_F00807CC
F00807C4: d027bff0                 st      %o0, [%fp+var_10]
F00807C8: d227bff0                 st      %o1, [%fp+var_10]
F00807CC: 7fff92b0                 call    _convert_port_to_host
F00807D0: d0062008                 ld      [%i0+8], %o0
F00807D4: 9207bff4                 add     %fp, var_C, %o1
F00807D8: 7fff79b2                 call    _host_ipc_hash_info
F00807DC: 9407bff0                 add     %fp, var_10, %o2
F00807E0: 80a22000                 cmp     %o0, 0
F00807E4: 12800024                 bne     locret_F0080874
F00807E8: d026601c                 st      %o0, [%i1+0x1C]
F00807EC: 133c0445                 sethi   %hi(dword_F01116BC), %o1
F00807F0: d00262bc                 ld      [%o1+%lo(dword_F01116BC)], %o0
F00807F4: d0266020                 st      %o0, [%i1+0x20]
F00807F8: 921262bc                 bset    %lo(dword_F01116BC), %o1
F00807FC: d0026004                 ld      [%o1+4], %o0
F0080800: 96102001                 mov     1, %o3
F0080804: d407bff4                 ld      [%fp+var_C], %o2
F0080808: d0266024                 st      %o0, [%i1+0x24]
F008080C: d0026008                 ld      [%o1+8], %o0
F0080810: 80a28010                 cmp     %o2, %l0
F0080814: 02800008                 be      loc_F0080834
F0080818: d0266028                 st      %o0, [%i1+0x28]
F008081C: d426602c                 st      %o2, [%i1+0x2C]
F0080820: d0066020                 ld      [%i1+0x20], %o0
F0080824: 96102000                 mov     0, %o3
F0080828: 900a3ff7                 and     %o0, -9, %o0
F008082C: 90122002                 bset    2, %o0
F0080830: d0266020                 st      %o0, [%i1+0x20]
F0080834: d207bff0                 ld      [%fp+var_10], %o1
F0080838: d0066020                 ld      [%i1+0x20], %o0
F008083C: 808a2008                 btst    8, %o0
F0080840: 02800005                 be      loc_F0080854
F0080844: d2266028                 st      %o1, [%i1+0x28]
F0080848: 912a6002                 sll     %o1, 2, %o0
F008084C: 10800003                 ba      loc_F0080858
F0080850: 9002202c                 inc     0x2C, %o0 ! ','
F0080854: 90102030                 mov     0x30, %o0 ! '0'
F0080858: 80a2e000                 cmp     %o3, 0
F008085C: 12800006                 bne     locret_F0080874
F0080860: d0266004                 st      %o0, [%i1+4]
F0080864: d0064000                 ld      [%i1], %o0
F0080868: 13200000                 sethi   0x80000000, %o1
F008086C: 90120009                 bset    %o1, %o0
F0080870: d0264000                 st      %o0, [%i1]
F0080874: 81c7e008                 ret
F0080878: 81e80000                 restore
