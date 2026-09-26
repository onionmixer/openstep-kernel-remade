F00936EC: 9de3bf90                 save    %sp, -0x70, %sp
F00936F0: 1120011990122014         set     -0x7FFB9BEC, %o0
F00936F8: 80a64008                 cmp     %i1, %o0
F00936FC: 02800016                 be      loc_F0093754
F0093700: b0102000                 mov     0, %i0
F0093704: 80a64008                 cmp     %i1, %o0
F0093708: 14800009                 bg      loc_F009372C
F009370C: 11200119                 sethi   -0x7FFB9C00, %o0
F0093710: 112000999012201b         set     -0x7FFD9BE5, %o0
F0093718: 80a64008                 cmp     %i1, %o0
F009371C: 02800060                 be      loc_F009389C
F0093720: 01000000                 nop
F0093724: 10800060                 ba      locret_F00938A4
F0093728: b0102016                 mov     0x16, %i0
F009372C: 90122016                 bset    0x16, %o0
F0093730: 80a64008                 cmp     %i1, %o0
F0093734: 02800048                 be      loc_F0093854
F0093738: 11080019                 sethi   0x20006400, %o0
F009373C: 9012201a                 bset    0x1A, %o0
F0093740: 80a64008                 cmp     %i1, %o0
F0093744: 02800053                 be      loc_F0093890
F0093748: 133c04c4                 sethi   -0xFECF000, %o1
F009374C: 10800056                 ba      locret_F00938A4
F0093750: b0102016                 mov     0x16, %i0
F0093754: d2068000                 ld      [%i2], %o1
F0093758: 113c04d0                 sethi   %hi(_active_threads), %o0
F009375C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0093760: 153c0449                 sethi   %hi(dword_F0112510), %o2
F0093764: d002200c                 ld      [%o0+0xC], %o0
F0093768: 7fff9f13                 call    _get_kern_port
F009376C: 9412a110                 bset    %lo(dword_F0112510), %o2
F0093770: 80a22000                 cmp     %o0, 0
F0093774: 22800004                 be,a    loc_F0093784
F0093778: 113c04c4                 sethi   -0xFECF000, %o0
F009377C: 10800031                 ba      loc_F0093840
F0093780: b0102016                 mov     0x16, %i0
F0093784: 7fff5590                 call    _lock_write
F0093788: 90122254                 bset    0x254, %o0
F009378C: 113c0449                 sethi   %hi(off_F0112520), %o0
F0093790: f2022120                 ld      [%o0+%lo(off_F0112520)], %i1
F0093794: 92122120                 or      %o0, %lo(off_F0112520), %o1
F0093798: 80a64009                 cmp     %i1, %o1
F009379C: 22800027                 be,a    loc_F0093838
F00937A0: 113c04c4                 sethi   -0xFECF000, %o0
F00937A4: a0100009                 mov     %o1, %l0
F00937A8: a2100008                 mov     %o0, %l1
F00937AC: 253c04d2                 sethi   -0xFECB800, %l2
F00937B0: f4064000                 ld      [%i1], %i2
F00937B4: 9210001a                 mov     %i2, %o1
F00937B8: 80a68010                 cmp     %i2, %l0
F00937BC: 12800004                 bne     loc_F00937CC
F00937C0: d0066004                 ld      [%i1+4], %o0
F00937C4: 10800003                 ba      loc_F00937D0
F00937C8: d0242004                 st      %o0, [%l0+4]
F00937CC: d026a004                 st      %o0, [%i2+4]
F00937D0: 80a20010                 cmp     %o0, %l0
F00937D4: 32800003                 bne,a   loc_F00937E0
F00937D8: d2220000                 st      %o1, [%o0]
F00937DC: d2246120                 st      %o1, [%l1+0x120]
F00937E0: d256600c                 ldsh    [%i1+0xC], %o1
F00937E4: d054a1c8                 ldsh    [%l2+0x1C8], %o0
F00937E8: 80a24008                 cmp     %o1, %o0
F00937EC: 0280000b                 be      loc_F0093818
F00937F0: 9a066058                 add     %i1, 0x58, %o5 ! 'X'
F00937F4: d0066008                 ld      [%i1+8], %o0
F00937F8: d456600e                 ldsh    [%i1+0xE], %o2
F00937FC: d6066010                 ld      [%i1+0x10], %o3
F0093800: d8066014                 ld      [%i1+0x14], %o4
F0093804: da23a05c                 st      %o5, [%sp+0x70+var_14]
F0093808: da066060                 ld      [%i1+0x60], %o5
F009380C: da23a060                 st      %o5, [%sp+0x70+var_10]
F0093810: 40000035                 call    sub_F00938E4
F0093814: 9a066018                 add     %i1, 0x18, %o5
F0093818: 90100019                 mov     %i1, %o0
F009381C: 7fff5261                 call    _kfree
F0093820: 92102064                 mov     0x64, %o1 ! 'd'
F0093824: b210001a                 mov     %i2, %i1
F0093828: 80a64010                 cmp     %i1, %l0
F009382C: 32bfffe2                 bne,a   loc_F00937B4
F0093830: f4064000                 ld      [%i1], %i2
F0093834: 113c04c4                 sethi   -0xFECF000, %o0
F0093838: 7fff55ff                 call    _lock_done
F009383C: 90122254                 bset    0x254, %o0
F0093840: 80a62000                 cmp     %i0, 0
F0093844: 12800018                 bne     locret_F00938A4
F0093848: 113c0449                 sethi   %hi(dword_F0112510), %o0
F009384C: 1080000d                 ba      loc_F0093880
F0093850: d0022110                 ld      [%o0+%lo(dword_F0112510)], %o0
F0093854: d2068000                 ld      [%i2], %o1
F0093858: 113c04d0                 sethi   %hi(_active_threads), %o0
F009385C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0093860: 213c0449                 sethi   %hi(_panel_req_port), %l0
F0093864: d002200c                 ld      [%o0+0xC], %o0
F0093868: 7fff9ed3                 call    _get_kern_port
F009386C: 94142114                 or      %l0, %lo(_panel_req_port), %o2
F0093870: 80a22000                 cmp     %o0, 0
F0093874: 32800002                 bne,a   loc_F009387C
F0093878: b0102016                 mov     0x16, %i0
F009387C: d0042114                 ld      [%l0+0x114], %o0
F0093880: 133c0449                 sethi   %hi(dword_F0112518), %o1
F0093884: 7fff9e8c                 call    _port_request_notification
F0093888: d2026118                 ld      [%o1+%lo(dword_F0112518)], %o1
F009388C: 30800006                 ba,a    locret_F00938A4
F0093890: 90102001                 mov     1, %o0
F0093894: 10800004                 ba      locret_F00938A4
F0093898: d0226264                 st      %o0, [%o1+0x264]
F009389C: 4000007c                 call    _vol_notify_cancel
F00938A0: d0568000                 ldsh    [%i2], %o0
F00938A4: 81c7e008                 ret
F00938A8: 81e80000                 restore
