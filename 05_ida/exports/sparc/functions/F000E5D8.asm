F000E5D8: 9de3bf98                 save    %sp, -0x68, %sp
F000E5DC: 113c043c                 sethi   %hi(_max_proc), %o0
F000E5E0: 92102d48                 mov     0xD48, %o1
F000E5E4: d002236c                 ld      [%o0+%lo(_max_proc)], %o0
F000E5E8: 7fffdfc6                 call    _umul
F000E5EC: 932a6002                 sll     %o1, 2, %o1
F000E5F0: 92100008                 mov     %o0, %o1
F000E5F4: 90102088                 mov     0x88, %o0
F000E5F8: 193c042c                 sethi   %hi(aProcStructures), %o4! "proc structures"
F000E5FC: 94102000                 mov     0, %o2
F000E600: 96102000                 mov     0, %o3
F000E604: 4001a64d                 call    _zinit
F000E608: 981320d0                 bset    %lo(aProcStructures), %o4! "proc structures"
F000E60C: 133c04d3                 sethi   %hi(_proc_zone), %o1! size_t
F000E610: d02262a0                 st      %o0, [%o1+%lo(_proc_zone)]
F000E614: 113c04bc                 sethi   %hi(dword_F012F1FC), %o0
F000E618: c02221fc                 clr     [%o0+%lo(dword_F012F1FC)]
F000E61C: 113c04d2                 sethi   %hi(_freeproc), %o0! void *
F000E620: 7fffffc8                 call    _getproc
F000E624: c02222e0                 clr     [%o0+%lo(_freeproc)]
F000E628: a0100008                 mov     %o0, %l0
F000E62C: 40021a0b                 call    _bzero
F000E630: 92102088                 mov     0x88, %o1
F000E634: 113c04d3                 sethi   %hi(_allproc), %o0
F000E638: e0222278                 st      %l0, [%o0+%lo(_allproc)]
F000E63C: c0242008                 clr     [%l0+8]
F000E640: 90122278                 bset    %lo(_allproc), %o0
F000E644: d024200c                 st      %o0, [%l0+0xC]
F000E648: 113c04d1                 sethi   %hi(_kernel_proc), %o0
F000E64C: e0222348                 st      %l0, [%o0+%lo(_kernel_proc)]
F000E650: 113c04d3                 sethi   %hi(_zombproc), %o0
F000E654: c0222270                 clr     [%o0+%lo(_zombproc)]
F000E658: 81c7e008                 ret
F000E65C: 81e80000                 restore
