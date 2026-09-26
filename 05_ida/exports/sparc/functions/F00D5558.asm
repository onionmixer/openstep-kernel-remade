F00D5558: 9de3bf98                 save    %sp, -0x68, %sp
F00D555C: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D5560: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D5564: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00D5568: 400070c2                 call    _objc_msgSend
F00D556C: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00D5570: 133c0505                 sethi   %hi(paSetspecialkeyp), %o1
F00D5574: 94100018                 mov     %i0, %o2
F00D5578: 96100019                 mov     %i1, %o3
F00D557C: d20262f8                 ld      [%o1+%lo(paSetspecialkeyp)], %o1! SEL
F00D5580: 400070bc                 call    _objc_msgSend
F00D5584: 9810001a                 mov     %i2, %o4
F00D5588: 81c7e008                 ret
F00D558C: 91e80008                 restore %g0, %o0, %o0
