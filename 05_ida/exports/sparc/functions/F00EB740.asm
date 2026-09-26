F00EB740: 9de3bf90                 save    %sp, -0x70, %sp
F00EB744: 113c04bc                 sethi   %hi(__alloc), %o0
F00EB748: d40220e8                 ld      [%o0+%lo(__alloc)], %o2
F00EB74C: 90100018                 mov     %i0, %o0
F00EB750: 9fc28000                 call    %o2
F00EB754: 92102000                 mov     0, %o1
F00EB758: 94100008                 mov     %o0, %o2
F00EB75C: d0060000                 ld      [%i0], %o0
F00EB760: d002200c                 ld      [%o0+0xC], %o0
F00EB764: 80a22001                 cmp     %o0, 1
F00EB768: 14800004                 bg      loc_F00EB778
F00EB76C: 133c0504                 sethi   -0xFEBF000, %o1! SEL
F00EB770: 10800006                 ba      locret_F00EB788
F00EB774: b010000a                 mov     %o2, %i0
F00EB778: 9010000a                 mov     %o2, %o0! id
F00EB77C: 4000183d                 call    _objc_msgSend
F00EB780: d202602c                 ld      [%o1+0x2C], %o1
F00EB784: b0100008                 mov     %o0, %i0
F00EB788: 81c7e008                 ret
F00EB78C: 81e80000                 restore
