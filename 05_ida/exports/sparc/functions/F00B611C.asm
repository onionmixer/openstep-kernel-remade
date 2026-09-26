F00B611C: 9de3bf98                 save    %sp, -0x68, %sp
F00B6120: a2100018                 mov     %i0, %l1
F00B6124: d05460b2                 ldsh    [%l1+0xB2], %o0
F00B6128: d80c6054                 ldub    [%l1+0x54], %o4
F00B612C: 912a2002                 sll     %o0, 2, %o0
F00B6130: 90020011                 add     %o0, %l1, %o0
F00B6134: e40220b8                 ld      [%o0+0xB8], %l2
F00B6138: b0102000                 mov     0, %i0
F00B613C: 808b2080                 btst    0x80, %o4
F00B6140: 0280001c                 be      loc_F00B61B0
F00B6144: e814a008                 lduh    [%l2+8], %l4
F00B6148: 900b2058                 and     %o4, 0x58, %o0
F00B614C: 80a00008                 cmp     %g0, %o0
F00B6150: 90402000                 addc    %g0, 0, %o0
F00B6154: 80a22000                 cmp     %o0, 0
F00B6158: a0100008                 mov     %o0, %l0
F00B615C: 113c0479                 sethi   %hi(aSMessage0xXFro), %o0! "%s message 0x%x from Target %d"
F00B6160: 02800005                 be      loc_F00B6174
F00B6164: 941223f8                 or      %o0, %lo(aSMessage0xXFro), %o2! "%s message 0x%x from Target %d"
F00B6168: 113c047a                 sethi   %hi(aGarbled), %o0! "Garbled"
F00B616C: 10800004                 ba      loc_F00B617C
F00B6170: 96122018                 or      %o0, %lo(aGarbled), %o3! "Garbled"
F00B6174: 113c047a96122020         set     aIdentify, %o3! "Identify"
F00B617C: 90100011                 mov     %l1, %o0
F00B6180: 92102003                 mov     3, %o1
F00B6184: 4000069a                 call    _esplog
F00B6188: 9a100014                 mov     %l4, %o5
F00B618C: 80a42000                 cmp     %l0, 0
F00B6190: 22800004                 be,a    loc_F00B61A0
F00B6194: d00c6041                 ldub    [%l1+0x41], %o0
F00B6198: 10800098                 ba      locret_F00B63F8! jumptable F00B6210 case 8
F00B619C: b0102005                 mov     5, %i0
F00B61A0: d02c6042                 stb     %o0, [%l1+0x42]
F00B61A4: 9010201a                 mov     0x1A, %o0
F00B61A8: 10800094                 ba      locret_F00B63F8! jumptable F00B6210 case 8
F00B61AC: d02c6041                 stb     %o0, [%l1+0x41]
F00B61B0: 900b20f0                 and     %o4, 0xF0, %o0
F00B61B4: 80a22020                 cmp     %o0, 0x20 ! ' '
F00B61B8: 02800005                 be      loc_F00B61CC
F00B61BC: 920b20ff                 and     %o4, 0xFF, %o1
F00B61C0: 80a26001                 cmp     %o1, 1
F00B61C4: 3280000a                 bne,a   loc_F00B61EC
F00B61C8: d00c6041                 ldub    [%l1+0x41], %o0
F00B61CC: 90102002                 mov     2, %o0
F00B61D0: d02c605c                 stb     %o0, [%l1+0x5C]
F00B61D4: d00c6041                 ldub    [%l1+0x41], %o0
F00B61D8: b0102000                 mov     0, %i0
F00B61DC: d02c6042                 stb     %o0, [%l1+0x42]
F00B61E0: 90102006                 mov     6, %o0
F00B61E4: 10800085                 ba      locret_F00B63F8! jumptable F00B6210 case 8
F00B61E8: d02c6041                 stb     %o0, [%l1+0x41]
F00B61EC: 80a2600b                 cmp     %o1, 0xB! switch 12 cases
F00B61F0: d02c6042                 stb     %o0, [%l1+0x42]
F00B61F4: 9010201a                 mov     0x1A, %o0
F00B61F8: 18800075                 bgu     def_F00B6210! jumptable F00B6210 default case, cases 1,5,6,9
F00B61FC: d02c6041                 stb     %o0, [%l1+0x41]
F00B6200: 113c02d890122218         set     jpt_F00B6210, %o0
F00B6208: 932a6002                 sll     %o1, 2, %o1
F00B620C: d0024008                 ld      [%o1+%o0], %o0
F00B6210: 81c20000                 jmp     %o0! switch jump
F00B6214: 01000000                 nop
F00B6248: d004a014                 ld      [%l2+0x14], %o0! jumptable F00B6210 case 4
F00B624C: 808a2002                 btst    2, %o0
F00B6250: 02800005                 be      loc_F00B6264
F00B6254: 90102008                 mov     8, %o0
F00B6258: 10800068                 ba      locret_F00B63F8! jumptable F00B6210 case 8
F00B625C: b0102007                 mov     7, %i0
F00B6260: 90102008                 mov     8, %o0! jumptable F00B6210 cases 0,10,11
F00B6264: 10800065                 ba      locret_F00B63F8! jumptable F00B6210 case 8
F00B6268: d02c6041                 stb     %o0, [%l1+0x41]
F00B626C: a6102000                 mov     0, %l3! jumptable F00B6210 case 7
F00B6270: d40c6052                 ldub    [%l1+0x52], %o2
F00B6274: 9202bfff                 add     %o2, -1, %o1
F00B6278: 80a26008                 cmp     %o1, 8! switch 9 cases
F00B627C: 18800025                 bgu     def_F00B6294! jumptable F00B6294 default case, cases 1-3
F00B6280: b0102006                 mov     6, %i0
F00B6284: 113c02d89012229c         set     jpt_F00B6294, %o0
F00B628C: 932a6002                 sll     %o1, 2, %o1
F00B6290: d0024008                 ld      [%o1+%o0], %o0
F00B6294: 81c20000                 jmp     %o0! switch jump
F00B6298: 01000000                 nop
F00B62C0: c02c6046                 clrb    [%l1+0x46]! jumptable F00B6294 case 0
F00B62C4: 90044014                 add     %l1, %l4, %o0
F00B62C8: c02a205e                 clrb    [%o0+0x5E]
F00B62CC: b0102000                 mov     0, %i0
F00B62D0: 90102001                 mov     1, %o0
F00B62D4: d20c6078                 ldub    [%l1+0x78], %o1
F00B62D8: 912a0014                 sll     %o0, %l4, %o0
F00B62DC: 92124008                 bset    %o0, %o1
F00B62E0: 10800019                 ba      loc_F00B6344
F00B62E4: d22c6078                 stb     %o1, [%l1+0x78]
F00B62E8: 10800017                 ba      loc_F00B6344! jumptable F00B6294 case 7
F00B62EC: a6102010                 mov     0x10, %l3
F00B62F0: 10800015                 ba      loc_F00B6344! jumptable F00B6294 case 4
F00B62F4: a610200d                 mov     0xD, %l3
F00B62F8: 10800013                 ba      loc_F00B6344! jumptable F00B6294 case 8
F00B62FC: a6102011                 mov     0x11, %l3
F00B6300: 10800011                 ba      loc_F00B6344! jumptable F00B6294 case 6
F00B6304: a610200f                 mov     0xF, %l3
F00B6308: 1080000e                 ba      loc_F00B6340! jumptable F00B6294 case 5
F00B630C: a610200e                 mov     0xE, %l3
F00B6310: 900aa098                 and     %o2, 0x98, %o0! jumptable F00B6294 default case, cases 1-3
F00B6314: 80a22080                 cmp     %o0, 0x80
F00B6318: 02800008                 be      loc_F00B6338
F00B631C: 80a2a0ff                 cmp     %o2, 0xFF
F00B6320: 32800008                 bne,a   loc_F00B6340
F00B6324: a6102003                 mov     3, %l3
F00B6328: d00c6053                 ldub    [%l1+0x53], %o0
F00B632C: 80a22000                 cmp     %o0, 0
F00B6330: 32800004                 bne,a   loc_F00B6340
F00B6334: a6102003                 mov     3, %l3
F00B6338: 10800003                 ba      loc_F00B6344
F00B633C: b0102000                 mov     0, %i0
F00B6340: b0103ffa                 mov     -6, %i0
F00B6344: 80a62000                 cmp     %i0, 0
F00B6348: 0280002c                 be      locret_F00B63F8! jumptable F00B6210 case 8
F00B634C: 9010000a                 mov     %o2, %o0
F00B6350: 213c047a                 sethi   %hi(aTargetDRejects), %l0! "Target %d rejects our message '%s'"
F00B6354: 40000c21                 call    _scsi_mname
F00B6358: a0142030                 bset    %lo(aTargetDRejects), %l0! "Target %d rejects our message '%s'"
F00B635C: 98100008                 mov     %o0, %o4
F00B6360: 90100011                 mov     %l1, %o0
F00B6364: 92102004                 mov     4, %o1
F00B6368: 94100010                 mov     %l0, %o2
F00B636C: 40000620                 call    _esplog
F00B6370: 96100014                 mov     %l4, %o3
F00B6374: d00ca028                 ldub    [%l2+0x28], %o0
F00B6378: 80a22000                 cmp     %o0, 0
F00B637C: 2280001f                 be,a    locret_F00B63F8! jumptable F00B6210 case 8
F00B6380: e62ca028                 stb     %l3, [%l2+0x28]
F00B6384: 3080001d                 ba,a    locret_F00B63F8! jumptable F00B6210 case 8
F00B6388: d004a020                 ld      [%l2+0x20], %o0! jumptable F00B6210 case 3
F00B638C: d204a01c                 ld      [%l2+0x1C], %o1
F00B6390: d404a034                 ld      [%l2+0x34], %o2
F00B6394: d024a02c                 st      %o0, [%l2+0x2C]
F00B6398: d004a038                 ld      [%l2+0x38], %o0
F00B639C: 80a28008                 cmp     %o2, %o0
F00B63A0: 02800016                 be      locret_F00B63F8! jumptable F00B6210 case 8
F00B63A4: d224a030                 st      %o1, [%l2+0x30]
F00B63A8: d024a034                 st      %o0, [%l2+0x34]
F00B63AC: d014a05c                 lduh    [%l2+0x5C], %o0
F00B63B0: 13000004                 sethi   0x1000, %o1
F00B63B4: 90120009                 bset    %o1, %o0
F00B63B8: 10800010                 ba      locret_F00B63F8! jumptable F00B6210 case 8
F00B63BC: d034a05c                 sth     %o0, [%l2+0x5C]
F00B63C0: d004a034                 ld      [%l2+0x34], %o0! jumptable F00B6210 case 2
F00B63C4: 1080000d                 ba      locret_F00B63F8! jumptable F00B6210 case 8
F00B63C8: d024a038                 st      %o0, [%l2+0x38]
F00B63CC: b0102007                 mov     7, %i0! jumptable F00B6210 default case, cases 1,5,6,9
F00B63D0: 9010000c                 mov     %o4, %o0
F00B63D4: 213c047a                 sethi   %hi(aRejectingMessa), %l0! "Rejecting message '%s' from Target %d"
F00B63D8: 40000c00                 call    _scsi_mname
F00B63DC: a0142058                 bset    %lo(aRejectingMessa), %l0! "Rejecting message '%s' from Target %d"
F00B63E0: 96100008                 mov     %o0, %o3
F00B63E4: 90100011                 mov     %l1, %o0
F00B63E8: 92102005                 mov     5, %o1
F00B63EC: 94100010                 mov     %l0, %o2
F00B63F0: 400005ff                 call    _esplog
F00B63F4: 98100014                 mov     %l4, %o4
F00B63F8: 81c7e008                 ret! jumptable F00B6210 case 8
F00B63FC: 81e80000                 restore
