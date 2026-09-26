F00638BC: 9de3bf98                 save    %sp, -0x68, %sp
F00638C0: b0102000                 mov     0, %i0
F00638C4: 053c04cf8410a160         set     _need_ast, %g2
F00638CC: 86102000                 mov     0, %g3
F00638D0: c020c002                 clr     [%g3+%g2]
F00638D4: b0062001                 inc     %i0
F00638D8: 80a62000                 cmp     %i0, 0
F00638DC: 04bffffd                 ble     loc_F00638D0
F00638E0: 8600e004                 inc     4, %g3
F00638E4: 81c7e008                 ret
F00638E8: 81e80000                 restore
