F004D11C: 9de3bf98                 save    %sp, -0x68, %sp
F004D120: 133c04eb                 sethi   %hi(dword_F013AD9C), %o1
F004D124: d002619c                 ld      [%o1+%lo(dword_F013AD9C)], %o0
F004D128: 80a22000                 cmp     %o0, 0
F004D12C: 0280000f                 be      loc_F004D168
F004D130: 9812619c                 or      %o1, %lo(dword_F013AD9C), %o4
F004D134: d406200c                 ld      [%i0+0xC], %o2
F004D138: 17200000                 sethi   0x80000000, %o3
F004D13C: 808a800b                 btst    %o3, %o2
F004D140: 1280000a                 bne     loc_F004D168
F004D144: 80a22000                 cmp     %o0, 0
F004D148: d2062010                 ld      [%i0+0x10], %o1
F004D14C: 90062010                 add     %i0, 0x10, %o0
F004D150: 80a20009                 cmp     %o0, %o1
F004D154: 12800017                 bne     locret_F004D1B0
F004D158: 9012800b                 or      %o2, %o3, %o0
F004D15C: d026200c                 st      %o0, [%i0+0xC]
F004D160: 10800012                 ba      loc_F004D1A8
F004D164: d2033ff8                 ld      [%o4-8], %o1
F004D168: 12800012                 bne     locret_F004D1B0
F004D16C: a012619c                 or      %o1, 0x19C, %l0
F004D170: d006200c                 ld      [%i0+0xC], %o0
F004D174: 80a22000                 cmp     %o0, 0
F004D178: 1680000e                 bge     locret_F004D1B0
F004D17C: 01000000                 nop
F004D180: d2043ff0                 ld      [%l0-0x10], %o1
F004D184: 9fc24000                 call    %o1
F004D188: 90100018                 mov     %i0, %o0
F004D18C: 80a22000                 cmp     %o0, 0
F004D190: 12800008                 bne     locret_F004D1B0
F004D194: 13200000                 sethi   0x80000000, %o1
F004D198: d006200c                 ld      [%i0+0xC], %o0
F004D19C: 922a0009                 andn    %o0, %o1, %o1
F004D1A0: d226200c                 st      %o1, [%i0+0xC]
F004D1A4: d2043ffc                 ld      [%l0-4], %o1
F004D1A8: 9fc24000                 call    %o1
F004D1AC: 90100018                 mov     %i0, %o0
F004D1B0: 81c7e008                 ret
F004D1B4: 81e80000                 restore
