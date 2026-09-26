F006E094: 9de3bf98                 save    %sp, -0x68, %sp
F006E098: 213c04f0                 sethi   %hi(__kernDebuggerLock), %l0
F006E09C: 4000a383                 call    _simple_lock_try
F006E0A0: d0042278                 ld      [%l0+%lo(__kernDebuggerLock)], %o0
F006E0A4: 80a22000                 cmp     %o0, 0
F006E0A8: 02800007                 be      loc_F006E0C4
F006E0AC: 113c0440                 sethi   -0xFEF0000, %o0
F006E0B0: 400099d4                 call    _miniMonGdb
F006E0B4: 90100018                 mov     %i0, %o0
F006E0B8: d2042278                 ld      [%l0+%lo(__kernDebuggerLock)], %o1
F006E0BC: c0224000                 clr     [%o1]
F006E0C0: 30800007                 ba,a    locret_F006E0DC
F006E0C4: 7fffffcd                 call    _safe_prf
F006E0C8: 90122008                 bset    8, %o0
F006E0CC: 113c0440                 sethi   %hi(aExitFromMonito), %o0! "exit from monitor and try again.\n"
F006E0D0: 7fffffca                 call    _safe_prf
F006E0D4: 90122030                 bset    %lo(aExitFromMonito), %o0! "exit from monitor and try again.\n"
F006E0D8: 90102001                 mov     1, %o0
F006E0DC: 81c7e008                 ret
F006E0E0: 91e80008                 restore %g0, %o0, %o0
