F0094940: 9de3bfa0                 save    %sp, -0x60, %sp
F0094944: a1480000                 rdhpr   %hpstate, %l0
F0094948: 7ffdc154                 call    _flush_windows
F009494C: 01000000                 nop
F0094950: e6062028                 ld      [%i0+0x28], %l3
F0094954: e024e008                 st      %l0, [%l3+8]
F0094958: fe24e000                 st      %i7, [%l3]
F009495C: fc24e004                 st      %fp, [%l3+4]
F0094960: 29000004                 sethi   0x1000, %l4
F0094964: 808d0010                 btst    %l0, %l4
F0094968: 0280001d                 be      loc_F00949DC
F009496C: 01000000                 nop
F0094970: e404e284                 ld      [%l3+0x284], %l2
F0094974: c12ca080                 st      %fsr, [%l2+0x80]
F0094978: c13ca000                 std     %f0, [%l2]
F009497C: c53ca008                 std     %f2, [%l2+8]
F0094980: c93ca010                 std     %f4, [%l2+0x10]
F0094984: cd3ca018                 std     %f6, [%l2+0x18]
F0094988: d13ca020                 std     %f8, [%l2+0x20]
F009498C: d53ca028                 std     %f10, [%l2+0x28]
F0094990: d93ca030                 std     %f12, [%l2+0x30]
F0094994: dd3ca038                 std     %f14, [%l2+0x38]
F0094998: e13ca040                 std     %f16, [%l2+0x40]
F009499C: e53ca048                 std     %f18, [%l2+0x48]
F00949A0: e93ca050                 std     %f20, [%l2+0x50]
F00949A4: ed3ca058                 std     %f22, [%l2+0x58]
F00949A8: f13ca060                 std     %f24, [%l2+0x60]
F00949AC: f53ca068                 std     %f26, [%l2+0x68]
F00949B0: f93ca070                 std     %f28, [%l2+0x70]
F00949B4: fd3ca078                 std     %f30, [%l2+0x78]
F00949B8: a1480000                 rdhpr   %hpstate, %l0
F00949BC: a02c0014                 bclr    %l4, %l0
F00949C0: 818c0000                 saved
F00949C4: 01000000                 nop
F00949C8: 01000000                 nop
F00949CC: 01000000                 nop
F00949D0: e204e234                 ld      [%l3+0x234], %l1
F00949D4: a22c4014                 bclr    %l4, %l1
F00949D8: e224e234                 st      %l1, [%l3+0x234]
F00949DC: b0100000                 clr     %i0
F00949E0: 81c7e008                 ret
F00949E4: 81e80000                 restore
