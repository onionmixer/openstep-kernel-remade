F00A6BA4: 9de3bf98                 save    %sp, -0x68, %sp
F00A6BA8: 11000040                 sethi   0x10000, %o0
F00A6BAC: 808e0008                 btst    %o0, %i0
F00A6BB0: 02800006                 be      loc_F00A6BC8
F00A6BB4: 113c046b                 sethi   %hi(aMultipleEccErr), %o0! "Multiple ECC Errors\n"
F00A6BB8: 7ffdb6a8                 call    _printf
F00A6BBC: 90122268                 bset    %lo(aMultipleEccErr), %o0! "Multiple ECC Errors\n"
F00A6BC0: 10800009                 ba      locret_F00A6BE4
F00A6BC4: b0103fff                 mov     -1, %i0
F00A6BC8: 11020000                 sethi   0x8000000, %o0
F00A6BCC: 808e4008                 btst    %o0, %i1
F00A6BD0: 02800005                 be      locret_F00A6BE4
F00A6BD4: 113c046b                 sethi   %hi(aEccErrorRecove), %o0! "ECC error recovery: Supervisor mode\n"
F00A6BD8: 7ffdb6a0                 call    _printf
F00A6BDC: 90122280                 bset    %lo(aEccErrorRecove), %o0! "ECC error recovery: Supervisor mode\n"
F00A6BE0: b0103fff                 mov     -1, %i0
F00A6BE4: 81c7e008                 ret
F00A6BE8: 81e80000                 restore
