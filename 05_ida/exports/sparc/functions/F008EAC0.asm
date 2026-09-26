F008EAC0: 9de3bf98                 save    %sp, -0x68, %sp
F008EAC4: a0100018                 mov     %i0, %l0
F008EAC8: 7fff656a                 call    _kalloc
F008EACC: 90102068                 mov     0x68, %o0! __b
F008EAD0: b0100008                 mov     %o0, %i0
F008EAD4: 92102000                 mov     0, %o1! __c
F008EAD8: 7ffdde29                 call    _memset
F008EADC: 94102068                 mov     0x68, %o2 ! 'h'! __len
F008EAE0: 90100018                 mov     %i0, %o0! __b
F008EAE4: 92102000                 mov     0, %o1! __c
F008EAE8: 7ffdde25                 call    _memset
F008EAEC: 9410202c                 mov     0x2C, %o2 ! ','
F008EAF0: 113c0506                 sethi   %hi(paKernlock), %o0
F008EAF4: d002228c                 ld      [%o0+%lo(paKernlock)], %o0! id
F008EAF8: 133c0503                 sethi   %hi(paAlloc), %o1
F008EAFC: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F008EB00: 40018b5c                 call    _objc_msgSend
F008EB04: c0260000                 clr     [%i0]
F008EB08: 133c0504                 sethi   %hi(paInitwithlevel), %o1
F008EB0C: d2026028                 ld      [%o1+%lo(paInitwithlevel)], %o1! SEL
F008EB10: 40018b58                 call    _objc_msgSend
F008EB14: 9410200a                 mov     0xA, %o2
F008EB18: d0262030                 st      %o0, [%i0+0x30]
F008EB1C: 7fff2ac5                 call    _ipc_object_reference
F008EB20: 90100010                 mov     %l0, %o0
F008EB24: e026202c                 st      %l0, [%i0+0x2C]
F008EB28: 113c023b901221c4         set     sub_F008EDC4, %o0
F008EB30: d0262040                 st      %o0, [%i0+0x40]
F008EB34: f0262048                 st      %i0, [%i0+0x48]
F008EB38: c0262058                 clr     [%i0+0x58]
F008EB3C: 90103ffe                 mov     -2, %o0
F008EB40: d0262008                 st      %o0, [%i0+8]
F008EB44: c026200c                 clr     [%i0+0xC]
F008EB48: c0262010                 clr     [%i0+0x10]
F008EB4C: 7fff2ab9                 call    _ipc_object_reference
F008EB50: d006202c                 ld      [%i0+0x2C], %o0
F008EB54: 81c7e008                 ret
F008EB58: 81e80000                 restore
