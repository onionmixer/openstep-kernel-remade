"""Negative controls for census/edge validation, not kernel execution tests."""
import copy
import json
from pathlib import Path
import branch_inventory as B

HERE = Path(__file__).resolve().parent


def rejected(name, action, evidence):
    try:
        action()
    except AssertionError as error:
        evidence.append({'test': name, 'rejected': True, 'reason': str(error)})
    else:
        raise AssertionError(('invalid input accepted', name))


def main():
    evidence = []
    entry = 0x17a248
    stem = B.EXPORT / 'functions' / f'{entry:08x}'
    original = stem.with_suffix('.asm').read_text()
    lines = original.splitlines()
    rejected('missing instruction', lambda: B.parse_function(entry, '\n'.join(lines[1:])), evidence)
    rejected('duplicate instruction', lambda: B.parse_function(entry, original + lines[0] + '\n'), evidence)
    rejected('wrong instruction size', lambda: B.parse_function(entry, original.replace('0x0017a248\t1\t', '0x0017a248\t2\t')), evidence)
    rejected('wrong branch destination', lambda: B.parse_function(entry, original.replace('JNZ 0x0017a264', 'JNZ 0x0017a265')), evidence)
    rejected('wrong mnemonic', lambda: B.parse_function(entry, original.replace('PUSH EBP', 'POP EBP')), evidence)
    meta = json.loads(stem.with_suffix('.json').read_text())
    meta['body'].append(copy.deepcopy(meta['body'][0]))
    rejected('overlapping metadata body', lambda: B.parse_function(entry, metadata=meta), evidence)
    functions = [B.parse_function(entry)]
    rejected('invalid adjacent branch head', lambda: B.observations(functions, [{'trace': ['0x17a253', '0x17a269']}]), evidence)
    rejected('truncated branch observation', lambda: B.observations(functions, [{'trace': ['0x17a253']}]), evidence)
    rejected('wrong adjacent call target', lambda: B.observations(functions, [{'trace': ['0x17a256', '0x17a25b']}]), evidence)
    # Separate cases cannot supply each other's missing successor.
    rejected('cross-case edge fabrication', lambda: B.observations(functions, [{'trace': ['0x17a253']}, {'trace': ['0x17a264']}]), evidence)
    B.observations(functions, [{'trace': ['0x17a253', '0x17a264']}, {'trace': ['0x17a253', '0x17a255']}])
    branch = next(r for r in functions[0]['rows'] if r['pc'] == '0x17a253')
    assert branch['report26_visits'] == 2 and branch['report26_cases'] == 2
    assert [e['report26_direct_transition_visits'] for e in branch['successors']] == [1, 1]
    result = {'negative_controls': evidence, 'rejections': len(evidence), 'positive_two_outcome_control': True,
              'scope': 'synthetic analyzer inputs, not CPU execution or VM fault feasibility'}
    (HERE / 'negative-controls.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
