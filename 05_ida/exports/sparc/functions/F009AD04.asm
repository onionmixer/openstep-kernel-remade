F009AD04: 9de3bf98                 save    %sp, -0x68, %sp
F009AD08: 113c045d                 sethi   %hi(_swift_kdnc), %o0
F009AD0C: d0022160                 ld      [%o0+%lo(_swift_kdnc)], %o0
F009AD10: 80a22001                 cmp     %o0, 1
F009AD14: 12800007                 bne     loc_F009AD30
F009AD18: 92100019                 mov     %i1, %o1
F009AD1C: 113c04f6                 sethi   %hi(_etext), %o0
F009AD20: d00221e0                 ld      [%o0+%lo(_etext)], %o0
F009AD24: 80a68008                 cmp     %i2, %o0
F009AD28: 38800002                 bgu,a   loc_F009AD30
F009AD2C: b00e3f7f                 and     %i0, -0x81, %i0
F009AD30: e0024000                 ld      [%o1], %l0
F009AD34: 80a40018                 cmp     %l0, %i0
F009AD38: 0280001e                 be      locret_F009ADB0
F009AD3C: 113c045d                 sethi   %hi(_swift_kdnx), %o0
F009AD40: d0022164                 ld      [%o0+%lo(_swift_kdnx)], %o0
F009AD44: 80a22001                 cmp     %o0, 1
F009AD48: 1280000c                 bne     loc_F009AD78
F009AD4C: 900e2003                 and     %i0, 3, %o0
F009AD50: 80a22002                 cmp     %o0, 2
F009AD54: 12800009                 bne     loc_F009AD78
F009AD58: 1103c000                 sethi   0xF000000, %o0
F009AD5C: 808e0008                 btst    %o0, %i0
F009AD60: 02800006                 be      loc_F009AD78
F009AD64: 900e201c                 and     %i0, 0x1C, %o0
F009AD68: 80a2201c                 cmp     %o0, 0x1C
F009AD6C: 12800003                 bne     loc_F009AD78
F009AD70: 900e3fe3                 and     %i0, -0x1D, %o0
F009AD74: b0122014                 or      %o0, 0x14, %i0
F009AD78: 7ffff03f                 call    _swapl
F009AD7C: 90100018                 mov     %i0, %o0
F009AD80: 808c2003                 btst    3, %l0
F009AD84: 0280000b                 be      locret_F009ADB0
F009AD88: 80a73fff                 cmp     %i4, -1
F009AD8C: 02800009                 be      locret_F009ADB0
F009AD90: 9010001b                 mov     %i3, %o0
F009AD94: 9210001a                 mov     %i2, %o1
F009AD98: 4000273f                 call    _srmmu_tlbflush
F009AD9C: 9410001c                 mov     %i4, %o2
F009ADA0: 9010001b                 mov     %i3, %o0
F009ADA4: 9210001a                 mov     %i2, %o1
F009ADA8: 40002757                 call    _srmmu_vacflush
F009ADAC: 9410001c                 mov     %i4, %o2
F009ADB0: 81c7e008                 ret
F009ADB4: 81e80000                 restore
