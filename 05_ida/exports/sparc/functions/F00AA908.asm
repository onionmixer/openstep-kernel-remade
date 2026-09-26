F00AA908: 9de3bf98                 save    %sp, -0x68, %sp
F00AA90C: 80a62002                 cmp     %i0, 2
F00AA910: 02800006                 be      loc_F00AA928
F00AA914: 80a62003                 cmp     %i0, 3
F00AA918: 02800005                 be      loc_F00AA92C
F00AA91C: 84102008                 mov     8, %g2
F00AA920: 10800006                 ba      locret_F00AA938
F00AA924: b0102000                 mov     0, %i0
F00AA928: 84102004                 mov     4, %g2
F00AA92C: c426c000                 st      %g2, [%i3]
F00AA930: f2270000                 st      %i1, [%i4]
F00AA934: b0102001                 mov     1, %i0
F00AA938: 81c7e008                 ret
F00AA93C: 81e80000                 restore
