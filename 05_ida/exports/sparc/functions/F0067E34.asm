F0067E34: 9de3bf98                 save    %sp, -0x68, %sp
F0067E38: 80a66000                 cmp     %i1, 0
F0067E3C: 12800006                 bne     loc_F0067E54
F0067E40: 80a6a005                 cmp     %i2, 5
F0067E44: 113c043e                 sethi   %hi(aObjectCopyout), %o0! "object_copyout"
F0067E48: 7ffeb4ca                 call    _panic
F0067E4C: 90122298                 bset    %lo(aObjectCopyout), %o0! "object_copyout"
F0067E50: 80a6a005                 cmp     %i2, 5
F0067E54: 12800003                 bne     loc_F0067E60
F0067E58: b4102011                 mov     0x11, %i2
F0067E5C: b4102010                 mov     0x10, %i2
F0067E60: 80a66000                 cmp     %i1, 0
F0067E64: 02800009                 be      loc_F0067E88
F0067E68: 92100019                 mov     %i1, %o1
F0067E6C: d0062088                 ld      [%i0+0x88], %o0
F0067E70: 9410001a                 mov     %i2, %o2
F0067E74: 7fffc8c5                 call    _ipc_object_copyout_compat
F0067E78: 9610001b                 mov     %i3, %o3
F0067E7C: 80a22000                 cmp     %o0, 0
F0067E80: 02800003                 be      locret_F0067E8C
F0067E84: 01000000                 nop
F0067E88: c026c000                 clr     [%i3]
F0067E8C: 81c7e008                 ret
F0067E90: 81e80000                 restore
