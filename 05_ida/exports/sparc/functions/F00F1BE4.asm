F00F1BE4: 9de3bf98                 save    %sp, -0x68, %sp
F00F1BE8: a0100018                 mov     %i0, %l0
F00F1BEC: d0040000                 ld      [%l0], %o0! mhp
F00F1BF0: 92100019                 mov     %i1, %o1! segname
F00F1BF4: 9410001a                 mov     %i2, %o2! sectname
F00F1BF8: 7ffde10f                 call    _getsectdatafromheader
F00F1BFC: 9610001b                 mov     %i3, %o3
F00F1C00: b0920000                 orcc    %o0, %g0, %i0
F00F1C04: 02800004                 be      locret_F00F1C14
F00F1C08: 01000000                 nop
F00F1C0C: d0042010                 ld      [%l0+0x10], %o0
F00F1C10: b0060008                 add     %i0, %o0, %i0
F00F1C14: 81c7e008                 ret
F00F1C18: 81e80000                 restore
