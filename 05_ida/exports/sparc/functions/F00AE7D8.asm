F00AE7D8: 9de3bf98                 save    %sp, -0x68, %sp
F00AE7DC: fa06200c                 ld      [%i0+0xC], %i5
F00AE7E0: c2062010                 ld      [%i0+0x10], %g1
F00AE7E4: c8062014                 ld      [%i0+0x14], %g4
F00AE7E8: c4062004                 ld      [%i0+4], %g2
F00AE7EC: 80a0a001                 cmp     %g2, 1
F00AE7F0: 1280005a                 bne     locret_F00AE958
F00AE7F4: de062018                 ld      [%i0+0x18], %o7
F00AE7F8: 84174001                 or      %i5, %g1, %g2
F00AE7FC: 84108004                 bset    %g4, %g2
F00AE800: 8090800f                 orcc    %g2, %o7, %g0
F00AE804: 12800004                 bne     loc_F00AE814
F00AE808: 80a76000                 cmp     %i5, 0
F00AE80C: 10800053                 ba      locret_F00AE958
F00AE810: c0262004                 clr     [%i0+4]
F00AE814: 1280000c                 bne     loc_F00AE844
F00AE818: 0500007f                 sethi   0x1FC00, %g2
F00AE81C: ba100001                 mov     %g1, %i5
F00AE820: 82100004                 mov     %g4, %g1
F00AE824: 8810000f                 mov     %o7, %g4
F00AE828: 9e102000                 mov     0, %o7
F00AE82C: c4062008                 ld      [%i0+8], %g2
F00AE830: 80a76000                 cmp     %i5, 0
F00AE834: 8400bfe0                 inc     -0x20, %g2
F00AE838: 02bffff9                 be      loc_F00AE81C
F00AE83C: c4262008                 st      %g2, [%i0+8]
F00AE840: 0500007f                 sethi   0x1FC00, %g2
F00AE844: 8410a3ff                 bset    0x3FF, %g2
F00AE848: 80a74002                 cmp     %i5, %g2
F00AE84C: 0880001e                 bleu    loc_F00AE8C4
F00AE850: b3376001                 srl     %i5, 1, %i1
F00AE854: 80a64002                 cmp     %i1, %g2
F00AE858: 08800006                 bleu    loc_F00AE870
F00AE85C: b4102001                 mov     1, %i2
F00AE860: b3366001                 srl     %i1, 1, %i1
F00AE864: 80a64002                 cmp     %i1, %g2
F00AE868: 18bffffe                 bgu     loc_F00AE860
F00AE86C: b406a001                 inc     %i2
F00AE870: 84102001                 mov     1, %g2
F00AE874: 8528801a                 sll     %g2, %i2, %g2
F00AE878: b800bfff                 add     %g2, -1, %i4
F00AE87C: 84102020                 mov     0x20, %g2 ! ' '
F00AE880: b620801a                 sub     %g2, %i2, %i3
F00AE884: 8409001c                 and     %g4, %i4, %g2
F00AE888: 8528801b                 sll     %g2, %i3, %g2
F00AE88C: 8733c01a                 srl     %o7, %i2, %g3
F00AE890: 9e108003                 or      %g2, %g3, %o7
F00AE894: 8408401c                 and     %g1, %i4, %g2
F00AE898: 8528801b                 sll     %g2, %i3, %g2
F00AE89C: 8731001a                 srl     %g4, %i2, %g3
F00AE8A0: 88108003                 or      %g2, %g3, %g4
F00AE8A4: 840f401c                 and     %i5, %i4, %g2
F00AE8A8: 8528801b                 sll     %g2, %i3, %g2
F00AE8AC: 8730401a                 srl     %g1, %i2, %g3
F00AE8B0: 82108003                 or      %g2, %g3, %g1
F00AE8B4: c4062008                 ld      [%i0+8], %g2
F00AE8B8: ba100019                 mov     %i1, %i5
F00AE8BC: 10800022                 ba      loc_F00AE944
F00AE8C0: 8400801a                 add     %g2, %i2, %g2
F00AE8C4: 0500003f8410a3ff         set     0xFFFF, %g2
F00AE8CC: 80a74002                 cmp     %i5, %g2
F00AE8D0: 3880001f                 bgu,a   loc_F00AE94C
F00AE8D4: fa26200c                 st      %i5, [%i0+0xC]
F00AE8D8: b32f6001                 sll     %i5, 1, %i1
F00AE8DC: 80a64002                 cmp     %i1, %g2
F00AE8E0: 18800006                 bgu     loc_F00AE8F8
F00AE8E4: b4102001                 mov     1, %i2
F00AE8E8: b32e6001                 sll     %i1, 1, %i1
F00AE8EC: 80a64002                 cmp     %i1, %g2
F00AE8F0: 08bffffe                 bleu    loc_F00AE8E8
F00AE8F4: b406a001                 inc     %i2
F00AE8F8: 84102020                 mov     0x20, %g2 ! ' '
F00AE8FC: b620801a                 sub     %g2, %i2, %i3
F00AE900: 84103fff                 mov     -1, %g2
F00AE904: b928801b                 sll     %g2, %i3, %i4
F00AE908: 872f401a                 sll     %i5, %i2, %g3
F00AE90C: 8408401c                 and     %g1, %i4, %g2
F00AE910: 8530801b                 srl     %g2, %i3, %g2
F00AE914: ba10c002                 or      %g3, %g2, %i5
F00AE918: 8728401a                 sll     %g1, %i2, %g3
F00AE91C: 8409001c                 and     %g4, %i4, %g2
F00AE920: 8530801b                 srl     %g2, %i3, %g2
F00AE924: 8210c002                 or      %g3, %g2, %g1
F00AE928: 8729001a                 sll     %g4, %i2, %g3
F00AE92C: 840bc01c                 and     %o7, %i4, %g2
F00AE930: 8530801b                 srl     %g2, %i3, %g2
F00AE934: 8810c002                 or      %g3, %g2, %g4
F00AE938: c4062008                 ld      [%i0+8], %g2
F00AE93C: 9f2bc01a                 sll     %o7, %i2, %o7
F00AE940: 8420801a                 sub     %g2, %i2, %g2
F00AE944: c4262008                 st      %g2, [%i0+8]
F00AE948: fa26200c                 st      %i5, [%i0+0xC]
F00AE94C: c2262010                 st      %g1, [%i0+0x10]
F00AE950: c8262014                 st      %g4, [%i0+0x14]
F00AE954: de262018                 st      %o7, [%i0+0x18]
F00AE958: 81c7e008                 ret
F00AE95C: 81e80000                 restore
