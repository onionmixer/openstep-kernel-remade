# Callback reset has no local range gate; reader entry remains indirect

The setter at `0x001a9c6c` compares its index with the 43-cell bound before writing its `+0x20` reader field. The reset at `0x001a9dec` computes the same 44-byte cell address and copies eleven dwords without a local bound comparison. Its sole direct caller checks only whether a lookup result equals `-1`, then passes that result to reset. The lookup result's range is not established.

The callback reader labelled `_smmap` has no direct relative `CALL` caller in all 5,253 exported bodies. Its actual entry cannot be closed by direct-call inventory. It reads its index byte from `[EAX+0x43]`; the same scan found zero explicit destination operands of form `[register+0x43]`. This does not exclude aliases, arithmetic addresses, bulk writes, or non-exported code.

Resolve the lookup bound, non-direct reader entries, and index-byte provenance before asserting callback table bounds, runtime mutation, or lifetime. Open Item 1 remains **in progress**.
