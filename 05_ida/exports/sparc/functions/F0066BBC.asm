F0066BBC: 9de3bf98                 save    %sp, -0x68, %sp
F0066BC0: a0062064                 add     %i0, 0x64, %l0 ! 'd'
F0066BC4: d0040000                 ld      [%l0], %o0
F0066BC8: 80a22000                 cmp     %o0, 0
F0066BCC: 12bffffe                 bne     loc_F0066BC4
F0066BD0: 01000000                 nop
F0066BD4: 4000c0b5                 call    _simple_lock_try
F0066BD8: 90100010                 mov     %l0, %o0
F0066BDC: 80a22000                 cmp     %o0, 0
F0066BE0: 02bffff9                 be      loc_F0066BC4
F0066BE4: 01000000                 nop
F0066BE8: d0062068                 ld      [%i0+0x68], %o0
F0066BEC: 80a22000                 cmp     %o0, 0
F0066BF0: 02800004                 be      loc_F0066C00
F0066BF4: 92100018                 mov     %i0, %o1
F0066BF8: 7ffffb0a                 call    _ipc_kobject_set
F0066BFC: 94102002                 mov     2, %o2
F0066C00: c0262064                 clr     [%i0+0x64]
F0066C04: 81c7e008                 ret
F0066C08: 81e80000                 restore
