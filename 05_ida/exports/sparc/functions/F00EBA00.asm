F00EBA00: 9de3bf90                 save    %sp, -0x70, %sp
F00EBA04: 213c0506                 sethi   %hi(paCopyfromzone), %l0
F00EBA08: 133c0506                 sethi   %hi(paZone), %o1! SEL
F00EBA0C: 90100018                 mov     %i0, %o0! id
F00EBA10: 40001798                 call    _objc_msgSend
F00EBA14: d2026254                 ld      [%o1+%lo(paZone)], %o1! SEL
F00EBA18: 94100008                 mov     %o0, %o2
F00EBA1C: 90100018                 mov     %i0, %o0! id
F00EBA20: 40001794                 call    _objc_msgSend
F00EBA24: d204222c                 ld      [%l0+%lo(paCopyfromzone)], %o1
F00EBA28: 81c7e008                 ret
F00EBA2C: 91e80008                 restore %g0, %o0, %o0
