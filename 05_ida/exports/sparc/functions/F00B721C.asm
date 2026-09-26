F00B721C: 9de3be98                 save    %sp, -0x168, %sp
F00B7220: a0100018                 mov     %i0, %l0
F00B7224: d05420b2                 ldsh    [%l0+0xB2], %o0
F00B7228: 80a23fff                 cmp     %o0, -1
F00B722C: 12800003                 bne     loc_F00B7238
F00B7230: f01420b2                 lduh    [%l0+0xB2], %i0
F00B7234: b0102000                 mov     0, %i0
F00B7238: 900420b8                 add     %l0, 0xB8, %o0! void *
F00B723C: 9207bef8                 add     %fp, var_108, %o1! void *
F00B7240: e80c2083                 ldub    [%l0+0x83], %l4
F00B7244: 7fff7633                 call    _bcopy
F00B7248: 94102100                 mov     0x100, %o2
F00B724C: d00c2041                 ldub    [%l0+0x41], %o0
F00B7250: 90023fe4                 inc     -0x1C, %o0
F00B7254: 900a20ff                 and     %o0, 0xFF, %o0
F00B7258: 80a22001                 cmp     %o0, 1
F00B725C: 0880000a                 bleu    loc_F00B7284
F00B7260: a6102004                 mov     4, %l3
F00B7264: 90100010                 mov     %l0, %o0
F00B7268: 4000017f                 call    _esp_internal_reset
F00B726C: 92102003                 mov     3, %o1
F00B7270: 90100010                 mov     %l0, %o0
F00B7274: 92102005                 mov     5, %o1
F00B7278: 153c047a                 sethi   %hi(aUnexpectedScsi), %o2! "unexpected SCSI bus reset"
F00B727C: 4000025c                 call    _esplog
F00B7280: 9412a318                 bset    %lo(aUnexpectedScsi), %o2! "unexpected SCSI bus reset"
F00B7284: 90100010                 mov     %l0, %o0
F00B7288: 40000177                 call    _esp_internal_reset
F00B728C: 92102010                 mov     0x10, %o1
F00B7290: a407bff8                 add     %fp, var_8, %l2
F00B7294: d00c2041                 ldub    [%l0+0x41], %o0
F00B7298: 932e2010                 sll     %i0, 16, %o1
F00B729C: a33a6010                 sra     %o1, 16, %l1
F00B72A0: d02c2042                 stb     %o0, [%l0+0x42]
F00B72A4: 9010201f                 mov     0x1F, %o0
F00B72A8: d02c2041                 stb     %o0, [%l0+0x41]
F00B72AC: 912e2010                 sll     %i0, 16, %o0
F00B72B0: 913a200e                 sra     %o0, 14, %o0
F00B72B4: 90020012                 add     %o0, %l2, %o0
F00B72B8: d2023f00                 ld      [%o0-0x100], %o1
F00B72BC: 80a26000                 cmp     %o1, 0
F00B72C0: 0280000e                 be      loc_F00B72F8
F00B72C4: 90062001                 add     %i0, 1, %o0
F00B72C8: d00a6028                 ldub    [%o1+0x28], %o0
F00B72CC: 80a22000                 cmp     %o0, 0
F00B72D0: 22800002                 be,a    loc_F00B72D8
F00B72D4: e62a6028                 stb     %l3, [%o1+0x28]
F00B72D8: d0026040                 ld      [%o1+0x40], %o0
F00B72DC: d4026010                 ld      [%o1+0x10], %o2
F00B72E0: 80a2a000                 cmp     %o2, 0
F00B72E4: 02800004                 be      loc_F00B72F4
F00B72E8: d0226024                 st      %o0, [%o1+0x24]
F00B72EC: 9fc28000                 call    %o2
F00B72F0: 90100009                 mov     %o1, %o0
F00B72F4: 90062001                 add     %i0, 1, %o0
F00B72F8: 900a203f                 and     %o0, 0x3F, %o0
F00B72FC: 80a20011                 cmp     %o0, %l1
F00B7300: 12bfffeb                 bne     loc_F00B72AC
F00B7304: b0100008                 mov     %o0, %i0
F00B7308: d00c2041                 ldub    [%l0+0x41], %o0
F00B730C: b0103fff                 mov     -1, %i0
F00B7310: d02c2042                 stb     %o0, [%l0+0x42]
F00B7314: d0042084                 ld      [%l0+0x84], %o0
F00B7318: 80a22000                 cmp     %o0, 0
F00B731C: 02800005                 be      locret_F00B7330
F00B7320: c02c2041                 clrb    [%l0+0x41]
F00B7324: 80a52000                 cmp     %l4, 0
F00B7328: 22800002                 be,a    locret_F00B7330
F00B732C: b0102005                 mov     5, %i0
F00B7330: 81c7e008                 ret
F00B7334: 81e80000                 restore
