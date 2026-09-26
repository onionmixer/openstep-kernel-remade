F0076BDC: 9de3bf98                 save    %sp, -0x68, %sp
F0076BE0: 113c0442                 sethi   %hi(dword_F0110BB0), %o0
F0076BE4: d00223b0                 ld      [%o0+%lo(dword_F0110BB0)], %o0
F0076BE8: 80a22000                 cmp     %o0, 0
F0076BEC: 02800058                 be      locret_F0076D4C
F0076BF0: 01000000                 nop
F0076BF4: 40007fe5                 call    _splusclock
F0076BF8: 01000000                 nop
F0076BFC: a4100008                 mov     %o0, %l2
F0076C00: 113c04c3a0122320         set     dword_F0130F20, %l0
F0076C08: d0040000                 ld      [%l0], %o0
F0076C0C: 80a22000                 cmp     %o0, 0
F0076C10: 12bffffe                 bne     loc_F0076C08
F0076C14: 01000000                 nop
F0076C18: 400080a4                 call    _simple_lock_try
F0076C1C: 90100010                 mov     %l0, %o0
F0076C20: 80a22000                 cmp     %o0, 0
F0076C24: 02bffff9                 be      loc_F0076C08
F0076C28: 233c04c3                 sethi   %hi(dword_F0130F24), %l1
F0076C2C: d0046324                 ld      [%l1+%lo(dword_F0130F24)], %o0
F0076C30: a0146324                 or      %l1, %lo(dword_F0130F24), %l0
F0076C34: 80a20010                 cmp     %o0, %l0
F0076C38: 12800006                 bne     loc_F0076C50
F0076C3C: d2046324                 ld      [%l1+%lo(dword_F0130F24)], %o1
F0076C40: 113c0442                 sethi   %hi(aInternalentrya), %o0! "internalEntryAllocate"
F0076C44: 7ffe794b                 call    _panic
F0076C48: 901223b8                 bset    %lo(aInternalentrya), %o0! "internalEntryAllocate"
F0076C4C: d2046324                 ld      [%l1+%lo(dword_F0130F24)], %o1
F0076C50: 80a24010                 cmp     %o1, %l0
F0076C54: 32800004                 bne,a   loc_F0076C64
F0076C58: d0024000                 ld      [%o1], %o0
F0076C5C: 10800005                 ba      loc_F0076C70
F0076C60: 92102000                 mov     0, %o1
F0076C64: e0222004                 st      %l0, [%o0+4]
F0076C68: d0024000                 ld      [%o1], %o0
F0076C6C: d0246324                 st      %o0, [%l1+0x324]
F0076C70: 96100009                 mov     %o1, %o3
F0076C74: f022e008                 st      %i0, [%o3+8]
F0076C78: f222e00c                 st      %i1, [%o3+0xC]
F0076C7C: c022e010                 clr     [%o3+0x10]
F0076C80: f43ae018                 std     %i2, [%o3+0x18]
F0076C84: 113c04c3                 sethi   %hi(dword_F0130F34), %o0
F0076C88: d4022334                 ld      [%o0+%lo(dword_F0130F34)], %o2
F0076C8C: 98122334                 or      %o0, %lo(dword_F0130F34), %o4
F0076C90: 80a2800c                 cmp     %o2, %o4
F0076C94: 2280001b                 be,a    loc_F0076D00
F0076C98: d402a004                 ld      [%o2+4], %o2
F0076C9C: d202a018                 ld      [%o2+0x18], %o1
F0076CA0: d002e018                 ld      [%o3+0x18], %o0
F0076CA4: 80a24008                 cmp     %o1, %o0
F0076CA8: 38800016                 bgu,a   loc_F0076D00
F0076CAC: d402a004                 ld      [%o2+4], %o2
F0076CB0: 32800009                 bne,a   loc_F0076CD4
F0076CB4: d202e018                 ld      [%o3+0x18], %o1
F0076CB8: d202a01c                 ld      [%o2+0x1C], %o1
F0076CBC: d002e01c                 ld      [%o3+0x1C], %o0
F0076CC0: 80a24008                 cmp     %o1, %o0
F0076CC4: 28800004                 bleu,a  loc_F0076CD4
F0076CC8: d202e018                 ld      [%o3+0x18], %o1
F0076CCC: 1080000d                 ba      loc_F0076D00
F0076CD0: d402a004                 ld      [%o2+4], %o2
F0076CD4: d002a018                 ld      [%o2+0x18], %o0
F0076CD8: 80a24008                 cmp     %o1, %o0
F0076CDC: 32bfffed                 bne,a   loc_F0076C90
F0076CE0: d4028000                 ld      [%o2], %o2
F0076CE4: d202e01c                 ld      [%o3+0x1C], %o1
F0076CE8: d002a01c                 ld      [%o2+0x1C], %o0
F0076CEC: 80a24008                 cmp     %o1, %o0
F0076CF0: 22800005                 be,a    loc_F0076D04
F0076CF4: d0028000                 ld      [%o2], %o0
F0076CF8: 10bfffe6                 ba      loc_F0076C90
F0076CFC: d4028000                 ld      [%o2], %o2
F0076D00: d0028000                 ld      [%o2], %o0
F0076D04: d022c000                 st      %o0, [%o3]
F0076D08: d422e004                 st      %o2, [%o3+4]
F0076D0C: d0028000                 ld      [%o2], %o0
F0076D10: d6222004                 st      %o3, [%o0+4]
F0076D14: d6228000                 st      %o3, [%o2]
F0076D18: 90102002                 mov     2, %o0
F0076D1C: d022e020                 st      %o0, [%o3+0x20]
F0076D20: 113c04c3                 sethi   %hi(dword_F0130F34), %o0
F0076D24: d0022334                 ld      [%o0+%lo(dword_F0130F34)], %o0
F0076D28: 80a2000b                 cmp     %o0, %o3
F0076D2C: 32800005                 bne,a   loc_F0076D40
F0076D30: 113c04c3                 sethi   -0xFECF400, %o0
F0076D34: 7ffffe82                 call    sub_F007673C
F0076D38: 9010000b                 mov     %o3, %o0
F0076D3C: 113c04c3                 sethi   -0xFECF400, %o0
F0076D40: c0222320                 clr     [%o0+0x320]
F0076D44: 40007ff8                 call    _splx
F0076D48: 90100012                 mov     %l2, %o0
F0076D4C: 81c7e008                 ret
F0076D50: 81e80000                 restore
