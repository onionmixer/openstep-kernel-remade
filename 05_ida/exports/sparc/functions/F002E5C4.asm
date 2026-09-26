F002E5C4: 9de3bf98                 save    %sp, -0x68, %sp
F002E5C8: 053c04bd8610a01e         set     unk_F012F41E, %g3
F002E5D0: b2102000                 mov     0, %i1
F002E5D4: 053c0431b410a090         set     a0123456789abcd, %i2! "0123456789abcdef"
F002E5DC: b610203a                 mov     0x3A, %i3 ! ':'
F002E5E0: c40e0000                 ldub    [%i0], %g2
F002E5E4: b2066001                 inc     %i1
F002E5E8: 8530a004                 srl     %g2, 4, %g2
F002E5EC: c408801a                 ldub    [%g2+%i2], %g2
F002E5F0: 80a66005                 cmp     %i1, 5
F002E5F4: c428c000                 stb     %g2, [%g3]
F002E5F8: c40e0000                 ldub    [%i0], %g2
F002E5FC: 8600e001                 inc     %g3
F002E600: 8408a00f                 and     %g2, 0xF, %g2
F002E604: c408801a                 ldub    [%g2+%i2], %g2
F002E608: b0062001                 inc     %i0
F002E60C: c428c000                 stb     %g2, [%g3]
F002E610: 8600e001                 inc     %g3
F002E614: f628c000                 stb     %i3, [%g3]
F002E618: 04bffff2                 ble     loc_F002E5E0
F002E61C: 8600e001                 inc     %g3
F002E620: c028ffff                 clrb    [%g3-1]
F002E624: 313c04bdb016201e         set     unk_F012F41E, %i0
F002E62C: 81c7e008                 ret
F002E630: 81e80000                 restore
