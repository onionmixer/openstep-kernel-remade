F00B154C: 9de3bf98                 save    %sp, -0x68, %sp
F00B1550: b6100018                 mov     %i0, %i3
F00B1554: 053c044a                 sethi   %hi(_sbus_numslots), %g2
F00B1558: c600a134                 ld      [%g2+%lo(_sbus_numslots)], %g3
F00B155C: b0102000                 mov     0, %i0
F00B1560: 80a60003                 cmp     %i0, %g3
F00B1564: 1a800013                 bcc     loc_F00B15B0
F00B1568: 053c044a                 sethi   %hi(_sbus_basepage), %g2
F00B156C: ba10a138                 or      %g2, %lo(_sbus_basepage), %i5
F00B1570: 053c044ab810a1b8         set     _sbus_slotsize, %i4
F00B1578: b4100003                 mov     %g3, %i2
F00B157C: b2102000                 mov     0, %i1
F00B1580: c606401d                 ld      [%i1+%i5], %g3
F00B1584: c406401c                 ld      [%i1+%i4], %g2
F00B1588: 8728e00c                 sll     %g3, 12, %g3
F00B158C: 8626c003                 sub     %i3, %g3, %g3
F00B1590: 8400bfff                 inc     -1, %g2
F00B1594: 80a0c002                 cmp     %g3, %g2
F00B1598: 08800007                 bleu    locret_F00B15B4
F00B159C: 01000000                 nop
F00B15A0: b0062001                 inc     %i0
F00B15A4: 80a6001a                 cmp     %i0, %i2
F00B15A8: 0abffff6                 bcs     loc_F00B1580
F00B15AC: b2066004                 inc     4, %i1
F00B15B0: b0103fff                 mov     -1, %i0
F00B15B4: 81c7e008                 ret
F00B15B8: 81e80000                 restore
