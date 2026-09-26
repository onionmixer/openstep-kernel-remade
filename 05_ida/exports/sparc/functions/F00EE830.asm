F00EE830: 9de3bf90                 save    %sp, -0x70, %sp
F00EE834: e406200c                 ld      [%i0+0xC], %l2
F00EE838: d0060000                 ld      [%i0], %o0
F00EE83C: d4020000                 ld      [%o0], %o2
F00EE840: 90100018                 mov     %i0, %o0
F00EE844: 9fc28000                 call    %o2
F00EE848: 92100019                 mov     %i1, %o1
F00EE84C: 94100008                 mov     %o0, %o2
F00EE850: 1300003f921263ff         set     0xFFFF, %o1
F00EE858: 920a8009                 and     %o2, %o1, %o1
F00EE85C: 9132a010                 srl     %o2, 16, %o0
F00EE860: 921a4008                 btog    %o0, %o1
F00EE864: 912a600c                 sll     %o1, 12, %o0
F00EE868: 90220009                 sub     %o0, %o1, %o0
F00EE86C: 912a2004                 sll     %o0, 4, %o0
F00EE870: 90020009                 add     %o0, %o1, %o0
F00EE874: 9002000a                 add     %o0, %o2, %o0
F00EE878: 7ffc600a                 call    _urem
F00EE87C: d2062008                 ld      [%i0+8], %o1
F00EE880: a6100008                 mov     %o0, %l3
F00EE884: 912ce003                 sll     %l3, 3, %o0
F00EE888: a2048008                 add     %l2, %o0, %l1
F00EE88C: d0048008                 ld      [%l2+%o0], %o0
F00EE890: 80a23fff                 cmp     %o0, -1
F00EE894: 02800040                 be      loc_F00EE994
F00EE898: 133c04bc                 sethi   %hi(dword_F012F0AC), %o1
F00EE89C: d00260ac                 ld      [%o1+%lo(dword_F012F0AC)], %o0
F00EE8A0: 90022001                 inc     %o0
F00EE8A4: d02260ac                 st      %o0, [%o1+%lo(dword_F012F0AC)]
F00EE8A8: d2044000                 ld      [%l1], %o1
F00EE8AC: 80a24019                 cmp     %o1, %i1
F00EE8B0: 02800009                 be      loc_F00EE8D4
F00EE8B4: 90102001                 mov     1, %o0
F00EE8B8: d0060000                 ld      [%i0], %o0
F00EE8BC: d6022004                 ld      [%o0+4], %o3
F00EE8C0: 90100018                 mov     %i0, %o0
F00EE8C4: 9fc2c000                 call    %o3
F00EE8C8: 94100019                 mov     %i1, %o2
F00EE8CC: 10800003                 ba      loc_F00EE8D8
F00EE8D0: 80a22000                 cmp     %o0, 0
F00EE8D4: 80a22000                 cmp     %o0, 0
F00EE8D8: 02800009                 be      loc_F00EE8FC
F00EE8DC: 133c04bc                 sethi   %hi(dword_F012F0B0), %o1
F00EE8E0: d0046004                 ld      [%l1+4], %o0
F00EE8E4: d027bff4                 st      %o0, [%fp+var_C]
F00EE8E8: d00260b0                 ld      [%o1+%lo(dword_F012F0B0)], %o0
F00EE8EC: 90022001                 inc     %o0
F00EE8F0: d02260b0                 st      %o0, [%o1+%lo(dword_F012F0B0)]
F00EE8F4: 10800029                 ba      loc_F00EE998
F00EE8F8: d0044000                 ld      [%l1], %o0
F00EE8FC: a0100013                 mov     %l3, %l0
F00EE900: 293c04bc                 sethi   -0xFED1000, %l4
F00EE904: 92042001                 add     %l0, 1, %o1
F00EE908: d0062008                 ld      [%i0+8], %o0
F00EE90C: 80a24008                 cmp     %o1, %o0
F00EE910: 1a800003                 bcc     loc_F00EE91C
F00EE914: 90102000                 mov     0, %o0
F00EE918: 90100009                 mov     %o1, %o0
F00EE91C: a0100008                 mov     %o0, %l0
F00EE920: 80a40013                 cmp     %l0, %l3
F00EE924: 0280001c                 be      loc_F00EE994
F00EE928: d00520b4                 ld      [%l4+0xB4], %o0
F00EE92C: 90022001                 inc     %o0
F00EE930: d02520b4                 st      %o0, [%l4+0xB4]
F00EE934: 912c2003                 sll     %l0, 3, %o0
F00EE938: a2048008                 add     %l2, %o0, %l1
F00EE93C: d0048008                 ld      [%l2+%o0], %o0
F00EE940: 80a23fff                 cmp     %o0, -1
F00EE944: 22800015                 be,a    loc_F00EE998
F00EE948: 90103fff                 mov     -1, %o0
F00EE94C: d2044000                 ld      [%l1], %o1
F00EE950: 80a24019                 cmp     %o1, %i1
F00EE954: 02800009                 be      loc_F00EE978
F00EE958: 90102001                 mov     1, %o0
F00EE95C: d0060000                 ld      [%i0], %o0
F00EE960: d6022004                 ld      [%o0+4], %o3
F00EE964: 90100018                 mov     %i0, %o0
F00EE968: 9fc2c000                 call    %o3
F00EE96C: 94100019                 mov     %i1, %o2
F00EE970: 10800003                 ba      loc_F00EE97C
F00EE974: 80a22000                 cmp     %o0, 0
F00EE978: 80a22000                 cmp     %o0, 0
F00EE97C: 02bfffe3                 be      loc_F00EE908
F00EE980: 92042001                 add     %l0, 1, %o1
F00EE984: d0046004                 ld      [%l1+4], %o0
F00EE988: d027bff4                 st      %o0, [%fp+var_C]
F00EE98C: 10800003                 ba      loc_F00EE998
F00EE990: d0044000                 ld      [%l1], %o0
F00EE994: 90103fff                 mov     -1, %o0
F00EE998: 80a23fff                 cmp     %o0, -1
F00EE99C: 02800003                 be      locret_F00EE9A8
F00EE9A0: b0102000                 mov     0, %i0
F00EE9A4: f007bff4                 ld      [%fp+var_C], %i0
F00EE9A8: 81c7e008                 ret
F00EE9AC: 81e80000                 restore
