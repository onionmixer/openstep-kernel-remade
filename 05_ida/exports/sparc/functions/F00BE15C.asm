F00BE15C: 9de3bf90                 save    %sp, -0x70, %sp
F00BE160: d2062044                 ld      [%i0+0x44], %o1
F00BE164: 80a26001                 cmp     %o1, 1
F00BE168: 0280000f                 be      loc_F00BE1A4
F00BE16C: a0100019                 mov     %i1, %l0
F00BE170: 80a26001                 cmp     %o1, 1
F00BE174: 0a800005                 bcs     loc_F00BE188
F00BE178: 80a26002                 cmp     %o1, 2
F00BE17C: 02800013                 be      loc_F00BE1C8
F00BE180: 96043fd0                 add     %l0, -0x30, %o3
F00BE184: 308000d0                 ba,a    loc_F00BE4C4
F00BE188: 912e6018                 sll     %i1, 24, %o0
F00BE18C: 913a2018                 sra     %o0, 24, %o0
F00BE190: 80a2201b                 cmp     %o0, 0x1B
F00BE194: 128000cc                 bne     loc_F00BE4C4
F00BE198: 90102001                 mov     1, %o0
F00BE19C: 10800139                 ba      locret_F00BE680
F00BE1A0: d0262044                 st      %o0, [%i0+0x44]
F00BE1A4: 912e6018                 sll     %i1, 24, %o0
F00BE1A8: 913a2018                 sra     %o0, 24, %o0
F00BE1AC: 80a2205b                 cmp     %o0, 0x5B ! '['
F00BE1B0: 32800005                 bne,a   loc_F00BE1C4
F00BE1B4: c0262044                 clr     [%i0+0x44]
F00BE1B8: 90102002                 mov     2, %o0
F00BE1BC: 10800131                 ba      locret_F00BE680
F00BE1C0: d0262044                 st      %o0, [%i0+0x44]
F00BE1C4: 96043fd0                 add     %l0, -0x30, %o3
F00BE1C8: 900ae0ff                 and     %o3, 0xFF, %o0
F00BE1CC: 80a22009                 cmp     %o0, 9
F00BE1D0: 1880000a                 bgu     loc_F00BE1F8
F00BE1D4: 912c2018                 sll     %l0, 24, %o0
F00BE1D8: d406204c                 ld      [%i0+0x4C], %o2
F00BE1DC: d20a8000                 ldub    [%o2], %o1
F00BE1E0: 912a6002                 sll     %o1, 2, %o0
F00BE1E4: 90020009                 add     %o0, %o1, %o0
F00BE1E8: 912a2001                 sll     %o0, 1, %o0
F00BE1EC: 9002000b                 add     %o0, %o3, %o0
F00BE1F0: 10800124                 ba      locret_F00BE680
F00BE1F4: d02a8000                 stb     %o0, [%o2]
F00BE1F8: 913a2018                 sra     %o0, 24, %o0
F00BE1FC: 80a2203b                 cmp     %o0, 0x3B ! ';'
F00BE200: 12800009                 bne     loc_F00BE224
F00BE204: 92102000                 mov     0, %o1
F00BE208: d206204c                 ld      [%i0+0x4C], %o1
F00BE20C: 9006204b                 add     %i0, 0x4B, %o0 ! 'K'
F00BE210: 80a24008                 cmp     %o1, %o0
F00BE214: 1a80011b                 bcc     locret_F00BE680
F00BE218: 90026001                 add     %o1, 1, %o0
F00BE21C: 10800119                 ba      locret_F00BE680
F00BE220: d026204c                 st      %o0, [%i0+0x4C]
F00BE224: 96102001                 mov     1, %o3
F00BE228: 94060009                 add     %i0, %o1, %o2
F00BE22C: d00aa048                 ldub    [%o2+0x48], %o0
F00BE230: 80a22000                 cmp     %o0, 0
F00BE234: 22800002                 be,a    loc_F00BE23C
F00BE238: d62aa048                 stb     %o3, [%o2+0x48]
F00BE23C: 92026001                 inc     %o1
F00BE240: 80a26002                 cmp     %o1, 2
F00BE244: 04bffffa                 ble     loc_F00BE22C
F00BE248: 94060009                 add     %i0, %o1, %o2
F00BE24C: d006204c                 ld      [%i0+0x4C], %o0
F00BE250: f20a0000                 ldub    [%o0], %i1
F00BE254: 7fffff32                 call    sub_F00BDF1C
F00BE258: 90100018                 mov     %i0, %o0
F00BE25C: 90043fbf                 add     %l0, -0x41, %o0
F00BE260: 912a2018                 sll     %o0, 24, %o0
F00BE264: 933a2018                 sra     %o0, 24, %o1
F00BE268: 80a2602c                 cmp     %o1, 0x2C ! ','! switch 45 cases
F00BE26C: 1880008b                 bgu     def_F00BE280! jumptable F00BE280 default case, cases 5,6,8,9,11-36,38-43
F00BE270: 113c02f8                 sethi   %hi(jpt_F00BE280), %o0
F00BE274: 90122288                 bset    %lo(jpt_F00BE280), %o0
F00BE278: 932a6002                 sll     %o1, 2, %o1
F00BE27C: d0024008                 ld      [%o1+%o0], %o0
F00BE280: 81c20000                 jmp     %o0! switch jump
F00BE284: 01000000                 nop
F00BE33C: b2067fff                 inc     -1, %i1! jumptable F00BE280 case 0
F00BE340: 80a67fff                 cmp     %i1, -1
F00BE344: 02800056                 be      loc_F00BE49C
F00BE348: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE34C: d0062024                 ld      [%i0+0x24], %o0
F00BE350: 80a22000                 cmp     %o0, 0
F00BE354: 02800004                 be      loc_F00BE364
F00BE358: b2067fff                 inc     -1, %i1
F00BE35C: 90023fff                 inc     -1, %o0
F00BE360: d0262024                 st      %o0, [%i0+0x24]
F00BE364: 80a67fff                 cmp     %i1, -1
F00BE368: 32bffffa                 bne,a   loc_F00BE350
F00BE36C: d0062024                 ld      [%i0+0x24], %o0
F00BE370: 1080004b                 ba      loc_F00BE49C
F00BE374: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE378: b2067fff                 inc     -1, %i1! jumptable F00BE280 case 1
F00BE37C: 80a67fff                 cmp     %i1, -1
F00BE380: 02800047                 be      loc_F00BE49C
F00BE384: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE388: b2067fff                 inc     -1, %i1
F00BE38C: d0062024                 ld      [%i0+0x24], %o0
F00BE390: 80a67fff                 cmp     %i1, -1
F00BE394: 90022001                 inc     %o0
F00BE398: 12bffffc                 bne     loc_F00BE388
F00BE39C: d0262024                 st      %o0, [%i0+0x24]
F00BE3A0: 1080003f                 ba      loc_F00BE49C
F00BE3A4: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE3A8: b2067fff                 inc     -1, %i1! jumptable F00BE280 case 2
F00BE3AC: 80a67fff                 cmp     %i1, -1
F00BE3B0: 0280003b                 be      loc_F00BE49C
F00BE3B4: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE3B8: b2067fff                 inc     -1, %i1
F00BE3BC: d0062028                 ld      [%i0+0x28], %o0
F00BE3C0: 80a67fff                 cmp     %i1, -1
F00BE3C4: 90022001                 inc     %o0
F00BE3C8: 12bffffc                 bne     loc_F00BE3B8
F00BE3CC: d0262028                 st      %o0, [%i0+0x28]
F00BE3D0: 10800033                 ba      loc_F00BE49C
F00BE3D4: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE3D8: b2067fff                 inc     -1, %i1! jumptable F00BE280 case 3
F00BE3DC: 80a67fff                 cmp     %i1, -1
F00BE3E0: 0280002f                 be      loc_F00BE49C
F00BE3E4: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE3E8: d0062028                 ld      [%i0+0x28], %o0
F00BE3EC: 80a22000                 cmp     %o0, 0
F00BE3F0: 02800004                 be      loc_F00BE400
F00BE3F4: b2067fff                 inc     -1, %i1
F00BE3F8: 90023fff                 inc     -1, %o0
F00BE3FC: d0262028                 st      %o0, [%i0+0x28]
F00BE400: 80a67fff                 cmp     %i1, -1
F00BE404: 32bffffa                 bne,a   loc_F00BE3EC
F00BE408: d0062028                 ld      [%i0+0x28], %o0
F00BE40C: 10800024                 ba      loc_F00BE49C
F00BE410: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE414: b2067fff                 inc     -1, %i1! jumptable F00BE280 case 4
F00BE418: 80a67fff                 cmp     %i1, -1
F00BE41C: 0280001f                 be      def_F00BE280! jumptable F00BE280 default case, cases 5,6,8,9,11-36,38-43
F00BE420: c0262028                 clr     [%i0+0x28]
F00BE424: b2067fff                 inc     -1, %i1
F00BE428: d0062024                 ld      [%i0+0x24], %o0
F00BE42C: 80a67fff                 cmp     %i1, -1
F00BE430: 90022001                 inc     %o0
F00BE434: 12bffffc                 bne     loc_F00BE424
F00BE438: d0262024                 st      %o0, [%i0+0x24]
F00BE43C: 10800018                 ba      loc_F00BE49C
F00BE440: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE444: d006204c                 ld      [%i0+0x4C], %o0! jumptable F00BE280 cases 7,37
F00BE448: d00a0000                 ldub    [%o0], %o0
F00BE44C: d206204c                 ld      [%i0+0x4C], %o1
F00BE450: 90023fff                 inc     -1, %o0
F00BE454: d0262028                 st      %o0, [%i0+0x28]
F00BE458: 90027fff                 add     %o1, -1, %o0
F00BE45C: d026204c                 st      %o0, [%i0+0x4C]
F00BE460: d00a7fff                 ldub    [%o1-1], %o0
F00BE464: 90023fff                 inc     -1, %o0
F00BE468: d206204c                 ld      [%i0+0x4C], %o1
F00BE46C: d0262024                 st      %o0, [%i0+0x24]
F00BE470: 92027fff                 inc     -1, %o1
F00BE474: 10800009                 ba      def_F00BE280! jumptable F00BE280 default case, cases 5,6,8,9,11-36,38-43
F00BE478: d226204c                 st      %o1, [%i0+0x4C]
F00BE47C: 7ffffeef                 call    sub_F00BE038! jumptable F00BE280 case 10
F00BE480: 90100018                 mov     %i0, %o0
F00BE484: 10800006                 ba      loc_F00BE49C
F00BE488: 90062049                 add     %i0, 0x49, %o0 ! 'I'
F00BE48C: d006204c                 ld      [%i0+0x4C], %o0! jumptable F00BE280 case 44
F00BE490: 90023ffe                 inc     -2, %o0
F00BE494: d026204c                 st      %o0, [%i0+0x4C]
F00BE498: 90062049                 add     %i0, 0x49, %o0 ! 'I'! jumptable F00BE280 default case, cases 5,6,8,9,11-36,38-43
F00BE49C: d026204c                 st      %o0, [%i0+0x4C]
F00BE4A0: 90062002                 add     %i0, 2, %o0
F00BE4A4: 92100018                 mov     %i0, %o1
F00BE4A8: c02a2048                 clrb    [%o0+0x48]
F00BE4AC: 90023fff                 inc     -1, %o0
F00BE4B0: 80a20009                 cmp     %o0, %o1
F00BE4B4: 36bffffe                 bge,a   loc_F00BE4AC
F00BE4B8: c02a2048                 clrb    [%o0+0x48]
F00BE4BC: 1080004d                 ba      loc_F00BE5F0
F00BE4C0: c0262044                 clr     [%i0+0x44]
F00BE4C4: 7ffffe96                 call    sub_F00BDF1C
F00BE4C8: 90100018                 mov     %i0, %o0
F00BE4CC: 90043ffc                 add     %l0, -4, %o0
F00BE4D0: 912a2018                 sll     %o0, 24, %o0
F00BE4D4: 933a2018                 sra     %o0, 24, %o1
F00BE4D8: 80a26009                 cmp     %o1, 9! switch 10 cases
F00BE4DC: 18800041                 bgu     def_F00BE4F0! jumptable F00BE4F0 default case, cases 1-3,7
F00BE4E0: 113c02f9                 sethi   %hi(jpt_F00BE4F0), %o0
F00BE4E4: 901220f8                 bset    %lo(jpt_F00BE4F0), %o0
F00BE4E8: 932a6002                 sll     %o1, 2, %o1
F00BE4EC: d0024008                 ld      [%o1+%o0], %o0
F00BE4F0: 81c20000                 jmp     %o0! switch jump
F00BE4F4: 01000000                 nop
F00BE520: 10800034                 ba      loc_F00BE5F0! jumptable F00BE4F0 case 9
F00BE524: c0262028                 clr     [%i0+0x28]
F00BE528: d0062024                 ld      [%i0+0x24], %o0! jumptable F00BE4F0 case 6
F00BE52C: c0262028                 clr     [%i0+0x28]
F00BE530: 90022001                 inc     %o0
F00BE534: 1080002f                 ba      loc_F00BE5F0
F00BE538: d0262024                 st      %o0, [%i0+0x24]
F00BE53C: d0062028                 ld      [%i0+0x28], %o0! jumptable F00BE4F0 case 4
F00BE540: 80a22000                 cmp     %o0, 0
F00BE544: 0280002b                 be      loc_F00BE5F0
F00BE548: 90023fff                 inc     -1, %o0
F00BE54C: 10800029                 ba      loc_F00BE5F0
F00BE550: d0262028                 st      %o0, [%i0+0x28]
F00BE554: d4062028                 ld      [%i0+0x28], %o2! jumptable F00BE4F0 case 5
F00BE558: 80a2a000                 cmp     %o2, 0
F00BE55C: 16800003                 bge     loc_F00BE568
F00BE560: 9210000a                 mov     %o2, %o1
F00BE564: 9202a007                 add     %o2, 7, %o1
F00BE568: 90100018                 mov     %i0, %o0
F00BE56C: 920a7ff8                 and     %o1, -8, %o1
F00BE570: 92228009                 sub     %o2, %o1, %o1
F00BE574: 94102008                 mov     8, %o2
F00BE578: 7ffffe69                 call    sub_F00BDF1C
F00BE57C: a0228009                 sub     %o2, %o1, %l0
F00BE580: b2102000                 mov     0, %i1
F00BE584: 80a64010                 cmp     %i1, %l0
F00BE588: 16800008                 bge     loc_F00BE5A8
F00BE58C: 90100018                 mov     %i0, %o0
F00BE590: 7ffffef3                 call    sub_F00BE15C
F00BE594: 92102020                 mov     0x20, %o1 ! ' '
F00BE598: b2066001                 inc     %i1
F00BE59C: 80a64010                 cmp     %i1, %l0
F00BE5A0: 06bffffc                 bl      loc_F00BE590
F00BE5A4: 90100018                 mov     %i0, %o0
F00BE5A8: 7ffffe5d                 call    sub_F00BDF1C
F00BE5AC: 90100018                 mov     %i0, %o0
F00BE5B0: 10800011                 ba      loc_F00BE5F4
F00BE5B4: d2062028                 ld      [%i0+0x28], %o1
F00BE5B8: c0262028                 clr     [%i0+0x28]! jumptable F00BE4F0 case 8
F00BE5BC: c0262024                 clr     [%i0+0x24]
F00BE5C0: 7ffffe8f                 call    sub_F00BDFFC
F00BE5C4: 90100018                 mov     %i0, %o0
F00BE5C8: 1080000b                 ba      loc_F00BE5F4
F00BE5CC: d2062028                 ld      [%i0+0x28], %o1
F00BE5D0: d0062028                 ld      [%i0+0x28], %o0! jumptable F00BE4F0 case 0
F00BE5D4: 90022001                 inc     %o0
F00BE5D8: 10800006                 ba      loc_F00BE5F0
F00BE5DC: d0262028                 st      %o0, [%i0+0x28]
F00BE5E0: 90100018                 mov     %i0, %o0! jumptable F00BE4F0 default case, cases 1-3,7
F00BE5E4: 932c2018                 sll     %l0, 24, %o1
F00BE5E8: 7ffffeb7                 call    sub_F00BE0C4
F00BE5EC: 933a6018                 sra     %o1, 24, %o1
F00BE5F0: d2062028                 ld      [%i0+0x28], %o1
F00BE5F4: d0062014                 ld      [%i0+0x14], %o0
F00BE5F8: 80a24008                 cmp     %o1, %o0
F00BE5FC: 26800007                 bl,a    loc_F00BE618
F00BE600: d2062024                 ld      [%i0+0x24], %o1
F00BE604: d0062024                 ld      [%i0+0x24], %o0
F00BE608: c0262028                 clr     [%i0+0x28]
F00BE60C: 90022001                 inc     %o0
F00BE610: d0262024                 st      %o0, [%i0+0x24]
F00BE614: d2062024                 ld      [%i0+0x24], %o1
F00BE618: d006201c                 ld      [%i0+0x1C], %o0
F00BE61C: 80a24008                 cmp     %o1, %o0
F00BE620: 06800016                 bl      loc_F00BE678
F00BE624: 9207bff0                 add     %fp, var_10, %o1
F00BE628: d006200c                 ld      [%i0+0xC], %o0
F00BE62C: d037bff0                 sth     %o0, [%fp+var_10]
F00BE630: d0062010                 ld      [%i0+0x10], %o0
F00BE634: 9002200c                 inc     0xC, %o0
F00BE638: d037bff2                 sth     %o0, [%fp+var_E]
F00BE63C: d0062018                 ld      [%i0+0x18], %o0
F00BE640: d037bff4                 sth     %o0, [%fp+var_C]
F00BE644: d0062020                 ld      [%i0+0x20], %o0
F00BE648: 90023ff4                 inc     -0xC, %o0
F00BE64C: d037bff6                 sth     %o0, [%fp+var_A]
F00BE650: d406200c                 ld      [%i0+0xC], %o2
F00BE654: d6062010                 ld      [%i0+0x10], %o3
F00BE658: 40009c7b                 call    _sparcfbMoveRect
F00BE65C: 90102000                 mov     0, %o0
F00BE660: c0262028                 clr     [%i0+0x28]
F00BE664: d2062024                 ld      [%i0+0x24], %o1
F00BE668: 90100018                 mov     %i0, %o0
F00BE66C: 92027fff                 inc     -1, %o1
F00BE670: 7ffffe72                 call    sub_F00BE038
F00BE674: d2262024                 st      %o1, [%i0+0x24]
F00BE678: 7ffffe29                 call    sub_F00BDF1C
F00BE67C: 90100018                 mov     %i0, %o0
F00BE680: 81c7e008                 ret
F00BE684: 81e80000                 restore
