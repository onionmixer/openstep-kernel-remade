F001036C: 9de3bf88                 save    %sp, -0x78, %sp! int
F0010370: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0010374: d40221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o2
F0010378: e202a024                 ld      [%o2+0x24], %l1
F001037C: d2044000                 ld      [%l1], %o1
F0010380: 80a27fff                 cmp     %o1, -1
F0010384: 02800017                 be      loc_F00103E0
F0010388: a01221dc                 or      %o0, %lo(dword_F0133DDC), %l0
F001038C: 80a26000                 cmp     %o1, 0
F0010390: 32800017                 bne,a   loc_F00103EC
F0010394: 90102016                 mov     0x16, %o0
F0010398: 9207bfe8                 add     %fp, var_18, %o1
F001039C: 113c04d0                 sethi   %hi(_active_threads), %o0
F00103A0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00103A4: 40019d94                 call    _thread_read_times
F00103A8: 9407bff0                 add     %fp, var_10, %o2! int
F00103AC: d2043ffc                 ld      [%l0-4], %o1
F00103B0: d007bfe8                 ld      [%fp+var_18], %o0
F00103B4: d022616c                 st      %o0, [%o1+0x16C]
F00103B8: d007bfec                 ld      [%fp+var_14], %o0
F00103BC: d0226170                 st      %o0, [%o1+0x170]
F00103C0: d2043ffc                 ld      [%l0-4], %o1
F00103C4: d007bff0                 ld      [%fp+var_10], %o0
F00103C8: d0226174                 st      %o0, [%o1+0x174]
F00103CC: d007bff4                 ld      [%fp+var_C], %o0
F00103D0: d0226178                 st      %o0, [%o1+0x178]
F00103D4: d0043ffc                 ld      [%l0-4], %o0
F00103D8: 10800007                 ba      loc_F00103F4
F00103DC: 9002216c                 inc     0x16C, %o0
F00103E0: d0043ffc                 ld      [%l0-4], %o0
F00103E4: 10800004                 ba      loc_F00103F4
F00103E8: 900221b4                 inc     0x1B4, %o0! int
F00103EC: 10800008                 ba      locret_F001040C
F00103F0: d02aa038                 stb     %o0, [%o2+0x38]
F00103F4: d2046004                 ld      [%l1+4], %o1! int
F00103F8: 40021f35                 call    _copyout
F00103FC: 94102048                 mov     0x48, %o2 ! 'H'
F0010400: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0010404: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0010408: d02a6038                 stb     %o0, [%o1+0x38]
F001040C: 81c7e008                 ret
F0010410: 81e80000                 restore
