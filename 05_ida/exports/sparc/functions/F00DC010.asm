F00DC010: 9de3bf88                 save    %sp, -0x78, %sp
F00DC014: 7ffe7ba0                 call    _kern_serv_kernel_task_port
F00DC018: 01000000                 nop
F00DC01C: a0100008                 mov     %o0, %l0
F00DC020: 9010001c                 mov     %i4, %o0
F00DC024: 92102002                 mov     2, %o1
F00DC028: 7fffb8a0                 call    _IOConvertPort
F00DC02C: 94102000                 mov     0, %o2
F00DC030: d2062068                 ld      [%i0+0x68], %o1
F00DC034: 80a26000                 cmp     %o1, 0
F00DC038: 12800007                 bne     loc_F00DC054
F00DC03C: a2100008                 mov     %o0, %l1
F00DC040: d006206c                 ld      [%i0+0x6C], %o0
F00DC044: 80a22001                 cmp     %o0, 1
F00DC048: 32800003                 bne,a   loc_F00DC054
F00DC04C: b40ebffc                 and     %i2, -4, %i2
F00DC050: b40ebffe                 and     %i2, -2, %i2
F00DC054: 90100010                 mov     %l0, %o0
F00DC058: 9207bfec                 add     %fp, var_14, %o1
F00DC05C: 9410001a                 mov     %i2, %o2
F00DC060: 400061ab                 call    _vm_allocate_EXTERNAL
F00DC064: 96102001                 mov     1, %o3
F00DC068: 80a22000                 cmp     %o0, 0
F00DC06C: 0280000c                 be      loc_F00DC09C
F00DC070: 113c0505                 sethi   -0xFEBEC00, %o0
F00DC074: 113c03f190122168         set     aAudioRecordReq, %o0! "Audio: record request (%d bytes) too la"...
F00DC07C: 7fffa81e                 call    _IOLog
F00DC080: 9210001a                 mov     %i2, %o1
F00DC084: 10800035                 ba      locret_F00DC158
F00DC088: b0102000                 mov     0, %i0
F00DC08C: e0262030                 st      %l0, [%i0+0x30]
F00DC090: d224203c                 st      %o1, [%l0+0x3C]
F00DC094: 10800021                 ba      loc_F00DC118
F00DC098: d2242040                 st      %o1, [%l0+0x40]
F00DC09C: d202203c                 ld      [%o0+0x3C], %o1! SEL
F00DC0A0: 400055f4                 call    _objc_msgSend
F00DC0A4: 90100018                 mov     %i0, %o0
F00DC0A8: a0100008                 mov     %o0, %l0
F00DC0AC: f4242010                 st      %i2, [%l0+0x10]
F00DC0B0: f6242014                 st      %i3, [%l0+0x14]
F00DC0B4: e224201c                 st      %l1, [%l0+0x1C]
F00DC0B8: fa242018                 st      %i5, [%l0+0x18]
F00DC0BC: d407bfec                 ld      [%fp+var_14], %o2
F00DC0C0: 113c0504                 sethi   %hi(paLock), %o0
F00DC0C4: d2022000                 ld      [%o0+%lo(paLock)], %o1! SEL
F00DC0C8: d4240000                 st      %o2, [%l0]
F00DC0CC: d424200c                 st      %o2, [%l0+0xC]
F00DC0D0: d0040000                 ld      [%l0], %o0
F00DC0D4: d4242008                 st      %o2, [%l0+8]
F00DC0D8: 9002001a                 add     %o0, %i2, %o0
F00DC0DC: d0242004                 st      %o0, [%l0+4]
F00DC0E0: fa262060                 st      %i5, [%i0+0x60]
F00DC0E4: d0062028                 ld      [%i0+0x28], %o0! id
F00DC0E8: 400055e2                 call    _objc_msgSend
F00DC0EC: e226205c                 st      %l1, [%i0+0x5C]
F00DC0F0: 9206202c                 add     %i0, 0x2C, %o1 ! ','
F00DC0F4: d006202c                 ld      [%i0+0x2C], %o0
F00DC0F8: 80a24008                 cmp     %o1, %o0
F00DC0FC: 22bfffe4                 be,a    loc_F00DC08C
F00DC100: e026202c                 st      %l0, [%i0+0x2C]
F00DC104: d0062030                 ld      [%i0+0x30], %o0
F00DC108: d0242040                 st      %o0, [%l0+0x40]
F00DC10C: d224203c                 st      %o1, [%l0+0x3C]
F00DC110: e0262030                 st      %l0, [%i0+0x30]
F00DC114: e022203c                 st      %l0, [%o0+0x3C]
F00DC118: d0062028                 ld      [%i0+0x28], %o0! id
F00DC11C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DC120: 400055d4                 call    _objc_msgSend
F00DC124: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DC128: 113c0505                 sethi   %hi(paChannel), %o0
F00DC12C: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DC130: 113c0505                 sethi   %hi(paDatapendingfor), %o0! id
F00DC134: e0022054                 ld      [%o0+%lo(paDatapendingfor)], %l0
F00DC138: e2062008                 ld      [%i0+8], %l1
F00DC13C: 400055cd                 call    _objc_msgSend
F00DC140: 90100018                 mov     %i0, %o0
F00DC144: 94100008                 mov     %o0, %o2
F00DC148: 90100011                 mov     %l1, %o0! id
F00DC14C: 400055c9                 call    _objc_msgSend
F00DC150: 92100010                 mov     %l0, %o1
F00DC154: b0102001                 mov     1, %i0
F00DC158: 81c7e008                 ret
F00DC15C: 81e80000                 restore
