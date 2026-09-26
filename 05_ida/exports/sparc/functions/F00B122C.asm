F00B122C: 9de3bf98                 save    %sp, -0x68, %sp
F00B1230: 373c04fb                 sethi   %hi(_dkn), %i3
F00B1234: f406e220                 ld      [%i3+%lo(_dkn)], %i2
F00B1238: b2100018                 mov     %i0, %i1
F00B123C: 80a6401a                 cmp     %i1, %i2
F00B1240: 36800026                 bge,a   locret_F00B12D8
F00B1244: b0103fff                 mov     -1, %i0
F00B1248: 80a66000                 cmp     %i1, 0
F00B124C: 16800004                 bge     loc_F00B125C
F00B1250: 313c04fb                 sethi   -0xFEC1400, %i0
F00B1254: 10800021                 ba      locret_F00B12D8
F00B1258: b0103fff                 mov     -1, %i0
F00B125C: b01620a0                 bset    0xA0, %i0
F00B1260: 872e6003                 sll     %i1, 3, %g3
F00B1264: 053c04718410a2b0         set     unk_F011C6B0, %g2
F00B126C: c420c018                 st      %g2, [%g3+%i0]
F00B1270: 8600c018                 add     %g3, %i0, %g3
F00B1274: c030e004                 clrh    [%g3+4]
F00B1278: 872e6002                 sll     %i1, 2, %g3
F00B127C: 053c04fb8410a1a0         set     _dk_read, %g2
F00B1284: c020c002                 clr     [%g3+%g2]
F00B1288: 053c04d08410a270         set     _dk_bps, %g2
F00B1290: c020c002                 clr     [%g3+%g2]
F00B1294: 053c04d18410a000         set     _dk_wds, %g2
F00B129C: c020c002                 clr     [%g3+%g2]
F00B12A0: 053c04d18410a080         set     _dk_xfer, %g2
F00B12A8: c020c002                 clr     [%g3+%g2]
F00B12AC: 053c04d08410a300         set     _dk_seek, %g2
F00B12B4: c020c002                 clr     [%g3+%g2]
F00B12B8: 053c04d08410a380         set     _dk_time, %g2
F00B12C0: c020c002                 clr     [%g3+%g2]
F00B12C4: 84066001                 add     %i1, 1, %g2
F00B12C8: 80a0801a                 cmp     %g2, %i2
F00B12CC: 22800002                 be,a    loc_F00B12D4
F00B12D0: f226e220                 st      %i1, [%i3+0x220]
F00B12D4: b0102000                 mov     0, %i0
F00B12D8: 81c7e008                 ret
F00B12DC: 81e80000                 restore
