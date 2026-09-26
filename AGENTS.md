# Kernel reconstruction requirements

- User requirement: use Python for all explicit calculations (including address/offset conversion, sizes, counts, differences, percentages and coverage aggregation). Do not perform these mentally or with shell/JavaScript arithmetic. Preserve analysis-tool outputs as evidence and use Python to calculate derived results.

- Current user-directed scope (2026-09-13 clarification): analyze the original OPENSTEP kernel only. Do not consult Mach4, NeXTMach, Darwin, or other external/reference code, including copies in `01_resources`. Use original kernel bytes and analysis outputs derived from that binary; treat decompiler interpretations as hypotheses until checked against the original. Follow `02_plan/FULL_ANALYSIS.md`.
- Do not implement, reconstruct source, build, or port the kernel in this analysis-only phase. Earlier reference-source comparisons are historical records, not confirmation of original behavior; do not silently carry their conclusions into new binary-only findings.

- Historical future reconstruction requirement, not authorization to implement in the current phase: the final reconstructed kernel must compile with GCC 2.7, including later architecture targets.
- Follow `08_build/GCC27_COMPATIBILITY.md` for source, generated code, ABI and acceptance criteria.
- Use C89-style source as the baseline. GNU/NeXT extensions require evidence from the selected GCC 2.7 toolchain.
- Do not mark compiler compatibility verified using only a modern compiler or a language-standard flag.
- Preserve reference inputs in `01_resources` and original binaries in `03_original`; edit reconstructed code in `07_kernel`.
- Keep original binary facts, decompiler interpretations, reconstructed implementations and validation results separate.
