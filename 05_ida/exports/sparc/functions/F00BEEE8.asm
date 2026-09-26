F00BEEE8: 9de3bf98                 save    %sp, -0x68, %sp
F00BEEEC: c606201c                 ld      [%i0+0x1C], %g3
F00BEEF0: c400e014                 ld      [%g3+0x14], %g2
F00BEEF4: c4366002                 sth     %g2, [%i1+2]
F00BEEF8: c400e01c                 ld      [%g3+0x1C], %g2
F00BEEFC: c4364000                 sth     %g2, [%i1]
F00BEF00: c400c000                 ld      [%g3], %g2
F00BEF04: c4366004                 sth     %g2, [%i1+4]
F00BEF08: c400e004                 ld      [%g3+4], %g2
F00BEF0C: c4366006                 sth     %g2, [%i1+6]
F00BEF10: 81c7e008                 ret
F00BEF14: 81e80000                 restore
