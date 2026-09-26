F00C9EA0: 9de3bf90                 save    %sp, -0x70, %sp
F00C9EA4: d0062004                 ld      [%i0+4], %o0
F00C9EA8: 7ffe7bc7                 call    _lock_write
F00C9EAC: d0022004                 ld      [%o0+4], %o0
F00C9EB0: 81c7e008                 ret
F00C9EB4: 81e80000                 restore
