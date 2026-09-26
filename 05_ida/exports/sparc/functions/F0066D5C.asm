F0066D5C: 9de3bf90                 save    %sp, -0x70, %sp
F0066D60: 113c04ef                 sethi   %hi(_ipc_space_kernel), %o0
F0066D64: 7fffd16a                 call    _ipc_port_alloc_special
F0066D68: d0022330                 ld      [%o0+%lo(_ipc_space_kernel)], %o0
F0066D6C: a0920000                 orcc    %o0, %g0, %l0
F0066D70: 32800006                 bne,a   loc_F0066D88
F0066D74: f0262090                 st      %i0, [%i0+0x90]
F0066D78: 113c043e                 sethi   %hi(aIpcThreadInit), %o0! "ipc_thread_init"
F0066D7C: 7ffeb8fd                 call    _panic
F0066D80: 90122270                 bset    %lo(aIpcThreadInit), %o0! "ipc_thread_init"
F0066D84: f0262090                 st      %i0, [%i0+0x90]
F0066D88: f0262094                 st      %i0, [%i0+0x94]
F0066D8C: c02620a4                 clr     [%i0+0xA4]
F0066D90: c02620a8                 clr     [%i0+0xA8]
F0066D94: e02620ac                 st      %l0, [%i0+0xAC]
F0066D98: 7fffd093                 call    _ipc_port_make_send
F0066D9C: 90100010                 mov     %l0, %o0
F0066DA0: d02620b0                 st      %o0, [%i0+0xB0]
F0066DA4: c02620b4                 clr     [%i0+0xB4]
F0066DA8: c02620bc                 clr     [%i0+0xBC]
F0066DAC: c02620c0                 clr     [%i0+0xC0]
F0066DB0: d006200c                 ld      [%i0+0xC], %o0
F0066DB4: 9207bff4                 add     %fp, var_C, %o1
F0066DB8: d0022088                 ld      [%o0+0x88], %o0
F0066DBC: 7fffd17a                 call    _ipc_port_alloc_compat
F0066DC0: 9407bff0                 add     %fp, var_10, %o2
F0066DC4: 80a22000                 cmp     %o0, 0
F0066DC8: 02800004                 be      loc_F0066DD8
F0066DCC: 113c043e                 sethi   %hi(aIpcThreadInit_0), %o0! "ipc_thread_init"
F0066DD0: 7ffeb8e8                 call    _panic
F0066DD4: 90122280                 bset    %lo(aIpcThreadInit_0), %o0! "ipc_thread_init"
F0066DD8: d207bff0                 ld      [%fp+var_10], %o1
F0066DDC: d002601c                 ld      [%o1+0x1C], %o0
F0066DE0: 90022001                 inc     %o0
F0066DE4: d022601c                 st      %o0, [%o1+0x1C]
F0066DE8: d0026004                 ld      [%o1+4], %o0
F0066DEC: 90022001                 inc     %o0
F0066DF0: d0226004                 st      %o0, [%o1+4]
F0066DF4: c0224000                 clr     [%o1]
F0066DF8: d22620b8                 st      %o1, [%i0+0xB8]
F0066DFC: 81c7e008                 ret
F0066E00: 81e80000                 restore
