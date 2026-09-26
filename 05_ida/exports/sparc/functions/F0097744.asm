F0097744: 9de3bf98                 save    %sp, -0x68, %sp
F0097748: 193c04c5                 sethi   %hi(qword_F0131478), %o4
F009774C: d41b2078                 ldd     [%o4+%lo(qword_F0131478)], %o2
F0097750: 90102000                 mov     0, %o0
F0097754: 1300000992126310         set     0x2710, %o1
F009775C: 9682c009                 addcc   %o3, %o1, %o3
F0097760: 94428008                 addc    %o2, %o0, %o2
F0097764: 113c04c5                 sethi   %hi(dword_F0131494), %o0
F0097768: d0022094                 ld      [%o0+%lo(dword_F0131494)], %o0
F009776C: 80a22000                 cmp     %o0, 0
F0097770: 0280000e                 be      loc_F00977A8
F0097774: d43b2078                 std     %o2, [%o4+%lo(qword_F0131478)]
F0097778: 113c043e                 sethi   %hi(_tick), %o0
F009777C: d00223e4                 ld      [%o0+%lo(_tick)], %o0
F0097780: 93366006                 srl     %i1, 6, %o1
F0097784: 921a6001                 btog    1, %o1
F0097788: 920a6001                 and     %o1, 1, %o1
F009778C: 940e6f00                 and     %i1, 0xF00, %o2
F0097790: 80a0000a                 cmp     %g0, %o2
F0097794: 7fff4809                 call    _clock_interrupt
F0097798: 94603fff                 subc    %g0, -1, %o2
F009779C: 90100018                 mov     %i0, %o0
F00977A0: 7ffdc97b                 call    _hardclock
F00977A4: 92100019                 mov     %i1, %o1
F00977A8: 213c04c5                 sethi   %hi(dword_F0131490), %l0
F00977AC: d0042090                 ld      [%l0+%lo(dword_F0131490)], %o0
F00977B0: 80a22000                 cmp     %o0, 0
F00977B4: 02800020                 be      locret_F0097834
F00977B8: 313c04c5                 sethi   %hi(qword_F0131488), %i0
F00977BC: d0062088                 ld      [%i0+%lo(qword_F0131488)], %o0
F00977C0: 80a22000                 cmp     %o0, 0
F00977C4: 12800006                 bne     loc_F00977DC
F00977C8: b2162088                 or      %i0, %lo(qword_F0131488), %i1
F00977CC: d0066004                 ld      [%i1+4], %o0
F00977D0: 80a22000                 cmp     %o0, 0
F00977D4: 02800018                 be      locret_F0097834
F00977D8: 01000000                 nop
F00977DC: 4000004b                 call    _clock_value
F00977E0: 90102001                 mov     1, %o0
F00977E4: d8062088                 ld      [%i0+0x88], %o4
F00977E8: 94100008                 mov     %o0, %o2
F00977EC: 96100009                 mov     %o1, %o3
F00977F0: 80a3000a                 cmp     %o4, %o2
F00977F4: 18800010                 bgu     locret_F0097834
F00977F8: 01000000                 nop
F00977FC: 12800006                 bne     loc_F0097814
F0097800: 01000000                 nop
F0097804: d0066004                 ld      [%i1+4], %o0
F0097808: 80a2000b                 cmp     %o0, %o3
F009780C: 1880000a                 bgu     locret_F0097834
F0097810: 01000000                 nop
F0097814: 84102000                 mov     0, %g2
F0097818: 86102000                 mov     0, %g3
F009781C: c43e2088                 std     %g2, [%i0+0x88]
F0097820: 90102000                 mov     0, %o0
F0097824: 92102000                 mov     0, %o1
F0097828: d6042090                 ld      [%l0+0x90], %o3
F009782C: 9fc2c000                 call    %o3
F0097830: 94102000                 mov     0, %o2
F0097834: 81c7e008                 ret
F0097838: 81e80000                 restore
