F0069034: 9de3bf98                 save    %sp, -0x68, %sp
F0069038: a0062008                 add     %i0, 8, %l0
F006903C: d0040000                 ld      [%l0], %o0
F0069040: 80a22000                 cmp     %o0, 0
F0069044: 12bffffe                 bne     loc_F006903C
F0069048: 01000000                 nop
F006904C: 4000b797                 call    _simple_lock_try
F0069050: 90100010                 mov     %l0, %o0
F0069054: 80a22000                 cmp     %o0, 0
F0069058: 02bffff9                 be      loc_F006903C
F006905C: 01000000                 nop
F0069060: d0162004                 lduh    [%i0+4], %o0
F0069064: 80a22000                 cmp     %o0, 0
F0069068: 02800004                 be      loc_F0069078
F006906C: 90023fff                 inc     -1, %o0
F0069070: 10800011                 ba      loc_F00690B4
F0069074: d0362004                 sth     %o0, [%i0+4]
F0069078: d2062004                 ld      [%i0+4], %o1
F006907C: 908a6fff                 andcc   %o1, 0xFFF, %o0
F0069080: 02800007                 be      loc_F006909C
F0069084: 90023fff                 inc     -1, %o0
F0069088: 920a7000                 and     %o1, -0x1000, %o1
F006908C: 900a2fff                 and     %o0, 0xFFF, %o0
F0069090: 92124008                 bset    %o0, %o1
F0069094: 10800008                 ba      loc_F00690B4
F0069098: d2262004                 st      %o1, [%i0+4]
F006909C: 11000020                 sethi   0x8000, %o0
F00690A0: 808a4008                 btst    %o0, %o1
F00690A4: 22800002                 be,a    loc_F00690AC
F00690A8: 11000010                 sethi   0x4000, %o0
F00690AC: 902a4008                 andn    %o1, %o0, %o0
F00690B0: d0262004                 st      %o0, [%i0+4]
F00690B4: d4062004                 ld      [%i0+4], %o2
F00690B8: 113fffc8                 sethi   -0xE000, %o0
F00690BC: 13000008                 sethi   0x2000, %o1
F00690C0: 900a8008                 and     %o2, %o0, %o0
F00690C4: 80a20009                 cmp     %o0, %o1
F00690C8: 12800008                 bne     loc_F00690E8
F00690CC: 11000008                 sethi   0x2000, %o0
F00690D0: 902a8008                 andn    %o2, %o0, %o0
F00690D4: d0262004                 st      %o0, [%i0+4]
F00690D8: 90100018                 mov     %i0, %o0
F00690DC: 92102000                 mov     0, %o1
F00690E0: 40001fc7                 call    _thread_wakeup_prim
F00690E4: 94102000                 mov     0, %o2
F00690E8: c0262008                 clr     [%i0+8]
F00690EC: 81c7e008                 ret
F00690F0: 81e80000                 restore
