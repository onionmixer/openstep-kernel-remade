# Decompiler issue boundary

Function names are export labels. The panic-call fall-through does not establish whether the panic
returns at runtime, and this report does not infer allocation lifetime.

