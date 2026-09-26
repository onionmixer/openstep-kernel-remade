F003106C: 9de3bf90                 save    %sp, -0x70, %sp
F0031070: d00e0000                 ldub    [%i0], %o0
F0031074: 80a66005                 cmp     %i1, 5
F0031078: 900a200f                 and     %o0, 0xF, %o0
F003107C: 02800006                 be      loc_F0031094
F0031080: a72a2002                 sll     %o0, 2, %l3
F0031084: 133c04d9                 sethi   %hi(_icmpstat), %o1
F0031088: d0026160                 ld      [%o1+%lo(_icmpstat)], %o0
F003108C: 90022001                 inc     %o0
F0031090: d0226160                 st      %o0, [%o1+%lo(_icmpstat)]
F0031094: d2162006                 lduh    [%i0+6], %o1
F0031098: 113fffd8                 sethi   -0xA000, %o0
F003109C: 80aa4008                 andncc  %o1, %o0, %g0
F00310A0: 1280007e                 bne     loc_F0031298
F00310A4: 01000000                 nop
F00310A8: d00e2009                 ldub    [%i0+9], %o0
F00310AC: 80a22001                 cmp     %o0, 1
F00310B0: 3280001e                 bne,a   loc_F0031128
F00310B4: d4062010                 ld      [%i0+0x10], %o2
F00310B8: 80a66005                 cmp     %i1, 5
F00310BC: 2280001b                 be,a    loc_F0031128
F00310C0: d4062010                 ld      [%i0+0x10], %o2
F00310C4: d20e0013                 ldub    [%i0+%l3], %o1
F00310C8: 900a60ff                 and     %o1, 0xFF, %o0
F00310CC: 80a22000                 cmp     %o0, 0
F00310D0: 02800015                 be      loc_F0031124
F00310D4: 80a22008                 cmp     %o0, 8
F00310D8: 02800013                 be      loc_F0031124
F00310DC: 90027ff3                 add     %o1, -0xD, %o0
F00310E0: 900a20ff                 and     %o0, 0xFF, %o0
F00310E4: 80a22001                 cmp     %o0, 1
F00310E8: 0880000f                 bleu    loc_F0031124
F00310EC: 90027ff1                 add     %o1, -0xF, %o0
F00310F0: 900a20ff                 and     %o0, 0xFF, %o0
F00310F4: 80a22001                 cmp     %o0, 1
F00310F8: 0880000b                 bleu    loc_F0031124
F00310FC: 90027fef                 add     %o1, -0x11, %o0
F0031100: 900a20ff                 and     %o0, 0xFF, %o0
F0031104: 80a22001                 cmp     %o0, 1
F0031108: 08800007                 bleu    loc_F0031124
F003110C: 133c04d9                 sethi   %hi(_icmpstat), %o1
F0031110: 92126160                 bset    %lo(_icmpstat), %o1
F0031114: d0026008                 ld      [%o1+8], %o0
F0031118: 90022001                 inc     %o0
F003111C: 1080005f                 ba      loc_F0031298
F0031120: d0226008                 st      %o0, [%o1+8]
F0031124: d4062010                 ld      [%i0+0x10], %o2
F0031128: 113c0000                 sethi   -0x10000000, %o0
F003112C: 13380000                 sethi   -0x20000000, %o1
F0031130: 900a8008                 and     %o2, %o0, %o0
F0031134: 80a20009                 cmp     %o0, %o1
F0031138: 02800058                 be      loc_F0031298
F003113C: 01000000                 nop
F0031140: d427bff4                 st      %o2, [%fp+var_C]
F0031144: 7ffff871                 call    _in_broadcast
F0031148: 9007bff4                 add     %fp, var_C, %o0
F003114C: 80a22000                 cmp     %o0, 0
F0031150: 12800052                 bne     loc_F0031298
F0031154: 90102000                 mov     0, %o0
F0031158: 7fffb201                 call    _m_get
F003115C: 92102002                 mov     2, %o1
F0031160: a2920000                 orcc    %o0, %g0, %l1
F0031164: 0280004d                 be      loc_F0031298
F0031168: 01000000                 nop
F003116C: d0562002                 ldsh    [%i0+2], %o0
F0031170: 80a22008                 cmp     %o0, 8
F0031174: 14800003                 bg      loc_F0031180
F0031178: a804e008                 add     %l3, 8, %l4
F003117C: a804c008                 add     %l3, %o0, %l4
F0031180: 90052008                 add     %l4, 8, %o0
F0031184: d0346008                 sth     %o0, [%l1+8]
F0031188: 912a2010                 sll     %o0, 16, %o0
F003118C: 913a2010                 sra     %o0, 16, %o0
F0031190: 9210207c                 mov     0x7C, %o1 ! '|'
F0031194: a4224008                 sub     %o1, %o0, %l2
F0031198: e4246004                 st      %l2, [%l1+4]
F003119C: 80a66012                 cmp     %i1, 0x12
F00311A0: 08800005                 bleu    loc_F00311B4
F00311A4: a0044012                 add     %l1, %l2, %l0
F00311A8: 113c0431                 sethi   %hi(aIcmpError), %o0! "icmp_error"
F00311AC: 7fff8ff1                 call    _panic
F00311B0: 90122320                 bset    %lo(aIcmpError), %o0! "icmp_error"
F00311B4: 113c04d99012216c         set     unk_F013656C, %o0
F00311BC: 952e6002                 sll     %i1, 2, %o2! size_t
F00311C0: d2028008                 ld      [%o2+%o0], %o1
F00311C4: 80a66005                 cmp     %i1, 5
F00311C8: 92026001                 inc     %o1
F00311CC: d2228008                 st      %o1, [%o2+%o0]
F00311D0: 12800005                 bne     loc_F00311E4
F00311D4: f22c4012                 stb     %i1, [%l1+%l2]
F00311D8: d0070000                 ld      [%i4], %o0
F00311DC: 10800003                 ba      loc_F00311E8
F00311E0: d0242004                 st      %o0, [%l0+4]
F00311E4: c0242004                 clr     [%l0+4]
F00311E8: 80a6600c                 cmp     %i1, 0xC
F00311EC: 32800005                 bne,a   loc_F0031200
F00311F0: f42c2001                 stb     %i2, [%l0+1]
F00311F4: f42c2004                 stb     %i2, [%l0+4]
F00311F8: b4102000                 mov     0, %i2
F00311FC: f42c2001                 stb     %i2, [%l0+1]
F0031200: 90100018                 mov     %i0, %o0! void *
F0031204: 92042008                 add     %l0, 8, %o1! void *
F0031208: 40018e42                 call    _bcopy
F003120C: 94100014                 mov     %l4, %o2
F0031210: d014200a                 lduh    [%l0+0xA], %o0
F0031214: 90020013                 add     %o0, %l3, %o0
F0031218: d034200a                 sth     %o0, [%l0+0xA]
F003121C: d2546008                 ldsh    [%l1+8], %o1
F0031220: 90024013                 add     %o1, %l3, %o0
F0031224: 80a22070                 cmp     %o0, 0x70 ! 'p'
F0031228: 38800002                 bgu,a   loc_F0031230
F003122C: a6102014                 mov     0x14, %l3
F0031230: 90024013                 add     %o1, %l3, %o0
F0031234: 80a22070                 cmp     %o0, 0x70 ! 'p'
F0031238: 28800006                 bleu,a  loc_F0031250
F003123C: 90100018                 mov     %i0, %o0
F0031240: 113c0431                 sethi   %hi(aIcmpLen), %o0! "icmp len"
F0031244: 7fff8fcb                 call    _panic
F0031248: 90122330                 bset    %lo(aIcmpLen), %o0! "icmp len"
F003124C: 90100018                 mov     %i0, %o0! void *
F0031250: d2046004                 ld      [%l1+4], %o1
F0031254: 94100013                 mov     %l3, %o2! size_t
F0031258: d6146008                 lduh    [%l1+8], %o3
F003125C: 9222400a                 sub     %o1, %o2, %o1! void *
F0031260: d2246004                 st      %o1, [%l1+4]
F0031264: 9602c00a                 add     %o3, %o2, %o3
F0031268: e0046004                 ld      [%l1+4], %l0
F003126C: d6346008                 sth     %o3, [%l1+8]
F0031270: a0044010                 add     %l1, %l0, %l0
F0031274: 40018e27                 call    _bcopy
F0031278: 92100010                 mov     %l0, %o1
F003127C: 90100010                 mov     %l0, %o0
F0031280: d4146008                 lduh    [%l1+8], %o2
F0031284: 9210001b                 mov     %i3, %o1
F0031288: d4322002                 sth     %o2, [%o0+2]
F003128C: 94102001                 mov     1, %o2
F0031290: 40000185                 call    _icmp_reflect
F0031294: d42a2009                 stb     %o2, [%o0+9]
F0031298: 7fffb273                 call    _m_freem
F003129C: 900e3f80                 and     %i0, -0x80, %o0
F00312A0: 81c7e008                 ret
F00312A4: 81e80000                 restore
