F00B9654: 9de3bf98                 save    %sp, -0x68, %sp
F00B9658: 353c04fc                 sethi   %hi(_zsaline), %i2
F00B965C: c4562014                 ldsh    [%i0+0x14], %g2
F00B9660: b416a160                 bset    %lo(_zsaline), %i2
F00B9664: b328a003                 sll     %g2, 3, %i1
F00B9668: b2064002                 add     %i1, %g2, %i1
F00B966C: b32e6003                 sll     %i1, 3, %i1
F00B9670: b2264002                 sub     %i1, %g2, %i1
F00B9674: b32e6002                 sll     %i1, 2, %i1
F00B9678: 8728a004                 sll     %g2, 4, %g3
F00B967C: 8600c002                 add     %g3, %g2, %g3
F00B9680: 8728e003                 sll     %g3, 3, %g3
F00B9684: 053c04fb8410a260         set     _zs_tty, %g2
F00B968C: 8600c002                 add     %g3, %g2, %g3
F00B9690: c626401a                 st      %g3, [%i1+%i2]
F00B9694: f020e034                 st      %i0, [%g3+0x34]
F00B9698: c4162014                 lduh    [%i0+0x14], %g2
F00B969C: c430e038                 sth     %g2, [%g3+0x38]
F00B96A0: 81c7e008                 ret
F00B96A4: 81e80000                 restore
