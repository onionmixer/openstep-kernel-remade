F0066EA4: 9de3bf90                 save    %sp, -0x70, %sp
F0066EA8: a00620a8                 add     %i0, 0xA8, %l0
F0066EAC: d0040000                 ld      [%l0], %o0
F0066EB0: 80a22000                 cmp     %o0, 0
F0066EB4: 12bffffe                 bne     loc_F0066EAC
F0066EB8: 01000000                 nop
F0066EBC: 4000bffb                 call    _simple_lock_try
F0066EC0: 90100010                 mov     %l0, %o0
F0066EC4: 80a22000                 cmp     %o0, 0
F0066EC8: 02bffff9                 be      loc_F0066EAC
F0066ECC: 01000000                 nop
F0066ED0: e40620ac                 ld      [%i0+0xAC], %l2
F0066ED4: 80a4a000                 cmp     %l2, 0
F0066ED8: 32800004                 bne,a   loc_F0066EE8
F0066EDC: c02620ac                 clr     [%i0+0xAC]
F0066EE0: c02620a8                 clr     [%i0+0xA8]
F0066EE4: 30800046                 ba,a    locret_F0066FFC
F0066EE8: d00620b0                 ld      [%i0+0xB0], %o0
F0066EEC: c02620a8                 clr     [%i0+0xA8]
F0066EF0: 80a22000                 cmp     %o0, 0
F0066EF4: 02800006                 be      loc_F0066F0C
F0066EF8: 80a23fff                 cmp     %o0, -1
F0066EFC: 22800005                 be,a    loc_F0066F10
F0066F00: d00620b4                 ld      [%i0+0xB4], %o0
F0066F04: 7fffd086                 call    _ipc_port_release_send
F0066F08: 01000000                 nop
F0066F0C: d00620b4                 ld      [%i0+0xB4], %o0
F0066F10: 80a22000                 cmp     %o0, 0
F0066F14: 02800006                 be      loc_F0066F2C
F0066F18: 80a23fff                 cmp     %o0, -1
F0066F1C: 22800005                 be,a    loc_F0066F30
F0066F20: d40620c0                 ld      [%i0+0xC0], %o2
F0066F24: 7fffd07e                 call    _ipc_port_release_send
F0066F28: 01000000                 nop
F0066F2C: d40620c0                 ld      [%i0+0xC0], %o2
F0066F30: 80a2a000                 cmp     %o2, 0
F0066F34: 02800008                 be      loc_F0066F54
F0066F38: 80a2bfff                 cmp     %o2, -1
F0066F3C: 22800007                 be,a    loc_F0066F58
F0066F40: d20620b8                 ld      [%i0+0xB8], %o1
F0066F44: 113c04ef                 sethi   %hi(_ipc_space_reply), %o0
F0066F48: d2022338                 ld      [%o0+%lo(_ipc_space_reply)], %o1
F0066F4C: 7fffd104                 call    _ipc_port_dealloc_special
F0066F50: 9010000a                 mov     %o2, %o0
F0066F54: d20620b8                 ld      [%i0+0xB8], %o1
F0066F58: 80a26000                 cmp     %o1, 0
F0066F5C: 02800024                 be      loc_F0066FEC
F0066F60: 80a27fff                 cmp     %o1, -1
F0066F64: 02800023                 be      loc_F0066FF0
F0066F68: 113c04ef                 sethi   -0xFEC4400, %o0
F0066F6C: d006200c                 ld      [%i0+0xC], %o0
F0066F70: f0022088                 ld      [%o0+0x88], %i0
F0066F74: a2100009                 mov     %o1, %l1
F0066F78: a0062008                 add     %i0, 8, %l0
F0066F7C: d0040000                 ld      [%l0], %o0
F0066F80: 80a22000                 cmp     %o0, 0
F0066F84: 12bffffe                 bne     loc_F0066F7C
F0066F88: 01000000                 nop
F0066F8C: 4000bfc7                 call    _simple_lock_try
F0066F90: 90100010                 mov     %l0, %o0
F0066F94: 80a22000                 cmp     %o0, 0
F0066F98: 02bffff9                 be      loc_F0066F7C
F0066F9C: 01000000                 nop
F0066FA0: d006200c                 ld      [%i0+0xC], %o0
F0066FA4: 80a22000                 cmp     %o0, 0
F0066FA8: 0280000e                 be      loc_F0066FE0
F0066FAC: 92100011                 mov     %l1, %o1
F0066FB0: 90100018                 mov     %i0, %o0
F0066FB4: 9407bff4                 add     %fp, var_C, %o2
F0066FB8: 7fffd2cf                 call    _ipc_right_reverse
F0066FBC: 9607bff0                 add     %fp, var_10, %o3
F0066FC0: 80a22000                 cmp     %o0, 0
F0066FC4: 02800007                 be      loc_F0066FE0
F0066FC8: d207bff4                 ld      [%fp+var_C], %o1
F0066FCC: c0244000                 clr     [%l1]
F0066FD0: d407bff0                 ld      [%fp+var_10], %o2
F0066FD4: 7fffd479                 call    _ipc_right_destroy
F0066FD8: 90100018                 mov     %i0, %o0
F0066FDC: 30800002                 ba,a    loc_F0066FE4
F0066FE0: c0262008                 clr     [%i0+8]
F0066FE4: 7fffd04e                 call    _ipc_port_release_send
F0066FE8: 90100011                 mov     %l1, %o0
F0066FEC: 113c04ef                 sethi   -0xFEC4400, %o0
F0066FF0: d2022330                 ld      [%o0+0x330], %o1
F0066FF4: 7fffd0da                 call    _ipc_port_dealloc_special
F0066FF8: 90100012                 mov     %l2, %o0
F0066FFC: 81c7e008                 ret
F0067000: 81e80000                 restore
