F0070380: 9de3bf60                 save    %sp, -0xA0, %sp
F0070384: 133c04bf                 sethi   %hi(dword_F012FF24), %o1
F0070388: d0026324                 ld      [%o1+%lo(dword_F012FF24)], %o0
F007038C: a407bfd8                 add     %fp, var_28, %l2
F0070390: a607bfc0                 add     %fp, var_40, %l3
F0070394: 80a22000                 cmp     %o0, 0
F0070398: 02800005                 be      loc_F00703AC
F007039C: a2126324                 or      %o1, %lo(dword_F012FF24), %l1
F00703A0: 113c0440                 sethi   %hi(aKdpSend), %o0! "kdp_send"
F00703A4: 400090cd                 call    _kdp_panic
F00703A8: 90122248                 bset    %lo(aKdpSend), %o0! "kdp_send"
F00703AC: 92100012                 mov     %l2, %o1! void *
F00703B0: 9410201c                 mov     0x1C, %o2! size_t
F00703B4: d0047ff8                 ld      [%l1-8], %o0
F00703B8: a0047a0c                 add     %l1, -0x5F4, %l0
F00703BC: 90023fe4                 inc     -0x1C, %o0! void *
F00703C0: d0247ff8                 st      %o0, [%l1-8]
F00703C4: 400091d3                 call    _bcopy
F00703C8: 90020010                 add     %o0, %l0, %o0
F00703CC: c027bfdc                 clr     [%fp+var_24]
F00703D0: c027bfd8                 clr     [%fp+var_28]
F00703D4: c02fbfe0                 clrb    [%fp+var_20]
F00703D8: 90102011                 mov     0x11, %o0
F00703DC: d02fbfe1                 stb     %o0, [%fp+var_1F]
F00703E0: 90102473                 mov     0x473, %o0
F00703E4: d037bfec                 sth     %o0, [%fp+var_14]
F00703E8: f037bfee                 sth     %i0, [%fp+var_12]
F00703EC: c037bff2                 clrh    [%fp+var_E]
F00703F0: d6047ffc                 ld      [%l1-4], %o3
F00703F4: 133c04f1                 sethi   %hi(_adr), %o1
F00703F8: d8026020                 ld      [%o1+%lo(_adr)], %o4
F00703FC: 9602e008                 inc     8, %o3
F0070400: d637bfe2                 sth     %o3, [%fp+var_1E]
F0070404: 92126020                 bset    %lo(_adr), %o1
F0070408: d202600c                 ld      [%o1+0xC], %o1
F007040C: 90100012                 mov     %l2, %o0! void *
F0070410: d827bfe4                 st      %o4, [%fp+var_1C]
F0070414: d227bfe8                 st      %o1, [%fp+var_18]
F0070418: d2047ff8                 ld      [%l1-8], %o1! void *
F007041C: 9410201c                 mov     0x1C, %o2! size_t
F0070420: d637bff0                 sth     %o3, [%fp+var_10]
F0070424: 400091bb                 call    _bcopy
F0070428: 92024010                 add     %o1, %l0, %o1
F007042C: 92100013                 mov     %l3, %o1! void *
F0070430: d0047ff8                 ld      [%l1-8], %o0! void *
F0070434: 94102014                 mov     0x14, %o2! size_t
F0070438: 400091b6                 call    _bcopy
F007043C: 90020010                 add     %o0, %l0, %o0
F0070440: c037bfca                 clrh    [%fp+var_36]
F0070444: 9a100013                 mov     %l3, %o5
F0070448: 86102000                 mov     0, %g3
F007044C: 84102000                 mov     0, %g2
F0070450: d0047ffc                 ld      [%l1-4], %o0
F0070454: 133c04d9                 sethi   %hi(_ip_id), %o1
F0070458: d41260a0                 lduh    [%o1+%lo(_ip_id)], %o2
F007045C: 9002201c                 inc     0x1C, %o0
F0070460: d037bfc2                 sth     %o0, [%fp+var_40+2]
F0070464: 9002a001                 add     %o2, 1, %o0
F0070468: d03260a0                 sth     %o0, [%o1+%lo(_ip_id)]
F007046C: 113c0432                 sethi   %hi(_udp_ttl), %o0
F0070470: d0022174                 ld      [%o0+%lo(_udp_ttl)], %o0
F0070474: d437bfc4                 sth     %o2, [%fp+var_3C]
F0070478: d02fbfc8                 stb     %o0, [%fp+var_38]
F007047C: d007bfc0                 ld      [%fp+var_40], %o0
F0070480: 133c0000                 sethi   -0x10000000, %o1
F0070484: 922a0009                 andn    %o0, %o1, %o1
F0070488: 11100000                 sethi   0x40000000, %o0
F007048C: 92124008                 bset    %o0, %o1
F0070490: d227bfc0                 st      %o1, [%fp+var_40]
F0070494: 1103c000                 sethi   0xF000000, %o0
F0070498: 902a4008                 andn    %o1, %o0, %o0
F007049C: 13014000                 sethi   0x5000000, %o1
F00704A0: 90120009                 bset    %o1, %o0
F00704A4: d027bfc0                 st      %o0, [%fp+var_40]
F00704A8: 91322018                 srl     %o0, 24, %o0
F00704AC: 900a200f                 and     %o0, 0xF, %o0
F00704B0: 80a22000                 cmp     %o0, 0
F00704B4: 02800011                 be      loc_F00704F8
F00704B8: 98023fff                 add     %o0, -1, %o4
F00704BC: 9607bfc2                 add     %fp, var_40+2, %o3
F00704C0: 9010000c                 mov     %o4, %o0
F00704C4: d40affff                 ldub    [%o3-1], %o2
F00704C8: 98033fff                 inc     -1, %o4
F00704CC: d20ae001                 ldub    [%o3+1], %o1
F00704D0: 80a22000                 cmp     %o0, 0
F00704D4: d00b4000                 ldub    [%o5], %o0
F00704D8: 94028009                 add     %o2, %o1, %o2
F00704DC: 8600c00a                 add     %g3, %o2, %g3
F00704E0: d20ac000                 ldub    [%o3], %o1
F00704E4: 9a036004                 inc     4, %o5
F00704E8: 90020009                 add     %o0, %o1, %o0
F00704EC: 84008008                 add     %g2, %o0, %g2
F00704F0: 12bffff4                 bne     loc_F00704C0
F00704F4: 9602e004                 inc     4, %o3
F00704F8: 9128a008                 sll     %g2, 8, %o0
F00704FC: 92020003                 add     %o0, %g3, %o1
F0070500: 95326010                 srl     %o1, 16, %o2
F0070504: 1100003f901223ff         set     0xFFFF, %o0
F007050C: 920a4008                 and     %o1, %o0, %o1
F0070510: 92028009                 add     %o2, %o1, %o1
F0070514: 80a24008                 cmp     %o1, %o0
F0070518: 38800004                 bgu,a   loc_F0070528
F007051C: 90026001                 add     %o1, 1, %o0
F0070520: 10800003                 ba      loc_F007052C
F0070524: 912a6010                 sll     %o1, 16, %o0
F0070528: 912a2010                 sll     %o0, 16, %o0
F007052C: 91322010                 srl     %o0, 16, %o0
F0070530: 90380008                 xnor    %g0, %o0, %o0
F0070534: d034e00a                 sth     %o0, [%l3+0xA]
F0070538: 90100013                 mov     %l3, %o0! void *
F007053C: 94102014                 mov     0x14, %o2! size_t
F0070540: 253c04bfa614a31c         set     unk_F012FF1C, %l3
F0070548: d204a31c                 ld      [%l2+0x31C], %o1! void *
F007054C: a804fa14                 add     %l3, -0x5EC, %l4
F0070550: 40009170                 call    _bcopy
F0070554: 92024014                 add     %o1, %l4, %o1
F0070558: 233c04f1a2146024         set     unk_F013C424, %l1
F0070560: 90100011                 mov     %l1, %o0! void *
F0070564: d204e004                 ld      [%l3+4], %o1
F0070568: 94102006                 mov     6, %o2! size_t
F007056C: e004a31c                 ld      [%l2+0x31C], %l0
F0070570: 9202601c                 inc     0x1C, %o1! void *
F0070574: d224e004                 st      %o1, [%l3+4]
F0070578: a0043ff2                 inc     -0xE, %l0
F007057C: e024a31c                 st      %l0, [%l2+0x31C]
F0070580: a0040014                 add     %l0, %l4, %l0
F0070584: 40009163                 call    _bcopy
F0070588: 92042006                 add     %l0, 6, %o1
F007058C: 9004600c                 add     %l1, 0xC, %o0! void *
F0070590: 92100010                 mov     %l0, %o1! void *
F0070594: 4000915f                 call    _bcopy
F0070598: 94102006                 mov     6, %o2
F007059C: 90102800                 mov     0x800, %o0
F00705A0: d034200c                 sth     %o0, [%l0+0xC]
F00705A4: d204e004                 ld      [%l3+4], %o1
F00705A8: d004a31c                 ld      [%l2+0x31C], %o0
F00705AC: 9202600e                 inc     0xE, %o1
F00705B0: d224e004                 st      %o1, [%l3+4]
F00705B4: 4000906f                 call    _kdp_en_send_pkt
F00705B8: 90020014                 add     %o0, %l4, %o0
F00705BC: 81c7e008                 ret
F00705C0: 81e80000                 restore
