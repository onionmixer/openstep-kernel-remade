F00726D4: 9de3bf98                 save    %sp, -0x68, %sp
F00726D8: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F00726DC: d20221b0                 ld      [%o0+%lo(_processor_ptr)], %o1
F00726E0: d0026108                 ld      [%o1+0x108], %o0
F00726E4: 80a22000                 cmp     %o0, 0
F00726E8: 14800007                 bg      loc_F0072704
F00726EC: 94102000                 mov     0, %o2
F00726F0: d002612c                 ld      [%o1+0x12C], %o0
F00726F4: d0022108                 ld      [%o0+0x108], %o0
F00726F8: 80a22000                 cmp     %o0, 0
F00726FC: 04800003                 ble     loc_F0072708
F0072700: 01000000                 nop
F0072704: 94102001                 mov     1, %o2
F0072708: 4000a641                 call    _thread_syscall_return
F007270C: 9010000a                 mov     %o2, %o0
F0072710: 81c7e008                 ret
F0072714: 81e80000                 restore
