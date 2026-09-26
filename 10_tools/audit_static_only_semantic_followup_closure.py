"""Close all remaining no-hardware semantic-evidence tasks conservatively."""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / "09_validation/reports/multiarch-input-20260921"
OUTPUT = REPORT / "static-only-semantic-followup-closure-20260923.json"


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf-8"))


def x86_c_header_binding():
    functions = load(ROOT / "04_ghidra/exports/x86/full-pass5/functions.json")
    raw_hash = sha256((ROOT / "03_original/x86/binaries/mach_kernel").read_bytes())
    checks = []
    for row in functions:
        address = int(row["address"], 16)
        base = ROOT / "04_ghidra/exports/x86/full-pass5/functions/{:08x}".format(address)
        c_path, asm_path = base.with_suffix(".c"), base.with_suffix(".asm")
        header = c_path.read_text(encoding="utf-8", errors="replace")[:400]
        checks.append(c_path.is_file() and asm_path.is_file() and raw_hash in header and row["address"] in header)
    return {
        "function_or_fragment_count_recomputed_with_python": len(functions),
        "all_c_and_asm_files_exist_and_c_headers_bind_original_hash_and_entry": all(checks),
    }


def main():
    contract = load(REPORT / "binary-only-contract-evidence-completion-audit-20260923.json")
    windows = load(REPORT / "binary-only-direct-call-argument-return-window-completion-audit-20260923.json")
    x86_indirect = load(REPORT / "x86-nonrel-call-jmp-census-audit-20260923.json")
    m68_jsr = load(REPORT / "m68k-jsr-opcode-pattern-census-audit.json")
    m68_jmp = load(REPORT / "m68k-jmp-opcode-pattern-census-audit.json")
    sparc_transfer = load(REPORT / "sparc-op2-op3-38-census-audit.json")
    progress = load(REPORT / "ghidradec-live-callback-corpus-progress-20260922.json")
    manual = load(REPORT / "ghidradec-failure-manual-analysis-completion-20260923.json")
    x86_binding = x86_c_header_binding()
    per_arch_progress = {}
    for arch in ("m68k", "sparc"):
        data = progress["architectures"][arch]
        fatal_count = len(data["single_candidate_fatal_plugin_failures"])
        per_arch_progress[arch] = {
            "candidate_count_recomputed_with_python": data["candidate_count"],
            "persisted_record_count": data["persisted_candidate_record_count"],
            "fatal_plugin_failure_count_recomputed_with_python": fatal_count,
            "candidate_partition_complete": data["candidate_count"] == data["persisted_candidate_record_count"] + fatal_count,
            "persisted_c_provenance_check_passes": data["all_persisted_records_have_unique_candidate_starts_matching_c_hashes_and_live_slice_provenance"],
        }
    checks = {
        "contract_ledger_raw_evidence_acquisition_complete": contract["raw_evidence_acquisition_complete"],
        "contract_ledger_all_architecture_checks_pass": all(all(row["checks"].values()) for row in contract["architectures"].values()),
        "direct_call_pre_post_window_coverage_complete": windows["all_direct_call_window_coverage_and_integrity_checks_pass"],
        "x86_nonrel_call_jmp_current_instruction_bytes_match_original": x86_indirect["all_current_instruction_bytes_match_original"],
        "m68k_jsr_opcode_items_and_direct_targets_match_original": m68_jsr["all_opcode_items_match_original_bytes_and_absolute_targets_match_direct_call_corpus"],
        "m68k_jmp_opcode_items_and_direct_targets_match_original": m68_jmp["all_opcode_items_match_original_bytes_and_absolute_targets_match_type19_xrefs"],
        "sparc_register_target_pattern_items_match_original": sparc_transfer["all_opcode_items_match_original_big_endian_bytes"],
        "x86_c_hypothesis_header_binding_complete": x86_binding["all_c_and_asm_files_exist_and_c_headers_bind_original_hash_and_entry"],
        "m68k_live_c_or_tool_failure_partition_complete": per_arch_progress["m68k"]["candidate_partition_complete"],
        "m68k_live_c_provenance_check_passes": per_arch_progress["m68k"]["persisted_c_provenance_check_passes"],
        "sparc_live_c_or_tool_failure_partition_complete": per_arch_progress["sparc"]["candidate_partition_complete"],
        "sparc_live_c_provenance_check_passes": per_arch_progress["sparc"]["persisted_c_provenance_check_passes"],
        "prior_ghidradec_failure_manual_records_complete": manual["all_manual_analysis_records_complete"],
    }
    complete = all(checks.values())
    result = {
        "schema": 1,
        "scope": "closure of remaining no-hardware static evidence tasks for call/return candidates, transfer targets, raw ObjC layout, and decompiler-hypothesis provenance",
        "checks": checks,
        "x86_c_hypothesis_binding": x86_binding,
        "m68k_and_sparc_live_c_or_tool_failure_partition": per_arch_progress,
        "static_only_evidence_tasks_complete": complete,
        "semantic_disposition": {
            "runtime_argument_positions_or_values_confirmed": False,
            "runtime_return_positions_or_values_confirmed": False,
            "indirect_or_tail_runtime_targets_confirmed": False,
            "structure_or_object_field_layout_confirmed": False,
            "reason": (
                "The completed static checks establish original byte provenance, current listing observations, and "
                "decompiler-output binding only. They do not establish runtime path selection, register/memory values, "
                "operand roles, type identity, ABI/runtime schema, or execution."
            ),
        },
        "interpretation_limit": (
            "Completion means that every task available within the approved no-hardware binary-only evidence scope has "
            "been audited. False semantic dispositions are retained results, not failed static checks."
        ),
    }
    OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if not complete:
        raise SystemExit("static-only semantic followup closure failed")
    print(json.dumps({
        "output": str(OUTPUT.relative_to(ROOT)),
        "static_only_evidence_tasks_complete": complete,
        "semantic_disposition": result["semantic_disposition"],
    }, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
