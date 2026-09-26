F0013DD8: 9de3bf98                 save    %sp, -0x68, %sp
F0013DDC: 80a66001                 cmp     %i1, 1
F0013DE0: 0480006f                 ble     locret_F0013F9C
F0013DE4: 113c042d                 sethi   %hi(dword_F010B480), %o0
F0013DE8: f4222080                 st      %i2, [%o0+%lo(dword_F010B480)]
F0013DEC: 113c042d                 sethi   %hi(dword_F010B47C), %o0
F0013DF0: f622207c                 st      %i3, [%o0+%lo(dword_F010B47C)]
F0013DF4: 912ea002                 sll     %i2, 2, %o0
F0013DF8: 213c042d                 sethi   %hi(dword_F010B484), %l0
F0013DFC: d0242084                 st      %o0, [%l0+%lo(dword_F010B484)]
F0013E00: 912ea001                 sll     %i2, 1, %o0
F0013E04: 9002001a                 add     %o0, %i2, %o0
F0013E08: 912a2001                 sll     %o0, 1, %o0
F0013E0C: 133c042d                 sethi   %hi(dword_F010B488), %o1
F0013E10: d0226088                 st      %o0, [%o1+%lo(dword_F010B488)]
F0013E14: 90100019                 mov     %i1, %o0
F0013E18: 7fffc9ba                 call    _umul
F0013E1C: 9210001a                 mov     %i2, %o1
F0013E20: 80a66003                 cmp     %i1, 3
F0013E24: 04800008                 ble     loc_F0013E44
F0013E28: a2060008                 add     %i0, %o0, %l1
F0013E2C: 90100018                 mov     %i0, %o0
F0013E30: 4000005d                 call    sub_F0013FA4
F0013E34: 92100011                 mov     %l1, %o1
F0013E38: d0042084                 ld      [%l0+%lo(dword_F010B484)], %o0
F0013E3C: 10800003                 ba      loc_F0013E48
F0013E40: b6060008                 add     %i0, %o0, %i3
F0013E44: b6100011                 mov     %l1, %i3
F0013E48: b2100018                 mov     %i0, %i1
F0013E4C: 133c042d                 sethi   %hi(dword_F010B480), %o1
F0013E50: d0026080                 ld      [%o1+%lo(dword_F010B480)], %o0
F0013E54: b4100019                 mov     %i1, %i2
F0013E58: b2064008                 add     %i1, %o0, %i1
F0013E5C: 80a6401b                 cmp     %i1, %i3
F0013E60: 1a800011                 bcc     loc_F0013EA4
F0013E64: 80a68018                 cmp     %i2, %i0
F0013E68: 253c042d                 sethi   -0xFEF4C00, %l2
F0013E6C: a0100009                 mov     %o1, %l0
F0013E70: 9010001a                 mov     %i2, %o0
F0013E74: d404a07c                 ld      [%l2+0x7C], %o2
F0013E78: 9fc28000                 call    %o2
F0013E7C: 92100019                 mov     %i1, %o1
F0013E80: 80a22000                 cmp     %o0, 0
F0013E84: 34800002                 bg,a    loc_F0013E8C
F0013E88: b4100019                 mov     %i1, %i2
F0013E8C: d0042080                 ld      [%l0+0x80], %o0
F0013E90: b2064008                 add     %i1, %o0, %i1
F0013E94: 80a6401b                 cmp     %i1, %i3
F0013E98: 0abffff7                 bcs     loc_F0013E74
F0013E9C: 9010001a                 mov     %i2, %o0
F0013EA0: 80a68018                 cmp     %i2, %i0
F0013EA4: 02800010                 be      loc_F0013EE4
F0013EA8: 113c042d                 sethi   %hi(dword_F010B480), %o0
F0013EAC: d0022080                 ld      [%o0+%lo(dword_F010B480)], %o0
F0013EB0: 92100018                 mov     %i0, %o1
F0013EB4: b6024008                 add     %o1, %o0, %i3
F0013EB8: 80a2401b                 cmp     %o1, %i3
F0013EBC: 3a80000b                 bcc,a   loc_F0013EE8
F0013EC0: 133c042d                 sethi   -0xFEF4C00, %o1
F0013EC4: d00a4000                 ldub    [%o1], %o0
F0013EC8: d40e8000                 ldub    [%i2], %o2
F0013ECC: d02e8000                 stb     %o0, [%i2]
F0013ED0: d42a4000                 stb     %o2, [%o1]
F0013ED4: 92026001                 inc     %o1
F0013ED8: 80a2401b                 cmp     %o1, %i3
F0013EDC: 0abffffa                 bcs     loc_F0013EC4
F0013EE0: b406a001                 inc     %i2
F0013EE4: 133c042d                 sethi   -0xFEF4C00, %o1
F0013EE8: d0026080                 ld      [%o1+0x80], %o0
F0013EEC: b6060008                 add     %i0, %o0, %i3
F0013EF0: 80a6c011                 cmp     %i3, %l1
F0013EF4: 1a80002a                 bcc     locret_F0013F9C
F0013EF8: b010001b                 mov     %i3, %i0
F0013EFC: 253c042d                 sethi   -0xFEF4C00, %l2
F0013F00: a0100009                 mov     %o1, %l0
F0013F04: d0042080                 ld      [%l0+0x80], %o0
F0013F08: 92100018                 mov     %i0, %o1
F0013F0C: d404a07c                 ld      [%l2+0x7C], %o2
F0013F10: b626c008                 sub     %i3, %o0, %i3
F0013F14: 9fc28000                 call    %o2
F0013F18: 9010001b                 mov     %i3, %o0
F0013F1C: 80a22000                 cmp     %o0, 0
F0013F20: 14bffffa                 bg      loc_F0013F08
F0013F24: d0042080                 ld      [%l0+0x80], %o0
F0013F28: d2042080                 ld      [%l0+0x80], %o1
F0013F2C: b606c009                 add     %i3, %o1, %i3
F0013F30: 80a6c018                 cmp     %i3, %i0
F0013F34: 22800017                 be,a    loc_F0013F90
F0013F38: b6060008                 add     %i0, %o0, %i3
F0013F3C: 10800010                 ba      loc_F0013F7C
F0013F40: b2060009                 add     %i0, %o1, %i1
F0013F44: 92100019                 mov     %i1, %o1
F0013F48: b4264008                 sub     %i1, %o0, %i2
F0013F4C: 80a6801b                 cmp     %i2, %i3
F0013F50: 0a80000a                 bcs     loc_F0013F78
F0013F54: d40e4000                 ldub    [%i1], %o2
F0013F58: d00e8000                 ldub    [%i2], %o0
F0013F5C: d02a4000                 stb     %o0, [%o1]
F0013F60: d0042080                 ld      [%l0+0x80], %o0
F0013F64: 9210001a                 mov     %i2, %o1
F0013F68: b4224008                 sub     %o1, %o0, %i2
F0013F6C: 80a6801b                 cmp     %i2, %i3
F0013F70: 3abffffb                 bcc,a   loc_F0013F5C
F0013F74: d00e8000                 ldub    [%i2], %o0
F0013F78: d42a4000                 stb     %o2, [%o1]
F0013F7C: b2067fff                 inc     -1, %i1
F0013F80: 80a64018                 cmp     %i1, %i0
F0013F84: 1abffff0                 bcc     loc_F0013F44
F0013F88: d0042080                 ld      [%l0+0x80], %o0
F0013F8C: b6060008                 add     %i0, %o0, %i3
F0013F90: 80a6c011                 cmp     %i3, %l1
F0013F94: 0abfffdc                 bcs     loc_F0013F04
F0013F98: b010001b                 mov     %i3, %i0
F0013F9C: 81c7e008                 ret
F0013FA0: 81e80000                 restore
