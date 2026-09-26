F0067D74: 9de3bf90                 save    %sp, -0x70, %sp
F0067D78: 113c04d0                 sethi   %hi(_active_threads), %o0
F0067D7C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0067D80: 80a62000                 cmp     %i0, 0
F0067D84: 12800008                 bne     loc_F0067DA4
F0067D88: e002200c                 ld      [%o0+0xC], %l0
F0067D8C: 7ffe9ef8                 call    _suser
F0067D90: 01000000                 nop
F0067D94: 80a22000                 cmp     %o0, 0
F0067D98: 2280001a                 be,a    locret_F0067E00
F0067D9C: b0102000                 mov     0, %i0
F0067DA0: 80a62000                 cmp     %i0, 0
F0067DA4: 06800004                 bl      loc_F0067DB4
F0067DA8: 80a62002                 cmp     %i0, 2
F0067DAC: 08800004                 bleu    loc_F0067DBC
F0067DB0: 113c043e                 sethi   -0xFEF0800, %o0
F0067DB4: 10800013                 ba      locret_F0067E00
F0067DB8: b0102000                 mov     0, %i0
F0067DBC: 90122290                 bset    0x290, %o0
F0067DC0: 932e2002                 sll     %i0, 2, %o1
F0067DC4: d0024008                 ld      [%o1+%o0], %o0
F0067DC8: 80a22000                 cmp     %o0, 0
F0067DCC: 2280000c                 be,a    loc_F0067DFC
F0067DD0: c027bff4                 clr     [%fp+var_C]
F0067DD4: 7fffcc9a                 call    _ipc_port_copy_send
F0067DD8: e0042088                 ld      [%l0+0x88], %l0
F0067DDC: 92100008                 mov     %o0, %o1
F0067DE0: 90100010                 mov     %l0, %o0
F0067DE4: 94102011                 mov     0x11, %o2
F0067DE8: 96102001                 mov     1, %o3
F0067DEC: 7fffc7c2                 call    _ipc_object_copyout
F0067DF0: 9807bff4                 add     %fp, var_C, %o4
F0067DF4: 10800003                 ba      locret_F0067E00
F0067DF8: f007bff4                 ld      [%fp+var_C], %i0
F0067DFC: f007bff4                 ld      [%fp+var_C], %i0
F0067E00: 81c7e008                 ret
F0067E04: 81e80000                 restore
