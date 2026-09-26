F00232D8: 9de3bf98                 save    %sp, -0x68, %sp
F00232DC: 90100018                 mov     %i0, %o0
F00232E0: d4122010                 lduh    [%o0+0x10], %o2
F00232E4: 173c04d4                 sethi   %hi(_unp_rights), %o3
F00232E8: d202e2d0                 ld      [%o3+%lo(_unp_rights)], %o1
F00232EC: 9402bfff                 inc     -1, %o2
F00232F0: d4322010                 sth     %o2, [%o0+0x10]
F00232F4: 92027fff                 inc     -1, %o1
F00232F8: 7fffa07a                 call    _closef
F00232FC: d222e2d0                 st      %o1, [%o3+%lo(_unp_rights)]
F0023300: 81c7e008                 ret
F0023304: 81e80000                 restore
