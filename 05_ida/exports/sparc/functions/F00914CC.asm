F00914CC: 9de3bf98                 save    %sp, -0x68, %sp
F00914D0: d6062004                 ld      [%i0+4], %o3
F00914D4: 80a2e067                 cmp     %o3, 0x67 ! 'g'
F00914D8: 0880002d                 bleu    loc_F009158C
F00914DC: 90103ed0                 mov     -0x130, %o0
F00914E0: d0060000                 ld      [%i0], %o0
F00914E4: 80a22000                 cmp     %o0, 0
F00914E8: 36800004                 bge,a   loc_F00914F8
F00914EC: d0062018                 ld      [%i0+0x18], %o0
F00914F0: 10800027                 ba      loc_F009158C
F00914F4: 90103ed0                 mov     -0x130, %o0
F00914F8: 133c0448                 sethi   %hi(dword_F011228C), %o1
F00914FC: d202628c                 ld      [%o1+%lo(dword_F011228C)], %o1
F0091500: 80a20009                 cmp     %o0, %o1
F0091504: 12800022                 bne     loc_F009158C
F0091508: 90103ed0                 mov     -0x130, %o0
F009150C: d0062020                 ld      [%i0+0x20], %o0
F0091510: 133c0448                 sethi   %hi(dword_F0112290), %o1
F0091514: d2026290                 ld      [%o1+%lo(dword_F0112290)], %o1
F0091518: 80a20009                 cmp     %o0, %o1
F009151C: 1280001c                 bne     loc_F009158C
F0091520: 90103ed0                 mov     -0x130, %o0
F0091524: d4062064                 ld      [%i0+0x64], %o2
F0091528: 133fffc09212600c         set     -0xFFF4, %o1
F0091530: 1102020090122008         set     0x8080008, %o0
F0091538: 920a8009                 and     %o2, %o1, %o1
F009153C: 80a24008                 cmp     %o1, %o0
F0091540: 12800013                 bne     loc_F009158C
F0091544: 90103ed0                 mov     -0x130, %o0
F0091548: 9132a004                 srl     %o2, 4, %o0
F009154C: 900a2fff                 and     %o0, 0xFFF, %o0
F0091550: 90022003                 inc     3, %o0
F0091554: 900a3ffc                 and     %o0, -4, %o0
F0091558: 90022068                 inc     0x68, %o0 ! 'h'
F009155C: 80a2c008                 cmp     %o3, %o0
F0091560: 1280000b                 bne     loc_F009158C
F0091564: 90103ed0                 mov     -0x130, %o0
F0091568: 7fff4f66                 call    _convert_port_to_host_priv
F009156C: d0062008                 ld      [%i0+8], %o0
F0091570: 94062024                 add     %i0, 0x24, %o2 ! '$'
F0091574: d8062064                 ld      [%i0+0x64], %o4
F0091578: 96062068                 add     %i0, 0x68, %o3 ! 'h'
F009157C: d206201c                 ld      [%i0+0x1C], %o1
F0091580: 99332004                 srl     %o4, 4, %o4
F0091584: 7ffffbdd                 call    _kern_IOSetCharValues
F0091588: 980b2fff                 and     %o4, 0xFFF, %o4
F009158C: d026601c                 st      %o0, [%i1+0x1C]
F0091590: 81c7e008                 ret
F0091594: 81e80000                 restore
