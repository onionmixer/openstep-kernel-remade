#!/usr/bin/env python3
"""Read-only evidence checks; write a separate report using Python calculations."""
import csv
import hashlib
import json
import subprocess
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
RUN = ROOT / '04_ghidra/exports/x86/full-pass5'


def read(path):
    return json.loads((ROOT / path).read_text())


def digest(path):
    checksum = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            checksum.update(block)
    return checksum.hexdigest()


def main():
    errors = []
    blocks = read('04_ghidra/exports/x86/full-pass5/memory-blocks.json')
    rows = list(csv.DictReader((RUN / 'code-units.tsv').open(), delimiter='\t'))
    block_reports = []
    for block in blocks:
        start = int(block['start'], 16)
        end = int(block['end_inclusive'], 16) + 1
        cursor = start
        counts = Counter()
        for row in rows:
            a = int(row['start'], 16)
            z = int(row['end_inclusive'], 16) + 1
            if a >= end or z <= start:
                continue
            a, z = max(a, start), min(z, end)
            if a != cursor:
                errors.append({'block': block['name'], 'expected': hex(cursor), 'actual': hex(a)})
            cursor = z
            counts[row['kind']] += z - a
        if cursor != end:
            errors.append({'block': block['name'], 'missing_end': hex(cursor)})
        block_reports.append({**block, 'listing_bytes_by_kind': dict(counts)})

    # Whole-program listing must contain exactly the same address/length sequence.
    listing = (RUN / 'whole-program.asm').read_text().splitlines()
    if len(listing) != len(rows):
        errors.append('listing/code-unit row count mismatch')
    for row, line in zip(rows, listing):
        address, length, _ = line.split('\t', 2)
        if int(address, 16) != int(row['start'], 16) or int(length) != int(row['length']):
            errors.append({'listing_row_mismatch': address})

    artifact_hashes = read('09_validation/reports/full-analysis/artifact-hashes.json')
    for row in artifact_hashes:
        path = ROOT / row['path']
        if path.stat().st_size != row['size'] or digest(path) != row['sha256']:
            errors.append({'changed_export': row['path']})

    extraction = read('01_resources/manifests/darwin-extraction.json')
    for row in extraction['files']:
        path = ROOT / '01_resources/upstream/darwin01' / row['path']
        if path.stat().st_size != row['size'] or digest(path) != row['sha256']:
            errors.append({'changed_reference': row['path']})
    acquisition = read('01_resources/manifests/acquisition.json')
    sources = []
    for row in acquisition['sources']:
        path = ROOT / row['path']
        if row['status'] != 'acquired':
            errors.append({'unacquired': row['id']})
        if row['kind'] == 'git':
            commit = subprocess.check_output(['git', '-C', str(path), 'rev-parse', 'HEAD'], text=True).strip()
            dirty = subprocess.check_output(['git', '-C', str(path), 'status', '--porcelain'], text=True).strip()
            if commit != row['commit'] or dirty:
                errors.append({'changed_checkout': row['id']})
        elif digest(path) != row['sha256']:
            errors.append({'changed_archive_or_license': row['id']})
        sources.append({'id': row['id'], 'path': row['path'], 'status': row['status']})

    ida = read('05_ida/exports/x86/index.json')
    for row in ida['functions']:
        if row.get('pseudocode') and digest(ROOT / row['pseudocode']) != row['sha256']:
            errors.append({'changed_ida_export': row['address']})
    ghidra = read('04_ghidra/exports/x86/full-pass5/functions.json')
    entries = {int(row['address'], 16) for row in ghidra}
    actions = read('09_validation/static/full-analysis/gap-actions.json')
    corrected_data = {int(row['start'], 16) for row in actions['data_corrections']}
    failed_ida = [row for row in ida['functions'] if not row.get('pseudocode')]
    missing_material = [row['address'] for row in failed_ida
                        if int(row['address'], 16) not in entries | corrected_data]
    if missing_material:
        errors.append({'ida_failures_without_ghidra_or_data_evidence': missing_material})
    report = {
        'errors': errors,
        'mapped_blocks': block_reports,
        'whole_program_listing_rows': len(listing),
        'verified_primary_export_files': len(artifact_hashes),
        'verified_extracted_reference_files': len(extraction['files']),
        'verified_sources': sources,
        'ida_successful_addresses': ida['successful_addresses'],
        'ida_failed_addresses': len(failed_ida),
        'ida_failed_addresses_with_ghidra_pseudocode': sum(int(row['address'], 16) in entries for row in failed_ida),
        'ida_failed_addresses_corrected_to_data': sum(int(row['address'], 16) in corrected_data for row in failed_ida),
        'ida_internal_binary_patches_verified': False,
        'scope': 'Material completeness and integrity, not semantic correctness or GCC 2.7 compatibility.',
    }
    (ROOT / '09_validation/reports/full-analysis/evidence-audit.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({k: v for k, v in report.items() if k != 'mapped_blocks'}, indent=2))
    if errors:
        raise SystemExit(1)


if __name__ == '__main__':
    main()
