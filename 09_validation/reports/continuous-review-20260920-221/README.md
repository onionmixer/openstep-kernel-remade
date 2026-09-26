# IRQ registration slot and dispatch closure

This report connects the selected registration and dispatch instructions using
only original bytes. Both compute slots at `0x001e7624 + 12 * index`.
Registration writes offsets `+0`, `+4`, and `+8`; dispatch reads `+8`, gates
on `+4`, pushes `+0`, loads `+4`, and indirectly calls that loaded value on
the shown conditional branch.

The dispatcher issues `STI` before that indirect call and `CLI` immediately
after it, restoring a saved global value. This is a local instruction sequence,
not proof that a device interrupt arrives, a callback executes successfully,
or nested interrupts make progress.

