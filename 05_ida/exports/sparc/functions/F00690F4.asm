F00690F4: 9de3bf98                 save    %sp, -0x68, %sp
F00690F8: a0062008                 add     %i0, 8, %l0
F00690FC: d0040000                 ld      [%l0], %o0
F0069100: 80a22000                 cmp     %o0, 0
F0069104: 12bffffe                 bne     loc_F00690FC
F0069108: 01000000                 nop
F006910C: 4000b767                 call    _simple_lock_try
F0069110: 90100010                 mov     %l0, %o0
F0069114: 80a22000                 cmp     %o0, 0
F0069118: 02bffff9                 be      loc_F00690FC
F006911C: 133c04d0                 sethi   %hi(_active_threads), %o1
F0069120: d0060000                 ld      [%i0], %o0
F0069124: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0069128: 80a20009                 cmp     %o0, %o1
F006912C: 02800042                 be      loc_F0069234
F0069130: 13000030                 sethi   0xC000, %o1
F0069134: d0062004                 ld      [%i0+4], %o0
F0069138: 808a0009                 btst    %o1, %o0
F006913C: 2280003f                 be,a    loc_F0069238
F0069140: d0162004                 lduh    [%i0+4], %o0
F0069144: a4100009                 mov     %o1, %l2
F0069148: a2062008                 add     %i0, 8, %l1
F006914C: 113c043e                 sethi   -0xFEF0800, %o0
F0069150: d2022380                 ld      [%o0+0x380], %o1
F0069154: 80a26000                 cmp     %o1, 0
F0069158: 2480001b                 ble,a   loc_F00691C4
F006915C: d2062004                 ld      [%i0+4], %o1
F0069160: c0262008                 clr     [%i0+8]
F0069164: 92027fff                 inc     -1, %o1
F0069168: 80a26000                 cmp     %o1, 0
F006916C: 2480000c                 ble,a   loc_F006919C
F0069170: a0062008                 add     %i0, 8, %l0
F0069174: d0062004                 ld      [%i0+4], %o0
F0069178: 900a0012                 and     %o0, %l2, %o0
F006917C: 80a22000                 cmp     %o0, 0
F0069180: 22800007                 be,a    loc_F006919C
F0069184: a0062008                 add     %i0, 8, %l0
F0069188: 92027fff                 inc     -1, %o1
F006918C: 80a26000                 cmp     %o1, 0
F0069190: 14bffffc                 bg      loc_F0069180
F0069194: 80a22000                 cmp     %o0, 0
F0069198: a0062008                 add     %i0, 8, %l0
F006919C: d0040000                 ld      [%l0], %o0
F00691A0: 80a22000                 cmp     %o0, 0
F00691A4: 12bffffe                 bne     loc_F006919C
F00691A8: 01000000                 nop
F00691AC: 4000b73f                 call    _simple_lock_try
F00691B0: 90100010                 mov     %l0, %o0
F00691B4: 80a22000                 cmp     %o0, 0
F00691B8: 02bffff9                 be      loc_F006919C
F00691BC: 01000000                 nop
F00691C0: d2062004                 ld      [%i0+4], %o1
F00691C4: 11000004                 sethi   0x1000, %o0
F00691C8: 808a4008                 btst    %o0, %o1
F00691CC: 22800017                 be,a    loc_F0069228
F00691D0: d0062004                 ld      [%i0+4], %o0
F00691D4: 808a4012                 btst    %l2, %o1
F00691D8: 22800014                 be,a    loc_F0069228
F00691DC: d0062004                 ld      [%i0+4], %o0
F00691E0: 1100000890124008         set     0x2000, %o0
F00691E8: d0262004                 st      %o0, [%i0+4]
F00691EC: 90100018                 mov     %i0, %o0
F00691F0: 92100011                 mov     %l1, %o1
F00691F4: 40001ff2                 call    _thread_sleep
F00691F8: 94102000                 mov     0, %o2
F00691FC: a0100011                 mov     %l1, %l0
F0069200: d0040000                 ld      [%l0], %o0
F0069204: 80a22000                 cmp     %o0, 0
F0069208: 12bffffe                 bne     loc_F0069200
F006920C: 01000000                 nop
F0069210: 4000b726                 call    _simple_lock_try
F0069214: 90100010                 mov     %l0, %o0
F0069218: 80a22000                 cmp     %o0, 0
F006921C: 02bffff9                 be      loc_F0069200
F0069220: 01000000                 nop
F0069224: d0062004                 ld      [%i0+4], %o0
F0069228: 808a0012                 btst    %l2, %o0
F006922C: 12bfffc9                 bne     loc_F0069150
F0069230: 113c043e                 sethi   -0xFEF0800, %o0
F0069234: d0162004                 lduh    [%i0+4], %o0
F0069238: c0262008                 clr     [%i0+8]
F006923C: 90022001                 inc     %o0
F0069240: d0362004                 sth     %o0, [%i0+4]
F0069244: 81c7e008                 ret
F0069248: 81e80000                 restore
