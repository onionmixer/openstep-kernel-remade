F00B26A8: 9de3bf98                 save    %sp, -0x68, %sp
F00B26AC: f027a044                 st      %i0, [%fp+arg_44]
F00B26B0: f227a048                 st      %i1, [%fp+arg_48]
F00B26B4: 113c04c590122390         set     unk_F0131790, %o0! jmp_buf
F00B26BC: 173c0466                 sethi   %hi(_nofault), %o3
F00B26C0: d402e144                 ld      [%o3+%lo(_nofault)], %o2
F00B26C4: 133c04c5                 sethi   %hi(dword_F013178C), %o1
F00B26C8: d422638c                 st      %o2, [%o1+%lo(dword_F013178C)]
F00B26CC: 7fff91a2                 call    _setjmp
F00B26D0: d022e144                 st      %o0, [%o3+%lo(_nofault)]
F00B26D4: 80a22000                 cmp     %o0, 0
F00B26D8: 02800005                 be      loc_F00B26EC
F00B26DC: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B26E0: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B26E4: 10800009                 ba      loc_F00B2708
F00B26E8: b0103fff                 mov     -1, %i0
F00B26EC: d007a044                 ld      [%fp+arg_44], %o0
F00B26F0: d2020000                 ld      [%o0], %o1
F00B26F4: d007a048                 ld      [%fp+arg_48], %o0
F00B26F8: d2220000                 st      %o1, [%o0]
F00B26FC: 113c04c5                 sethi   %hi(dword_F013178C), %o0
F00B2700: d202238c                 ld      [%o0+%lo(dword_F013178C)], %o1
F00B2704: b0102000                 mov     0, %i0
F00B2708: 113c0466                 sethi   %hi(_nofault), %o0
F00B270C: d2222144                 st      %o1, [%o0+%lo(_nofault)]
F00B2710: 81c7e008                 ret
F00B2714: 81e80000                 restore
