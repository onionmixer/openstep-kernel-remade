F0065068: 9de3bf98                 save    %sp, -0x68, %sp
F006506C: 113c04ef                 sethi   %hi(_ipc_space_kernel), %o0
F0065070: 7fffd8a7                 call    _ipc_port_alloc_special
F0065074: d0022330                 ld      [%o0+%lo(_ipc_space_kernel)], %o0
F0065078: a0920000                 orcc    %o0, %g0, %l0
F006507C: 32800006                 bne,a   loc_F0065094
F0065080: e0262140                 st      %l0, [%i0+0x140]
F0065084: 113c043e                 sethi   %hi(aIpcProcessorIn), %o0! "ipc_processor_init"
F0065088: 7ffec03a                 call    _panic
F006508C: 90122128                 bset    %lo(aIpcProcessorIn), %o0! "ipc_processor_init"
F0065090: e0262140                 st      %l0, [%i0+0x140]
F0065094: 90100010                 mov     %l0, %o0
F0065098: 92100018                 mov     %i0, %o1
F006509C: 400001e1                 call    _ipc_kobject_set
F00650A0: 94102005                 mov     5, %o2
F00650A4: 81c7e008                 ret
F00650A8: 81e80000                 restore
