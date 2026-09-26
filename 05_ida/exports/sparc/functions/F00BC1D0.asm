F00BC1D0: 9de3bf98                 save    %sp, -0x68, %sp
F00BC1D4: 113c04c8                 sethi   %hi(dword_F0132048), %o0
F00BC1D8: a2102001                 mov     1, %l1
F00BC1DC: e2222048                 st      %l1, [%o0+%lo(dword_F0132048)]
F00BC1E0: 213c0485                 sethi   %hi(_static_KERNBOOTSTRUCT), %l0
F00BC1E4: 4000072b                 call    _BasicAllocateConsole
F00BC1E8: a0142050                 bset    %lo(_static_KERNBOOTSTRUCT), %l0
F00BC1EC: 94100008                 mov     %o0, %o2
F00BC1F0: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BC1F4: d2042138                 ld      [%l0+0x138], %o1
F00BC1F8: 80a26000                 cmp     %o1, 0
F00BC1FC: 0280000d                 be      loc_F00BC230
F00BC200: d4222228                 st      %o2, [%o0+%lo(_basicConsole)]
F00BC204: 133c04fd                 sethi   %hi(_basicConsoleMode), %o1
F00BC208: 90102002                 mov     2, %o0
F00BC20C: d0226230                 st      %o0, [%o1+%lo(_basicConsoleMode)]
F00BC210: 9010000a                 mov     %o2, %o0
F00BC214: 92102002                 mov     2, %o1
F00BC218: 153c047f                 sethi   %hi(_mach_title), %o2
F00BC21C: d802a274                 ld      [%o2+%lo(_mach_title)], %o4
F00BC220: 96102000                 mov     0, %o3
F00BC224: da022004                 ld      [%o0+4], %o5
F00BC228: 1080000b                 ba      loc_F00BC254
F00BC22C: 94102000                 mov     0, %o2
F00BC230: 113c04fd                 sethi   %hi(_basicConsoleMode), %o0
F00BC234: e2222230                 st      %l1, [%o0+%lo(_basicConsoleMode)]
F00BC238: 9010000a                 mov     %o2, %o0
F00BC23C: 92102001                 mov     1, %o1
F00BC240: 153c047f                 sethi   %hi(_mach_title), %o2
F00BC244: d802a274                 ld      [%o2+%lo(_mach_title)], %o4
F00BC248: 96102001                 mov     1, %o3
F00BC24C: da022004                 ld      [%o0+4], %o5
F00BC250: 94102001                 mov     1, %o2
F00BC254: 9fc34000                 call    %o5
F00BC258: 01000000                 nop
F00BC25C: 81c7e008                 ret
F00BC260: 81e80000                 restore
