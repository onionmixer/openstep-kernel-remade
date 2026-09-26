F00D62E4: 9de3bf90                 save    %sp, -0x70, %sp
F00D62E8: 133c0505                 sethi   %hi(paDeviceflags), %o1
F00D62EC: 9606a010                 add     %i2, 0x10, %o3
F00D62F0: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D62F4: 94102001                 mov     1, %o2
F00D62F8: d2026254                 ld      [%o1+%lo(paDeviceflags)], %o1! SEL
F00D62FC: 40006d5d                 call    _objc_msgSend
F00D6300: a12a800b                 sll     %o2, %o3, %l0
F00D6304: 932ea002                 sll     %i2, 2, %o1
F00D6308: 92060009                 add     %i0, %o1, %o1
F00D630C: d402608c                 ld      [%o1+0x8C], %o2
F00D6310: a42a0010                 andn    %o0, %l0, %l2
F00D6314: 80a2a000                 cmp     %o2, 0
F00D6318: 02800024                 be      loc_F00D63A8
F00D631C: d0162004                 lduh    [%i0+4], %o0
F00D6320: 80a22000                 cmp     %o0, 0
F00D6324: 02800007                 be      loc_F00D6340
F00D6328: 96102000                 mov     0, %o3
F00D632C: d8528000                 ldsh    [%o2], %o4
F00D6330: 10800006                 ba      loc_F00D6348
F00D6334: 9402a002                 inc     2, %o2
F00D6338: 1080001d                 ba      loc_F00D63AC
F00D633C: 90102001                 mov     1, %o0
F00D6340: d80a8000                 ldub    [%o2], %o4
F00D6344: 9402a001                 inc     %o2
F00D6348: 80a2c00c                 cmp     %o3, %o4
F00D634C: 36800018                 bge,a   loc_F00D63AC
F00D6350: 90102000                 mov     0, %o0
F00D6354: 912a2010                 sll     %o0, 16, %o0
F00D6358: 9b3a2010                 sra     %o0, 16, %o5
F00D635C: 84102001                 mov     1, %g2
F00D6360: 80a36000                 cmp     %o5, 0
F00D6364: 22800005                 be,a    loc_F00D6378
F00D6368: d20a8000                 ldub    [%o2], %o1
F00D636C: d2528000                 ldsh    [%o2], %o1
F00D6370: 10800003                 ba      loc_F00D637C
F00D6374: 9402a002                 inc     2, %o2
F00D6378: 9402a001                 inc     %o2
F00D637C: 91326005                 srl     %o1, 5, %o0
F00D6380: 912a2002                 sll     %o0, 2, %o0
F00D6384: 920a601f                 and     %o1, 0x1F, %o1
F00D6388: d006c008                 ld      [%i3+%o0], %o0
F00D638C: 93288009                 sll     %g2, %o1, %o1
F00D6390: 808a0009                 btst    %o1, %o0
F00D6394: 12bfffe9                 bne     loc_F00D6338
F00D6398: 9602e001                 inc     %o3
F00D639C: 80a2c00c                 cmp     %o3, %o4
F00D63A0: 06bffff1                 bl      loc_F00D6364
F00D63A4: 80a36000                 cmp     %o5, 0
F00D63A8: 90102000                 mov     0, %o0
F00D63AC: 80a22000                 cmp     %o0, 0
F00D63B0: 32800002                 bne,a   loc_F00D63B8
F00D63B4: a4148010                 bset    %l0, %l2
F00D63B8: 80a6a001                 cmp     %i2, 1
F00D63BC: 1280003e                 bne     loc_F00D64B4
F00D63C0: 80a6a000                 cmp     %i2, 0
F00D63C4: 11000400                 sethi   0x100000, %o0
F00D63C8: 808c8008                 btst    %o0, %l2
F00D63CC: 0280002a                 be      loc_F00D6474
F00D63D0: 133c0505                 sethi   -0xFEBEC00, %o1
F00D63D4: d006208c                 ld      [%i0+0x8C], %o0
F00D63D8: 80a22000                 cmp     %o0, 0
F00D63DC: 32800027                 bne,a   loc_F00D6478
F00D63E0: 15000040                 sethi   0x10000, %o2
F00D63E4: d21624e0                 lduh    [%i0+0x4E0], %o1
F00D63E8: 1100003f901223ff         set     0xFFFF, %o0
F00D63F0: 80a24008                 cmp     %o1, %o0
F00D63F4: 32800020                 bne,a   loc_F00D6474
F00D63F8: 133c0505                 sethi   -0xFEBEC00, %o1
F00D63FC: 808c8010                 btst    %l0, %l2
F00D6400: 02800006                 be      loc_F00D6418
F00D6404: 94102000                 mov     0, %o2
F00D6408: d00624f8                 ld      [%i0+0x4F8], %o0
F00D640C: 133c0505                 sethi   %hi(paSetcharkeyacti), %o1
F00D6410: 10800016                 ba      loc_F00D6468
F00D6414: d2026250                 ld      [%o1+%lo(paSetcharkeyacti)], %o1
F00D6418: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D641C: 133c0505                 sethi   %hi(paCharkeyactive), %o1! SEL
F00D6420: 40006d14                 call    _objc_msgSend
F00D6424: d202624c                 ld      [%o1+%lo(paCharkeyactive)], %o1
F00D6428: 912a2018                 sll     %o0, 24, %o0
F00D642C: 80a22000                 cmp     %o0, 0
F00D6430: 12800011                 bne     loc_F00D6474
F00D6434: 133c0505                 sethi   -0xFEBEC00, %o1
F00D6438: 113c0505                 sethi   %hi(paAlphalock), %o0
F00D643C: d2022248                 ld      [%o0+%lo(paAlphalock)], %o1! SEL
F00D6440: e00624f8                 ld      [%i0+0x4F8], %l0
F00D6444: 113c0505                 sethi   %hi(paSetalphalock), %o0! id
F00D6448: e2022244                 ld      [%o0+%lo(paSetalphalock)], %l1
F00D644C: 40006d09                 call    _objc_msgSend
F00D6450: 90100010                 mov     %l0, %o0
F00D6454: 952a2018                 sll     %o0, 24, %o2
F00D6458: 90100010                 mov     %l0, %o0! id
F00D645C: 92100011                 mov     %l1, %o1! SEL
F00D6460: 80a0000a                 cmp     %g0, %o2
F00D6464: 94603fff                 subc    %g0, -1, %o2
F00D6468: 40006d02                 call    _objc_msgSend
F00D646C: 01000000                 nop
F00D6470: 133c0505                 sethi   -0xFEBEC00, %o1
F00D6474: 15000040                 sethi   0x10000, %o2
F00D6478: a22c800a                 andn    %l2, %o2, %l1
F00D647C: 15000080                 sethi   0x20000, %o2
F00D6480: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D6484: 940c800a                 and     %l2, %o2, %o2
F00D6488: d2026248                 ld      [%o1+0x248], %o1! SEL
F00D648C: 40006cf9                 call    _objc_msgSend
F00D6490: a132a001                 srl     %o2, 1, %l0
F00D6494: 912a2018                 sll     %o0, 24, %o0
F00D6498: 913a2018                 sra     %o0, 24, %o0
F00D649C: 80a22001                 cmp     %o0, 1
F00D64A0: 1280000c                 bne     loc_F00D64D0
F00D64A4: a4144010                 or      %l1, %l0, %l2
F00D64A8: 11000040                 sethi   0x10000, %o0
F00D64AC: 10800009                 ba      loc_F00D64D0
F00D64B0: a4144008                 or      %l1, %o0, %l2
F00D64B4: 12800008                 bne     loc_F00D64D4
F00D64B8: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D64BC: 133c0505                 sethi   %hi(paSetalphalock), %o1
F00D64C0: 9534a010                 srl     %l2, 16, %o2
F00D64C4: d2026244                 ld      [%o1+%lo(paSetalphalock)], %o1! SEL
F00D64C8: 40006cea                 call    _objc_msgSend
F00D64CC: 940aa001                 and     %o2, 1, %o2
F00D64D0: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D64D4: 133c0505                 sethi   %hi(paSetdeviceflags), %o1
F00D64D8: d2026240                 ld      [%o1+%lo(paSetdeviceflags)], %o1! SEL
F00D64DC: 40006ce5                 call    _objc_msgSend
F00D64E0: 94100012                 mov     %l2, %o2
F00D64E4: 81c7e008                 ret
F00D64E8: 81e80000                 restore
