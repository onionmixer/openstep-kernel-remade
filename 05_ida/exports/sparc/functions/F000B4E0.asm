F000B4E0: 9de3bf98                 save    %sp, -0x68, %sp
F000B4E4: 80a62000                 cmp     %i0, 0
F000B4E8: 0280001f                 be      locret_F000B564
F000B4EC: 01000000                 nop
F000B4F0: d256200e                 ldsh    [%i0+0xE], %o1
F000B4F4: 80a26001                 cmp     %o1, 1
F000B4F8: 04800005                 ble     loc_F000B50C
F000B4FC: 90100009                 mov     %o1, %o0
F000B500: 90023fff                 inc     -1, %o0
F000B504: 10800018                 ba      locret_F000B564
F000B508: d036200e                 sth     %o0, [%i0+0xE]
F000B50C: 02800004                 be      loc_F000B51C
F000B510: 113c042b                 sethi   %hi(aFpNotOne), %o0! "fp not one\n"
F000B514: 40002717                 call    _panic
F000B518: 90122258                 bset    %lo(aFpNotOne), %o0! "fp not one\n"
F000B51C: d0062014                 ld      [%i0+0x14], %o0
F000B520: 80a22000                 cmp     %o0, 0
F000B524: 02800005                 be      loc_F000B538
F000B528: 01000000                 nop
F000B52C: d202200c                 ld      [%o0+0xC], %o1
F000B530: 9fc24000                 call    %o1
F000B534: 90100018                 mov     %i0, %o0
F000B538: 40001138                 call    _crfree
F000B53C: d0062020                 ld      [%i0+0x20], %o0
F000B540: d056200e                 ldsh    [%i0+0xE], %o0
F000B544: 80a22001                 cmp     %o0, 1
F000B548: 02800004                 be      loc_F000B558
F000B54C: 113c042b                 sethi   %hi(aFpNotOne2), %o0! "fp not one2\n"
F000B550: 40002708                 call    _panic
F000B554: 90122268                 bset    %lo(aFpNotOne2), %o0! "fp not one2\n"
F000B558: c036200e                 clrh    [%i0+0xE]
F000B55C: 40000004                 call    _free_file
F000B560: 90100018                 mov     %i0, %o0
F000B564: 81c7e008                 ret
F000B568: 81e80000                 restore
