# Map-record copies and deletion modify the pointer target’s `+0x30`

The earlier object-prefix inventory was deliberately narrow. Original
map-record code supplies a separate, explicit pointer provenance for nonzero
`+0x30` changes.

In `0x00176164`, each of two split paths allocates a record, sets the
destination register to it, and executes `ECX=0xb; REP MOVSD` from the old
record.  After the copy, the code tests the old record byte at `+0x18` with
mask `0x05`. On the nonzero branch it loads `[new_record+0x10]` into EDX,
enters the shown `EDX+0x34` exchange loop, increments `[EDX+0x30]`, then
clears that `+0x34` dword by exchange. Thus the increment target is the pointer
copied from the old record’s `+0x10`, rather than the map record itself.

Both the standalone entry-delete body at `0x00176084` and the deletion path in
`0x00176164` take the same converse shape: after the same `+0x18` mask,
they load `[entry+0x10]`, acquire the shown `pointer+0x34` exchange exclusion,
read `pointer+0x30`, store `old_value-1`, release `+0x34`, and test the old
value. A positive old value branches away; the non-positive branch calls the
map-delete entry in the shown `0x00176164` path before later cleanup. This
establishes a static increment/decrement transition pair for this
record-derived pointer field.

The instructions do not establish the pointer’s C type, actual lock semantics,
whether a branch executes, arithmetic overflow/underflow reachability,
concurrent aliases, callback behaviour, or final runtime object lifetime.
Open Item 1 remains **in progress**.
