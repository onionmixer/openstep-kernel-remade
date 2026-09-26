F00AC318: 9de3bf18                 save    %sp, -0xE8, %sp
F00AC31C: d6064000                 ld      [%i1], %o3
F00AC320: e8068000                 ld      [%i2], %l4
F00AC324: 9532e00e                 srl     %o3, 14, %o2
F00AC328: 940aa01f                 and     %o2, 0x1F, %o2
F00AC32C: a732e019                 srl     %o3, 25, %l3
F00AC330: a60ce01f                 and     %l3, 0x1F, %l3
F00AC334: c026200c                 clr     [%i0+0xC]
F00AC338: 91352017                 srl     %l4, 23, %o0
F00AC33C: 900a201f                 and     %o0, 0x1F, %o0
F00AC340: d0260000                 st      %o0, [%i0]
F00AC344: 9135201e                 srl     %l4, 30, %o0
F00AC348: d0262004                 st      %o0, [%i0+4]
F00AC34C: 9135201c                 srl     %l4, 28, %o0
F00AC350: 900a2003                 and     %o0, 3, %o0
F00AC354: d0262008                 st      %o0, [%i0+8]
F00AC358: 9132e007                 srl     %o3, 7, %o0
F00AC35C: 920a203f                 and     %o0, 0x3F, %o1
F00AC360: 80a26034                 cmp     %o1, 0x34 ! '4'! switch 53 cases
F00AC364: 1880014e                 bgu     def_F00AC37C! jumptable F00AC37C default case, cases 3-9,11-15,22-25,28-48
F00AC368: b20ae01f                 and     %o3, 0x1F, %i1
F00AC36C: 113c02b090122384         set     jpt_F00AC37C, %o0
F00AC374: 932a6002                 sll     %o1, 2, %o1
F00AC378: d0024008                 ld      [%o1+%o0], %o0
F00AC37C: 81c20000                 jmp     %o0! switch jump
F00AC380: 01000000                 nop
F00AC458: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 0
F00AC45C: a007bf7c                 add     %fp, var_84, %l0
F00AC460: 92100010                 mov     %l0, %o1
F00AC464: 400008c7                 call    __fp_unpack_word
F00AC468: 94100019                 mov     %i1, %o2
F00AC46C: 90100018                 mov     %i0, %o0
F00AC470: 92100010                 mov     %l0, %o1
F00AC474: 4000077a                 call    __fp_pack_word
F00AC478: 94100013                 mov     %l3, %o2
F00AC47C: 1080010b                 ba      loc_F00AC8A8
F00AC480: d206200c                 ld      [%i0+0xC], %o1
F00AC484: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 2
F00AC488: a007bf7c                 add     %fp, var_84, %l0
F00AC48C: 92100010                 mov     %l0, %o1
F00AC490: 400008bc                 call    __fp_unpack_word
F00AC494: 94100019                 mov     %i1, %o2
F00AC498: 90100018                 mov     %i0, %o0
F00AC49C: 92100010                 mov     %l0, %o1
F00AC4A0: 94100013                 mov     %l3, %o2
F00AC4A4: d807bf7c                 ld      [%fp+var_84], %o4
F00AC4A8: 17200000                 sethi   0x80000000, %o3
F00AC4AC: 1080000d                 ba      loc_F00AC4E0
F00AC4B0: 962b000b                 andn    %o4, %o3, %o3
F00AC4B4: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 1
F00AC4B8: a007bf7c                 add     %fp, var_84, %l0
F00AC4BC: 92100010                 mov     %l0, %o1
F00AC4C0: 400008b0                 call    __fp_unpack_word
F00AC4C4: 94100019                 mov     %i1, %o2
F00AC4C8: 90100018                 mov     %i0, %o0
F00AC4CC: 92100010                 mov     %l0, %o1
F00AC4D0: 94100013                 mov     %l3, %o2
F00AC4D4: d607bf7c                 ld      [%fp+var_84], %o3
F00AC4D8: 19200000                 sethi   0x80000000, %o4
F00AC4DC: 961ac00c                 btog    %o4, %o3
F00AC4E0: 4000075f                 call    __fp_pack_word
F00AC4E4: d627bf7c                 st      %o3, [%fp+var_84]
F00AC4E8: 108000f0                 ba      loc_F00AC8A8
F00AC4EC: d206200c                 ld      [%i0+0xC], %o1
F00AC4F0: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 16
F00AC4F4: a407bfd0                 add     %fp, var_30, %l2
F00AC4F8: 92100012                 mov     %l2, %o1
F00AC4FC: a332e005                 srl     %o3, 5, %l1
F00AC500: a20c6003                 and     %l1, 3, %l1
F00AC504: 40000847                 call    __fp_unpack
F00AC508: 96100011                 mov     %l1, %o3
F00AC50C: 90100018                 mov     %i0, %o0
F00AC510: a007bfa8                 add     %fp, var_58, %l0
F00AC514: 92100010                 mov     %l0, %o1
F00AC518: 94100019                 mov     %i1, %o2
F00AC51C: 40000841                 call    __fp_unpack
F00AC520: 96100011                 mov     %l1, %o3
F00AC524: 90100018                 mov     %i0, %o0
F00AC528: 92100012                 mov     %l2, %o1
F00AC52C: 94100010                 mov     %l0, %o2
F00AC530: a007bf80                 add     %fp, var_80, %l0
F00AC534: 7ffffc1e                 call    __fp_add
F00AC538: 96100010                 mov     %l0, %o3
F00AC53C: 10800098                 ba      loc_F00AC79C
F00AC540: 90100018                 mov     %i0, %o0
F00AC544: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 17
F00AC548: a407bfd0                 add     %fp, var_30, %l2
F00AC54C: 92100012                 mov     %l2, %o1
F00AC550: a332e005                 srl     %o3, 5, %l1
F00AC554: a20c6003                 and     %l1, 3, %l1
F00AC558: 40000832                 call    __fp_unpack
F00AC55C: 96100011                 mov     %l1, %o3
F00AC560: 90100018                 mov     %i0, %o0
F00AC564: a007bfa8                 add     %fp, var_58, %l0
F00AC568: 92100010                 mov     %l0, %o1
F00AC56C: 94100019                 mov     %i1, %o2
F00AC570: 4000082c                 call    __fp_unpack
F00AC574: 96100011                 mov     %l1, %o3
F00AC578: 90100018                 mov     %i0, %o0
F00AC57C: 92100012                 mov     %l2, %o1
F00AC580: 94100010                 mov     %l0, %o2
F00AC584: a007bf80                 add     %fp, var_80, %l0
F00AC588: 7ffffc19                 call    __fp_sub
F00AC58C: 96100010                 mov     %l0, %o3
F00AC590: 10800083                 ba      loc_F00AC79C
F00AC594: 90100018                 mov     %i0, %o0
F00AC598: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 18
F00AC59C: a407bfd0                 add     %fp, var_30, %l2
F00AC5A0: 92100012                 mov     %l2, %o1
F00AC5A4: a332e005                 srl     %o3, 5, %l1
F00AC5A8: a20c6003                 and     %l1, 3, %l1
F00AC5AC: 4000081d                 call    __fp_unpack
F00AC5B0: 96100011                 mov     %l1, %o3
F00AC5B4: 90100018                 mov     %i0, %o0
F00AC5B8: a007bfa8                 add     %fp, var_58, %l0
F00AC5BC: 92100010                 mov     %l0, %o1
F00AC5C0: 94100019                 mov     %i1, %o2
F00AC5C4: 40000817                 call    __fp_unpack
F00AC5C8: 96100011                 mov     %l1, %o3
F00AC5CC: 90100018                 mov     %i0, %o0
F00AC5D0: 92100012                 mov     %l2, %o1
F00AC5D4: 94100010                 mov     %l0, %o2
F00AC5D8: a007bf80                 add     %fp, var_80, %l0
F00AC5DC: 40000296                 call    __fp_mul
F00AC5E0: 96100010                 mov     %l0, %o3
F00AC5E4: 1080006e                 ba      loc_F00AC79C
F00AC5E8: 90100018                 mov     %i0, %o0
F00AC5EC: 90100018                 mov     %i0, %o0! jumptable F00AC37C cases 26,27
F00AC5F0: a407bfd0                 add     %fp, var_30, %l2
F00AC5F4: 92100012                 mov     %l2, %o1
F00AC5F8: a332e005                 srl     %o3, 5, %l1
F00AC5FC: a20c6003                 and     %l1, 3, %l1
F00AC600: 40000808                 call    __fp_unpack
F00AC604: 96100011                 mov     %l1, %o3
F00AC608: 90100018                 mov     %i0, %o0
F00AC60C: a007bfa8                 add     %fp, var_58, %l0
F00AC610: 92100010                 mov     %l0, %o1
F00AC614: 94100019                 mov     %i1, %o2
F00AC618: 40000802                 call    __fp_unpack
F00AC61C: 96100011                 mov     %l1, %o3
F00AC620: 90100018                 mov     %i0, %o0
F00AC624: 92100012                 mov     %l2, %o1
F00AC628: 94100010                 mov     %l0, %o2
F00AC62C: a007bf80                 add     %fp, var_80, %l0
F00AC630: 40000281                 call    __fp_mul
F00AC634: 96100010                 mov     %l0, %o3
F00AC638: 90100018                 mov     %i0, %o0
F00AC63C: 92100010                 mov     %l0, %o1
F00AC640: 94100013                 mov     %l3, %o2
F00AC644: 4000066b                 call    __fp_pack
F00AC648: 96046001                 add     %l1, 1, %o3
F00AC64C: 10800097                 ba      loc_F00AC8A8
F00AC650: d206200c                 ld      [%i0+0xC], %o1
F00AC654: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 19
F00AC658: a407bfd0                 add     %fp, var_30, %l2
F00AC65C: 92100012                 mov     %l2, %o1
F00AC660: a332e005                 srl     %o3, 5, %l1
F00AC664: a20c6003                 and     %l1, 3, %l1
F00AC668: 400007ee                 call    __fp_unpack
F00AC66C: 96100011                 mov     %l1, %o3
F00AC670: 90100018                 mov     %i0, %o0
F00AC674: a007bfa8                 add     %fp, var_58, %l0
F00AC678: 92100010                 mov     %l0, %o1
F00AC67C: 94100019                 mov     %i1, %o2
F00AC680: 400007e8                 call    __fp_unpack
F00AC684: 96100011                 mov     %l1, %o3
F00AC688: 90100018                 mov     %i0, %o0
F00AC68C: 92100012                 mov     %l2, %o1
F00AC690: 94100010                 mov     %l0, %o2
F00AC694: a007bf80                 add     %fp, var_80, %l0
F00AC698: 7ffffc34                 call    __fp_div
F00AC69C: 96100010                 mov     %l0, %o3
F00AC6A0: 1080003f                 ba      loc_F00AC79C
F00AC6A4: 90100018                 mov     %i0, %o0
F00AC6A8: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 20
F00AC6AC: a407bfd0                 add     %fp, var_30, %l2
F00AC6B0: 92100012                 mov     %l2, %o1
F00AC6B4: a132e005                 srl     %o3, 5, %l0
F00AC6B8: a00c2003                 and     %l0, 3, %l0
F00AC6BC: 400007d9                 call    __fp_unpack
F00AC6C0: 96100010                 mov     %l0, %o3
F00AC6C4: 90100018                 mov     %i0, %o0
F00AC6C8: a207bfa8                 add     %fp, var_58, %l1
F00AC6CC: 92100011                 mov     %l1, %o1
F00AC6D0: 94100019                 mov     %i1, %o2
F00AC6D4: 400007d3                 call    __fp_unpack
F00AC6D8: 96100010                 mov     %l0, %o3
F00AC6DC: 90100018                 mov     %i0, %o0
F00AC6E0: 92100012                 mov     %l2, %o1
F00AC6E4: 94100011                 mov     %l1, %o2
F00AC6E8: 10800013                 ba      loc_F00AC734
F00AC6EC: 96102000                 mov     0, %o3
F00AC6F0: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 21
F00AC6F4: a407bfd0                 add     %fp, var_30, %l2
F00AC6F8: 92100012                 mov     %l2, %o1
F00AC6FC: a132e005                 srl     %o3, 5, %l0
F00AC700: a00c2003                 and     %l0, 3, %l0
F00AC704: 400007c7                 call    __fp_unpack
F00AC708: 96100010                 mov     %l0, %o3
F00AC70C: 90100018                 mov     %i0, %o0
F00AC710: a207bfa8                 add     %fp, var_58, %l1
F00AC714: 92100011                 mov     %l1, %o1
F00AC718: 94100019                 mov     %i1, %o2
F00AC71C: 400007c1                 call    __fp_unpack
F00AC720: 96100010                 mov     %l0, %o3
F00AC724: 90100018                 mov     %i0, %o0
F00AC728: 92100012                 mov     %l2, %o1
F00AC72C: 94100011                 mov     %l1, %o2
F00AC730: 96102001                 mov     1, %o3
F00AC734: 7ffffbc4                 call    __fp_compare
F00AC738: 01000000                 nop
F00AC73C: d406200c                 ld      [%i0+0xC], %o2
F00AC740: d2060000                 ld      [%i0], %o1
F00AC744: 808a8009                 btst    %o1, %o2
F00AC748: 32800058                 bne,a   loc_F00AC8A8
F00AC74C: d206200c                 ld      [%i0+0xC], %o1
F00AC750: a80d33ff                 and     %l4, -0xC01, %l4
F00AC754: 900a2003                 and     %o0, 3, %o0
F00AC758: 912a200a                 sll     %o0, 10, %o0
F00AC75C: 10800052                 ba      loc_F00AC8A4
F00AC760: a8150008                 bset    %o0, %l4
F00AC764: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 10
F00AC768: a007bfd0                 add     %fp, var_30, %l0
F00AC76C: 92100010                 mov     %l0, %o1
F00AC770: 94100019                 mov     %i1, %o2
F00AC774: a332e005                 srl     %o3, 5, %l1
F00AC778: a20c6003                 and     %l1, 3, %l1
F00AC77C: 400007a9                 call    __fp_unpack
F00AC780: 96100011                 mov     %l1, %o3
F00AC784: 90100018                 mov     %i0, %o0
F00AC788: 92100010                 mov     %l0, %o1
F00AC78C: a007bf80                 add     %fp, var_80, %l0
F00AC790: 7ffffd5d                 call    __fp_sqrt
F00AC794: 94100010                 mov     %l0, %o2
F00AC798: 90100018                 mov     %i0, %o0
F00AC79C: 92100010                 mov     %l0, %o1
F00AC7A0: 94100013                 mov     %l3, %o2
F00AC7A4: 40000613                 call    __fp_pack
F00AC7A8: 96100011                 mov     %l1, %o3
F00AC7AC: 1080003f                 ba      loc_F00AC8A8
F00AC7B0: d206200c                 ld      [%i0+0xC], %o1
F00AC7B4: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 52
F00AC7B8: a007bfd0                 add     %fp, var_30, %l0
F00AC7BC: 92100010                 mov     %l0, %o1
F00AC7C0: 94100019                 mov     %i1, %o2
F00AC7C4: 9732e005                 srl     %o3, 5, %o3
F00AC7C8: 40000796                 call    __fp_unpack
F00AC7CC: 960ae003                 and     %o3, 3, %o3
F00AC7D0: 90102001                 mov     1, %o0
F00AC7D4: d0262004                 st      %o0, [%i0+4]
F00AC7D8: 90100018                 mov     %i0, %o0
F00AC7DC: 92100010                 mov     %l0, %o1
F00AC7E0: 94100013                 mov     %l3, %o2
F00AC7E4: 40000603                 call    __fp_pack
F00AC7E8: 96102000                 mov     0, %o3
F00AC7EC: 1080002f                 ba      loc_F00AC8A8
F00AC7F0: d206200c                 ld      [%i0+0xC], %o1
F00AC7F4: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 49
F00AC7F8: a007bfd0                 add     %fp, var_30, %l0
F00AC7FC: 92100010                 mov     %l0, %o1
F00AC800: 94100019                 mov     %i1, %o2
F00AC804: 9732e005                 srl     %o3, 5, %o3
F00AC808: 40000786                 call    __fp_unpack
F00AC80C: 960ae003                 and     %o3, 3, %o3
F00AC810: 90100018                 mov     %i0, %o0
F00AC814: 92100010                 mov     %l0, %o1
F00AC818: 94100013                 mov     %l3, %o2
F00AC81C: 400005f5                 call    __fp_pack
F00AC820: 96102001                 mov     1, %o3
F00AC824: 10800021                 ba      loc_F00AC8A8
F00AC828: d206200c                 ld      [%i0+0xC], %o1
F00AC82C: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 50
F00AC830: a007bfd0                 add     %fp, var_30, %l0
F00AC834: 92100010                 mov     %l0, %o1
F00AC838: 94100019                 mov     %i1, %o2
F00AC83C: 9732e005                 srl     %o3, 5, %o3
F00AC840: 40000778                 call    __fp_unpack
F00AC844: 960ae003                 and     %o3, 3, %o3
F00AC848: 90100018                 mov     %i0, %o0
F00AC84C: 92100010                 mov     %l0, %o1
F00AC850: 94100013                 mov     %l3, %o2
F00AC854: 400005e7                 call    __fp_pack
F00AC858: 96102002                 mov     2, %o3
F00AC85C: 10800013                 ba      loc_F00AC8A8
F00AC860: d206200c                 ld      [%i0+0xC], %o1
F00AC864: 90100018                 mov     %i0, %o0! jumptable F00AC37C case 51
F00AC868: a007bfd0                 add     %fp, var_30, %l0
F00AC86C: 92100010                 mov     %l0, %o1
F00AC870: 94100019                 mov     %i1, %o2
F00AC874: 9732e005                 srl     %o3, 5, %o3
F00AC878: 4000076a                 call    __fp_unpack
F00AC87C: 960ae003                 and     %o3, 3, %o3
F00AC880: 90100018                 mov     %i0, %o0
F00AC884: 92100010                 mov     %l0, %o1
F00AC888: 94100013                 mov     %l3, %o2
F00AC88C: 400005d9                 call    __fp_pack
F00AC890: 96102003                 mov     3, %o3
F00AC894: 10800005                 ba      loc_F00AC8A8
F00AC898: d206200c                 ld      [%i0+0xC], %o1
F00AC89C: 10800031                 ba      locret_F00AC960! jumptable F00AC37C default case, cases 3-9,11-15,22-25,28-48
F00AC8A0: b0102003                 mov     3, %i0
F00AC8A4: d206200c                 ld      [%i0+0xC], %o1
F00AC8A8: a80d3fe0                 and     %l4, -0x20, %l4
F00AC8AC: 900a601f                 and     %o1, 0x1F, %o0
F00AC8B0: 80a26000                 cmp     %o1, 0
F00AC8B4: 02800029                 be      loc_F00AC958
F00AC8B8: a8150008                 bset    %o0, %l4
F00AC8BC: 91352017                 srl     %l4, 23, %o0
F00AC8C0: 900a201f                 and     %o0, 0x1F, %o0
F00AC8C4: 908a4008                 andcc   %o1, %o0, %o0
F00AC8C8: 0280001e                 be      loc_F00AC940
F00AC8CC: 808a2010                 btst    0x10, %o0
F00AC8D0: 02800005                 be      loc_F00AC8E4
F00AC8D4: 808a2008                 btst    8, %o0
F00AC8D8: 9010260a                 mov     0x60A, %o0
F00AC8DC: 10800016                 ba      loc_F00AC934
F00AC8E0: d026201c                 st      %o0, [%i0+0x1C]
F00AC8E4: 02800005                 be      loc_F00AC8F8
F00AC8E8: 808a2004                 btst    4, %o0
F00AC8EC: 9010260b                 mov     0x60B, %o0
F00AC8F0: 10800011                 ba      loc_F00AC934
F00AC8F4: d026201c                 st      %o0, [%i0+0x1C]
F00AC8F8: 02800005                 be      loc_F00AC90C
F00AC8FC: 808a2002                 btst    2, %o0
F00AC900: 90102609                 mov     0x609, %o0
F00AC904: 1080000c                 ba      loc_F00AC934
F00AC908: d026201c                 st      %o0, [%i0+0x1C]
F00AC90C: 02800005                 be      loc_F00AC920
F00AC910: 808a2001                 btst    1, %o0
F00AC914: 90102608                 mov     0x608, %o0
F00AC918: 10800007                 ba      loc_F00AC934
F00AC91C: d026201c                 st      %o0, [%i0+0x1C]
F00AC920: 02800004                 be      loc_F00AC930
F00AC924: 90102607                 mov     0x607, %o0
F00AC928: 10800003                 ba      loc_F00AC934
F00AC92C: d026201c                 st      %o0, [%i0+0x1C]
F00AC930: c026201c                 clr     [%i0+0x1C]
F00AC934: e8268000                 st      %l4, [%i2]
F00AC938: 1080000a                 ba      locret_F00AC960
F00AC93C: b0102001                 mov     1, %i0
F00AC940: 91352005                 srl     %l4, 5, %o0
F00AC944: a80d3c1f                 and     %l4, -0x3E1, %l4
F00AC948: 90124008                 bset    %o1, %o0
F00AC94C: 900a201f                 and     %o0, 0x1F, %o0
F00AC950: 912a2005                 sll     %o0, 5, %o0
F00AC954: a8150008                 bset    %o0, %l4
F00AC958: e8268000                 st      %l4, [%i2]
F00AC95C: b0102000                 mov     0, %i0
F00AC960: 81c7e008                 ret
F00AC964: 81e80000                 restore
