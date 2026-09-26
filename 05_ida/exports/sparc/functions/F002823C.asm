F002823C: 9de3bf98                 save    %sp, -0x68, %sp
F0028240: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0028244: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0028248: d0022024                 ld      [%o0+0x24], %o0
F002824C: 40000006                 call    _stat1
F0028250: 92102000                 mov     0, %o1
F0028254: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0028258: d02a6038                 stb     %o0, [%o1+0x38]
F002825C: 81c7e008                 ret
F0028260: 81e80000                 restore
