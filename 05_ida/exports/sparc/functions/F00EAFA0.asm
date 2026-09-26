F00EAFA0: 9de3bf90                 save    %sp, -0x70, %sp
F00EAFA4: 80a6a000                 cmp     %i2, 0
F00EAFA8: 0280000f                 be      locret_F00EAFE4
F00EAFAC: f426200c                 st      %i2, [%i0+0xC]
F00EAFB0: 213c0506                 sethi   %hi(paZone), %l0
F00EAFB4: 90100018                 mov     %i0, %o0! id
F00EAFB8: 40001a2e                 call    _objc_msgSend
F00EAFBC: d2042254                 ld      [%l0+%lo(paZone)], %o1! SEL
F00EAFC0: a2100008                 mov     %o0, %l1
F00EAFC4: 90100018                 mov     %i0, %o0! id
F00EAFC8: 40001a2a                 call    _objc_msgSend
F00EAFCC: d2042254                 ld      [%l0+%lo(paZone)], %o1
F00EAFD0: d206200c                 ld      [%i0+0xC], %o1
F00EAFD4: d4046004                 ld      [%l1+4], %o2
F00EAFD8: 9fc28000                 call    %o2
F00EAFDC: 932a6002                 sll     %o1, 2, %o1
F00EAFE0: d0262004                 st      %o0, [%i0+4]
F00EAFE4: 81c7e008                 ret
F00EAFE8: 81e80000                 restore
