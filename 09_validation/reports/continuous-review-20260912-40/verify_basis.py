"""Pinned preserved inputs and raw original opcode/listing correspondence."""
import hashlib
import json
import sys
import audit_removal as A


def main():
    preserved = A.S.preserve()
    root = A.S.ROOT
    binary = root / '03_original/x86/binaries/mach_kernel'
    assert hashlib.sha256(binary.read_bytes()).hexdigest() == '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
    files = {binary}
    for entry in ('00191144', '0018f7f8', '00190f90'):
        directory = root / '04_ghidra/exports/x86/full-pass5/functions'
        files.update(directory / (entry + suffix) for suffix in ('.asm', '.c', '.json'))
        for line in (directory / (entry + '.asm')).read_text().splitlines():
            address, size, _ = line.split('\t', 2)
            ins = A.A.instruction(int(address, 16))
            assert ins.address == int(address, 16) and ins.size == int(size)
    opcodes = {}
    for pc in (0x1912e3, 0x1912eb, 0x1912f0, 0x191301, 0x191333, 0x19133b, 0x19133e,
               0x191396, 0x1913c3, 0x18f8b4, 0x18fa13, 0x18fa33, 0x191040, 0x19107c, 0x1913db):
        ins = A.A.instruction(pc)
        assert bytes(ins.bytes) == A.A.original(pc, ins.size)
        opcodes[hex(pc)] = {'bytes': bytes(ins.bytes).hex(), 'mnemonic': ins.mnemonic, 'operands': ins.op_str}
    # Include all imported read-only auditor module sources and fixed runner/helper sources.
    for module in list(sys.modules.values()):
        name = getattr(module, '__file__', None)
        if name:
            path = __import__('pathlib').Path(name).resolve()
            if path.is_relative_to(root) and path.suffix == '.py':
                files.add(path)
    files.update(A.S.HERE.glob('*.py'))
    files.update(A.S.R34 / n for n in ('pt_gc_review.py', 'dirty_prefix.py', 'helper-check.json'))
    rows = [{'path': str(p.relative_to(root)), 'size': p.stat().st_size,
             'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in sorted(files)]
    A.S.save('source-basis.json', {'inputs': rows, 'opcodes': opcodes,
        'preservation_sha256': A.S.canonical(preserved), 'whole_goal_complete': False,
        'scope': 'pinned source inputs and original-byte instruction boundaries; no GCC 2.7 compilation'})
    print(json.dumps({'basis_inputs': len(rows), 'selected_opcodes': len(opcodes)}))


if __name__ == '__main__':
    main()
