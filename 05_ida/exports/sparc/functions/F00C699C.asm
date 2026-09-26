F00C699C: 9de3bf90                 save    %sp, -0x70, %sp
F00C69A0: 80a6a001                 cmp     %i2, 1
F00C69A4: 0280000a                 be      loc_F00C69CC
F00C69A8: 90100018                 mov     %i0, %o0
F00C69AC: 80a6a001                 cmp     %i2, 1
F00C69B0: 0a800005                 bcs     loc_F00C69C4
F00C69B4: 80a6a002                 cmp     %i2, 2
F00C69B8: 22800006                 be,a    loc_F00C69D0
F00C69BC: 92103fff                 mov     -1, %o1
F00C69C0: 30800004                 ba,a    loc_F00C69D0
F00C69C4: 10800003                 ba      loc_F00C69D0
F00C69C8: 92102002                 mov     2, %o1
F00C69CC: 92102000                 mov     0, %o1
F00C69D0: 4000067a                 call    _volCheckRequest
F00C69D4: 01000000                 nop
F00C69D8: 81c7e008                 ret
F00C69DC: 81e80000                 restore
