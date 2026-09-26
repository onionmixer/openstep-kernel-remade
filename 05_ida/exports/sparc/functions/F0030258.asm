F0030258: 9de3bf78                 save    %sp, -0x88, %sp
F003025C: 233c0431                 sethi   %hi(dword_F010C4C8), %l1
F0030260: d00460c8                 ld      [%l1+%lo(dword_F010C4C8)], %o0
F0030264: 80a22000                 cmp     %o0, 0
F0030268: 1280001e                 bne     locret_F00302E0
F003026C: b0102000                 mov     0, %i0
F0030270: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0030274: 153c0431                 sethi   %hi(aConfiguringNet), %o2! "Configuring Network"
F0030278: 173c0431                 sethi   %hi(aL_0), %o3! "%L"
F003027C: 9412a170                 bset    %lo(aConfiguringNet), %o2! "Configuring Network"
F0030280: 9612e188                 bset    %lo(aL_0), %o3! "%L"
F0030284: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0030288: 98102000                 mov     0, %o4
F003028C: d0026028                 ld      [%o1+0x28], %o0
F0030290: 9a102000                 mov     0, %o5
F0030294: d027bff0                 st      %o0, [%fp+var_10]
F0030298: d202602c                 ld      [%o1+0x2C], %o1
F003029C: 9010203c                 mov     0x3C, %o0 ! '<'
F00302A0: d227bff4                 st      %o1, [%fp+var_C]
F00302A4: c023a05c                 clr     [%sp+0x88+var_2C]
F00302A8: c023a060                 clr     [%sp+0x88+var_28]
F00302AC: c023a064                 clr     [%sp+0x88+var_24]
F00302B0: c023a068                 clr     [%sp+0x88+var_20]
F00302B4: c023a06c                 clr     [%sp+0x88+var_1C]
F00302B8: 40022f87                 call    _alert
F00302BC: 92102008                 mov     8, %o1
F00302C0: d40421dc                 ld      [%l0+0x1DC], %o2
F00302C4: b0100008                 mov     %o0, %i0
F00302C8: d207bff0                 ld      [%fp+var_10], %o1
F00302CC: 90102001                 mov     1, %o0
F00302D0: d222a028                 st      %o1, [%o2+0x28]
F00302D4: d207bff4                 ld      [%fp+var_C], %o1
F00302D8: d02460c8                 st      %o0, [%l1+0xC8]
F00302DC: d222a02c                 st      %o1, [%o2+0x2C]
F00302E0: 81c7e008                 ret
F00302E4: 81e80000                 restore
