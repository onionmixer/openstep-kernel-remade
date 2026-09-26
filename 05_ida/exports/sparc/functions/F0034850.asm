F0034850: 9de3bf98                 save    %sp, -0x68, %sp
F0034854: 90100018                 mov     %i0, %o0
F0034858: d2022004                 ld      [%o0+4], %o1
F003485C: 173c0432                 sethi   %hi(_ripdst), %o3
F0034860: 98020009                 add     %o0, %o1, %o4
F0034864: 133c0432                 sethi   %hi(_ripproto), %o1
F0034868: d40b2009                 ldub    [%o4+9], %o2
F003486C: 921260a0                 bset    %lo(_ripproto), %o1
F0034870: d4326002                 sth     %o2, [%o1+2]
F0034874: d4032010                 ld      [%o4+0x10], %o2
F0034878: 9612e080                 bset    %lo(_ripdst), %o3
F003487C: d422e004                 st      %o2, [%o3+4]
F0034880: 153c0432                 sethi   %hi(_ripsrc), %o2
F0034884: d803200c                 ld      [%o4+0xC], %o4
F0034888: 9412a090                 bset    %lo(_ripsrc), %o2
F003488C: 7fffdf8a                 call    _raw_input
F0034890: d822a004                 st      %o4, [%o2+4]
F0034894: 81c7e008                 ret
F0034898: 81e80000                 restore
