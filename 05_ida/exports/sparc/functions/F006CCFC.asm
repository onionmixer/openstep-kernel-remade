F006CCFC: 9de3bf98                 save    %sp, -0x68, %sp
F006CD00: d4066014                 ld      [%i1+0x14], %o2
F006CD04: 80a2a000                 cmp     %o2, 0
F006CD08: 32800004                 bne,a   loc_F006CD18
F006CD0C: d2066008                 ld      [%i1+8], %o1
F006CD10: 108000cd                 ba      locret_F006D044
F006CD14: b0102000                 mov     0, %i0
F006CD18: 80a26000                 cmp     %o1, 0
F006CD1C: 06800004                 bl      loc_F006CD2C
F006CD20: 8082400a                 addcc   %o1, %o2, %g0
F006CD24: 1c800008                 bpos    loc_F006CD44
F006CD28: 01000000                 nop
F006CD2C: 108000c6                 ba      locret_F006D044
F006CD30: b0102016                 mov     0x16, %i0
F006CD34: 7ffffed0                 call    _mfs_put
F006CD38: 90100018                 mov     %i0, %o0
F006CD3C: 108000c2                 ba      locret_F006D044
F006CD40: b0102000                 mov     0, %i0
F006CD44: 7ffffeba                 call    _mfs_get
F006CD48: 90100018                 mov     %i0, %o0
F006CD4C: e0060000                 ld      [%i0], %l0
F006CD50: 80a6a001                 cmp     %i2, 1
F006CD54: 12800005                 bne     loc_F006CD68
F006CD58: ec042014                 ld      [%l0+0x14], %l6
F006CD5C: 808ee002                 btst    2, %i3
F006CD60: 32800002                 bne,a   loc_F006CD68
F006CD64: ec266008                 st      %l6, [%i1+8]
F006CD68: fa066008                 ld      [%i1+8], %i5
F006CD6C: d0062024                 ld      [%i0+0x24], %o0
F006CD70: ee066014                 ld      [%i1+0x14], %l7
F006CD74: 80a6a001                 cmp     %i2, 1
F006CD78: 02800009                 be      loc_F006CD9C
F006CD7C: e8022010                 ld      [%o0+0x10], %l4
F006CD80: 80a6a000                 cmp     %i2, 0
F006CD84: 32800011                 bne,a   loc_F006CDC8
F006CD88: c0242034                 clr     [%l0+0x34]
F006CD8C: d0042030                 ld      [%l0+0x30], %o0
F006CD90: 80a22000                 cmp     %o0, 0
F006CD94: 3280000d                 bne,a   loc_F006CDC8
F006CD98: c0242034                 clr     [%l0+0x34]
F006CD9C: d0170000                 lduh    [%i4], %o0
F006CDA0: 90022001                 inc     %o0
F006CDA4: d0370000                 sth     %o0, [%i4]
F006CDA8: d0042030                 ld      [%l0+0x30], %o0
F006CDAC: 80a22000                 cmp     %o0, 0
F006CDB0: 22800005                 be,a    loc_F006CDC4
F006CDB4: f8242030                 st      %i4, [%l0+0x30]
F006CDB8: 7ffe8b18                 call    _crfree
F006CDBC: 01000000                 nop
F006CDC0: f8242030                 st      %i4, [%l0+0x30]
F006CDC4: c0242034                 clr     [%l0+0x34]
F006CDC8: ea066008                 ld      [%i1+8], %l5
F006CDCC: a6102000                 mov     0, %l3
F006CDD0: d0066014                 ld      [%i1+0x14], %o0
F006CDD4: 80a50008                 cmp     %l4, %o0
F006CDD8: 0a800003                 bcs     loc_F006CDE4
F006CDDC: a2100014                 mov     %l4, %l1
F006CDE0: a2100008                 mov     %o0, %l1
F006CDE4: 80a6a000                 cmp     %i2, 0
F006CDE8: 1280000a                 bne     loc_F006CE10
F006CDEC: 80a6a001                 cmp     %i2, 1
F006CDF0: d0066008                 ld      [%i1+8], %o0
F006CDF4: 90258008                 sub     %l6, %o0, %o0
F006CDF8: 80a22000                 cmp     %o0, 0
F006CDFC: 04bfffce                 ble     loc_F006CD34
F006CE00: 80a20011                 cmp     %o0, %l1
F006CE04: 26800002                 bl,a    loc_F006CE0C
F006CE08: a2100008                 mov     %o0, %l1
F006CE0C: 80a6a001                 cmp     %i2, 1
F006CE10: 32800009                 bne,a   loc_F006CE34
F006CE14: d4066008                 ld      [%i1+8], %o2
F006CE18: d0066008                 ld      [%i1+8], %o0
F006CE1C: d2042014                 ld      [%l0+0x14], %o1
F006CE20: 90020011                 add     %o0, %l1, %o0
F006CE24: 80a20009                 cmp     %o0, %o1
F006CE28: 38800002                 bgu,a   loc_F006CE30
F006CE2C: d0242014                 st      %o0, [%l0+0x14]
F006CE30: d4066008                 ld      [%i1+8], %o2
F006CE34: d6042010                 ld      [%l0+0x10], %o3
F006CE38: 80a2800b                 cmp     %o2, %o3
F006CE3C: 0a800007                 bcs     loc_F006CE58
F006CE40: 92028011                 add     %o2, %l1, %o1
F006CE44: d004200c                 ld      [%l0+0xC], %o0
F006CE48: 9002c008                 add     %o3, %o0, %o0
F006CE4C: 80a24008                 cmp     %o1, %o0
F006CE50: 28800007                 bleu,a  loc_F006CE6C
F006CE54: d0042008                 ld      [%l0+8], %o0
F006CE58: 90100018                 mov     %i0, %o0
F006CE5C: 9210000a                 mov     %o2, %o1
F006CE60: 7ffffdbc                 call    _remap_vnode
F006CE64: 94100011                 mov     %l1, %o2
F006CE68: d0042008                 ld      [%l0+8], %o0
F006CE6C: 92100011                 mov     %l1, %o1
F006CE70: d8066008                 ld      [%i1+8], %o4
F006CE74: 9410001a                 mov     %i2, %o2
F006CE78: d6042010                 ld      [%l0+0x10], %o3
F006CE7C: 9002000c                 add     %o0, %o4, %o0
F006CE80: 9022000b                 sub     %o0, %o3, %o0
F006CE84: 7ffe9525                 call    _uiomove
F006CE88: 96100019                 mov     %i1, %o3
F006CE8C: 80a6a001                 cmp     %i2, 1
F006CE90: 12800006                 bne     loc_F006CEA8
F006CE94: a4100008                 mov     %o0, %l2
F006CE98: d0042038                 ld      [%l0+0x38], %o0
F006CE9C: 13100000                 sethi   0x40000000, %o1
F006CEA0: 90120009                 bset    %o1, %o0
F006CEA4: d0242038                 st      %o0, [%l0+0x38]
F006CEA8: d0042034                 ld      [%l0+0x34], %o0
F006CEAC: 80a22000                 cmp     %o0, 0
F006CEB0: 02800008                 be      loc_F006CED0
F006CEB4: 80a6a001                 cmp     %i2, 1
F006CEB8: a4100008                 mov     %o0, %l2
F006CEBC: d0042030                 ld      [%l0+0x30], %o0
F006CEC0: 7ffe8ad6                 call    _crfree
F006CEC4: c0242034                 clr     [%l0+0x34]
F006CEC8: c0242030                 clr     [%l0+0x30]
F006CECC: 80a6a001                 cmp     %i2, 1
F006CED0: 12800029                 bne     loc_F006CF74
F006CED4: 80a4a000                 cmp     %l2, 0
F006CED8: d0062024                 ld      [%i0+0x24], %o0
F006CEDC: d002200c                 ld      [%o0+0xC], %o0
F006CEE0: 808a2100                 btst    0x100, %o0
F006CEE4: 02800023                 be      loc_F006CF70
F006CEE8: 113c0470                 sethi   %hi(_nmfsbuf), %o0
F006CEEC: d002205c                 ld      [%o0+%lo(_nmfsbuf)], %o0
F006CEF0: a604e001                 inc     %l3
F006CEF4: 80a4c008                 cmp     %l3, %o0
F006CEF8: 0680001e                 bl      loc_F006CF70
F006CEFC: 80a4a000                 cmp     %l2, 0
F006CF00: 3280001d                 bne,a   loc_F006CF74
F006CF04: a6102000                 mov     0, %l3
F006CF08: 400001be                 call    _vmp_push
F006CF0C: 90100010                 mov     %l0, %o0
F006CF10: 80a48013                 cmp     %l2, %l3
F006CF14: 16800011                 bge     loc_F006CF58
F006CF18: b8102000                 mov     0, %i4
F006CF1C: d206201c                 ld      [%i0+0x1C], %o1
F006CF20: 90100018                 mov     %i0, %o0
F006CF24: d2026080                 ld      [%o1+0x80], %o1
F006CF28: 9fc24000                 call    %o1
F006CF2C: b8072001                 inc     %i4
F006CF30: 92100008                 mov     %o0, %o1
F006CF34: 7ffe65b3                 call    _udiv
F006CF38: 90100015                 mov     %l5, %o0
F006CF3C: 92100008                 mov     %o0, %o1
F006CF40: 90100018                 mov     %i0, %o0
F006CF44: 7ffee081                 call    _blkflush
F006CF48: 94100014                 mov     %l4, %o2
F006CF4C: 80a70013                 cmp     %i4, %l3
F006CF50: 06bffff3                 bl      loc_F006CF1C
F006CF54: aa054014                 add     %l5, %l4, %l5
F006CF58: d0042034                 ld      [%l0+0x34], %o0
F006CF5C: 80a22000                 cmp     %o0, 0
F006CF60: 02800004                 be      loc_F006CF70
F006CF64: a6102000                 mov     0, %l3
F006CF68: a4100008                 mov     %o0, %l2
F006CF6C: c0242034                 clr     [%l0+0x34]
F006CF70: 80a4a000                 cmp     %l2, 0
F006CF74: 12800009                 bne     loc_F006CF98
F006CF78: 80a4a000                 cmp     %l2, 0
F006CF7C: d0066014                 ld      [%i1+0x14], %o0
F006CF80: 80a22000                 cmp     %o0, 0
F006CF84: 04800004                 ble     loc_F006CF94
F006CF88: 80a46000                 cmp     %l1, 0
F006CF8C: 12bfff93                 bne     loc_F006CDD8
F006CF90: 80a50008                 cmp     %l4, %o0
F006CF94: 80a4a000                 cmp     %l2, 0
F006CF98: 12800028                 bne     loc_F006D038
F006CF9C: 80a6a001                 cmp     %i2, 1
F006CFA0: 12800026                 bne     loc_F006D038
F006CFA4: 808ee004                 btst    4, %i3
F006CFA8: 12800007                 bne     loc_F006CFC4
F006CFAC: 01000000                 nop
F006CFB0: d0062024                 ld      [%i0+0x24], %o0
F006CFB4: d002200c                 ld      [%o0+0xC], %o0
F006CFB8: 808a2100                 btst    0x100, %o0
F006CFBC: 0280001f                 be      loc_F006D038
F006CFC0: 01000000                 nop
F006CFC4: 4000018f                 call    _vmp_push
F006CFC8: 90100010                 mov     %l0, %o0
F006CFCC: b210001d                 mov     %i5, %i1
F006CFD0: 90064017                 add     %i1, %l7, %o0
F006CFD4: 80a64008                 cmp     %i1, %o0
F006CFD8: 3a800013                 bcc,a   loc_F006D024
F006CFDC: d0042034                 ld      [%l0+0x34], %o0
F006CFE0: a2100008                 mov     %o0, %l1
F006CFE4: d006201c                 ld      [%i0+0x1C], %o0
F006CFE8: d2022080                 ld      [%o0+0x80], %o1
F006CFEC: 9fc24000                 call    %o1
F006CFF0: 90100018                 mov     %i0, %o0
F006CFF4: 92100008                 mov     %o0, %o1
F006CFF8: 7ffe6582                 call    _udiv
F006CFFC: 90100019                 mov     %i1, %o0
F006D000: 92100008                 mov     %o0, %o1
F006D004: 90100018                 mov     %i0, %o0
F006D008: 7ffee050                 call    _blkflush
F006D00C: 94100014                 mov     %l4, %o2
F006D010: b2064014                 add     %i1, %l4, %i1
F006D014: 80a64011                 cmp     %i1, %l1
F006D018: 2abffff4                 bcs,a   loc_F006CFE8
F006D01C: d006201c                 ld      [%i0+0x1C], %o0
F006D020: d0042034                 ld      [%l0+0x34], %o0
F006D024: 80a22000                 cmp     %o0, 0
F006D028: 02800004                 be      loc_F006D038
F006D02C: 01000000                 nop
F006D030: a4100008                 mov     %o0, %l2
F006D034: c0242034                 clr     [%l0+0x34]
F006D038: 7ffffe0f                 call    _mfs_put
F006D03C: 90100018                 mov     %i0, %o0
F006D040: b0100012                 mov     %l2, %i0
F006D044: 81c7e008                 ret
F006D048: 81e80000                 restore
