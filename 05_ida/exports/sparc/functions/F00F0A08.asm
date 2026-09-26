F00F0A08: 9de3bf98                 save    %sp, -0x68, %sp
F00F0A0C: 113c03f490122188         set     aObjcFatalS, %o0! "objc fatal: %s\n"
F00F0A14: 7ffc8f11                 call    _printf
F00F0A18: 92100018                 mov     %i0, %o1
F00F0A1C: 113c03f4                 sethi   %hi(aObjectiveCFata), %o0! "Objective-C fatal"
F00F0A20: 7ffc91d4                 call    _panic
F00F0A24: 90122198                 bset    %lo(aObjectiveCFata), %o0! "Objective-C fatal"
F00F0A28: 81c7e008                 ret
F00F0A2C: 81e80000                 restore
