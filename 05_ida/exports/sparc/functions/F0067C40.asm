F0067C40: 9de3bf90                 save    %sp, -0x70, %sp
F0067C44: 113c04d0                 sethi   %hi(_active_threads), %o0
F0067C48: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0067C4C: 7ffe9f48                 call    _suser
F0067C50: e002200c                 ld      [%o0+0xC], %l0
F0067C54: 80a22000                 cmp     %o0, 0
F0067C58: 32800005                 bne,a   loc_F0067C6C
F0067C5C: 113c04d4                 sethi   -0xFECB000, %o0
F0067C60: 113c04d4                 sethi   %hi(_realhost), %o0
F0067C64: 10800003                 ba      loc_F0067C70
F0067C68: d0022170                 ld      [%o0+%lo(_realhost)], %o0
F0067C6C: d0022174                 ld      [%o0+0x174], %o0
F0067C70: 80a22000                 cmp     %o0, 0
F0067C74: 2280000c                 be,a    loc_F0067CA4
F0067C78: c027bff4                 clr     [%fp+var_C]
F0067C7C: 7fffccf0                 call    _ipc_port_copy_send
F0067C80: e0042088                 ld      [%l0+0x88], %l0
F0067C84: 92100008                 mov     %o0, %o1
F0067C88: 90100010                 mov     %l0, %o0
F0067C8C: 94102011                 mov     0x11, %o2
F0067C90: 96102001                 mov     1, %o3
F0067C94: 7fffc818                 call    _ipc_object_copyout
F0067C98: 9807bff4                 add     %fp, var_C, %o4
F0067C9C: 10800003                 ba      locret_F0067CA8
F0067CA0: f007bff4                 ld      [%fp+var_C], %i0
F0067CA4: f007bff4                 ld      [%fp+var_C], %i0
F0067CA8: 81c7e008                 ret
F0067CAC: 81e80000                 restore
