F006EE44: 9de3bf98                 save    %sp, -0x68, %sp
F006EE48: c0262100                 clr     [%i0+0x100]
F006EE4C: 8410201f                 mov     0x1F, %g2
F006EE50: c4262104                 st      %g2, [%i0+0x104]
F006EE54: c0262108                 clr     [%i0+0x108]
F006EE58: 86102000                 mov     0, %g3
F006EE5C: 84100018                 mov     %i0, %g2
F006EE60: c420a004                 st      %g2, [%g2+4]
F006EE64: c4208000                 st      %g2, [%g2]
F006EE68: 8600e001                 inc     %g3
F006EE6C: 80a0e01f                 cmp     %g3, 0x1F
F006EE70: 04bffffc                 ble     loc_F006EE60
F006EE74: 8400a008                 inc     8, %g2
F006EE78: 8406210c                 add     %i0, 0x10C, %g2
F006EE7C: c4262110                 st      %g2, [%i0+0x110]
F006EE80: c426210c                 st      %g2, [%i0+0x10C]
F006EE84: c0262114                 clr     [%i0+0x114]
F006EE88: c0262118                 clr     [%i0+0x118]
F006EE8C: c026211c                 clr     [%i0+0x11C]
F006EE90: c0262120                 clr     [%i0+0x120]
F006EE94: c0262124                 clr     [%i0+0x124]
F006EE98: c0262128                 clr     [%i0+0x128]
F006EE9C: c026212c                 clr     [%i0+0x12C]
F006EEA0: c0262130                 clr     [%i0+0x130]
F006EEA4: 84062134                 add     %i0, 0x134, %g2
F006EEA8: c4262138                 st      %g2, [%i0+0x138]
F006EEAC: c4262134                 st      %g2, [%i0+0x134]
F006EEB0: c026213c                 clr     [%i0+0x13C]
F006EEB4: c0262140                 clr     [%i0+0x140]
F006EEB8: f2262144                 st      %i1, [%i0+0x144]
F006EEBC: 81c7e008                 ret
F006EEC0: 81e80000                 restore
