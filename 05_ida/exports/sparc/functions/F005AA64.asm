F005AA64: 9de3bf90                 save    %sp, -0x70, %sp
F005AA68: 90100018                 mov     %i0, %o0
F005AA6C: 92102000                 mov     0, %o1
F005AA70: 15000080                 sethi   0x20000, %o2
F005AA74: 96102000                 mov     0, %o3
F005AA78: 9807bff4                 add     %fp, var_C, %o4
F005AA7C: 7ffffb67                 call    _ipc_object_alloc
F005AA80: 9a07bff0                 add     %fp, var_10, %o5
F005AA84: 80a22000                 cmp     %o0, 0
F005AA88: 3280000b                 bne,a   locret_F005AAB4
F005AA8C: b0100008                 mov     %o0, %i0
F005AA90: d007bff0                 ld      [%fp+var_10], %o0
F005AA94: d407bff4                 ld      [%fp+var_C], %o2
F005AA98: 7fffffe0                 call    _ipc_port_init
F005AA9C: 92100018                 mov     %i0, %o1
F005AAA0: d007bff4                 ld      [%fp+var_C], %o0
F005AAA4: d0264000                 st      %o0, [%i1]
F005AAA8: d007bff0                 ld      [%fp+var_10], %o0
F005AAAC: b0102000                 mov     0, %i0
F005AAB0: d0268000                 st      %o0, [%i2]
F005AAB4: 81c7e008                 ret
F005AAB8: 81e80000                 restore
