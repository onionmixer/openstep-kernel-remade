"""Record the local IDA Hex-Rays plugin availability for m68k and SPARC."""
import json
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'
IDA_ROOT = Path('/mnt/USERS/onion/DATA_ORIGN/local/ida-pro-9.3')


def main():
    plugin_names = sorted(path.name for path in (IDA_ROOT / 'plugins').iterdir() if path.is_file())
    hexrays_plugin_files = [name for name in plugin_names if name.lower().startswith('hex')]
    cfg_text = (IDA_ROOT / 'plugins/plugins.cfg').read_text(encoding='utf-8', errors='replace')
    configured_plugins = []
    for line in cfg_text.splitlines():
        if re.search(r'Hex-Rays_Decompiler', line, re.IGNORECASE):
            fields = line.split()
            if len(fields) >= 2:
                configured_plugins.append(fields[1])
    capabilities = {}
    for architecture, processor in (('m68k', '68K'), ('sparc', 'sparcb')):
        capability = json.loads((ROOT / '05_ida/exports' / architecture /
                                'decompiler-capability.json').read_text())
        assert capability['architecture'] == architecture
        assert capability['ida_processor'] == processor
        assert capability['ida_big_endian']
        assert capability['module_imported']
        assert not capability['plugin_initialized']
        capabilities[architecture] = {
            'ida_processor': processor,
            'ida_big_endian': capability['ida_big_endian'],
            'idapython_hexrays_module_imported': capability['module_imported'],
            'hexrays_plugin_initialized': capability['plugin_initialized'],
            'hexrays_version': capability['version'],
            'installed_hexrays_plugin_filename_matches_architecture': any(
                architecture in name.lower() or
                (architecture == 'm68k' and '68k' in name.lower())
                for name in hexrays_plugin_files),
            'plugins_cfg_hexrays_entry_matches_architecture': any(
                architecture in name.lower() or
                (architecture == 'm68k' and '68k' in name.lower())
                for name in configured_plugins),
        }
        assert not capabilities[architecture]['installed_hexrays_plugin_filename_matches_architecture']
        assert not capabilities[architecture]['plugins_cfg_hexrays_entry_matches_architecture']
    output = {
        'schema': 1,
        'ida_installation_path': str(IDA_ROOT),
        'installed_hexrays_plugin_filenames': hexrays_plugin_files,
        'plugins_cfg_hexrays_plugin_names': configured_plugins,
        'targets': capabilities,
        'local_conclusion': (
            'the current local IDA installation has no m68k or SPARC Hex-Rays architecture plugin file or '
            'plugins.cfg entry, and initialization failed on both validated big-endian databases'),
        'recommended_direction': (
            'retain IDA assembly/xref exports as static tool observations; do not retry IDA Hex-Rays for these '
            'architectures under this installation; perform a separate explicitly big-endian Ghidra decompiler '
            'capability probe before using any Ghidra output'),
        'interpretation_limit': (
            'This describes only the current local installation and validated databases. It does not establish '
            'global vendor support policy, a license cause, decompilation correctness, code/data truth, function '
            'boundaries, ABI, or behavior.'),
    }
    (REPORT / 'ida-hexrays-architecture-availability-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({architecture: target['hexrays_plugin_initialized']
                      for architecture, target in capabilities.items()}, sort_keys=True))


if __name__ == '__main__':
    main()
