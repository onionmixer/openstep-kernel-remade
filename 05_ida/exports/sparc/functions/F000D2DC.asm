F000D2DC: 9de3bf88                 save    %sp, -0x78, %sp! int
F000D2E0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000D2E4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F000D2E8: d0022024                 ld      [%o0+0x24], %o0
F000D2EC: c027bfec                 clr     [%fp+var_14]
F000D2F0: d027bff0                 st      %o0, [%fp+var_10]
F000D2F4: 113c04cf                 sethi   -0xFECC400, %o0
F000D2F8: d00221d8                 ld      [%o0+0x1D8], %o0
F000D2FC: d4020000                 ld      [%o0], %o2
F000D300: e002a048                 ld      [%o2+0x48], %l0
F000D304: 80a42000                 cmp     %l0, 0
F000D308: 02800089                 be      loc_F000D52C
F000D30C: d807bfec                 ld      [%fp+var_14], %o4
F000D310: 313c04cfa41621dc         set     dword_F0133DDC, %l2
F000D318: 233c04d2                 sethi   -0xFECB800, %l1
F000D31C: d607bff0                 ld      [%fp+var_10], %o3! int
F000D320: d254202e                 ldsh    [%l0+0x2E], %o1
F000D324: d002c000                 ld      [%o3], %o0
F000D328: 80a20009                 cmp     %o0, %o1
F000D32C: 3280007c                 bne,a   loc_F000D51C
F000D330: e004204c                 ld      [%l0+0x4C], %l0
F000D334: d807bfec                 ld      [%fp+var_14], %o4! int
F000D338: d0042068                 ld      [%l0+0x68], %o0
F000D33C: 98032001                 inc     %o4
F000D340: 80a22000                 cmp     %o0, 0
F000D344: 1280004a                 bne     loc_F000D46C
F000D348: d827bfec                 st      %o4, [%fp+var_14]
F000D34C: d40621dc                 ld      [%i0+0x1DC], %o2! int
F000D350: d2542030                 ldsh    [%l0+0x30], %o1
F000D354: 90042034                 add     %l0, 0x34, %o0 ! '4'! int
F000D358: d222a030                 st      %o1, [%o2+0x30]
F000D35C: d202e004                 ld      [%o3+4], %o1! int
F000D360: 40022b5b                 call    _copyout
F000D364: 94102004                 mov     4, %o2! int
F000D368: d20621dc                 ld      [%i0+0x1DC], %o1
F000D36C: d02a6038                 stb     %o0, [%o1+0x38]
F000D370: d00621dc                 ld      [%i0+0x1DC], %o0
F000D374: d04a2038                 ldsb    [%o0+0x38], %o0
F000D378: 80a22000                 cmp     %o0, 0
F000D37C: 328000a4                 bne,a   locret_F000D60C
F000D380: b0102000                 mov     0, %i0
F000D384: d2042038                 ld      [%l0+0x38], %o1
F000D388: 80a26000                 cmp     %o1, 0
F000D38C: 02800009                 be      loc_F000D3B0
F000D390: c0342034                 clrh    [%l0+0x34]
F000D394: d004bffc                 ld      [%l2-4], %o0
F000D398: 40000c1f                 call    _ruadd
F000D39C: 900221b4                 inc     0x1B4, %o0
F000D3A0: d0042038                 ld      [%l0+0x38], %o0
F000D3A4: 40016b7f                 call    _kfree
F000D3A8: 92102048                 mov     0x48, %o1 ! 'H'
F000D3AC: c0242038                 clr     [%l0+0x38]
F000D3B0: 40000521                 call    _leavepgrp
F000D3B4: 90100010                 mov     %l0, %o0
F000D3B8: 40000642                 call    _delete_posix_proc
F000D3BC: 90100010                 mov     %l0, %o0
F000D3C0: c02c2013                 clrb    [%l0+0x13]
F000D3C4: d204200c                 ld      [%l0+0xC], %o1
F000D3C8: c0342030                 clrh    [%l0+0x30]
F000D3CC: d0042008                 ld      [%l0+8], %o0
F000D3D0: c0342032                 clrh    [%l0+0x32]
F000D3D4: 80a22000                 cmp     %o0, 0
F000D3D8: 02800005                 be      loc_F000D3EC
F000D3DC: d0224000                 st      %o0, [%o1]
F000D3E0: d2042008                 ld      [%l0+8], %o1
F000D3E4: d004200c                 ld      [%l0+0xC], %o0
F000D3E8: d022600c                 st      %o0, [%o1+0xC]
F000D3EC: d00462e0                 ld      [%l1+0x2E0], %o0
F000D3F0: d2042050                 ld      [%l0+0x50], %o1
F000D3F4: d0242008                 st      %o0, [%l0+8]
F000D3F8: 80a26000                 cmp     %o1, 0
F000D3FC: 02800004                 be      loc_F000D40C
F000D400: e02462e0                 st      %l0, [%l1+0x2E0]
F000D404: d004204c                 ld      [%l0+0x4C], %o0
F000D408: d022604c                 st      %o0, [%o1+0x4C]
F000D40C: d204204c                 ld      [%l0+0x4C], %o1
F000D410: 80a26000                 cmp     %o1, 0
F000D414: 22800005                 be,a    loc_F000D428
F000D418: d2042044                 ld      [%l0+0x44], %o1
F000D41C: d0042050                 ld      [%l0+0x50], %o0
F000D420: d0226050                 st      %o0, [%o1+0x50]
F000D424: d2042044                 ld      [%l0+0x44], %o1
F000D428: d0026048                 ld      [%o1+0x48], %o0
F000D42C: 80a20010                 cmp     %o0, %l0
F000D430: 32800005                 bne,a   loc_F000D444
F000D434: c0242044                 clr     [%l0+0x44]
F000D438: d004204c                 ld      [%l0+0x4C], %o0
F000D43C: d0226048                 st      %o0, [%o1+0x48]
F000D440: c0242044                 clr     [%l0+0x44]
F000D444: c0242050                 clr     [%l0+0x50]
F000D448: c024204c                 clr     [%l0+0x4C]
F000D44C: c0242048                 clr     [%l0+0x48]
F000D450: c0242018                 clr     [%l0+0x18]
F000D454: c0242024                 clr     [%l0+0x24]
F000D458: c0242020                 clr     [%l0+0x20]
F000D45C: c024201c                 clr     [%l0+0x1C]
F000D460: c0242028                 clr     [%l0+0x28]
F000D464: 10800069                 ba      loc_F000D608
F000D468: c02c2017                 clrb    [%l0+0x17]
F000D46C: d0022044                 ld      [%o0+0x44], %o0
F000D470: 80a22000                 cmp     %o0, 0
F000D474: 2480002a                 ble,a   loc_F000D51C
F000D478: e004204c                 ld      [%l0+0x4C], %l0
F000D47C: d04c2013                 ldsb    [%l0+0x13], %o0
F000D480: 80a22006                 cmp     %o0, 6
F000D484: 32800026                 bne,a   loc_F000D51C
F000D488: e004204c                 ld      [%l0+0x4C], %l0
F000D48C: d2042028                 ld      [%l0+0x28], %o1
F000D490: 808a6020                 btst    0x20, %o1 ! ' '
F000D494: 32800022                 bne,a   loc_F000D51C
F000D498: e004204c                 ld      [%l0+0x4C], %l0
F000D49C: 808a6010                 btst    0x10, %o1
F000D4A0: 32800007                 bne,a   loc_F000D4BC
F000D4A4: d004207c                 ld      [%l0+0x7C], %o0
F000D4A8: d002e008                 ld      [%o3+8], %o0
F000D4AC: 808a2002                 btst    2, %o0
F000D4B0: 2280001b                 be,a    loc_F000D51C
F000D4B4: e004204c                 ld      [%l0+0x4C], %l0
F000D4B8: d004207c                 ld      [%l0+0x7C], %o0
F000D4BC: 80a22000                 cmp     %o0, 0
F000D4C0: 02800004                 be      loc_F000D4D0
F000D4C4: 80a2000a                 cmp     %o0, %o2
F000D4C8: 32800015                 bne,a   loc_F000D51C
F000D4CC: e004204c                 ld      [%l0+0x4C], %l0
F000D4D0: 90126020                 or      %o1, 0x20, %o0
F000D4D4: d0242028                 st      %o0, [%l0+0x28]
F000D4D8: d20621dc                 ld      [%i0+0x1DC], %o1
F000D4DC: d0542030                 ldsh    [%l0+0x30], %o0
F000D4E0: d0226030                 st      %o0, [%o1+0x30]
F000D4E4: d04c2017                 ldsb    [%l0+0x17], %o0
F000D4E8: 80a22000                 cmp     %o0, 0
F000D4EC: 22800002                 be,a    loc_F000D4F4
F000D4F0: d004203c                 ld      [%l0+0x3C], %o0
F000D4F4: 912a2008                 sll     %o0, 8, %o0
F000D4F8: 9012207f                 bset    0x7F, %o0
F000D4FC: d027bff4                 st      %o0, [%fp+var_C]
F000D500: d207bff0                 ld      [%fp+var_10], %o1
F000D504: 9007bff4                 add     %fp, var_C, %o0! int
F000D508: d2026004                 ld      [%o1+4], %o1! int
F000D50C: 40022af0                 call    _copyout
F000D510: 94102004                 mov     4, %o2
F000D514: 1080001b                 ba      loc_F000D580
F000D518: d20621dc                 ld      [%i0+0x1DC], %o1
F000D51C: 80a42000                 cmp     %l0, 0
F000D520: 12bfff80                 bne     loc_F000D320
F000D524: d607bff0                 ld      [%fp+var_10], %o3! int
F000D528: d807bfec                 ld      [%fp+var_14], %o4! int
F000D52C: 80a32000                 cmp     %o4, 0
F000D530: 12800008                 bne     loc_F000D550
F000D534: d407bff0                 ld      [%fp+var_10], %o2! int
F000D538: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000D53C: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000D540: b0102000                 mov     0, %i0
F000D544: 9010200a                 mov     0xA, %o0
F000D548: 10800031                 ba      locret_F000D60C
F000D54C: d02a6038                 stb     %o0, [%o1+0x38]
F000D550: d002a008                 ld      [%o2+8], %o0
F000D554: 808a2001                 btst    1, %o0
F000D558: 0280000d                 be      loc_F000D58C
F000D55C: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000D560: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F000D564: c027bff4                 clr     [%fp+var_C]
F000D568: c0226030                 clr     [%o1+0x30]
F000D56C: d202a004                 ld      [%o2+4], %o1! int
F000D570: 9007bff4                 add     %fp, var_C, %o0! int
F000D574: 40022ad6                 call    _copyout
F000D578: 94102004                 mov     4, %o2
F000D57C: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F000D580: b0102000                 mov     0, %i0
F000D584: 10800022                 ba      locret_F000D60C
F000D588: d02a6038                 stb     %o0, [%o1+0x38]
F000D58C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000D590: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F000D594: 400225f0                 call    _setjmp
F000D598: 90022028                 inc     0x28, %o0 ! '('
F000D59C: 80a22000                 cmp     %o0, 0
F000D5A0: 02800013                 be      loc_F000D5EC
F000D5A4: 153c04cf                 sethi   %hi(_active_u), %o2
F000D5A8: d202a1d8                 ld      [%o2+%lo(_active_u)], %o1
F000D5AC: e0024000                 ld      [%o1], %l0
F000D5B0: d04c2017                 ldsb    [%l0+0x17], %o0
F000D5B4: d202613c                 ld      [%o1+0x13C], %o1
F000D5B8: 90023fff                 inc     -1, %o0
F000D5BC: 933a4008                 sra     %o1, %o0, %o1
F000D5C0: 808a6001                 btst    1, %o1
F000D5C4: 02800006                 be      loc_F000D5DC
F000D5C8: 9412a1d8                 bset    %lo(_active_u), %o2
F000D5CC: d202a004                 ld      [%o2+4], %o1
F000D5D0: 90102004                 mov     4, %o0
F000D5D4: 1080000d                 ba      loc_F000D608
F000D5D8: d02a6038                 stb     %o0, [%o1+0x38]
F000D5DC: d202a004                 ld      [%o2+4], %o1
F000D5E0: 90102002                 mov     2, %o0
F000D5E4: 10800009                 ba      loc_F000D608
F000D5E8: d02a6039                 stb     %o0, [%o1+0x39]
F000D5EC: 113c04cf                 sethi   %hi(_active_u), %o0
F000D5F0: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000D5F4: d0020000                 ld      [%o0], %o0! unsigned int
F000D5F8: 40001420                 call    _sleep
F000D5FC: 9210201e                 mov     0x1E, %o1
F000D600: 10bfff3e                 ba      loc_F000D2F8
F000D604: 113c04cf                 sethi   -0xFECC400, %o0
F000D608: b0102000                 mov     0, %i0
F000D60C: 81c7e008                 ret
F000D610: 81e80000                 restore
