F0091118: 9de3bf98                 save    %sp, -0x68, %sp
F009111C: d0062004                 ld      [%i0+4], %o0
F0091120: 80a22020                 cmp     %o0, 0x20 ! ' '
F0091124: 1280000c                 bne     loc_F0091154
F0091128: 90103ed0                 mov     -0x130, %o0
F009112C: d0060000                 ld      [%i0], %o0
F0091130: 80a22000                 cmp     %o0, 0
F0091134: 06800007                 bl      loc_F0091150
F0091138: 133c0448                 sethi   %hi(dword_F011224C), %o1
F009113C: d0062018                 ld      [%i0+0x18], %o0
F0091140: d202624c                 ld      [%o1+%lo(dword_F011224C)], %o1
F0091144: 80a20009                 cmp     %o0, %o1
F0091148: 02800005                 be      loc_F009115C
F009114C: 01000000                 nop
F0091150: 90103ed0                 mov     -0x130, %o0
F0091154: 10800013                 ba      locret_F00911A0
F0091158: d026601c                 st      %o0, [%i1+0x1C]
F009115C: 7fff504c                 call    _convert_port_to_host
F0091160: d0062008                 ld      [%i0+8], %o0
F0091164: 94066024                 add     %i1, 0x24, %o2 ! '$'
F0091168: d206201c                 ld      [%i0+0x1C], %o1
F009116C: 7ffffc8a                 call    _kern_IOLookupByObjectNumber
F0091170: 96066078                 add     %i1, 0x78, %o3 ! 'x'
F0091174: 80a22000                 cmp     %o0, 0
F0091178: 1280000a                 bne     locret_F00911A0
F009117C: d026601c                 st      %o0, [%i1+0x1C]
F0091180: 901020c8                 mov     0xC8, %o0
F0091184: d0266004                 st      %o0, [%i1+4]
F0091188: 113c0448                 sethi   %hi(dword_F0112250), %o0
F009118C: d0022250                 ld      [%o0+%lo(dword_F0112250)], %o0
F0091190: d0266020                 st      %o0, [%i1+0x20]
F0091194: 113c0448                 sethi   %hi(dword_F0112254), %o0
F0091198: d0022254                 ld      [%o0+%lo(dword_F0112254)], %o0
F009119C: d0266074                 st      %o0, [%i1+0x74]
F00911A0: 81c7e008                 ret
F00911A4: 81e80000                 restore
