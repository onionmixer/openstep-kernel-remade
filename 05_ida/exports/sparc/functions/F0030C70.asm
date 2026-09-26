F0030C70: 9de3bf98                 save    %sp, -0x68, %sp
F0030C74: c026200c                 clr     [%i0+0xC]
F0030C78: d006201c                 ld      [%i0+0x1C], %o0
F0030C7C: c0362010                 clrh    [%i0+0x10]
F0030C80: d0122006                 lduh    [%o0+6], %o0
F0030C84: 808a2001                 btst    1, %o0
F0030C88: 02800004                 be      locret_F0030C98
F0030C8C: 01000000                 nop
F0030C90: 40000004                 call    _in_pcbdetach
F0030C94: 90100018                 mov     %i0, %o0
F0030C98: 81c7e008                 ret
F0030C9C: 81e80000                 restore
