F0053274: 9de3bf98                 save    %sp, -0x68, %sp
F0053278: 113c043c                 sethi   %hi(aUfsBadop), %o0! "ufs_badop"
F005327C: 7fff07bd                 call    _panic
F0053280: 90122218                 bset    %lo(aUfsBadop), %o0! "ufs_badop"
F0053284: 81c7e008                 ret
F0053288: 81e80000                 restore
