"""Lexical/AST inventory of prior audit consumers; not a vulnerability proof."""
import ast
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PATTERNS = ('CS_AC_WRITE', 'op.access', 'def trace_check(', 'def replay(', 'def stack_flow(')


def main():
    findings, scanned = [], []
    for p in sorted(HERE.parent.rglob('*.py')):
        if HERE in p.parents or '__pycache__' in p.parts:
            continue
        data = p.read_bytes()
        source = data.decode('utf-8')
        tree = ast.parse(source, filename=str(p))
        scanned.append({'path': str(p.relative_to(ROOT)), 'size': len(data), 'sha256': hashlib.sha256(data).hexdigest()})
        functions = [node for node in ast.walk(tree) if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef))]
        for line, text in enumerate(source.splitlines(), 1):
            hits = [pattern for pattern in PATTERNS if pattern in text]
            if hits:
                owners = [node for node in functions if node.lineno <= line <= node.end_lineno]
                owner = min(owners, key=lambda node: node.end_lineno - node.lineno).name if owners else None
                findings.append({'path': str(p.relative_to(ROOT)), 'line': line, 'function': owner, 'patterns': hits, 'text': text.strip()})
    output = {'files': scanned, 'findings': findings, 'patterns': list(PATTERNS),
              'scope': 'prior report Python sources only; lexical/AST triage, not whole-repository semantic assurance',
              'remaining': 'consumers before31 and full generic EA/flags/control-flow/dataflow still need evidence-specific review'}
    (HERE / 'consumer-inventory.json').write_text(json.dumps(output, indent=2) + '\n')
    print(json.dumps({'files_scanned': len(scanned), 'pattern_hits': len(findings)}))


if __name__ == '__main__':
    main()
