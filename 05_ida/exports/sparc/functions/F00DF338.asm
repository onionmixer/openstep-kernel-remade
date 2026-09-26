F00DF338: 9de3bf30                 save    %sp, -0xD0, %sp
F00DF33C: f027bfcc                 st      %i0, [%fp+var_34]
F00DF340: c027bfc4                 clr     [%fp+var_3C]
F00DF344: b8102000                 mov     0, %i4
F00DF348: a6102000                 mov     0, %l3
F00DF34C: ba102000                 mov     0, %i5
F00DF350: b4103fff                 mov     -1, %i2
F00DF354: b0102000                 mov     0, %i0
F00DF358: ae102000                 mov     0, %l7
F00DF35C: 113c0506                 sethi   %hi(paAudiochannel), %o0
F00DF360: d00222d0                 ld      [%o0+%lo(paAudiochannel)], %o0! id
F00DF364: 133c0505                 sethi   %hi(paStreamforuserp), %o1
F00DF368: d2026020                 ld      [%o1+%lo(paStreamforuserp)], %o1! SEL
F00DF36C: aa102000                 mov     0, %l5
F00DF370: e807bfcc                 ld      [%fp+var_34], %l4
F00DF374: ac102000                 mov     0, %l6
F00DF378: d405200c                 ld      [%l4+0xC], %o2
F00DF37C: c027bfbc                 clr     [%fp+var_44]
F00DF380: f605201c                 ld      [%l4+0x1C], %i3
F00DF384: 4000493b                 call    _objc_msgSend
F00DF388: c027bfb4                 clr     [%fp+var_4C]
F00DF38C: c027bfac                 clr     [%fp+var_54]
F00DF390: d2052014                 ld      [%l4+0x14], %o1
F00DF394: 80a26001                 cmp     %o1, 1
F00DF398: 1280000b                 bne     loc_F00DF3C4
F00DF39C: a4100008                 mov     %o0, %l2
F00DF3A0: 9207bfec                 add     %fp, var_14, %o1
F00DF3A4: 7ffffd6a                 call    __NXAudioStreamInfo
F00DF3A8: 9407bfe8                 add     %fp, var_18, %o2
F00DF3AC: d2052010                 ld      [%l4+0x10], %o1
F00DF3B0: d407bfec                 ld      [%fp+var_14], %o2
F00DF3B4: d607bfe8                 ld      [%fp+var_18], %o3
F00DF3B8: 40000873                 call    _audio_snd_reply_ret_samples
F00DF3BC: 90100019                 mov     %i1, %o0
F00DF3C0: 30800162                 ba,a    locret_F00DF948
F00DF3C4: d2052004                 ld      [%l4+4], %o1
F00DF3C8: 90052028                 add     %l4, 0x28, %o0 ! '('
F00DF3CC: b2027fd8                 add     %o1, -0x28, %i1
F00DF3D0: 80a66000                 cmp     %i1, 0
F00DF3D4: 04800065                 ble     loc_F00DF568
F00DF3D8: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF3DC: 113c0505                 sethi   %hi(paChannel), %o0
F00DF3E0: e2022058                 ld      [%o0+%lo(paChannel)], %l1
F00DF3E4: d007bfe4                 ld      [%fp+var_1C], %o0
F00DF3E8: d0022004                 ld      [%o0+4], %o0
F00DF3EC: 80a22005                 cmp     %o0, 5! switch 6 cases
F00DF3F0: 18800059                 bgu     def_F00DF404! jumptable F00DF404 default case
F00DF3F4: 912a2002                 sll     %o0, 2, %o0
F00DF3F8: 053c037d8410a00c         set     jpt_F00DF404, %g2
F00DF400: d0020002                 ld      [%o0+%g2], %o0
F00DF404: 81c20000                 jmp     %o0! switch jump
F00DF408: 01000000                 nop
F00DF424: b2067fd8                 inc     -0x28, %i1! jumptable F00DF404 case 0
F00DF428: d007bfe4                 ld      [%fp+var_1C], %o0
F00DF42C: 80a76000                 cmp     %i5, 0
F00DF430: 90022028                 inc     0x28, %o0 ! '('
F00DF434: 12800005                 bne     loc_F00DF448
F00DF438: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF43C: 80a6a001                 cmp     %i2, 1
F00DF440: 22800002                 be,a    loc_F00DF448
F00DF444: ba102067                 mov     0x67, %i5 ! 'g'
F00DF448: 10800045                 ba      loc_F00DF55C
F00DF44C: b4102000                 mov     0, %i2
F00DF450: d207bfe4                 ld      [%fp+var_1C], %o1! jumptable F00DF404 case 1
F00DF454: d002601c                 ld      [%o1+0x1C], %o0
F00DF458: 91322004                 srl     %o0, 4, %o0
F00DF45C: 900a2fff                 and     %o0, 0xFFF, %o0
F00DF460: 90022020                 inc     0x20, %o0 ! ' '
F00DF464: 92024008                 add     %o1, %o0, %o1
F00DF468: d227bfe4                 st      %o1, [%fp+var_1C]
F00DF46C: 1080003c                 ba      loc_F00DF55C
F00DF470: b2264008                 sub     %i1, %o0, %i1
F00DF474: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF404 case 3
F00DF478: b2067ff0                 inc     -0x10, %i1
F00DF47C: 92022010                 add     %o0, 0x10, %o1
F00DF480: d002200c                 ld      [%o0+0xC], %o0
F00DF484: d227bfe4                 st      %o1, [%fp+var_1C]
F00DF488: 10800035                 ba      loc_F00DF55C
F00DF48C: b8170008                 bset    %o0, %i4
F00DF490: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF404 case 5
F00DF494: c4022010                 ld      [%o0+0x10], %g2
F00DF498: c427bfbc                 st      %g2, [%fp+var_44]
F00DF49C: 84102001                 mov     1, %g2
F00DF4A0: c427bfac                 st      %g2, [%fp+var_54]
F00DF4A4: c4022014                 ld      [%o0+0x14], %g2
F00DF4A8: b2067fe8                 inc     -0x18, %i1
F00DF4AC: ec02200c                 ld      [%o0+0xC], %l6
F00DF4B0: c427bfb4                 st      %g2, [%fp+var_4C]
F00DF4B4: 90022018                 inc     0x18, %o0
F00DF4B8: 10800029                 ba      loc_F00DF55C
F00DF4BC: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF4C0: 90100012                 mov     %l2, %o0! jumptable F00DF404 case 2
F00DF4C4: e007bfe4                 ld      [%fp+var_1C], %l0
F00DF4C8: 92100011                 mov     %l1, %o1! SEL
F00DF4CC: f004200c                 ld      [%l0+0xC], %i0
F00DF4D0: 94042018                 add     %l0, 0x18, %o2
F00DF4D4: ee042010                 ld      [%l0+0x10], %l7
F00DF4D8: 400048e6                 call    _objc_msgSend
F00DF4DC: d427bfe4                 st      %o2, [%fp+var_1C]
F00DF4E0: 9207bfe0                 add     %fp, var_20, %o1! SEL
F00DF4E4: 7ffffaf0                 call    __NXAudioGetBufferOptions
F00DF4E8: 9407bfdc                 add     %fp, var_24, %o2
F00DF4EC: 90100012                 mov     %l2, %o0! id
F00DF4F0: 400048e0                 call    _objc_msgSend
F00DF4F4: 92100011                 mov     %l1, %o1
F00DF4F8: d4042014                 ld      [%l0+0x14], %o2
F00DF4FC: b2067fe8                 inc     -0x18, %i1
F00DF500: 10800011                 ba      loc_F00DF544
F00DF504: d607bfdc                 ld      [%fp+var_24], %o3
F00DF508: 90100012                 mov     %l2, %o0! jumptable F00DF404 case 4
F00DF50C: e007bfe4                 ld      [%fp+var_1C], %l0
F00DF510: 92100011                 mov     %l1, %o1! SEL
F00DF514: 94042010                 add     %l0, 0x10, %o2
F00DF518: 400048d6                 call    _objc_msgSend
F00DF51C: d427bfe4                 st      %o2, [%fp+var_1C]
F00DF520: 9207bfe0                 add     %fp, var_20, %o1! SEL
F00DF524: 7ffffae0                 call    __NXAudioGetBufferOptions
F00DF528: 9407bfdc                 add     %fp, var_24, %o2
F00DF52C: 90100012                 mov     %l2, %o0! id
F00DF530: 400048d0                 call    _objc_msgSend
F00DF534: 92100011                 mov     %l1, %o1
F00DF538: d407bfe0                 ld      [%fp+var_20], %o2
F00DF53C: b2067ff0                 inc     -0x10, %i1
F00DF540: d604200c                 ld      [%l0+0xC], %o3
F00DF544: 7ffffaf4                 call    __NXAudioSetBufferOptions
F00DF548: 92102000                 mov     0, %o1
F00DF54C: 10800005                 ba      loc_F00DF560
F00DF550: 80a66000                 cmp     %i1, 0
F00DF554: ba102066                 mov     0x66, %i5 ! 'f'! jumptable F00DF404 default case
F00DF558: b2102000                 mov     0, %i1
F00DF55C: 80a66000                 cmp     %i1, 0
F00DF560: 14bfffa2                 bg      loc_F00DF3E8
F00DF564: d007bfe4                 ld      [%fp+var_1C], %o0
F00DF568: 80a76000                 cmp     %i5, 0
F00DF56C: 02800038                 be      loc_F00DF64C
F00DF570: c407bfcc                 ld      [%fp+var_34], %g2
F00DF574: d200a004                 ld      [%g2+4], %o1
F00DF578: 90052028                 add     %l4, 0x28, %o0 ! '('
F00DF57C: b2027fd8                 add     %o1, -0x28, %i1
F00DF580: 80a66000                 cmp     %i1, 0
F00DF584: 04800030                 ble     loc_F00DF644
F00DF588: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF58C: 113c037da21221b8         set     jpt_F00DF5B0, %l1
F00DF594: d007bfe4                 ld      [%fp+var_1C], %o0
F00DF598: d0022004                 ld      [%o0+4], %o0
F00DF59C: 80a22005                 cmp     %o0, 5! switch 6 cases
F00DF5A0: 38800027                 bgu,a   def_F00DF5B0! jumptable F00DF5B0 default case
F00DF5A4: 80a66000                 cmp     %i1, 0
F00DF5A8: 912a2002                 sll     %o0, 2, %o0
F00DF5AC: d0020011                 ld      [%o0+%l1], %o0
F00DF5B0: 81c20000                 jmp     %o0! switch jump
F00DF5B4: 01000000                 nop
F00DF5D0: e007bfe4                 ld      [%fp+var_1C], %l0! jumptable F00DF5B0 case 0
F00DF5D4: 90042028                 add     %l0, 0x28, %o0 ! '('
F00DF5D8: 7fffab1a                 call    _IOVmTaskSelf
F00DF5DC: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF5E0: d2042024                 ld      [%l0+0x24], %o1
F00DF5E4: d4042020                 ld      [%l0+0x20], %o2
F00DF5E8: 40005370                 call    _vm_deallocate_EXTERNAL
F00DF5EC: b2067fd8                 inc     -0x28, %i1
F00DF5F0: 10800013                 ba      def_F00DF5B0! jumptable F00DF5B0 default case
F00DF5F4: 80a66000                 cmp     %i1, 0
F00DF5F8: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF5B0 case 1
F00DF5FC: b2067fe0                 inc     -0x20, %i1
F00DF600: 1080000d                 ba      loc_F00DF634
F00DF604: 90022020                 inc     0x20, %o0 ! ' '
F00DF608: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF5B0 case 5
F00DF60C: b2067fe8                 inc     -0x18, %i1
F00DF610: 10800009                 ba      loc_F00DF634
F00DF614: 90022018                 inc     0x18, %o0
F00DF618: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF5B0 case 2
F00DF61C: b2067fe8                 inc     -0x18, %i1
F00DF620: 10800005                 ba      loc_F00DF634
F00DF624: 90022018                 inc     0x18, %o0
F00DF628: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF5B0 cases 3,4
F00DF62C: b2067ff0                 inc     -0x10, %i1
F00DF630: 90022010                 inc     0x10, %o0
F00DF634: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF638: 80a66000                 cmp     %i1, 0
F00DF63C: 14bfffd7                 bg      loc_F00DF598! jumptable F00DF5B0 default case
F00DF640: d007bfe4                 ld      [%fp+var_1C], %o0
F00DF644: 108000c1                 ba      locret_F00DF948
F00DF648: b010001d                 mov     %i5, %i0
F00DF64C: c027bff4                 clr     [%fp+var_C]
F00DF650: 808f2002                 btst    2, %i4
F00DF654: 02800008                 be      loc_F00DF674
F00DF658: c027bff0                 clr     [%fp+var_10]
F00DF65C: c027bfd0                 clr     [%fp+var_30]
F00DF660: c027bfd4                 clr     [%fp+var_2C]
F00DF664: 90100012                 mov     %l2, %o0
F00DF668: 92102002                 mov     2, %o1
F00DF66C: 7ffffc78                 call    __NXAudioStreamControl
F00DF670: 9407bfd0                 add     %fp, var_30, %o2
F00DF674: 808f2001                 btst    1, %i4
F00DF678: 02800009                 be      loc_F00DF69C
F00DF67C: 90100012                 mov     %l2, %o0
F00DF680: 92102003                 mov     3, %o1
F00DF684: d807bff0                 ld      [%fp+var_10], %o4
F00DF688: 9407bfd0                 add     %fp, var_30, %o2
F00DF68C: d607bff4                 ld      [%fp+var_C], %o3
F00DF690: d827bfd0                 st      %o4, [%fp+var_30]
F00DF694: 7ffffc6e                 call    __NXAudioStreamControl
F00DF698: d627bfd4                 st      %o3, [%fp+var_2C]
F00DF69C: 808f2004                 btst    4, %i4
F00DF6A0: 02800009                 be      loc_F00DF6C4
F00DF6A4: 90100012                 mov     %l2, %o0
F00DF6A8: 92102000                 mov     0, %o1
F00DF6AC: d807bff0                 ld      [%fp+var_10], %o4
F00DF6B0: 9407bfd0                 add     %fp, var_30, %o2
F00DF6B4: d607bff4                 ld      [%fp+var_C], %o3
F00DF6B8: d827bfd0                 st      %o4, [%fp+var_30]
F00DF6BC: 7ffffc64                 call    __NXAudioStreamControl
F00DF6C0: d627bfd4                 st      %o3, [%fp+var_2C]
F00DF6C4: c407bfcc                 ld      [%fp+var_34], %g2
F00DF6C8: 90052028                 add     %l4, 0x28, %o0 ! '('
F00DF6CC: d200a004                 ld      [%g2+4], %o1
F00DF6D0: b2027fd8                 add     %o1, -0x28, %i1
F00DF6D4: 80a66000                 cmp     %i1, 0
F00DF6D8: 0480008f                 ble     loc_F00DF914
F00DF6DC: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF6E0: 113c037da812230c         set     jpt_F00DF704, %l4
F00DF6E8: d007bfe4                 ld      [%fp+var_1C], %o0
F00DF6EC: d0022004                 ld      [%o0+4], %o0
F00DF6F0: 80a22005                 cmp     %o0, 5! switch 6 cases
F00DF6F4: 18800028                 bgu     def_F00DF704! jumptable F00DF704 default case
F00DF6F8: a2102000                 mov     0, %l1
F00DF6FC: 912a2002                 sll     %o0, 2, %o0
F00DF700: d0020014                 ld      [%o0+%l4], %o0
F00DF704: 81c20000                 jmp     %o0! switch jump
F00DF708: 01000000                 nop
F00DF724: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF704 case 0
F00DF728: e602200c                 ld      [%o0+0xC], %l3
F00DF72C: c4022024                 ld      [%o0+0x24], %g2
F00DF730: e2022020                 ld      [%o0+0x20], %l1
F00DF734: b2067fd8                 inc     -0x28, %i1
F00DF738: ea022014                 ld      [%o0+0x14], %l5
F00DF73C: c427bfc4                 st      %g2, [%fp+var_3C]
F00DF740: 10800014                 ba      loc_F00DF790
F00DF744: 90022028                 inc     0x28, %o0 ! '('
F00DF748: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF704 case 1
F00DF74C: e602200c                 ld      [%o0+0xC], %l3
F00DF750: e2022010                 ld      [%o0+0x10], %l1
F00DF754: ea022018                 ld      [%o0+0x18], %l5
F00DF758: b2067fe0                 inc     -0x20, %i1
F00DF75C: 1080000d                 ba      loc_F00DF790
F00DF760: 90022020                 inc     0x20, %o0 ! ' '
F00DF764: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF704 case 5
F00DF768: b2067fe8                 inc     -0x18, %i1
F00DF76C: 10800009                 ba      loc_F00DF790
F00DF770: 90022018                 inc     0x18, %o0
F00DF774: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF704 case 2
F00DF778: b2067fe8                 inc     -0x18, %i1
F00DF77C: 10800005                 ba      loc_F00DF790
F00DF780: 90022018                 inc     0x18, %o0
F00DF784: d007bfe4                 ld      [%fp+var_1C], %o0! jumptable F00DF704 cases 3,4
F00DF788: b2067ff0                 inc     -0x10, %i1
F00DF78C: 90022010                 inc     0x10, %o0
F00DF790: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF794: 80a46000                 cmp     %l1, 0! jumptable F00DF704 default case
F00DF798: 0280005d                 be      loc_F00DF90C
F00DF79C: 80a66000                 cmp     %i1, 0
F00DF7A0: 80a6a000                 cmp     %i2, 0
F00DF7A4: 12800005                 bne     loc_F00DF7B8
F00DF7A8: a00ce001                 and     %l3, 1, %l0
F00DF7AC: 808ce002                 btst    2, %l3
F00DF7B0: 32800002                 bne,a   loc_F00DF7B8
F00DF7B4: a0142002                 bset    2, %l0
F00DF7B8: 808ce008                 btst    8, %l3
F00DF7BC: 32800002                 bne,a   loc_F00DF7C4
F00DF7C0: a0142004                 bset    4, %l0
F00DF7C4: 808ce010                 btst    0x10, %l3
F00DF7C8: 32800002                 bne,a   loc_F00DF7D0
F00DF7CC: a0142008                 bset    8, %l0
F00DF7D0: 808ce004                 btst    4, %l3
F00DF7D4: 32800002                 bne,a   loc_F00DF7DC
F00DF7D8: a0142010                 bset    0x10, %l0
F00DF7DC: 808ce020                 btst    0x20, %l3 ! ' '
F00DF7E0: 32800002                 bne,a   loc_F00DF7E8
F00DF7E4: a0142020                 bset    0x20, %l0 ! ' '
F00DF7E8: 80a6a000                 cmp     %i2, 0
F00DF7EC: 1280002d                 bne     loc_F00DF8A0
F00DF7F0: c407bfac                 ld      [%fp+var_54], %g2
F00DF7F4: 80a0a000                 cmp     %g2, 0
F00DF7F8: 02800012                 be      loc_F00DF840
F00DF7FC: 90102000                 mov     0, %o0
F00DF800: f023a05c                 st      %i0, [%sp+0xD0+var_74]
F00DF804: 92100012                 mov     %l2, %o1
F00DF808: d607bfbc                 ld      [%fp+var_44], %o3
F00DF80C: 94100016                 mov     %l6, %o2
F00DF810: d807bfb4                 ld      [%fp+var_4C], %o4
F00DF814: 7ffffea4                 call    sub_F00DF2A4
F00DF818: 9a100017                 mov     %l7, %o5
F00DF81C: 90100012                 mov     %l2, %o0
F00DF820: 94100011                 mov     %l1, %o2
F00DF824: 9610001b                 mov     %i3, %o3
F00DF828: 98100015                 mov     %l5, %o4
F00DF82C: d207bfc4                 ld      [%fp+var_3C], %o1
F00DF830: 7ffffd5b                 call    __NXAudioPlayStreamData
F00DF834: 9a100010                 mov     %l0, %o5
F00DF838: 10800035                 ba      loc_F00DF90C
F00DF83C: 80a66000                 cmp     %i1, 0
F00DF840: 90100012                 mov     %l2, %o0! id
F00DF844: 133c0505                 sethi   %hi(paType), %o1
F00DF848: d2026098                 ld      [%o1+%lo(paType)], %o1! SEL
F00DF84C: 40004809                 call    _objc_msgSend
F00DF850: ac102002                 mov     2, %l6
F00DF854: 80a22003                 cmp     %o0, 3
F00DF858: 22800002                 be,a    loc_F00DF860
F00DF85C: ac102001                 mov     1, %l6
F00DF860: 11000020                 sethi   0x8000, %o0
F00DF864: d023a05c                 st      %o0, [%sp+0xD0+var_74]
F00DF868: d023a060                 st      %o0, [%sp+0xD0+var_70]
F00DF86C: ee23a064                 st      %l7, [%sp+0xD0+var_6C]
F00DF870: f023a068                 st      %i0, [%sp+0xD0+var_68]
F00DF874: ea23a06c                 st      %l5, [%sp+0xD0+var_64]
F00DF878: e023a070                 st      %l0, [%sp+0xD0+var_60]
F00DF87C: 90100012                 mov     %l2, %o0
F00DF880: d207bfc4                 ld      [%fp+var_3C], %o1
F00DF884: 94100011                 mov     %l1, %o2
F00DF888: 9610001b                 mov     %i3, %o3
F00DF88C: 98102002                 mov     2, %o4
F00DF890: 7ffffc4d                 call    __NXAudioPlayStream
F00DF894: 9a100016                 mov     %l6, %o5
F00DF898: 1080001d                 ba      loc_F00DF90C
F00DF89C: 80a66000                 cmp     %i1, 0
F00DF8A0: 80a0a000                 cmp     %g2, 0
F00DF8A4: 02800011                 be      loc_F00DF8E8
F00DF8A8: 9010001a                 mov     %i2, %o0
F00DF8AC: f023a05c                 st      %i0, [%sp+0xD0+var_74]
F00DF8B0: 92100012                 mov     %l2, %o1
F00DF8B4: d607bfbc                 ld      [%fp+var_44], %o3
F00DF8B8: 94100016                 mov     %l6, %o2
F00DF8BC: d807bfb4                 ld      [%fp+var_4C], %o4
F00DF8C0: 7ffffe79                 call    sub_F00DF2A4
F00DF8C4: 9a100017                 mov     %l7, %o5
F00DF8C8: 90100012                 mov     %l2, %o0
F00DF8CC: 92100011                 mov     %l1, %o1
F00DF8D0: 9410001b                 mov     %i3, %o2
F00DF8D4: 96100015                 mov     %l5, %o3
F00DF8D8: 7ffffd45                 call    __NXAudioRecordStreamData
F00DF8DC: 98100010                 mov     %l0, %o4
F00DF8E0: 1080000b                 ba      loc_F00DF90C
F00DF8E4: 80a66000                 cmp     %i1, 0
F00DF8E8: e023a05c                 st      %l0, [%sp+0xD0+var_74]
F00DF8EC: 90100012                 mov     %l2, %o0
F00DF8F0: 92100011                 mov     %l1, %o1
F00DF8F4: 9410001b                 mov     %i3, %o2
F00DF8F8: 96100017                 mov     %l7, %o3
F00DF8FC: 98100018                 mov     %i0, %o4
F00DF900: 7ffffcc0                 call    __NXAudioRecordStream
F00DF904: 9a100015                 mov     %l5, %o5
F00DF908: 80a66000                 cmp     %i1, 0
F00DF90C: 14bfff78                 bg      loc_F00DF6EC
F00DF910: d007bfe4                 ld      [%fp+var_1C], %o0
F00DF914: 808f2008                 btst    8, %i4
F00DF918: 02800009                 be      loc_F00DF93C
F00DF91C: 90100012                 mov     %l2, %o0
F00DF920: 92102001                 mov     1, %o1
F00DF924: d807bff0                 ld      [%fp+var_10], %o4
F00DF928: 9407bfd0                 add     %fp, var_30, %o2
F00DF92C: d607bff4                 ld      [%fp+var_C], %o3
F00DF930: d827bfd0                 st      %o4, [%fp+var_30]
F00DF934: 7ffffbc6                 call    __NXAudioStreamControl
F00DF938: d627bfd4                 st      %o3, [%fp+var_2C]
F00DF93C: b0974000                 orcc    %i5, %g0, %i0
F00DF940: 22800002                 be,a    locret_F00DF948
F00DF944: b0102064                 mov     0x64, %i0 ! 'd'
F00DF948: 81c7e008                 ret
F00DF94C: 81e80000                 restore
