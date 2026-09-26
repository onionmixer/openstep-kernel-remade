F0005F5C: 80a2a007                 cmp     %o2, 7
F0005F60: 24800022                 ble,a   loc_F0005FE8
F0005F64: 92224008                 sub     %o1, %o0, %o1
F0005F68: 968a2003                 andcc   %o0, 3, %o3
F0005F6C: 2280002d                 be,a    loc_F0006020
F0005F70: 988a6003                 andcc   %o1, 3, %o4
F0005F74: 80a2e002                 cmp     %o3, 2
F0005F78: 0280000c                 be      loc_F0005FA8
F0005F7C: 80a2e003                 cmp     %o3, 3
F0005F80: d80a0000                 ldub    [%o0], %o4
F0005F84: 90022001                 inc     %o0
F0005F88: da0a4000                 ldub    [%o1], %o5
F0005F8C: 92026001                 inc     %o1
F0005F90: 9422a001                 dec     %o2
F0005F94: 02800012                 be      loc_F0005FDC
F0005F98: 80a3000d                 cmp     %o4, %o5
F0005F9C: 02800003                 be      loc_F0005FA8
F0005FA0: 01000000                 nop
F0005FA4: 3080001d                 ba,a    locret_F0006018
F0005FA8: d8120000                 lduh    [%o0], %o4
F0005FAC: 90022002                 inc     2, %o0
F0005FB0: da0a4000                 ldub    [%o1], %o5
F0005FB4: 92026001                 inc     %o1
F0005FB8: 97332008                 srl     %o4, 8, %o3
F0005FBC: 80a2c00d                 cmp     %o3, %o5
F0005FC0: 22800003                 be,a    loc_F0005FCC
F0005FC4: da0a4000                 ldub    [%o1], %o5
F0005FC8: 30800014                 ba,a    locret_F0006018
F0005FCC: 92026001                 inc     %o1
F0005FD0: 9422a002                 dec     2, %o2
F0005FD4: 980b20ff                 and     %o4, 0xFF, %o4
F0005FD8: 80a3000d                 cmp     %o4, %o5
F0005FDC: 02800011                 be      loc_F0006020
F0005FE0: 988a6003                 andcc   %o1, 3, %o4
F0005FE4: 3080000d                 ba,a    locret_F0006018
F0005FE8: 10800008                 ba      loc_F0006008
F0005FEC: 94a2a001                 deccc   %o2
F0005FF0: da0a0009                 ldub    [%o0+%o1], %o5
F0005FF4: 90022001                 inc     %o0
F0005FF8: 80a3000d                 cmp     %o4, %o5
F0005FFC: 22800003                 be,a    loc_F0006008
F0006000: 94a2a001                 deccc   %o2
F0006004: 30800005                 ba,a    locret_F0006018
F0006008: 36bffffa                 bge,a   loc_F0005FF0
F000600C: d80a0000                 ldub    [%o0], %o4
F0006010: 81c3e008                 retl
F0006014: 90100000                 clr     %o0
F0006018: 81c3e008                 retl
F000601C: 90102001                 mov     1, %o0
F0006020: 962aa003                 andn    %o2, 3, %o3
F0006024: 940aa003                 and     %o2, 3, %o2
F0006028: 02800039                 be      loc_F000610C
F000602C: 80a32002                 cmp     %o4, 2
F0006030: 02800026                 be      loc_F00060C8
F0006034: 80a32001                 cmp     %o4, 1
F0006038: c20a4000                 ldub    [%o1], %g1
F000603C: 92026001                 inc     %o1
F0006040: 02800010                 be      loc_F0006080
F0006044: 9b286018                 sll     %g1, 24, %o5
F0006048: 92224008                 sub     %o1, %o0, %o1
F000604C: c2020009                 ld      [%o0+%o1], %g1
F0006050: d8020000                 ld      [%o0], %o4
F0006054: 90022004                 inc     4, %o0
F0006058: 85306008                 srl     %g1, 8, %g2
F000605C: 9a10800d                 bset    %g2, %o5
F0006060: 80a3000d                 cmp     %o4, %o5
F0006064: 12bfffed                 bne     locret_F0006018
F0006068: 96a2e004                 deccc   4, %o3
F000606C: 12bffff8                 bne     loc_F000604C
F0006070: 9b286018                 sll     %g1, 24, %o5
F0006074: 92226001                 dec     %o1
F0006078: 10bfffe4                 ba      loc_F0006008
F000607C: 94a2a001                 deccc   %o2
F0006080: c2124000                 lduh    [%o1], %g1
F0006084: 92026002                 inc     2, %o1
F0006088: 85286008                 sll     %g1, 8, %g2
F000608C: 9a134002                 bset    %g2, %o5
F0006090: 92224008                 sub     %o1, %o0, %o1
F0006094: c2020009                 ld      [%o0+%o1], %g1
F0006098: d8020000                 ld      [%o0], %o4
F000609C: 90022004                 inc     4, %o0
F00060A0: 85306018                 srl     %g1, 24, %g2
F00060A4: 9a10800d                 bset    %g2, %o5
F00060A8: 80a3000d                 cmp     %o4, %o5
F00060AC: 12bfffdb                 bne     locret_F0006018
F00060B0: 96a2e004                 deccc   4, %o3
F00060B4: 12bffff8                 bne     loc_F0006094
F00060B8: 9b286008                 sll     %g1, 8, %o5
F00060BC: 92226003                 dec     3, %o1
F00060C0: 10bfffd2                 ba      loc_F0006008
F00060C4: 94a2a001                 deccc   %o2
F00060C8: c2124000                 lduh    [%o1], %g1
F00060CC: 92026002                 inc     2, %o1
F00060D0: 9b286010                 sll     %g1, 16, %o5
F00060D4: 92224008                 sub     %o1, %o0, %o1
F00060D8: c2020009                 ld      [%o0+%o1], %g1
F00060DC: d8020000                 ld      [%o0], %o4
F00060E0: 90022004                 inc     4, %o0
F00060E4: 85306010                 srl     %g1, 16, %g2
F00060E8: 9a10800d                 bset    %g2, %o5
F00060EC: 80a3000d                 cmp     %o4, %o5
F00060F0: 12bfffca                 bne     locret_F0006018
F00060F4: 96a2e004                 deccc   4, %o3
F00060F8: 12bffff8                 bne     loc_F00060D8
F00060FC: 9b286010                 sll     %g1, 16, %o5
F0006100: 92226002                 dec     2, %o1
F0006104: 10bfffc1                 ba      loc_F0006008
F0006108: 94a2a001                 deccc   %o2
F000610C: 92224008                 sub     %o1, %o0, %o1
F0006110: da020009                 ld      [%o0+%o1], %o5
F0006114: d8020000                 ld      [%o0], %o4
F0006118: 90022004                 inc     4, %o0
F000611C: 80a3000d                 cmp     %o4, %o5
F0006120: 12bfffbe                 bne     locret_F0006018
F0006124: 96a2e004                 deccc   4, %o3
F0006128: 32bffffb                 bne,a   loc_F0006114
F000612C: da020009                 ld      [%o0+%o1], %o5
F0006130: 10bfffb6                 ba      loc_F0006008
F0006134: 94a2a001                 deccc   %o2
