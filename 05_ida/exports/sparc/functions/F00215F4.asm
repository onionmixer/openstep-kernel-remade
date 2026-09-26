F00215F4: 9de3bf78                 save    %sp, -0x88, %sp
F00215F8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00215FC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0021600: d2022024                 ld      [%o0+0x24], %o1
F0021604: d0026010                 ld      [%o1+0x10], %o0
F0021608: d027bfe0                 st      %o0, [%fp+var_20]
F002160C: d0026014                 ld      [%o1+0x14], %o0
F0021610: d027bfe4                 st      %o0, [%fp+var_1C]
F0021614: 9007bfd8                 add     %fp, var_28, %o0
F0021618: d027bfe8                 st      %o0, [%fp+var_18]
F002161C: 90102001                 mov     1, %o0
F0021620: d027bfec                 st      %o0, [%fp+var_14]
F0021624: d0026004                 ld      [%o1+4], %o0
F0021628: d027bfd8                 st      %o0, [%fp+var_28]
F002162C: d0026008                 ld      [%o1+8], %o0
F0021630: d027bfdc                 st      %o0, [%fp+var_24]
F0021634: c027bff0                 clr     [%fp+var_10]
F0021638: c027bff4                 clr     [%fp+var_C]
F002163C: d0024000                 ld      [%o1], %o0
F0021640: d402600c                 ld      [%o1+0xC], %o2
F0021644: 40000042                 call    _sendit
F0021648: 9207bfe0                 add     %fp, var_20, %o1
F002164C: 81c7e008                 ret
F0021650: 81e80000                 restore
