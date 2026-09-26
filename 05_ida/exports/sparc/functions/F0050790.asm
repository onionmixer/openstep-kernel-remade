F0050790: 9de3bf98                 save    %sp, -0x68, %sp
F0050794: 133c043c                 sethi   %hi(dword_F010F0B0), %o1
F0050798: d00260b0                 ld      [%o1+%lo(dword_F010F0B0)], %o0
F005079C: a0100018                 mov     %i0, %l0
F00507A0: 90022001                 inc     %o0
F00507A4: 80a22001                 cmp     %o0, 1
F00507A8: 02800004                 be      loc_F00507B8
F00507AC: d02260b0                 st      %o0, [%o1+%lo(dword_F010F0B0)]
F00507B0: 1080002f                 ba      locret_F005086C
F00507B4: b0102010                 mov     0x10, %i0
F00507B8: 113c04d2                 sethi   %hi(_rootdev), %o0
F00507BC: d05221c8                 ldsh    [%o0+%lo(_rootdev)], %o0
F00507C0: 80a23fff                 cmp     %o0, -1
F00507C4: 0280002a                 be      locret_F005086C
F00507C8: b0102002                 mov     2, %i0
F00507CC: 7fffdac6                 call    _bdevvp
F00507D0: 01000000                 nop
F00507D4: d0264000                 st      %o0, [%i1]
F00507D8: 113c04ef                 sethi   %hi(_rootrw), %o0
F00507DC: d00222c0                 ld      [%o0+%lo(_rootrw)], %o0
F00507E0: 80a22000                 cmp     %o0, 0
F00507E4: 12800006                 bne     loc_F00507FC
F00507E8: 90100019                 mov     %i1, %o0
F00507EC: d004200c                 ld      [%l0+0xC], %o0
F00507F0: 90122001                 bset    1, %o0
F00507F4: d024200c                 st      %o0, [%l0+0xC]
F00507F8: 90100019                 mov     %i1, %o0
F00507FC: 133c043c921260b8         set     unk_F010F0B8, %o1
F0050804: 4000001c                 call    sub_F0050874
F0050808: 94100010                 mov     %l0, %o2
F005080C: b0920000                 orcc    %o0, %g0, %i0
F0050810: 12800014                 bne     loc_F0050860
F0050814: 90102000                 mov     0, %o0
F0050818: d404200c                 ld      [%l0+0xC], %o2
F005081C: 92100010                 mov     %l0, %o1
F0050820: 7fff4ddd                 call    _vfs_add
F0050824: 940aa001                 and     %o2, 1, %o2
F0050828: b0920000                 orcc    %o0, %g0, %i0
F005082C: 1280000b                 bne     loc_F0050858
F0050830: 90100010                 mov     %l0, %o0
F0050834: 7fff4e66                 call    _vfs_unlock
F0050838: 90100010                 mov     %l0, %o0
F005083C: d0042128                 ld      [%l0+0x128], %o0
F0050840: d002200c                 ld      [%o0+0xC], %o0
F0050844: d0022020                 ld      [%o0+0x20], %o0
F0050848: 7fff0a0a                 call    _inittodr
F005084C: d0022020                 ld      [%o0+0x20], %o0
F0050850: 10800007                 ba      locret_F005086C
F0050854: b0102000                 mov     0, %i0
F0050858: 40000188                 call    sub_F0050E78
F005085C: 92102000                 mov     0, %o1
F0050860: 7fff60c1                 call    _vn_rele
F0050864: d0064000                 ld      [%i1], %o0
F0050868: c0264000                 clr     [%i1]
F005086C: 81c7e008                 ret
F0050870: 81e80000                 restore
