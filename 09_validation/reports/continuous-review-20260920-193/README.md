# Constructor callers leave pmap table lifetime open

The original-byte validation confirms seven direct calls to the outer
constructor at `0x001353b0`, from six exported functions. The function
labelled `_pmap_kgetport` contributes one of those calls at `0x00135e6c`; the
same outer constructor is also reached from five other functions. The inner
constructor at `0x00134f94` has five direct call sites, and the function
labelled `_pmap_kgetport` has one direct relative caller.

The outer constructor stores `0x001dcdc4` at `[EBX+0x8]`, calls the inner
constructor, then stores its result at `[EBX+0x4]`. The inner constructor
stores `0x001dcd88` at `[EBX+0x20]`. On the outer constructor's shown failure
path, two calls to `0x0015a824` precede a zero return. This narrows the direct
construction evidence, but it cannot prove cleanup semantics, ownership,
runtime overwrites, indirect callers, or alias reachability.

Accordingly, Open Item 1 remains **in progress**. The remaining pmap work is
to trace aliases and indirect entry paths to these constructor-produced
objects, and to determine table mutation and object lifetime from additional
original-byte evidence.
