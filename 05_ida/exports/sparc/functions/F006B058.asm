F006B058: 9de3bf98                 save    %sp, -0x68, %sp
F006B05C: 80a6a000                 cmp     %i2, 0
F006B060: 02800016                 be      loc_F006B0B8
F006B064: c026c000                 clr     [%i3]
F006B068: d2064000                 ld      [%i1], %o1
F006B06C: 90100018                 mov     %i0, %o0
F006B070: b2066004                 inc     4, %i1
F006B074: e0064000                 ld      [%i1], %l0
F006B078: 9810001b                 mov     %i3, %o4
F006B07C: b2066004                 inc     4, %i1
F006B080: 94042002                 add     %l0, 2, %o2
F006B084: 952aa002                 sll     %o2, 2, %o2
F006B088: b426800a                 sub     %i2, %o2, %i2
F006B08C: 94100019                 mov     %i1, %o2
F006B090: 4000c313                 call    _thread_userstack
F006B094: 96100010                 mov     %l0, %o3
F006B098: 80a22000                 cmp     %o0, 0
F006B09C: 02800004                 be      loc_F006B0AC
F006B0A0: 912c2002                 sll     %l0, 2, %o0
F006B0A4: 10800006                 ba      locret_F006B0BC
F006B0A8: b0102004                 mov     4, %i0
F006B0AC: 80a6a000                 cmp     %i2, 0
F006B0B0: 12bfffee                 bne     loc_F006B068
F006B0B4: b2064008                 add     %i1, %o0, %i1
F006B0B8: b0102000                 mov     0, %i0
F006B0BC: 81c7e008                 ret
F006B0C0: 81e80000                 restore
