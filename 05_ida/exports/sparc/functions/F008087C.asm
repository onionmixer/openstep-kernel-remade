F008087C: 9de3bf90                 save    %sp, -0x70, %sp
F0080880: d0062004                 ld      [%i0+4], %o0
F0080884: 80a22020                 cmp     %o0, 0x20 ! ' '
F0080888: 1280000c                 bne     loc_F00808B8
F008088C: 90103ed0                 mov     -0x130, %o0
F0080890: d0060000                 ld      [%i0], %o0
F0080894: 80a22000                 cmp     %o0, 0
F0080898: 06800007                 bl      loc_F00808B4
F008089C: 133c0445                 sethi   %hi(dword_F01116C8), %o1
F00808A0: d0062018                 ld      [%i0+0x18], %o0
F00808A4: d20262c8                 ld      [%o1+%lo(dword_F01116C8)], %o1
F00808A8: 80a20009                 cmp     %o0, %o1
F00808AC: 02800005                 be      loc_F00808C0
F00808B0: a0066034                 add     %i1, 0x34, %l0 ! '4'
F00808B4: 90103ed0                 mov     -0x130, %o0
F00808B8: 10800037                 ba      locret_F0080994
F00808BC: d026601c                 st      %o0, [%i1+0x1C]
F00808C0: e027bff4                 st      %l0, [%fp+var_C]
F00808C4: 90102200                 mov     0x200, %o0
F00808C8: d206201c                 ld      [%i0+0x1C], %o1
F00808CC: 80a26200                 cmp     %o1, 0x200
F00808D0: 1a800003                 bcc     loc_F00808DC
F00808D4: d027bff0                 st      %o0, [%fp+var_10]
F00808D8: d227bff0                 st      %o1, [%fp+var_10]
F00808DC: 7fff926c                 call    _convert_port_to_host
F00808E0: d0062008                 ld      [%i0+8], %o0
F00808E4: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00808E8: 9407bff4                 add     %fp, var_C, %o2
F00808EC: 7fff79ba                 call    _host_ipc_marequest_info
F00808F0: 9607bff0                 add     %fp, var_10, %o3
F00808F4: 80a22000                 cmp     %o0, 0
F00808F8: 12800027                 bne     locret_F0080994
F00808FC: d026601c                 st      %o0, [%i1+0x1C]
F0080900: 113c0445                 sethi   %hi(dword_F01116CC), %o0
F0080904: d00222cc                 ld      [%o0+%lo(dword_F01116CC)], %o0
F0080908: 133c0445                 sethi   %hi(dword_F01116D0), %o1
F008090C: d0266020                 st      %o0, [%i1+0x20]
F0080910: d00262d0                 ld      [%o1+%lo(dword_F01116D0)], %o0
F0080914: d0266028                 st      %o0, [%i1+0x28]
F0080918: 921262d0                 bset    %lo(dword_F01116D0), %o1
F008091C: d0026004                 ld      [%o1+4], %o0
F0080920: 96102001                 mov     1, %o3
F0080924: d407bff4                 ld      [%fp+var_C], %o2
F0080928: d026602c                 st      %o0, [%i1+0x2C]
F008092C: d0026008                 ld      [%o1+8], %o0
F0080930: 80a28010                 cmp     %o2, %l0
F0080934: 02800008                 be      loc_F0080954
F0080938: d0266030                 st      %o0, [%i1+0x30]
F008093C: d4266034                 st      %o2, [%i1+0x34]
F0080940: d0066028                 ld      [%i1+0x28], %o0
F0080944: 96102000                 mov     0, %o3
F0080948: 900a3ff7                 and     %o0, -9, %o0
F008094C: 90122002                 bset    2, %o0
F0080950: d0266028                 st      %o0, [%i1+0x28]
F0080954: d207bff0                 ld      [%fp+var_10], %o1
F0080958: d0066028                 ld      [%i1+0x28], %o0
F008095C: 808a2008                 btst    8, %o0
F0080960: 02800005                 be      loc_F0080974
F0080964: d2266030                 st      %o1, [%i1+0x30]
F0080968: 912a6002                 sll     %o1, 2, %o0
F008096C: 10800003                 ba      loc_F0080978
F0080970: 90022034                 inc     0x34, %o0 ! '4'
F0080974: 90102038                 mov     0x38, %o0 ! '8'
F0080978: 80a2e000                 cmp     %o3, 0
F008097C: 12800006                 bne     locret_F0080994
F0080980: d0266004                 st      %o0, [%i1+4]
F0080984: d0064000                 ld      [%i1], %o0
F0080988: 13200000                 sethi   0x80000000, %o1
F008098C: 90120009                 bset    %o1, %o0
F0080990: d0264000                 st      %o0, [%i1]
F0080994: 81c7e008                 ret
F0080998: 81e80000                 restore
