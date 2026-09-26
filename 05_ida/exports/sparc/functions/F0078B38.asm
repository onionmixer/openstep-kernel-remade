F0078B38: 9de3bf98                 save    %sp, -0x68, %sp
F0078B3C: 113c04f2                 sethi   %hi(_all_zones_lock), %o0
F0078B40: c0222380                 clr     [%o0+%lo(_all_zones_lock)]
F0078B44: 113c04f2                 sethi   %hi(_first_zone), %o0
F0078B48: c0222388                 clr     [%o0+%lo(_first_zone)]
F0078B4C: 90122388                 bset    %lo(_first_zone), %o0
F0078B50: 133c04f2                 sethi   %hi(_last_zone), %o1
F0078B54: d0226390                 st      %o0, [%o1+%lo(_last_zone)]
F0078B58: 113c04f2                 sethi   %hi(_num_zones), %o0
F0078B5C: c0222398                 clr     [%o0+%lo(_num_zones)]
F0078B60: 113c04f2                 sethi   %hi(_zget_space_lock), %o0
F0078B64: c02223a8                 clr     [%o0+%lo(_zget_space_lock)]
F0078B68: 133c04f292126350         set     __zone_default_space, %o1
F0078B70: 113c04f290122370         set     __zone_default_space_hint, %o0
F0078B78: d0226014                 st      %o0, [%o1+0x14]
F0078B7C: 94102001                 mov     1, %o2
F0078B80: d4226018                 st      %o2, [%o1+0x18]
F0078B84: 113c04f2                 sethi   %hi(_zone_free_space), %o0
F0078B88: d22223b0                 st      %o1, [%o0+%lo(_zone_free_space)]
F0078B8C: 113c04f2                 sethi   %hi(_zone_free_space_count), %o0
F0078B90: d42223d0                 st      %o2, [%o0+%lo(_zone_free_space_count)]
F0078B94: 213c04f2                 sethi   %hi(_zone_zone), %l0
F0078B98: c02423e8                 clr     [%l0+%lo(_zone_zone)]
F0078B9C: 90102044                 mov     0x44, %o0 ! 'D'
F0078BA0: 1300000892126200         set     0x2200, %o1
F0078BA8: 193c0443                 sethi   %hi(aZones), %o4! "zones"
F0078BAC: 94102044                 mov     0x44, %o2 ! 'D'
F0078BB0: 96102000                 mov     0, %o3
F0078BB4: 7ffffce1                 call    _zinit
F0078BB8: 98132028                 bset    %lo(aZones), %o4! "zones"
F0078BBC: d02423e8                 st      %o0, [%l0+%lo(_zone_zone)]
F0078BC0: 90102010                 mov     0x10, %o0
F0078BC4: 7fffff8b                 call    sub_F00789F0
F0078BC8: 92102060                 mov     0x60, %o1 ! '`'
F0078BCC: 90102080                 mov     0x80, %o0
F0078BD0: 7fffff88                 call    sub_F00789F0
F0078BD4: 92102300                 mov     0x300, %o1
F0078BD8: 113c0447                 sethi   %hi(_page_size), %o0
F0078BDC: d202213c                 ld      [%o0+%lo(_page_size)], %o1
F0078BE0: 7fffff84                 call    sub_F00789F0
F0078BE4: 90102400                 mov     0x400, %o0
F0078BE8: 81c7e008                 ret
F0078BEC: 81e80000                 restore
