"""Check evidence for the OS42J m68k/SPARC static-analysis material set.

The result deliberately distinguishes material acquisition from semantic or
runtime conclusions.  It never reads external/reference source code.
"""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORTS = ROOT / "09_validation/reports/multiarch-input-20260921"
OUT = REPORTS / "multiarch-static-analysis-material-completion-20260923.json"
REQUIRED = {
    "input_and_tool_configuration": [
        "ida-initial-validation.json", "separation-and-integrity-validation.json"],
    "all_load_listing_and_original_mapping": ["all-load-units-validation.json"],
    "function_assembly_and_decompiler_status": [
        "m68k-ida-function-asm-validation.json", "sparc-ida-function-asm-validation.json",
        "ghidradec-live-callback-corpus-progress-20260922.json"],
    "symbols_xrefs_and_metadata": [
        "xref-source-kind-audit.json", "objc-word-layout-audit.json",
        "objc-nul-section-tsv-validation.json"],
    "outside_function_and_deferred_reinvestigation": [
        "raw-layout-deferred-evidence-closure-20260922.json",
        "m68k-direct-call-outside-function-candidates.json",
        "sparc-direct-call-outside-function-candidates.json"],
    "coverage_and_failure_listing": [
        "multiarch-analysis-prerequisite-closure.json",
        "ghidradec-live-callback-failure-asm-coverage-20260923.json"],
}


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def main():
    checks = {}
    for requirement, names in REQUIRED.items():
        files = []
        for name in names:
            path = REPORTS / name
            files.append({"path": str(path.relative_to(ROOT)), "present": path.is_file(), "sha256_recomputed_with_python": sha256(path) if path.is_file() else None})
        checks[requirement] = {"all_required_evidence_files_present": all(row["present"] for row in files), "files": files}
    progress = json.loads((REPORTS / "ghidradec-live-callback-corpus-progress-20260922.json").read_text())
    coverage = {}
    for arch in ("m68k", "sparc"):
        row = progress["architectures"][arch]
        complete = row["valid_c_hypothesis_count"] + row["error_output_count"] + len(row["single_candidate_fatal_plugin_failures"])
        coverage[arch] = {
            "candidate_count": row["candidate_count"],
            "classified_count_recomputed_with_python": complete,
            "unclassified_count_recomputed_with_python": row["candidate_count"] - complete,
        }
    all_evidence = all(item["all_required_evidence_files_present"] for item in checks.values())
    no_unclassified = all(item["unclassified_count_recomputed_with_python"] == 0 for item in coverage.values())
    result = {
        "schema": 1,
        "scope": "original OS42J m68k/SPARC binary-only static analysis material acquisition; no semantic, ABI, runtime, or reconstruction conclusion",
        "requirements": checks,
        "live_callback_candidate_classification": coverage,
        "all_required_static_material_evidence_present": all_evidence,
        "all_live_callback_candidates_classified": no_unclassified,
        "material_acquisition_complete": all_evidence and no_unclassified,
    }
    OUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n")
    if not result["material_acquisition_complete"]:
        raise SystemExit("static material completion audit failed")
    print(json.dumps({"output": str(OUT.relative_to(ROOT)), "material_acquisition_complete": True}, sort_keys=True))


if __name__ == "__main__":
    main()
