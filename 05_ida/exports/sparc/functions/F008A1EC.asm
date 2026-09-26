F008A1EC: 9de3bf98                 save    %sp, -0x68, %sp
F008A1F0: 113c04d0                 sethi   %hi(_active_threads), %o0
F008A1F4: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F008A1F8: d202200c                 ld      [%o0+0xC], %o1
F008A1FC: 113c04d0                 sethi   %hi(_page_mask), %o0
F008A200: d40220d8                 ld      [%o0+%lo(_page_mask)], %o2
F008A204: 98102000                 mov     0, %o4
F008A208: 9638000a                 xnor    %g0, %o2, %o3
F008A20C: 9402a001                 inc     %o2
F008A210: 9406000a                 add     %i0, %o2, %o2
F008A214: d002600c                 ld      [%o1+0xC], %o0
F008A218: 940a800b                 and     %o2, %o3, %o2
F008A21C: 920e000b                 and     %i0, %o3, %o1
F008A220: 7fffe9fa                 call    _vm_map_protect
F008A224: 96100019                 mov     %i1, %o3
F008A228: 80a00008                 cmp     %g0, %o0
F008A22C: b0603fff                 subc    %g0, -1, %i0
F008A230: 81c7e008                 ret
F008A234: 81e80000                 restore
