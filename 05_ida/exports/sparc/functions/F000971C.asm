F000971C: 9de3bf98                 save    %sp, -0x68, %sp
F0009720: 053c04cf8410a300         set     _bufhash, %g2
F0009728: b0102000                 mov     0, %i0
F000972C: 8600a004                 add     %g2, 4, %g3
F0009730: c420e004                 st      %g2, [%g3+4]
F0009734: c420c000                 st      %g2, [%g3]
F0009738: b0062001                 inc     %i0
F000973C: 8600e00c                 inc     0xC, %g3
F0009740: 80a6200f                 cmp     %i0, 0xF
F0009744: 04bffffb                 ble     loc_F0009730
F0009748: 8400a00c                 inc     0xC, %g2
F000974C: 81c7e008                 ret
F0009750: 81e80000                 restore
