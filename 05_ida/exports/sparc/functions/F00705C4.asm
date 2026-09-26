F00705C4: 9de3bf60                 save    %sp, -0xA0, %sp
F00705C8: 2b3c04bf                 sethi   %hi(dword_F012FF24), %l5
F00705CC: d0056324                 ld      [%l5+%lo(dword_F012FF24)], %o0
F00705D0: a607bfd8                 add     %fp, var_28, %l3
F00705D4: a807bfc0                 add     %fp, var_40, %l4
F00705D8: 80a22000                 cmp     %o0, 0
F00705DC: 02800005                 be      loc_F00705F0
F00705E0: a2156324                 or      %l5, %lo(dword_F012FF24), %l1
F00705E4: 113c0440                 sethi   %hi(aKdpPoll), %o0! "kdp_poll"
F00705E8: 4000903c                 call    _kdp_panic
F00705EC: 90122258                 bset    %lo(aKdpPoll), %o0! "kdp_poll"
F00705F0: c0247ff8                 clr     [%l1-8]
F00705F4: a0047a0c                 add     %l1, -0x5F4, %l0
F00705F8: 90100010                 mov     %l0, %o0
F00705FC: 92047ffc                 add     %l1, -4, %o1
F0070600: 40009062                 call    _kdp_en_recv_pkt
F0070604: 94102003                 mov     3, %o2! size_t
F0070608: d0047ffc                 ld      [%l1-4], %o0
F007060C: 80a22000                 cmp     %o0, 0
F0070610: 02800039                 be      locret_F00706F4
F0070614: 80a22029                 cmp     %o0, 0x29 ! ')'
F0070618: 08800037                 bleu    locret_F00706F4
F007061C: 01000000                 nop
F0070620: d0047ff8                 ld      [%l1-8], %o0
F0070624: 9202200e                 add     %o0, 0xE, %o1
F0070628: d2247ff8                 st      %o1, [%l1-8]
F007062C: a4020010                 add     %o0, %l0, %l2
F0070630: d014a00c                 lduh    [%l2+0xC], %o0
F0070634: 80a22800                 cmp     %o0, 0x800
F0070638: 1280002f                 bne     locret_F00706F4
F007063C: 90024010                 add     %o1, %l0, %o0! void *
F0070640: 92100013                 mov     %l3, %o1! void *
F0070644: 40009133                 call    _bcopy
F0070648: 9410201c                 mov     0x1C, %o2
F007064C: 92100014                 mov     %l4, %o1! void *
F0070650: d0047ff8                 ld      [%l1-8], %o0! void *
F0070654: 94102014                 mov     0x14, %o2! size_t
F0070658: 4000912e                 call    _bcopy
F007065C: 90020010                 add     %o0, %l0, %o0
F0070660: d0047ff8                 ld      [%l1-8], %o0
F0070664: d20fbfe1                 ldub    [%fp+var_1F], %o1
F0070668: 9002201c                 inc     0x1C, %o0
F007066C: 80a26011                 cmp     %o1, 0x11
F0070670: 12800021                 bne     locret_F00706F4
F0070674: d0247ff8                 st      %o0, [%l1-8]
F0070678: d00fbfc0                 ldub    [%fp+var_40], %o0
F007067C: 900a200f                 and     %o0, 0xF, %o0
F0070680: 80a22005                 cmp     %o0, 5
F0070684: 1880001c                 bgu     locret_F00706F4
F0070688: d017bfee                 lduh    [%fp+var_12], %o0
F007068C: 80a22473                 cmp     %o0, 0x473
F0070690: 12800019                 bne     locret_F00706F4
F0070694: 113c04f1                 sethi   %hi(dword_F013C408), %o0
F0070698: d0022008                 ld      [%o0+%lo(dword_F013C408)], %o0
F007069C: 80a22000                 cmp     %o0, 0
F00706A0: 12800011                 bne     loc_F00706E4
F00706A4: d017bff0                 lduh    [%fp+var_10], %o0
F00706A8: 90100012                 mov     %l2, %o0! void *
F00706AC: 213c04f1a0142024         set     unk_F013C424, %l0
F00706B4: 92100010                 mov     %l0, %o1! void *
F00706B8: 40009116                 call    _bcopy
F00706BC: 94102006                 mov     6, %o2
F00706C0: 9004a006                 add     %l2, 6, %o0! void *
F00706C4: 9204200c                 add     %l0, 0xC, %o1! void *
F00706C8: d607bfe8                 ld      [%fp+var_18], %o3
F00706CC: 94102006                 mov     6, %o2! size_t
F00706D0: 40009110                 call    _bcopy
F00706D4: d6243ffc                 st      %o3, [%l0-4]
F00706D8: d007bfe4                 ld      [%fp+var_1C], %o0
F00706DC: d0242008                 st      %o0, [%l0+8]
F00706E0: d017bff0                 lduh    [%fp+var_10], %o0
F00706E4: 92102001                 mov     1, %o1
F00706E8: d2256324                 st      %o1, [%l5+0x324]
F00706EC: 90023ff8                 inc     -8, %o0
F00706F0: d0247ffc                 st      %o0, [%l1-4]
F00706F4: 81c7e008                 ret
F00706F8: 81e80000                 restore
