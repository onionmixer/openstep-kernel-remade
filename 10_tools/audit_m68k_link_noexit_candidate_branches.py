"""Verify raw direct branch encodings for five bounded m68k LINK no-exit candidates."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
TARGETS = (0x400159A, 0x40015E2, 0x400165E, 0x40016D0, 0x4095890)


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def decode_branch_target(source, raw):
    word = int.from_bytes(raw[:2], 'big')
    if word & 0xf000 == 0x6000:
        size = word & 0xff
        if size == 0:
            displacement = int.from_bytes(raw[2:4], 'big', signed=True)
            form = 'bcc_word_displacement'
        elif size == 0xff:
            displacement = int.from_bytes(raw[2:6], 'big', signed=True)
            form = 'bcc_long_displacement'
        else:
            displacement = int.from_bytes(raw[1:2], 'big', signed=True)
            form = 'bcc_byte_displacement'
        return (source + 2 + displacement) & 0xffffffff, displacement, form
    if word & 0xf0f8 == 0x50c8:
        displacement = int.from_bytes(raw[2:4], 'big', signed=True)
        return (source + 2 + displacement) & 0xffffffff, displacement, 'dbcc_word_displacement'
    raise AssertionError(hex(word))


def raw_item(binary, unit, text_start, text_offset):
    address = int(unit['address'], 16)
    position = text_offset + address - text_start
    original = binary[position:position + int(unit['length'])]
    assert original.hex() == unit['bytes']
    return {
        'address': unit['address'],
        'kind': unit['kind'],
        'original_bytes': original.hex(),
        'ida_disassembly': unit['disassembly'],
    }


def main():
    binary = (ROOT / '03_original/m68k/binaries/mach_kernel').read_bytes()
    inventory = json.loads((ROOT / '03_original/m68k/inventory/macho.json').read_text())
    text = next(section for section in inventory['sections']
                if section['segment'] == '__TEXT' and section['name'] == '__text')
    text_start = int(text['address'], 16)
    text_offset = int(text['file_offset'])
    candidates = {int(candidate['start'], 16): candidate for candidate in
                  read_tsv(ROOT / '05_ida/exports/m68k/function-candidate-lexical-exits.tsv')}
    units = {int(unit['address'], 16): unit for unit in
             read_tsv(ROOT / '05_ida/exports/m68k/text-units.tsv')}
    xrefs = read_tsv(ROOT / '05_ida/exports/m68k/xrefs.tsv')
    rows = []
    total = 0
    for start in TARGETS:
        candidate = candidates[start]
        end = int(candidate['end'], 16)
        branches = [xref for xref in xrefs if xref['type'] == '19'
                    and start <= int(xref['from'], 16) < end]
        branch_rows = []
        mnemonic_counts = Counter()
        form_counts = Counter()
        internal = 0
        external = 0
        for xref in branches:
            source = int(xref['from'], 16)
            target = int(xref['to'], 16)
            source_item = raw_item(binary, units[source], text_start, text_offset)
            target_item = raw_item(binary, units[target], text_start, text_offset)
            raw = bytes.fromhex(source_item['original_bytes'])
            computed, displacement, form = decode_branch_target(source, raw)
            assert computed == target
            name = source_item['ida_disassembly'].split(None, 1)[0]
            mnemonic_counts[name] += 1
            form_counts[form] += 1
            if start <= target < end:
                internal += 1
            else:
                external += 1
            branch_rows.append({
                'source': hex(source),
                'target': hex(target),
                'signed_big_endian_displacement': displacement,
                'encoding_form': form,
                'source_item': source_item,
                'target_item': target_item,
                'target_relation': 'inside_candidate' if start <= target < end else 'outside_candidate',
            })
        total += len(branch_rows)
        rows.append({
            'candidate': candidate,
            'direct_branch_count': len(branch_rows),
            'branch_mnemonic_counts': dict(mnemonic_counts),
            'branch_encoding_form_counts': dict(form_counts),
            'target_relation_counts': {'inside_candidate': internal, 'outside_candidate': external},
            'branches': branch_rows,
        })
    assert len(rows) == 5
    assert total == 31
    output = {
        'schema': 1,
        'architecture': 'm68k',
        'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
        'candidate_count': len(rows),
        'direct_branch_count': total,
        'all_branch_targets_match_raw_big_endian_displacements_and_type19_xrefs': True,
        'rows': rows,
        'interpretation_limit': ('direct branch targets and candidate-range relations do not establish branch '
                                'conditions, fallthrough, path reachability, terminal behavior, function boundaries, '
                                'calling convention, ABI, or behavior'),
    }
    (REPORT / 'm68k-link-noexit-candidate-branches-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({'candidate_count': len(rows), 'direct_branch_count': total,
                      'all_checks_passed': True}))


if __name__ == '__main__':
    main()
