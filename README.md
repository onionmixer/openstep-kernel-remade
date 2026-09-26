# OPENSTEP Kernel Analysis

This project aims to remake the OPENSTEP kernel. This workspace preserves and analyzes original OPENSTEP 4.2 kernel binaries as the evidence base for that future reconstruction. The current analysis-only phase uses original binary bytes and derived analysis outputs; it does not use external source code as evidence and does not yet implement, build, boot, or port a reconstructed kernel.

## Current status

Static evidence collection is complete for the Intel x86, Motorola m68k, and SPARC kernels. The m68k and SPARC inputs are handled independently as big-endian binaries; x86 is little-endian. The collected material includes provenance, Mach-O layout, original-byte-validated assembly, function candidates, symbols, cross-references, direct-call records, and separately stored decompiler hypotheses. Analysis is still in progress: the remaining work is to establish the evidence needed for reliable semantic conclusions before reconstruction begins.

The three architectures can be compared for input provenance, byte order, and static structural observations. They cannot establish equivalent function behavior, calling conventions, argument or return values, object layouts, or function boundaries. Those semantic conclusions remain unconfirmed in the binary-only scope.

See [the full analysis plan](02_plan/FULL_ANALYSIS.md), [the multi-architecture plan](02_plan/MULTIARCH_STATIC_ANALYSIS.md), and [the static-evidence closure audit](09_validation/reports/multiarch-input-20260921/static-only-semantic-followup-closure-20260923.json).

## Tools

- **IDA Pro:** Creates architecture-specific databases, disassembly listings, function candidates, and cross-reference exports. Its output is checked against the original file-backed bytes.
- **Ghidra and GhidraDec:** Produce separately stored decompiler hypotheses and support independent headless checks. A decompiler result is not treated as original-binary proof.
- **Python:** Runs all explicit calculations and produces repeatable Mach-O, byte, hash, coverage, and audit reports.
- **Git:** Tracks plans, scripts, reports, and reviewable text while excluding original binaries, analysis databases, and local temporary files.

## Layout

```text
02_plan/        Analysis scope and plans
03_original/    Original kernels, provenance, and static inventories
04_ghidra/      Ghidra projects and exported hypotheses
05_ida/         IDA databases, snapshots, and exports
09_validation/  Evidence audits and validation reports
10_tools/       Repeatable analysis and audit tools
```

## What is not in this repository

**Original kernel binaries.** The OPENSTEP 4.2 kernels under `03_original/` are Apple/NeXT copyrighted files and are not redistributed here. `.gitignore` excludes every `03_original/**/binaries/` directory, so the tree ships only the provenance records and the inventories derived from the bytes. To re-populate the analysis inputs, place the following files at the paths shown and check their SHA-256 against `03_original/manifest.json` and `03_original/installation-media/os42j/provenance.json`:

| Path | Size (bytes) | SHA-256 | Origin |
|---|---|---|---|
| `03_original/x86/binaries/mach_kernel` | 1,117,920 | `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890` | `/mach_kernel` of an OPENSTEP 4.2 Intel installation |
| `03_original/installation-media/os42j/binaries/mach_kernel.universal` | 3,391,352 | `f3b57f877218adf9e0814f69c5494aca74e7c7b4e9dbd395156cce78d62de148` | `/mach_kernel` on the UFS volume of the OPENSTEP 4.2J install CD (UFS starts at LBA 80, 2048-byte sectors); a three-slice fat container |
| `03_original/m68k/binaries/mach_kernel` | 832,196 | `dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75` | fat slice 0 of the container above, offset 68 |
| `03_original/sparc/binaries/mach_kernel` | 1,441,656 | `287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1` | fat slice 2 of the container above, offset 1,949,696 |

The m68k and SPARC files are byte ranges cut from the fat container at the offsets and sizes recorded in `provenance.json`; no tool beyond a byte copy is needed. Every report in `09_validation/` names the input hashes it was produced from, so a restored input can be checked against the recorded evidence.

**IDA databases, Ghidra projects and the IDA SDK.** `05_ida/databases/`, `05_ida/snapshots/` and `04_ghidra/projects/` are excluded because they are derived from the excluded binaries and are large. `10_tools/vendor-cache/` keeps the pinned GhidraDec bundle and the built headless plugins, but not the Hex-Rays IDA SDK bundle, which is not redistributable; its pinned commit and hash are listed in `10_tools/vendor-cache/README.md`.

**Case dumps stored as `.json.gz`.** Six `continuous-review-*` case dumps under `09_validation/reports/` exceed GitHub's 100 MiB per-file limit, so each is committed as a gzip'd sibling (about 27:1). Restore the plain file next to it with `gunzip -k <name>.json.gz`; the other files in the same report directory refer to the plain name.

| Compressed file | Plain size (bytes) |
|---|---|
| `09_validation/reports/continuous-review-20260911-32/fault-new-pt-cases.json.gz` | 274,100,803 |
| `09_validation/reports/continuous-review-20260911-33/dirty-remove-cases.json.gz` | 215,275,283 |
| `09_validation/reports/continuous-review-20260912-34/gc-cases.json.gz` | 304,406,637 |
| `09_validation/reports/continuous-review-20260912-36/direct-cases.json.gz` | 272,393,411 |
| `09_validation/reports/continuous-review-20260912-40/removal-cases.json.gz` | 205,408,759 |
| `09_validation/reports/continuous-review-20260912-41/pd-cases.json.gz` | 142,721,963 |
