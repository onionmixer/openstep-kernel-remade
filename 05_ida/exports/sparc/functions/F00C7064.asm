F00C7064: 9de3bf68                 save    %sp, -0x98, %sp
F00C7068: 9010001a                 mov     %i2, %o0! id
F00C706C: ac102000                 mov     0, %l6
F00C7070: a8102000                 mov     0, %l4
F00C7074: b8102000                 mov     0, %i4
F00C7078: ba102000                 mov     0, %i5
F00C707C: 133c0506                 sethi   %hi(paDirectdevice), %o1
F00C7080: d2026190                 ld      [%o1+%lo(paDirectdevice)], %o1! SEL
F00C7084: 4000a9fb                 call    _objc_msgSend
F00C7088: c02fbfcf                 clrb    [%fp+var_31]
F00C708C: 133c0504                 sethi   %hi(paName), %o1! SEL
F00C7090: a4100008                 mov     %o0, %l2
F00C7094: 4000a9f7                 call    _objc_msgSend
F00C7098: d2026008                 ld      [%o1+%lo(paName)], %o1
F00C709C: 133c0506                 sethi   %hi(paIsphysical_0), %o1
F00C70A0: a6100008                 mov     %o0, %l3
F00C70A4: d202618c                 ld      [%o1+%lo(paIsphysical_0)], %o1! SEL
F00C70A8: 4000a9f2                 call    _objc_msgSend
F00C70AC: 90100012                 mov     %l2, %o0
F00C70B0: 912a2018                 sll     %o0, 24, %o0
F00C70B4: 80a22000                 cmp     %o0, 0
F00C70B8: 12800004                 bne     loc_F00C70C8
F00C70BC: 113c0506                 sethi   -0xFEBE800, %o0! id
F00C70C0: 108000fc                 ba      locret_F00C74B0
F00C70C4: b0102000                 mov     0, %i0
F00C70C8: d2022198                 ld      [%o0+0x198], %o1! SEL
F00C70CC: 4000a9e9                 call    _objc_msgSend
F00C70D0: 90100012                 mov     %l2, %o0! id
F00C70D4: 80a22000                 cmp     %o0, 0
F00C70D8: 0280000a                 be      loc_F00C7100
F00C70DC: a2100008                 mov     %o0, %l1
F00C70E0: 133c0506                 sethi   %hi(paConnecttophysi), %o1
F00C70E4: d2026188                 ld      [%o1+%lo(paConnecttophysi)], %o1! SEL
F00C70E8: 4000a9e2                 call    _objc_msgSend
F00C70EC: 94100012                 mov     %l2, %o2
F00C70F0: c02c61a8                 clrb    [%l1+0x1A8]
F00C70F4: c02c61a9                 clrb    [%l1+0x1A9]
F00C70F8: 10800043                 ba      loc_F00C7204
F00C70FC: c02c61aa                 clrb    [%l1+0x1AA]
F00C7100: 113c0506                 sethi   %hi(paIodiskpartitio_1), %o0
F00C7104: d00222f4                 ld      [%o0+%lo(paIodiskpartitio_1)], %o0! id
F00C7108: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00C710C: 4000a9d9                 call    _objc_msgSend
F00C7110: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00C7114: a2100008                 mov     %o0, %l1
F00C7118: a007bfd0                 add     %fp, var_30, %l0
F00C711C: 90100010                 mov     %l0, %o0! char *
F00C7120: 133c03eb92126010         set     aSa, %o1! "%sa"
F00C7128: 7ffd3590                 call    _sprintf
F00C712C: 94100013                 mov     %l3, %o2
F00C7130: 90100011                 mov     %l1, %o0! id
F00C7134: 133c0504                 sethi   %hi(paSetname), %o1
F00C7138: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00C713C: 4000a9cd                 call    _objc_msgSend
F00C7140: 94100010                 mov     %l0, %o2
F00C7144: 90100011                 mov     %l1, %o0! id
F00C7148: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00C714C: 153c03eb                 sethi   %hi(aIodiskpartitio), %o2! "IODiskPartition"
F00C7150: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00C7154: 4000a9c7                 call    _objc_msgSend
F00C7158: 9412a018                 bset    %lo(aIodiskpartitio), %o2! "IODiskPartition"
F00C715C: 90100011                 mov     %l1, %o0! id
F00C7160: 133c0506                 sethi   %hi(paSetdrivename), %o1
F00C7164: 153c03eb                 sethi   %hi(aIodiskpartitio_0), %o2! "IODiskPartition Partition"
F00C7168: d2026184                 ld      [%o1+%lo(paSetdrivename)], %o1! SEL
F00C716C: 4000a9c1                 call    _objc_msgSend
F00C7170: 9412a028                 bset    %lo(aIodiskpartitio_0), %o2! "IODiskPartition Partition"
F00C7174: 90100011                 mov     %l1, %o0! id
F00C7178: 133c0504                 sethi   %hi(paSetlocation), %o1
F00C717C: d2026254                 ld      [%o1+%lo(paSetlocation)], %o1! SEL
F00C7180: 4000a9bc                 call    _objc_msgSend
F00C7184: 94102000                 mov     0, %o2
F00C7188: 113c0504                 sethi   %hi(paInit), %o0! id
F00C718C: d202202c                 ld      [%o0+%lo(paInit)], %o1! SEL
F00C7190: 4000a9b8                 call    _objc_msgSend
F00C7194: 90100011                 mov     %l1, %o0
F00C7198: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00C719C: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00C71A0: 4000a9b4                 call    _objc_msgSend
F00C71A4: 90100011                 mov     %l1, %o0
F00C71A8: 90100011                 mov     %l1, %o0! id
F00C71AC: 133c0506                 sethi   %hi(paConnecttophysi), %o1
F00C71B0: d2026188                 ld      [%o1+%lo(paConnecttophysi)], %o1! SEL
F00C71B4: 4000a9af                 call    _objc_msgSend
F00C71B8: 94100012                 mov     %l2, %o2
F00C71BC: 90100012                 mov     %l2, %o0! id
F00C71C0: 133c0506                 sethi   %hi(paSetlogicaldisk), %o1
F00C71C4: d20261a4                 ld      [%o1+%lo(paSetlogicaldisk)], %o1! SEL
F00C71C8: 4000a9aa                 call    _objc_msgSend
F00C71CC: 94100011                 mov     %l1, %o2
F00C71D0: c02c61a8                 clrb    [%l1+0x1A8]
F00C71D4: c02c61a9                 clrb    [%l1+0x1A9]
F00C71D8: c02c61aa                 clrb    [%l1+0x1AA]
F00C71DC: 90100012                 mov     %l2, %o0! id
F00C71E0: 133c0506                 sethi   %hi(paRegisterunixdi), %o1! SEL
F00C71E4: e0026180                 ld      [%o1+%lo(paRegisterunixdi)], %l0
F00C71E8: 94102000                 mov     0, %o2
F00C71EC: 4000a9a1                 call    _objc_msgSend
F00C71F0: 92100010                 mov     %l0, %o1
F00C71F4: 90100011                 mov     %l1, %o0! id
F00C71F8: 92100010                 mov     %l0, %o1! SEL
F00C71FC: 4000a99d                 call    _objc_msgSend
F00C7200: 94102000                 mov     0, %o2
F00C7204: 90100012                 mov     %l2, %o0! id
F00C7208: 133c0506                 sethi   %hi(paLastreadystate_0), %o1
F00C720C: d202617c                 ld      [%o1+%lo(paLastreadystate_0)], %o1! SEL
F00C7210: a0102000                 mov     0, %l0
F00C7214: 333c0506                 sethi   %hi(paUpdatereadysta), %i1
F00C7218: 373c03eb                 sethi   -0xFF05400, %i3
F00C721C: 2f3c03eb                 sethi   -0xFF05400, %l7
F00C7220: 4000a994                 call    _objc_msgSend
F00C7224: 2b3c03eb                 sethi   -0xFF05400, %l5
F00C7228: b0100008                 mov     %o0, %i0
F00C722C: d20661c8                 ld      [%i1+%lo(paUpdatereadysta)], %o1! SEL
F00C7230: 4000a990                 call    _objc_msgSend
F00C7234: 90100012                 mov     %l2, %o0
F00C7238: b4100008                 mov     %o0, %i2
F00C723C: 80a6a001                 cmp     %i2, 1
F00C7240: 2280000c                 be,a    loc_F00C7270
F00C7244: 80a42000                 cmp     %l0, 0
F00C7248: 0a800017                 bcs     loc_F00C72A4
F00C724C: 80a6a002                 cmp     %i2, 2
F00C7250: 12800008                 bne     loc_F00C7270
F00C7254: 80a42000                 cmp     %l0, 0
F00C7258: 0480006d                 ble     loc_F00C740C
F00C725C: 80a76000                 cmp     %i5, 0
F00C7260: 7ffffba5                 call    _IOLog
F00C7264: 9016e048                 or      %i3, 0x48, %o0
F00C7268: 10800069                 ba      loc_F00C740C
F00C726C: 80a76000                 cmp     %i5, 0
F00C7270: 12800005                 bne     loc_F00C7284
F00C7274: 9015e050                 or      %l7, 0x50, %o0
F00C7278: 7ffffb9f                 call    _IOLog
F00C727C: 92100013                 mov     %l3, %o1
F00C7280: 30800003                 ba,a    loc_F00C728C
F00C7284: 7ffffb9c                 call    _IOLog
F00C7288: 90156078                 or      %l5, 0x78, %o0
F00C728C: 7ffffb3c                 call    _IOSleep
F00C7290: 901023e8                 mov     0x3E8, %o0
F00C7294: a0042001                 inc     %l0
F00C7298: 80a4200e                 cmp     %l0, 0xE
F00C729C: 04bfffe5                 ble     loc_F00C7230
F00C72A0: d20661c8                 ld      [%i1+0x1C8], %o1
F00C72A4: 80a42000                 cmp     %l0, 0
F00C72A8: 04800004                 ble     loc_F00C72B8
F00C72AC: 113c03eb                 sethi   %hi(asc_F00FAC48), %o0! "\n"
F00C72B0: 7ffffb91                 call    _IOLog
F00C72B4: 90122048                 bset    %lo(asc_F00FAC48), %o0! "\n"
F00C72B8: 90100012                 mov     %l2, %o0! id
F00C72BC: 133c0506                 sethi   %hi(paSetlastreadyst), %o1
F00C72C0: d2026178                 ld      [%o1+%lo(paSetlastreadyst)], %o1! SEL
F00C72C4: 4000a96b                 call    _objc_msgSend
F00C72C8: 9410001a                 mov     %i2, %o2
F00C72CC: 80a6a000                 cmp     %i2, 0
F00C72D0: 02800004                 be      loc_F00C72E0
F00C72D4: 113c03eb                 sethi   %hi(aSDiskNotReady), %o0! "%s: Disk Not Ready\n"
F00C72D8: 10800013                 ba      loc_F00C7324
F00C72DC: 90122080                 bset    %lo(aSDiskNotReady), %o0! "%s: Disk Not Ready\n"
F00C72E0: 80a62000                 cmp     %i0, 0
F00C72E4: 22800007                 be,a    loc_F00C7300
F00C72E8: 113c0504                 sethi   -0xFEBF000, %o0
F00C72EC: 113c0504                 sethi   %hi(paUpdatephysical), %o0! id
F00C72F0: d20221c4                 ld      [%o0+%lo(paUpdatephysical)], %o1! SEL
F00C72F4: 4000a95f                 call    _objc_msgSend
F00C72F8: 90100012                 mov     %l2, %o0
F00C72FC: 113c0504                 sethi   -0xFEBF000, %o0! id
F00C7300: d2022178                 ld      [%o0+0x178], %o1! SEL
F00C7304: 4000a95b                 call    _objc_msgSend
F00C7308: 90100012                 mov     %l2, %o0
F00C730C: 912a2018                 sll     %o0, 24, %o0
F00C7310: 80a22000                 cmp     %o0, 0
F00C7314: 12800008                 bne     loc_F00C7334
F00C7318: 133c0504                 sethi   -0xFEBF000, %o1
F00C731C: 113c03eb90122098         set     aSDiskUnformatt, %o0! "%s: Disk Unformatted\n"
F00C7324: 7ffffb74                 call    _IOLog
F00C7328: 92100013                 mov     %l3, %o1
F00C732C: 10800038                 ba      loc_F00C740C
F00C7330: 80a76000                 cmp     %i5, 0
F00C7334: d2026188                 ld      [%o1+0x188], %o1! SEL
F00C7338: 4000a94e                 call    _objc_msgSend
F00C733C: 90100012                 mov     %l2, %o0
F00C7340: a8100008                 mov     %o0, %l4
F00C7344: 90100011                 mov     %l1, %o0! id
F00C7348: 133c0506                 sethi   %hi(paSetphysicalblo), %o1
F00C734C: d2026174                 ld      [%o1+%lo(paSetphysicalblo)], %o1! SEL
F00C7350: 4000a948                 call    _objc_msgSend
F00C7354: 94100014                 mov     %l4, %o2
F00C7358: 113c0504                 sethi   %hi(paDisksize), %o0
F00C735C: f40221b0                 ld      [%o0+%lo(paDisksize)], %i2
F00C7360: ba102001                 mov     1, %i5
F00C7364: 90100012                 mov     %l2, %o0! id
F00C7368: 4000a942                 call    _objc_msgSend
F00C736C: 9210001a                 mov     %i2, %o1
F00C7370: b8100008                 mov     %o0, %i4
F00C7374: 11000007                 sethi   0x1C00, %o0
F00C7378: 7ffffaee                 call    _IOMalloc
F00C737C: 9012205c                 bset    0x5C, %o0 ! '\'
F00C7380: ac100008                 mov     %o0, %l6
F00C7384: 90100011                 mov     %l1, %o0! id
F00C7388: 133c0504                 sethi   %hi(paReadlabel), %o1
F00C738C: d202619c                 ld      [%o1+%lo(paReadlabel)], %o1! SEL
F00C7390: 4000a938                 call    _objc_msgSend
F00C7394: 94100016                 mov     %l6, %o2
F00C7398: 80a22000                 cmp     %o0, 0
F00C739C: 02800013                 be      loc_F00C73E8
F00C73A0: 113c03eb                 sethi   %hi(aSNoValidDiskLa), %o0! "%s: No Valid Disk Label\n"
F00C73A4: 901220b0                 bset    %lo(aSNoValidDiskLa), %o0! "%s: No Valid Disk Label\n"
F00C73A8: 7ffffb53                 call    _IOLog
F00C73AC: 92100013                 mov     %l3, %o1
F00C73B0: 90100011                 mov     %l1, %o0! id
F00C73B4: 133c0506                 sethi   %hi(paSetblocksize), %o1
F00C73B8: d2026170                 ld      [%o1+%lo(paSetblocksize)], %o1! SEL
F00C73BC: 4000a92d                 call    _objc_msgSend
F00C73C0: 94100014                 mov     %l4, %o2
F00C73C4: 133c0506                 sethi   %hi(paSetdisksize), %o1! SEL
F00C73C8: e002616c                 ld      [%o1+%lo(paSetdisksize)], %l0
F00C73CC: 90100012                 mov     %l2, %o0! id
F00C73D0: 4000a928                 call    _objc_msgSend
F00C73D4: 9210001a                 mov     %i2, %o1
F00C73D8: 94100008                 mov     %o0, %o2
F00C73DC: 90100011                 mov     %l1, %o0
F00C73E0: 10800008                 ba      loc_F00C7400
F00C73E4: 92100010                 mov     %l0, %o1
F00C73E8: 96102001                 mov     1, %o3
F00C73EC: d62fbfcf                 stb     %o3, [%fp+var_31]
F00C73F0: 90100011                 mov     %l1, %o0! id
F00C73F4: 133c0506                 sethi   %hi(paProbelabel), %o1
F00C73F8: d2026168                 ld      [%o1+%lo(paProbelabel)], %o1! SEL
F00C73FC: 94100016                 mov     %l6, %o2
F00C7400: 4000a91c                 call    _objc_msgSend
F00C7404: 01000000                 nop
F00C7408: 80a76000                 cmp     %i5, 0
F00C740C: 0280001a                 be      loc_F00C7474
F00C7410: 113c03eb                 sethi   %hi(aSDeviceBlockSi), %o0! "%s: Device Block Size: %u bytes\n"
F00C7414: 901220d0                 bset    %lo(aSDeviceBlockSi), %o0! "%s: Device Block Size: %u bytes\n"
F00C7418: 92100013                 mov     %l3, %o1
F00C741C: 7ffffb36                 call    _IOLog
F00C7420: 94100014                 mov     %l4, %o2
F00C7424: 9137200a                 srl     %i4, 10, %o0
F00C7428: 7ffcfc36                 call    _umul
F00C742C: 92100014                 mov     %l4, %o1
F00C7430: 94100008                 mov     %o0, %o2
F00C7434: 1100000a                 sethi   0x2800, %o0
F00C7438: 80a28008                 cmp     %o2, %o0
F00C743C: 08800004                 bleu    loc_F00C744C
F00C7440: 113c03eb                 sethi   %hi(aSDeviceCapacit), %o0! "%s: Device Capacity:   %u MB\n"
F00C7444: 10800009                 ba      loc_F00C7468
F00C7448: 901220f8                 bset    %lo(aSDeviceCapacit), %o0! "%s: Device Capacity:   %u MB\n"
F00C744C: 9010001c                 mov     %i4, %o0
F00C7450: 92100014                 mov     %l4, %o1
F00C7454: 213c03eb                 sethi   %hi(aSDeviceCapacit_0), %l0! "%s: Device Capacity:   %u KB\n"
F00C7458: 7ffcfc2a                 call    _umul
F00C745C: a0142118                 bset    %lo(aSDeviceCapacit_0), %l0! "%s: Device Capacity:   %u KB\n"
F00C7460: 94100008                 mov     %o0, %o2
F00C7464: 90100010                 mov     %l0, %o0
F00C7468: 92100013                 mov     %l3, %o1
F00C746C: 7ffffb22                 call    _IOLog
F00C7470: 9532a00a                 srl     %o2, 10, %o2
F00C7474: d60fbfcf                 ldub    [%fp+var_31], %o3
F00C7478: 80a2e000                 cmp     %o3, 0
F00C747C: 02800006                 be      loc_F00C7494
F00C7480: 113c03eb                 sethi   %hi(aSDiskLabelS), %o0! "%s: Disk Label:        %s\n"
F00C7484: 90122138                 bset    %lo(aSDiskLabelS), %o0! "%s: Disk Label:        %s\n"
F00C7488: 92100013                 mov     %l3, %o1
F00C748C: 7ffffb1a                 call    _IOLog
F00C7490: 9405a00c                 add     %l6, 0xC, %o2
F00C7494: 80a5a000                 cmp     %l6, 0
F00C7498: 02800005                 be      loc_F00C74AC
F00C749C: 90100016                 mov     %l6, %o0
F00C74A0: 13000007                 sethi   0x1C00, %o1
F00C74A4: 7ffffaa8                 call    _IOFree
F00C74A8: 9212605c                 bset    0x5C, %o1 ! '\'
F00C74AC: b0102001                 mov     1, %i0
F00C74B0: 81c7e008                 ret
F00C74B4: 81e80000                 restore
