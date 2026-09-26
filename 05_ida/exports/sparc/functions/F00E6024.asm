F00E6024: 9de3bf98                 save    %sp, -0x68, %sp
F00E6028: 80a6200f                 cmp     %i0, 0xF
F00E602C: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E6030: 912e2004                 sll     %i0, 4, %o0
F00E6034: 90020018                 add     %o0, %i0, %o0
F00E6038: 912a2002                 sll     %o0, 2, %o0
F00E603C: d2026364                 ld      [%o1+%lo(_sparcfbs)], %o1
F00E6040: 90022008                 inc     8, %o0
F00E6044: 18800006                 bgu     loc_F00E605C
F00E6048: a8024008                 add     %o1, %o0, %l4
F00E604C: d0024008                 ld      [%o1+%o0], %o0
F00E6050: 80a22000                 cmp     %o0, 0
F00E6054: 12800004                 bne     loc_F00E6064
F00E6058: 113c04bb                 sethi   -0xFED1400, %o0
F00E605C: 1080007e                 ba      locret_F00E6254
F00E6060: b0103d40                 mov     -0x2C0, %i0
F00E6064: e6022368                 ld      [%o0+0x368], %l3
F00E6068: 80a4e000                 cmp     %l3, 0
F00E606C: 0280000c                 be      loc_F00E609C
F00E6070: ae102000                 mov     0, %l7
F00E6074: d004c000                 ld      [%l3], %o0
F00E6078: 80a22000                 cmp     %o0, 0
F00E607C: 12800008                 bne     loc_F00E609C
F00E6080: 80a4e000                 cmp     %l3, 0
F00E6084: ae100013                 mov     %l3, %l7
F00E6088: e604e008                 ld      [%l3+8], %l3
F00E608C: 80a4e000                 cmp     %l3, 0
F00E6090: 32bffffa                 bne,a   loc_F00E6078
F00E6094: d004c000                 ld      [%l3], %o0
F00E6098: 80a4e000                 cmp     %l3, 0
F00E609C: 0280006e                 be      locret_F00E6254
F00E60A0: b0103d3e                 mov     -0x2C2, %i0
F00E60A4: d204e00c                 ld      [%l3+0xC], %o1
F00E60A8: d0052034                 ld      [%l4+0x34], %o0
F00E60AC: 80a24008                 cmp     %o1, %o0
F00E60B0: 22800003                 be,a    loc_F00E60BC
F00E60B4: f014e014                 lduh    [%l3+0x14], %i0
F00E60B8: 30800067                 ba,a    locret_F00E6254
F00E60BC: e414e016                 lduh    [%l3+0x16], %l2
F00E60C0: d0052038                 ld      [%l4+0x38], %o0! int
F00E60C4: e014e012                 lduh    [%l3+0x12], %l0
F00E60C8: d2052034                 ld      [%l4+0x34], %o1! int
F00E60CC: 7ffc814f                 call    _div
F00E60D0: ec14e010                 lduh    [%l3+0x10], %l6
F00E60D4: d2052034                 ld      [%l4+0x34], %o1
F00E60D8: 80a26001                 cmp     %o1, 1
F00E60DC: 02800007                 be      loc_F00E60F8
F00E60E0: aa220018                 sub     %o0, %i0, %l5
F00E60E4: 80a26004                 cmp     %o1, 4
F00E60E8: 02800020                 be      loc_F00E6168
F00E60EC: a204e01c                 add     %l3, 0x1C, %l1
F00E60F0: 10800039                 ba      loc_F00E61D4
F00E60F4: 80a5e000                 cmp     %l7, 0
F00E60F8: a204e01c                 add     %l3, 0x1C, %l1
F00E60FC: d2052038                 ld      [%l4+0x38], %o1
F00E6100: 7ffc8100                 call    _umul
F00E6104: 90100010                 mov     %l0, %o0
F00E6108: 94100008                 mov     %o0, %o2
F00E610C: e0052014                 ld      [%l4+0x14], %l0
F00E6110: 90100016                 mov     %l6, %o0
F00E6114: d2052034                 ld      [%l4+0x34], %o1
F00E6118: 7ffc80fa                 call    _umul
F00E611C: a004000a                 add     %l0, %o2, %l0
F00E6120: a484bfff                 inccc   -1, %l2
F00E6124: 0c80002b                 bneg    loc_F00E61D0
F00E6128: a0040008                 add     %l0, %o0, %l0
F00E612C: f014e014                 lduh    [%l3+0x14], %i0
F00E6130: b0863fff                 inccc   -1, %i0
F00E6134: 2c800009                 bneg,a  loc_F00E6158
F00E6138: a484bfff                 inccc   -1, %l2
F00E613C: d00c4000                 ldub    [%l1], %o0
F00E6140: b0863fff                 inccc   -1, %i0
F00E6144: d02c0000                 stb     %o0, [%l0]
F00E6148: a2046001                 inc     %l1
F00E614C: 1cbffffc                 bpos    loc_F00E613C
F00E6150: a0042001                 inc     %l0
F00E6154: a484bfff                 inccc   -1, %l2
F00E6158: 1cbffff5                 bpos    loc_F00E612C
F00E615C: a0040015                 add     %l0, %l5, %l0
F00E6160: 1080001d                 ba      loc_F00E61D4
F00E6164: 80a5e000                 cmp     %l7, 0
F00E6168: d2052038                 ld      [%l4+0x38], %o1
F00E616C: 7ffc80e5                 call    _umul
F00E6170: 90100010                 mov     %l0, %o0
F00E6174: 94100008                 mov     %o0, %o2
F00E6178: e0052018                 ld      [%l4+0x18], %l0
F00E617C: 90100016                 mov     %l6, %o0
F00E6180: d2052034                 ld      [%l4+0x34], %o1
F00E6184: 7ffc80df                 call    _umul
F00E6188: a004000a                 add     %l0, %o2, %l0
F00E618C: a484bfff                 inccc   -1, %l2
F00E6190: 0c800010                 bneg    loc_F00E61D0
F00E6194: a0040008                 add     %l0, %o0, %l0
F00E6198: 932d6002                 sll     %l5, 2, %o1
F00E619C: f014e014                 lduh    [%l3+0x14], %i0
F00E61A0: b0863fff                 inccc   -1, %i0
F00E61A4: 2c800009                 bneg,a  loc_F00E61C8
F00E61A8: a484bfff                 inccc   -1, %l2
F00E61AC: d0044000                 ld      [%l1], %o0
F00E61B0: b0863fff                 inccc   -1, %i0
F00E61B4: d0240000                 st      %o0, [%l0]
F00E61B8: a2046004                 inc     4, %l1
F00E61BC: 1cbffffc                 bpos    loc_F00E61AC
F00E61C0: a0042004                 inc     4, %l0
F00E61C4: a484bfff                 inccc   -1, %l2
F00E61C8: 1cbffff5                 bpos    loc_F00E619C
F00E61CC: a0040009                 add     %l0, %o1, %l0
F00E61D0: 80a5e000                 cmp     %l7, 0
F00E61D4: 22800005                 be,a    loc_F00E61E8
F00E61D8: d204e008                 ld      [%l3+8], %o1
F00E61DC: d004e008                 ld      [%l3+8], %o0
F00E61E0: 10800004                 ba      loc_F00E61F0
F00E61E4: d025e008                 st      %o0, [%l7+8]
F00E61E8: 113c04bb                 sethi   %hi(dword_F012EF68), %o0
F00E61EC: d2222368                 st      %o1, [%o0+%lo(dword_F012EF68)]
F00E61F0: 173c04bb                 sethi   %hi(dword_F012EF74), %o3
F00E61F4: d002e374                 ld      [%o3+%lo(dword_F012EF74)], %o0
F00E61F8: 80a22009                 cmp     %o0, 9
F00E61FC: 04800010                 ble     loc_F00E623C
F00E6200: 153c04bb                 sethi   -0xFED1400, %o2
F00E6204: 113c04cc901220e4         set     unk_F01330E4, %o0
F00E620C: 80a4c008                 cmp     %l3, %o0
F00E6210: 12800006                 bne     loc_F00E6228
F00E6214: 113c04d1                 sethi   -0xFECBC00, %o0
F00E6218: 133c04bb                 sethi   %hi(dword_F012EF78), %o1
F00E621C: 90102c04                 mov     0xC04, %o0
F00E6220: 1080000c                 ba      loc_F00E6250
F00E6224: d0226378                 st      %o0, [%o1+%lo(dword_F012EF78)]
F00E6228: d0022340                 ld      [%o0+0x340], %o0
F00E622C: 7ffe7596                 call    _kmem_free
F00E6230: 92100013                 mov     %l3, %o1
F00E6234: 10800008                 ba      locret_F00E6254
F00E6238: b0102000                 mov     0, %i0
F00E623C: d202a36c                 ld      [%o2+0x36C], %o1
F00E6240: 90022001                 inc     %o0
F00E6244: d022e374                 st      %o0, [%o3+0x374]
F00E6248: d224e008                 st      %o1, [%l3+8]
F00E624C: e622a36c                 st      %l3, [%o2+0x36C]
F00E6250: b0102000                 mov     0, %i0
F00E6254: 81c7e008                 ret
F00E6258: 81e80000                 restore
