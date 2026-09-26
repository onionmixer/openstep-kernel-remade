"""Independent original CALL scan and pinned local source evidence."""
import collections
import hashlib
import json
from run_experiment import HERE, ROOT, R


def main():
    job = json.loads((HERE / 'job.json').read_text())
    targets = {int(p['entry'], 16) for p in job['prototypes']}
    calls = []
    heads = set()
    for entry in sorted(R.FMAP):
        for ins in R.function_instructions(entry).values():
            heads.add(ins.address)
            if ins.mnemonic == 'call' and ins.operands[0].type == R.X86_OP_IMM and ins.operands[0].imm in targets:
                calls.append({'owner': f'{entry:08x}', 'site': f'{ins.address:08x}',
                              'target': f'{ins.operands[0].imm:08x}', 'bytes': ins.bytes.hex()})
    project = lambda rows: sorted((c['owner'], c['site'], c['target'], c['bytes']) for c in rows)
    assert project(calls) == project(job['direct_calls'])
    sources = []
    prefix = '01_resources/upstream/nextmach/mk-108.1/kern/'
    selections = [('task.c', 'kern_return_t task_create(parent_task, inherit_memory, child_task)', 36),
                  ('thread.c', 'thread_policy(thread, policy, data)', 16),
                  ('mig_support.c', 'void mig_dealloc_reply_port()', 5),
                  ('mach_server.c', 'task_create(target_task, In0P->inherit_memory, &child_task)', 4),
                  ('mach_host_server.c', 'thread_policy(thread, In0P->policy, In0P->data)', 4)]
    inputs = {ROOT / '03_original/x86/binaries/mach_kernel',
              HERE.parent / 'cautious-followup-20260911/review.py',
              HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py'}
    for name, needle, count in selections:
        path = ROOT / (prefix + name)
        lines = path.read_text().splitlines()
        indices = [i for i, line in enumerate(lines) if needle in line]
        assert len(indices) == 1, (path, indices)
        start = indices[0]
        sources.append({'path': str(path.relative_to(ROOT)), 'start_line': start + 1,
                        'end_line': min(start + count, len(lines)),
                        'excerpt': '\n'.join(lines[start:start+count]),
                        'interpretation': 'Older related source corroborates argument roles, not identical implementation.'})
        inputs.add(path)
    for p in job['prototypes']:
        inputs.add(ROOT / '05_ida/exports/x86/functions' / (p['entry'] + '.c'))
    input_rows = [{'path': str(p.relative_to(ROOT)), 'size': p.stat().st_size,
                   'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in sorted(inputs)]
    (HERE / 'input-hashes.json').write_text(json.dumps(input_rows, indent=2) + '\n')
    raw_context = []
    for c in calls:
        instructions = list(R.function_instructions(int(c['owner'], 16)).values())
        index = next(i for i, ins in enumerate(instructions) if ins.address == int(c['site'], 16))
        raw_context.append(dict(c, preceding_listing_context=[{'address': f'{i.address:08x}', 'bytes': i.bytes.hex(),
                                                               'instruction': f'{i.mnemonic} {i.op_str}'}
                                                              for i in instructions[max(0, index-10):index+2]],
                                caveat='Linear context excerpt, not an all-path argument dataflow proof.'))
    result = {'summary': {'function_units_scanned': len(R.FMAP), 'unique_instruction_heads_decoded': len(heads),
                          'matching_direct_calls': len(calls), 'stored_reference_call_set_exact': True,
                          'calls_by_target': dict(collections.Counter(c['target'] for c in calls))},
              'call_context': raw_context, 'source_excerpts': sources,
              'limits': ['Scan covers current exported instruction heads, not proof against undiscovered code or indirect calls.',
                         'Both decompilers carry matching wrong prototypes; agreement is not independent ABI proof.',
                         'Raw task_create compares third argument address against kernel_task global address, unlike older source parent-task test.',
                         'Correcting these APIs leaves other callee prototype and lock-loop interpretation questions open.']}
    (HERE / 'evidence.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result['summary'], indent=2))


if __name__ == '__main__':
    main()
