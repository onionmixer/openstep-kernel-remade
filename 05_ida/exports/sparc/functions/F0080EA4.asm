F0080EA4: 9de3bf10                 save    %sp, -0xF0, %sp
F0080EA8: 113c04d0                 sethi   %hi(_active_threads), %o0
F0080EAC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0080EB0: e202200c                 ld      [%o0+0xC], %l1
F0080EB4: 90102001                 mov     1, %o0
F0080EB8: 7fff98fe                 call    _task_self
F0080EBC: d0246050                 st      %o0, [%l1+0x50]
F0080EC0: 133c04c3                 sethi   %hi(dword_F0130F60), %o1
F0080EC4: d0226360                 st      %o0, [%o1+%lo(dword_F0130F60)]
F0080EC8: 113c04c3a012235c         set     dword_F0130F5C, %l0
F0080ED0: d0040000                 ld      [%l0], %o0
F0080ED4: 80a22000                 cmp     %o0, 0
F0080ED8: 12bffffe                 bne     loc_F0080ED0
F0080EDC: 01000000                 nop
F0080EE0: 400057f2                 call    _simple_lock_try
F0080EE4: 90100010                 mov     %l0, %o0
F0080EE8: 80a22000                 cmp     %o0, 0
F0080EEC: 02bffff9                 be      loc_F0080ED0
F0080EF0: 273c04c3                 sethi   %hi(dword_F0130F60), %l3
F0080EF4: d004e360                 ld      [%l3+%lo(dword_F0130F60)], %o0
F0080EF8: 4001cbdf                 call    _port_set_allocate_EXTERNAL
F0080EFC: 9207bff4                 add     %fp, var_C, %o1
F0080F00: 80a22000                 cmp     %o0, 0
F0080F04: 02800004                 be      loc_F0080F14
F0080F08: 113c0445                 sethi   %hi(aUxHandlerPortS), %o0! "ux_handler: port_set_allocate failed"
F0080F0C: 7ffe5099                 call    _panic
F0080F10: 90122398                 bset    %lo(aUxHandlerPortS), %o0! "ux_handler: port_set_allocate failed"
F0080F14: d004e360                 ld      [%l3+0x360], %o0
F0080F18: 4001cb12                 call    _port_allocate_EXTERNAL
F0080F1C: 9207bff0                 add     %fp, var_10, %o1
F0080F20: 80a22000                 cmp     %o0, 0
F0080F24: 02800004                 be      loc_F0080F34
F0080F28: 113c0445                 sethi   %hi(aUxHandlerPortA), %o0! "ux_handler: port_allocate failed"
F0080F2C: 7ffe5091                 call    _panic
F0080F30: 901223c0                 bset    %lo(aUxHandlerPortA), %o0! "ux_handler: port_allocate failed"
F0080F34: d004e360                 ld      [%l3+0x360], %o0
F0080F38: d207bff4                 ld      [%fp+var_C], %o1
F0080F3C: 4001cb8b                 call    _port_set_add_EXTERNAL
F0080F40: d407bff0                 ld      [%fp+var_10], %o2
F0080F44: 80a22000                 cmp     %o0, 0
F0080F48: 02800004                 be      loc_F0080F58
F0080F4C: 113c0445                 sethi   %hi(aUxHandlerPortS_0), %o0! "ux_handler: port_set_add failed"
F0080F50: 7ffe5088                 call    _panic
F0080F54: 901223e8                 bset    %lo(aUxHandlerPortS_0), %o0! "ux_handler: port_set_add failed"
F0080F58: 90100011                 mov     %l1, %o0
F0080F5C: d207bff0                 ld      [%fp+var_10], %o1
F0080F60: 94102006                 mov     6, %o2
F0080F64: 173c04d2a012e1e0         set     _ux_exception_port, %l0
F0080F6C: 96102000                 mov     0, %o3
F0080F70: 7fff9ba6                 call    _object_copyin
F0080F74: 98100010                 mov     %l0, %o4
F0080F78: 80a22000                 cmp     %o0, 0
F0080F7C: 32800006                 bne,a   loc_F0080F94
F0080F80: 90100010                 mov     %l0, %o0
F0080F84: 113c0446                 sethi   %hi(aUxHandlerObjec), %o0! "ux_handler: object_copyin(ux_exception_"...
F0080F88: 7ffe507a                 call    _panic
F0080F8C: 90122008                 bset    %lo(aUxHandlerObjec), %o0! "ux_handler: object_copyin(ux_exception_"...
F0080F90: 90100010                 mov     %l0, %o0
F0080F94: 92102000                 mov     0, %o1
F0080F98: 7fffc019                 call    _thread_wakeup_prim
F0080F9C: 94102000                 mov     0, %o2
F0080FA0: 113c04c3                 sethi   %hi(dword_F0130F5C), %o0
F0080FA4: c022235c                 clr     [%o0+%lo(dword_F0130F5C)]
F0080FA8: 113c0446                 sethi   %hi(aUxExcept), %o0! "ux_except"
F0080FAC: 7ffe206c                 call    _task_name
F0080FB0: 90122040                 bset    %lo(aUxExcept), %o0! "ux_except"
F0080FB4: aa102058                 mov     0x58, %l5 ! 'X'
F0080FB8: a407bf70                 add     %fp, var_90, %l2
F0080FBC: a207bfc8                 add     %fp, var_38, %l1
F0080FC0: a8100013                 mov     %l3, %l4
F0080FC4: 273c0446                 sethi   -0xFEEE800, %l3
F0080FC8: ea27bf74                 st      %l5, [%fp+var_8C]
F0080FCC: 90100012                 mov     %l2, %o0
F0080FD0: 92102000                 mov     0, %o1
F0080FD4: d607bff4                 ld      [%fp+var_C], %o3
F0080FD8: 94102000                 mov     0, %o2
F0080FDC: 7fff93a0                 call    _msg_receive
F0080FE0: d627bf7c                 st      %o3, [%fp+var_84]
F0080FE4: 80a22000                 cmp     %o0, 0
F0080FE8: 12800014                 bne     loc_F0081038
F0080FEC: 80a23f34                 cmp     %o0, -0xCC
F0080FF0: 90100012                 mov     %l2, %o0
F0080FF4: e007bf80                 ld      [%fp+var_80], %l0
F0080FF8: 7fffebf5                 call    _exc_server
F0080FFC: 92100011                 mov     %l1, %o1
F0081000: 80a22000                 cmp     %o0, 0
F0081004: 02800005                 be      loc_F0081018
F0081008: 90100011                 mov     %l1, %o0
F008100C: 92102000                 mov     0, %o1
F0081010: 7fff9331                 call    _msg_send
F0081014: 94102000                 mov     0, %o2
F0081018: 80a42000                 cmp     %l0, 0
F008101C: 22bfffec                 be,a    loc_F0080FCC
F0081020: ea27bf74                 st      %l5, [%fp+var_8C]
F0081024: d0052360                 ld      [%l4+0x360], %o0! char *
F0081028: 4001cb11                 call    _port_deallocate_EXTERNAL
F008102C: 92100010                 mov     %l0, %o1
F0081030: 10bfffe7                 ba      loc_F0080FCC
F0081034: ea27bf74                 st      %l5, [%fp+var_8C]
F0081038: 22bfffe5                 be,a    loc_F0080FCC
F008103C: ea27bf74                 st      %l5, [%fp+var_8C]
F0081040: 7ffe504c                 call    _panic
F0081044: 9014e050                 or      %l3, 0x50, %o0
F0081048: 10bfffe1                 ba      loc_F0080FCC
F008104C: ea27bf74                 st      %l5, [%fp+var_8C]
