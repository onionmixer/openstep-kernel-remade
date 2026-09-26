F00C4034: 9de3bf90                 save    %sp, -0x70, %sp
F00C4038: 113c04cc                 sethi   %hi(dword_F013302C), %o0
F00C403C: d002202c                 ld      [%o0+%lo(dword_F013302C)], %o0! id
F00C4040: 133c0504                 sethi   %hi(paObjectat), %o1
F00C4044: d20260c8                 ld      [%o1+%lo(paObjectat)], %o1! SEL
F00C4048: 4000b60a                 call    _objc_msgSend
F00C404C: 94102000                 mov     0, %o2
F00C4050: 133c0504                 sethi   %hi(paIsirqshared), %o1
F00C4054: d2026370                 ld      [%o1+%lo(paIsirqshared)], %o1! SEL
F00C4058: 4000b606                 call    _objc_msgSend
F00C405C: 9410001a                 mov     %i2, %o2
F00C4060: 912a2018                 sll     %o0, 24, %o0
F00C4064: b13a2018                 sra     %o0, 24, %i0
F00C4068: 81c7e008                 ret
F00C406C: 81e80000                 restore
