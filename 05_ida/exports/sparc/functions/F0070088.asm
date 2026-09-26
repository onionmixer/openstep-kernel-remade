F0070088: 9de3bf90                 save    %sp, -0x70, %sp
F007008C: d0064000                 ld      [%i1], %o0
F0070090: 80a2200f                 cmp     %o0, 0xF
F0070094: 0880001c                 bleu    loc_F0070104
F0070098: a0100018                 mov     %i0, %l0
F007009C: 15004000                 sethi   0x1000000, %o2
F00700A0: d2040000                 ld      [%l0], %o1
F00700A4: 9607bff4                 add     %fp, var_C, %o3
F00700A8: d0042008                 ld      [%l0+8], %o0
F00700AC: 9212400a                 bset    %o2, %o1
F00700B0: d2240000                 st      %o1, [%l0]
F00700B4: 9210200c                 mov     0xC, %o1
F00700B8: d2342002                 sth     %o1, [%l0+2]
F00700BC: d204200c                 ld      [%l0+0xC], %o1
F00700C0: 40009143                 call    _kdp_machine_read_regs
F00700C4: 9404200c                 add     %l0, 0xC, %o2
F00700C8: d407bff4                 ld      [%fp+var_C], %o2
F00700CC: d0242008                 st      %o0, [%l0+8]
F00700D0: d2142002                 lduh    [%l0+2], %o1
F00700D4: 113c04f1                 sethi   %hi(_kdp), %o0
F00700D8: 9202400a                 add     %o1, %o2, %o1
F00700DC: d2342002                 sth     %o1, [%l0+2]
F00700E0: d0122000                 lduh    [%o0+%lo(_kdp)], %o0
F00700E4: b0102001                 mov     1, %i0
F00700E8: d0368000                 sth     %o0, [%i2]
F00700EC: 1100003f                 sethi   0xFC00, %o0
F00700F0: d2040000                 ld      [%l0], %o1
F00700F4: 901223ff                 bset    0x3FF, %o0
F00700F8: 920a4008                 and     %o1, %o0, %o1
F00700FC: 10800003                 ba      locret_F0070108
F0070100: d2264000                 st      %o1, [%i1]
F0070104: b0102000                 mov     0, %i0
F0070108: 81c7e008                 ret
F007010C: 81e80000                 restore
