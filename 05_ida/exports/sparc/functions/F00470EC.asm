F00470EC: 9de3bf98                 save    %sp, -0x68, %sp
F00470F0: 113c0438                 sethi   %hi(aFifoBadop), %o0! "fifo_badop\n"
F00470F4: 7fff381f                 call    _panic
F00470F8: 90122388                 bset    %lo(aFifoBadop), %o0! "fifo_badop\n"
F00470FC: 81c7e008                 ret
F0047100: 81e80000                 restore
