F00C9DC0: 9de3bf90                 save    %sp, -0x70, %sp
F00C9DC4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C9DC8: e0062004                 ld      [%i0+4], %l0
F00C9DCC: 133c0504                 sethi   %hi(paInit), %o1
F00C9DD0: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00C9DD4: 153c0507                 sethi   %hi(stru_F0141FAC.ext), %o2
F00C9DD8: d402a3d8                 ld      [%o2+%lo(stru_F0141FAC.ext)], %o2
F00C9DDC: f027bff0                 st      %i0, [%fp+var_10]
F00C9DE0: 40009ee7                 call    _objc_msgSendSuper
F00C9DE4: d427bff4                 st      %o2, [%fp+var_C]
F00C9DE8: 80a42000                 cmp     %l0, 0
F00C9DEC: 3280000b                 bne,a   loc_F00C9E18
F00C9DF0: d0040000                 ld      [%l0], %o0
F00C9DF4: 7ffe789f                 call    _kalloc
F00C9DF8: 9010200c                 mov     0xC, %o0
F00C9DFC: 7ffe7bad                 call    _simple_lock_alloc
F00C9E00: a0100008                 mov     %o0, %l0
F00C9E04: 7ffe7bb6                 call    _lock_alloc
F00C9E08: d0240000                 st      %o0, [%l0]
F00C9E0C: d0242004                 st      %o0, [%l0+4]
F00C9E10: e0262004                 st      %l0, [%i0+4]
F00C9E14: d0040000                 ld      [%l0], %o0
F00C9E18: c0220000                 clr     [%o0]
F00C9E1C: d0042004                 ld      [%l0+4], %o0
F00C9E20: 7ffe7bba                 call    _lock_init
F00C9E24: 92102001                 mov     1, %o1
F00C9E28: f4242008                 st      %i2, [%l0+8]
F00C9E2C: 81c7e008                 ret
F00C9E30: 81e80000                 restore
