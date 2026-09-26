F0080304: 9de3b7a8                 save    %sp, -0x858, %sp
F0080308: d0062004                 ld      [%i0+4], %o0
F008030C: 80a22028                 cmp     %o0, 0x28 ! '('
F0080310: 12800011                 bne     loc_F0080354
F0080314: a0100019                 mov     %i1, %l0
F0080318: d0060000                 ld      [%i0], %o0
F008031C: 80a22000                 cmp     %o0, 0
F0080320: 0680000d                 bl      loc_F0080354
F0080324: 133c0445                 sethi   %hi(dword_F0111670), %o1
F0080328: d0062018                 ld      [%i0+0x18], %o0
F008032C: d2026270                 ld      [%o1+%lo(dword_F0111670)], %o1
F0080330: 80a20009                 cmp     %o0, %o1
F0080334: 12800009                 bne     loc_F0080358
F0080338: 90103ed0                 mov     -0x130, %o0
F008033C: d0062020                 ld      [%i0+0x20], %o0
F0080340: 133c0445                 sethi   %hi(dword_F0111674), %o1
F0080344: d2026274                 ld      [%o1+%lo(dword_F0111674)], %o1
F0080348: 80a20009                 cmp     %o0, %o1
F008034C: 02800005                 be      loc_F0080360
F0080350: a404202c                 add     %l0, 0x2C, %l2 ! ','
F0080354: 90103ed0                 mov     -0x130, %o0
F0080358: 10800066                 ba      locret_F00804F0
F008035C: d024201c                 st      %o0, [%l0+0x1C]
F0080360: e427b814                 st      %l2, [%fp+var_7EC]
F0080364: 90102019                 mov     0x19, %o0
F0080368: d206201c                 ld      [%i0+0x1C], %o1
F008036C: 80a26019                 cmp     %o1, 0x19
F0080370: 1a800003                 bcc     loc_F008037C
F0080374: d027b810                 st      %o0, [%fp+var_7F0]
F0080378: d227b810                 st      %o1, [%fp+var_7F0]
F008037C: a607b818                 add     %fp, var_7E8, %l3
F0080380: e627b80c                 st      %l3, [%fp+var_7F4]
F0080384: 90102038                 mov     0x38, %o0 ! '8'
F0080388: d2062024                 ld      [%i0+0x24], %o1
F008038C: 80a26038                 cmp     %o1, 0x38 ! '8'
F0080390: 1a800003                 bcc     loc_F008039C
F0080394: d027b808                 st      %o0, [%fp+var_7F8]
F0080398: d227b808                 st      %o1, [%fp+var_7F8]
F008039C: 7fff93bc                 call    _convert_port_to_host
F00803A0: d0062008                 ld      [%i0+8], %o0
F00803A4: 9207b814                 add     %fp, var_7EC, %o1
F00803A8: 9407b810                 add     %fp, var_7F0, %o2
F00803AC: 9607b80c                 add     %fp, var_7F4, %o3
F00803B0: 7fffe47f                 call    _host_zone_info
F00803B4: 9807b808                 add     %fp, var_7F8, %o4
F00803B8: 80a22000                 cmp     %o0, 0
F00803BC: 1280004d                 bne     locret_F00804F0
F00803C0: d024201c                 st      %o0, [%l0+0x1C]
F00803C4: 133c0445                 sethi   %hi(dword_F0111678), %o1
F00803C8: d0026278                 ld      [%o1+%lo(dword_F0111678)], %o0
F00803CC: d0242020                 st      %o0, [%l0+0x20]
F00803D0: 92126278                 bset    %lo(dword_F0111678), %o1
F00803D4: d0026004                 ld      [%o1+4], %o0
F00803D8: a2102001                 mov     1, %l1
F00803DC: d407b814                 ld      [%fp+var_7EC], %o2
F00803E0: d0242024                 st      %o0, [%l0+0x24]
F00803E4: d0026008                 ld      [%o1+8], %o0
F00803E8: 80a28012                 cmp     %o2, %l2
F00803EC: 02800008                 be      loc_F008040C
F00803F0: d0242028                 st      %o0, [%l0+0x28]
F00803F4: d424202c                 st      %o2, [%l0+0x2C]
F00803F8: d0042020                 ld      [%l0+0x20], %o0
F00803FC: a2102000                 mov     0, %l1
F0080400: 900a3ff7                 and     %o0, -9, %o0
F0080404: 90122002                 bset    2, %o0
F0080408: d0242020                 st      %o0, [%l0+0x20]
F008040C: d007b810                 ld      [%fp+var_7F0], %o0
F0080410: 94102004                 mov     4, %o2
F0080414: 932a2002                 sll     %o0, 2, %o1
F0080418: 92024008                 add     %o1, %o0, %o1
F008041C: 932a6004                 sll     %o1, 4, %o1
F0080420: d0042020                 ld      [%l0+0x20], %o0
F0080424: 808a2008                 btst    8, %o0
F0080428: 02800003                 be      loc_F0080434
F008042C: d2242028                 st      %o1, [%l0+0x28]
F0080430: 94100009                 mov     %o1, %o2
F0080434: b002a038                 add     %o2, 0x38, %i0 ! '8'
F0080438: 113c0445                 sethi   %hi(dword_F0111684), %o0
F008043C: d2022284                 ld      [%o0+%lo(dword_F0111684)], %o1
F0080440: 9404000a                 add     %l0, %o2, %o2
F0080444: d222a02c                 st      %o1, [%o2+0x2C]
F0080448: 90122284                 bset    %lo(dword_F0111684), %o0
F008044C: d2022004                 ld      [%o0+4], %o1
F0080450: a002b830                 add     %o2, -0x7D0, %l0
F0080454: d807b80c                 ld      [%fp+var_7F4], %o4
F0080458: d222a030                 st      %o1, [%o2+0x30]
F008045C: d0022008                 ld      [%o0+8], %o0
F0080460: 80a30013                 cmp     %o4, %l3
F0080464: 02800009                 be      loc_F0080488
F0080468: d022a034                 st      %o0, [%o2+0x34]
F008046C: d822a038                 st      %o4, [%o2+0x38]
F0080470: d002a02c                 ld      [%o2+0x2C], %o0
F0080474: a2102000                 mov     0, %l1
F0080478: 900a3ff7                 and     %o0, -9, %o0
F008047C: 90122002                 bset    2, %o0
F0080480: 10800009                 ba      loc_F00804A4
F0080484: d022a02c                 st      %o0, [%o2+0x2C]
F0080488: 9002a038                 add     %o2, 0x38, %o0 ! '8'! __dst
F008048C: d607b808                 ld      [%fp+var_7F8], %o3
F0080490: 9210000c                 mov     %o4, %o1! __src
F0080494: 952ae003                 sll     %o3, 3, %o2
F0080498: 9402800b                 add     %o2, %o3, %o2! __n
F008049C: 7ffe1b81                 call    _memcpy
F00804A0: 952aa002                 sll     %o2, 2, %o2
F00804A4: d007b808                 ld      [%fp+var_7F8], %o0
F00804A8: 932a2003                 sll     %o0, 3, %o1
F00804AC: 92024008                 add     %o1, %o0, %o1
F00804B0: d00427fc                 ld      [%l0+0x7FC], %o0
F00804B4: 808a2008                 btst    8, %o0
F00804B8: 02800005                 be      loc_F00804CC
F00804BC: d2242804                 st      %o1, [%l0+0x804]
F00804C0: 912a6002                 sll     %o1, 2, %o0
F00804C4: 10800003                 ba      loc_F00804D0
F00804C8: b0060008                 add     %i0, %o0, %i0
F00804CC: b0062004                 inc     4, %i0
F00804D0: 80a46000                 cmp     %l1, 0
F00804D4: 12800006                 bne     loc_F00804EC
F00804D8: a0100019                 mov     %i1, %l0
F00804DC: d0040000                 ld      [%l0], %o0
F00804E0: 13200000                 sethi   0x80000000, %o1
F00804E4: 90120009                 bset    %o1, %o0
F00804E8: d0240000                 st      %o0, [%l0]
F00804EC: f0242004                 st      %i0, [%l0+4]
F00804F0: 81c7e008                 ret
F00804F4: 81e80000                 restore
