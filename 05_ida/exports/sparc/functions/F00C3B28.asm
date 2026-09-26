F00C3B28: 9de3bf98                 save    %sp, -0x68, %sp
F00C3B2C: 7ffffe02                 call    sub_F00C3334
F00C3B30: d0062004                 ld      [%i0+4], %o0
F00C3B34: d02e2008                 stb     %o0, [%i0+8]
F00C3B38: d0060000                 ld      [%i0], %o0! id
F00C3B3C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C3B40: 4000b74c                 call    _objc_msgSend
F00C3B44: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C3B48: d0060000                 ld      [%i0], %o0! id
F00C3B4C: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00C3B50: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00C3B54: 4000b747                 call    _objc_msgSend
F00C3B58: 94102001                 mov     1, %o2
F00C3B5C: 400019b0                 call    _IOExitThread
F00C3B60: 01000000                 nop
F00C3B64: 81c7e008                 ret
F00C3B68: 81e80000                 restore
