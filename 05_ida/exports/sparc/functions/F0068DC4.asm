F0068DC4: 9de3bf98                 save    %sp, -0x68, %sp
F0068DC8: a0062008                 add     %i0, 8, %l0
F0068DCC: d0040000                 ld      [%l0], %o0
F0068DD0: 80a22000                 cmp     %o0, 0
F0068DD4: 12bffffe                 bne     loc_F0068DCC
F0068DD8: 01000000                 nop
F0068DDC: 4000b833                 call    _simple_lock_try
F0068DE0: 90100010                 mov     %l0, %o0
F0068DE4: 80a22000                 cmp     %o0, 0
F0068DE8: 02bffff9                 be      loc_F0068DCC
F0068DEC: 133c04d0                 sethi   %hi(_active_threads), %o1
F0068DF0: d0060000                 ld      [%i0], %o0
F0068DF4: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0068DF8: 80a20009                 cmp     %o0, %o1
F0068DFC: 1280000a                 bne     loc_F0068E24
F0068E00: d0062004                 ld      [%i0+4], %o0
F0068E04: c0262008                 clr     [%i0+8]
F0068E08: 920a3000                 and     %o0, -0x1000, %o1
F0068E0C: 900a2fff                 and     %o0, 0xFFF, %o0
F0068E10: 90022001                 inc     %o0
F0068E14: 900a2fff                 and     %o0, 0xFFF, %o0
F0068E18: 92124008                 bset    %o0, %o1
F0068E1C: 10800084                 ba      locret_F006902C
F0068E20: d2262004                 st      %o1, [%i0+4]
F0068E24: 13000010                 sethi   0x4000, %o1
F0068E28: 808a0009                 btst    %o1, %o0
F0068E2C: 2280003e                 be,a    loc_F0068F24
F0068E30: d0062004                 ld      [%i0+4], %o0
F0068E34: 273c043e                 sethi   %hi(_lock_wait_time), %l3
F0068E38: a4100009                 mov     %o1, %l2
F0068E3C: a2062008                 add     %i0, 8, %l1
F0068E40: d204e380                 ld      [%l3+%lo(_lock_wait_time)], %o1
F0068E44: 80a26000                 cmp     %o1, 0
F0068E48: 2480001b                 ble,a   loc_F0068EB4
F0068E4C: d4062004                 ld      [%i0+4], %o2
F0068E50: c0262008                 clr     [%i0+8]
F0068E54: 92027fff                 inc     -1, %o1
F0068E58: 80a26000                 cmp     %o1, 0
F0068E5C: 0480000c                 ble     loc_F0068E8C
F0068E60: a0062008                 add     %i0, 8, %l0
F0068E64: d0062004                 ld      [%i0+4], %o0
F0068E68: 900a0012                 and     %o0, %l2, %o0
F0068E6C: 80a22000                 cmp     %o0, 0
F0068E70: 02800007                 be      loc_F0068E8C
F0068E74: a0062008                 add     %i0, 8, %l0
F0068E78: 92027fff                 inc     -1, %o1
F0068E7C: 80a26000                 cmp     %o1, 0
F0068E80: 14bffffc                 bg      loc_F0068E70
F0068E84: 80a22000                 cmp     %o0, 0
F0068E88: a0062008                 add     %i0, 8, %l0
F0068E8C: d0040000                 ld      [%l0], %o0
F0068E90: 80a22000                 cmp     %o0, 0
F0068E94: 12bffffe                 bne     loc_F0068E8C
F0068E98: 01000000                 nop
F0068E9C: 4000b803                 call    _simple_lock_try
F0068EA0: 90100010                 mov     %l0, %o0
F0068EA4: 80a22000                 cmp     %o0, 0
F0068EA8: 02bffff9                 be      loc_F0068E8C
F0068EAC: 01000000                 nop
F0068EB0: d4062004                 ld      [%i0+4], %o2
F0068EB4: 13000014                 sethi   0x5000, %o1
F0068EB8: 900a8009                 and     %o2, %o1, %o0
F0068EBC: 80a20009                 cmp     %o0, %o1
F0068EC0: 32800014                 bne,a   loc_F0068F10
F0068EC4: d0062004                 ld      [%i0+4], %o0
F0068EC8: 1100000890128008         set     0x2000, %o0
F0068ED0: d0262004                 st      %o0, [%i0+4]
F0068ED4: 90100018                 mov     %i0, %o0
F0068ED8: 92100011                 mov     %l1, %o1
F0068EDC: 400020b8                 call    _thread_sleep
F0068EE0: 94102000                 mov     0, %o2
F0068EE4: a0100011                 mov     %l1, %l0
F0068EE8: d0040000                 ld      [%l0], %o0
F0068EEC: 80a22000                 cmp     %o0, 0
F0068EF0: 12bffffe                 bne     loc_F0068EE8
F0068EF4: 01000000                 nop
F0068EF8: 4000b7ec                 call    _simple_lock_try
F0068EFC: 90100010                 mov     %l0, %o0
F0068F00: 80a22000                 cmp     %o0, 0
F0068F04: 02bffff9                 be      loc_F0068EE8
F0068F08: 01000000                 nop
F0068F0C: d0062004                 ld      [%i0+4], %o0
F0068F10: 808a0012                 btst    %l2, %o0
F0068F14: 12bfffcc                 bne     loc_F0068E44
F0068F18: d204e380                 ld      [%l3+0x380], %o1
F0068F1C: d0062004                 ld      [%i0+4], %o0
F0068F20: 13000010                 sethi   0x4000, %o1
F0068F24: 90120009                 bset    %o1, %o0
F0068F28: 133fffe0                 sethi   -0x8000, %o1
F0068F2C: 808a0009                 btst    %o1, %o0
F0068F30: 0280003e                 be      loc_F0069028
F0068F34: d0262004                 st      %o0, [%i0+4]
F0068F38: a4100009                 mov     %o1, %l2
F0068F3C: a2062008                 add     %i0, 8, %l1
F0068F40: 113c043e                 sethi   -0xFEF0800, %o0
F0068F44: d2022380                 ld      [%o0+0x380], %o1
F0068F48: 80a26000                 cmp     %o1, 0
F0068F4C: 2480001b                 ble,a   loc_F0068FB8
F0068F50: d2062004                 ld      [%i0+4], %o1
F0068F54: c0262008                 clr     [%i0+8]
F0068F58: 92027fff                 inc     -1, %o1
F0068F5C: 80a26000                 cmp     %o1, 0
F0068F60: 2480000c                 ble,a   loc_F0068F90
F0068F64: a0062008                 add     %i0, 8, %l0
F0068F68: d0062004                 ld      [%i0+4], %o0
F0068F6C: 900a0012                 and     %o0, %l2, %o0
F0068F70: 80a22000                 cmp     %o0, 0
F0068F74: 22800007                 be,a    loc_F0068F90
F0068F78: a0062008                 add     %i0, 8, %l0
F0068F7C: 92027fff                 inc     -1, %o1
F0068F80: 80a26000                 cmp     %o1, 0
F0068F84: 14bffffc                 bg      loc_F0068F74
F0068F88: 80a22000                 cmp     %o0, 0
F0068F8C: a0062008                 add     %i0, 8, %l0
F0068F90: d0040000                 ld      [%l0], %o0
F0068F94: 80a22000                 cmp     %o0, 0
F0068F98: 12bffffe                 bne     loc_F0068F90
F0068F9C: 01000000                 nop
F0068FA0: 4000b7c2                 call    _simple_lock_try
F0068FA4: 90100010                 mov     %l0, %o0
F0068FA8: 80a22000                 cmp     %o0, 0
F0068FAC: 02bffff9                 be      loc_F0068F90
F0068FB0: 01000000                 nop
F0068FB4: d2062004                 ld      [%i0+4], %o1
F0068FB8: 11000004                 sethi   0x1000, %o0
F0068FBC: 808a4008                 btst    %o0, %o1
F0068FC0: 22800017                 be,a    loc_F006901C
F0068FC4: d0062004                 ld      [%i0+4], %o0
F0068FC8: 808a4012                 btst    %l2, %o1
F0068FCC: 22800014                 be,a    loc_F006901C
F0068FD0: d0062004                 ld      [%i0+4], %o0
F0068FD4: 1100000890124008         set     0x2000, %o0
F0068FDC: d0262004                 st      %o0, [%i0+4]
F0068FE0: 90100018                 mov     %i0, %o0
F0068FE4: 92100011                 mov     %l1, %o1
F0068FE8: 40002075                 call    _thread_sleep
F0068FEC: 94102000                 mov     0, %o2
F0068FF0: a0100011                 mov     %l1, %l0
F0068FF4: d0040000                 ld      [%l0], %o0
F0068FF8: 80a22000                 cmp     %o0, 0
F0068FFC: 12bffffe                 bne     loc_F0068FF4
F0069000: 01000000                 nop
F0069004: 4000b7a9                 call    _simple_lock_try
F0069008: 90100010                 mov     %l0, %o0
F006900C: 80a22000                 cmp     %o0, 0
F0069010: 02bffff9                 be      loc_F0068FF4
F0069014: 01000000                 nop
F0069018: d0062004                 ld      [%i0+4], %o0
F006901C: 808a0012                 btst    %l2, %o0
F0069020: 12bfffc9                 bne     loc_F0068F44
F0069024: 113c043e                 sethi   -0xFEF0800, %o0
F0069028: c0262008                 clr     [%i0+8]
F006902C: 81c7e008                 ret
F0069030: 81e80000                 restore
