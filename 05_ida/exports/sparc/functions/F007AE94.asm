F007AE94: 9de3bf90                 save    %sp, -0x70, %sp
F007AE98: 213c0442                 sethi   %hi(_kernel_task), %l0
F007AE9C: 7fffe0b2                 call    _task_reference
F007AEA0: d0042250                 ld      [%l0+%lo(_kernel_task)], %o0
F007AEA4: 7fffb316                 call    _convert_task_to_port
F007AEA8: d0042250                 ld      [%l0+%lo(_kernel_task)], %o0
F007AEAC: 92920000                 orcc    %o0, %g0, %o1
F007AEB0: 0280000a                 be      loc_F007AED8
F007AEB4: d227bff4                 st      %o1, [%fp+var_C]
F007AEB8: 113c04d0                 sethi   %hi(_active_threads), %o0
F007AEBC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F007AEC0: 94102006                 mov     6, %o2
F007AEC4: d002200c                 ld      [%o0+0xC], %o0
F007AEC8: 7fffb3db                 call    _object_copyout
F007AECC: 9607bff4                 add     %fp, var_C, %o3
F007AED0: 10800003                 ba      locret_F007AEDC
F007AED4: f007bff4                 ld      [%fp+var_C], %i0
F007AED8: b0102000                 mov     0, %i0
F007AEDC: 81c7e008                 ret
F007AEE0: 81e80000                 restore
