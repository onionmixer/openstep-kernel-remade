F0070B58: 9de3bf98                 save    %sp, -0x68, %sp
F0070B5C: b0102000                 mov     0, %i0
F0070B60: 053c04f1b210a290         set     _wait_lock, %i1
F0070B68: 86102000                 mov     0, %g3
F0070B6C: 053c04f18410a380         set     _wait_queue, %g2
F0070B74: c420a004                 st      %g2, [%g2+4]
F0070B78: c4208000                 st      %g2, [%g2]
F0070B7C: c020c019                 clr     [%g3+%i1]
F0070B80: 8600e004                 inc     4, %g3
F0070B84: b0062001                 inc     %i0
F0070B88: 80a6203a                 cmp     %i0, 0x3A ! ':'
F0070B8C: 04bffffa                 ble     loc_F0070B74
F0070B90: 8400a008                 inc     8, %g2
F0070B94: 81c7e008                 ret
F0070B98: 81e80000                 restore
