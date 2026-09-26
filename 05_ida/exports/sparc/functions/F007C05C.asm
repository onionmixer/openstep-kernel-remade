F007C05C: 9de3bf90                 save    %sp, -0x70, %sp
F007C060: d0062004                 ld      [%i0+4], %o0
F007C064: 80a22018                 cmp     %o0, 0x18
F007C068: 12800007                 bne     loc_F007C084
F007C06C: 90103ed0                 mov     -0x130, %o0
F007C070: d0060000                 ld      [%i0], %o0
F007C074: 21200000                 sethi   0x80000000, %l0
F007C078: 808a0010                 btst    %l0, %o0
F007C07C: 02800004                 be      loc_F007C08C
F007C080: 90103ed0                 mov     -0x130, %o0
F007C084: 10800019                 ba      locret_F007C0E8
F007C088: d026601c                 st      %o0, [%i1+0x1C]
F007C08C: 7fffa49d                 call    _convert_port_to_host_priv
F007C090: d0062008                 ld      [%i0+8], %o0! host_priv
F007C094: 9206602c                 add     %i1, 0x2C, %o1 ! ','! out_processor_list
F007C098: 7fffa2d7                 call    _host_processors
F007C09C: 9407bff4                 add     %fp, var_C, %o2
F007C0A0: 80a22000                 cmp     %o0, 0
F007C0A4: 12800011                 bne     locret_F007C0E8
F007C0A8: d026601c                 st      %o0, [%i1+0x1C]
F007C0AC: 92102030                 mov     0x30, %o1 ! '0'
F007C0B0: d0064000                 ld      [%i1], %o0
F007C0B4: d2266004                 st      %o1, [%i1+4]
F007C0B8: 90120010                 bset    %l0, %o0
F007C0BC: d0264000                 st      %o0, [%i1]
F007C0C0: 113c0444                 sethi   %hi(dword_F011105C), %o0
F007C0C4: d202205c                 ld      [%o0+%lo(dword_F011105C)], %o1
F007C0C8: d2266020                 st      %o1, [%i1+0x20]
F007C0CC: 9012205c                 bset    %lo(dword_F011105C), %o0
F007C0D0: d2022004                 ld      [%o0+4], %o1
F007C0D4: d2266024                 st      %o1, [%i1+0x24]
F007C0D8: d0022008                 ld      [%o0+8], %o0
F007C0DC: d207bff4                 ld      [%fp+var_C], %o1
F007C0E0: d0266028                 st      %o0, [%i1+0x28]
F007C0E4: d2266028                 st      %o1, [%i1+0x28]
F007C0E8: 81c7e008                 ret
F007C0EC: 81e80000                 restore
