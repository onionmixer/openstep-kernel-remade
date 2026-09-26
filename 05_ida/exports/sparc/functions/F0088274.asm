F0088274: 9de3bf98                 save    %sp, -0x68, %sp
F0088278: 80a62000                 cmp     %i0, 0
F008827C: 32800006                 bne,a   loc_F0088294
F0088280: d0060000                 ld      [%i0], %o0
F0088284: 113c0447                 sethi   %hi(aVmPagerDealloc), %o0! "vm_pager_deallocate: null pager"
F0088288: 7ffe33ba                 call    _panic
F008828C: 90122100                 bset    %lo(aVmPagerDealloc), %o0! "vm_pager_deallocate: null pager"
F0088290: d0060000                 ld      [%i0], %o0
F0088294: 80a22000                 cmp     %o0, 0
F0088298: 12800005                 bne     loc_F00882AC
F008829C: 01000000                 nop
F00882A0: 40000f4a                 call    _vnode_dealloc
F00882A4: 90100018                 mov     %i0, %o0
F00882A8: 30800003                 ba,a    locret_F00882B4
F00882AC: 40000884                 call    _device_dealloc
F00882B0: 90100018                 mov     %i0, %o0
F00882B4: 81c7e008                 ret
F00882B8: 91e80008                 restore %g0, %o0, %o0
