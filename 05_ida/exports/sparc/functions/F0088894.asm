F0088894: 9de3bf98                 save    %sp, -0x68, %sp
F0088898: 213c0447                 sethi   %hi(_page_size), %l0
F008889C: d404213c                 ld      [%l0+%lo(_page_size)], %o2
F00888A0: 113c04d0                 sethi   %hi(_page_mask), %o0
F00888A4: 9202bfff                 add     %o2, -1, %o1
F00888A8: 808a400a                 btst    %o2, %o1
F00888AC: 02800005                 be      loc_F00888C0
F00888B0: d22220d8                 st      %o1, [%o0+%lo(_page_mask)]
F00888B4: 113c0447                 sethi   %hi(aVmSetPageSizeP), %o0! "vm_set_page_size: page size not a power"...
F00888B8: 7ffe322e                 call    _panic
F00888BC: 90122158                 bset    %lo(aVmSetPageSizeP), %o0! "vm_set_page_size: page size not a power"...
F00888C0: 133c04f4                 sethi   %hi(_page_shift), %o1
F00888C4: d004213c                 ld      [%l0+0x13C], %o0
F00888C8: 80a22001                 cmp     %o0, 1
F00888CC: 0280000b                 be      locret_F00888F8
F00888D0: c0226348                 clr     [%o1+%lo(_page_shift)]
F00888D4: 96102001                 mov     1, %o3
F00888D8: 94100008                 mov     %o0, %o2
F00888DC: d0026348                 ld      [%o1+%lo(_page_shift)], %o0
F00888E0: 90022001                 inc     %o0
F00888E4: d0226348                 st      %o0, [%o1+0x348]
F00888E8: 912ac008                 sll     %o3, %o0, %o0
F00888EC: 80a2000a                 cmp     %o0, %o2
F00888F0: 12bffffc                 bne     loc_F00888E0
F00888F4: d0026348                 ld      [%o1+0x348], %o0
F00888F8: 81c7e008                 ret
F00888FC: 81e80000                 restore
