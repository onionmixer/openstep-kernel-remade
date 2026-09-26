F005AA18: 9de3bf98                 save    %sp, -0x68, %sp
F005AA1C: f226200c                 st      %i1, [%i0+0xC]
F005AA20: f4262010                 st      %i2, [%i0+0x10]
F005AA24: c0262018                 clr     [%i0+0x18]
F005AA28: c026201c                 clr     [%i0+0x1C]
F005AA2C: c0262020                 clr     [%i0+0x20]
F005AA30: c0262024                 clr     [%i0+0x24]
F005AA34: c0262028                 clr     [%i0+0x28]
F005AA38: c026202c                 clr     [%i0+0x2C]
F005AA3C: c0262030                 clr     [%i0+0x30]
F005AA40: c0262034                 clr     [%i0+0x34]
F005AA44: c0262038                 clr     [%i0+0x38]
F005AA48: 90102005                 mov     5, %o0
F005AA4C: d026203c                 st      %o0, [%i0+0x3C]
F005AA50: 7ffff64a                 call    _ipc_mqueue_init
F005AA54: 90062040                 add     %i0, 0x40, %o0 ! '@'
F005AA58: c026204c                 clr     [%i0+0x4C]
F005AA5C: 81c7e008                 ret
F005AA60: 81e80000                 restore
