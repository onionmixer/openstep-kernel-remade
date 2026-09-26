"""Supplement: every byte value at every discovered byte INC/DEC site."""
import json
from normalized_execution import HERE, site_cases


def main():
    scan = json.loads((HERE / 'scan.json').read_text())
    sites = [s for s in scan['sites'] if s['width'] == 1]
    rows = [site_cases(s, exhaustive_byte=True) for s in sites]
    summary = {'sites': len(rows), 'input_values_per_site': len({c[0] for r in rows for c in r['cases']}),
               'cases': sum(len(r['cases']) for r in rows), 'mismatches': [],
               'scope': 'All byte values with the same four carry/status input patterns; not all architectural machine states.'}
    (HERE / 'exhaustive-byte.json').write_text(json.dumps({'summary': summary,
        'case_columns': ['old', 'incoming_eflags', 'new', 'actual_eflags', 'memory_reads', 'memory_writes'], 'sites': rows}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
