F0024520: 9de3bf98                 save    %sp, -0x68, %sp
F0024524: 133c04d4                 sethi   %hi(_bstats), %o1
F0024528: d00263b0                 ld      [%o1+%lo(_bstats)], %o0
F002452C: 80a6a000                 cmp     %i2, 0
F0024530: a01263b0                 or      %o1, %lo(_bstats), %l0
F0024534: 90022001                 inc     %o0
F0024538: 12800005                 bne     loc_F002454C
F002453C: d02263b0                 st      %o0, [%o1+%lo(_bstats)]
F0024540: 113c042f                 sethi   %hi(aBreadSize0), %o0! "bread: size 0"
F0024544: 7fffc30b                 call    _panic
F0024548: 901222d8                 bset    %lo(aBreadSize0), %o0! "bread: size 0"
F002454C: 90100018                 mov     %i0, %o0
F0024550: 92100019                 mov     %i1, %o1
F0024554: 40000145                 call    _getblk
F0024558: 9410001a                 mov     %i2, %o2
F002455C: b0100008                 mov     %o0, %i0
F0024560: d2060000                 ld      [%i0], %o1
F0024564: 808a6002                 btst    2, %o1
F0024568: 22800006                 be,a    loc_F0024580
F002456C: d0062014                 ld      [%i0+0x14], %o0
F0024570: d0042004                 ld      [%l0+4], %o0
F0024574: 90022001                 inc     %o0
F0024578: 10800016                 ba      locret_F00245D0
F002457C: d0242004                 st      %o0, [%l0+4]
F0024580: 92126001                 bset    1, %o1
F0024584: d4062018                 ld      [%i0+0x18], %o2
F0024588: 80a2000a                 cmp     %o0, %o2
F002458C: 04800005                 ble     loc_F00245A0
F0024590: d2260000                 st      %o1, [%i0]
F0024594: 113c042f                 sethi   %hi(aBread), %o0! "bread"
F0024598: 7fffc2f6                 call    _panic
F002459C: 901222e8                 bset    %lo(aBread), %o0! "bread"
F00245A0: d0062040                 ld      [%i0+0x40], %o0
F00245A4: d002201c                 ld      [%o0+0x1C], %o0
F00245A8: d2022054                 ld      [%o0+0x54], %o1
F00245AC: 9fc24000                 call    %o1
F00245B0: 90100018                 mov     %i0, %o0
F00245B4: 113c04cf                 sethi   %hi(_active_u), %o0
F00245B8: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F00245BC: d202a198                 ld      [%o2+0x198], %o1
F00245C0: 90100018                 mov     %i0, %o0
F00245C4: 92026001                 inc     %o1
F00245C8: 400002a6                 call    _biowait
F00245CC: d222a198                 st      %o1, [%o2+0x198]
F00245D0: 81c7e008                 ret
F00245D4: 81e80000                 restore
