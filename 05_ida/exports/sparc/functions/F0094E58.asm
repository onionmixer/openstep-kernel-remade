F0094E58: 9de3bfa0                 save    %sp, -0x60, %sp
F0094E5C: b4102000                 mov     0, %i2
F0094E60: 80a6600f                 cmp     %i1, 0xF
F0094E64: 0680003f                 bl      loc_F0094F60
F0094E68: 01000000                 nop
F0094E6C: 808e2003                 btst    3, %i0
F0094E70: 02800007                 be      loc_F0094E8C
F0094E74: b6102100                 mov     0x100, %i3
F0094E78: c02e0000                 clrb    [%i0]
F0094E7C: b0062001                 inc     %i0
F0094E80: 808e2003                 btst    3, %i0
F0094E84: 12bffffd                 bne     loc_F0094E78
F0094E88: b2266001                 dec     %i1
F0094E8C: 808e2007                 btst    7, %i0
F0094E90: 02800027                 be      loc_F0094F2C
F0094E94: 82100000                 clr     %g1
F0094E98: c0260000                 clr     [%i0]
F0094E9C: b2266004                 dec     4, %i1
F0094EA0: 10800023                 ba      loc_F0094F2C
F0094EA4: b0062004                 inc     4, %i0
F0094EA8: c03e20f0                 std     %g0, [%i0+0xF0]
F0094EAC: c03e20e8                 std     %g0, [%i0+0xE8]
F0094EB0: c03e20e0                 std     %g0, [%i0+0xE0]
F0094EB4: c03e20d8                 std     %g0, [%i0+0xD8]
F0094EB8: c03e20d0                 std     %g0, [%i0+0xD0]
F0094EBC: c03e20c8                 std     %g0, [%i0+0xC8]
F0094EC0: c03e20c0                 std     %g0, [%i0+0xC0]
F0094EC4: c03e20b8                 std     %g0, [%i0+0xB8]
F0094EC8: c03e20b0                 std     %g0, [%i0+0xB0]
F0094ECC: c03e20a8                 std     %g0, [%i0+0xA8]
F0094ED0: c03e20a0                 std     %g0, [%i0+0xA0]
F0094ED4: c03e2098                 std     %g0, [%i0+0x98]
F0094ED8: c03e2090                 std     %g0, [%i0+0x90]
F0094EDC: c03e2088                 std     %g0, [%i0+0x88]
F0094EE0: c03e2080                 std     %g0, [%i0+0x80]
F0094EE4: c03e2078                 std     %g0, [%i0+0x78]
F0094EE8: c03e2070                 std     %g0, [%i0+0x70]
F0094EEC: c03e2068                 std     %g0, [%i0+0x68]
F0094EF0: c03e2060                 std     %g0, [%i0+0x60]
F0094EF4: c03e2058                 std     %g0, [%i0+0x58]
F0094EF8: c03e2050                 std     %g0, [%i0+0x50]
F0094EFC: c03e2048                 std     %g0, [%i0+0x48]
F0094F00: c03e2040                 std     %g0, [%i0+0x40]
F0094F04: c03e2038                 std     %g0, [%i0+0x38]
F0094F08: c03e2030                 std     %g0, [%i0+0x30]
F0094F0C: c03e2028                 std     %g0, [%i0+0x28]
F0094F10: c03e2020                 std     %g0, [%i0+0x20]
F0094F14: c03e2018                 std     %g0, [%i0+0x18]
F0094F18: c03e2010                 std     %g0, [%i0+0x10]
F0094F1C: c03e2008                 std     %g0, [%i0+8]
F0094F20: c03e2000                 std     %g0, [%i0]
F0094F24: b006001b                 add     %i0, %i3, %i0
F0094F28: b226401b                 sub     %i1, %i3, %i1
F0094F2C: 80a66100                 cmp     %i1, 0x100
F0094F30: 36bfffde                 bge,a   loc_F0094EA8
F0094F34: c03e20f8                 std     %g0, [%i0+0xF8]
F0094F38: 80a66007                 cmp     %i1, 7
F0094F3C: 04800009                 ble     loc_F0094F60
F0094F40: b62e6007                 andn    %i1, 7, %i3
F0094F44: b536e001                 srl     %i3, 1, %i2
F0094F48: 393c0253b8172324         set     loc_F0094F24, %i4
F0094F50: b827001a                 sub     %i4, %i2, %i4
F0094F54: 81c70000                 jmp     %i4
F0094F58: 01000000                 nop
F0094F5C: b0062001                 inc     %i0
F0094F60: b2a66001                 deccc   %i1
F0094F64: 36bffffe                 bge,a   loc_F0094F5C
F0094F68: c02e0000                 clrb    [%i0]
F0094F6C: 81c7e008                 ret
F0094F70: 91e86000                 restore %g1, 0, %o0
