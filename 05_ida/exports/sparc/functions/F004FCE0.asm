F004FCE0: 9de3bf98                 save    %sp, -0x68, %sp
F004FCE4: 90100018                 mov     %i0, %o0
F004FCE8: d4022010                 ld      [%o0+0x10], %o2
F004FCEC: d202a008                 ld      [%o2+8], %o1
F004FCF0: 92027fff                 inc     -1, %o1
F004FCF4: d222a008                 st      %o1, [%o2+8]
F004FCF8: 4000612a                 call    _kfree
F004FCFC: 9210201c                 mov     0x1C, %o1
F004FD00: 81c7e008                 ret
F004FD04: 81e80000                 restore
