F00E2508: 9de3bf98                 save    %sp, -0x68, %sp
F00E250C: c0270000                 clr     [%i4]
F00E2510: 80a62001                 cmp     %i0, 1
F00E2514: 1280001d                 bne     loc_F00E2588
F00E2518: c026c000                 clr     [%i3]
F00E251C: b0102000                 mov     0, %i0
F00E2520: b536a001                 srl     %i2, 1, %i2
F00E2524: 80a6001a                 cmp     %i0, %i2
F00E2528: 3a800016                 bcc,a   loc_F00E2580
F00E252C: c406c000                 ld      [%i3], %g2
F00E2530: c40e4000                 ldub    [%i1], %g2
F00E2534: b2066001                 inc     %i1
F00E2538: 8618bf80                 xor     %g2, -0x80, %g3
F00E253C: 8408a07f                 and     %g2, 0x7F, %g2
F00E2540: 8610c002                 bset    %g2, %g3
F00E2544: 8088e080                 btst    0x80, %g3
F00E2548: 02800003                 be      loc_F00E2554
F00E254C: 84100003                 mov     %g3, %g2
F00E2550: 84200003                 neg     %g3, %g2
F00E2554: 8528a018                 sll     %g2, 24, %g2
F00E2558: c606c000                 ld      [%i3], %g3
F00E255C: 8538a018                 sra     %g2, 24, %g2
F00E2560: 80a08003                 cmp     %g2, %g3
F00E2564: 38800002                 bgu,a   loc_F00E256C
F00E2568: c426c000                 st      %g2, [%i3]
F00E256C: b0062001                 inc     %i0
F00E2570: 80a6001a                 cmp     %i0, %i2
F00E2574: 0abfffef                 bcs     loc_F00E2530
F00E2578: b2066001                 inc     %i1
F00E257C: c406c000                 ld      [%i3], %g2
F00E2580: 10800029                 ba      loc_F00E2624
F00E2584: c4270000                 st      %g2, [%i4]
F00E2588: b0102000                 mov     0, %i0
F00E258C: b536a001                 srl     %i2, 1, %i2
F00E2590: 80a6001a                 cmp     %i0, %i2
F00E2594: 3a800025                 bcc,a   loc_F00E2628
F00E2598: c4070000                 ld      [%i4], %g2
F00E259C: c40e4000                 ldub    [%i1], %g2
F00E25A0: b2066001                 inc     %i1
F00E25A4: 8618bf80                 xor     %g2, -0x80, %g3
F00E25A8: 8408a07f                 and     %g2, 0x7F, %g2
F00E25AC: 8610c002                 bset    %g2, %g3
F00E25B0: 8088e080                 btst    0x80, %g3
F00E25B4: 02800003                 be      loc_F00E25C0
F00E25B8: 84100003                 mov     %g3, %g2
F00E25BC: 84200003                 neg     %g3, %g2
F00E25C0: 8528a018                 sll     %g2, 24, %g2
F00E25C4: c606c000                 ld      [%i3], %g3
F00E25C8: 8538a018                 sra     %g2, 24, %g2
F00E25CC: 80a08003                 cmp     %g2, %g3
F00E25D0: 38800002                 bgu,a   loc_F00E25D8
F00E25D4: c426c000                 st      %g2, [%i3]
F00E25D8: c40e4000                 ldub    [%i1], %g2
F00E25DC: b2066001                 inc     %i1
F00E25E0: 8618bf80                 xor     %g2, -0x80, %g3
F00E25E4: 8408a07f                 and     %g2, 0x7F, %g2
F00E25E8: 8610c002                 bset    %g2, %g3
F00E25EC: 8088e080                 btst    0x80, %g3
F00E25F0: 02800003                 be      loc_F00E25FC
F00E25F4: 84100003                 mov     %g3, %g2
F00E25F8: 84200003                 neg     %g3, %g2
F00E25FC: 8528a018                 sll     %g2, 24, %g2
F00E2600: c6070000                 ld      [%i4], %g3
F00E2604: 8538a018                 sra     %g2, 24, %g2
F00E2608: 80a08003                 cmp     %g2, %g3
F00E260C: 38800002                 bgu,a   loc_F00E2614
F00E2610: c4270000                 st      %g2, [%i4]
F00E2614: b0062001                 inc     %i0
F00E2618: 80a6001a                 cmp     %i0, %i2
F00E261C: 2abfffe1                 bcs,a   loc_F00E25A0
F00E2620: c40e4000                 ldub    [%i1], %g2
F00E2624: c4070000                 ld      [%i4], %g2
F00E2628: 8528a008                 sll     %g2, 8, %g2
F00E262C: c4270000                 st      %g2, [%i4]
F00E2630: c406c000                 ld      [%i3], %g2
F00E2634: 8528a008                 sll     %g2, 8, %g2
F00E2638: c426c000                 st      %g2, [%i3]
F00E263C: 81c7e008                 ret
F00E2640: 81e80000                 restore
