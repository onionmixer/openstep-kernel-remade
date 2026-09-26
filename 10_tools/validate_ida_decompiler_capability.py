"""Validate read-only Hex-Rays capability probes against original OS42J inputs."""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT_DIR = ROOT / "09_validation/reports/multiarch-input-20260921"
TARGETS = {
    "m68k": {
        "binary": ROOT / "03_original/m68k/binaries/mach_kernel",
        "export": ROOT / "05_ida/exports/m68k/decompiler-capability.json",
        "processor": "68K",
    },
    "sparc": {
        "binary": ROOT / "03_original/sparc/binaries/mach_kernel",
        "export": ROOT / "05_ida/exports/sparc/decompiler-capability.json",
        "processor": "sparcb",
    },
}
SCOPE = (
    "availability probe only; no function decompilation, type application, rename, "
    "or database classification change"
)


def main():
    targets = {}
    for architecture, expected in TARGETS.items():
        export = json.loads(expected["export"].read_text(encoding="utf-8"))
        original_hash = hashlib.sha256(expected["binary"].read_bytes()).hexdigest()
        assert export["schema"] == 1
        assert export["architecture"] == architecture
        assert export["input_sha256"] == original_hash
        assert export["ida_processor"] == expected["processor"]
        assert export["ida_big_endian"] is True
        assert export["module_imported"] is True
        assert export["plugin_initialized"] is False
        assert export["version"] is None
        assert export["scope"] == SCOPE
        assert "x86" not in expected["export"].parts
        targets[architecture] = {
            "original_sha256_recomputed_with_python": original_hash,
            "ida_processor": export["ida_processor"],
            "ida_big_endian": export["ida_big_endian"],
            "ida_hexrays_module_imported": export["module_imported"],
            "ida_hexrays_plugin_initialized": export["plugin_initialized"],
            "decompilation_performed": False,
            "database_classification_changed": False,
        }
    report = {
        "schema": 1,
        "scope": "read-only capability probe validation; no decompilation output is evidence",
        "targets": targets,
        "all_checks_passed": True,
    }
    output = REPORT_DIR / "ida-decompiler-capability-validation.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
