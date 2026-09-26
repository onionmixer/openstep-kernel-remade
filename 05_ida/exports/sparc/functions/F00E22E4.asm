F00E22E4: 9de3bf98                 save    %sp, -0x68, %sp
F00E22E8: c0270000                 clr     [%i4]
F00E22EC: 80a62001                 cmp     %i0, 1
F00E22F0: 1280001d                 bne     loc_F00E2364
F00E22F4: c026c000                 clr     [%i3]
F00E22F8: b0102000                 mov     0, %i0
F00E22FC: b536a002                 srl     %i2, 2, %i2
F00E2300: 80a6001a                 cmp     %i0, %i2
F00E2304: 1a800015                 bcc     loc_F00E2358
F00E2308: 053c03e5                 sethi   %hi(_audio_muLaw), %g2
F00E230C: ba10a3c4                 or      %g2, %lo(_audio_muLaw), %i5
F00E2310: c40e4000                 ldub    [%i1], %g2
F00E2314: 8528a001                 sll     %g2, 1, %g2
F00E2318: c450801d                 ldsh    [%g2+%i5], %g2
F00E231C: b2066001                 inc     %i1
F00E2320: 80a0a000                 cmp     %g2, 0
F00E2324: 16800003                 bge     loc_F00E2330
F00E2328: 86100002                 mov     %g2, %g3
F00E232C: 86200003                 neg     %g3
F00E2330: 8528e010                 sll     %g3, 16, %g2
F00E2334: c606c000                 ld      [%i3], %g3
F00E2338: 8538a010                 sra     %g2, 16, %g2
F00E233C: 80a08003                 cmp     %g2, %g3
F00E2340: 38800002                 bgu,a   loc_F00E2348
F00E2344: c426c000                 st      %g2, [%i3]
F00E2348: b0062001                 inc     %i0
F00E234C: 80a6001a                 cmp     %i0, %i2
F00E2350: 0abffff0                 bcs     loc_F00E2310
F00E2354: b2066003                 inc     3, %i1
F00E2358: c406c000                 ld      [%i3], %g2
F00E235C: 10800029                 ba      locret_F00E2400
F00E2360: c4270000                 st      %g2, [%i4]
F00E2364: b0102000                 mov     0, %i0
F00E2368: b536a002                 srl     %i2, 2, %i2
F00E236C: 80a6001a                 cmp     %i0, %i2
F00E2370: 1a800024                 bcc     locret_F00E2400
F00E2374: 053c03e5                 sethi   %hi(_audio_muLaw), %g2
F00E2378: ba10a3c4                 or      %g2, %lo(_audio_muLaw), %i5
F00E237C: c40e4000                 ldub    [%i1], %g2
F00E2380: 8528a001                 sll     %g2, 1, %g2
F00E2384: c450801d                 ldsh    [%g2+%i5], %g2
F00E2388: b2066001                 inc     %i1
F00E238C: 80a0a000                 cmp     %g2, 0
F00E2390: 16800003                 bge     loc_F00E239C
F00E2394: 86100002                 mov     %g2, %g3
F00E2398: 86200003                 neg     %g3
F00E239C: 8528e010                 sll     %g3, 16, %g2
F00E23A0: c606c000                 ld      [%i3], %g3
F00E23A4: 8538a010                 sra     %g2, 16, %g2
F00E23A8: 80a08003                 cmp     %g2, %g3
F00E23AC: 38800002                 bgu,a   loc_F00E23B4
F00E23B0: c426c000                 st      %g2, [%i3]
F00E23B4: b2066001                 inc     %i1
F00E23B8: c40e4000                 ldub    [%i1], %g2
F00E23BC: 8528a001                 sll     %g2, 1, %g2
F00E23C0: c450801d                 ldsh    [%g2+%i5], %g2
F00E23C4: b2066001                 inc     %i1
F00E23C8: 80a0a000                 cmp     %g2, 0
F00E23CC: 16800003                 bge     loc_F00E23D8
F00E23D0: 86100002                 mov     %g2, %g3
F00E23D4: 86200003                 neg     %g3
F00E23D8: 8528e010                 sll     %g3, 16, %g2
F00E23DC: c6070000                 ld      [%i4], %g3
F00E23E0: 8538a010                 sra     %g2, 16, %g2
F00E23E4: 80a08003                 cmp     %g2, %g3
F00E23E8: 38800002                 bgu,a   loc_F00E23F0
F00E23EC: c4270000                 st      %g2, [%i4]
F00E23F0: b0062001                 inc     %i0
F00E23F4: 80a6001a                 cmp     %i0, %i2
F00E23F8: 0abfffe1                 bcs     loc_F00E237C
F00E23FC: b2066001                 inc     %i1
F00E2400: 81c7e008                 ret
F00E2404: 81e80000                 restore
