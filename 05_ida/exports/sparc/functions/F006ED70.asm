F006ED70: 9de3bf98                 save    %sp, -0x68, %sp
F006ED74: c0262100                 clr     [%i0+0x100]
F006ED78: 8410201f                 mov     0x1F, %g2
F006ED7C: c4262104                 st      %g2, [%i0+0x104]
F006ED80: c0262108                 clr     [%i0+0x108]
F006ED84: 86102000                 mov     0, %g3
F006ED88: 84100018                 mov     %i0, %g2
F006ED8C: c420a004                 st      %g2, [%g2+4]
F006ED90: c4208000                 st      %g2, [%g2]
F006ED94: 8600e001                 inc     %g3
F006ED98: 80a0e01f                 cmp     %g3, 0x1F
F006ED9C: 04bffffc                 ble     loc_F006ED8C
F006EDA0: 8400a008                 inc     8, %g2
F006EDA4: 8406210c                 add     %i0, 0x10C, %g2
F006EDA8: c4262110                 st      %g2, [%i0+0x110]
F006EDAC: c426210c                 st      %g2, [%i0+0x10C]
F006EDB0: c0262114                 clr     [%i0+0x114]
F006EDB4: c0262118                 clr     [%i0+0x118]
F006EDB8: 8406211c                 add     %i0, 0x11C, %g2
F006EDBC: c4262120                 st      %g2, [%i0+0x120]
F006EDC0: c426211c                 st      %g2, [%i0+0x11C]
F006EDC4: c0262124                 clr     [%i0+0x124]
F006EDC8: 86102001                 mov     1, %g3
F006EDCC: c6262128                 st      %g3, [%i0+0x128]
F006EDD0: 8406212c                 add     %i0, 0x12C, %g2
F006EDD4: c4262130                 st      %g2, [%i0+0x130]
F006EDD8: c426212c                 st      %g2, [%i0+0x12C]
F006EDDC: c0262134                 clr     [%i0+0x134]
F006EDE0: 84062138                 add     %i0, 0x138, %g2
F006EDE4: c426213c                 st      %g2, [%i0+0x13C]
F006EDE8: c4262138                 st      %g2, [%i0+0x138]
F006EDEC: c0262140                 clr     [%i0+0x140]
F006EDF0: c6262144                 st      %g3, [%i0+0x144]
F006EDF4: c0262148                 clr     [%i0+0x148]
F006EDF8: 8406214c                 add     %i0, 0x14C, %g2
F006EDFC: c4262150                 st      %g2, [%i0+0x150]
F006EE00: c426214c                 st      %g2, [%i0+0x14C]
F006EE04: c0262154                 clr     [%i0+0x154]
F006EE08: c0262158                 clr     [%i0+0x158]
F006EE0C: c026215c                 clr     [%i0+0x15C]
F006EE10: c0262160                 clr     [%i0+0x160]
F006EE14: 84102012                 mov     0x12, %g2
F006EE18: c4262164                 st      %g2, [%i0+0x164]
F006EE1C: c6262168                 st      %g3, [%i0+0x168]
F006EE20: c0262170                 clr     [%i0+0x170]
F006EE24: 053c04f0                 sethi   %hi(_min_quantum), %g2
F006EE28: c600a290                 ld      [%g2+%lo(_min_quantum)], %g3
F006EE2C: c0262174                 clr     [%i0+0x174]
F006EE30: 84102080                 mov     0x80, %g2
F006EE34: c4262178                 st      %g2, [%i0+0x178]
F006EE38: c626216c                 st      %g3, [%i0+0x16C]
F006EE3C: 81c7e008                 ret
F006EE40: 81e80000                 restore
