F00EE6BC: 9de3bf98                 save    %sp, -0x68, %sp
F00EE6C0: a2100018                 mov     %i0, %l1
F00EE6C4: e404600c                 ld      [%l1+0xC], %l2
F00EE6C8: d0044000                 ld      [%l1], %o0
F00EE6CC: d4020000                 ld      [%o0], %o2
F00EE6D0: 90100011                 mov     %l1, %o0
F00EE6D4: 9fc28000                 call    %o2
F00EE6D8: 92100019                 mov     %i1, %o1
F00EE6DC: 94100008                 mov     %o0, %o2
F00EE6E0: 1300003f921263ff         set     0xFFFF, %o1
F00EE6E8: 920a8009                 and     %o2, %o1, %o1
F00EE6EC: 9132a010                 srl     %o2, 16, %o0
F00EE6F0: 921a4008                 btog    %o0, %o1
F00EE6F4: 912a600c                 sll     %o1, 12, %o0
F00EE6F8: 90220009                 sub     %o0, %o1, %o0
F00EE6FC: 912a2004                 sll     %o0, 4, %o0
F00EE700: 90020009                 add     %o0, %o1, %o0
F00EE704: 9002000a                 add     %o0, %o2, %o0
F00EE708: 7ffc6066                 call    _urem
F00EE70C: d2046008                 ld      [%l1+8], %o1
F00EE710: a6100008                 mov     %o0, %l3
F00EE714: 912ce003                 sll     %l3, 3, %o0
F00EE718: b0048008                 add     %l2, %o0, %i0
F00EE71C: d0048008                 ld      [%l2+%o0], %o0
F00EE720: 80a23fff                 cmp     %o0, -1
F00EE724: 02800040                 be      loc_F00EE824
F00EE728: 133c04bc                 sethi   %hi(dword_F012F0AC), %o1
F00EE72C: d00260ac                 ld      [%o1+%lo(dword_F012F0AC)], %o0
F00EE730: 90022001                 inc     %o0
F00EE734: d02260ac                 st      %o0, [%o1+%lo(dword_F012F0AC)]
F00EE738: d2060000                 ld      [%i0], %o1
F00EE73C: 80a24019                 cmp     %o1, %i1
F00EE740: 02800009                 be      loc_F00EE764
F00EE744: 90102001                 mov     1, %o0
F00EE748: d0044000                 ld      [%l1], %o0
F00EE74C: d6022004                 ld      [%o0+4], %o3
F00EE750: 90100011                 mov     %l1, %o0
F00EE754: 9fc2c000                 call    %o3
F00EE758: 94100019                 mov     %i1, %o2
F00EE75C: 10800003                 ba      loc_F00EE768
F00EE760: 80a22000                 cmp     %o0, 0
F00EE764: 80a22000                 cmp     %o0, 0
F00EE768: 02800009                 be      loc_F00EE78C
F00EE76C: 133c04bc                 sethi   %hi(dword_F012F0B0), %o1
F00EE770: d0062004                 ld      [%i0+4], %o0
F00EE774: d0268000                 st      %o0, [%i2]
F00EE778: d00260b0                 ld      [%o1+%lo(dword_F012F0B0)], %o0
F00EE77C: 90022001                 inc     %o0
F00EE780: d02260b0                 st      %o0, [%o1+%lo(dword_F012F0B0)]
F00EE784: 10800029                 ba      locret_F00EE828
F00EE788: f0060000                 ld      [%i0], %i0
F00EE78C: a0100013                 mov     %l3, %l0
F00EE790: 293c04bc                 sethi   -0xFED1000, %l4
F00EE794: 92042001                 add     %l0, 1, %o1
F00EE798: d0046008                 ld      [%l1+8], %o0
F00EE79C: 80a24008                 cmp     %o1, %o0
F00EE7A0: 1a800003                 bcc     loc_F00EE7AC
F00EE7A4: 90102000                 mov     0, %o0
F00EE7A8: 90100009                 mov     %o1, %o0
F00EE7AC: a0100008                 mov     %o0, %l0
F00EE7B0: 80a40013                 cmp     %l0, %l3
F00EE7B4: 0280001c                 be      loc_F00EE824
F00EE7B8: d00520b4                 ld      [%l4+0xB4], %o0
F00EE7BC: 90022001                 inc     %o0
F00EE7C0: d02520b4                 st      %o0, [%l4+0xB4]
F00EE7C4: 912c2003                 sll     %l0, 3, %o0
F00EE7C8: b0048008                 add     %l2, %o0, %i0
F00EE7CC: d0048008                 ld      [%l2+%o0], %o0
F00EE7D0: 80a23fff                 cmp     %o0, -1
F00EE7D4: 22800015                 be,a    locret_F00EE828
F00EE7D8: b0103fff                 mov     -1, %i0
F00EE7DC: d2060000                 ld      [%i0], %o1
F00EE7E0: 80a24019                 cmp     %o1, %i1
F00EE7E4: 02800009                 be      loc_F00EE808
F00EE7E8: 90102001                 mov     1, %o0
F00EE7EC: d0044000                 ld      [%l1], %o0
F00EE7F0: d6022004                 ld      [%o0+4], %o3
F00EE7F4: 90100011                 mov     %l1, %o0
F00EE7F8: 9fc2c000                 call    %o3
F00EE7FC: 94100019                 mov     %i1, %o2
F00EE800: 10800003                 ba      loc_F00EE80C
F00EE804: 80a22000                 cmp     %o0, 0
F00EE808: 80a22000                 cmp     %o0, 0
F00EE80C: 02bfffe3                 be      loc_F00EE798
F00EE810: 92042001                 add     %l0, 1, %o1
F00EE814: d0062004                 ld      [%i0+4], %o0
F00EE818: d0268000                 st      %o0, [%i2]
F00EE81C: 10800003                 ba      locret_F00EE828
F00EE820: f0060000                 ld      [%i0], %i0
F00EE824: b0103fff                 mov     -1, %i0
F00EE828: 81c7e008                 ret
F00EE82C: 81e80000                 restore
