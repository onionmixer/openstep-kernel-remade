F008C388: 9de3bf98                 save    %sp, -0x68, %sp
F008C38C: 40000030                 call    sub_F008C44C
F008C390: 01000000                 nop
F008C394: 4000f73b                 call    _IOInitGeneralFuncs
F008C398: 01000000                 nop
F008C39C: 4000efcc                 call    _volCheckInit
F008C3A0: 01000000                 nop
F008C3A4: 113c04baa21222ec         set     _pseudo_inits, %l1
F008C3AC: d0046004                 ld      [%l1+4], %o0
F008C3B0: 80a22000                 cmp     %o0, 0
F008C3B4: 0280000a                 be      loc_F008C3DC
F008C3B8: a0046004                 add     %l1, 4, %l0
F008C3BC: d2040000                 ld      [%l0], %o1
F008C3C0: 9fc24000                 call    %o1
F008C3C4: d0044000                 ld      [%l1], %o0
F008C3C8: a0042008                 inc     8, %l0
F008C3CC: d0040000                 ld      [%l0], %o0
F008C3D0: 80a22000                 cmp     %o0, 0
F008C3D4: 12bffffa                 bne     loc_F008C3BC
F008C3D8: a2046008                 inc     8, %l1
F008C3DC: 113c0506                 sethi   %hi(paNxconditionloc), %o0
F008C3E0: d002226c                 ld      [%o0+%lo(paNxconditionloc)], %o0! id
F008C3E4: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008C3E8: 40019522                 call    _objc_msgSend
F008C3EC: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008C3F0: 213c04c3                 sethi   %hi(dword_F0130FF0), %l0
F008C3F4: d02423f0                 st      %o0, [%l0+%lo(dword_F0130FF0)]
F008C3F8: 133c0503                 sethi   %hi(paInitwith), %o1
F008C3FC: d20263f4                 ld      [%o1+%lo(paInitwith)], %o1! SEL
F008C400: 4001951c                 call    _objc_msgSend
F008C404: 94102000                 mov     0, %o2
F008C408: 133c02319212625c         set     sub_F008C65C, %o1
F008C410: 113c04f6                 sethi   %hi(_IOTask_kern), %o0
F008C414: d00221b8                 ld      [%o0+%lo(_IOTask_kern)], %o0
F008C418: 7fffa587                 call    _kernel_thread
F008C41C: 94102000                 mov     0, %o2
F008C420: d00423f0                 ld      [%l0+%lo(dword_F0130FF0)], %o0! id
F008C424: 133c0503                 sethi   %hi(paLockwhen), %o1
F008C428: d20263f8                 ld      [%o1+%lo(paLockwhen)], %o1! SEL
F008C42C: 40019511                 call    _objc_msgSend
F008C430: 94102001                 mov     1, %o2
F008C434: d00423f0                 ld      [%l0+%lo(dword_F0130FF0)], %o0! id
F008C438: 133c0503                 sethi   %hi(paFree), %o1! SEL
F008C43C: 4001950d                 call    _objc_msgSend
F008C440: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F008C444: 81c7e008                 ret
F008C448: 81e80000                 restore
