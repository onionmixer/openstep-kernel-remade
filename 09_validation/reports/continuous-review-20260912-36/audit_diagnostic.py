"""Read-only audit of the stopped kernel prefix and isolated backend diagnostics.

This must not mark the planned kernel resource reuse complete.
"""
import copy
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys
from verify_artifacts import preserved

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('review35', HERE.parent / 'continuous-review-20260912-35/review.py')
R = importlib.util.module_from_spec(spec)
spec.loader.exec_module(R)
G, F, B, A = R.G, R.F, R.B, R.A


def probe_check(data):
    fields = 'eax ebx ecx edx esi edi ebp esp eip eflags cs ss ds es fs gs cr0 cr2 cr3 cr4 gdtr idtr ldtr tr'.split()
    assert data['public_cpu_fields'] == fields
    geometry = {'pd': 0x1000, 'pt': 0x2000, 'entry': 0x3000, 'absent': 0x4000, 'ram_size': 0x10000, 'nop': 0x3005}
    assert data['geometry'] == geometry and data['code_hex'] == 'a10040000090'
    assert data['unicorn_version'] == '2.1.4' and data['all_expected_results_observed']
    assert data['kernel_reuse_completed'] is False
    lib = Path(data['library'])
    assert hashlib.sha256(lib.read_bytes()).hexdigest() == data['library_sha256']
    expected = {'same_instance_repeated_NP': [14, 8], 'NOP_between_NP': [14, None, 8],
                'fresh_instance': [14], 'prefault_context_restore': [14, 14], 'postfault_context_restore': [14, 8]}
    assert len(data['cases']) == len(expected) and {c['name'] for c in data['cases']} == set(expected)
    ram = bytearray(geometry['ram_size'])
    struct.pack_into('<I', ram, geometry['pd'], geometry['pt'] | 0x23)
    struct.pack_into('<I', ram, geometry['pt'] + (geometry['entry'] >> 12) * 4, geometry['entry'] | 0x23)
    ram[geometry['entry']:geometry['entry'] + len(bytes.fromhex(data['code_hex']))] = bytes.fromhex(data['code_hex'])
    ram_hash = hashlib.sha256(ram).hexdigest()
    for case in data['cases']:
        assert len(case['runs']) == len(expected[case['name']])
        for run, vector in zip(case['runs'], expected[case['name']]):
            assert run['writes'] == [] and run['before_ram_sha256'] == run['after_ram_sha256'] == ram_hash
            assert set(run['before']) == set(run['after']) == set(data['public_cpu_fields'])
            assert run['before']['cr0'] == run['after']['cr0'] == 0x80000011
            assert run['before']['cr3'] == run['after']['cr3'] == geometry['pd']
            if vector is None:
                assert run['events'] == [] and run['heads'] == [{'address': geometry['nop'], 'size': 1}]
                assert run['after']['eip'] == geometry['nop'] + 1
                assert run['after'] == dict(run['before'], eip=geometry['nop'] + 1)
            else:
                assert run['heads'] == [{'address': geometry['entry'], 'size': 5}]
                assert run['events'] == [{'vector': vector, 'cpu': run['after']}]
                assert run['after']['eip'] == geometry['entry'] and run['after']['cr2'] == geometry['absent']
                assert run['after']['eax'] == 0x22222222
                assert run['after'] == dict(run['before'], eip=geometry['entry'])
        if case['name'] == 'prefault_context_restore':
            assert case['restore_public_cpu_before'] == case['restore_public_cpu_after'] == case['runs'][0]['after'] == case['runs'][1]['before']
            assert case['restore_ram_before'] == case['restore_ram_after'] == ram_hash
            assert case['public_state_equal'] is True and case['opaque_context_equal_claimed'] is False
    return {'cases': len(data['cases']), 'public_fields': len(data['public_cpu_fields']), 'ram_hash_independently_reconstructed': ram_hash}


