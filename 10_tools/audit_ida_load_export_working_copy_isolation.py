"""Record current canonical/working DB separation for all-load IDA exports."""
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def digest(path):
    data = path.read_bytes()
    return len(data), hashlib.sha256(data).hexdigest()


def main():
    targets = {}
    for architecture in ('m68k', 'sparc'):
        canonical = ROOT / '05_ida/databases' / ('%s-os42j.i64' % architecture)
        working = ROOT / '05_ida/databases' / ('%s-os42j-load-units-export.i64' % architecture)
        canonical_size, canonical_hash = digest(canonical)
        working_size, working_hash = digest(working)
        summary = json.loads((ROOT / '05_ida/exports' / architecture /
                              'load-units-summary.json').read_text())
        assert summary['database_kind'] == 'copied_working_database'
        assert summary['database_filename'] == working.name
        targets[architecture] = {
            'canonical_database_filename': canonical.name,
            'working_database_filename': working.name,
            'canonical_database_byte_count': canonical_size,
            'working_database_byte_count': working_size,
            'canonical_database_sha256_recomputed_with_python': canonical_hash,
            'working_database_sha256_recomputed_with_python': working_hash,
            'working_database_differs_from_canonical_after_export': canonical_hash != working_hash,
            'load_export_summary_identifies_copied_working_database': True,
        }
    output = {
        'schema': 1, 'targets': targets,
        'interpretation_limit': (
            'This records current database file separation and hashes only. A difference does not identify '
            'which database metadata changed, why it changed, or establish any binary, code/data, relocation, '
            'runtime, function-boundary, ABI, or behavior conclusion.'),
    }
    (REPORT / 'ida-load-export-working-copy-isolation-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({architecture: entry['working_database_differs_from_canonical_after_export']
                      for architecture, entry in targets.items()}, sort_keys=True))


if __name__ == '__main__':
    main()
