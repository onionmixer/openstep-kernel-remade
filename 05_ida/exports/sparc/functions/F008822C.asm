F008822C: 9de3bf98                 save    %sp, -0x68, %sp
F0088230: 80a62000                 cmp     %i0, 0
F0088234: 32800006                 bne,a   loc_F008824C
F0088238: d0060000                 ld      [%i0], %o0
F008823C: 113c0447                 sethi   %hi(aVmPagerPutNull), %o0! "vm_pager_put: null pager"
F0088240: 7ffe33cc                 call    _panic
F0088244: 901220e0                 bset    %lo(aVmPagerPutNull), %o0! "vm_pager_put: null pager"
F0088248: d0060000                 ld      [%i0], %o0
F008824C: 80a22000                 cmp     %o0, 0
F0088250: 12800005                 bne     loc_F0088264
F0088254: 01000000                 nop
F0088258: 40000d1e                 call    _vnode_pageout
F008825C: 90100019                 mov     %i1, %o0
F0088260: 30800003                 ba,a    locret_F008826C
F0088264: 40000890                 call    _device_pageout
F0088268: 90100019                 mov     %i1, %o0
F008826C: 81c7e008                 ret
F0088270: 91e80008                 restore %g0, %o0, %o0
