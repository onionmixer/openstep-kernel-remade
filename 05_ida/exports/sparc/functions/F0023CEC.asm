F0023CEC: 9de3bf98                 save    %sp, -0x68, %sp
F0023CF0: a0100018                 mov     %i0, %l0
F0023CF4: 133c042f                 sethi   %hi(_vfssw), %o1
F0023CF8: 153c0430                 sethi   %hi(_vfsNVFS), %o2
F0023CFC: d002a08c                 ld      [%o2+%lo(_vfsNVFS)], %o0! __s1
F0023D00: b01263d8                 or      %o1, %lo(_vfssw), %i0
F0023D04: 80a60008                 cmp     %i0, %o0
F0023D08: 3a80000e                 bcc,a   locret_F0023D40
F0023D0C: b0102000                 mov     0, %i0
F0023D10: a210000a                 mov     %o2, %l1
F0023D14: d2060000                 ld      [%i0], %o1! __s2
F0023D18: 7fff9125                 call    _strcmp
F0023D1C: 90100010                 mov     %l0, %o0
F0023D20: 80a22000                 cmp     %o0, 0
F0023D24: 02800007                 be      locret_F0023D40
F0023D28: d004608c                 ld      [%l1+0x8C], %o0
F0023D2C: b0062008                 inc     8, %i0
F0023D30: 80a60008                 cmp     %i0, %o0
F0023D34: 2abffff9                 bcs,a   loc_F0023D18
F0023D38: d2060000                 ld      [%i0], %o1
F0023D3C: b0102000                 mov     0, %i0
F0023D40: 81c7e008                 ret
F0023D44: 81e80000                 restore
