F00241CC: 9de3bf98                 save    %sp, -0x68, %sp
F00241D0: d006200c                 ld      [%i0+0xC], %o0
F00241D4: 808a2002                 btst    2, %o0
F00241D8: 32800006                 bne,a   loc_F00241F0
F00241DC: d206200c                 ld      [%i0+0xC], %o1
F00241E0: 113c042f                 sethi   %hi(aVfsUnlock), %o0! "vfs_unlock"
F00241E4: 7fffc3e3                 call    _panic
F00241E8: 901222c8                 bset    %lo(aVfsUnlock), %o0! "vfs_unlock"
F00241EC: d206200c                 ld      [%i0+0xC], %o1
F00241F0: 900a7ffd                 and     %o1, -3, %o0
F00241F4: 808a6004                 btst    4, %o1
F00241F8: 02800006                 be      locret_F0024210
F00241FC: d026200c                 st      %o0, [%i0+0xC]
F0024200: 900a7ff9                 and     %o1, -7, %o0
F0024204: d026200c                 st      %o0, [%i0+0xC]
F0024208: 7fffbaf8                 call    _wakeup
F002420C: 90100018                 mov     %i0, %o0
F0024210: 81c7e008                 ret
F0024214: 81e80000                 restore
