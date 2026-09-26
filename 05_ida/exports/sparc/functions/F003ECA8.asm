F003ECA8: 9de3bf98                 save    %sp, -0x68, %sp
F003ECAC: 113c0435                 sethi   %hi(aNfsBadop), %o0! "nfs_badop"
F003ECB0: 7fff5930                 call    _panic
F003ECB4: 901221a8                 bset    %lo(aNfsBadop), %o0! "nfs_badop"
F003ECB8: 81c7e008                 ret
F003ECBC: 81e80000                 restore
