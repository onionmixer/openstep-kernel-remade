F008DF08: 9de3bf90                 save    %sp, -0x70, %sp
F008DF0C: f027bff0                 st      %i0, [%fp+var_10]
F008DF10: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008DF14: 133c0507                 sethi   %hi(stru_F0141C3C.ext), %o1
F008DF18: 992f6018                 sll     %i5, 24, %o4
F008DF1C: 9610001b                 mov     %i3, %o3
F008DF20: d4026068                 ld      [%o1+%lo(stru_F0141C3C.ext)], %o2
F008DF24: 993b2018                 sra     %o4, 24, %o4
F008DF28: 133c0504                 sethi   %hi(paInitforresourc_0), %o1
F008DF2C: d427bff4                 st      %o2, [%fp+var_C]
F008DF30: d2026034                 ld      [%o1+%lo(paInitforresourc_0)], %o1! SEL
F008DF34: 40018e92                 call    _objc_msgSendSuper
F008DF38: 9410001a                 mov     %i2, %o2
F008DF3C: 113c0503                 sethi   %hi(paAlloc), %o0
F008DF40: e20223f0                 ld      [%o0+%lo(paAlloc)], %l1
F008DF44: 113c0506                 sethi   %hi(paList), %o0
F008DF48: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F008DF4C: 40018e49                 call    _objc_msgSend
F008DF50: 92100011                 mov     %l1, %o1
F008DF54: 133c0504                 sethi   %hi(paInit), %o1! SEL
F008DF58: e002602c                 ld      [%o1+%lo(paInit)], %l0
F008DF5C: 40018e45                 call    _objc_msgSend
F008DF60: 92100010                 mov     %l0, %o1
F008DF64: d0262014                 st      %o0, [%i0+0x14]
F008DF68: 113c0506                 sethi   %hi(paKernlock), %o0! id
F008DF6C: e402228c                 ld      [%o0+%lo(paKernlock)], %l2
F008DF70: 92100011                 mov     %l1, %o1! SEL
F008DF74: 40018e3f                 call    _objc_msgSend
F008DF78: 90100012                 mov     %l2, %o0! id
F008DF7C: 40018e3d                 call    _objc_msgSend
F008DF80: 92100010                 mov     %l0, %o1! SEL
F008DF84: d026201c                 st      %o0, [%i0+0x1C]
F008DF88: 90100012                 mov     %l2, %o0! id
F008DF8C: 40018e39                 call    _objc_msgSend
F008DF90: 92100011                 mov     %l1, %o1! SEL
F008DF94: 40018e37                 call    _objc_msgSend
F008DF98: 92100010                 mov     %l0, %o1
F008DF9C: d0262024                 st      %o0, [%i0+0x24]
F008DFA0: 80a72000                 cmp     %i4, 0
F008DFA4: 12800005                 bne     locret_F008DFB8
F008DFA8: f8262028                 st      %i4, [%i0+0x28]
F008DFAC: 113c023b90122028         set     _KernDeviceInterruptDispatch, %o0
F008DFB4: d0262028                 st      %o0, [%i0+0x28]
F008DFB8: 81c7e008                 ret
F008DFBC: 81e80000                 restore
