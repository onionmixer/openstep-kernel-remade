# Shown map-entry delete path clears `WORD +0x28` before `zfree`

In the function labelled `_vm_map_entry_delete`, `CMP WORD [ESI+0x28],0` selects two paths. A nonzero value calls `0x001735f4` and then stores zero to `WORD [ESI+0x28]`; a zero value bypasses that store. The paths join before the final `PUSH ESI; PUSH EAX; CALL 0x0016b84c` sequence, where the export identifies `0x0016b84c` as `zfree`.

Consequently, on this shown direct path, the `+0x28` word is zero at the static program point immediately before the `zfree` call: it was already zero or was explicitly cleared. Python found no direct relative `CALL` site to this entry in all exported bodies. The enclosing map delete function has fourteen direct sites in nine functions, but its internal entry-delete action cannot be closed from the absent direct call edge.

This narrows the free-list stale-value question for one deletion path. It does not prove every free path clears the field, or rule out aliases, bulk copies, indirect entry, concurrent mutation, or allocator reuse. Open Item 1 remains **in progress**.
