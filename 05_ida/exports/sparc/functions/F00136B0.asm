F00136B0: 9de3bf98                 save    %sp, -0x68, %sp
F00136B4: 90100018                 mov     %i0, %o0
F00136B8: d2020000                 ld      [%o0], %o1
F00136BC: d4064000                 ld      [%i1], %o2
F00136C0: 9222400a                 sub     %o1, %o2, %o1
F00136C4: d4022004                 ld      [%o0+4], %o2
F00136C8: d2220000                 st      %o1, [%o0]
F00136CC: d2066004                 ld      [%i1+4], %o1
F00136D0: 94228009                 sub     %o2, %o1, %o2
F00136D4: 40000004                 call    _timevalfix
F00136D8: d4222004                 st      %o2, [%o0+4]
F00136DC: 81c7e008                 ret
F00136E0: 81e80000                 restore
