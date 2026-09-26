# Scope

Only original OPENSTEP x86 kernel bytes and binary-derived full-pass5 function metadata were used. Python parsed Mach-O `__text`, calculated each `CALL rel32` target, and Capstone x86-32 decoded only the recorded original function bodies. No reference source, runtime execution, reconstructed code, or Ghidra mutation was used.