def kernel_check(row):
    params = tuple(row['params'])
    assert params == ('A', '_copyout', 0x100, 2, 1), 'diagnostic scope is the actually recorded case only'
    rows = json.loads((HERE.parent / 'continuous-review-20260912-34/gc-cases.json').read_text())
    ref = next(r for r in rows if tuple(r['params']) == params and (r['last'], r['tick']) == (1, 3))
    assert row['prefix34_canonical_sha256'] == G.canonical(ref)
    assert row['pre_input'] == ref['after']
    words = [F.STOP, F.VA + 0x101, F.VA + params[2], 1]
    assert row['caller_input'] == {'stack': 0x710000, 'words': words, 'flags': params[3]}
    expected = copy.deepcopy(ref['after'])
    G.R.patch(expected, 'stack_memory', 0x710000 - F.STACK, F.STOP)
    expected['copy_stack'] = struct.pack('<4I', *words).hex()
    expected['cpu'].update(G.R.CALLEE, esp=0x710000, eflags=params[3])
    assert row['before'] == expected, 'undeclared caller boundary change'
    trace, fault = row['fault']['trace'], row['fault']['after']
    assert trace == row['recorded_heads'] and trace[0] == '0x189cec' and trace[-1] == '0x189d1b'
    assert row['fault']['error'] is None
    assert row['fault']['interrupts'] == [{'vector': 8, 'snapshot': fault, 'recover': 0x189e70}]
    assert fault == row['at_fault']['cpu'] and fault['cr2'] == F.VA + params[2]
    F.C.trace_check(trace[:-1], fault['eip'])
    ins = A.instruction(fault['eip'])
    assert ins.mnemonic == 'mov' and ins.op_str == 'byte ptr fs:[ecx], bl'
    assert fault['ecx'] == fault['cr2'] and fault['fs'] == 0x50
    payload = (0x101 * 17 + (0x101 >> 8) * 29 + 0xc7) & 0xff
    assert fault['ebx'] & 0xff == payload
    assert not B.walk(G.regions(row['at_fault']), F.ROOTS[params[0]], fault['cr2'])['present']
    for key, value in row['before'].items():
        if key not in ('cpu', 'stack_memory'):
            assert row['at_fault'][key] == value, ('unexpected prefault state change', key)
    assert all(w['trace_index'] < len(trace) - 1 for w in row['writes']), 'failed store must not be replayed as committed'
    R.cardinality({'observation': {'trace': trace[:-1]}, 'writes': row['writes']})
    replay_row = dict(row, observation=row['fault'], points=[], after=row['at_fault'])
    G.replay(replay_row)
    return {'prefault_heads': len(trace), 'committed_writes': len(row['writes']),
            'observed_vector': 8, 'handler_entered': False, 'planned_reuse_completed': False}


def main():
    preservation = preserved()
    names = ('latest-prefault.json', 'exception-probe.json')
    before = {n: hashlib.sha256((HERE / n).read_bytes()).hexdigest() for n in names}
    stopped = subprocess.run([sys.executable, '-B', str(HERE / 'reuse_review.py'), '--single'], cwd=HERE,
                             text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    assert stopped.returncode == 1 and "refusing to inject handler for other vector', 8" in stopped.stderr
    subprocess.run([sys.executable, '-B', str(HERE / 'exception_probe.py')], cwd=HERE, check=True)
    after = {n: hashlib.sha256((HERE / n).read_bytes()).hexdigest() for n in names}
    assert before == after, 'diagnostic rerun differs'
    probe = probe_check(json.loads((HERE / 'exception-probe.json').read_text()))
    kernel = kernel_check(json.loads((HERE / 'latest-prefault.json').read_text()))
    assert preserved() == preservation
    result = {'probe': probe, 'kernel': kernel, 'reproducibility': {'before': before, 'after': after, 'equal': True},
              'expected_stopped_runner': {'returncode': stopped.returncode, 'stdout': stopped.stdout, 'stderr': stopped.stderr},
              'preservation': preservation, 'whole_goal_complete': False, 'report36_reuse_complete': False,
              'scope': 'diagnostic evidence validated; not resource-reuse acceptance or native double-fault delivery'}
    (HERE / 'diagnostic-verification.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'probe': probe, 'kernel': kernel, 'diagnostic_reproduced': True}))


if __name__ == '__main__':
    main()
