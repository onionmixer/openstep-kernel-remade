F0040E94: 9de3bf88                 save    %sp, -0x78, %sp
F0040E98: d0066014                 ld      [%i1+0x14], %o0
F0040E9C: b6102000                 mov     0, %i3
F0040EA0: a0022010                 add     %o0, 0x10, %l0
F0040EA4: d0040000                 ld      [%l0], %o0
F0040EA8: 80a22000                 cmp     %o0, 0
F0040EAC: 12bffffe                 bne     loc_F0040EA4
F0040EB0: 01000000                 nop
F0040EB4: 400157fd                 call    _simple_lock_try
F0040EB8: 90100010                 mov     %l0, %o0
F0040EBC: 80a22000                 cmp     %o0, 0
F0040EC0: 02bffff9                 be      loc_F0040EA4
F0040EC4: 13000400                 sethi   0x100000, %o1
F0040EC8: d0066020                 ld      [%i1+0x20], %o0
F0040ECC: 90120009                 bset    %o1, %o0
F0040ED0: d2066014                 ld      [%i1+0x14], %o1
F0040ED4: d0266020                 st      %o0, [%i1+0x20]
F0040ED8: c0226010                 clr     [%o1+0x10]
F0040EDC: e4062030                 ld      [%i0+0x30], %l2
F0040EE0: 7ffff1d1                 call    _rlock
F0040EE4: 90100012                 mov     %l2, %o0
F0040EE8: 113c0447                 sethi   %hi(_page_size), %o0
F0040EEC: ec02213c                 ld      [%o0+%lo(_page_size)], %l6
F0040EF0: d0060000                 ld      [%i0], %o0
F0040EF4: e0022030                 ld      [%o0+0x30], %l0
F0040EF8: d0062024                 ld      [%i0+0x24], %o0
F0040EFC: d0022128                 ld      [%o0+0x128], %o0
F0040F00: ea022024                 ld      [%o0+0x24], %l5
F0040F04: 80a42000                 cmp     %l0, 0
F0040F08: 12800022                 bne     loc_F0040F90
F0040F0C: aa0d7c00                 and     %l5, -0x400, %l5
F0040F10: 113c04d0                 sethi   %hi(_active_threads), %o0
F0040F14: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0040F18: d002200c                 ld      [%o0+0xC], %o0
F0040F1C: d002203c                 ld      [%o0+0x3C], %o0
F0040F20: 80a22000                 cmp     %o0, 0
F0040F24: 02800005                 be      loc_F0040F38
F0040F28: 113c04cf                 sethi   %hi(_active_u), %o0
F0040F2C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0040F30: 10800018                 ba      loc_F0040F90
F0040F34: e002201c                 ld      [%o0+0x1C], %l0
F0040F38: d004a070                 ld      [%l2+0x70], %o0
F0040F3C: 80a22000                 cmp     %o0, 0
F0040F40: 12800014                 bne     loc_F0040F90
F0040F44: a0100008                 mov     %o0, %l0
F0040F48: 113c0435                 sethi   %hi(aNfsFailureOnPa), %o0! "NFS failure on pagein: no credentials\n"
F0040F4C: 7fff4dc3                 call    _printf
F0040F50: 90122340                 bset    %lo(aNfsFailureOnPa), %o0! "NFS failure on pagein: no credentials\n"
F0040F54: 7ffff1d2                 call    _runlock
F0040F58: 90100012                 mov     %l2, %o0
F0040F5C: d0066014                 ld      [%i1+0x14], %o0
F0040F60: a0022010                 add     %o0, 0x10, %l0
F0040F64: d0040000                 ld      [%l0], %o0
F0040F68: 80a22000                 cmp     %o0, 0
F0040F6C: 12bffffe                 bne     loc_F0040F64
F0040F70: 01000000                 nop
F0040F74: 400157cd                 call    _simple_lock_try
F0040F78: 90100010                 mov     %l0, %o0
F0040F7C: 80a22000                 cmp     %o0, 0
F0040F80: 02bffff9                 be      loc_F0040F64
F0040F84: b0102002                 mov     2, %i0
F0040F88: 108000d2                 ba      loc_F00412D0
F0040F8C: d0066020                 ld      [%i1+0x20], %o0
F0040F90: d0140000                 lduh    [%l0], %o0
F0040F94: 90022001                 inc     %o0
F0040F98: d0340000                 sth     %o0, [%l0]
F0040F9C: d004a070                 ld      [%l2+0x70], %o0
F0040FA0: 80a22000                 cmp     %o0, 0
F0040FA4: 22800005                 be,a    loc_F0040FB8
F0040FA8: e024a070                 st      %l0, [%l2+0x70]
F0040FAC: 7fff3a9b                 call    _crfree
F0040FB0: 01000000                 nop
F0040FB4: e024a070                 st      %l0, [%l2+0x70]
F0040FB8: d204a098                 ld      [%l2+0x98], %o1
F0040FBC: 90068016                 add     %i2, %l6, %o0
F0040FC0: 80a24008                 cmp     %o1, %o0
F0040FC4: 1a800005                 bcc     loc_F0040FD8
F0040FC8: 113ffbff                 sethi   -0x100400, %o0
F0040FCC: 40012254                 call    _vm_page_zero_fill
F0040FD0: 90100019                 mov     %i1, %o0
F0040FD4: 113ffbff                 sethi   -0x100400, %o0
F0040FD8: b81223ff                 or      %o0, 0x3FF, %i4
F0040FDC: 9010001a                 mov     %i2, %o0
F0040FE0: 7fff1588                 call    _udiv
F0040FE4: 92100015                 mov     %l5, %o1
F0040FE8: a8100008                 mov     %o0, %l4
F0040FEC: 9010001a                 mov     %i2, %o0
F0040FF0: 7fff162c                 call    _urem
F0040FF4: 92100015                 mov     %l5, %o1
F0040FF8: ae100008                 mov     %o0, %l7
F0040FFC: 90254017                 sub     %l5, %l7, %o0
F0041000: 80a20016                 cmp     %o0, %l6
F0041004: 1a800003                 bcc     loc_F0041010
F0041008: a2100016                 mov     %l6, %l1
F004100C: a2100008                 mov     %o0, %l1
F0041010: d004a098                 ld      [%l2+0x98], %o0
F0041014: 80a2001a                 cmp     %o0, %i2
F0041018: 18800015                 bgu     loc_F004106C
F004101C: 9022001a                 sub     %o0, %i2, %o0
F0041020: 80a6e000                 cmp     %i3, 0
F0041024: 1280009c                 bne     loc_F0041294
F0041028: 01000000                 nop
F004102C: 7ffff19c                 call    _runlock
F0041030: 90100012                 mov     %l2, %o0
F0041034: d0066014                 ld      [%i1+0x14], %o0
F0041038: b0022010                 add     %o0, 0x10, %i0
F004103C: d0060000                 ld      [%i0], %o0
F0041040: 80a22000                 cmp     %o0, 0
F0041044: 12bffffe                 bne     loc_F004103C
F0041048: 01000000                 nop
F004104C: 40015797                 call    _simple_lock_try
F0041050: 90100018                 mov     %i0, %o0
F0041054: 80a22000                 cmp     %o0, 0
F0041058: 02bffff9                 be      loc_F004103C
F004105C: 01000000                 nop
F0041060: d0066020                 ld      [%i1+0x20], %o0
F0041064: 10800080                 ba      loc_F0041264
F0041068: b0102001                 mov     1, %i0
F004106C: 80a20011                 cmp     %o0, %l1
F0041070: 2a800002                 bcs,a   loc_F0041078
F0041074: a2100008                 mov     %o0, %l1
F0041078: 90100018                 mov     %i0, %o0
F004107C: d606201c                 ld      [%i0+0x1C], %o3
F0041080: 92100014                 mov     %l4, %o1
F0041084: d802e050                 ld      [%o3+0x50], %o4
F0041088: 9407bff4                 add     %fp, var_C, %o2
F004108C: 9fc30000                 call    %o4
F0041090: 9607bff0                 add     %fp, var_10, %o3
F0041094: d007bff0                 ld      [%fp+var_10], %o0
F0041098: 80a22000                 cmp     %o0, 0
F004109C: 16800012                 bge     loc_F00410E4
F00410A0: d007bff4                 ld      [%fp+var_C], %o0
F00410A4: 7ffff17e                 call    _runlock
F00410A8: 90100012                 mov     %l2, %o0
F00410AC: d0066014                 ld      [%i1+0x14], %o0
F00410B0: b0022010                 add     %o0, 0x10, %i0
F00410B4: d0060000                 ld      [%i0], %o0
F00410B8: 80a22000                 cmp     %o0, 0
F00410BC: 12bffffe                 bne     loc_F00410B4
F00410C0: 01000000                 nop
F00410C4: 40015779                 call    _simple_lock_try
F00410C8: 90100018                 mov     %i0, %o0
F00410CC: 80a22000                 cmp     %o0, 0
F00410D0: 02bffff9                 be      loc_F00410B4
F00410D4: 01000000                 nop
F00410D8: d0066020                 ld      [%i1+0x20], %o0
F00410DC: 10800062                 ba      loc_F0041264
F00410E0: b0102001                 mov     1, %i0
F00410E4: d204a070                 ld      [%l2+0x70], %o1
F00410E8: 7fffe148                 call    _nfs_validate_caches
F00410EC: 94102000                 mov     0, %o2
F00410F0: d204a064                 ld      [%l2+0x64], %o1
F00410F4: 90026001                 add     %o1, 1, %o0
F00410F8: 80a20014                 cmp     %o0, %l4
F00410FC: 12800011                 bne     loc_F0041140
F0041100: a6102000                 mov     0, %l3
F0041104: 90100018                 mov     %i0, %o0
F0041108: d606201c                 ld      [%i0+0x1C], %o3
F004110C: 92026002                 inc     2, %o1
F0041110: d802e050                 ld      [%o3+0x50], %o4
F0041114: 94102000                 mov     0, %o2
F0041118: 9fc30000                 call    %o4
F004111C: 9607bfec                 add     %fp, var_14, %o3
F0041120: d007bff4                 ld      [%fp+var_C], %o0
F0041124: d207bff0                 ld      [%fp+var_10], %o1
F0041128: 94100015                 mov     %l5, %o2
F004112C: d607bfec                 ld      [%fp+var_14], %o3
F0041130: 7fff8d2a                 call    _breada
F0041134: 98100015                 mov     %l5, %o4
F0041138: 10800007                 ba      loc_F0041154
F004113C: a0100008                 mov     %o0, %l0
F0041140: d007bff4                 ld      [%fp+var_C], %o0
F0041144: d207bff0                 ld      [%fp+var_10], %o1
F0041148: 7fff8cf6                 call    _bread
F004114C: 94100015                 mov     %l5, %o2
F0041150: a0100008                 mov     %o0, %l0
F0041154: e824a064                 st      %l4, [%l2+0x64]
F0041158: d0040000                 ld      [%l0], %o0
F004115C: 808a2004                 btst    4, %o0
F0041160: 22800004                 be,a    loc_F0041170
F0041164: d0042020                 ld      [%l0+0x20], %o0
F0041168: 1080000d                 ba      loc_F004119C
F004116C: e654201c                 ldsh    [%l0+0x1C], %l3
F0041170: 94100011                 mov     %l1, %o2
F0041174: d2066024                 ld      [%i1+0x24], %o1
F0041178: 90020017                 add     %o0, %l7, %o0
F004117C: 400179f0                 call    _copy_to_phys
F0041180: 9202401b                 add     %o1, %i3, %o1
F0041184: d2040000                 ld      [%l0], %o1
F0041188: 808a7ffc                 btst    -4, %o1
F004118C: 12800004                 bne     loc_F004119C
F0041190: 11001000                 sethi   0x400000, %o0
F0041194: 90124008                 bset    %o1, %o0
F0041198: d0240000                 st      %o0, [%l0]
F004119C: 7fff8db3                 call    _brelse
F00411A0: 90100010                 mov     %l0, %o0
F00411A4: 80a4e000                 cmp     %l3, 0
F00411A8: 22800034                 be,a    loc_F0041278
F00411AC: ac258011                 sub     %l6, %l1, %l6
F00411B0: d0060000                 ld      [%i0], %o0
F00411B4: e6222034                 st      %l3, [%o0+0x34]
F00411B8: d0060000                 ld      [%i0], %o0
F00411BC: d0522004                 ldsh    [%o0+4], %o0
F00411C0: 80a22000                 cmp     %o0, 0
F00411C4: 12800019                 bne     loc_F0041228
F00411C8: 113c04d0                 sethi   %hi(_active_threads), %o0
F00411CC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00411D0: d002200c                 ld      [%o0+0xC], %o0
F00411D4: d002203c                 ld      [%o0+0x3C], %o0
F00411D8: 80a22000                 cmp     %o0, 0
F00411DC: 02800009                 be      loc_F0041200
F00411E0: 113c04cf                 sethi   %hi(_active_u), %o0
F00411E4: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F00411E8: 113c0435                 sethi   %hi(aSD_1), %o0! "%s[%d]: "
F00411EC: d4024000                 ld      [%o1], %o2
F00411F0: 90122368                 bset    %lo(aSD_1), %o0! "%s[%d]: "
F00411F4: d452a030                 ldsh    [%o2+0x30], %o2
F00411F8: 7fff4d18                 call    _printf
F00411FC: 92026008                 inc     8, %o1
F0041200: 80a4e046                 cmp     %l3, 0x46 ! 'F'
F0041204: 12800006                 bne     loc_F004121C
F0041208: 113c0435                 sethi   -0xFEF2C00, %o0
F004120C: 113c0435                 sethi   %hi(aNfsReadErrorOn), %o0! "NFS read error on pagein: stale file ha"...
F0041210: 7fff4d12                 call    _printf
F0041214: 90122378                 bset    %lo(aNfsReadErrorOn), %o0! "NFS read error on pagein: stale file ha"...
F0041218: 30800004                 ba,a    loc_F0041228
F004121C: 901223a8                 bset    0x3A8, %o0! char *
F0041220: 7fff4d0e                 call    _printf
F0041224: 92100013                 mov     %l3, %o1
F0041228: 7ffff11d                 call    _runlock
F004122C: 90100012                 mov     %l2, %o0
F0041230: d0066014                 ld      [%i1+0x14], %o0
F0041234: b0022010                 add     %o0, 0x10, %i0
F0041238: d0060000                 ld      [%i0], %o0
F004123C: 80a22000                 cmp     %o0, 0
F0041240: 12bffffe                 bne     loc_F0041238
F0041244: 01000000                 nop
F0041248: 40015718                 call    _simple_lock_try
F004124C: 90100018                 mov     %i0, %o0
F0041250: 80a22000                 cmp     %o0, 0
F0041254: 02bffff9                 be      loc_F0041238
F0041258: 01000000                 nop
F004125C: d0066020                 ld      [%i1+0x20], %o0
F0041260: b0102002                 mov     2, %i0
F0041264: d2066014                 ld      [%i1+0x14], %o1
F0041268: 900a001c                 and     %o0, %i4, %o0
F004126C: d0266020                 st      %o0, [%i1+0x20]
F0041270: c0226010                 clr     [%o1+0x10]
F0041274: 3080001c                 ba,a    locret_F00412E4
F0041278: b606c011                 add     %i3, %l1, %i3
F004127C: 80a5a000                 cmp     %l6, 0
F0041280: 04800005                 ble     loc_F0041294
F0041284: b4068011                 add     %i2, %l1, %i2
F0041288: 80a46000                 cmp     %l1, 0
F004128C: 12bfff55                 bne     loc_F0040FE0
F0041290: 9010001a                 mov     %i2, %o0
F0041294: 7ffff102                 call    _runlock
F0041298: 90100012                 mov     %l2, %o0
F004129C: d0066014                 ld      [%i1+0x14], %o0
F00412A0: a0022010                 add     %o0, 0x10, %l0
F00412A4: d0040000                 ld      [%l0], %o0
F00412A8: 80a22000                 cmp     %o0, 0
F00412AC: 12bffffe                 bne     loc_F00412A4
F00412B0: 01000000                 nop
F00412B4: 400156fd                 call    _simple_lock_try
F00412B8: 90100010                 mov     %l0, %o0
F00412BC: 80a22000                 cmp     %o0, 0
F00412C0: 02bffff9                 be      loc_F00412A4
F00412C4: 01000000                 nop
F00412C8: b0102000                 mov     0, %i0
F00412CC: d0066020                 ld      [%i1+0x20], %o0
F00412D0: 13000400                 sethi   0x100000, %o1
F00412D4: 922a0009                 andn    %o0, %o1, %o1
F00412D8: d0066014                 ld      [%i1+0x14], %o0
F00412DC: d2266020                 st      %o1, [%i1+0x20]
F00412E0: c0222010                 clr     [%o0+0x10]
F00412E4: 81c7e008                 ret
F00412E8: 81e80000                 restore
