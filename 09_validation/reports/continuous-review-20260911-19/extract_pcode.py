"""Reuse the unchanged validated read-only extraction driver with new paths."""
import importlib.util
from scan import HERE, ROOT

spec = importlib.util.spec_from_file_location('read_only_driver', HERE.parent / 'continuous-review-20260911-17/extract_pcode.py')
driver = importlib.util.module_from_spec(spec)
spec.loader.exec_module(driver)
driver.HERE = HERE
driver.ROOT = ROOT
driver.SNAPSHOT = ROOT / '04_ghidra/projects/experiments/segment-state-review-20260911'


if __name__ == '__main__':
    driver.main()
