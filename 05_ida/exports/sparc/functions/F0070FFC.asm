F0070FFC: 9de3bf98                 save    %sp, -0x68, %sp
F0071000: 80a62000                 cmp     %i0, 0
F0071004: 16800003                 bge     loc_F0071010
F0071008: 90100018                 mov     %i0, %o0
F007100C: 90380018                 xnor    %g0, %i0, %o0
F0071010: 7ffe5626                 call    _rem
F0071014: 9210203b                 mov     0x3B, %o1 ! ';'
F0071018: a0100008                 mov     %o0, %l0
F007101C: 932c2003                 sll     %l0, 3, %o1
F0071020: 113c04f190122380         set     _wait_queue, %o0
F0071028: 400096d8                 call    _splusclock
F007102C: a8024008                 add     %o1, %o0, %l4
F0071030: ac100008                 mov     %o0, %l6
F0071034: 932c2002                 sll     %l0, 2, %o1
F0071038: 113c04f190122290         set     _wait_lock, %o0
F0071040: a4024008                 add     %o1, %o0, %l2
F0071044: d0048000                 ld      [%l2], %o0
F0071048: 80a22000                 cmp     %o0, 0
F007104C: 12bffffe                 bne     loc_F0071044
F0071050: 01000000                 nop
F0071054: 40009795                 call    _simple_lock_try
F0071058: 90100012                 mov     %l2, %o0
F007105C: 80a22000                 cmp     %o0, 0
F0071060: 02bffff9                 be      loc_F0071044
F0071064: 01000000                 nop
F0071068: e0050000                 ld      [%l4], %l0
F007106C: 80a50010                 cmp     %l4, %l0
F0071070: 0280004e                 be      loc_F00711A8
F0071074: 113c01c4                 sethi   %hi(jpt_F0071108), %o0
F0071078: aa122110                 or      %o0, %lo(jpt_F0071108), %l5
F007107C: d004203c                 ld      [%l0+0x3C], %o0
F0071080: 80a20018                 cmp     %o0, %i0
F0071084: 12800045                 bne     loc_F0071198
F0071088: e6040000                 ld      [%l0], %l3
F007108C: a2042020                 add     %l0, 0x20, %l1 ! ' '
F0071090: d0044000                 ld      [%l1], %o0
F0071094: 80a22000                 cmp     %o0, 0
F0071098: 12bffffe                 bne     loc_F0071090
F007109C: 01000000                 nop
F00710A0: 40009782                 call    _simple_lock_try
F00710A4: 90100011                 mov     %l1, %o0
F00710A8: 80a22000                 cmp     %o0, 0
F00710AC: 02bffff9                 be      loc_F0071090
F00710B0: 01000000                 nop
F00710B4: d2040000                 ld      [%l0], %o1
F00710B8: d0042004                 ld      [%l0+4], %o0
F00710BC: d0226004                 st      %o0, [%o1+4]
F00710C0: d2042004                 ld      [%l0+4], %o1
F00710C4: d0040000                 ld      [%l0], %o0
F00710C8: d0224000                 st      %o0, [%o1]
F00710CC: c024203c                 clr     [%l0+0x3C]
F00710D0: d004214c                 ld      [%l0+0x14C], %o0
F00710D4: 80a22000                 cmp     %o0, 0
F00710D8: 22800005                 be,a    loc_F00710EC
F00710DC: d204204c                 ld      [%l0+0x4C], %o1
F00710E0: 7fffe25d                 call    _reset_timeout
F00710E4: 90042118                 add     %l0, 0x118, %o0
F00710E8: d204204c                 ld      [%l0+0x4C], %o1
F00710EC: 900a600f                 and     %o1, 0xF, %o0
F00710F0: 90023fff                 inc     -1, %o0
F00710F4: 80a2200e                 cmp     %o0, 0xE! switch 15 cases
F00710F8: 38800022                 bgu,a   def_F0071108! jumptable F0071108 default case
F00710FC: 113c0441                 sethi   -0xFEEFC00, %o0
F0071100: 912a2002                 sll     %o0, 2, %o0
F0071104: d0020015                 ld      [%o0+%l5], %o0
F0071108: 81c20000                 jmp     %o0! switch jump
F007110C: 01000000                 nop
F007114C: 900a7ffe                 and     %o1, -2, %o0! jumptable F0071108 cases 0,8,10
F0071150: 90122004                 bset    4, %o0
F0071154: d024204c                 st      %o0, [%l0+0x4C]
F0071158: f4242044                 st      %i2, [%l0+0x44]
F007115C: 90100010                 mov     %l0, %o0
F0071160: 400002d0                 call    _thread_setrun
F0071164: 92102001                 mov     1, %o1
F0071168: 30800008                 ba,a    loc_F0071188
F007116C: 900a7ffe                 and     %o1, -2, %o0! jumptable F0071108 cases 2,4,6,12,14
F0071170: d024204c                 st      %o0, [%l0+0x4C]
F0071174: 10800005                 ba      loc_F0071188
F0071178: f4242044                 st      %i2, [%l0+0x44]
F007117C: 113c0441                 sethi   -0xFEEFC00, %o0! jumptable F0071108 cases 1,3,5,7,9,11,13
F0071180: 7ffe8ffc                 call    _panic! jumptable F0071108 default case
F0071184: 90122008                 bset    8, %o0
F0071188: c0242020                 clr     [%l0+0x20]
F007118C: 80a66000                 cmp     %i1, 0
F0071190: 12800006                 bne     loc_F00711A8
F0071194: 01000000                 nop
F0071198: a0100013                 mov     %l3, %l0
F007119C: 80a50010                 cmp     %l4, %l0
F00711A0: 32bfffb8                 bne,a   loc_F0071080
F00711A4: d004203c                 ld      [%l0+0x3C], %o0
F00711A8: c0248000                 clr     [%l2]
F00711AC: 400096de                 call    _splx
F00711B0: 90100016                 mov     %l6, %o0
F00711B4: 81c7e008                 ret
F00711B8: 81e80000                 restore
