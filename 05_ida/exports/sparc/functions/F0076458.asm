F0076458: 9de3bf98                 save    %sp, -0x68, %sp
F007645C: d006204c                 ld      [%i0+0x4C], %o0
F0076460: 920a2300                 and     %o0, 0x300, %o1
F0076464: 80a26100                 cmp     %o1, 0x100
F0076468: 02800005                 be      loc_F007647C
F007646C: 80a26200                 cmp     %o1, 0x200
F0076470: 0280001f                 be      locret_F00764EC
F0076474: 113c0442                 sethi   -0xFEEF800, %o0
F0076478: 3080001b                 ba,a    loc_F00764E4
F007647C: 900a3cff                 and     %o0, -0x301, %o0
F0076480: 90122200                 bset    0x200, %o0
F0076484: d026204c                 st      %o0, [%i0+0x4C]
F0076488: 113c04f2a0122330         set     _swapper_lock_data, %l0
F0076490: d0040000                 ld      [%l0], %o0
F0076494: 80a22000                 cmp     %o0, 0
F0076498: 12bffffe                 bne     loc_F0076490
F007649C: 01000000                 nop
F00764A0: 40008282                 call    _simple_lock_try
F00764A4: 90100010                 mov     %l0, %o0
F00764A8: 80a22000                 cmp     %o0, 0
F00764AC: 02bffff9                 be      loc_F0076490
F00764B0: 113c04f2                 sethi   %hi(_swapin_queue), %o0
F00764B4: 90122328                 bset    %lo(_swapin_queue), %o0! char *
F00764B8: d0260000                 st      %o0, [%i0]
F00764BC: d2022004                 ld      [%o0+4], %o1
F00764C0: 94102000                 mov     0, %o2
F00764C4: d2262004                 st      %o1, [%i0+4]
F00764C8: f0224000                 st      %i0, [%o1]
F00764CC: f0222004                 st      %i0, [%o0+4]
F00764D0: 133c04f2                 sethi   %hi(_swapper_lock_data), %o1
F00764D4: c0226330                 clr     [%o1+%lo(_swapper_lock_data)]
F00764D8: 7fffeac9                 call    _thread_wakeup_prim
F00764DC: 92102000                 mov     0, %o1
F00764E0: 30800003                 ba,a    locret_F00764EC
F00764E4: 7ffe7b23                 call    _panic
F00764E8: 901223a0                 bset    0x3A0, %o0
F00764EC: 81c7e008                 ret
F00764F0: 81e80000                 restore
