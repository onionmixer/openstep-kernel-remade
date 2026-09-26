F0074FA8: 9de3bf98                 save    %sp, -0x68, %sp
F0074FAC: 113c0442                 sethi   %hi(aTheZombieWalks), %o0! "the zombie walks!"
F0074FB0: 7ffe8070                 call    _panic
F0074FB4: 90122338                 bset    %lo(aTheZombieWalks), %o0! "the zombie walks!"
F0074FB8: 81c7e008                 ret
F0074FBC: 81e80000                 restore
