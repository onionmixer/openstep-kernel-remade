F008C370: 9de3bf98                 save    %sp, -0x68, %sp
F008C374: 113c0447                 sethi   %hi(aObjcFatalError), %o0! "objc: fatal error\n"
F008C378: 7ffe237e                 call    _panic
F008C37C: 90122398                 bset    %lo(aObjcFatalError), %o0! "objc: fatal error\n"
F008C380: 81c7e008                 ret
F008C384: 81e80000                 restore
