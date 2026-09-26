"""Check exact declared adaptation of preserved report34 GC runner."""
import ast
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
SOURCE = HERE.parent / 'continuous-review-20260912-34/pt_gc_review.py'
IMPORT = '''import importlib.util
_prefix_spec = importlib.util.spec_from_file_location('dirty34', Path(__file__).resolve().parent.parent / 'continuous-review-20260912-34/dirty_prefix.py')
C = importlib.util.module_from_spec(_prefix_spec)
_prefix_spec.loader.exec_module(C)'''


def expected():
    source = SOURCE.read_text()
    for needle in ("    save('latest-diagnostic.json', result)\n", '    return result\n\n\ndef main():', 'import dirty_prefix as C'):
        assert source.count(needle) == 1, needle
    source = source.replace("    save('latest-diagnostic.json', result)\n", '')
    source = source.replace('    return result\n\n\ndef main():', '    return uc, result\n\n\ndef main():')
    source = source.replace('import dirty_prefix as C', IMPORT)
    return source.split('\n\ndef main():')[0].rstrip() + '\n'


def check():
    actual = (HERE / 'gc_prefix.py').read_text()
    assert actual == expected()
    ast.parse(actual)
    result = {'matched': True, 'source_sha256': hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
        'helper_sha256': hashlib.sha256(actual.encode()).hexdigest(),
        'changes': ['remove case diagnostic write', 'return live CPU and record', 'omit main', 'explicit preserved dirty_prefix import'],
        'scope': 'exact source transformation, not semantic replacement'}
    (HERE / 'helper-check.json').write_text(json.dumps(result, indent=2) + '\n')
    return result


if __name__ == '__main__':
    print(json.dumps(check()))
