"""Independent JVM experiment; all selection, arithmetic and hashing is Python."""
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
SNAPSHOT = ROOT / '04_ghidra/projects/experiments/protected-data-review-20260911'
spec = importlib.util.spec_from_file_location('original', HERE.parent / 'cautious-followup-20260911/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
STAGES = ('baseline', 'lock_only', 'data_only', 'combined', 'reopened_baseline')


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    assert not SNAPSHOT.exists(), 'Refusing to overwrite snapshot'
    locks = {0x1e9858, 0x1f64cc, 0x1e5534, 0x1e5540}
    word = struct.calcsize('<I')
    related = {op.mem.disp for i in R.function_instructions(R.NAMES['_mfs_cache_trim']).values()
               for op in i.operands if op.type == R.X86_OP_MEM and not op.mem.base and not op.mem.index} - locks
    targets = locks | related
    refs = []
    heads = set()
    for entry in sorted(R.FMAP):
        for ins in R.function_instructions(entry).values():
            heads.add(ins.address)
            hits = set()
            for op in ins.operands:
                if op.type == R.X86_OP_MEM and not op.mem.base and not op.mem.index:
                    hits |= {a for a in targets if a <= op.mem.disp < a + word}
                if op.type == R.X86_OP_IMM:
                    hits |= {a for a in targets if a <= op.imm < a + word}
            for lock in sorted(hits):
                refs.append({'owner': f'{entry:08x}', 'site': f'{ins.address:08x}', 'target': f'{lock:08x}',
                             'bytes': ins.bytes.hex(), 'instruction': f'{ins.mnemonic} {ins.op_str}'})
    selected = {int(r['owner'], 16) for r in refs}
    selected |= {int(a, 16) for a in json.loads((HERE.parent / 'continuous-review-20260911-11/job.json').read_text())['selected']}
    selected |= {R.NAMES['_strcpy'], R.NAMES['_objc_msgSend']}
    job = {'binary_sha256': hashlib.sha256(R.RAW).hexdigest(), 'word_size': word,
           'locks': [f'{a:08x}' for a in sorted(locks)], 'selected': [f'{a:08x}' for a in sorted(selected)],
           'related_data': [f'{a:08x}' for a in sorted(related)], 'edge_indices': list(range(256)),
           'direct_operand_sites': refs, 'instruction_heads_scanned': len(heads),
           'selection_limit': 'Absolute operand/immediate references plus explicit prior samples and controls; dynamic aliases not exhaustively followed.'}
    (HERE / 'job.json').write_text(json.dumps(job, indent=2) + '\n')
    source = ROOT / '04_ghidra/projects'
    before = json.loads((HERE.parent / 'continuous-review-20260911-12/source-project-before.json').read_text())
    assert all(digest(source / r['path']) == r['sha256'] for r in before)
    for row in json.loads((HERE.parent / 'continuous-review-20260911-12/artifact-hashes.json').read_text()):
        assert digest(ROOT / row['path']) == row['sha256']
    SNAPSHOT.mkdir(parents=True)
    shutil.copy2(source / 'x86-full.gpr', SNAPSHOT / 'x86-full.gpr')
    shutil.copytree(source / 'x86-full.rep', SNAPSHOT / 'x86-full.rep')
    assert all(digest(SNAPSHOT / r['path']) == r['sha256'] for r in before)
    (HERE / 'source-project-before.json').write_text(json.dumps(before, indent=2) + '\n')
    previous = HERE.parent / 'continuous-review-20260911-10'
    old_snapshot = ROOT / '04_ghidra/projects/experiments/api-contract-review-20260911'
    cmd = [a.replace(str(previous), str(HERE)).replace(str(old_snapshot), str(SNAPSHOT))
           .replace('ApiContractExperiment.java', 'ProtectedDataExperiment.java')
           for a in json.loads((previous / 'baseline-command.json').read_text())]
    (HERE / 'exports').mkdir()
    runs = []
    print(json.dumps({'selected_functions': len(selected), 'direct_referencing_owners': len({r['owner'] for r in refs}),
                      'operand_references': len(refs), 'related_data': len(related),
                      'references_by_target': dict(collections.Counter(r['target'] for r in refs))}), flush=True)
    for stage in STAGES:
        phase = [a.replace('/baseline-', f'/{stage}-').replace('/runtime-isolated/baseline/', f'/runtime-isolated/{stage}/')
                 if a != 'baseline' else stage for a in cmd]
        (HERE / f'{stage}-command.json').write_text(json.dumps(phase, indent=2) + '\n')
        with (HERE / f'{stage}-console.log').open('w') as stream:
            proc = subprocess.run(phase, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT)
        changed = {label: [r['path'] for r in before if digest(base / r['path']) != r['sha256']]
                   for label, base in [('original', source), ('snapshot', SNAPSHOT)]}
        runs.append({'stage': stage, 'returncode': proc.returncode, 'changed': changed})
        (HERE / 'run-result.json').write_text(json.dumps({'runs': runs, 'files_per_copy': len(before)}, indent=2) + '\n')
        print(json.dumps(runs[-1]), flush=True)
        assert proc.returncode == 0 and not any(changed.values()), runs[-1]
        assert json.loads((HERE / 'exports' / f'{stage}-execution-marker.json').read_text()) == {
            'class': 'ProtectedDataExperiment', 'version': 'protected-data-v1', 'stage': stage}
        assert (HERE / 'exports' / stage / 'functions.json').exists()


if __name__ == '__main__':
    main()
