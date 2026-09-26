F0046758: 9de3bf98                 save    %sp, -0x68, %sp
F004675C: 80a6a001                 cmp     %i2, 1
F0046760: 14800056                 bg      locret_F00468B8
F0046764: f0062030                 ld      [%i0+0x30], %i0
F0046768: 808e6001                 btst    1, %i1
F004676C: 2280001e                 be,a    loc_F00467E4
F0046770: d0062074                 ld      [%i0+0x74], %o0
F0046774: d0162082                 lduh    [%i0+0x82], %o0
F0046778: 90023fff                 inc     -1, %o0
F004677C: d0362082                 sth     %o0, [%i0+0x82]
F0046780: 912a2010                 sll     %o0, 16, %o0
F0046784: 80a22000                 cmp     %o0, 0
F0046788: 32800017                 bne,a   loc_F00467E4
F004678C: d0062074                 ld      [%i0+0x74], %o0
F0046790: d0162088                 lduh    [%i0+0x88], %o0
F0046794: 808a2002                 btst    2, %o0
F0046798: 02800005                 be      loc_F00467AC
F004679C: 900a3ffd                 and     %o0, -3, %o0
F00467A0: d0362088                 sth     %o0, [%i0+0x88]
F00467A4: 7fff3191                 call    _wakeup
F00467A8: 90062080                 add     %i0, 0x80, %o0
F00467AC: d0062078                 ld      [%i0+0x78], %o0
F00467B0: 80a22000                 cmp     %o0, 0
F00467B4: 2280000c                 be,a    loc_F00467E4
F00467B8: d0062074                 ld      [%i0+0x74], %o0
F00467BC: d2162088                 lduh    [%i0+0x88], %o1
F00467C0: 7fff3e55                 call    _selwakeup
F00467C4: 920a6010                 and     %o1, 0x10, %o1
F00467C8: 4000b6f9                 call    _thread_deallocate
F00467CC: d0062078                 ld      [%i0+0x78], %o0
F00467D0: d0162088                 lduh    [%i0+0x88], %o0
F00467D4: c0262078                 clr     [%i0+0x78]
F00467D8: 900a3fef                 and     %o0, -0x11, %o0
F00467DC: d0362088                 sth     %o0, [%i0+0x88]
F00467E0: d0062074                 ld      [%i0+0x74], %o0
F00467E4: 80a22000                 cmp     %o0, 0
F00467E8: 22800006                 be,a    loc_F0046800
F00467EC: d0062070                 ld      [%i0+0x70], %o0
F00467F0: 4000b6ef                 call    _thread_deallocate
F00467F4: 01000000                 nop
F00467F8: c0262074                 clr     [%i0+0x74]
F00467FC: d0062070                 ld      [%i0+0x70], %o0
F0046800: 80a22000                 cmp     %o0, 0
F0046804: 02800006                 be      loc_F004681C
F0046808: 808e6002                 btst    2, %i1
F004680C: 4000b6e8                 call    _thread_deallocate
F0046810: 01000000                 nop
F0046814: c0262070                 clr     [%i0+0x70]
F0046818: 808e6002                 btst    2, %i1
F004681C: 22800011                 be,a    loc_F0046860
F0046820: d0062080                 ld      [%i0+0x80], %o0
F0046824: d0162080                 lduh    [%i0+0x80], %o0
F0046828: 90023fff                 inc     -1, %o0
F004682C: d0362080                 sth     %o0, [%i0+0x80]
F0046830: 912a2010                 sll     %o0, 16, %o0
F0046834: 80a22000                 cmp     %o0, 0
F0046838: 3280000a                 bne,a   loc_F0046860
F004683C: d0062080                 ld      [%i0+0x80], %o0
F0046840: d0162088                 lduh    [%i0+0x88], %o0
F0046844: 808a2001                 btst    1, %o0
F0046848: 02800005                 be      loc_F004685C
F004684C: 900a3ffe                 and     %o0, -2, %o0
F0046850: d0362088                 sth     %o0, [%i0+0x88]
F0046854: 7fff3165                 call    _wakeup
F0046858: 90062082                 add     %i0, 0x82, %o0
F004685C: d0062080                 ld      [%i0+0x80], %o0
F0046860: 80a22000                 cmp     %o0, 0
F0046864: 12800015                 bne     locret_F00468B8
F0046868: 01000000                 nop
F004686C: d0062068                 ld      [%i0+0x68], %o0
F0046870: 80a22000                 cmp     %o0, 0
F0046874: 22800008                 be,a    loc_F0046894
F0046878: d006207c                 ld      [%i0+0x7C], %o0
F004687C: 40000277                 call    sub_F0047258
F0046880: 92100018                 mov     %i0, %o1
F0046884: 80a22000                 cmp     %o0, 0
F0046888: 12bffffd                 bne     loc_F004687C
F004688C: 01000000                 nop
F0046890: d006207c                 ld      [%i0+0x7C], %o0
F0046894: 80a22000                 cmp     %o0, 0
F0046898: 02800004                 be      loc_F00468A8
F004689C: 90100018                 mov     %i0, %o0
F00468A0: 40000446                 call    _smark
F00468A4: 92102042                 mov     0x42, %o1 ! 'B'
F00468A8: c0262068                 clr     [%i0+0x68]
F00468AC: c0362086                 clrh    [%i0+0x86]
F00468B0: c0362084                 clrh    [%i0+0x84]
F00468B4: c026207c                 clr     [%i0+0x7C]
F00468B8: 81c7e008                 ret
F00468BC: 91e82000                 restore %g0, 0, %o0
