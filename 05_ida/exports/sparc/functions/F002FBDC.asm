F002FBDC: 9de3bf98                 save    %sp, -0x68, %sp
F002FBE0: 4000e124                 call    _kalloc
F002FBE4: 90102148                 mov     0x148, %o0! void *
F002FBE8: b0100008                 mov     %o0, %i0
F002FBEC: 4001949b                 call    _bzero
F002FBF0: 92102148                 mov     0x148, %o1
F002FBF4: 9010001a                 mov     %i2, %o0! void *
F002FBF8: 92062038                 add     %i0, 0x38, %o1 ! '8'! void *
F002FBFC: 153c0000                 sethi   -0x10000000, %o2
F002FC00: 193c04d9                 sethi   %hi(_ip_id), %o4
F002FC04: d6060000                 ld      [%i0], %o3
F002FC08: a0102001                 mov     1, %l0
F002FC0C: da1320a0                 lduh    [%o4+%lo(_ip_id)], %o5
F002FC10: 942ac00a                 andn    %o3, %o2, %o2
F002FC14: 17100000                 sethi   0x40000000, %o3
F002FC18: 9412800b                 bset    %o3, %o2
F002FC1C: 1703c000                 sethi   0xF000000, %o3
F002FC20: 962a800b                 andn    %o2, %o3, %o3
F002FC24: 15014000                 sethi   0x5000000, %o2
F002FC28: 9612c00a                 bset    %o2, %o3
F002FC2C: d6260000                 st      %o3, [%i0]
F002FC30: 94036001                 add     %o5, 1, %o2
F002FC34: d43320a0                 sth     %o2, [%o4+%lo(_ip_id)]
F002FC38: da362004                 sth     %o5, [%i0+4]
F002FC3C: 941020ff                 mov     0xFF, %o2
F002FC40: d42e2008                 stb     %o2, [%i0+8]
F002FC44: 94102011                 mov     0x11, %o2
F002FC48: d42e2009                 stb     %o2, [%i0+9]
F002FC4C: d6066004                 ld      [%i1+4], %o3
F002FC50: 94102006                 mov     6, %o2! size_t
F002FC54: d626200c                 st      %o3, [%i0+0xC]
F002FC58: 96103fff                 mov     -1, %o3
F002FC5C: d6262010                 st      %o3, [%i0+0x10]
F002FC60: 96102044                 mov     0x44, %o3 ! 'D'
F002FC64: d6362014                 sth     %o3, [%i0+0x14]
F002FC68: 96102043                 mov     0x43, %o3 ! 'C'
F002FC6C: d6362016                 sth     %o3, [%i0+0x16]
F002FC70: c036201a                 clrh    [%i0+0x1A]
F002FC74: e02e201c                 stb     %l0, [%i0+0x1C]
F002FC78: e02e201d                 stb     %l0, [%i0+0x1D]
F002FC7C: 96102006                 mov     6, %o3
F002FC80: d62e201e                 stb     %o3, [%i0+0x1E]
F002FC84: 400193a3                 call    _bcopy
F002FC88: c0262028                 clr     [%i0+0x28]
F002FC8C: 113c0431901220d0         set     aNext_0, %o0! "NeXT"
F002FC94: 92062108                 add     %i0, 0x108, %o1! void *
F002FC98: 4001939e                 call    _bcopy
F002FC9C: 94102004                 mov     4, %o2
F002FCA0: e02e210c                 stb     %l0, [%i0+0x10C]
F002FCA4: c02e210e                 clrb    [%i0+0x10E]
F002FCA8: 90102134                 mov     0x134, %o0
F002FCAC: d0362018                 sth     %o0, [%i0+0x18]
F002FCB0: 90102148                 mov     0x148, %o0
F002FCB4: d0362002                 sth     %o0, [%i0+2]
F002FCB8: c036200a                 clrh    [%i0+0xA]
F002FCBC: 81c7e008                 ret
F002FCC0: 81e80000                 restore
