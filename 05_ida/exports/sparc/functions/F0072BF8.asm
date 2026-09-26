F0072BF8: 9de3bf88                 save    %sp, -0x78, %sp! int
F0072BFC: 113c04d0                 sethi   %hi(_active_threads), %o0
F0072C00: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0072C04: d002200c                 ld      [%o0+0xC], %o0
F0072C08: e402200c                 ld      [%o0+0xC], %l2
F0072C0C: 7ffe621e                 call    _getf
F0072C10: 90100018                 mov     %i0, %o0
F0072C14: 92920000                 orcc    %o0, %g0, %o1
F0072C18: 22800073                 be,a    locret_F0072DE4
F0072C1C: b0102004                 mov     4, %i0
F0072C20: d052600c                 ldsh    [%o1+0xC], %o0
F0072C24: 80a22001                 cmp     %o0, 1
F0072C28: 12800034                 bne     loc_F0072CF8
F0072C2C: e6026018                 ld      [%o1+0x18], %l3
F0072C30: d004e028                 ld      [%l3+0x28], %o0
F0072C34: 80a22001                 cmp     %o0, 1
F0072C38: 3280006b                 bne,a   locret_F0072DE4
F0072C3C: b0102004                 mov     4, %i0
F0072C40: 213c04d0                 sethi   %hi(_page_mask), %l0
F0072C44: d20420d8                 ld      [%l0+%lo(_page_mask)], %o1
F0072C48: 80a6e000                 cmp     %i3, 0
F0072C4C: 90070009                 add     %i4, %o1, %o0
F0072C50: 02800016                 be      loc_F0072CA8
F0072C54: a22a0009                 andn    %o0, %o1, %l1
F0072C58: 90100012                 mov     %l2, %o0! target_task
F0072C5C: a007bff4                 add     %fp, address, %l0
F0072C60: 92100010                 mov     %l0, %o1! address
F0072C64: 9410001c                 mov     %i4, %o2! int
F0072C68: 40005eee                 call    _vm_allocate
F0072C6C: 96102001                 mov     1, %o3! int
F0072C70: b0920000                 orcc    %o0, %g0, %i0
F0072C74: 1280005c                 bne     locret_F0072DE4
F0072C78: 90100010                 mov     %l0, %o0! int
F0072C7C: 9210001a                 mov     %i2, %o1! int
F0072C80: 40009513                 call    _copyout
F0072C84: 94102004                 mov     4, %o2! size
F0072C88: 80a22000                 cmp     %o0, 0
F0072C8C: 0280001d                 be      loc_F0072D00
F0072C90: 90100012                 mov     %l2, %o0! target_task
F0072C94: d207bff4                 ld      [%fp+address], %o1! address
F0072C98: 40005f02                 call    _vm_deallocate
F0072C9C: 9410001c                 mov     %i4, %o2! int
F0072CA0: 10800051                 ba      locret_F0072DE4
F0072CA4: b0102001                 mov     1, %i0
F0072CA8: 9010001a                 mov     %i2, %o0! int
F0072CAC: 9207bff4                 add     %fp, address, %o1! int
F0072CB0: 400094ea                 call    _copyin
F0072CB4: 94102004                 mov     4, %o2
F0072CB8: 80a22000                 cmp     %o0, 0
F0072CBC: 1280004a                 bne     locret_F0072DE4
F0072CC0: b0102001                 mov     1, %i0
F0072CC4: d20420d8                 ld      [%l0+0xD8], %o1
F0072CC8: d007bff4                 ld      [%fp+address], %o0
F0072CCC: 922a0009                 andn    %o0, %o1, %o1
F0072CD0: 80a24008                 cmp     %o1, %o0
F0072CD4: 12800044                 bne     locret_F0072DE4
F0072CD8: b0102004                 mov     4, %i0
F0072CDC: 90100012                 mov     %l2, %o0
F0072CE0: 94024011                 add     %o1, %l1, %o2
F0072CE4: 400049b2                 call    _vm_map_check_protection
F0072CE8: 96102003                 mov     3, %o3
F0072CEC: 80a22000                 cmp     %o0, 0
F0072CF0: 12800005                 bne     loc_F0072D04
F0072CF4: 80a72000                 cmp     %i4, 0
F0072CF8: 1080003b                 ba      locret_F0072DE4
F0072CFC: b0102004                 mov     4, %i0
F0072D00: 80a72000                 cmp     %i4, 0
F0072D04: 12800004                 bne     loc_F0072D14
F0072D08: 90100013                 mov     %l3, %o0
F0072D0C: 10800036                 ba      locret_F0072DE4
F0072D10: b0102000                 mov     0, %i0
F0072D14: 92102000                 mov     0, %o1
F0072D18: 40006209                 call    _vnode_pager_setup
F0072D1C: 94102000                 mov     0, %o2
F0072D20: a0100008                 mov     %o0, %l0
F0072D24: 4000a6a7                 call    _pmap_create
F0072D28: 90100011                 mov     %l1, %o0
F0072D2C: 92102000                 mov     0, %o1
F0072D30: 94100011                 mov     %l1, %o2
F0072D34: 400044df                 call    _vm_map_create
F0072D38: 96102001                 mov     1, %o3
F0072D3C: c027bff0                 clr     [%fp+var_10]
F0072D40: b4100008                 mov     %o0, %i2
F0072D44: 9207bff0                 add     %fp, var_10, %o1
F0072D48: 94100011                 mov     %l1, %o2
F0072D4C: 96102000                 mov     0, %o3
F0072D50: 98100010                 mov     %l0, %o4
F0072D54: 40005e74                 call    _vm_allocate_with_pager
F0072D58: 9a100019                 mov     %i1, %o5
F0072D5C: b0920000                 orcc    %o0, %g0, %i0
F0072D60: 1280000a                 bne     loc_F0072D88
F0072D64: 90100012                 mov     %l2, %o0
F0072D68: 9210001a                 mov     %i2, %o1
F0072D6C: 96100011                 mov     %l1, %o3
F0072D70: 98102000                 mov     0, %o4
F0072D74: d407bff4                 ld      [%fp+address], %o2! size
F0072D78: 9a102000                 mov     0, %o5
F0072D7C: 40004a2d                 call    _vm_map_copy
F0072D80: c023a05c                 clr     [%sp+0x78+var_1C]
F0072D84: b0920000                 orcc    %o0, %g0, %i0
F0072D88: 02800007                 be      loc_F0072DA4
F0072D8C: 80a6e000                 cmp     %i3, 0
F0072D90: 02800005                 be      loc_F0072DA4
F0072D94: 90100012                 mov     %l2, %o0! target_task
F0072D98: d207bff4                 ld      [%fp+address], %o1! address
F0072D9C: 40005ec1                 call    _vm_deallocate
F0072DA0: 94100011                 mov     %l1, %o2
F0072DA4: 4000451a                 call    _vm_map_deallocate
F0072DA8: 9010001a                 mov     %i2, %o0
F0072DAC: d004c000                 ld      [%l3], %o0
F0072DB0: d0022030                 ld      [%o0+0x30], %o0
F0072DB4: 80a22000                 cmp     %o0, 0
F0072DB8: 1280000b                 bne     locret_F0072DE4
F0072DBC: 153c04cf                 sethi   %hi(_active_u), %o2
F0072DC0: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F0072DC4: d202201c                 ld      [%o0+0x1C], %o1
F0072DC8: d0124000                 lduh    [%o1], %o0
F0072DCC: 90022001                 inc     %o0
F0072DD0: d0324000                 sth     %o0, [%o1]
F0072DD4: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F0072DD8: d204c000                 ld      [%l3], %o1
F0072DDC: d002201c                 ld      [%o0+0x1C], %o0
F0072DE0: d0226030                 st      %o0, [%o1+0x30]
F0072DE4: 81c7e008                 ret
F0072DE8: 81e80000                 restore
