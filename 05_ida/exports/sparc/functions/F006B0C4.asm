F006B0C4: 9de3bf98                 save    %sp, -0x68, %sp
F006B0C8: 80a6a000                 cmp     %i2, 0
F006B0CC: 02800016                 be      loc_F006B124
F006B0D0: c026c000                 clr     [%i3]
F006B0D4: d2064000                 ld      [%i1], %o1
F006B0D8: 90100018                 mov     %i0, %o0
F006B0DC: b2066004                 inc     4, %i1
F006B0E0: e0064000                 ld      [%i1], %l0
F006B0E4: 9810001b                 mov     %i3, %o4
F006B0E8: b2066004                 inc     4, %i1
F006B0EC: 94042002                 add     %l0, 2, %o2
F006B0F0: 952aa002                 sll     %o2, 2, %o2
F006B0F4: b426800a                 sub     %i2, %o2, %i2
F006B0F8: 94100019                 mov     %i1, %o2
F006B0FC: 4000c30d                 call    _thread_entrypoint
F006B100: 96100010                 mov     %l0, %o3
F006B104: 80a22000                 cmp     %o0, 0
F006B108: 02800004                 be      loc_F006B118
F006B10C: 912c2002                 sll     %l0, 2, %o0
F006B110: 10800006                 ba      locret_F006B128
F006B114: b0102004                 mov     4, %i0
F006B118: 80a6a000                 cmp     %i2, 0
F006B11C: 12bfffee                 bne     loc_F006B0D4
F006B120: b2064008                 add     %i1, %o0, %i1
F006B124: b0102000                 mov     0, %i0
F006B128: 81c7e008                 ret
F006B12C: 81e80000                 restore
