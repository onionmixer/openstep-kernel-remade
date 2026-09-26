F0067CB0: 9de3bf88                 save    %sp, -0x78, %sp
F0067CB4: 113c04d0                 sethi   %hi(_active_threads), %o0
F0067CB8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0067CBC: 80a62000                 cmp     %i0, 0
F0067CC0: 0280001a                 be      loc_F0067D28
F0067CC4: e002200c                 ld      [%o0+0xC], %l0
F0067CC8: 7ffe9f29                 call    _suser
F0067CCC: 01000000                 nop
F0067CD0: 80a22000                 cmp     %o0, 0
F0067CD4: 32800004                 bne,a   loc_F0067CE4
F0067CD8: d0042088                 ld      [%l0+0x88], %o0
F0067CDC: 10800024                 ba      locret_F0067D6C
F0067CE0: b0102000                 mov     0, %i0
F0067CE4: 92100018                 mov     %i0, %o1
F0067CE8: 94102014                 mov     0x14, %o2
F0067CEC: 7fffc75f                 call    _ipc_object_copyin
F0067CF0: 9607bff4                 add     %fp, var_C, %o3
F0067CF4: 80a22000                 cmp     %o0, 0
F0067CF8: 3280001d                 bne,a   locret_F0067D6C
F0067CFC: b0102000                 mov     0, %i0
F0067D00: 213c04f0                 sethi   %hi(_lookupd_port), %l0
F0067D04: d0042060                 ld      [%l0+%lo(_lookupd_port)], %o0
F0067D08: 80a22000                 cmp     %o0, 0
F0067D0C: 22800005                 be,a    loc_F0067D20
F0067D10: d007bff4                 ld      [%fp+var_C], %o0
F0067D14: 7fffcd02                 call    _ipc_port_release_send
F0067D18: 01000000                 nop
F0067D1C: d007bff4                 ld      [%fp+var_C], %o0
F0067D20: 10800013                 ba      locret_F0067D6C
F0067D24: d0242060                 st      %o0, [%l0+0x60]
F0067D28: 113c04f0                 sethi   %hi(_lookupd_port), %o0
F0067D2C: d0022060                 ld      [%o0+%lo(_lookupd_port)], %o0
F0067D30: 80a22000                 cmp     %o0, 0
F0067D34: 0280000c                 be      loc_F0067D64
F0067D38: d027bff4                 st      %o0, [%fp+var_C]
F0067D3C: 7fffccc0                 call    _ipc_port_copy_send
F0067D40: e0042088                 ld      [%l0+0x88], %l0
F0067D44: 92100008                 mov     %o0, %o1
F0067D48: 90100010                 mov     %l0, %o0
F0067D4C: 94102011                 mov     0x11, %o2
F0067D50: 96102001                 mov     1, %o3
F0067D54: 7fffc7e8                 call    _ipc_object_copyout
F0067D58: 9807bfec                 add     %fp, var_14, %o4
F0067D5C: 10800004                 ba      locret_F0067D6C
F0067D60: f007bfec                 ld      [%fp+var_14], %i0
F0067D64: c027bfec                 clr     [%fp+var_14]
F0067D68: f007bfec                 ld      [%fp+var_14], %i0
F0067D6C: 81c7e008                 ret
F0067D70: 81e80000                 restore
