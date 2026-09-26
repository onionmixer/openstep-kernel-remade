F00DC7EC: 9de3bf88                 save    %sp, -0x78, %sp
F00DC7F0: 9010001d                 mov     %i5, %o0
F00DC7F4: 92102002                 mov     2, %o1
F00DC7F8: e607a05c                 ld      [%fp+arg_5C], %l3
F00DC7FC: 7fffb6ab                 call    _IOConvertPort
F00DC800: 94102000                 mov     0, %o2
F00DC804: d2062068                 ld      [%i0+0x68], %o1
F00DC808: 80a26000                 cmp     %o1, 0
F00DC80C: 12800007                 bne     loc_F00DC828
F00DC810: a4100008                 mov     %o0, %l2
F00DC814: d006206c                 ld      [%i0+0x6C], %o0
F00DC818: 80a22001                 cmp     %o0, 1
F00DC81C: 32800003                 bne,a   loc_F00DC828
F00DC820: b60efffc                 and     %i3, -4, %i3
F00DC824: b60efffe                 and     %i3, -2, %i3
F00DC828: 113c04d0                 sethi   %hi(_page_mask), %o0
F00DC82C: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F00DC830: 94380009                 xnor    %g0, %o1, %o2
F00DC834: a20e800a                 and     %i2, %o2, %l1
F00DC838: b4268011                 sub     %i2, %l1, %i2
F00DC83C: 9006c01a                 add     %i3, %i2, %o0
F00DC840: 90020009                 add     %o0, %o1, %o0
F00DC844: 7ffe7994                 call    _kern_serv_kernel_task_port
F00DC848: a00a000a                 and     %o0, %o2, %l0
F00DC84C: 7ffe2a99                 call    _task_self
F00DC850: ba100008                 mov     %o0, %i5
F00DC854: 92100011                 mov     %l1, %o1
F00DC858: 94100010                 mov     %l0, %o2
F00DC85C: 96102000                 mov     0, %o3
F00DC860: 40005ffb                 call    _vm_protect_EXTERNAL
F00DC864: 98102001                 mov     1, %o4
F00DC868: 92920000                 orcc    %o0, %g0, %o1
F00DC86C: 02800004                 be      loc_F00DC87C
F00DC870: 113c03f1                 sethi   %hi(aAudioVmProtect), %o0! "Audio: vm_protect returned %d\n"
F00DC874: 7fffa620                 call    _IOLog
F00DC878: 90122228                 bset    %lo(aAudioVmProtect), %o0! "Audio: vm_protect returned %d\n"
F00DC87C: 9010001d                 mov     %i5, %o0
F00DC880: 9207bfec                 add     %fp, var_14, %o1
F00DC884: 94100010                 mov     %l0, %o2
F00DC888: 40005fa1                 call    _vm_allocate_EXTERNAL
F00DC88C: 96102001                 mov     1, %o3
F00DC890: 80a22000                 cmp     %o0, 0
F00DC894: 1280001a                 bne     loc_F00DC8FC
F00DC898: 92102000                 mov     0, %o1
F00DC89C: 9010001d                 mov     %i5, %o0
F00DC8A0: d207bfec                 ld      [%fp+var_14], %o1
F00DC8A4: 94100011                 mov     %l1, %o2
F00DC8A8: 40006034                 call    _vm_write_EXTERNAL
F00DC8AC: 96100010                 mov     %l0, %o3
F00DC8B0: 92920000                 orcc    %o0, %g0, %o1
F00DC8B4: 02800004                 be      loc_F00DC8C4
F00DC8B8: 113c03f1                 sethi   %hi(aAudioVmWriteRe), %o0! "Audio: vm_write returned %d\n"
F00DC8BC: 7fffa60e                 call    _IOLog
F00DC8C0: 90122248                 bset    %lo(aAudioVmWriteRe), %o0! "Audio: vm_write returned %d\n"
F00DC8C4: 7ffe2a7b                 call    _task_self
F00DC8C8: 01000000                 nop
F00DC8CC: 92100011                 mov     %l1, %o1
F00DC8D0: 40005eb6                 call    _vm_deallocate_EXTERNAL
F00DC8D4: 94100010                 mov     %l0, %o2
F00DC8D8: 92920000                 orcc    %o0, %g0, %o1
F00DC8DC: 02800004                 be      loc_F00DC8EC
F00DC8E0: 113c03f1                 sethi   %hi(aAudioVmDealloc_0), %o0! "Audio: vm_deallocate returned %d\n"
F00DC8E4: 7fffa604                 call    _IOLog
F00DC8E8: 90122268                 bset    %lo(aAudioVmDealloc_0), %o0! "Audio: vm_deallocate returned %d\n"
F00DC8EC: d007bfec                 ld      [%fp+var_14], %o0
F00DC8F0: 92102001                 mov     1, %o1
F00DC8F4: 9002001a                 add     %o0, %i2, %o0
F00DC8F8: d027bfec                 st      %o0, [%fp+var_14]
F00DC8FC: 80a26000                 cmp     %o1, 0
F00DC900: 1280000c                 bne     loc_F00DC930
F00DC904: 113c0505                 sethi   -0xFEBEC00, %o0
F00DC908: 113c03f190122290         set     aAudioPlaybackR, %o0! "Audio: playback request (%d bytes) too "...
F00DC910: 7fffa5f9                 call    _IOLog
F00DC914: 9210001b                 mov     %i3, %o1
F00DC918: 10800033                 ba      locret_F00DC9E4
F00DC91C: b0102000                 mov     0, %i0
F00DC920: e0262030                 st      %l0, [%i0+0x30]
F00DC924: d224203c                 st      %o1, [%l0+0x3C]
F00DC928: 1080001f                 ba      loc_F00DC9A4
F00DC92C: d2242040                 st      %o1, [%l0+0x40]
F00DC930: d202203c                 ld      [%o0+0x3C], %o1! SEL
F00DC934: 400053cf                 call    _objc_msgSend
F00DC938: 90100018                 mov     %i0, %o0
F00DC93C: a0100008                 mov     %o0, %l0
F00DC940: f6242010                 st      %i3, [%l0+0x10]
F00DC944: f8242014                 st      %i4, [%l0+0x14]
F00DC948: e424201c                 st      %l2, [%l0+0x1C]
F00DC94C: e6242018                 st      %l3, [%l0+0x18]
F00DC950: d007bfec                 ld      [%fp+var_14], %o0
F00DC954: 133c0504                 sethi   %hi(paLock), %o1
F00DC958: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00DC95C: d0242008                 st      %o0, [%l0+8]
F00DC960: d0240000                 st      %o0, [%l0]
F00DC964: 9002001b                 add     %o0, %i3, %o0
F00DC968: d0242004                 st      %o0, [%l0+4]
F00DC96C: e6262060                 st      %l3, [%i0+0x60]
F00DC970: d0062028                 ld      [%i0+0x28], %o0! id
F00DC974: 400053bf                 call    _objc_msgSend
F00DC978: e426205c                 st      %l2, [%i0+0x5C]
F00DC97C: 9206202c                 add     %i0, 0x2C, %o1 ! ','
F00DC980: d006202c                 ld      [%i0+0x2C], %o0
F00DC984: 80a24008                 cmp     %o1, %o0
F00DC988: 22bfffe6                 be,a    loc_F00DC920
F00DC98C: e026202c                 st      %l0, [%i0+0x2C]
F00DC990: d0062030                 ld      [%i0+0x30], %o0
F00DC994: d0242040                 st      %o0, [%l0+0x40]
F00DC998: d224203c                 st      %o1, [%l0+0x3C]
F00DC99C: e0262030                 st      %l0, [%i0+0x30]
F00DC9A0: e022203c                 st      %l0, [%o0+0x3C]
F00DC9A4: d0062028                 ld      [%i0+0x28], %o0! id
F00DC9A8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DC9AC: 400053b1                 call    _objc_msgSend
F00DC9B0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DC9B4: 113c0505                 sethi   %hi(paChannel), %o0
F00DC9B8: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DC9BC: 113c0505                 sethi   %hi(paDatapendingfor), %o0! id
F00DC9C0: e0022054                 ld      [%o0+%lo(paDatapendingfor)], %l0
F00DC9C4: e2062008                 ld      [%i0+8], %l1
F00DC9C8: 400053aa                 call    _objc_msgSend
F00DC9CC: 90100018                 mov     %i0, %o0
F00DC9D0: 94100008                 mov     %o0, %o2
F00DC9D4: 90100011                 mov     %l1, %o0! id
F00DC9D8: 400053a6                 call    _objc_msgSend
F00DC9DC: 92100010                 mov     %l0, %o1
F00DC9E0: b0102001                 mov     1, %i0
F00DC9E4: 81c7e008                 ret
F00DC9E8: 81e80000                 restore
