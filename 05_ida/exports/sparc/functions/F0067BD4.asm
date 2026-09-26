F0067BD4: 9de3bf90                 save    %sp, -0x70, %sp
F0067BD8: 113c04d0                 sethi   %hi(_active_threads), %o0
F0067BDC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0067BE0: 7ffe9f63                 call    _suser
F0067BE4: e002200c                 ld      [%o0+0xC], %l0
F0067BE8: 80a22000                 cmp     %o0, 0
F0067BEC: 12800004                 bne     loc_F0067BFC
F0067BF0: 113c04d4                 sethi   -0xFECB000, %o0
F0067BF4: 10800011                 ba      locret_F0067C38
F0067BF8: b0102000                 mov     0, %i0
F0067BFC: d0022174                 ld      [%o0+0x174], %o0
F0067C00: 80a22000                 cmp     %o0, 0
F0067C04: 2280000c                 be,a    loc_F0067C34
F0067C08: c027bff4                 clr     [%fp+var_C]
F0067C0C: 7fffcd0c                 call    _ipc_port_copy_send
F0067C10: e0042088                 ld      [%l0+0x88], %l0
F0067C14: 92100008                 mov     %o0, %o1
F0067C18: 90100010                 mov     %l0, %o0
F0067C1C: 94102011                 mov     0x11, %o2
F0067C20: 96102001                 mov     1, %o3
F0067C24: 7fffc834                 call    _ipc_object_copyout
F0067C28: 9807bff4                 add     %fp, var_C, %o4
F0067C2C: 10800003                 ba      locret_F0067C38
F0067C30: f007bff4                 ld      [%fp+var_C], %i0
F0067C34: f007bff4                 ld      [%fp+var_C], %i0
F0067C38: 81c7e008                 ret
F0067C3C: 81e80000                 restore
