F0012DB8: 9de3bf98                 save    %sp, -0x68, %sp
F0012DBC: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0012DC0: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F0012DC4: c02a2040                 clrb    [%o0+0x40]
F0012DC8: 921261dc                 bset    %lo(dword_F0133DDC), %o1
F0012DCC: 113c042c                 sethi   %hi(aSContinuing), %o0! "[%s: ... continuing]\r\n"
F0012DD0: d2027ffc                 ld      [%o1-4], %o1
F0012DD4: 90122340                 bset    %lo(aSContinuing), %o0! "[%s: ... continuing]\r\n"
F0012DD8: 40000632                 call    _uprintf
F0012DDC: 92026008                 inc     8, %o1
F0012DE0: 81c7e008                 ret
F0012DE4: 81e80000                 restore
