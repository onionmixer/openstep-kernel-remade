F00B2718: 9de3bf98                 save    %sp, -0x68, %sp
F00B271C: f027a044                 st      %i0, [%fp+arg_44]
F00B2720: f227a048                 st      %i1, [%fp+arg_48]
F00B2724: 113c04c590122390         set     unk_F0131790, %o0! jmp_buf
F00B272C: 173c0466                 sethi   %hi(_nofault), %o3
F00B2730: d402e144                 ld      [%o3+%lo(_nofault)], %o2
F00B2734: 133c04c5                 sethi   %hi(dword_F013178C), %o1
F00B2738: d422638c                 st      %o2, [%o1+%lo(dword_F013178C)]
F00B273C: 7fff9186                 call    _setjmp
F00B2740: d022e144                 st      %o0, [%o3+%lo(_nofault)]
F00B2744: 80a22000                 cmp     %o0, 0
F00B2748: 1280000e                 bne     loc_F00B2780
F00B274C: b0102001                 mov     1, %i0
F00B2750: 213c0466                 sethi   %hi(_pokefault), %l0
F00B2754: d407a044                 ld      [%fp+arg_44], %o2
F00B2758: 90103fff                 mov     -1, %o0
F00B275C: d207a048                 ld      [%fp+arg_48], %o1
F00B2760: d0242148                 st      %o0, [%l0+%lo(_pokefault)]
F00B2764: d2228000                 st      %o1, [%o2]
F00B2768: 7fff9283                 call    _flush_writebuffers_to
F00B276C: d007a044                 ld      [%fp+arg_44], %o0
F00B2770: d0042148                 ld      [%l0+%lo(_pokefault)], %o0
F00B2774: 901a2001                 btog    1, %o0
F00B2778: 80a00008                 cmp     %g0, %o0
F00B277C: b0603fff                 subc    %g0, -1, %i0
F00B2780: 113c0466                 sethi   %hi(_pokefault), %o0
F00B2784: c0222148                 clr     [%o0+%lo(_pokefault)]
F00B2788: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B278C: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B2790: 113c0466                 sethi   %hi(_nofault), %o0
F00B2794: d2222144                 st      %o1, [%o0+%lo(_nofault)]
F00B2798: 81c7e008                 ret
F00B279C: 81e80000                 restore
