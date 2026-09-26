F0099FF8: 9de3bf98                 save    %sp, -0x68, %sp
F0099FFC: 11000040                 sethi   0x10000, %o0
F009A000: 808e4008                 btst    %o0, %i1
F009A004: 02800004                 be      locret_F009A014
F009A008: 113c045c                 sethi   %hi(aPleaseWaitUnti), %o0! "Please wait until it's safe\n to turn o"...
F009A00C: 7fffffef                 call    sub_F0099FC8
F009A010: 90122168                 bset    %lo(aPleaseWaitUnti), %o0! "Please wait until it's safe\n to turn o"...
F009A014: 81c7e008                 ret
F009A018: 81e80000                 restore
