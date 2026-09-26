F004E318: 9de3bf98                 save    %sp, -0x68, %sp
F004E31C: d0162044                 lduh    [%i0+0x44], %o0
F004E320: 808a2001                 btst    1, %o0
F004E324: 32800006                 bne,a   loc_F004E33C
F004E328: d2162044                 lduh    [%i0+0x44], %o1
F004E32C: 113c043b                 sethi   %hi(aIdrop), %o0! "idrop"
F004E330: 7fff1b90                 call    _panic
F004E334: 90122098                 bset    %lo(aIdrop), %o0! "idrop"
F004E338: d2162044                 lduh    [%i0+0x44], %o1
F004E33C: 1100003f901223fe         set     0xFFFE, %o0
F004E344: 920a4008                 and     %o1, %o0, %o1
F004E348: 808a6010                 btst    0x10, %o1
F004E34C: 02800008                 be      loc_F004E36C
F004E350: d2362044                 sth     %o1, [%i0+0x44]
F004E354: 1100003f901223ef         set     0xFFEF, %o0
F004E35C: 900a4008                 and     %o1, %o0, %o0
F004E360: d0362044                 sth     %o0, [%i0+0x44]
F004E364: 7fff12a1                 call    _wakeup
F004E368: 90100018                 mov     %i0, %o0
F004E36C: d0162012                 lduh    [%i0+0x12], %o0
F004E370: 90023fff                 inc     -1, %o0
F004E374: d0362012                 sth     %o0, [%i0+0x12]
F004E378: 912a2010                 sll     %o0, 16, %o0
F004E37C: 80a22000                 cmp     %o0, 0
F004E380: 12800012                 bne     locret_F004E3C8
F004E384: 133c04eb                 sethi   %hi(_ifreeh), %o1
F004E388: d00261a0                 ld      [%o1+%lo(_ifreeh)], %o0
F004E38C: c0362044                 clrh    [%i0+0x44]
F004E390: 80a22000                 cmp     %o0, 0
F004E394: 02800007                 be      loc_F004E3B0
F004E398: 901261a0                 or      %o1, %lo(_ifreeh), %o0
F004E39C: 113c04eb                 sethi   %hi(_ifreet), %o0
F004E3A0: d20221a8                 ld      [%o0+%lo(_ifreet)], %o1
F004E3A4: f0224000                 st      %i0, [%o1]
F004E3A8: 10800003                 ba      loc_F004E3B4
F004E3AC: d00221a8                 ld      [%o0+%lo(_ifreet)], %o0
F004E3B0: f02261a0                 st      %i0, [%o1+0x1A0]
F004E3B4: d0262060                 st      %o0, [%i0+0x60]
F004E3B8: c026205c                 clr     [%i0+0x5C]
F004E3BC: 9206205c                 add     %i0, 0x5C, %o1 ! '\'
F004E3C0: 113c04eb                 sethi   %hi(_ifreet), %o0
F004E3C4: d22221a8                 st      %o1, [%o0+%lo(_ifreet)]
F004E3C8: 81c7e008                 ret
F004E3CC: 81e80000                 restore
