F00155E4: 9de3bf78                 save    %sp, -0x88, %sp
F00155E8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00155EC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F00155F0: d2022024                 ld      [%o0+0x24], %o1
F00155F4: 9007bfd8                 add     %fp, var_28, %o0
F00155F8: d027bfe0                 st      %o0, [%fp+var_20]
F00155FC: 90102001                 mov     1, %o0
F0015600: d027bfe4                 st      %o0, [%fp+var_1C]
F0015604: d0026004                 ld      [%o1+4], %o0
F0015608: d027bfd8                 st      %o0, [%fp+var_28]
F001560C: d2026008                 ld      [%o1+8], %o1
F0015610: 9007bfe0                 add     %fp, var_20, %o0
F0015614: d227bfdc                 st      %o1, [%fp+var_24]
F0015618: 40000021                 call    _rwuio
F001561C: 92102001                 mov     1, %o1
F0015620: 81c7e008                 ret
F0015624: 81e80000                 restore
