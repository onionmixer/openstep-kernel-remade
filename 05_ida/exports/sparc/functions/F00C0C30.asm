F00C0C30: 9de3bf98                 save    %sp, -0x68, %sp
F00C0C34: d0062008                 ld      [%i0+8], %o0
F00C0C38: 80a22062                 cmp     %o0, 0x62 ! 'b'
F00C0C3C: 12800025                 bne     loc_F00C0CD0
F00C0C40: 94100019                 mov     %i1, %o2
F00C0C44: d04e200c                 ldsb    [%i0+0xC], %o0
F00C0C48: 80a22000                 cmp     %o0, 0
F00C0C4C: 02800021                 be      loc_F00C0CD0
F00C0C50: 113c04cc                 sethi   %hi(dword_F0133004), %o0
F00C0C54: d2022004                 ld      [%o0+%lo(dword_F0133004)], %o1
F00C0C58: 11010000                 sethi   0x4000000, %o0
F00C0C5C: 808a4008                 btst    %o0, %o1
F00C0C60: 0280001c                 be      loc_F00C0CD0
F00C0C64: 11004000                 sethi   0x1000000, %o0
F00C0C68: 808a4008                 btst    %o0, %o1
F00C0C6C: 0280000d                 be      loc_F00C0CA0
F00C0C70: 113c0483                 sethi   %hi(unk_F0120E30), %o0
F00C0C74: 90122230                 bset    %lo(unk_F0120E30), %o0
F00C0C78: 133c0483                 sethi   %hi(aKernelDebugger), %o1! "Kernel Debugger"
F00C0C7C: 7fff6400                 call    _mini_mon
F00C0C80: 92126238                 bset    %lo(aKernelDebugger), %o1! "Kernel Debugger"
F00C0C84: d41e0000                 ldd     [%i0], %o2
F00C0C88: 9210000a                 mov     %o2, %o1
F00C0C8C: 9410000b                 mov     %o3, %o2
F00C0C90: 7fffffd3                 call    sub_F00C0BDC
F00C0C94: 90102078                 mov     0x78, %o0 ! 'x'
F00C0C98: 10800008                 ba      loc_F00C0CB8
F00C0C9C: d41e0000                 ldd     [%i0], %o2
F00C0CA0: 113c048390122248         set     aRestart_0, %o0! "restart"
F00C0CA8: 133c0483                 sethi   %hi(aRestart_1), %o1! "Restart"
F00C0CAC: 7fff63f4                 call    _mini_mon
F00C0CB0: 92126250                 bset    %lo(aRestart_1), %o1! "Restart"
F00C0CB4: d41e0000                 ldd     [%i0], %o2
F00C0CB8: 9210000a                 mov     %o2, %o1
F00C0CBC: 9410000b                 mov     %o3, %o2
F00C0CC0: 7fffffc7                 call    sub_F00C0BDC
F00C0CC4: 9010207a                 mov     0x7A, %o0 ! 'z'
F00C0CC8: 10800003                 ba      locret_F00C0CD4
F00C0CCC: b0102001                 mov     1, %i0
F00C0CD0: b0102000                 mov     0, %i0
F00C0CD4: 81c7e008                 ret
F00C0CD8: 81e80000                 restore
