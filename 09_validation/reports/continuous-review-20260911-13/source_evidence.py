"""Pin the original raw P-code and local instruction-language evidence."""
import hashlib
import json
from pathlib import Path
from run_experiment import HERE, ROOT, R
from audit_experiment import node


def main():
    language = Path('/home/onion/ghidra_12.1_PUBLIC/Ghidra/Processors/x86/data/languages')
    cpp = Path('/home/onion/ghidra_12.1_PUBLIC/Ghidra/Features/Decompiler/src/decompile/cpp')
    raw_path = HERE.parent / 'continuous-review-20260911-11/exports/pcode.json'
    function = next(f for f in json.loads(raw_path.read_text()) if f['entry'] == '0015ec00')
    raw = [r for r in function['raw_instructions'] if r['address'] in ('0015ec81', '0015ec87')]
    samples = []
    for row in raw:
        instruction = R.function_instructions(R.NAMES['_mfs_cache_trim'])[int(row['address'], 16)]
        target = instruction.operands[0].mem.disp
        uses = [o['opcode'] for o in row['operations'] for text in o['inputs'] if node(text)[:2] == ('ram', target)]
        assert len(uses) == 5
        samples.append({'address': row['address'], 'instruction_bytes': instruction.bytes.hex(),
                        'direct_ram_input_uses': uses, 'raw_pcode': row})
    old_source = ROOT / '01_resources/upstream/nextmach/mk-108.1/kern/mfs_prim.c'
    selections = [(language / 'lockable.sinc', ':DEC^lockx m32', 10),
                  (language / 'lockable.sinc', ':INC^lockx m32', 10),
                  (language / 'ia.sinc', 'macro resultflags(result)', 6),
                  (cpp / 'funcdata_varnode.cc', 'bool Funcdata::replaceVolatile', 54),
                  (old_source, 'queue_head_t', 8),
                  (old_source, 'mfs_cache_trim()', 27)]
    excerpts = []
    for path, needle, length in selections:
        lines = path.read_text().splitlines()
        starts = [i for i, line in enumerate(lines) if line.startswith(needle)]
        assert len(starts) == 1, (path, starts)
        start = starts[0]
        excerpts.append({'path': str(path), 'start_line': start + 1, 'excerpt': '\n'.join(lines[start:start+length])})
    (HERE / 'source-evidence.json').write_text(json.dumps({'raw_pcode_samples': samples, 'excerpts': excerpts,
                                                        'interpretation': 'Multiple RAM varnode uses for arithmetic/flags are materialized as separate volatile reads; not a claim of multiple physical bus reads by original x86.'}, indent=2) + '\n')
    paths = {p for p, _, _ in selections} | {raw_path, ROOT / '03_original/x86/binaries/mach_kernel',
             HERE.parent / 'cautious-followup-20260911/review.py',
             HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py'}
    (HERE / 'input-hashes.json').write_text(json.dumps([{'path': str(p.relative_to(ROOT)) if p.is_relative_to(ROOT) else str(p),
                                                       'size': p.stat().st_size, 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in sorted(paths)], indent=2) + '\n')
    print(json.dumps({'raw_samples': len(samples), 'source_excerpts': len(excerpts), 'inputs': len(paths)}))


if __name__ == '__main__':
    main()
