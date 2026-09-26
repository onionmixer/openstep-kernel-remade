F00BEFD0: 9de3bf98                 save    %sp, -0x68, %sp
F00BEFD4: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00BEFD8: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00BEFDC: 7fff7fdf                 call    _pmap_extract
F00BEFE0: 92100019                 mov     %i1, %o1
F00BEFE4: 133c04f4                 sethi   %hi(_page_shift), %o1
F00BEFE8: f0026348                 ld      [%o1+%lo(_page_shift)], %i0
F00BEFEC: b1320018                 srl     %o0, %i0, %i0
F00BEFF0: 81c7e008                 ret
F00BEFF4: 81e80000                 restore
