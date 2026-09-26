F00AFB20: 9de3bf98                 save    %sp, -0x68, %sp
F00AFB24: 113c000c                 sethi   %hi(_romp), %o0
F00AFB28: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AFB2C: d2022064                 ld      [%o0+0x64], %o1
F00AFB30: 9fc24000                 call    %o1
F00AFB34: 90100018                 mov     %i0, %o0
F00AFB38: 81c7e008                 ret
F00AFB3C: 81e80000                 restore
