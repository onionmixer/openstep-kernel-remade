F007704C: 9de3bf98                 save    %sp, -0x68, %sp
F0077050: a4100019                 mov     %i1, %l2
F0077054: a610001a                 mov     %i2, %l3
F0077058: 40007ecc                 call    _splusclock
F007705C: 01000000                 nop
F0077060: b2100008                 mov     %o0, %i1
F0077064: 113c04c3a0122320         set     dword_F0130F20, %l0
F007706C: d0040000                 ld      [%l0], %o0
F0077070: 80a22000                 cmp     %o0, 0
F0077074: 12bffffe                 bne     loc_F007706C
F0077078: 01000000                 nop
F007707C: 40007f8b                 call    _simple_lock_try
F0077080: 90100010                 mov     %l0, %o0
F0077084: 80a22000                 cmp     %o0, 0
F0077088: 02bffff9                 be      loc_F007706C
F007708C: 01000000                 nop
F0077090: d0062020                 ld      [%i0+0x20], %o0
F0077094: 80a22000                 cmp     %o0, 0
F0077098: 12800034                 bne     loc_F0077168
F007709C: 113c04c3                 sethi   -0xFECF400, %o0
F00770A0: e43e2018                 std     %l2, [%i0+0x18]
F00770A4: 133c04c3                 sethi   %hi(dword_F0130F34), %o1
F00770A8: d0062010                 ld      [%i0+0x10], %o0
F00770AC: 96126334                 or      %o1, %lo(dword_F0130F34), %o3
F00770B0: d026200c                 st      %o0, [%i0+0xC]
F00770B4: d4026334                 ld      [%o1+%lo(dword_F0130F34)], %o2
F00770B8: 80a2800b                 cmp     %o2, %o3
F00770BC: 2280001b                 be,a    loc_F0077128
F00770C0: d402a004                 ld      [%o2+4], %o2
F00770C4: d202a018                 ld      [%o2+0x18], %o1
F00770C8: d0062018                 ld      [%i0+0x18], %o0
F00770CC: 80a24008                 cmp     %o1, %o0
F00770D0: 38800016                 bgu,a   loc_F0077128
F00770D4: d402a004                 ld      [%o2+4], %o2
F00770D8: 32800009                 bne,a   loc_F00770FC
F00770DC: d2062018                 ld      [%i0+0x18], %o1
F00770E0: d202a01c                 ld      [%o2+0x1C], %o1
F00770E4: d006201c                 ld      [%i0+0x1C], %o0
F00770E8: 80a24008                 cmp     %o1, %o0
F00770EC: 28800004                 bleu,a  loc_F00770FC
F00770F0: d2062018                 ld      [%i0+0x18], %o1
F00770F4: 1080000d                 ba      loc_F0077128
F00770F8: d402a004                 ld      [%o2+4], %o2
F00770FC: d002a018                 ld      [%o2+0x18], %o0
F0077100: 80a24008                 cmp     %o1, %o0
F0077104: 32bfffed                 bne,a   loc_F00770B8
F0077108: d4028000                 ld      [%o2], %o2
F007710C: d206201c                 ld      [%i0+0x1C], %o1
F0077110: d002a01c                 ld      [%o2+0x1C], %o0
F0077114: 80a24008                 cmp     %o1, %o0
F0077118: 22800005                 be,a    loc_F007712C
F007711C: d0028000                 ld      [%o2], %o0
F0077120: 10bfffe6                 ba      loc_F00770B8
F0077124: d4028000                 ld      [%o2], %o2
F0077128: d0028000                 ld      [%o2], %o0
F007712C: d0260000                 st      %o0, [%i0]
F0077130: d4262004                 st      %o2, [%i0+4]
F0077134: d0028000                 ld      [%o2], %o0
F0077138: f0222004                 st      %i0, [%o0+4]
F007713C: f0228000                 st      %i0, [%o2]
F0077140: 90102002                 mov     2, %o0
F0077144: d0262020                 st      %o0, [%i0+0x20]
F0077148: 113c04c3                 sethi   %hi(dword_F0130F34), %o0
F007714C: d0022334                 ld      [%o0+%lo(dword_F0130F34)], %o0
F0077150: 80a20018                 cmp     %o0, %i0
F0077154: 32800005                 bne,a   loc_F0077168
F0077158: 113c04c3                 sethi   -0xFECF400, %o0
F007715C: 7ffffd78                 call    sub_F007673C
F0077160: 90100018                 mov     %i0, %o0
F0077164: 113c04c3                 sethi   -0xFECF400, %o0
F0077168: c0222320                 clr     [%o0+0x320]
F007716C: 40007eee                 call    _splx
F0077170: 90100019                 mov     %i1, %o0
F0077174: 81c7e008                 ret
F0077178: 81e80000                 restore
