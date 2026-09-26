F0066AB4: 9de3bf90                 save    %sp, -0x70, %sp
F0066AB8: 113c04f0                 sethi   %hi(_ipc_table_entries), %o0
F0066ABC: d0022030                 ld      [%o0+%lo(_ipc_table_entries)], %o0
F0066AC0: 7fffdcf8                 call    _ipc_space_create
F0066AC4: 9207bff4                 add     %fp, var_C, %o1
F0066AC8: 80a22000                 cmp     %o0, 0
F0066ACC: 22800006                 be,a    loc_F0066AE4
F0066AD0: 113c04ef                 sethi   -0xFEC4400, %o0
F0066AD4: 113c043e                 sethi   %hi(aIpcTaskInit), %o0! "ipc_task_init"
F0066AD8: 7ffeb9a6                 call    _panic
F0066ADC: 90122250                 bset    %lo(aIpcTaskInit), %o0! "ipc_task_init"
F0066AE0: 113c04ef                 sethi   -0xFEC4400, %o0
F0066AE4: 7fffd20a                 call    _ipc_port_alloc_special
F0066AE8: d0022330                 ld      [%o0+0x330], %o0
F0066AEC: a0920000                 orcc    %o0, %g0, %l0
F0066AF0: 12800004                 bne     loc_F0066B00
F0066AF4: 113c043e                 sethi   %hi(aIpcTaskInit_0), %o0! "ipc_task_init"
F0066AF8: 7ffeb99e                 call    _panic
F0066AFC: 90122260                 bset    %lo(aIpcTaskInit_0), %o0! "ipc_task_init"
F0066B00: c0262064                 clr     [%i0+0x64]
F0066B04: e0262068                 st      %l0, [%i0+0x68]
F0066B08: 7fffd137                 call    _ipc_port_make_send
F0066B0C: 90100010                 mov     %l0, %o0
F0066B10: d026206c                 st      %o0, [%i0+0x6C]
F0066B14: d007bff4                 ld      [%fp+var_C], %o0
F0066B18: 80a66000                 cmp     %i1, 0
F0066B1C: 1280000b                 bne     loc_F0066B48
F0066B20: d0262088                 st      %o0, [%i0+0x88]
F0066B24: c0262070                 clr     [%i0+0x70]
F0066B28: c0262074                 clr     [%i0+0x74]
F0066B2C: 9006200c                 add     %i0, 0xC, %o0
F0066B30: c0222078                 clr     [%o0+0x78]
F0066B34: 90023ffc                 inc     -4, %o0
F0066B38: 80a20018                 cmp     %o0, %i0
F0066B3C: 36bffffe                 bge,a   loc_F0066B34
F0066B40: c0222078                 clr     [%o0+0x78]
F0066B44: 3080001c                 ba,a    locret_F0066BB4
F0066B48: a0066064                 add     %i1, 0x64, %l0 ! 'd'
F0066B4C: d0040000                 ld      [%l0], %o0
F0066B50: 80a22000                 cmp     %o0, 0
F0066B54: 12bffffe                 bne     loc_F0066B4C
F0066B58: 01000000                 nop
F0066B5C: 4000c0d3                 call    _simple_lock_try
F0066B60: 90100010                 mov     %l0, %o0
F0066B64: 80a22000                 cmp     %o0, 0
F0066B68: 02bffff9                 be      loc_F0066B4C
F0066B6C: a4102000                 mov     0, %l2
F0066B70: a2100018                 mov     %i0, %l1
F0066B74: a0100019                 mov     %i1, %l0
F0066B78: d0042078                 ld      [%l0+0x78], %o0
F0066B7C: 7fffd130                 call    _ipc_port_copy_send
F0066B80: a404a001                 inc     %l2
F0066B84: d0246078                 st      %o0, [%l1+0x78]
F0066B88: a2046004                 inc     4, %l1
F0066B8C: 80a4a003                 cmp     %l2, 3
F0066B90: 04bffffa                 ble     loc_F0066B78
F0066B94: a0042004                 inc     4, %l0
F0066B98: 7fffd129                 call    _ipc_port_copy_send
F0066B9C: d0066070                 ld      [%i1+0x70], %o0
F0066BA0: d0262070                 st      %o0, [%i0+0x70]
F0066BA4: 7fffd126                 call    _ipc_port_copy_send
F0066BA8: d0066074                 ld      [%i1+0x74], %o0
F0066BAC: d0262074                 st      %o0, [%i0+0x74]
F0066BB0: c0266064                 clr     [%i1+0x64]
F0066BB4: 81c7e008                 ret
F0066BB8: 81e80000                 restore
