F0073FF0: 9de3bf98                 save    %sp, -0x68, %sp
F0073FF4: 901021a0                 mov     0x1A0, %o0
F0073FF8: 193c0442                 sethi   %hi(aThreads), %o4! "threads"
F0073FFC: 130000d0                 sethi   0x34000, %o1
F0074000: 1500001a                 sethi   0x6800, %o2
F0074004: 96102000                 mov     0, %o3
F0074008: 40000fcc                 call    _zinit
F007400C: 981322a8                 bset    %lo(aThreads), %o4! "threads"
F0074010: 133c04f2                 sethi   %hi(_thread_zone), %o1
F0074014: d0226320                 st      %o0, [%o1+%lo(_thread_zone)]
F0074018: 213c04f2a0142180         set     _thread_template, %l0
F0074020: c0242008                 clr     [%l0+8]
F0074024: 90102002                 mov     2, %o0
F0074028: d0242024                 st      %o0, [%l0+0x24]
F007402C: c0242028                 clr     [%l0+0x28]
F0074030: c024202c                 clr     [%l0+0x2C]
F0074034: c0242030                 clr     [%l0+0x30]
F0074038: c024203c                 clr     [%l0+0x3C]
F007403C: c0242044                 clr     [%l0+0x44]
F0074040: c0242048                 clr     [%l0+0x48]
F0074044: 90102102                 mov     0x102, %o0
F0074048: d024204c                 st      %o0, [%l0+0x4C]
F007404C: 113c026f901223d0         set     _thread_bootstrap_return, %o0
F0074054: d0242034                 st      %o0, [%l0+0x34]
F0074058: c0242038                 clr     [%l0+0x38]
F007405C: 90102012                 mov     0x12, %o0
F0074060: d0242054                 st      %o0, [%l0+0x54]
F0074064: c024205c                 clr     [%l0+0x5C]
F0074068: 92102001                 mov     1, %o1
F007406C: d2242060                 st      %o1, [%l0+0x60]
F0074070: 90103fff                 mov     -1, %o0
F0074074: d0242064                 st      %o0, [%l0+0x64]
F0074078: c0242068                 clr     [%l0+0x68]
F007407C: c024206c                 clr     [%l0+0x6C]
F0074080: c0242074                 clr     [%l0+0x74]
F0074084: c0242078                 clr     [%l0+0x78]
F0074088: c024207c                 clr     [%l0+0x7C]
F007408C: c0242080                 clr     [%l0+0x80]
F0074090: d0242088                 st      %o0, [%l0+0x88]
F0074094: d224208c                 st      %o1, [%l0+0x8C]
F0074098: 40000e29                 call    _timer_init
F007409C: 900420e0                 add     %l0, 0xE0, %o0
F00740A0: 40000e27                 call    _timer_init
F00740A4: 900420f0                 add     %l0, 0xF0, %o0
F00740A8: c0242100                 clr     [%l0+0x100]
F00740AC: c0242104                 clr     [%l0+0x104]
F00740B0: c0242108                 clr     [%l0+0x108]
F00740B4: c024210c                 clr     [%l0+0x10C]
F00740B8: c0242110                 clr     [%l0+0x110]
F00740BC: c0242114                 clr     [%l0+0x114]
F00740C0: c0242188                 clr     [%l0+0x188]
F00740C4: c024218c                 clr     [%l0+0x18C]
F00740C8: c0242194                 clr     [%l0+0x194]
F00740CC: 7fffd099                 call    _initKernelStacks
F00740D0: c0242198                 clr     [%l0+0x198]
F00740D4: 133c04d490126150         set     _reaper_queue, %o0
F00740DC: d0222004                 st      %o0, [%o0+4]
F00740E0: d0226150                 st      %o0, [%o1+0x150]
F00740E4: 113c04f2                 sethi   %hi(_reaper_lock), %o0
F00740E8: c0222168                 clr     [%o0+%lo(_reaper_lock)]
F00740EC: 113c04f2                 sethi   %hi(_stack_usage_lock), %o0
F00740F0: c0222170                 clr     [%o0+%lo(_stack_usage_lock)]
F00740F4: 40009e39                 call    _pcb_module_init
F00740F8: 01000000                 nop
F00740FC: 81c7e008                 ret
F0074100: 81e80000                 restore
