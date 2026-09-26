F000E540: 9de3bf98                 save    %sp, -0x68, %sp
F000E544: 153c04bc                 sethi   %hi(dword_F012F1FC), %o2
F000E548: d202a1fc                 ld      [%o2+%lo(dword_F012F1FC)], %o1
F000E54C: 113c043c                 sethi   %hi(_max_proc), %o0
F000E550: d002236c                 ld      [%o0+%lo(_max_proc)], %o0
F000E554: 80a24008                 cmp     %o1, %o0
F000E558: 16800008                 bge     locret_F000E578
F000E55C: b0102000                 mov     0, %i0
F000E560: 113c04d3                 sethi   %hi(_proc_zone), %o0
F000E564: d00222a0                 ld      [%o0+%lo(_proc_zone)], %o0
F000E568: 92026001                 inc     %o1
F000E56C: 4001aad8                 call    _zalloc
F000E570: d222a1fc                 st      %o1, [%o2+%lo(dword_F012F1FC)]
F000E574: b0100008                 mov     %o0, %i0
F000E578: 81c7e008                 ret
F000E57C: 81e80000                 restore
