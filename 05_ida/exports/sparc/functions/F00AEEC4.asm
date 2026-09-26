F00AEEC4: 9de3bf98                 save    %sp, -0x68, %sp
F00AEEC8: 113c000c                 sethi   %hi(_romp), %o0
F00AEECC: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AEED0: 7ffd5887                 call    _montrap
F00AEED4: d002206c                 ld      [%o0+0x6C], %o0
F00AEED8: 81c7e008                 ret
F00AEEDC: 81e80000                 restore
