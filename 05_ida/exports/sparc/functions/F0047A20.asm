F0047A20: 9de3bf98                 save    %sp, -0x68, %sp
F0047A24: 113c0438                 sethi   %hi(aSpecBadop), %o0! "spec_badop"
F0047A28: 7fff35d2                 call    _panic
F0047A2C: 901223b8                 bset    %lo(aSpecBadop), %o0! "spec_badop"
F0047A30: 81c7e008                 ret
F0047A34: 81e80000                 restore
