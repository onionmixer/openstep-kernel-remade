F000C6F0: 9de3bf98                 save    %sp, -0x68, %sp
F000C6F4: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000C6F8: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F000C6FC: d0022024                 ld      [%o0+0x24], %o0
F000C700: d00a2003                 ldub    [%o0+3], %o0! int
F000C704: 40000004                 call    _exit
