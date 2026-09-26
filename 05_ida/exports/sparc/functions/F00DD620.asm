F00DD620: 9de3bf90                 save    %sp, -0x70, %sp
F00DD624: d00620a0                 ld      [%i0+0xA0], %o0
F00DD628: 80a22000                 cmp     %o0, 0
F00DD62C: 22800005                 be,a    loc_F00DD640
F00DD630: d006209c                 ld      [%i0+0x9C], %o0
F00DD634: 7fffa244                 call    _IOFree
F00DD638: 92102040                 mov     0x40, %o1 ! '@'
F00DD63C: d006209c                 ld      [%i0+0x9C], %o0
F00DD640: 80a22000                 cmp     %o0, 0
F00DD644: 22800005                 be,a    loc_F00DD658
F00DD648: d006208c                 ld      [%i0+0x8C], %o0
F00DD64C: 7fffa23e                 call    _IOFree
F00DD650: 92102040                 mov     0x40, %o1 ! '@'
F00DD654: d006208c                 ld      [%i0+0x8C], %o0
F00DD658: 9206208c                 add     %i0, 0x8C, %o1
F00DD65C: 80a24008                 cmp     %o1, %o0
F00DD660: 22800019                 be,a    loc_F00DD6C4
F00DD664: d4062070                 ld      [%i0+0x70], %o2
F00DD668: a0100009                 mov     %o1, %l0
F00DD66C: d006208c                 ld      [%i0+0x8C], %o0
F00DD670: d6022014                 ld      [%o0+0x14], %o3
F00DD674: 80a4000b                 cmp     %l0, %o3
F00DD678: 12800004                 bne     loc_F00DD688
F00DD67C: d4022018                 ld      [%o0+0x18], %o2
F00DD680: 10800003                 ba      loc_F00DD68C
F00DD684: 92100010                 mov     %l0, %o1
F00DD688: 9202e014                 add     %o3, 0x14, %o1
F00DD68C: 80a4000a                 cmp     %l0, %o2
F00DD690: 12800004                 bne     loc_F00DD6A0
F00DD694: d4226004                 st      %o2, [%o1+4]
F00DD698: 10800003                 ba      loc_F00DD6A4
F00DD69C: 92100010                 mov     %l0, %o1
F00DD6A0: 9202a014                 add     %o2, 0x14, %o1
F00DD6A4: d6224000                 st      %o3, [%o1]
F00DD6A8: 7fffa227                 call    _IOFree
F00DD6AC: 9210201c                 mov     0x1C, %o1
F00DD6B0: d006208c                 ld      [%i0+0x8C], %o0
F00DD6B4: 80a40008                 cmp     %l0, %o0
F00DD6B8: 32bfffef                 bne,a   loc_F00DD674
F00DD6BC: d6022014                 ld      [%o0+0x14], %o3
F00DD6C0: d4062070                 ld      [%i0+0x70], %o2
F00DD6C4: 80a2a000                 cmp     %o2, 0
F00DD6C8: 02800006                 be      loc_F00DD6E0
F00DD6CC: 113c0447                 sethi   %hi(_page_size), %o0
F00DD6D0: d202213c                 ld      [%o0+%lo(_page_size)], %o1
F00DD6D4: 9010000a                 mov     %o2, %o0
F00DD6D8: 7fffa21b                 call    _IOFree
F00DD6DC: 932a6003                 sll     %o1, 3, %o1
F00DD6E0: d4062074                 ld      [%i0+0x74], %o2
F00DD6E4: 80a2a000                 cmp     %o2, 0
F00DD6E8: 02800006                 be      loc_F00DD700
F00DD6EC: 113c0447                 sethi   %hi(_page_size), %o0
F00DD6F0: d202213c                 ld      [%o0+%lo(_page_size)], %o1
F00DD6F4: 9010000a                 mov     %o2, %o0
F00DD6F8: 7fffa213                 call    _IOFree
F00DD6FC: 932a6002                 sll     %o1, 2, %o1
F00DD700: f027bff0                 st      %i0, [%fp+var_10]
F00DD704: 133c0508                 sethi   %hi(stru_F01422CC.ext), %o1
F00DD708: d40262f8                 ld      [%o1+%lo(stru_F01422CC.ext)], %o2
F00DD70C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DD710: 133c0503                 sethi   %hi(paFree), %o1
F00DD714: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00DD718: 40005099                 call    _objc_msgSendSuper
F00DD71C: d427bff4                 st      %o2, [%fp+var_C]
F00DD720: 81c7e008                 ret
F00DD724: 91e80008                 restore %g0, %o0, %o0
