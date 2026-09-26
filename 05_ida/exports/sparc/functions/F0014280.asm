F0014280: 9de3bf98                 save    %sp, -0x68, %sp
F0014284: 113c04d4                 sethi   %hi(_log_open), %o0
F0014288: 133c04d4                 sethi   %hi(dword_F013518C), %o1
F001428C: c0222178                 clr     [%o0+%lo(_log_open)]
F0014290: e002618c                 ld      [%o1+%lo(dword_F013518C)], %l0
F0014294: a212618c                 or      %o1, %lo(dword_F013518C), %l1
F0014298: c022618c                 clr     [%o1+%lo(dword_F013518C)]
F001429C: 40018c01                 call    _calloutEntryRemove
F00142A0: 90100010                 mov     %l0, %o0
F00142A4: 40018af3                 call    _calloutEntryFree
F00142A8: 90100010                 mov     %l0, %o0
F00142AC: 40020a37                 call    _splusclock
F00142B0: c0247ff4                 clr     [%l1-0xC]
F00142B4: e0047ff8                 ld      [%l1-8], %l0
F00142B8: 40020a9b                 call    _splx
F00142BC: c0247ff8                 clr     [%l1-8]
F00142C0: 80a42000                 cmp     %l0, 0
F00142C4: 22800005                 be,a    locret_F00142D8
F00142C8: c0247ffc                 clr     [%l1-4]
F00142CC: 40018038                 call    _thread_deallocate
F00142D0: 90100010                 mov     %l0, %o0
F00142D4: c0247ffc                 clr     [%l1-4]
F00142D8: 81c7e008                 ret
F00142DC: 81e80000                 restore
