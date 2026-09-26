F0067E08: 9de3bf98                 save    %sp, -0x68, %sp
F0067E0C: d0062088                 ld      [%i0+0x88], %o0
F0067E10: 92100019                 mov     %i1, %o1
F0067E14: 9410001a                 mov     %i2, %o2
F0067E18: 9610001b                 mov     %i3, %o3
F0067E1C: 7fffc8bc                 call    _ipc_object_copyin_compat
F0067E20: 9810001c                 mov     %i4, %o4
F0067E24: 80a00008                 cmp     %g0, %o0
F0067E28: b0603fff                 subc    %g0, -1, %i0
F0067E2C: 81c7e008                 ret
F0067E30: 81e80000                 restore
