#!/usr/bin/env python3
"""Run the validated 2026-09-22 30-round audit in a new isolated output directory."""
import importlib.util
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "10_tools/audit_multiarch_rounds_20260922.py"
OUT = ROOT / "09_validation/reports/multiarch-continuous-20260922-continuation2"


def main():
    assert not OUT.exists()
    spec = importlib.util.spec_from_file_location("round_audit_20260922", SOURCE)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    module.OUT = OUT
    module.main()


if __name__ == "__main__":
    main()
