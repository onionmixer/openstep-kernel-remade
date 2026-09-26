F0078C2C: 9de3bf90                 save    %sp, -0x70, %sp
F0078C30: 80a62000                 cmp     %i0, 0
F0078C34: 32800006                 bne,a   loc_F0078C4C
F0078C38: d006202c                 ld      [%i0+0x2C], %o0
F0078C3C: 113c0443                 sethi   %hi(aZallocNullZone), %o0! "zalloc: null zone"
F0078C40: 7ffe714c                 call    _panic
F0078C44: 90122030                 bset    %lo(aZallocNullZone), %o0! "zalloc: null zone"
F0078C48: d006202c                 ld      [%i0+0x2C], %o0
F0078C4C: 80a22000                 cmp     %o0, 0
F0078C50: 16800006                 bge     loc_F0078C68
F0078C54: 01000000                 nop
F0078C58: 7fffc05b                 call    _lock_write
F0078C5C: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0078C60: 10800010                 ba      loc_F0078CA0
F0078C64: d4062010                 ld      [%i0+0x10], %o2
F0078C68: 400077c8                 call    _splusclock
F0078C6C: 01000000                 nop
F0078C70: a0100008                 mov     %o0, %l0
F0078C74: d0060000                 ld      [%i0], %o0
F0078C78: 80a22000                 cmp     %o0, 0
F0078C7C: 12bffffe                 bne     loc_F0078C74
F0078C80: 01000000                 nop
F0078C84: 40007889                 call    _simple_lock_try
F0078C88: 90100018                 mov     %i0, %o0
F0078C8C: 80a22000                 cmp     %o0, 0
F0078C90: 02bffff9                 be      loc_F0078C74
F0078C94: 01000000                 nop
F0078C98: e0262004                 st      %l0, [%i0+4]
F0078C9C: d4062010                 ld      [%i0+0x10], %o2
F0078CA0: 80a2a000                 cmp     %o2, 0
F0078CA4: 0280000b                 be      loc_F0078CD0
F0078CA8: d427bff4                 st      %o2, [%fp+var_C]
F0078CAC: d0062008                 ld      [%i0+8], %o0
F0078CB0: d206200c                 ld      [%i0+0xC], %o1
F0078CB4: 90022001                 inc     %o0
F0078CB8: d0262008                 st      %o0, [%i0+8]
F0078CBC: d0028000                 ld      [%o2], %o0
F0078CC0: 80a2400a                 cmp     %o1, %o2
F0078CC4: 12800003                 bne     loc_F0078CD0
F0078CC8: d0262010                 st      %o0, [%i0+0x10]
F0078CCC: c026200c                 clr     [%i0+0xC]
F0078CD0: d007bff4                 ld      [%fp+var_C], %o0
F0078CD4: 80a22000                 cmp     %o0, 0
F0078CD8: 328000f0                 bne,a   loc_F0079098
F0078CDC: d006202c                 ld      [%i0+0x2C], %o0
F0078CE0: 23200000                 sethi   0x80000000, %l1
F0078CE4: d0062024                 ld      [%i0+0x24], %o0
F0078CE8: 80a22000                 cmp     %o0, 0
F0078CEC: 02800032                 be      loc_F0078DB4
F0078CF0: 80a66000                 cmp     %i1, 0
F0078CF4: 12800012                 bne     loc_F0078D3C
F0078CF8: 90062024                 add     %i0, 0x24, %o0 ! '$'
F0078CFC: d006202c                 ld      [%i0+0x2C], %o0
F0078D00: 808a0011                 btst    %l1, %o0
F0078D04: 12800007                 bne     loc_F0078D20
F0078D08: 01000000                 nop
F0078D0C: d0062004                 ld      [%i0+4], %o0
F0078D10: c0260000                 clr     [%i0]
F0078D14: 40007804                 call    _splx
F0078D18: b0102000                 mov     0, %i0
F0078D1C: 308000ea                 ba,a    locret_F00790C4
F0078D20: 7fffc0c5                 call    _lock_done
F0078D24: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0078D28: 108000e7                 ba      locret_F00790C4
F0078D2C: b0102000                 mov     0, %i0
F0078D30: 7fffc0c1                 call    _lock_done
F0078D34: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0078D38: 3080000b                 ba,a    loc_F0078D64
F0078D3C: 7fffdfe6                 call    _assert_wait
F0078D40: 92102001                 mov     1, %o1
F0078D44: d006202c                 ld      [%i0+0x2C], %o0
F0078D48: 808a0011                 btst    %l1, %o0
F0078D4C: 12bffff9                 bne     loc_F0078D30
F0078D50: 01000000                 nop
F0078D54: d0062004                 ld      [%i0+4], %o0
F0078D58: c0260000                 clr     [%i0]
F0078D5C: 400077f2                 call    _splx
F0078D60: 01000000                 nop
F0078D64: 7fffe277                 call    _thread_block_with_continuation
F0078D68: 90102000                 mov     0, %o0
F0078D6C: d006202c                 ld      [%i0+0x2C], %o0
F0078D70: 808a0011                 btst    %l1, %o0
F0078D74: 128000c2                 bne     loc_F007907C
F0078D78: 01000000                 nop
F0078D7C: 40007783                 call    _splusclock
F0078D80: 01000000                 nop
F0078D84: a0100008                 mov     %o0, %l0
F0078D88: d0060000                 ld      [%i0], %o0
F0078D8C: 80a22000                 cmp     %o0, 0
F0078D90: 12bffffe                 bne     loc_F0078D88
F0078D94: 01000000                 nop
F0078D98: 40007844                 call    _simple_lock_try
F0078D9C: 90100018                 mov     %i0, %o0
F0078DA0: 80a22000                 cmp     %o0, 0
F0078DA4: 02bffff9                 be      loc_F0078D88
F0078DA8: 01000000                 nop
F0078DAC: 108000b6                 ba      loc_F0079084
F0078DB0: e0262004                 st      %l0, [%i0+4]
F0078DB4: d2062014                 ld      [%i0+0x14], %o1
F0078DB8: d006202c                 ld      [%i0+0x2C], %o0
F0078DBC: 808a0011                 btst    %l1, %o0
F0078DC0: 02800009                 be      loc_F0078DE4
F0078DC4: d4062018                 ld      [%i0+0x18], %o2
F0078DC8: d0062020                 ld      [%i0+0x20], %o0
F0078DCC: 90024008                 add     %o1, %o0, %o0
F0078DD0: 80a2000a                 cmp     %o0, %o2
F0078DD4: 3880000a                 bgu,a   loc_F0078DFC
F0078DD8: d206202c                 ld      [%i0+0x2C], %o1
F0078DDC: 10800037                 ba      loc_F0078EB8
F0078DE0: d006202c                 ld      [%i0+0x2C], %o0
F0078DE4: d006201c                 ld      [%i0+0x1C], %o0
F0078DE8: 90024008                 add     %o1, %o0, %o0
F0078DEC: 80a2000a                 cmp     %o0, %o2
F0078DF0: 28800032                 bleu,a  loc_F0078EB8
F0078DF4: d006202c                 ld      [%i0+0x2C], %o0
F0078DF8: d206202c                 ld      [%i0+0x2C], %o1
F0078DFC: 11080000                 sethi   0x20000000, %o0
F0078E00: 808a4008                 btst    %o0, %o1
F0078E04: 128000a4                 bne     loc_F0079094
F0078E08: 11040000                 sethi   0x10000000, %o0
F0078E0C: 808a4008                 btst    %o0, %o1
F0078E10: 0280000b                 be      loc_F0078E3C
F0078E14: 113c0442                 sethi   -0xFEEF800, %o0
F0078E18: d0062018                 ld      [%i0+0x18], %o0
F0078E1C: 93322001                 srl     %o0, 1, %o1
F0078E20: 90020009                 add     %o0, %o1, %o0
F0078E24: 10800024                 ba      loc_F0078EB4
F0078E28: d0262018                 st      %o0, [%i0+0x18]
F0078E2C: 7fffc082                 call    _lock_done
F0078E30: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0078E34: 1080000e                 ba      loc_F0078E6C
F0078E38: 80a66000                 cmp     %i1, 0
F0078E3C: d00223e8                 ld      [%o0+0x3E8], %o0
F0078E40: 80a22000                 cmp     %o0, 0
F0078E44: 3280001d                 bne,a   loc_F0078EB8
F0078E48: d006202c                 ld      [%i0+0x2C], %o0
F0078E4C: 808a4011                 btst    %l1, %o1
F0078E50: 12bffff7                 bne     loc_F0078E2C
F0078E54: 01000000                 nop
F0078E58: d0062004                 ld      [%i0+4], %o0
F0078E5C: c0260000                 clr     [%i0]
F0078E60: 400077b1                 call    _splx
F0078E64: 01000000                 nop
F0078E68: 80a66000                 cmp     %i1, 0
F0078E6C: 3280000c                 bne,a   loc_F0078E9C
F0078E70: d2062028                 ld      [%i0+0x28], %o1
F0078E74: 10800094                 ba      locret_F00790C4
F0078E78: b0102000                 mov     0, %i0
F0078E7C: 7fffc06e                 call    _lock_done
F0078E80: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0078E84: 1080001a                 ba      loc_F0078EEC
F0078E88: d006202c                 ld      [%i0+0x2C], %o0
F0078E8C: 7fffbfce                 call    _lock_write
F0078E90: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0078E94: 10800038                 ba      loc_F0078F74
F0078E98: c0262024                 clr     [%i0+0x24]
F0078E9C: 113c0443                 sethi   %hi(aZoneSEmpty), %o0! "zone \"%s\" empty.\n"
F0078EA0: 7ffe6dee                 call    _printf
F0078EA4: 90122048                 bset    %lo(aZoneSEmpty), %o0! "zone \"%s\" empty.\n"
F0078EA8: 113c0443                 sethi   %hi(aZalloc), %o0! "zalloc"
F0078EAC: 7ffe70b1                 call    _panic
F0078EB0: 90122060                 bset    %lo(aZalloc), %o0! "zalloc"
F0078EB4: d006202c                 ld      [%i0+0x2C], %o0
F0078EB8: 808a0011                 btst    %l1, %o0
F0078EBC: 02800003                 be      loc_F0078EC8
F0078EC0: 90102001                 mov     1, %o0
F0078EC4: d0262024                 st      %o0, [%i0+0x24]
F0078EC8: d006202c                 ld      [%i0+0x2C], %o0
F0078ECC: 808a0011                 btst    %l1, %o0
F0078ED0: 12bfffeb                 bne     loc_F0078E7C
F0078ED4: 01000000                 nop
F0078ED8: d0062004                 ld      [%i0+4], %o0
F0078EDC: c0260000                 clr     [%i0]
F0078EE0: 40007791                 call    _splx
F0078EE4: 01000000                 nop
F0078EE8: d006202c                 ld      [%i0+0x2C], %o0
F0078EEC: 808a0011                 btst    %l1, %o0
F0078EF0: 02800033                 be      loc_F0078FBC
F0078EF4: 113c0442                 sethi   %hi(_zone_map), %o0
F0078EF8: d00223ec                 ld      [%o0+%lo(_zone_map)], %o0
F0078EFC: d4062020                 ld      [%i0+0x20], %o2
F0078F00: 40002a4c                 call    _kmem_alloc_pageable
F0078F04: 9207bff4                 add     %fp, var_C, %o1
F0078F08: 80a22000                 cmp     %o0, 0
F0078F0C: 02800004                 be      loc_F0078F1C
F0078F10: 113c0443                 sethi   %hi(aZalloc_0), %o0! "zalloc"
F0078F14: 7ffe7097                 call    _panic
F0078F18: 90122068                 bset    %lo(aZalloc_0), %o0! "zalloc"
F0078F1C: d207bff4                 ld      [%fp+var_C], %o1
F0078F20: d4062020                 ld      [%i0+0x20], %o2
F0078F24: 7ffffc66                 call    _zcram
F0078F28: 90100018                 mov     %i0, %o0
F0078F2C: d006202c                 ld      [%i0+0x2C], %o0
F0078F30: 808a0011                 btst    %l1, %o0
F0078F34: 12bfffd6                 bne     loc_F0078E8C
F0078F38: 01000000                 nop
F0078F3C: 40007713                 call    _splusclock
F0078F40: 01000000                 nop
F0078F44: a0100008                 mov     %o0, %l0
F0078F48: d0060000                 ld      [%i0], %o0
F0078F4C: 80a22000                 cmp     %o0, 0
F0078F50: 12bffffe                 bne     loc_F0078F48
F0078F54: 01000000                 nop
F0078F58: 400077d4                 call    _simple_lock_try
F0078F5C: 90100018                 mov     %i0, %o0
F0078F60: 80a22000                 cmp     %o0, 0
F0078F64: 02bffff9                 be      loc_F0078F48
F0078F68: 01000000                 nop
F0078F6C: e0262004                 st      %l0, [%i0+4]
F0078F70: c0262024                 clr     [%i0+0x24]
F0078F74: 90062024                 add     %i0, 0x24, %o0 ! '$'
F0078F78: 92102000                 mov     0, %o1
F0078F7C: 7fffe020                 call    _thread_wakeup_prim
F0078F80: 94102000                 mov     0, %o2
F0078F84: d4062010                 ld      [%i0+0x10], %o2
F0078F88: 80a2a000                 cmp     %o2, 0
F0078F8C: 0280003e                 be      loc_F0079084
F0078F90: d427bff4                 st      %o2, [%fp+var_C]
F0078F94: d0062008                 ld      [%i0+8], %o0
F0078F98: d206200c                 ld      [%i0+0xC], %o1
F0078F9C: 90022001                 inc     %o0
F0078FA0: d0262008                 st      %o0, [%i0+8]
F0078FA4: d0028000                 ld      [%o2], %o0
F0078FA8: 80a2400a                 cmp     %o1, %o2
F0078FAC: 12800036                 bne     loc_F0079084
F0078FB0: d0262010                 st      %o0, [%i0+0x10]
F0078FB4: 10800034                 ba      loc_F0079084
F0078FB8: c026200c                 clr     [%i0+0xC]
F0078FBC: d006203c                 ld      [%i0+0x3C], %o0
F0078FC0: d206201c                 ld      [%i0+0x1C], %o1
F0078FC4: 7ffffe08                 call    _zget_space
F0078FC8: 94100019                 mov     %i1, %o2
F0078FCC: 80a22000                 cmp     %o0, 0
F0078FD0: 1280000d                 bne     loc_F0079004
F0078FD4: d027bff4                 st      %o0, [%fp+var_C]
F0078FD8: 80a66000                 cmp     %i1, 0
F0078FDC: 12800008                 bne     loc_F0078FFC
F0078FE0: 113c0443                 sethi   -0xFEEF400, %o0
F0078FE4: 10800038                 ba      locret_F00790C4
F0078FE8: b0102000                 mov     0, %i0
F0078FEC: 7fffbf76                 call    _lock_write
F0078FF0: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0078FF4: 10800016                 ba      loc_F007904C
F0078FF8: d0062008                 ld      [%i0+8], %o0! char *
F0078FFC: 7ffe705d                 call    _panic
F0079000: 90122070                 bset    0x70, %o0 ! 'p'
F0079004: d006202c                 ld      [%i0+0x2C], %o0
F0079008: 808a0011                 btst    %l1, %o0
F007900C: 12bffff8                 bne     loc_F0078FEC
F0079010: 01000000                 nop
F0079014: 400076dd                 call    _splusclock
F0079018: 01000000                 nop
F007901C: a0100008                 mov     %o0, %l0
F0079020: d0060000                 ld      [%i0], %o0
F0079024: 80a22000                 cmp     %o0, 0
F0079028: 12bffffe                 bne     loc_F0079020
F007902C: 01000000                 nop
F0079030: 4000779e                 call    _simple_lock_try
F0079034: 90100018                 mov     %i0, %o0
F0079038: 80a22000                 cmp     %o0, 0
F007903C: 02bffff9                 be      loc_F0079020
F0079040: 01000000                 nop
F0079044: e0262004                 st      %l0, [%i0+4]
F0079048: d0062008                 ld      [%i0+8], %o0
F007904C: d2062014                 ld      [%i0+0x14], %o1
F0079050: d406201c                 ld      [%i0+0x1C], %o2
F0079054: 90022001                 inc     %o0
F0079058: d0262008                 st      %o0, [%i0+8]
F007905C: 9202400a                 add     %o1, %o2, %o1
F0079060: d2262014                 st      %o1, [%i0+0x14]
F0079064: d006202c                 ld      [%i0+0x2C], %o0
F0079068: 808a0011                 btst    %l1, %o0
F007906C: 1280000e                 bne     loc_F00790A4
F0079070: 01000000                 nop
F0079074: 10800010                 ba      loc_F00790B4
F0079078: d0062004                 ld      [%i0+4], %o0
F007907C: 7fffbf52                 call    _lock_write
F0079080: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0079084: d007bff4                 ld      [%fp+var_C], %o0
F0079088: 80a22000                 cmp     %o0, 0
F007908C: 22bfff17                 be,a    loc_F0078CE8
F0079090: d0062024                 ld      [%i0+0x24], %o0
F0079094: d006202c                 ld      [%i0+0x2C], %o0
F0079098: 80a22000                 cmp     %o0, 0
F007909C: 36800006                 bge,a   loc_F00790B4
F00790A0: d0062004                 ld      [%i0+4], %o0
F00790A4: 7fffbfe4                 call    _lock_done
F00790A8: 90062030                 add     %i0, 0x30, %o0 ! '0'
F00790AC: 10800006                 ba      locret_F00790C4
F00790B0: f007bff4                 ld      [%fp+var_C], %i0
F00790B4: c0260000                 clr     [%i0]
F00790B8: 4000771b                 call    _splx
F00790BC: 01000000                 nop
F00790C0: f007bff4                 ld      [%fp+var_C], %i0
F00790C4: 81c7e008                 ret
F00790C8: 81e80000                 restore
