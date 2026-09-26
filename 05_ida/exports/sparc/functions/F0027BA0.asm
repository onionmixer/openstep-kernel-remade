F0027BA0: 9de3bf98                 save    %sp, -0x68, %sp
F0027BA4: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0027BA8: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0027BAC: d0022024                 ld      [%o0+0x24], %o0
F0027BB0: 92102000                 mov     0, %o1
F0027BB4: d0020000                 ld      [%o0], %o0
F0027BB8: 400005d6                 call    _vn_remove
F0027BBC: 94102000                 mov     0, %o2
F0027BC0: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0027BC4: d02a6038                 stb     %o0, [%o1+0x38]
F0027BC8: 81c7e008                 ret
F0027BCC: 81e80000                 restore
