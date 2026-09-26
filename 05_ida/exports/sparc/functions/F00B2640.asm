F00B2640: 9de3bf90                 save    %sp, -0x70, %sp
F00B2644: f027a044                 st      %i0, [%fp+arg_44]
F00B2648: 113c04c590122390         set     unk_F0131790, %o0! jmp_buf
F00B2650: 173c0466                 sethi   %hi(_nofault), %o3
F00B2654: d402e144                 ld      [%o3+%lo(_nofault)], %o2
F00B2658: 133c04c5                 sethi   %hi(dword_F013178C), %o1
F00B265C: d422638c                 st      %o2, [%o1+%lo(dword_F013178C)]
F00B2660: 7fff91bd                 call    _setjmp
F00B2664: d022e144                 st      %o0, [%o3+%lo(_nofault)]
F00B2668: 80a22000                 cmp     %o0, 0
F00B266C: 02800005                 be      loc_F00B2680
F00B2670: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B2674: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B2678: 10800008                 ba      loc_F00B2698
F00B267C: b0103fff                 mov     -1, %i0
F00B2680: d007a044                 ld      [%fp+arg_44], %o0
F00B2684: f04a0000                 ldsb    [%o0], %i0
F00B2688: f027bff4                 st      %i0, [%fp+var_C]
F00B268C: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B2690: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B2694: b00e20ff                 and     %i0, 0xFF, %i0
F00B2698: 113c0466                 sethi   %hi(_nofault), %o0
F00B269C: d2222144                 st      %o1, [%o0+%lo(_nofault)]
F00B26A0: 81c7e008                 ret
F00B26A4: 81e80000                 restore
