F00C42E0: 9de3bf90                 save    %sp, -0x70, %sp
F00C42E4: 113c0506                 sethi   %hi(paSparckerndevic), %o0
F00C42E8: d00222c8                 ld      [%o0+%lo(paSparckerndevic)], %o0! id
F00C42EC: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00C42F0: 4000b560                 call    _objc_msgSend
F00C42F4: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00C42F8: 133c0504                 sethi   %hi(paInitfromconfig), %o1
F00C42FC: d2026070                 ld      [%o1+%lo(paInitfromconfig)], %o1! SEL
F00C4300: 4000b55c                 call    _objc_msgSend
F00C4304: 9410001a                 mov     %i2, %o2
F00C4308: 81c7e008                 ret
F00C430C: 91e80008                 restore %g0, %o0, %o0
