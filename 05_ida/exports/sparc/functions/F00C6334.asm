F00C6334: 9de3bf90                 save    %sp, -0x70, %sp
F00C6338: 113c03ea                 sethi   %hi(aIodiskEjectInK), %o0! "IODisk eject in kernel illegal\n"
F00C633C: 7fffff7a                 call    _IOPanic
F00C6340: 90122308                 bset    %lo(aIodiskEjectInK), %o0! "IODisk eject in kernel illegal\n"
F00C6344: 81c7e008                 ret
F00C6348: 91e83d39                 restore %g0, -0x2C7, %o0
