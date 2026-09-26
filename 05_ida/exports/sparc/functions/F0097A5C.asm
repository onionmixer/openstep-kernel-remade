F0097A5C: 9de3bf98                 save    %sp, -0x68, %sp
F0097A60: 073c04c5                 sethi   %hi(dword_F0131490), %g3
F0097A64: c400e090                 ld      [%g3+%lo(dword_F0131490)], %g2
F0097A68: 80a0a000                 cmp     %g2, 0
F0097A6C: 22800002                 be,a    locret_F0097A74
F0097A70: f220e090                 st      %i1, [%g3+%lo(dword_F0131490)]
F0097A74: 81c7e008                 ret
F0097A78: 81e80000                 restore
