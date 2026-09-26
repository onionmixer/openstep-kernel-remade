F00C7F34: 9de3bf70                 save    %sp, -0x90, %sp
F00C7F38: 90100018                 mov     %i0, %o0! id
F00C7F3C: 133c0506                 sethi   %hi(paPhysicaldisk_0), %o1
F00C7F40: a32ea001                 sll     %i2, 1, %l1
F00C7F44: a204401a                 add     %l1, %i2, %l1
F00C7F48: a32c6004                 sll     %l1, 4, %l1
F00C7F4C: d2026164                 ld      [%o1+%lo(paPhysicaldisk_0)], %o1! SEL
F00C7F50: 4000a648                 call    _objc_msgSend
F00C7F54: a2046094                 inc     0x94, %l1
F00C7F58: a6100008                 mov     %o0, %l3
F00C7F5C: 133c0504                 sethi   %hi(paName), %o1
F00C7F60: a407bfd0                 add     %fp, var_30, %l2
F00C7F64: 213c03eb                 sethi   %hi(aSC), %l0! "%s%c"
F00C7F68: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C7F6C: 4000a641                 call    _objc_msgSend
F00C7F70: a0142270                 bset    %lo(aSC), %l0! "%s%c"
F00C7F74: 94100008                 mov     %o0, %o2
F00C7F78: 90100012                 mov     %l2, %o0! char *
F00C7F7C: 92100010                 mov     %l0, %o1! char *
F00C7F80: 7ffd31fa                 call    _sprintf
F00C7F84: 9606a061                 add     %i2, 0x61, %o3 ! 'a'
F00C7F88: 90100018                 mov     %i0, %o0! id
F00C7F8C: 133c0504                 sethi   %hi(paSetname), %o1
F00C7F90: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00C7F94: 4000a637                 call    _objc_msgSend
F00C7F98: 94100012                 mov     %l2, %o2
F00C7F9C: 90100018                 mov     %i0, %o0! id
F00C7FA0: 133c0506                 sethi   %hi(paSetdrivename), %o1
F00C7FA4: 153c03eb                 sethi   %hi(aIodiskpartitio_0), %o2! "IODiskPartition Partition"
F00C7FA8: d2026184                 ld      [%o1+%lo(paSetdrivename)], %o1! SEL
F00C7FAC: 4000a631                 call    _objc_msgSend
F00C7FB0: 9412a028                 bset    %lo(aIodiskpartitio_0), %o2! "IODiskPartition Partition"
F00C7FB4: 90100018                 mov     %i0, %o0! id
F00C7FB8: 133c0504                 sethi   %hi(paSetlocation), %o1
F00C7FBC: d2026254                 ld      [%o1+%lo(paSetlocation)], %o1! SEL
F00C7FC0: 4000a62c                 call    _objc_msgSend
F00C7FC4: 94102000                 mov     0, %o2
F00C7FC8: 113c0506                 sethi   %hi(paSetdisksize), %o0
F00C7FCC: d202216c                 ld      [%o0+%lo(paSetdisksize)], %o1! SEL
F00C7FD0: 9006c011                 add     %i3, %l1, %o0! id
F00C7FD4: d4022004                 ld      [%o0+4], %o2
F00C7FD8: 4000a626                 call    _objc_msgSend
F00C7FDC: 90100018                 mov     %i0, %o0
F00C7FE0: 113c0506                 sethi   %hi(paSetblocksize), %o0! id
F00C7FE4: d2022170                 ld      [%o0+%lo(paSetblocksize)], %o1! SEL
F00C7FE8: d406e030                 ld      [%i3+0x30], %o2
F00C7FEC: 4000a621                 call    _objc_msgSend
F00C7FF0: 90100018                 mov     %i0, %o0
F00C7FF4: 113c0506                 sethi   %hi(paUnit_0), %o0
F00C7FF8: d2022138                 ld      [%o0+%lo(paUnit_0)], %o1! SEL
F00C7FFC: 113c0504                 sethi   %hi(paSetunit), %o0! id
F00C8000: e0022248                 ld      [%o0+%lo(paSetunit)], %l0
F00C8004: 4000a61b                 call    _objc_msgSend
F00C8008: 90100013                 mov     %l3, %o0
F00C800C: 94100008                 mov     %o0, %o2
F00C8010: 90100018                 mov     %i0, %o0! id
F00C8014: 4000a617                 call    _objc_msgSend
F00C8018: 92100010                 mov     %l0, %o1
F00C801C: 113c0506                 sethi   %hi(paIswriteprotect), %o0
F00C8020: d20221bc                 ld      [%o0+%lo(paIswriteprotect)], %o1! SEL
F00C8024: 113c0506                 sethi   %hi(paSetwriteprotec), %o0! id
F00C8028: e00221a8                 ld      [%o0+%lo(paSetwriteprotec)], %l0
F00C802C: 4000a611                 call    _objc_msgSend
F00C8030: 90100013                 mov     %l3, %o0
F00C8034: 952a2018                 sll     %o0, 24, %o2
F00C8038: 90100018                 mov     %i0, %o0! id
F00C803C: 92100010                 mov     %l0, %o1! SEL
F00C8040: 4000a60c                 call    _objc_msgSend
F00C8044: 953aa018                 sra     %o2, 24, %o2
F00C8048: d456e044                 ldsh    [%i3+0x44], %o2
F00C804C: 90100018                 mov     %i0, %o0! id
F00C8050: e006c011                 ld      [%i3+%l1], %l0
F00C8054: 133c0506                 sethi   %hi(paPhysicalblocks_0), %o1
F00C8058: d2026160                 ld      [%o1+%lo(paPhysicalblocks_0)], %o1! SEL
F00C805C: 4000a605                 call    _objc_msgSend
F00C8060: a004000a                 add     %l0, %o2, %l0
F00C8064: 92100008                 mov     %o0, %o1
F00C8068: 7ffcf966                 call    _udiv
F00C806C: d006e030                 ld      [%i3+0x30], %o0
F00C8070: 92100008                 mov     %o0, %o1
F00C8074: 7ffcf923                 call    _umul
F00C8078: 90100010                 mov     %l0, %o0! id
F00C807C: 94100008                 mov     %o0, %o2
F00C8080: 133c0506                 sethi   %hi(paSetpartitionba), %o1
F00C8084: d2026134                 ld      [%o1+%lo(paSetpartitionba)], %o1! SEL
F00C8088: 4000a5fa                 call    _objc_msgSend
F00C808C: 90100018                 mov     %i0, %o0
F00C8090: f42621a4                 st      %i2, [%i0+0x1A4]
F00C8094: f027bff0                 st      %i0, [%fp+var_10]
F00C8098: 113c03eb                 sethi   %hi(aIologicaldisk), %o0! "IOLogicalDisk"
F00C809C: 40009d70                 call    _objc_getOrigClass
F00C80A0: 90122278                 bset    %lo(aIologicaldisk), %o0! "IOLogicalDisk"
F00C80A4: d027bff4                 st      %o0, [%fp+var_C]
F00C80A8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C80AC: 133c0506                 sethi   %hi(paSetformattedin), %o1
F00C80B0: d20261ac                 ld      [%o1+%lo(paSetformattedin)], %o1! SEL
F00C80B4: 4000a632                 call    _objc_msgSendSuper
F00C80B8: 94102001                 mov     1, %o2
F00C80BC: 90102001                 mov     1, %o0
F00C80C0: d02e21a8                 stb     %o0, [%i0+0x1A8]
F00C80C4: 90100018                 mov     %i0, %o0! id
F00C80C8: 133c0506                 sethi   %hi(paRegisterunixdi), %o1
F00C80CC: d2026180                 ld      [%o1+%lo(paRegisterunixdi)], %o1! SEL
F00C80D0: 4000a5e8                 call    _objc_msgSend
F00C80D4: 9410001a                 mov     %i2, %o2
F00C80D8: 81c7e008                 ret
F00C80DC: 81e80000                 restore
