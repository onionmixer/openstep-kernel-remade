F0064B70: 9de3bf98                 save    %sp, -0x68, %sp
F0064B74: d0062020                 ld      [%i0+0x20], %o0
F0064B78: 133c04d0                 sethi   %hi(_active_threads), %o1
F0064B7C: e0026260                 ld      [%o1+%lo(_active_threads)], %l0
F0064B80: 90023fff                 inc     -1, %o0
F0064B84: d0262020                 st      %o0, [%i0+0x20]
F0064B88: d0062004                 ld      [%i0+4], %o0
F0064B8C: 90023ffe                 inc     -2, %o0
F0064B90: d0262004                 st      %o0, [%i0+4]
F0064B94: c0260000                 clr     [%i0]
F0064B98: 7fffff25                 call    _exception_parse_reply
F0064B9C: 90100019                 mov     %i1, %o0
F0064BA0: 80a22000                 cmp     %o0, 0
F0064BA4: 3280000a                 bne,a   loc_F0064BCC
F0064BA8: d00420c8                 ld      [%l0+0xC8], %o0
F0064BAC: d0042038                 ld      [%l0+0x38], %o0
F0064BB0: 80a22000                 cmp     %o0, 0
F0064BB4: 02800004                 be      loc_F0064BC4
F0064BB8: 01000000                 nop
F0064BBC: 4000bfca                 call    _call_continuation
F0064BC0: 01000000                 nop
F0064BC4: 4000dd08                 call    _thread_exception_return
F0064BC8: 9e03e020                 inc     0x20, %o7 ! ' '
F0064BCC: 80a22000                 cmp     %o0, 0
F0064BD0: 02800005                 be      loc_F0064BE4
F0064BD4: 01000000                 nop
F0064BD8: d20420cc                 ld      [%l0+0xCC], %o1
F0064BDC: 7ffffce1                 call    _exception_try_task
F0064BE0: d40420d0                 ld      [%l0+0xD0], %o2
F0064BE4: 7ffffd1c                 call    _exception_no_server
F0064BE8: 01000000                 nop
F0064BEC: 81c7e008                 ret
F0064BF0: 81e80000                 restore
