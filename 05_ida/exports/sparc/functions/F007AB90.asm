F007AB90: 9de3bf90                 save    %sp, -0x70, %sp
F007AB94: d0062028                 ld      [%i0+0x28], %o0
F007AB98: d4062024                 ld      [%i0+0x24], %o2
F007AB9C: 133c04d0                 sethi   %hi(_page_mask), %o1
F007ABA0: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F007ABA4: 9022000a                 sub     %o0, %o2, %o0
F007ABA8: 90020009                 add     %o0, %o1, %o0
F007ABAC: 40006ff7                 call    _splusclock
F007ABB0: a42a0009                 andn    %o0, %o1, %l2
F007ABB4: a2100008                 mov     %o0, %l1
F007ABB8: d0060000                 ld      [%i0], %o0
F007ABBC: 80a22000                 cmp     %o0, 0
F007ABC0: 12bffffe                 bne     loc_F007ABB8
F007ABC4: 01000000                 nop
F007ABC8: 400070b8                 call    _simple_lock_try
F007ABCC: 90100018                 mov     %i0, %o0
F007ABD0: 80a22000                 cmp     %o0, 0
F007ABD4: 02bffff9                 be      loc_F007ABB8
F007ABD8: 01000000                 nop
F007ABDC: c0260000                 clr     [%i0]
F007ABE0: e0062018                 ld      [%i0+0x18], %l0
F007ABE4: 90100011                 mov     %l1, %o0
F007ABE8: 4000704f                 call    _splx
F007ABEC: c0262018                 clr     [%i0+0x18]
F007ABF0: 80a42000                 cmp     %l0, 0
F007ABF4: 02800026                 be      locret_F007AC8C
F007ABF8: 94100012                 mov     %l2, %o2
F007ABFC: d00624cc                 ld      [%i0+0x4CC], %o0
F007AC00: 9607bff4                 add     %fp, var_C, %o3
F007AC04: d2062024                 ld      [%i0+0x24], %o1
F007AC08: 4001e62b                 call    _vm_read_EXTERNAL
F007AC0C: 9807bff0                 add     %fp, var_10, %o4
F007AC10: d4062028                 ld      [%i0+0x28], %o2
F007AC14: d6062024                 ld      [%i0+0x24], %o3
F007AC18: 90100010                 mov     %l0, %o0
F007AC1C: d207bff4                 ld      [%fp+var_C], %o1
F007AC20: 9422800b                 sub     %o2, %o3, %o2
F007AC24: 40000497                 call    _kern_serv_log_data
F007AC28: 953aa005                 sra     %o2, 5, %o2
F007AC2C: d0062008                 ld      [%i0+8], %o0
F007AC30: 4001e40f                 call    _port_deallocate_EXTERNAL
F007AC34: 92100010                 mov     %l0, %o1
F007AC38: d0062008                 ld      [%i0+8], %o0
F007AC3C: d207bff4                 ld      [%fp+var_C], %o1
F007AC40: 4001e5da                 call    _vm_deallocate_EXTERNAL
F007AC44: 94100012                 mov     %l2, %o2
F007AC48: 40006fd0                 call    _splusclock
F007AC4C: 01000000                 nop
F007AC50: a2100008                 mov     %o0, %l1
F007AC54: d0060000                 ld      [%i0], %o0
F007AC58: 80a22000                 cmp     %o0, 0
F007AC5C: 12bffffe                 bne     loc_F007AC54
F007AC60: 01000000                 nop
F007AC64: 40007091                 call    _simple_lock_try
F007AC68: 90100018                 mov     %i0, %o0
F007AC6C: 80a22000                 cmp     %o0, 0
F007AC70: 02bffff9                 be      loc_F007AC54
F007AC74: 01000000                 nop
F007AC78: c0260000                 clr     [%i0]
F007AC7C: d2062024                 ld      [%i0+0x24], %o1
F007AC80: 90100011                 mov     %l1, %o0
F007AC84: 40007028                 call    _splx
F007AC88: d2262028                 st      %o1, [%i0+0x28]
F007AC8C: 81c7e008                 ret
F007AC90: 81e80000                 restore
