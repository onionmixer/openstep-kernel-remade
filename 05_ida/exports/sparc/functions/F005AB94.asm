F005AB94: 9de3bf98                 save    %sp, -0x68, %sp
F005AB98: e0062028                 ld      [%i0+0x28], %l0
F005AB9C: 80a42000                 cmp     %l0, 0
F005ABA0: 02800028                 be      loc_F005AC40
F005ABA4: 01000000                 nop
F005ABA8: c0262028                 clr     [%i0+0x28]
F005ABAC: c0262010                 clr     [%i0+0x10]
F005ABB0: c026200c                 clr     [%i0+0xC]
F005ABB4: c0260000                 clr     [%i0]
F005ABB8: 808c2001                 btst    1, %l0
F005ABBC: 0280000e                 be      loc_F005ABF4
F005ABC0: 90100018                 mov     %i0, %o0
F005ABC4: a00c3ffe                 and     %l0, -2, %l0
F005ABC8: 4000007f                 call    _ipc_port_check_circularity
F005ABCC: 92100010                 mov     %l0, %o1
F005ABD0: 80a22000                 cmp     %o0, 0
F005ABD4: 12800005                 bne     loc_F005ABE8
F005ABD8: 90100010                 mov     %l0, %o0
F005ABDC: 7ffffa64                 call    _ipc_notify_port_destroyed_compat
F005ABE0: 92100018                 mov     %i0, %o1
F005ABE4: 30800076                 ba,a    locret_F005ADBC
F005ABE8: 4000014d                 call    _ipc_port_release_send
F005ABEC: 90100010                 mov     %l0, %o0
F005ABF0: 3080000b                 ba,a    loc_F005AC1C
F005ABF4: 40000074                 call    _ipc_port_check_circularity
F005ABF8: 92100010                 mov     %l0, %o1
F005ABFC: 80a22000                 cmp     %o0, 0
F005AC00: 12800005                 bne     loc_F005AC14
F005AC04: 90100010                 mov     %l0, %o0
F005AC08: 7ffff951                 call    _ipc_notify_port_destroyed
F005AC0C: 92100018                 mov     %i0, %o1
F005AC10: 3080006b                 ba,a    locret_F005ADBC
F005AC14: 40000187                 call    _ipc_port_release_sonce
F005AC18: 90100010                 mov     %l0, %o0
F005AC1C: d0060000                 ld      [%i0], %o0
F005AC20: 80a22000                 cmp     %o0, 0
F005AC24: 12bffffe                 bne     loc_F005AC1C
F005AC28: 01000000                 nop
F005AC2C: 4000f09f                 call    _simple_lock_try
F005AC30: 90100018                 mov     %i0, %o0
F005AC34: 80a22000                 cmp     %o0, 0
F005AC38: 02bffff9                 be      loc_F005AC1C
F005AC3C: 01000000                 nop
F005AC40: 40001061                 call    _ipc_thread_dequeue
F005AC44: 9006204c                 add     %i0, 0x4C, %o0 ! 'L'
F005AC48: 80a22000                 cmp     %o0, 0
F005AC4C: 22800005                 be,a    loc_F005AC60
F005AC50: d2062008                 ld      [%i0+8], %o1
F005AC54: 40002e70                 call    _thread_go
F005AC58: c0222098                 clr     [%o0+0x98]
F005AC5C: 30bffff9                 ba,a    loc_F005AC40
F005AC60: 11200000                 sethi   0x80000000, %o0
F005AC64: 902a4008                 andn    %o1, %o0, %o0
F005AC68: 7ffffe16                 call    _ipc_port_timestamp
F005AC6C: d0262008                 st      %o0, [%i0+8]
F005AC70: d026200c                 st      %o0, [%i0+0xC]
F005AC74: d0062024                 ld      [%i0+0x24], %o0
F005AC78: c0260000                 clr     [%i0]
F005AC7C: 80a22000                 cmp     %o0, 0
F005AC80: 02800004                 be      loc_F005AC90
F005AC84: a2062040                 add     %i0, 0x40, %l1 ! '@'
F005AC88: 7ffff98b                 call    _ipc_notify_send_once
F005AC8C: 01000000                 nop
F005AC90: d0044000                 ld      [%l1], %o0
F005AC94: 80a22000                 cmp     %o0, 0
F005AC98: 12bffffe                 bne     loc_F005AC90
F005AC9C: 01000000                 nop
F005ACA0: 4000f082                 call    _simple_lock_try
F005ACA4: 90100011                 mov     %l1, %o0
F005ACA8: 80a22000                 cmp     %o0, 0
F005ACAC: 02bffff9                 be      loc_F005AC90
F005ACB0: a4046004                 add     %l1, 4, %l2
F005ACB4: 7fffe835                 call    _ipc_kmsg_dequeue
F005ACB8: 90100012                 mov     %l2, %o0
F005ACBC: a0920000                 orcc    %o0, %g0, %l0
F005ACC0: 02800012                 be      loc_F005AD08
F005ACC4: 01000000                 nop
F005ACC8: c0244000                 clr     [%l1]
F005ACCC: 7ffffa69                 call    _ipc_object_release
F005ACD0: 90100018                 mov     %i0, %o0
F005ACD4: c024201c                 clr     [%l0+0x1C]
F005ACD8: 7fffe854                 call    _ipc_kmsg_destroy
F005ACDC: 90100010                 mov     %l0, %o0
F005ACE0: d0044000                 ld      [%l1], %o0
F005ACE4: 80a22000                 cmp     %o0, 0
F005ACE8: 12bffffe                 bne     loc_F005ACE0
F005ACEC: 01000000                 nop
F005ACF0: 4000f06e                 call    _simple_lock_try
F005ACF4: 90100011                 mov     %l1, %o0
F005ACF8: 80a22000                 cmp     %o0, 0
F005ACFC: 02bffff9                 be      loc_F005ACE0
F005AD00: 01000000                 nop
F005AD04: 30bfffec                 ba,a    loc_F005ACB4
F005AD08: c0244000                 clr     [%l1]
F005AD0C: e606202c                 ld      [%i0+0x2C], %l3
F005AD10: 80a4e000                 cmp     %l3, 0
F005AD14: 22800021                 be,a    loc_F005AD98
F005AD18: d2062008                 ld      [%i0+8], %o1
F005AD1C: e804e004                 ld      [%l3+4], %l4
F005AD20: e4050000                 ld      [%l4], %l2
F005AD24: a2102001                 mov     1, %l1
F005AD28: 80a44012                 cmp     %l1, %l2
F005AD2C: 3a800017                 bcc,a   loc_F005AD88
F005AD30: d0050000                 ld      [%l4], %o0
F005AD34: a004e008                 add     %l3, 8, %l0
F005AD38: d4042004                 ld      [%l0+4], %o2
F005AD3C: 80a2a000                 cmp     %o2, 0
F005AD40: 2280000e                 be,a    loc_F005AD78
F005AD44: a2046001                 inc     %l1
F005AD48: d2040000                 ld      [%l0], %o1
F005AD4C: 808a6001                 btst    1, %o1
F005AD50: 02800006                 be      loc_F005AD68
F005AD54: 90100018                 mov     %i0, %o0
F005AD58: 7fffff6d                 call    _ipc_port_delete_compat
F005AD5C: 920a7ffe                 and     %o1, -2, %o1
F005AD60: 10800006                 ba      loc_F005AD78
F005AD64: a2046001                 inc     %l1
F005AD68: 90100009                 mov     %o1, %o0
F005AD6C: 7ffff978                 call    _ipc_notify_dead_name
F005AD70: 9210000a                 mov     %o2, %o1
F005AD74: a2046001                 inc     %l1
F005AD78: 80a44012                 cmp     %l1, %l2
F005AD7C: 0abfffef                 bcs     loc_F005AD38
F005AD80: a0042008                 inc     8, %l0
F005AD84: d0050000                 ld      [%l4], %o0
F005AD88: 92100013                 mov     %l3, %o1
F005AD8C: 40000ff1                 call    _ipc_table_free
F005AD90: 912a2003                 sll     %o0, 3, %o0
F005AD94: d2062008                 ld      [%i0+8], %o1
F005AD98: 1100003f901223ff         set     0xFFFF, %o0
F005ADA0: 808a4008                 btst    %o0, %o1
F005ADA4: 02800004                 be      loc_F005ADB4
F005ADA8: 01000000                 nop
F005ADAC: 40002ab0                 call    _ipc_kobject_destroy
F005ADB0: 90100018                 mov     %i0, %o0
F005ADB4: 7ffffa2f                 call    _ipc_object_release
F005ADB8: 90100018                 mov     %i0, %o0
F005ADBC: 81c7e008                 ret
F005ADC0: 81e80000                 restore
