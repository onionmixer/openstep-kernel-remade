F006AFF0: 9de3bf98                 save    %sp, -0x68, %sp
F006AFF4: 80a6a000                 cmp     %i2, 0
F006AFF8: 22800016                 be,a    locret_F006B050
F006AFFC: b0102000                 mov     0, %i0
F006B000: d2064000                 ld      [%i1], %o1
F006B004: b2066004                 inc     4, %i1
F006B008: e0064000                 ld      [%i1], %l0
F006B00C: 90100018                 mov     %i0, %o0
F006B010: b2066004                 inc     4, %i1
F006B014: 94042002                 add     %l0, 2, %o2
F006B018: 952aa002                 sll     %o2, 2, %o2
F006B01C: b426800a                 sub     %i2, %o2, %i2
F006B020: 94100019                 mov     %i1, %o2
F006B024: 4000c28a                 call    _thread_setstatus
F006B028: 96100010                 mov     %l0, %o3
F006B02C: 80a22000                 cmp     %o0, 0
F006B030: 02800004                 be      loc_F006B040
F006B034: 912c2002                 sll     %l0, 2, %o0
F006B038: 10800006                 ba      locret_F006B050
F006B03C: b0102004                 mov     4, %i0
F006B040: 80a6a000                 cmp     %i2, 0
F006B044: 12bfffef                 bne     loc_F006B000
F006B048: b2064008                 add     %i1, %o0, %i1
F006B04C: b0102000                 mov     0, %i0
F006B050: 81c7e008                 ret
F006B054: 81e80000                 restore
