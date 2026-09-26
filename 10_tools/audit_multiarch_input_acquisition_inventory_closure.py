"""Verify OS42J input acquisition and big-endian raw inventory prerequisites."""
import hashlib
import json
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    provenance = json.loads((ROOT / '03_original/installation-media/os42j/provenance.json').read_text())
    inventory_validation = json.loads((REPORT / 'raw-inventory-validation.json').read_text())['targets']
    source_iso = Path(provenance['source_iso']['path'])
    assert source_iso.stat().st_size == provenance['source_iso']['size']
    assert sha256(source_iso) == provenance['source_iso']['sha256']
    container_path = ROOT / provenance['container']['destination']
    container = container_path.read_bytes()
    assert len(container) == provenance['container']['size']
    assert hashlib.sha256(container).hexdigest() == provenance['container']['sha256']
    magic, arch_count = struct.unpack_from('>II', container, 0)
    assert magic == 0xcafebabe
    assert arch_count == provenance['container']['fat_arch_count']
    fat_entries = []
    for index in range(arch_count):
        cputype, cpusubtype, offset, size, alignment = struct.unpack_from('>iiIII', container, 8 + index * 20)
        assert offset + size <= len(container)
        fat_entries.append({'index': index, 'cputype': cputype, 'cpusubtype': cpusubtype,
                            'offset': offset, 'size': size, 'alignment_exponent': alignment})
    target_results = {}
    for item in provenance['slices']:
        architecture = item['architecture']
        thin_path = ROOT / item['destination']
        thin = thin_path.read_bytes()
        entry = fat_entries[item['fat_index']]
        assert len(thin) == item['size'] == entry['size']
        assert entry['offset'] == item['offset'] and entry['alignment_exponent'] == item['alignment_exponent']
        assert entry['cputype'] == int(item['cputype_raw'], 16)
        assert entry['cpusubtype'] == int(item['cpusubtype_raw'], 16)
        assert container[entry['offset']:entry['offset'] + entry['size']] == thin
        assert hashlib.sha256(thin).hexdigest() == item['sha256']
        thin_magic, cputype = struct.unpack_from('>Ii', thin, 0)
        assert thin_magic == 0xfeedface and cputype == entry['cputype']
        inventory = json.loads((ROOT / '03_original' / architecture / 'inventory/macho.json').read_text())
        validation = inventory_validation[architecture]
        assert inventory['sha256'] == item['sha256']
        assert inventory['endian'] == 'big' and inventory['cpu_type'] == entry['cputype']
        assert validation['sha256_match'] and validation['big_endian'] == 'big'
        assert validation['segment_and_section_file_bounds_valid']
        target_results[architecture] = {
            'thin_sha256_recomputed_with_python': hashlib.sha256(thin).hexdigest(),
            'fat_entry_big_endian_fields_match_provenance': True,
            'fat_slice_bytes_equal_preserved_thin_binary': True,
            'thin_header_big_endian_magic_and_cpu_type_match_fat_entry': True,
            'raw_inventory_sha256_and_big_endian_fields_match': True,
            'raw_inventory_file_bounds_valid': True,
            'fat_entry': {'index': item['fat_index'], 'offset': entry['offset'], 'size': entry['size'],
                          'cputype': entry['cputype'], 'cpusubtype': entry['cpusubtype'],
                          'alignment_exponent': entry['alignment_exponent']},
        }
    assert set(target_results) == {'m68k', 'sparc'}
    output = {
        'schema': 1,
        'source_iso_sha256_recomputed_with_python': sha256(source_iso),
        'source_iso_byte_count': source_iso.stat().st_size,
        'fat_container_sha256_recomputed_with_python': hashlib.sha256(container).hexdigest(),
        'fat_container_byte_count': len(container),
        'fat_header_big_endian_arch_count': arch_count,
        'targets': target_results,
        'prerequisite_closure': {
            'os42j_input_acquisition_hash_and_fat_slice_validation': True,
            'big_endian_raw_macho_inventory_validation': True,
        },
        'interpretation_limit': (
            'This verifies only source-media, Fat-container, thin-slice, and raw Mach-O inventory provenance. '
            'It does not establish code/data truth, relocation, execution, function boundaries, ABI, types, '
            'or behavior.'),
    }
    (REPORT / 'multiarch-input-acquisition-inventory-closure.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(output['prerequisite_closure'], sort_keys=True))


if __name__ == '__main__':
    main()
