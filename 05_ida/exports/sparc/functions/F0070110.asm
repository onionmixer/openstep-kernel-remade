F0070110: 9de3bf58                 save    %sp, -0xA8, %sp
F0070114: 133c04bf                 sethi   %hi(dword_F012FF24), %o1
F0070118: d0026324                 ld      [%o1+%lo(dword_F012FF24)], %o0
F007011C: a407bfd8                 add     %fp, var_28, %l2
F0070120: a607bfc0                 add     %fp, var_40, %l3
F0070124: 80a22000                 cmp     %o0, 0
F0070128: 12800005                 bne     loc_F007013C
F007012C: a2126324                 or      %o1, %lo(dword_F012FF24), %l1
F0070130: 113c0440                 sethi   %hi(aKdpReply), %o0! "kdp_reply"
F0070134: 40009169                 call    _kdp_panic
F0070138: 90122238                 bset    %lo(aKdpReply), %o0! "kdp_reply"
F007013C: 92100012                 mov     %l2, %o1! void *
F0070140: 9410201c                 mov     0x1C, %o2! size_t
F0070144: d0047ff8                 ld      [%l1-8], %o0
F0070148: a0047a0c                 add     %l1, -0x5F4, %l0
F007014C: 90023fe4                 inc     -0x1C, %o0! void *
F0070150: d0247ff8                 st      %o0, [%l1-8]
F0070154: 4000926f                 call    _bcopy
F0070158: 90020010                 add     %o0, %l0, %o0
F007015C: c027bfdc                 clr     [%fp+var_24]
F0070160: c027bfd8                 clr     [%fp+var_28]
F0070164: c02fbfe0                 clrb    [%fp+var_20]
F0070168: 90102011                 mov     0x11, %o0
F007016C: d02fbfe1                 stb     %o0, [%fp+var_1F]
F0070170: 90102473                 mov     0x473, %o0
F0070174: d037bfec                 sth     %o0, [%fp+var_14]
F0070178: f037bfee                 sth     %i0, [%fp+var_12]
F007017C: c037bff2                 clrh    [%fp+var_E]
F0070180: d6047ffc                 ld      [%l1-4], %o3
F0070184: d807bfe4                 ld      [%fp+var_1C], %o4
F0070188: 90100012                 mov     %l2, %o0! void *
F007018C: d207bfe8                 ld      [%fp+var_18], %o1
F0070190: 9602e008                 inc     8, %o3
F0070194: d637bfe2                 sth     %o3, [%fp+var_1E]
F0070198: d227bfe4                 st      %o1, [%fp+var_1C]
F007019C: d827bfe8                 st      %o4, [%fp+var_18]
F00701A0: d2047ff8                 ld      [%l1-8], %o1! void *
F00701A4: 9410201c                 mov     0x1C, %o2! size_t
F00701A8: d637bff0                 sth     %o3, [%fp+var_10]
F00701AC: 40009259                 call    _bcopy
F00701B0: 92024010                 add     %o1, %l0, %o1
F00701B4: 92100013                 mov     %l3, %o1! void *
F00701B8: d0047ff8                 ld      [%l1-8], %o0! void *
F00701BC: 94102014                 mov     0x14, %o2! size_t
F00701C0: 40009254                 call    _bcopy
F00701C4: 90020010                 add     %o0, %l0, %o0
F00701C8: c037bfca                 clrh    [%fp+var_36]
F00701CC: 9a100013                 mov     %l3, %o5
F00701D0: 86102000                 mov     0, %g3
F00701D4: 84102000                 mov     0, %g2
F00701D8: d0047ffc                 ld      [%l1-4], %o0
F00701DC: 133c04d9                 sethi   %hi(_ip_id), %o1
F00701E0: d41260a0                 lduh    [%o1+%lo(_ip_id)], %o2
F00701E4: 9002201c                 inc     0x1C, %o0
F00701E8: d037bfc2                 sth     %o0, [%fp+var_40+2]
F00701EC: 9002a001                 add     %o2, 1, %o0
F00701F0: d03260a0                 sth     %o0, [%o1+%lo(_ip_id)]
F00701F4: 113c0432                 sethi   %hi(_udp_ttl), %o0
F00701F8: d0022174                 ld      [%o0+%lo(_udp_ttl)], %o0
F00701FC: d437bfc4                 sth     %o2, [%fp+var_3C]
F0070200: d02fbfc8                 stb     %o0, [%fp+var_38]
F0070204: d007bfc0                 ld      [%fp+var_40], %o0
F0070208: 133c0000                 sethi   -0x10000000, %o1
F007020C: 922a0009                 andn    %o0, %o1, %o1
F0070210: 11100000                 sethi   0x40000000, %o0
F0070214: 92124008                 bset    %o0, %o1
F0070218: d227bfc0                 st      %o1, [%fp+var_40]
F007021C: 1103c000                 sethi   0xF000000, %o0
F0070220: 902a4008                 andn    %o1, %o0, %o0
F0070224: 13014000                 sethi   0x5000000, %o1
F0070228: 90120009                 bset    %o1, %o0
F007022C: d027bfc0                 st      %o0, [%fp+var_40]
F0070230: 91322018                 srl     %o0, 24, %o0
F0070234: 900a200f                 and     %o0, 0xF, %o0
F0070238: 80a22000                 cmp     %o0, 0
F007023C: 02800011                 be      loc_F0070280
F0070240: 98023fff                 add     %o0, -1, %o4
F0070244: 9607bfc2                 add     %fp, var_40+2, %o3
F0070248: 9010000c                 mov     %o4, %o0
F007024C: d40affff                 ldub    [%o3-1], %o2
F0070250: 98033fff                 inc     -1, %o4
F0070254: d20ae001                 ldub    [%o3+1], %o1
F0070258: 80a22000                 cmp     %o0, 0
F007025C: d00b4000                 ldub    [%o5], %o0
F0070260: 94028009                 add     %o2, %o1, %o2
F0070264: 8600c00a                 add     %g3, %o2, %g3
F0070268: d20ac000                 ldub    [%o3], %o1
F007026C: 9a036004                 inc     4, %o5
F0070270: 90020009                 add     %o0, %o1, %o0
F0070274: 84008008                 add     %g2, %o0, %g2
F0070278: 12bffff4                 bne     loc_F0070248
F007027C: 9602e004                 inc     4, %o3
F0070280: 9128a008                 sll     %g2, 8, %o0
F0070284: 92020003                 add     %o0, %g3, %o1
F0070288: 95326010                 srl     %o1, 16, %o2
F007028C: 1100003f901223ff         set     0xFFFF, %o0
F0070294: 920a4008                 and     %o1, %o0, %o1
F0070298: 92028009                 add     %o2, %o1, %o1
F007029C: 80a24008                 cmp     %o1, %o0
F00702A0: 38800004                 bgu,a   loc_F00702B0
F00702A4: 90026001                 add     %o1, 1, %o0
F00702A8: 10800003                 ba      loc_F00702B4
F00702AC: 912a6010                 sll     %o1, 16, %o0
F00702B0: 912a2010                 sll     %o0, 16, %o0
F00702B4: 91322010                 srl     %o0, 16, %o0
F00702B8: 90380008                 xnor    %g0, %o0, %o0
F00702BC: d034e00a                 sth     %o0, [%l3+0xA]
F00702C0: 90100013                 mov     %l3, %o0! void *
F00702C4: 94102014                 mov     0x14, %o2! size_t
F00702C8: 273c04bfa414e31c         set     unk_F012FF1C, %l2
F00702D0: d204e31c                 ld      [%l3+0x31C], %o1! void *
F00702D4: a804ba14                 add     %l2, -0x5EC, %l4
F00702D8: 4000920e                 call    _bcopy
F00702DC: 92024014                 add     %o1, %l4, %o1
F00702E0: 9207bfb8                 add     %fp, var_48, %o1! void *
F00702E4: d004a004                 ld      [%l2+4], %o0
F00702E8: 94102006                 mov     6, %o2! size_t
F00702EC: e004e31c                 ld      [%l3+0x31C], %l0
F00702F0: 9002201c                 inc     0x1C, %o0! void *
F00702F4: d024a004                 st      %o0, [%l2+4]
F00702F8: a0043ff2                 inc     -0xE, %l0
F00702FC: e024e31c                 st      %l0, [%l3+0x31C]
F0070300: a0040014                 add     %l0, %l4, %l0
F0070304: a2042006                 add     %l0, 6, %l1
F0070308: 40009202                 call    _bcopy
F007030C: 90100011                 mov     %l1, %o0
F0070310: 90100010                 mov     %l0, %o0! void *
F0070314: 92100011                 mov     %l1, %o1! void *
F0070318: 400091fe                 call    _bcopy
F007031C: 94102006                 mov     6, %o2! size_t
F0070320: 9007bfb8                 add     %fp, var_48, %o0! void *
F0070324: 92100010                 mov     %l0, %o1! void *
F0070328: 400091fa                 call    _bcopy
F007032C: 94102006                 mov     6, %o2
F0070330: 90102800                 mov     0x800, %o0
F0070334: d034200c                 sth     %o0, [%l0+0xC]
F0070338: 90100014                 mov     %l4, %o0! void *
F007033C: 133c04bf92126328         set     unk_F012FF28, %o1! void *
F0070344: d604a004                 ld      [%l2+4], %o3
F0070348: 941025f8                 mov     0x5F8, %o2! size_t
F007034C: 9602e00e                 inc     0xE, %o3
F0070350: 400091f0                 call    _bcopy
F0070354: d624a004                 st      %o3, [%l2+4]
F0070358: d004e31c                 ld      [%l3+0x31C], %o0
F007035C: d204a004                 ld      [%l2+4], %o1
F0070360: 40009104                 call    _kdp_en_send_pkt
F0070364: 90020014                 add     %o0, %l4, %o0
F0070368: 133c04be                 sethi   %hi(unk_F012F92C), %o1
F007036C: d00a612c                 ldub    [%o1+%lo(unk_F012F92C)], %o0
F0070370: 90022001                 inc     %o0
F0070374: d02a612c                 stb     %o0, [%o1+%lo(unk_F012F92C)]
F0070378: 81c7e008                 ret
F007037C: 81e80000                 restore
