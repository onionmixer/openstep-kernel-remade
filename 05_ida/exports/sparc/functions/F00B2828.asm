F00B2828: 9de3bf90                 save    %sp, -0x70, %sp
F00B282C: f027a044                 st      %i0, [%fp+arg_44]
F00B2830: f22fbff7                 stb     %i1, [%fp+var_9]
F00B2834: 113c04c590122390         set     unk_F0131790, %o0! jmp_buf
F00B283C: 173c0466                 sethi   %hi(_nofault), %o3
F00B2840: d402e144                 ld      [%o3+%lo(_nofault)], %o2
F00B2844: 133c04c5                 sethi   %hi(dword_F013178C), %o1
F00B2848: d422638c                 st      %o2, [%o1+%lo(dword_F013178C)]
F00B284C: 7fff9142                 call    _setjmp
F00B2850: d022e144                 st      %o0, [%o3+%lo(_nofault)]
F00B2854: 80a22000                 cmp     %o0, 0
F00B2858: 1280000e                 bne     loc_F00B2890
F00B285C: b0102001                 mov     1, %i0
F00B2860: 213c0466                 sethi   %hi(_pokefault), %l0
F00B2864: d407a044                 ld      [%fp+arg_44], %o2
F00B2868: 90103fff                 mov     -1, %o0
F00B286C: d20fbff7                 ldub    [%fp+var_9], %o1
F00B2870: d0242148                 st      %o0, [%l0+%lo(_pokefault)]
F00B2874: d22a8000                 stb     %o1, [%o2]
F00B2878: 7fff923f                 call    _flush_writebuffers_to
F00B287C: d007a044                 ld      [%fp+arg_44], %o0
F00B2880: d0042148                 ld      [%l0+%lo(_pokefault)], %o0
F00B2884: 901a2001                 btog    1, %o0
F00B2888: 80a00008                 cmp     %g0, %o0
F00B288C: b0603fff                 subc    %g0, -1, %i0
F00B2890: 113c0466                 sethi   %hi(_pokefault), %o0
F00B2894: c0222148                 clr     [%o0+%lo(_pokefault)]
F00B2898: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B289C: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B28A0: 113c0466                 sethi   %hi(_nofault), %o0
F00B28A4: d2222144                 st      %o1, [%o0+%lo(_nofault)]
F00B28A8: 81c7e008                 ret
F00B28AC: 81e80000                 restore
