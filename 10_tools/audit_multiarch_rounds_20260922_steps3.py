#!/usr/bin/env python3
"""Run the validated 30-step OS42J audit in an isolated steps3 report directory."""
import importlib.util
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "10_tools/audit_multiarch_rounds_20260922.py"
OUT = ROOT / "09_validation/reports/multiarch-continuous-20260922-steps3"


def main():
    assert not OUT.exists()
    spec = importlib.util.spec_from_file_location("round_audit_20260922_steps3", SOURCE)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    module.OUT = OUT
    module.main()


if __name__ == "__main__":
    main()
