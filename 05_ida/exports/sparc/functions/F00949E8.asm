F00949E8: 9de3bfa0                 save    %sp, -0x60, %sp
F00949EC: a1480000                 rdhpr   %hpstate, %l0
F00949F0: e6062028                 ld      [%i0+0x28], %l3
F00949F4: 29000004                 sethi   0x1000, %l4
F00949F8: 808d0010                 btst    %l0, %l4
F00949FC: 0280001d                 be      locret_F0094A70
F0094A00: 01000000                 nop
F0094A04: e404e284                 ld      [%l3+0x284], %l2
F0094A08: c12ca080                 st      %fsr, [%l2+0x80]
F0094A0C: c13ca000                 std     %f0, [%l2]
F0094A10: c53ca008                 std     %f2, [%l2+8]
F0094A14: c93ca010                 std     %f4, [%l2+0x10]
F0094A18: cd3ca018                 std     %f6, [%l2+0x18]
F0094A1C: d13ca020                 std     %f8, [%l2+0x20]
F0094A20: d53ca028                 std     %f10, [%l2+0x28]
F0094A24: d93ca030                 std     %f12, [%l2+0x30]
F0094A28: dd3ca038                 std     %f14, [%l2+0x38]
F0094A2C: e13ca040                 std     %f16, [%l2+0x40]
F0094A30: e53ca048                 std     %f18, [%l2+0x48]
F0094A34: e93ca050                 std     %f20, [%l2+0x50]
F0094A38: ed3ca058                 std     %f22, [%l2+0x58]
F0094A3C: f13ca060                 std     %f24, [%l2+0x60]
F0094A40: f53ca068                 std     %f26, [%l2+0x68]
F0094A44: f93ca070                 std     %f28, [%l2+0x70]
F0094A48: fd3ca078                 std     %f30, [%l2+0x78]
F0094A4C: a1480000                 rdhpr   %hpstate, %l0
F0094A50: a02c0014                 bclr    %l4, %l0
F0094A54: 818c0000                 saved
F0094A58: 01000000                 nop
F0094A5C: 01000000                 nop
F0094A60: 01000000                 nop
F0094A64: e204e234                 ld      [%l3+0x234], %l1
F0094A68: a22c4014                 bclr    %l4, %l1
F0094A6C: e224e234                 st      %l1, [%l3+0x234]
F0094A70: 81c7e008                 ret
F0094A74: 81e80000                 restore
