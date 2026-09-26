# Decompiler issue boundary

The exports identify `_vm_object_init`, `__vm_object_allocate`, and `_vm_object_collapse`, but
the conclusions here rely on raw decoded instructions. A matching `+0x30` displacement in
`_vm_map_lookup` or `_vm_region` belongs to map-entry paths and is excluded unless the pointer
identity is independently established.

The common-region template has no file-backed initial bytes. Its runtime value is established
here only by the initializer instruction before `__vm_object_allocate` copies it.
