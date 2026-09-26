F00D1E90: 9de3bf90                 save    %sp, -0x70, %sp
F00D1E94: 213c04bb                 sethi   %hi(dword_F012EEA8), %l0
F00D1E98: d00422a8                 ld      [%l0+%lo(dword_F012EEA8)], %o0
F00D1E9C: 80a22000                 cmp     %o0, 0
F00D1EA0: 3280001e                 bne,a   locret_F00D1F18
F00D1EA4: b0102001                 mov     1, %i0
F00D1EA8: 113c0503                 sethi   %hi(paAlloc), %o0! id
F00D1EAC: d20223f0                 ld      [%o0+%lo(paAlloc)], %o1! SEL
F00D1EB0: 40007e70                 call    _objc_msgSend
F00D1EB4: 90100018                 mov     %i0, %o0! id
F00D1EB8: d02422a8                 st      %o0, [%l0+%lo(dword_F012EEA8)]
F00D1EBC: c022210c                 clr     [%o0+0x10C]
F00D1EC0: 133c0504                 sethi   %hi(paSetunit), %o1
F00D1EC4: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00D1EC8: 40007e6a                 call    _objc_msgSend
F00D1ECC: 94102000                 mov     0, %o2
F00D1ED0: 133c0504                 sethi   %hi(paSetname), %o1
F00D1ED4: d00422a8                 ld      [%l0+%lo(dword_F012EEA8)], %o0! id
F00D1ED8: 153c03ee                 sethi   %hi(aEvent0), %o2! "event0"
F00D1EDC: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00D1EE0: 40007e64                 call    _objc_msgSend
F00D1EE4: 9412a308                 bset    %lo(aEvent0), %o2! "event0"
F00D1EE8: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00D1EEC: d00422a8                 ld      [%l0+0x2A8], %o0! id
F00D1EF0: 153c03ee                 sethi   %hi(aEvent), %o2! "event"
F00D1EF4: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00D1EF8: 40007e5e                 call    _objc_msgSend
F00D1EFC: 9412a310                 bset    %lo(aEvent), %o2! "event"
F00D1F00: d00422a8                 ld      [%l0+0x2A8], %o0! id
F00D1F04: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00D1F08: 40007e5a                 call    _objc_msgSend
F00D1F0C: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00D1F10: 80a00008                 cmp     %g0, %o0
F00D1F14: b0402000                 addc    %g0, 0, %i0
F00D1F18: 81c7e008                 ret
F00D1F1C: 81e80000                 restore
