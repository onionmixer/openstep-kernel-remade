F005A14C: 9de3bf90                 save    %sp, -0x70, %sp
F005A150: 90100018                 mov     %i0, %o0
F005A154: 92100019                 mov     %i1, %o1
F005A158: 40000649                 call    _ipc_right_lookup_write
F005A15C: 9407bff4                 add     %fp, var_C, %o2
F005A160: 80a22000                 cmp     %o0, 0
F005A164: 12800007                 bne     locret_F005A180
F005A168: 92100019                 mov     %i1, %o1
F005A16C: 90100018                 mov     %i0, %o0
F005A170: d407bff4                 ld      [%fp+var_C], %o2
F005A174: 9610001a                 mov     %i2, %o3
F005A178: 40000e9b                 call    _ipc_right_copyin_header
F005A17C: 9810001b                 mov     %i3, %o4
F005A180: 81c7e008                 ret
F005A184: 91e80008                 restore %g0, %o0, %o0
