F00F3920: 053c04bc9810a150         set     unk_F012F150, %o4
F00F3928: 10800018                 ba      loc_F00F3988
F00F392C: 96102000                 mov     0, %o3
F00F3930: c4032014                 ld      [%o4+0x14], %g2
F00F3934: 9400c002                 add     %g3, %g2, %o2
F00F3938: c400c002                 ld      [%g3+%g2], %g2
F00F393C: 80a0a000                 cmp     %g2, 0
F00F3940: 22800012                 be,a    loc_F00F3988
F00F3944: 9602e001                 inc     %o3
F00F3948: c4028000                 ld      [%o2], %g2
F00F394C: c600a004                 ld      [%g2+4], %g3
F00F3950: 80a0c008                 cmp     %g3, %o0
F00F3954: 0a800007                 bcs     loc_F00F3970
F00F3958: 80a0c009                 cmp     %g3, %o1
F00F395C: 3a800006                 bcc,a   loc_F00F3974
F00F3960: 94100002                 mov     %g2, %o2
F00F3964: c4008000                 ld      [%g2], %g2
F00F3968: 10800003                 ba      loc_F00F3974
F00F396C: c4228000                 st      %g2, [%o2]
F00F3970: 94100002                 mov     %g2, %o2
F00F3974: c4028000                 ld      [%o2], %g2
F00F3978: 80a0a000                 cmp     %g2, 0
F00F397C: 32bffff5                 bne,a   loc_F00F3950
F00F3980: c600a004                 ld      [%g2+4], %g3
F00F3984: 9602e001                 inc     %o3
F00F3988: c4032004                 ld      [%o4+4], %g2
F00F398C: 80a2c002                 cmp     %o3, %g2
F00F3990: 0abfffe8                 bcs     loc_F00F3930
F00F3994: 872ae002                 sll     %o3, 2, %g3
F00F3998: 81c3e008                 retl
F00F399C: 01000000                 nop
