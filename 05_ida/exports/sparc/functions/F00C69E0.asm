F00C69E0: 9de3bf90                 save    %sp, -0x70, %sp
F00C69E4: 80a6a001                 cmp     %i2, 1
F00C69E8: 0280000a                 be      loc_F00C6A10
F00C69EC: 90100018                 mov     %i0, %o0
F00C69F0: 80a6a001                 cmp     %i2, 1
F00C69F4: 0a800005                 bcs     loc_F00C6A08
F00C69F8: 80a6a002                 cmp     %i2, 2
F00C69FC: 22800006                 be,a    loc_F00C6A14
F00C6A00: 92103fff                 mov     -1, %o1
F00C6A04: 30800004                 ba,a    loc_F00C6A14
F00C6A08: 10800003                 ba      loc_F00C6A14
F00C6A0C: 92102002                 mov     2, %o1
F00C6A10: 92102000                 mov     0, %o1
F00C6A14: 40000672                 call    _volCheckEjecting
F00C6A18: 01000000                 nop
F00C6A1C: 81c7e008                 ret
F00C6A20: 81e80000                 restore
