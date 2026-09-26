F0099020: 9de3bf98                 save    %sp, -0x68, %sp
F0099024: d0060000                 ld      [%i0], %o0
F0099028: 92102064                 mov     0x64, %o1 ! 'd'
F009902C: 94022001                 add     %o0, 1, %o2
F0099030: 7ffdb61e                 call    _rem
F0099034: d4260000                 st      %o2, [%i0]
F0099038: 80a22001                 cmp     %o0, 1
F009903C: 12800006                 bne     locret_F0099054
F0099040: 113c044d                 sethi   %hi(aLevelDSinterru), %o0! "Level %d %sinterrupt not serviced\n"
F0099044: 90122138                 bset    %lo(aLevelDSinterru), %o0! "Level %d %sinterrupt not serviced\n"
F0099048: 92100019                 mov     %i1, %o1
F009904C: 7ffded83                 call    _printf
F0099050: 9410001a                 mov     %i2, %o2
F0099054: 81c7e008                 ret
F0099058: 91e83fff                 restore %g0, -1, %o0
