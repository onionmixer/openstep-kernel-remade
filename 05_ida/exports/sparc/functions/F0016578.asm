F0016578: 9de3bf98                 save    %sp, -0x68, %sp
F001657C: f4060000                 ld      [%i0], %i2
F0016580: b2102000                 mov     0, %i1
F0016584: f8062010                 ld      [%i0+0x10], %i4
F0016588: 8410001a                 mov     %i2, %g2
F001658C: f606a03c                 ld      [%i2+0x3C], %i3
F0016590: c020a064                 clr     [%g2+0x64]
F0016594: b2066001                 inc     %i1
F0016598: 80a66007                 cmp     %i1, 7
F001659C: 08bffffd                 bleu    loc_F0016590
F00165A0: 8400a004                 inc     4, %g2
F00165A4: 808ee020                 btst    0x20, %i3 ! ' '
F00165A8: 128000c7                 bne     locret_F00168C4
F00165AC: 808f2010                 btst    0x10, %i4
F00165B0: 0280001d                 be      loc_F0016624
F00165B4: 808f2008                 btst    8, %i4
F00165B8: f20ea05a                 ldub    [%i2+0x5A], %i1
F00165BC: b00e60ff                 and     %i1, 0xFF, %i0
F00165C0: 80a620ff                 cmp     %i0, 0xFF
F00165C4: 0280000a                 be      loc_F00165EC
F00165C8: b1362005                 srl     %i0, 5, %i0
F00165CC: b12e2002                 sll     %i0, 2, %i0
F00165D0: b006001a                 add     %i0, %i2, %i0
F00165D4: b20e601f                 and     %i1, 0x1F, %i1
F00165D8: 84102001                 mov     1, %g2
F00165DC: c6062064                 ld      [%i0+0x64], %g3
F00165E0: 85288019                 sll     %g2, %i1, %g2
F00165E4: 8610c002                 bset    %g2, %g3
F00165E8: c6262064                 st      %g3, [%i0+0x64]
F00165EC: f20ea058                 ldub    [%i2+0x58], %i1
F00165F0: b00e60ff                 and     %i1, 0xFF, %i0
F00165F4: 80a620ff                 cmp     %i0, 0xFF
F00165F8: 0280000a                 be      loc_F0016620
F00165FC: b1362005                 srl     %i0, 5, %i0
F0016600: b12e2002                 sll     %i0, 2, %i0
F0016604: b006001a                 add     %i0, %i2, %i0
F0016608: b20e601f                 and     %i1, 0x1F, %i1
F001660C: 84102001                 mov     1, %g2
F0016610: c6062064                 ld      [%i0+0x64], %g3
F0016614: 85288019                 sll     %g2, %i1, %g2
F0016618: 8610c002                 bset    %g2, %g3
F001661C: c6262064                 st      %g3, [%i0+0x64]
F0016620: 808f2008                 btst    8, %i4
F0016624: 0280002a                 be      loc_F00166CC
F0016628: 05010000                 sethi   0x4000000, %g2
F001662C: f20ea04f                 ldub    [%i2+0x4F], %i1
F0016630: b00e60ff                 and     %i1, 0xFF, %i0
F0016634: 80a620ff                 cmp     %i0, 0xFF
F0016638: 0280000a                 be      loc_F0016660
F001663C: b1362005                 srl     %i0, 5, %i0
F0016640: b12e2002                 sll     %i0, 2, %i0
F0016644: b006001a                 add     %i0, %i2, %i0
F0016648: b20e601f                 and     %i1, 0x1F, %i1
F001664C: 84102001                 mov     1, %g2
F0016650: c6062064                 ld      [%i0+0x64], %g3
F0016654: 85288019                 sll     %g2, %i1, %g2
F0016658: 8610c002                 bset    %g2, %g3
F001665C: c6262064                 st      %g3, [%i0+0x64]
F0016660: f20ea050                 ldub    [%i2+0x50], %i1
F0016664: b00e60ff                 and     %i1, 0xFF, %i0
F0016668: 80a620ff                 cmp     %i0, 0xFF
F001666C: 0280000a                 be      loc_F0016694
F0016670: b1362005                 srl     %i0, 5, %i0
F0016674: b12e2002                 sll     %i0, 2, %i0
F0016678: b006001a                 add     %i0, %i2, %i0
F001667C: b20e601f                 and     %i1, 0x1F, %i1
F0016680: 84102001                 mov     1, %g2
F0016684: c6062064                 ld      [%i0+0x64], %g3
F0016688: 85288019                 sll     %g2, %i1, %g2
F001668C: 8610c002                 bset    %g2, %g3
F0016690: c6262064                 st      %g3, [%i0+0x64]
F0016694: f20ea055                 ldub    [%i2+0x55], %i1
F0016698: b00e60ff                 and     %i1, 0xFF, %i0
F001669C: 80a620ff                 cmp     %i0, 0xFF
F00166A0: 0280000a                 be      loc_F00166C8
F00166A4: b1362005                 srl     %i0, 5, %i0
F00166A8: b12e2002                 sll     %i0, 2, %i0
F00166AC: b006001a                 add     %i0, %i2, %i0
F00166B0: b20e601f                 and     %i1, 0x1F, %i1
F00166B4: 84102001                 mov     1, %g2
F00166B8: c6062064                 ld      [%i0+0x64], %g3
F00166BC: 85288019                 sll     %g2, %i1, %g2
F00166C0: 8610c002                 bset    %g2, %g3
F00166C4: c6262064                 st      %g3, [%i0+0x64]
F00166C8: 05010000                 sethi   0x4000000, %g2
F00166CC: 808f0002                 btst    %g2, %i4
F00166D0: 0280001d                 be      loc_F0016744
F00166D4: 808ee010                 btst    0x10, %i3
F00166D8: f20ea052                 ldub    [%i2+0x52], %i1
F00166DC: b00e60ff                 and     %i1, 0xFF, %i0
F00166E0: 80a620ff                 cmp     %i0, 0xFF
F00166E4: 0280000a                 be      loc_F001670C
F00166E8: b1362005                 srl     %i0, 5, %i0
F00166EC: b12e2002                 sll     %i0, 2, %i0
F00166F0: b006001a                 add     %i0, %i2, %i0
F00166F4: b20e601f                 and     %i1, 0x1F, %i1
F00166F8: 84102001                 mov     1, %g2
F00166FC: c6062064                 ld      [%i0+0x64], %g3
F0016700: 85288019                 sll     %g2, %i1, %g2
F0016704: 8610c002                 bset    %g2, %g3
F0016708: c6262064                 st      %g3, [%i0+0x64]
F001670C: f20ea051                 ldub    [%i2+0x51], %i1
F0016710: b00e60ff                 and     %i1, 0xFF, %i0
F0016714: 80a620ff                 cmp     %i0, 0xFF
F0016718: 0280000a                 be      loc_F0016740
F001671C: b1362005                 srl     %i0, 5, %i0
F0016720: b12e2002                 sll     %i0, 2, %i0
F0016724: b006001a                 add     %i0, %i2, %i0
F0016728: b20e601f                 and     %i1, 0x1F, %i1
F001672C: 84102001                 mov     1, %g2
F0016730: c6062064                 ld      [%i0+0x64], %g3
F0016734: 85288019                 sll     %g2, %i1, %g2
F0016738: 8610c002                 bset    %g2, %g3
F001673C: c6262064                 st      %g3, [%i0+0x64]
F0016740: 808ee010                 btst    0x10, %i3
F0016744: 32800007                 bne,a   loc_F0016760
F0016748: c406a064                 ld      [%i2+0x64], %g2
F001674C: 0500c000                 sethi   0x3000000, %g2
F0016750: 808f0002                 btst    %g2, %i4
F0016754: 02800007                 be      loc_F0016770
F0016758: 05002000                 sethi   0x800000, %g2
F001675C: c406a064                 ld      [%i2+0x64], %g2
F0016760: 07000008                 sethi   0x2000, %g3
F0016764: 84108003                 bset    %g3, %g2
F0016768: c426a064                 st      %g2, [%i2+0x64]
F001676C: 05002000                 sethi   0x800000, %g2
F0016770: 808f0002                 btst    %g2, %i4
F0016774: 02800005                 be      loc_F0016788
F0016778: 808ee002                 btst    2, %i3
F001677C: c406a064                 ld      [%i2+0x64], %g2
F0016780: 8410a400                 bset    0x400, %g2
F0016784: c426a064                 st      %g2, [%i2+0x64]
F0016788: 12800037                 bne     loc_F0016864
F001678C: 808ee004                 btst    4, %i3
F0016790: f20ea04d                 ldub    [%i2+0x4D], %i1
F0016794: b00e60ff                 and     %i1, 0xFF, %i0
F0016798: 80a620ff                 cmp     %i0, 0xFF
F001679C: 0280000a                 be      loc_F00167C4
F00167A0: b1362005                 srl     %i0, 5, %i0
F00167A4: b12e2002                 sll     %i0, 2, %i0
F00167A8: b006001a                 add     %i0, %i2, %i0
F00167AC: b20e601f                 and     %i1, 0x1F, %i1
F00167B0: 84102001                 mov     1, %g2
F00167B4: c6062064                 ld      [%i0+0x64], %g3
F00167B8: 85288019                 sll     %g2, %i1, %g2
F00167BC: 8610c002                 bset    %g2, %g3
F00167C0: c6262064                 st      %g3, [%i0+0x64]
F00167C4: f20ea04e                 ldub    [%i2+0x4E], %i1
F00167C8: b00e60ff                 and     %i1, 0xFF, %i0
F00167CC: 80a620ff                 cmp     %i0, 0xFF
F00167D0: 0280000a                 be      loc_F00167F8
F00167D4: b1362005                 srl     %i0, 5, %i0
F00167D8: b12e2002                 sll     %i0, 2, %i0
F00167DC: b006001a                 add     %i0, %i2, %i0
F00167E0: b20e601f                 and     %i1, 0x1F, %i1
F00167E4: 84102001                 mov     1, %g2
F00167E8: c6062064                 ld      [%i0+0x64], %g3
F00167EC: 85288019                 sll     %g2, %i1, %g2
F00167F0: 8610c002                 bset    %g2, %g3
F00167F4: c6262064                 st      %g3, [%i0+0x64]
F00167F8: f20ea059                 ldub    [%i2+0x59], %i1
F00167FC: b00e60ff                 and     %i1, 0xFF, %i0
F0016800: 80a620ff                 cmp     %i0, 0xFF
F0016804: 0280000a                 be      loc_F001682C
F0016808: b1362005                 srl     %i0, 5, %i0
F001680C: b12e2002                 sll     %i0, 2, %i0
F0016810: b006001a                 add     %i0, %i2, %i0
F0016814: b20e601f                 and     %i1, 0x1F, %i1
F0016818: 84102001                 mov     1, %g2
F001681C: c6062064                 ld      [%i0+0x64], %g3
F0016820: 85288019                 sll     %g2, %i1, %g2
F0016824: 8610c002                 bset    %g2, %g3
F0016828: c6262064                 st      %g3, [%i0+0x64]
F001682C: f20ea057                 ldub    [%i2+0x57], %i1
F0016830: b00e60ff                 and     %i1, 0xFF, %i0
F0016834: 80a620ff                 cmp     %i0, 0xFF
F0016838: 0280000a                 be      loc_F0016860
F001683C: b1362005                 srl     %i0, 5, %i0
F0016840: b12e2002                 sll     %i0, 2, %i0
F0016844: b006001a                 add     %i0, %i2, %i0
F0016848: b20e601f                 and     %i1, 0x1F, %i1
F001684C: 84102001                 mov     1, %g2
F0016850: c6062064                 ld      [%i0+0x64], %g3
F0016854: 85288019                 sll     %g2, %i1, %g2
F0016858: 8610c002                 bset    %g2, %g3
F001685C: c6262064                 st      %g3, [%i0+0x64]
F0016860: 808ee004                 btst    4, %i3
F0016864: 02800010                 be      loc_F00168A4
F0016868: 05000604                 sethi   0x181000, %g2
F001686C: b2102000                 mov     0, %i1
F0016870: b6102001                 mov     1, %i3
F0016874: 85366003                 srl     %i1, 3, %g2
F0016878: b00e601f                 and     %i1, 0x1F, %i0
F001687C: b2066001                 inc     %i1
F0016880: 80a6607f                 cmp     %i1, 0x7F
F0016884: 8408a01c                 and     %g2, 0x1C, %g2
F0016888: 8400801a                 add     %g2, %i2, %g2
F001688C: c600a064                 ld      [%g2+0x64], %g3
F0016890: b12ec018                 sll     %i3, %i0, %i0
F0016894: 8610c018                 bset    %i0, %g3
F0016898: 04bffff7                 ble     loc_F0016874
F001689C: c620a064                 st      %g3, [%g2+0x64]
F00168A0: 05000604                 sethi   0x181000, %g2
F00168A4: 840f0002                 and     %i4, %g2, %g2
F00168A8: 07000404                 sethi   0x101000, %g3
F00168AC: 80a08003                 cmp     %g2, %g3
F00168B0: 12800005                 bne     locret_F00168C4
F00168B4: 07200000                 sethi   0x80000000, %g3
F00168B8: c406a080                 ld      [%i2+0x80], %g2
F00168BC: 84108003                 bset    %g3, %g2
F00168C0: c426a080                 st      %g2, [%i2+0x80]
F00168C4: 81c7e008                 ret
F00168C8: 81e80000                 restore
