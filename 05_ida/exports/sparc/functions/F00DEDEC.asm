F00DEDEC: 9de3bf98                 save    %sp, -0x68, %sp
F00DEDF0: 90100018                 mov     %i0, %o0! id
F00DEDF4: 94100019                 mov     %i1, %o2
F00DEDF8: 9610001a                 mov     %i2, %o3
F00DEDFC: 9810001b                 mov     %i3, %o4
F00DEE00: 80a22000                 cmp     %o0, 0
F00DEE04: 12800004                 bne     loc_F00DEE14
F00DEE08: 9a10001c                 mov     %i4, %o5
F00DEE0C: 10800009                 ba      locret_F00DEE30
F00DEE10: b01020ca                 mov     0xCA, %i0
F00DEE14: 133c0504                 sethi   %hi(paRecordsizeTagR), %o1! SEL
F00DEE18: 40004a96                 call    _objc_msgSend
F00DEE1C: d20263f4                 ld      [%o1+%lo(paRecordsizeTagR)], %o1
F00DEE20: 912a2018                 sll     %o0, 24, %o0
F00DEE24: 80a00008                 cmp     %g0, %o0
F00DEE28: b0403fff                 addc    %g0, -1, %i0
F00DEE2C: b00e20cc                 and     %i0, 0xCC, %i0
F00DEE30: 81c7e008                 ret
F00DEE34: 81e80000                 restore
