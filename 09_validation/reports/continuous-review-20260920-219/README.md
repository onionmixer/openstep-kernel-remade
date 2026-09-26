# IRQ registration and mask update: static protocol

This report examines original x86 bytes for the IRQ register, unregister,
enable, and disable bodies. Registration accepts the code's shown IRQ range
except value two, checks a priority-like input up to seven, and derives a
12-byte slot. It writes three dwords to that slot; unregister clears the same
three offsets.

Each selected path saves the incoming interrupt-flag bit after `CLI` and later
chooses `STI` or `CLI` from that saved bit. The mask-update paths conditionally
write two I/O ports and execute two lock-prefixed increments when the effective
mask comparison differs. These are static instruction facts only; they do not
prove hardware delivery, handler execution, progress, reentrancy, or runtime
locking behavior.

