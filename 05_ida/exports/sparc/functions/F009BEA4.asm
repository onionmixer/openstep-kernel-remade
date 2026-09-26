F009BEA4: 9de3bf98                 save    %sp, -0x68, %sp
F009BEA8: 7ffffffa                 call    _stack_detach
F009BEAC: 90100018                 mov     %i0, %o0
F009BEB0: 92100008                 mov     %o0, %o1
F009BEB4: 90100019                 mov     %i1, %o0
F009BEB8: 7fffffe7                 call    _stack_attach
F009BEBC: 94102000                 mov     0, %o2
F009BEC0: 7ffda40f                 call    _flush_user_windows
F009BEC4: 01000000                 nop
F009BEC8: 7fffe2c8                 call    _save_fpu_context
F009BECC: 90100018                 mov     %i0, %o0
F009BED0: 113c04d0                 sethi   %hi(_active_threads), %o0
F009BED4: f2222260                 st      %i1, [%o0+%lo(_active_threads)]
F009BED8: d2066028                 ld      [%i1+0x28], %o1
F009BEDC: d406600c                 ld      [%i1+0xC], %o2
F009BEE0: 113c0428                 sethi   %hi(_active_pcb), %o0
F009BEE4: d606200c                 ld      [%i0+0xC], %o3
F009BEE8: 80a2800b                 cmp     %o2, %o3
F009BEEC: 0280000d                 be      locret_F009BF20
F009BEF0: d2222024                 st      %o1, [%o0+%lo(_active_pcb)]
F009BEF4: d002e00c                 ld      [%o3+0xC], %o0
F009BEF8: 92100018                 mov     %i0, %o1
F009BEFC: d0022024                 ld      [%o0+0x24], %o0
F009BF00: 40000e0a                 call    _pmap_deactivate
F009BF04: 94102000                 mov     0, %o2
F009BF08: d006600c                 ld      [%i1+0xC], %o0
F009BF0C: d002200c                 ld      [%o0+0xC], %o0
F009BF10: 92100019                 mov     %i1, %o1
F009BF14: d0022024                 ld      [%o0+0x24], %o0
F009BF18: 40000dba                 call    _pmap_activate
F009BF1C: 94102000                 mov     0, %o2
F009BF20: 81c7e008                 ret
F009BF24: 81e80000                 restore
