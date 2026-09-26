F0033F98: 9de3bf98                 save    %sp, -0x68, %sp
F0033F9C: d0060000                 ld      [%i0], %o0
F0033FA0: 80a22000                 cmp     %o0, 0
F0033FA4: 02800005                 be      loc_F0033FB8
F0033FA8: 80a66000                 cmp     %i1, 0
F0033FAC: 7fffa6c2                 call    _m_free
F0033FB0: 01000000                 nop
F0033FB4: 80a66000                 cmp     %i1, 0
F0033FB8: 02800006                 be      loc_F0033FD0
F0033FBC: c0260000                 clr     [%i0]
F0033FC0: d4566008                 ldsh    [%i1+8], %o2
F0033FC4: 80a2a000                 cmp     %o2, 0
F0033FC8: 12800009                 bne     loc_F0033FEC
F0033FCC: 9210000a                 mov     %o2, %o1
F0033FD0: 80a66000                 cmp     %i1, 0
F0033FD4: 0280004c                 be      locret_F0034104
F0033FD8: b0102000                 mov     0, %i0
F0033FDC: 7fffa6b6                 call    _m_free
F0033FE0: 90100019                 mov     %i1, %o0
F0033FE4: 10800048                 ba      locret_F0034104
F0033FE8: b0102000                 mov     0, %i0
F0033FEC: 808aa003                 btst    3, %o2
F0033FF0: 12800042                 bne     loc_F00340F8
F0033FF4: 01000000                 nop
F0033FF8: d0066004                 ld      [%i1+4], %o0
F0033FFC: 9002000a                 add     %o0, %o2, %o0
F0034000: 90022004                 inc     4, %o0
F0034004: 80a2207c                 cmp     %o0, 0x7C ! '|'
F0034008: 1880003c                 bgu     loc_F00340F8
F003400C: a610000a                 mov     %o2, %l3
F0034010: 90026004                 add     %o1, 4, %o0
F0034014: d0366008                 sth     %o0, [%i1+8]
F0034018: d0066004                 ld      [%i1+4], %o0
F003401C: 90064008                 add     %i1, %o0, %o0
F0034020: a4022004                 add     %o0, 4, %l2
F0034024: 40018373                 call    _ovbcopy
F0034028: 92100012                 mov     %l2, %o1
F003402C: d0066004                 ld      [%i1+4], %o0! void *
F0034030: 92102004                 mov     4, %o1! size_t
F0034034: 40018389                 call    _bzero
F0034038: 90064008                 add     %i1, %o0, %o0
F003403C: 80a4e000                 cmp     %l3, 0
F0034040: 2480002c                 ble,a   loc_F00340F0
F0034044: f2260000                 st      %i1, [%i0]
F0034048: d20c8000                 ldub    [%l2], %o1
F003404C: 900a60ff                 and     %o1, 0xFF, %o0
F0034050: 80a22000                 cmp     %o0, 0
F0034054: 02800026                 be      loc_F00340EC
F0034058: 80a22001                 cmp     %o0, 1
F003405C: 32800004                 bne,a   loc_F003406C
F0034060: e20ca001                 ldub    [%l2+1], %l1
F0034064: 10800007                 ba      loc_F0034080
F0034068: a2102001                 mov     1, %l1
F003406C: 80a46001                 cmp     %l1, 1
F0034070: 04800022                 ble     loc_F00340F8
F0034074: 80a44013                 cmp     %l1, %l3
F0034078: 14800020                 bg      loc_F00340F8
F003407C: 900a60ff                 and     %o1, 0xFF, %o0
F0034080: 80a22083                 cmp     %o0, 0x83
F0034084: 02800004                 be      loc_F0034094
F0034088: 80a22089                 cmp     %o0, 0x89
F003408C: 32800015                 bne,a   loc_F00340E0
F0034090: a624c011                 sub     %l3, %l1, %l3
F0034094: 80a46006                 cmp     %l1, 6
F0034098: 08800018                 bleu    loc_F00340F8
F003409C: a604fffc                 inc     -4, %l3
F00340A0: a2047ffc                 inc     -4, %l1
F00340A4: a004a003                 add     %l2, 3, %l0
F00340A8: d2166008                 lduh    [%i1+8], %o1
F00340AC: 90100010                 mov     %l0, %o0! void *
F00340B0: 92027ffc                 inc     -4, %o1
F00340B4: d2366008                 sth     %o1, [%i1+8]
F00340B8: e22ca001                 stb     %l1, [%l2+1]
F00340BC: d2066004                 ld      [%i1+4], %o1! void *
F00340C0: 94102004                 mov     4, %o2! size_t
F00340C4: 40018293                 call    _bcopy
F00340C8: 92064009                 add     %i1, %o1, %o1
F00340CC: 9004a007                 add     %l2, 7, %o0
F00340D0: 92100010                 mov     %l0, %o1
F00340D4: 40018347                 call    _ovbcopy
F00340D8: 9404e004                 add     %l3, 4, %o2
F00340DC: a624c011                 sub     %l3, %l1, %l3
F00340E0: 80a4e000                 cmp     %l3, 0
F00340E4: 14bfffd9                 bg      loc_F0034048
F00340E8: a4048011                 add     %l2, %l1, %l2
F00340EC: f2260000                 st      %i1, [%i0]
F00340F0: 10800005                 ba      locret_F0034104
F00340F4: b0102000                 mov     0, %i0
F00340F8: 7fffa66f                 call    _m_free
F00340FC: 90100019                 mov     %i1, %o0
F0034100: b0102016                 mov     0x16, %i0
F0034104: 81c7e008                 ret
F0034108: 81e80000                 restore
