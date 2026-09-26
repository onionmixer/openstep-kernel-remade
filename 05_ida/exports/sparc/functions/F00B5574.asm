F00B5574: 9de3bf98                 save    %sp, -0x68, %sp
F00B5578: d05620b2                 ldsh    [%i0+0xB2], %o0
F00B557C: 912a2002                 sll     %o0, 2, %o0
F00B5580: 90020018                 add     %o0, %i0, %o0
F00B5584: e40220b8                 ld      [%o0+0xB8], %l2
F00B5588: d00e2044                 ldub    [%i0+0x44], %o0
F00B558C: 80a22020                 cmp     %o0, 0x20 ! ' '
F00B5590: 0280001a                 be      loc_F00B55F8
F00B5594: e00e2054                 ldub    [%i0+0x54], %l0
F00B5598: 90043ff6                 add     %l0, -0xA, %o0
F00B559C: 900a20ff                 and     %o0, 0xFF, %o0
F00B55A0: 80a22001                 cmp     %o0, 1
F00B55A4: 08800010                 bleu    loc_F00B55E4
F00B55A8: 90100010                 mov     %l0, %o0
F00B55AC: 213c0479                 sethi   %hi(aTargetDDidnTDi), %l0! "Target %d didn't disconnect after sendi"...
F00B55B0: e214a008                 lduh    [%l2+8], %l1
F00B55B4: 40000f89                 call    _scsi_mname
F00B55B8: a01421c8                 bset    %lo(aTargetDDidnTDi), %l0! "Target %d didn't disconnect after sendi"...
F00B55BC: 98100008                 mov     %o0, %o4
F00B55C0: 90100018                 mov     %i0, %o0
F00B55C4: 92102004                 mov     4, %o1
F00B55C8: 94100010                 mov     %l0, %o2
F00B55CC: 40000988                 call    _esplog
F00B55D0: 96100011                 mov     %l1, %o3
F00B55D4: 90102003                 mov     3, %o0
F00B55D8: d02ca028                 stb     %o0, [%l2+0x28]
F00B55DC: 10800024                 ba      locret_F00B566C
F00B55E0: b0102006                 mov     6, %i0
F00B55E4: 901020ff                 mov     0xFF, %o0
F00B55E8: d02e2052                 stb     %o0, [%i0+0x52]
F00B55EC: c02e2053                 clrb    [%i0+0x53]
F00B55F0: 1080001f                 ba      locret_F00B566C
F00B55F4: b0102003                 mov     3, %i0
F00B55F8: 40000798                 call    _esp_chip_disconnect
F00B55FC: 90100018                 mov     %i0, %o0
F00B5600: 80a42004                 cmp     %l0, 4
F00B5604: 12800016                 bne     loc_F00B565C
F00B5608: 94102003                 mov     3, %o2
F00B560C: d00ca02a                 ldub    [%l2+0x2A], %o0
F00B5610: d214a05c                 lduh    [%l2+0x5C], %o1
F00B5614: 90122001                 bset    1, %o0
F00B5618: d02ca02a                 stb     %o0, [%l2+0x2A]
F00B561C: 92126010                 bset    0x10, %o1
F00B5620: d234a05c                 sth     %o1, [%l2+0x5C]
F00B5624: d0062090                 ld      [%i0+0x90], %o0
F00B5628: 94102005                 mov     5, %o2
F00B562C: d2062088                 ld      [%i0+0x88], %o1
F00B5630: 90022001                 inc     %o0
F00B5634: d0262090                 st      %o0, [%i0+0x90]
F00B5638: 92026001                 inc     %o1
F00B563C: d00e2041                 ldub    [%i0+0x41], %o0
F00B5640: d2262088                 st      %o1, [%i0+0x88]
F00B5644: d02e2042                 stb     %o0, [%i0+0x42]
F00B5648: d01620b2                 lduh    [%i0+0xB2], %o0
F00B564C: c02e2041                 clrb    [%i0+0x41]
F00B5650: d03620b0                 sth     %o0, [%i0+0xB0]
F00B5654: 90103fff                 mov     -1, %o0
F00B5658: d03620b2                 sth     %o0, [%i0+0xB2]
F00B565C: 901020ff                 mov     0xFF, %o0
F00B5660: d02e2052                 stb     %o0, [%i0+0x52]
F00B5664: c02e2053                 clrb    [%i0+0x53]
F00B5668: b010000a                 mov     %o2, %i0
F00B566C: 81c7e008                 ret
F00B5670: 81e80000                 restore
