F00C15F0: 9de3bf98                 save    %sp, -0x68, %sp! int
F00C15F4: 7ffffe0c                 call    _kbdflush
F00C15F8: 90100018                 mov     %i0, %o0! int
F00C15FC: 7ffffe74                 call    _kbdreset
F00C1600: 90100018                 mov     %i0, %o0
F00C1604: 81c7e008                 ret
F00C1608: 81e80000                 restore
