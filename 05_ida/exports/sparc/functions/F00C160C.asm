F00C160C: 9de3bf98                 save    %sp, -0x68, %sp
F00C1610: f027a044                 st      %i0, [%fp+arg_44]
F00C1614: 7ffffe38                 call    sub_F00C0EF4
F00C1618: 9007a044                 add     %fp, arg_44, %o0
F00C161C: b0920000                 orcc    %o0, %g0, %i0
F00C1620: 0280000b                 be      locret_F00C164C
F00C1624: 01000000                 nop
F00C1628: d00e0000                 ldub    [%i0], %o0
F00C162C: 80a22004                 cmp     %o0, 4
F00C1630: 12800007                 bne     locret_F00C164C
F00C1634: d007a044                 ld      [%fp+arg_44], %o0
F00C1638: 7ffffe45                 call    _kbdcmd
F00C163C: 9210200e                 mov     0xE, %o1
F00C1640: d007a044                 ld      [%fp+arg_44], %o0
F00C1644: 7ffffe42                 call    _kbdcmd
F00C1648: d24e202a                 ldsb    [%i0+0x2A], %o1
F00C164C: 81c7e008                 ret
F00C1650: 81e80000                 restore
