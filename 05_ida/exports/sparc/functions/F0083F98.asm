F0083F98: 9de3bf98                 save    %sp, -0x68, %sp
F0083F9C: 7fff938a                 call    _lock_write
F0083FA0: 90100018                 mov     %i0, %o0
F0083FA4: d006204c                 ld      [%i0+0x4C], %o0
F0083FA8: 90022001                 inc     %o0
F0083FAC: d026204c                 st      %o0, [%i0+0x4C]
F0083FB0: 113c04d0                 sethi   %hi(_page_mask), %o0
F0083FB4: d60220d8                 ld      [%o0+%lo(_page_mask)], %o3
F0083FB8: 90100018                 mov     %i0, %o0
F0083FBC: 9438000b                 xnor    %g0, %o3, %o2
F0083FC0: 920e400a                 and     %i1, %o2, %o1
F0083FC4: b206401a                 add     %i1, %i2, %i1
F0083FC8: b206400b                 add     %i1, %o3, %i1
F0083FCC: 4000047e                 call    _vm_map_delete
F0083FD0: 940e400a                 and     %i1, %o2, %o2
F0083FD4: 90100018                 mov     %i0, %o0
F0083FD8: 92102000                 mov     0, %o1
F0083FDC: 7fffb408                 call    _thread_wakeup_prim
F0083FE0: 94102000                 mov     0, %o2
F0083FE4: 7fff9414                 call    _lock_done
F0083FE8: 90100018                 mov     %i0, %o0
F0083FEC: 81c7e008                 ret
F0083FF0: 81e80000                 restore
