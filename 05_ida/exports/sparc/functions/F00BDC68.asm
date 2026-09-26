F00BDC68: 9de3bf80                 save    %sp, -0x80, %sp
F00BDC6C: d0062114                 ld      [%i0+0x114], %o0
F00BDC70: 80a22002                 cmp     %o0, 2
F00BDC74: 1280001a                 bne     locret_F00BDCDC
F00BDC78: 133c04cb                 sethi   %hi(dword_F0132F18), %o1
F00BDC7C: 90102138                 mov     0x138, %o0
F00BDC80: d0226318                 st      %o0, [%o1+%lo(dword_F0132F18)]
F00BDC84: 90102138                 mov     0x138, %o0
F00BDC88: d037bfe4                 sth     %o0, [%fp+var_1C]
F00BDC8C: 133c04cb                 sethi   %hi(dword_F0132F1C), %o1
F00BDC90: 901020b0                 mov     0xB0, %o0
F00BDC94: d022631c                 st      %o0, [%o1+%lo(dword_F0132F1C)]
F00BDC98: 901020b0                 mov     0xB0, %o0
F00BDC9C: d037bfe6                 sth     %o0, [%fp+var_1A]
F00BDCA0: 9210219a                 mov     0x19A, %o1
F00BDCA4: 113c04cb                 sethi   %hi(dword_F0132F28), %o0
F00BDCA8: d2222328                 st      %o1, [%o0+%lo(dword_F0132F28)]
F00BDCAC: d237bfe0                 sth     %o1, [%fp+var_20]
F00BDCB0: 94102148                 mov     0x148, %o2
F00BDCB4: d437bfe2                 sth     %o2, [%fp+var_1E]
F00BDCB8: 113c03d3901223f8         set     _NSPanel, %o0
F00BDCC0: d027bfe8                 st      %o0, [%fp+var_18]
F00BDCC4: 133c04cb                 sethi   %hi(dword_F0132F2C), %o1
F00BDCC8: d006210c                 ld      [%i0+0x10C], %o0
F00BDCCC: d422632c                 st      %o2, [%o1+%lo(dword_F0132F2C)]
F00BDCD0: d402200c                 ld      [%o0+0xC], %o2
F00BDCD4: 9fc28000                 call    %o2
F00BDCD8: 9207bfe0                 add     %fp, var_20, %o1
F00BDCDC: 81c7e008                 ret
F00BDCE0: 81e80000                 restore
