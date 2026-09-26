"""Reject any helper edit outside the declared mechanical report33 adaptation."""
import ast
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
PRIOR = HERE.parent / 'continuous-review-20260911-33/dirty_remove_review.py'


def check():
    source = PRIOR.read_text()
    assert source.count("    save('latest-diagnostic.json', result)\n") == 1
    assert source.count('    return result\n\n\ndef main():') == 1
    expected = source.replace("    save('latest-diagnostic.json', result)\n", '')
    expected = expected.replace('    return result\n\n\ndef main():', '    return uc, result\n\n\ndef main():')
    expected = expected.split('\n\ndef main():')[0] + '\n'
    actual = (HERE / 'dirty_prefix.py').read_text()
    assert actual.rstrip() == expected.rstrip()
    ast.parse(actual)
    assert "HERE.parent / 'continuous-review-20260911-32/fault_new_pt_review.py'" in actual
    result = {'matched': True, 'source': str(PRIOR.relative_to(HERE.parent)),
              'source_sha256': hashlib.sha256(PRIOR.read_bytes()).hexdigest(),
              'helper_sha256': hashlib.sha256((HERE / 'dirty_prefix.py').read_bytes()).hexdigest(),
              'changes': ['remove case diagnostic write', 'return live CPU and case result', 'omit main and its invocation'],
              'comparison': 'exact source text after declared substitutions, ignoring trailing whitespace only'}
    (HERE / 'helper-check.json').write_text(json.dumps(result, indent=2) + '\n')
    return result


if __name__ == '__main__':
    print(json.dumps(check()))
