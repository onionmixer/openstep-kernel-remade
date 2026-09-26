F00665AC: 9de3bf98                 save    %sp, -0x68, %sp
F00665B0: 113c043e                 sethi   %hi(aMigDeallocRepl), %o0! "mig_dealloc_reply_port"
F00665B4: 7ffebaef                 call    _panic
F00665B8: 90122228                 bset    %lo(aMigDeallocRepl), %o0! "mig_dealloc_reply_port"
F00665BC: 81c7e008                 ret
F00665C0: 81e80000                 restore
