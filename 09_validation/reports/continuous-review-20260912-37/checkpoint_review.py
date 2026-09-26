"""Preservation and hashes for unfinished native-IDT/RF diagnostic evidence."""
import hashlib
import importlib.util
import json
from pathlib import Path
import reproduce_native as R

HERE=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('verify36',R.PRIOR/'verify_artifacts.py')
V=importlib.util.module_from_spec(spec)
spec.loader.exec_module(V)


def main():
    prior=R.preservation()
    preservation=V.preserved()
    repro=json.loads((HERE/'reproducibility.json').read_text())
    assert repro['equal'] and repro['strict_RF_command_still_fails'] and not repro['RF_contract_passed']
    for name,expected in repro['after'].items():
        assert hashlib.sha256((HERE/name).read_bytes()).hexdigest()==expected,name
    entries=[]
    for path in sorted(HERE.rglob('*')):
        if path.is_file() and path.name!='checkpoint.json' and '__pycache__' not in path.parts:
            entries.append({'path':str(path.relative_to(HERE)),'size':path.stat().st_size,
                            'sha256':hashlib.sha256(path.read_bytes()).hexdigest()})
    result={'files':entries,'prior_checkpoint_sha256':prior,'preservation':preservation,
            'RF_contract_passed':False,'original_GC_fault_reentry_verified':False,
            'report_finalized':False,'whole_goal_complete':False}
    (HERE/'checkpoint.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'checkpoint_files':len(entries),'RF_contract_passed':False}))


if __name__ == '__main__':
    main()
