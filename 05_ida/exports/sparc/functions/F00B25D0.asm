F00B25D0: 9de3bf90                 save    %sp, -0x70, %sp
F00B25D4: f027a044                 st      %i0, [%fp+arg_44]
F00B25D8: 113c04c590122390         set     unk_F0131790, %o0! jmp_buf
F00B25E0: 173c0466                 sethi   %hi(_nofault), %o3
F00B25E4: d402e144                 ld      [%o3+%lo(_nofault)], %o2
F00B25E8: 133c04c5                 sethi   %hi(dword_F013178C), %o1
F00B25EC: d422638c                 st      %o2, [%o1+%lo(dword_F013178C)]
F00B25F0: 7fff91d9                 call    _setjmp
F00B25F4: d022e144                 st      %o0, [%o3+%lo(_nofault)]
F00B25F8: 80a22000                 cmp     %o0, 0
F00B25FC: 02800005                 be      loc_F00B2610
F00B2600: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B2604: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B2608: 1080000a                 ba      loc_F00B2630
F00B260C: b0103fff                 mov     -1, %i0
F00B2610: d007a044                 ld      [%fp+arg_44], %o0
F00B2614: 3100003f                 sethi   0xFC00, %i0
F00B2618: d4520000                 ldsh    [%o0], %o2
F00B261C: b01623ff                 bset    0x3FF, %i0
F00B2620: d427bff4                 st      %o2, [%fp+var_C]
F00B2624: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B2628: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B262C: b00a8018                 and     %o2, %i0, %i0
F00B2630: 113c0466                 sethi   %hi(_nofault), %o0
F00B2634: d2222144                 st      %o1, [%o0+%lo(_nofault)]
F00B2638: 81c7e008                 ret
F00B263C: 81e80000                 restore
