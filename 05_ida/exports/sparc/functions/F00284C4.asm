F00284C4: 9de3bf48                 save    %sp, -0xB8, %sp! int
F00284C8: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F00284CC: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F00284D0: e4022024                 ld      [%o0+0x24], %l2
F00284D4: 9207bfe8                 add     %fp, var_18, %o1! int
F00284D8: d004a004                 ld      [%l2+4], %o0! int
F00284DC: 4001bedf                 call    _copyin
F00284E0: 94102010                 mov     0x10, %o2
F00284E4: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F00284E8: d02a6038                 stb     %o0, [%o1+0x38]
F00284EC: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F00284F0: d04a2038                 ldsb    [%o0+0x38], %o0
F00284F4: 80a22000                 cmp     %o0, 0
F00284F8: 12800012                 bne     locret_F0028540
F00284FC: a007bfa8                 add     %fp, var_58, %l0
F0028500: 400003e5                 call    _vattr_null
F0028504: 90100010                 mov     %l0, %o0
F0028508: d007bfe8                 ld      [%fp+var_18], %o0
F002850C: d407bfec                 ld      [%fp+var_14], %o2
F0028510: 92102001                 mov     1, %o1
F0028514: d607bff0                 ld      [%fp+var_10], %o3
F0028518: d027bfc8                 st      %o0, [%fp+var_38]
F002851C: d427bfcc                 st      %o2, [%fp+var_34]
F0028520: d007bff4                 ld      [%fp+var_C], %o0
F0028524: d627bfd0                 st      %o3, [%fp+var_30]
F0028528: d027bfd4                 st      %o0, [%fp+var_2C]
F002852C: d0048000                 ld      [%l2], %o0
F0028530: 4000009e                 call    _namesetattr
F0028534: 94100010                 mov     %l0, %o2
F0028538: d20461dc                 ld      [%l1+0x1DC], %o1
F002853C: d02a6038                 stb     %o0, [%o1+0x38]
F0028540: 81c7e008                 ret
F0028544: 81e80000                 restore
