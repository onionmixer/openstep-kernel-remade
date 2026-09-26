F00BD544: 9de3bf28                 save    %sp, -0xD8, %sp
F00BD548: 113c0481                 sethi   %hi(aReallyShutDown), %o0! "\nReally Shut down (y/n)? "
F00BD54C: 7ffd5c43                 call    _printf
F00BD550: 901220e8                 bset    %lo(aReallyShutDown), %o0! "\nReally Shut down (y/n)? "
F00BD554: 9007bf88                 add     %fp, var_78, %o0! char *
F00BD558: 7fffa744                 call    _gets
F00BD55C: 92100008                 mov     %o0, %o1
F00BD560: d04fbf88                 ldsb    [%fp+var_78], %o0
F00BD564: 80a22079                 cmp     %o0, 0x79 ! 'y'
F00BD568: 02800005                 be      loc_F00BD57C
F00BD56C: 113c0481                 sethi   %hi(aAbortingShutdo), %o0! "...aborting shutdown\n"
F00BD570: 7ffd5c3a                 call    _printf
F00BD574: 90122108                 bset    %lo(aAbortingShutdo), %o0! "...aborting shutdown\n"
F00BD578: 30800006                 ba,a    locret_F00BD590
F00BD57C: 90102001                 mov     1, %o0
F00BD580: 13000240                 sethi   0x90000, %o1
F00BD584: 153c0481                 sethi   %hi(unk_F0120520), %o2
F00BD588: 7ffd4bbf                 call    _boot
F00BD58C: 9412a120                 bset    %lo(unk_F0120520), %o2
F00BD590: 81c7e008                 ret
F00BD594: 81e80000                 restore
