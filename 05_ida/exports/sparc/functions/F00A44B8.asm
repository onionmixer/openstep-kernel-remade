F00A44B8: 9de3bf98                 save    %sp, -0x68, %sp
F00A44BC: b6960000                 orcc    %i0, %g0, %i3
F00A44C0: 02800021                 be      loc_F00A4544
F00A44C4: 82100019                 mov     %i1, %g1
F00A44C8: b400401a                 add     %g1, %i2, %i2
F00A44CC: c406c000                 ld      [%i3], %g2
F00A44D0: b0102000                 mov     0, %i0
F00A44D4: 80a08018                 cmp     %g2, %i0
F00A44D8: 18800017                 bgu     loc_F00A4534
F00A44DC: b2100001                 mov     %g1, %i1
F00A44E0: 80a08018                 cmp     %g2, %i0
F00A44E4: 32800007                 bne,a   loc_F00A4500
F00A44E8: f01ec000                 ldd     [%i3], %i0
F00A44EC: c406e004                 ld      [%i3+4], %g2
F00A44F0: 80a08019                 cmp     %g2, %i1
F00A44F4: 38800011                 bgu,a   loc_F00A4538
F00A44F8: f606e010                 ld      [%i3+0x10], %i3
F00A44FC: f01ec000                 ldd     [%i3], %i0
F00A4500: c41ee008                 ldd     [%i3+8], %g2
F00A4504: b8102000                 mov     0, %i4
F00A4508: b2864003                 addcc   %i1, %g3, %i1
F00A450C: b0460002                 addc    %i0, %g2, %i0
F00A4510: 80a70018                 cmp     %i4, %i0
F00A4514: 18800008                 bgu     loc_F00A4534
F00A4518: ba10001a                 mov     %i2, %i5
F00A451C: 80a70018                 cmp     %i4, %i0
F00A4520: 1280000a                 bne     locret_F00A4548
F00A4524: b0102001                 mov     1, %i0
F00A4528: 80a74019                 cmp     %i5, %i1
F00A452C: 08800007                 bleu    locret_F00A4548
F00A4530: 01000000                 nop
F00A4534: f606e010                 ld      [%i3+0x10], %i3
F00A4538: 80a6e000                 cmp     %i3, 0
F00A453C: 32bfffe5                 bne,a   loc_F00A44D0
F00A4540: c406c000                 ld      [%i3], %g2
F00A4544: b0102000                 mov     0, %i0
F00A4548: 81c7e008                 ret
F00A454C: 81e80000                 restore
