F00DB6F8: 9de3bf90                 save    %sp, -0x70, %sp
F00DB6FC: 80a6a001                 cmp     %i2, 1
F00DB700: 22800047                 be,a    loc_F00DB81C
F00DB704: d206c000                 ld      [%i3], %o1
F00DB708: 0a800008                 bcs     loc_F00DB728
F00DB70C: 80a6a002                 cmp     %i2, 2
F00DB710: 02800089                 be      loc_F00DB934
F00DB714: 80a6a004                 cmp     %i2, 4
F00DB718: 028000ef                 be      loc_F00DBAD4
F00DB71C: 90100018                 mov     %i0, %o0
F00DB720: 108000f2                 ba      loc_F00DBAE8
F00DB724: 113c03f1                 sethi   -0xFF03C00, %o0
F00DB728: d206c000                 ld      [%i3], %o1
F00DB72C: 80a26000                 cmp     %o1, 0
F00DB730: 32800007                 bne,a   loc_F00DB74C
F00DB734: d2262044                 st      %o1, [%i0+0x44]
F00DB738: d006e004                 ld      [%i3+4], %o0
F00DB73C: 80a22000                 cmp     %o0, 0
F00DB740: 0280002f                 be      loc_F00DB7FC
F00DB744: 90102001                 mov     1, %o0
F00DB748: d2262044                 st      %o1, [%i0+0x44]
F00DB74C: d206e004                 ld      [%i3+4], %o1
F00DB750: 90102028                 mov     0x28, %o0 ! '('
F00DB754: 7fffa9f7                 call    _IOMalloc
F00DB758: d2262048                 st      %o1, [%i0+0x48]
F00DB75C: b6062038                 add     %i0, 0x38, %i3 ! '8'
F00DB760: a4062044                 add     %i0, 0x44, %l2 ! 'D'
F00DB764: d2062038                 ld      [%i0+0x38], %o1
F00DB768: 80a26000                 cmp     %o1, 0
F00DB76C: 128000ac                 bne     loc_F00DBA1C
F00DB770: a0100008                 mov     %o0, %l0
F00DB774: 7ffe2ecf                 call    _task_self
F00DB778: 01000000                 nop
F00DB77C: 400060f9                 call    _port_allocate_EXTERNAL
F00DB780: 9210001b                 mov     %i3, %o1
F00DB784: 80a22000                 cmp     %o0, 0
F00DB788: 02800009                 be      loc_F00DB7AC
F00DB78C: 113c03f1                 sethi   %hi(aAudioStreamCon), %o0! "Audio: stream control thread port_alloc"...
F00DB790: 90122088                 bset    %lo(aAudioStreamCon), %o0! "Audio: stream control thread port_alloc"...
F00DB794: 133c03f1                 sethi   %hi(aMachErr), %o1! "MACH ERR"
F00DB798: 7fffaa57                 call    _IOLog
F00DB79C: 92126020                 bset    %lo(aMachErr), %o1! "MACH ERR"
F00DB7A0: 113c03f1                 sethi   %hi(aAudioDriverErr), %o0! "Audio Driver error"
F00DB7A4: 7fffaa54                 call    _IOLog
F00DB7A8: 901220b8                 bset    %lo(aAudioDriverErr), %o0! "Audio Driver error"
F00DB7AC: 233c04bb                 sethi   %hi(dword_F012EF3C), %l1
F00DB7B0: d004633c                 ld      [%l1+%lo(dword_F012EF3C)], %o0
F00DB7B4: 80a22000                 cmp     %o0, 0
F00DB7B8: 3280000d                 bne,a   loc_F00DB7EC
F00DB7BC: 133c0504                 sethi   -0xFEBF000, %o1
F00DB7C0: 113c0506                 sethi   %hi(paNxlock), %o0
F00DB7C4: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00DB7C8: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00DB7CC: 40005829                 call    _objc_msgSend
F00DB7D0: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00DB7D4: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00DB7D8: 40005826                 call    _objc_msgSend
F00DB7DC: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00DB7E0: d024633c                 st      %o0, [%l1+%lo(dword_F012EF3C)]
F00DB7E4: d004633c                 ld      [%l1+%lo(dword_F012EF3C)], %o0! id
F00DB7E8: 133c0504                 sethi   -0xFEBF000, %o1! SEL
F00DB7EC: 40005821                 call    _objc_msgSend
F00DB7F0: d2026000                 ld      [%o1], %o1
F00DB7F4: 10800084                 ba      loc_F00DBA04
F00DB7F8: d2062038                 ld      [%i0+0x38], %o1
F00DB7FC: d02e2024                 stb     %o0, [%i0+0x24]
F00DB800: 90100018                 mov     %i0, %o0! id
F00DB804: 133c0505                 sethi   %hi(paSendcontrolmes), %o1
F00DB808: d202605c                 ld      [%o1+%lo(paSendcontrolmes)], %o1! SEL
F00DB80C: 94102002                 mov     2, %o2
F00DB810: 40005818                 call    _objc_msgSend
F00DB814: 96102004                 mov     4, %o3
F00DB818: 308000b7                 ba,a    locret_F00DBAF4
F00DB81C: 80a26000                 cmp     %o1, 0
F00DB820: 32800007                 bne,a   loc_F00DB83C
F00DB824: d226204c                 st      %o1, [%i0+0x4C]
F00DB828: d006e004                 ld      [%i3+4], %o0
F00DB82C: 80a22000                 cmp     %o0, 0
F00DB830: 2280002f                 be,a    loc_F00DB8EC
F00DB834: c02e2024                 clrb    [%i0+0x24]
F00DB838: d226204c                 st      %o1, [%i0+0x4C]
F00DB83C: d206e004                 ld      [%i3+4], %o1
F00DB840: 90102028                 mov     0x28, %o0 ! '('
F00DB844: 7fffa9bb                 call    _IOMalloc
F00DB848: d2262050                 st      %o1, [%i0+0x50]
F00DB84C: b606203c                 add     %i0, 0x3C, %i3 ! '<'
F00DB850: a406204c                 add     %i0, 0x4C, %l2 ! 'L'
F00DB854: d206203c                 ld      [%i0+0x3C], %o1
F00DB858: 80a26000                 cmp     %o1, 0
F00DB85C: 12800070                 bne     loc_F00DBA1C
F00DB860: a0100008                 mov     %o0, %l0
F00DB864: 7ffe2e93                 call    _task_self
F00DB868: 01000000                 nop
F00DB86C: 400060bd                 call    _port_allocate_EXTERNAL
F00DB870: 9210001b                 mov     %i3, %o1
F00DB874: 80a22000                 cmp     %o0, 0
F00DB878: 02800009                 be      loc_F00DB89C
F00DB87C: 113c03f1                 sethi   %hi(aAudioStreamCon), %o0! "Audio: stream control thread port_alloc"...
F00DB880: 90122088                 bset    %lo(aAudioStreamCon), %o0! "Audio: stream control thread port_alloc"...
F00DB884: 133c03f1                 sethi   %hi(aMachErr), %o1! "MACH ERR"
F00DB888: 7fffaa1b                 call    _IOLog
F00DB88C: 92126020                 bset    %lo(aMachErr), %o1! "MACH ERR"
F00DB890: 113c03f1                 sethi   %hi(aAudioDriverErr), %o0! "Audio Driver error"
F00DB894: 7fffaa18                 call    _IOLog
F00DB898: 901220b8                 bset    %lo(aAudioDriverErr), %o0! "Audio Driver error"
F00DB89C: 233c04bb                 sethi   %hi(dword_F012EF3C), %l1
F00DB8A0: d004633c                 ld      [%l1+%lo(dword_F012EF3C)], %o0
F00DB8A4: 80a22000                 cmp     %o0, 0
F00DB8A8: 3280000d                 bne,a   loc_F00DB8DC
F00DB8AC: 133c0504                 sethi   -0xFEBF000, %o1
F00DB8B0: 113c0506                 sethi   %hi(paNxlock), %o0
F00DB8B4: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00DB8B8: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00DB8BC: 400057ed                 call    _objc_msgSend
F00DB8C0: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00DB8C4: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00DB8C8: 400057ea                 call    _objc_msgSend
F00DB8CC: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00DB8D0: d024633c                 st      %o0, [%l1+%lo(dword_F012EF3C)]
F00DB8D4: d004633c                 ld      [%l1+%lo(dword_F012EF3C)], %o0! id
F00DB8D8: 133c0504                 sethi   -0xFEBF000, %o1! SEL
F00DB8DC: 400057e5                 call    _objc_msgSend
F00DB8E0: d2026000                 ld      [%o1], %o1
F00DB8E4: 10800048                 ba      loc_F00DBA04
F00DB8E8: d206203c                 ld      [%i0+0x3C], %o1
F00DB8EC: 90100018                 mov     %i0, %o0! id
F00DB8F0: 94102003                 mov     3, %o2
F00DB8F4: 133c0505                 sethi   %hi(paSendcontrolmes), %o1
F00DB8F8: d202605c                 ld      [%o1+%lo(paSendcontrolmes)], %o1! SEL
F00DB8FC: 400057dd                 call    _objc_msgSend
F00DB900: 96102008                 mov     8, %o3
F00DB904: 113c0505                 sethi   %hi(paChannel), %o0
F00DB908: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DB90C: 113c0505                 sethi   %hi(paDatapendingfor), %o0! id
F00DB910: e0022054                 ld      [%o0+%lo(paDatapendingfor)], %l0
F00DB914: e2062008                 ld      [%i0+8], %l1
F00DB918: 400057d6                 call    _objc_msgSend
F00DB91C: 90100018                 mov     %i0, %o0
F00DB920: 94100008                 mov     %o0, %o2
F00DB924: 90100011                 mov     %l1, %o0! id
F00DB928: 400057d2                 call    _objc_msgSend
F00DB92C: 92100010                 mov     %l0, %o1
F00DB930: 30800071                 ba,a    locret_F00DBAF4
F00DB934: d206c000                 ld      [%i3], %o1
F00DB938: 80a26000                 cmp     %o1, 0
F00DB93C: 32800007                 bne,a   loc_F00DB958
F00DB940: d2262054                 st      %o1, [%i0+0x54]
F00DB944: d006e004                 ld      [%i3+4], %o0
F00DB948: 80a22000                 cmp     %o0, 0
F00DB94C: 02800054                 be      loc_F00DBA9C
F00DB950: 90100018                 mov     %i0, %o0
F00DB954: d2262054                 st      %o1, [%i0+0x54]
F00DB958: d206e004                 ld      [%i3+4], %o1
F00DB95C: 90102028                 mov     0x28, %o0 ! '('
F00DB960: 7fffa974                 call    _IOMalloc
F00DB964: d2262058                 st      %o1, [%i0+0x58]
F00DB968: b6062040                 add     %i0, 0x40, %i3 ! '@'
F00DB96C: a4062054                 add     %i0, 0x54, %l2 ! 'T'
F00DB970: d2062040                 ld      [%i0+0x40], %o1
F00DB974: 80a26000                 cmp     %o1, 0
F00DB978: 12800029                 bne     loc_F00DBA1C
F00DB97C: a0100008                 mov     %o0, %l0
F00DB980: 7ffe2e4c                 call    _task_self
F00DB984: 01000000                 nop
F00DB988: 40006076                 call    _port_allocate_EXTERNAL
F00DB98C: 9210001b                 mov     %i3, %o1
F00DB990: 80a22000                 cmp     %o0, 0
F00DB994: 02800009                 be      loc_F00DB9B8
F00DB998: 113c03f1                 sethi   %hi(aAudioStreamCon), %o0! "Audio: stream control thread port_alloc"...
F00DB99C: 90122088                 bset    %lo(aAudioStreamCon), %o0! "Audio: stream control thread port_alloc"...
F00DB9A0: 133c03f1                 sethi   %hi(aMachErr), %o1! "MACH ERR"
F00DB9A4: 7fffa9d4                 call    _IOLog
F00DB9A8: 92126020                 bset    %lo(aMachErr), %o1! "MACH ERR"
F00DB9AC: 113c03f1                 sethi   %hi(aAudioDriverErr), %o0! "Audio Driver error"
F00DB9B0: 7fffa9d1                 call    _IOLog
F00DB9B4: 901220b8                 bset    %lo(aAudioDriverErr), %o0! "Audio Driver error"
F00DB9B8: 233c04bb                 sethi   %hi(dword_F012EF3C), %l1
F00DB9BC: d004633c                 ld      [%l1+%lo(dword_F012EF3C)], %o0
F00DB9C0: 80a22000                 cmp     %o0, 0
F00DB9C4: 1280000d                 bne     loc_F00DB9F8
F00DB9C8: 133c0504                 sethi   -0xFEBF000, %o1
F00DB9CC: 113c0506                 sethi   %hi(paNxlock), %o0
F00DB9D0: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00DB9D4: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00DB9D8: 400057a6                 call    _objc_msgSend
F00DB9DC: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00DB9E0: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00DB9E4: 400057a3                 call    _objc_msgSend
F00DB9E8: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00DB9EC: d024633c                 st      %o0, [%l1+%lo(dword_F012EF3C)]
F00DB9F0: d004633c                 ld      [%l1+%lo(dword_F012EF3C)], %o0! id
F00DB9F4: 133c0504                 sethi   -0xFEBF000, %o1! SEL
F00DB9F8: 4000579e                 call    _objc_msgSend
F00DB9FC: d2026000                 ld      [%o1], %o1
F00DBA00: d2062040                 ld      [%i0+0x40], %o1
F00DBA04: 113c04bb                 sethi   %hi(dword_F012EF38), %o0
F00DBA08: 7ffe615d                 call    _current_task_EXTERNAL
F00DBA0C: d2222338                 st      %o1, [%o0+%lo(dword_F012EF38)]
F00DBA10: 133c036f                 sethi   %hi(sub_F00DBEB4), %o1
F00DBA14: 7ffe6808                 call    _kernel_thread
F00DBA18: 921262b4                 bset    %lo(sub_F00DBEB4), %o1
F00DBA1C: 133c03e5                 sethi   %hi(dword_F00F9764), %o1
F00DBA20: d0026364                 ld      [%o1+%lo(dword_F00F9764)], %o0
F00DBA24: d0240000                 st      %o0, [%l0]
F00DBA28: 92126364                 bset    %lo(dword_F00F9764), %o1
F00DBA2C: d0026004                 ld      [%o1+4], %o0
F00DBA30: d0242004                 st      %o0, [%l0+4]
F00DBA34: d0026008                 ld      [%o1+8], %o0
F00DBA38: d0242008                 st      %o0, [%l0+8]
F00DBA3C: d002600c                 ld      [%o1+0xC], %o0
F00DBA40: d024200c                 st      %o0, [%l0+0xC]
F00DBA44: d0026010                 ld      [%o1+0x10], %o0
F00DBA48: d0242010                 st      %o0, [%l0+0x10]
F00DBA4C: d0026014                 ld      [%o1+0x14], %o0
F00DBA50: d0242014                 st      %o0, [%l0+0x14]
F00DBA54: d0026018                 ld      [%o1+0x18], %o0
F00DBA58: d0242018                 st      %o0, [%l0+0x18]
F00DBA5C: d002601c                 ld      [%o1+0x1C], %o0
F00DBA60: d024201c                 st      %o0, [%l0+0x1C]
F00DBA64: d4026020                 ld      [%o1+0x20], %o2
F00DBA68: 90100010                 mov     %l0, %o0! id
F00DBA6C: d4222020                 st      %o2, [%o0+0x20]
F00DBA70: d4026024                 ld      [%o1+0x24], %o2
F00DBA74: 92102001                 mov     1, %o1
F00DBA78: d4222024                 st      %o2, [%o0+0x24]
F00DBA7C: d606c000                 ld      [%i3], %o3
F00DBA80: 941023e8                 mov     0x3E8, %o2
F00DBA84: d6222010                 st      %o3, [%o0+0x10]
F00DBA88: f022201c                 st      %i0, [%o0+0x1C]
F00DBA8C: f4222020                 st      %i2, [%o0+0x20]
F00DBA90: 7ffe2891                 call    _msg_send
F00DBA94: e4222024                 st      %l2, [%o0+0x24]
F00DBA98: 30800017                 ba,a    locret_F00DBAF4
F00DBA9C: 133c0505                 sethi   %hi(paMarkabortionse), %o1
F00DBAA0: d2026050                 ld      [%o1+%lo(paMarkabortionse)], %o1! SEL
F00DBAA4: 40005773                 call    _objc_msgSend
F00DBAA8: 94102000                 mov     0, %o2
F00DBAAC: 912a2018                 sll     %o0, 24, %o0
F00DBAB0: 80a22000                 cmp     %o0, 0
F00DBAB4: 12800010                 bne     locret_F00DBAF4
F00DBAB8: 90100018                 mov     %i0, %o0! id
F00DBABC: 133c0505                 sethi   %hi(paSendcontrolmes), %o1
F00DBAC0: d202605c                 ld      [%o1+%lo(paSendcontrolmes)], %o1! SEL
F00DBAC4: 94102004                 mov     4, %o2
F00DBAC8: 4000576a                 call    _objc_msgSend
F00DBACC: 96102010                 mov     0x10, %o3
F00DBAD0: 30800009                 ba,a    locret_F00DBAF4
F00DBAD4: 133c0505                 sethi   %hi(paMarkabortionse), %o1
F00DBAD8: d2026050                 ld      [%o1+%lo(paMarkabortionse)], %o1! SEL
F00DBADC: 40005765                 call    _objc_msgSend
F00DBAE0: 94102001                 mov     1, %o2
F00DBAE4: 30800004                 ba,a    locret_F00DBAF4
F00DBAE8: 901220d0                 bset    0xD0, %o0
F00DBAEC: 7fffa982                 call    _IOLog
F00DBAF0: 9210001a                 mov     %i2, %o1
F00DBAF4: 81c7e008                 ret
F00DBAF8: 81e80000                 restore
