F008C2D8: 9de3bf98                 save    %sp, -0x68, %sp
F008C2DC: 90102018                 mov     0x18, %o0
F008C2E0: 130000ea                 sethi   0x3A800, %o1
F008C2E4: 153c0447                 sethi   %hi(_page_size), %o2
F008C2E8: 193c0447                 sethi   %hi(aVnodePagerStru), %o4! "vnode pager structures"
F008C2EC: 92126180                 bset    0x180, %o1
F008C2F0: d402a13c                 ld      [%o2+%lo(_page_size)], %o2
F008C2F4: 96102000                 mov     0, %o3
F008C2F8: 7fffaf10                 call    _zinit
F008C2FC: 98132380                 bset    %lo(aVnodePagerStru), %o4! "vnode pager structures"
F008C300: 133c04f6                 sethi   %hi(_vstruct_zone), %o1
F008C304: d02261a0                 st      %o0, [%o1+%lo(_vstruct_zone)]
F008C308: 113c04f6                 sethi   %hi(_vstruct_lock), %o0
F008C30C: c0222198                 clr     [%o0+%lo(_vstruct_lock)]
F008C310: 133c04c390126364         set     dword_F0130F64, %o0
F008C318: d0222004                 st      %o0, [%o0+4]
F008C31C: d0226364                 st      %o0, [%o1+%lo(dword_F013DB64)]
F008C320: 81c7e008                 ret
F008C324: 81e80000                 restore
