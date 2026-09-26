# Decompiler issue boundary

The report uses Ghidra-exported labels only to identify original symbol addresses. Dispatch facts
come from raw instructions and raw file-backed dwords. It does not infer function prototypes,
vnode C types, callback names, or a complete runtime assignment set from the labels.

The static vector data establishes candidate table contents, not proof that every live pointer
references one of those vectors.
