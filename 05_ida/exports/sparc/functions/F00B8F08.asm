F00B8F08: 9de3bf98                 save    %sp, -0x68, %sp
F00B8F0C: a2103fff                 mov     -1, %l1
F00B8F10: e4062014                 ld      [%i0+0x14], %l2
F00B8F14: a0102000                 mov     0, %l0
F00B8F18: ee062010                 ld      [%i0+0x10], %l7
F00B8F1C: 153c047d                 sethi   %hi(dword_F011F4E8), %o2
F00B8F20: d202a0e8                 ld      [%o2+%lo(dword_F011F4E8)], %o1
F00B8F24: 9014a001                 or      %l2, 1, %o0
F00B8F28: d0262014                 st      %o0, [%i0+0x14]
F00B8F2C: 113c02e3901223f8         set     _scsi_pollintr, %o0
F00B8F34: 80a40009                 cmp     %l0, %o1
F00B8F38: 16800024                 bge     loc_F00B8FC8
F00B8F3C: d0262010                 st      %o0, [%i0+0x10]
F00B8F40: 333fffc0                 sethi   -0x10000, %i1
F00B8F44: 2d004000                 sethi   0x1000000, %l6
F00B8F48: 2b000009                 sethi   0x2400, %l5
F00B8F4C: 290003d0                 sethi   0xF4000, %l4
F00B8F50: a610000a                 mov     %o2, %l3
F00B8F54: 40000152                 call    _pkt_transport
F00B8F58: 90100018                 mov     %i0, %o0
F00B8F5C: 80a22001                 cmp     %o0, 1
F00B8F60: 3280001b                 bne,a   loc_F00B8FCC
F00B8F64: e4262014                 st      %l2, [%i0+0x14]
F00B8F68: d0062028                 ld      [%i0+0x28], %o0
F00B8F6C: 900a0019                 and     %o0, %i1, %o0
F00B8F70: 80a20016                 cmp     %o0, %l6
F00B8F74: 32800004                 bne,a   loc_F00B8F84
F00B8F78: d00e2028                 ldub    [%i0+0x28], %o0
F00B8F7C: 1080000d                 ba      loc_F00B8FB0
F00B8F80: 90156310                 or      %l5, 0x310, %o0
F00B8F84: 80a22000                 cmp     %o0, 0
F00B8F88: 32800011                 bne,a   loc_F00B8FCC
F00B8F8C: e4262014                 st      %l2, [%i0+0x14]
F00B8F90: d006201c                 ld      [%i0+0x1C], %o0
F00B8F94: d00a0000                 ldub    [%o0], %o0
F00B8F98: 900a203e                 and     %o0, 0x3E, %o0
F00B8F9C: 80a22008                 cmp     %o0, 8
F00B8FA0: 02800004                 be      loc_F00B8FB0
F00B8FA4: 90152240                 or      %l4, 0x240, %o0
F00B8FA8: 10800008                 ba      loc_F00B8FC8
F00B8FAC: a2102000                 mov     0, %l1
F00B8FB0: 7fff7a2c                 call    _us_spin
F00B8FB4: a0042001                 inc     %l0
F00B8FB8: d004e0e8                 ld      [%l3+0xE8], %o0
F00B8FBC: 80a40008                 cmp     %l0, %o0
F00B8FC0: 06bfffe5                 bl      loc_F00B8F54
F00B8FC4: 01000000                 nop
F00B8FC8: e4262014                 st      %l2, [%i0+0x14]
F00B8FCC: ee262010                 st      %l7, [%i0+0x10]
F00B8FD0: 113c047d                 sethi   %hi(dword_F011F4E8), %o0
F00B8FD4: d00220e8                 ld      [%o0+%lo(dword_F011F4E8)], %o0
F00B8FD8: 80a40008                 cmp     %l0, %o0
F00B8FDC: 06800005                 bl      locret_F00B8FF0
F00B8FE0: b0100011                 mov     %l1, %i0
F00B8FE4: 80a46000                 cmp     %l1, 0
F00B8FE8: 22800002                 be,a    locret_F00B8FF0
F00B8FEC: b0100010                 mov     %l0, %i0
F00B8FF0: 81c7e008                 ret
F00B8FF4: 81e80000                 restore
