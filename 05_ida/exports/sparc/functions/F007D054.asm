F007D054: 9de3bf90                 save    %sp, -0x70, %sp
F007D058: d0062004                 ld      [%i0+4], %o0
F007D05C: 80a22018                 cmp     %o0, 0x18
F007D060: 12800007                 bne     loc_F007D07C
F007D064: 90103ed0                 mov     -0x130, %o0
F007D068: d0060000                 ld      [%i0], %o0
F007D06C: 21200000                 sethi   0x80000000, %l0
F007D070: 808a0010                 btst    %l0, %o0
F007D074: 02800004                 be      loc_F007D084
F007D078: 90103ed0                 mov     -0x130, %o0
F007D07C: 10800019                 ba      locret_F007D0E0
F007D080: d026601c                 st      %o0, [%i1+0x1C]
F007D084: 7fffa082                 call    _convert_port_to_host
F007D088: d0062008                 ld      [%i0+8], %o0! host_priv
F007D08C: 9206602c                 add     %i1, 0x2C, %o1 ! ','! processor_sets
F007D090: 7fff9f91                 call    _host_processor_sets
F007D094: 9407bff4                 add     %fp, var_C, %o2
F007D098: 80a22000                 cmp     %o0, 0
F007D09C: 12800011                 bne     locret_F007D0E0
F007D0A0: d026601c                 st      %o0, [%i1+0x1C]
F007D0A4: 92102030                 mov     0x30, %o1 ! '0'
F007D0A8: d0064000                 ld      [%i1], %o0
F007D0AC: d2266004                 st      %o1, [%i1+4]
F007D0B0: 90120010                 bset    %l0, %o0
F007D0B4: d0264000                 st      %o0, [%i1]
F007D0B8: 113c0444                 sethi   %hi(dword_F0111118), %o0
F007D0BC: d2022118                 ld      [%o0+%lo(dword_F0111118)], %o1
F007D0C0: d2266020                 st      %o1, [%i1+0x20]
F007D0C4: 90122118                 bset    %lo(dword_F0111118), %o0
F007D0C8: d2022004                 ld      [%o0+4], %o1
F007D0CC: d2266024                 st      %o1, [%i1+0x24]
F007D0D0: d0022008                 ld      [%o0+8], %o0
F007D0D4: d207bff4                 ld      [%fp+var_C], %o1
F007D0D8: d0266028                 st      %o0, [%i1+0x28]
F007D0DC: d2266028                 st      %o1, [%i1+0x28]
F007D0E0: 81c7e008                 ret
F007D0E4: 81e80000                 restore
