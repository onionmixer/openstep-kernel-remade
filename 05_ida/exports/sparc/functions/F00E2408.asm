F00E2408: 9de3bf98                 save    %sp, -0x68, %sp
F00E240C: c0270000                 clr     [%i4]
F00E2410: 80a62001                 cmp     %i0, 1
F00E2414: 1280001a                 bne     loc_F00E247C
F00E2418: c026c000                 clr     [%i3]
F00E241C: b0102000                 mov     0, %i0
F00E2420: b536a001                 srl     %i2, 1, %i2
F00E2424: 80a6001a                 cmp     %i0, %i2
F00E2428: 3a800013                 bcc,a   loc_F00E2474
F00E242C: c406c000                 ld      [%i3], %g2
F00E2430: c6164000                 lduh    [%i1], %g3
F00E2434: 8528e010                 sll     %g3, 16, %g2
F00E2438: 80a0a000                 cmp     %g2, 0
F00E243C: 16800004                 bge     loc_F00E244C
F00E2440: b2066002                 inc     2, %i1
F00E2444: 86200003                 neg     %g3
F00E2448: 8528e010                 sll     %g3, 16, %g2
F00E244C: c606c000                 ld      [%i3], %g3
F00E2450: 8538a010                 sra     %g2, 16, %g2
F00E2454: 80a08003                 cmp     %g2, %g3
F00E2458: 38800002                 bgu,a   loc_F00E2460
F00E245C: c426c000                 st      %g2, [%i3]
F00E2460: b0062001                 inc     %i0
F00E2464: 80a6001a                 cmp     %i0, %i2
F00E2468: 0abffff2                 bcs     loc_F00E2430
F00E246C: b2066002                 inc     2, %i1
F00E2470: c406c000                 ld      [%i3], %g2
F00E2474: 10800023                 ba      locret_F00E2500
F00E2478: c4270000                 st      %g2, [%i4]
F00E247C: b0102000                 mov     0, %i0
F00E2480: b536a001                 srl     %i2, 1, %i2
F00E2484: 80a6001a                 cmp     %i0, %i2
F00E2488: 1a80001e                 bcc     locret_F00E2500
F00E248C: 01000000                 nop
F00E2490: c6164000                 lduh    [%i1], %g3
F00E2494: 8528e010                 sll     %g3, 16, %g2
F00E2498: 80a0a000                 cmp     %g2, 0
F00E249C: 16800004                 bge     loc_F00E24AC
F00E24A0: b2066002                 inc     2, %i1
F00E24A4: 86200003                 neg     %g3
F00E24A8: 8528e010                 sll     %g3, 16, %g2
F00E24AC: c606c000                 ld      [%i3], %g3
F00E24B0: 8538a010                 sra     %g2, 16, %g2
F00E24B4: 80a08003                 cmp     %g2, %g3
F00E24B8: 38800002                 bgu,a   loc_F00E24C0
F00E24BC: c426c000                 st      %g2, [%i3]
F00E24C0: c6164000                 lduh    [%i1], %g3
F00E24C4: 8528e010                 sll     %g3, 16, %g2
F00E24C8: 80a0a000                 cmp     %g2, 0
F00E24CC: 16800004                 bge     loc_F00E24DC
F00E24D0: b2066002                 inc     2, %i1
F00E24D4: 86200003                 neg     %g3
F00E24D8: 8528e010                 sll     %g3, 16, %g2
F00E24DC: c6070000                 ld      [%i4], %g3
F00E24E0: 8538a010                 sra     %g2, 16, %g2
F00E24E4: 80a08003                 cmp     %g2, %g3
F00E24E8: 38800002                 bgu,a   loc_F00E24F0
F00E24EC: c4270000                 st      %g2, [%i4]
F00E24F0: b0062001                 inc     %i0
F00E24F4: 80a6001a                 cmp     %i0, %i2
F00E24F8: 2abfffe7                 bcs,a   loc_F00E2494
F00E24FC: c6164000                 lduh    [%i1], %g3
F00E2500: 81c7e008                 ret
F00E2504: 81e80000                 restore
