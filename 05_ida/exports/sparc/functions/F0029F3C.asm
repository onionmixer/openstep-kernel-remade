F0029F3C: 9de3bf78                 save    %sp, -0x88, %sp! int
F0029F40: 113c04d0                 sethi   %hi(_ifnet), %o0
F0029F44: e60220b8                 ld      [%o0+%lo(_ifnet)], %l3
F0029F48: b0102000                 mov     0, %i0
F0029F4C: e2064000                 ld      [%i1], %l1
F0029F50: aa07bfe6                 add     %fp, var_1A, %l5
F0029F54: 80a46020                 cmp     %l1, 0x20 ! ' '
F0029F58: 0880004b                 bleu    loc_F002A084
F0029F5C: e4066004                 ld      [%i1+4], %l2
F0029F60: a807bfd8                 add     %fp, var_28, %l4
F0029F64: 80a4e000                 cmp     %l3, 0
F0029F68: 02800047                 be      loc_F002A084
F0029F6C: 92100014                 mov     %l4, %o1! void *
F0029F70: d004c000                 ld      [%l3], %o0! void *
F0029F74: 4001aae7                 call    _bcopy
F0029F78: 9410200e                 mov     0xE, %o2! int
F0029F7C: 80a50015                 cmp     %l4, %l5
F0029F80: 1a80000a                 bcc     loc_F0029FA8
F0029F84: 92100014                 mov     %l4, %o1! size_t
F0029F88: d04a4000                 ldsb    [%o1], %o0
F0029F8C: 80a22000                 cmp     %o0, 0
F0029F90: 22800007                 be,a    loc_F0029FAC
F0029F94: d00ce009                 ldub    [%l3+9], %o0
F0029F98: 92026001                 inc     %o1
F0029F9C: 80a24015                 cmp     %o1, %l5
F0029FA0: 2abffffb                 bcs,a   loc_F0029F8C
F0029FA4: d04a4000                 ldsb    [%o1], %o0
F0029FA8: d00ce009                 ldub    [%l3+9], %o0
F0029FAC: 90022030                 inc     0x30, %o0 ! '0'
F0029FB0: d02a4000                 stb     %o0, [%o1]
F0029FB4: c02a6001                 clrb    [%o1+1]
F0029FB8: e004e018                 ld      [%l3+0x18], %l0
F0029FBC: 80a42000                 cmp     %l0, 0
F0029FC0: 1280002c                 bne     loc_F002A070
F0029FC4: 80a46020                 cmp     %l1, 0x20 ! ' '
F0029FC8: 9007bfe8                 add     %fp, var_18, %o0! void *
F0029FCC: 4001aba3                 call    _bzero
F0029FD0: 92102010                 mov     0x10, %o1
F0029FD4: 90100014                 mov     %l4, %o0! int
F0029FD8: 92100012                 mov     %l2, %o1! int
F0029FDC: 4001b83c                 call    _copyout
F0029FE0: 94102020                 mov     0x20, %o2 ! ' '
F0029FE4: b0920000                 orcc    %o0, %g0, %i0
F0029FE8: 32800028                 bne,a   loc_F002A088
F0029FEC: d0064000                 ld      [%i1], %o0
F0029FF0: a2047fe0                 inc     -0x20, %l1
F0029FF4: 10800021                 ba      loc_F002A078
F0029FF8: a404a020                 inc     0x20, %l2 ! ' '
F0029FFC: 02800020                 be      loc_F002A07C
F002A000: 80a46020                 cmp     %l1, 0x20 ! ' '
F002A004: d0140000                 lduh    [%l0], %o0
F002A008: d037bfe8                 sth     %o0, [%fp+var_18]
F002A00C: d0142002                 lduh    [%l0+2], %o0
F002A010: d037bfea                 sth     %o0, [%fp+var_16]
F002A014: d0142004                 lduh    [%l0+4], %o0
F002A018: d037bfec                 sth     %o0, [%fp+var_14]
F002A01C: d0142006                 lduh    [%l0+6], %o0
F002A020: d037bfee                 sth     %o0, [%fp+var_12]
F002A024: d0142008                 lduh    [%l0+8], %o0
F002A028: d037bff0                 sth     %o0, [%fp+var_10]
F002A02C: d214200a                 lduh    [%l0+0xA], %o1
F002A030: 9007bfd8                 add     %fp, var_28, %o0! int
F002A034: d237bff2                 sth     %o1, [%fp+var_E]
F002A038: d414200c                 lduh    [%l0+0xC], %o2
F002A03C: 92100012                 mov     %l2, %o1! int
F002A040: d437bff4                 sth     %o2, [%fp+var_C]
F002A044: d614200e                 lduh    [%l0+0xE], %o3! int
F002A048: 94102020                 mov     0x20, %o2 ! ' '! int
F002A04C: 4001b820                 call    _copyout
F002A050: d637bff6                 sth     %o3, [%fp+var_A]
F002A054: b0920000                 orcc    %o0, %g0, %i0
F002A058: 12800009                 bne     loc_F002A07C
F002A05C: 80a46020                 cmp     %l1, 0x20 ! ' '
F002A060: a2047fe0                 inc     -0x20, %l1
F002A064: a404a020                 inc     0x20, %l2 ! ' '
F002A068: e0042024                 ld      [%l0+0x24], %l0
F002A06C: 80a46020                 cmp     %l1, 0x20 ! ' '
F002A070: 18bfffe3                 bgu     loc_F0029FFC
F002A074: 80a42000                 cmp     %l0, 0
F002A078: 80a46020                 cmp     %l1, 0x20 ! ' '
F002A07C: 18bfffba                 bgu     loc_F0029F64
F002A080: e604e05c                 ld      [%l3+0x5C], %l3
F002A084: d0064000                 ld      [%i1], %o0
F002A088: 90220011                 sub     %o0, %l1, %o0
F002A08C: d0264000                 st      %o0, [%i1]
F002A090: 81c7e008                 ret
F002A094: 81e80000                 restore
