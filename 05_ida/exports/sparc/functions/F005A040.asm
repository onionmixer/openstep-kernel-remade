F005A040: 9de3bf90                 save    %sp, -0x70, %sp
F005A044: 90100018                 mov     %i0, %o0
F005A048: 9210001a                 mov     %i2, %o1
F005A04C: 7fffe6d7                 call    _ipc_entry_alloc_name
F005A050: 9407bff4                 add     %fp, var_C, %o2
F005A054: 80a22000                 cmp     %o0, 0
F005A058: 3280001e                 bne,a   locret_F005A0D0
F005A05C: b0100008                 mov     %o0, %i0
F005A060: 90100018                 mov     %i0, %o0
F005A064: d407bff4                 ld      [%fp+var_C], %o2
F005A068: 40000753                 call    _ipc_right_inuse
F005A06C: 9210001a                 mov     %i2, %o1
F005A070: 80a22000                 cmp     %o0, 0
F005A074: 02800004                 be      loc_F005A084
F005A078: 80a6401a                 cmp     %i1, %i2
F005A07C: 10800015                 ba      locret_F005A0D0
F005A080: b010200d                 mov     0xD, %i0
F005A084: 02800007                 be      loc_F005A0A0
F005A088: 90100018                 mov     %i0, %o0
F005A08C: 7fffe66c                 call    _ipc_entry_lookup
F005A090: 92100019                 mov     %i1, %o1
F005A094: 94920000                 orcc    %o0, %g0, %o2
F005A098: 12800009                 bne     loc_F005A0BC
F005A09C: 90100018                 mov     %i0, %o0
F005A0A0: 90100018                 mov     %i0, %o0
F005A0A4: d407bff4                 ld      [%fp+var_C], %o2
F005A0A8: 7fffe774                 call    _ipc_entry_dealloc
F005A0AC: 9210001a                 mov     %i2, %o1
F005A0B0: c0262008                 clr     [%i0+8]
F005A0B4: 10800007                 ba      locret_F005A0D0
F005A0B8: b010200f                 mov     0xF, %i0
F005A0BC: 92100019                 mov     %i1, %o1
F005A0C0: d807bff4                 ld      [%fp+var_C], %o4
F005A0C4: 40000d72                 call    _ipc_right_rename
F005A0C8: 9610001a                 mov     %i2, %o3
F005A0CC: b0100008                 mov     %o0, %i0
F005A0D0: 81c7e008                 ret
F005A0D4: 81e80000                 restore
