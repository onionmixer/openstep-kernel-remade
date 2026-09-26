F00911A8: 9de3bf98                 save    %sp, -0x68, %sp
F00911AC: d0062004                 ld      [%i0+4], %o0
F00911B0: 80a2206c                 cmp     %o0, 0x6C ! 'l'
F00911B4: 1280000c                 bne     loc_F00911E4
F00911B8: 90103ed0                 mov     -0x130, %o0
F00911BC: d0060000                 ld      [%i0], %o0
F00911C0: 80a22000                 cmp     %o0, 0
F00911C4: 06800007                 bl      loc_F00911E0
F00911C8: 133c0448                 sethi   %hi(dword_F0112258), %o1
F00911CC: d0062018                 ld      [%i0+0x18], %o0
F00911D0: d2026258                 ld      [%o1+%lo(dword_F0112258)], %o1
F00911D4: 80a20009                 cmp     %o0, %o1
F00911D8: 02800005                 be      loc_F00911EC
F00911DC: 01000000                 nop
F00911E0: 90103ed0                 mov     -0x130, %o0
F00911E4: 10800013                 ba      locret_F0091230
F00911E8: d026601c                 st      %o0, [%i1+0x1C]
F00911EC: 7fff5028                 call    _convert_port_to_host
F00911F0: d0062008                 ld      [%i0+8], %o0
F00911F4: 9206201c                 add     %i0, 0x1C, %o1
F00911F8: 94066024                 add     %i1, 0x24, %o2 ! '$'
F00911FC: 7ffffc76                 call    _kern_IOLookupByDeviceName
F0091200: 9606602c                 add     %i1, 0x2C, %o3 ! ','
F0091204: 80a22000                 cmp     %o0, 0
F0091208: 1280000a                 bne     locret_F0091230
F009120C: d026601c                 st      %o0, [%i1+0x1C]
F0091210: 9010207c                 mov     0x7C, %o0 ! '|'
F0091214: d0266004                 st      %o0, [%i1+4]
F0091218: 113c0448                 sethi   %hi(dword_F011225C), %o0
F009121C: d002225c                 ld      [%o0+%lo(dword_F011225C)], %o0
F0091220: d0266020                 st      %o0, [%i1+0x20]
F0091224: 113c0448                 sethi   %hi(dword_F0112260), %o0
F0091228: d0022260                 ld      [%o0+%lo(dword_F0112260)], %o0
F009122C: d0266028                 st      %o0, [%i1+0x28]
F0091230: 81c7e008                 ret
F0091234: 81e80000                 restore
