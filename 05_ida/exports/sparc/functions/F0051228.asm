F0051228: 9de3bf90                 save    %sp, -0x70, %sp
F005122C: 90100018                 mov     %i0, %o0
F0051230: 92102000                 mov     0, %o1
F0051234: 94102001                 mov     1, %o2
F0051238: 96102000                 mov     0, %o3
F005123C: 7fff55e2                 call    _lookupname
F0051240: 9807bff4                 add     %fp, var_C, %o4
F0051244: b0920000                 orcc    %o0, %g0, %i0
F0051248: 02800008                 be      loc_F0051268
F005124C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0051250: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0051254: d04a2038                 ldsb    [%o0+0x38], %o0
F0051258: 80a22002                 cmp     %o0, 2
F005125C: 22800019                 be,a    locret_F00512C0
F0051260: b0102013                 mov     0x13, %i0
F0051264: 30800017                 ba,a    locret_F00512C0
F0051268: d207bff4                 ld      [%fp+var_C], %o1
F005126C: d0026028                 ld      [%o1+0x28], %o0
F0051270: 80a22003                 cmp     %o0, 3
F0051274: 22800006                 be,a    loc_F005128C
F0051278: d012602c                 lduh    [%o1+0x2C], %o0
F005127C: 7fff5e3a                 call    _vn_rele
F0051280: 90100009                 mov     %o1, %o0
F0051284: 1080000f                 ba      locret_F00512C0
F0051288: b010200f                 mov     0xF, %i0
F005128C: d0364000                 sth     %o0, [%i1]
F0051290: 7fff5e35                 call    _vn_rele
F0051294: d007bff4                 ld      [%fp+var_C], %o0
F0051298: d0164000                 lduh    [%i1], %o0
F005129C: 133c0472                 sethi   %hi(_nblkdev), %o1
F00512A0: d20261ec                 ld      [%o1+%lo(_nblkdev)], %o1
F00512A4: 91322008                 srl     %o0, 8, %o0
F00512A8: 80a20009                 cmp     %o0, %o1
F00512AC: 36800003                 bge,a   loc_F00512B8
F00512B0: b0102001                 mov     1, %i0
F00512B4: b0102000                 mov     0, %i0
F00512B8: b0200018                 neg     %i0
F00512BC: b00e2006                 and     %i0, 6, %i0
F00512C0: 81c7e008                 ret
F00512C4: 81e80000                 restore
