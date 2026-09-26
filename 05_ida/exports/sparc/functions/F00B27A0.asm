F00B27A0: 9de3bf90                 save    %sp, -0x70, %sp
F00B27A4: f027a044                 st      %i0, [%fp+arg_44]
F00B27A8: f237bff6                 sth     %i1, [%fp+var_A]
F00B27AC: 113c04c590122390         set     unk_F0131790, %o0! jmp_buf
F00B27B4: 173c0466                 sethi   %hi(_nofault), %o3
F00B27B8: d402e144                 ld      [%o3+%lo(_nofault)], %o2
F00B27BC: 133c04c5                 sethi   %hi(dword_F013178C), %o1
F00B27C0: d422638c                 st      %o2, [%o1+%lo(dword_F013178C)]
F00B27C4: 7fff9164                 call    _setjmp
F00B27C8: d022e144                 st      %o0, [%o3+%lo(_nofault)]
F00B27CC: 80a22000                 cmp     %o0, 0
F00B27D0: 1280000e                 bne     loc_F00B2808
F00B27D4: b0102001                 mov     1, %i0
F00B27D8: 213c0466                 sethi   %hi(_pokefault), %l0
F00B27DC: d407a044                 ld      [%fp+arg_44], %o2
F00B27E0: 90103fff                 mov     -1, %o0
F00B27E4: d217bff6                 lduh    [%fp+var_A], %o1
F00B27E8: d0242148                 st      %o0, [%l0+%lo(_pokefault)]
F00B27EC: d2328000                 sth     %o1, [%o2]
F00B27F0: 7fff9261                 call    _flush_writebuffers_to
F00B27F4: d007a044                 ld      [%fp+arg_44], %o0
F00B27F8: d0042148                 ld      [%l0+%lo(_pokefault)], %o0
F00B27FC: 901a2001                 btog    1, %o0
F00B2800: 80a00008                 cmp     %g0, %o0
F00B2804: b0603fff                 subc    %g0, -1, %i0
F00B2808: 113c0466                 sethi   %hi(_pokefault), %o0
F00B280C: c0222148                 clr     [%o0+%lo(_pokefault)]
F00B2810: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B2814: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B2818: 113c0466                 sethi   %hi(_nofault), %o0
F00B281C: d2222144                 st      %o1, [%o0+%lo(_nofault)]
F00B2820: 81c7e008                 ret
F00B2824: 81e80000                 restore
