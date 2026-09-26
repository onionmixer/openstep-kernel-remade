F006F138: 9de3bf98                 save    %sp, -0x68, %sp
F006F13C: 80a62000                 cmp     %i0, 0
F006F140: 02800015                 be      locret_F006F194
F006F144: a0062148                 add     %i0, 0x148, %l0
F006F148: d0040000                 ld      [%l0], %o0
F006F14C: 80a22000                 cmp     %o0, 0
F006F150: 12bffffe                 bne     loc_F006F148
F006F154: 01000000                 nop
F006F158: 40009f54                 call    _simple_lock_try
F006F15C: 90100010                 mov     %l0, %o0
F006F160: 80a22000                 cmp     %o0, 0
F006F164: 02bffff9                 be      loc_F006F148
F006F168: 01000000                 nop
F006F16C: d0062144                 ld      [%i0+0x144], %o0
F006F170: 90023fff                 inc     -1, %o0
F006F174: 80a22000                 cmp     %o0, 0
F006F178: 04800004                 ble     loc_F006F188
F006F17C: d0262144                 st      %o0, [%i0+0x144]
F006F180: c0262148                 clr     [%i0+0x148]
F006F184: 30800004                 ba,a    locret_F006F194
F006F188: 113c0440                 sethi   %hi(aPsetDeallocate), %o0! "pset_deallocate: default_pset destroyed"
F006F18C: 7ffe97f9                 call    _panic
F006F190: 90122090                 bset    %lo(aPsetDeallocate), %o0! "pset_deallocate: default_pset destroyed"
F006F194: 81c7e008                 ret
F006F198: 81e80000                 restore
