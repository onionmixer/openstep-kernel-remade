"""Read-only report33 CALL/RET regression; no old producer or manifest writes."""
import json
from pathlib import Path
import audit_results as A

HERE = Path(__file__).resolve().parent


def main():
    refs = A.references()
    rows = json.loads((A.PRIOR / 'dirty-remove-cases.json').read_text())
    result = []
    for row in rows:
        assert A.canonical(row) == refs[tuple(row['params'])]['hash']
        result.append({'params': row['params'], 'passed': True, 'stack_flow': A.stack_flow(row)})
    out = {'cases': result, 'all_passed': True,
           'scope': 'read-only report33 ordinary ESP/EBP/CALL/RET check only; not full re-audit, not report32 IRETD',
           'write_cardinality_applied': False,
           'write_cardinality_limit': 'report33 includes MOVZX absent from report34 GC whitelist; no silent expansion'}
    (HERE / 'legacy-stack-review.json').write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps({'legacy_stack_rows_passed': len(result)}))


if __name__ == '__main__':
    main()
