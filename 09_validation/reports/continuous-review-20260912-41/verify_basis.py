"""Original raw opcodes, preserved source inputs and failure evidence identity."""
import hashlib
import json
import audit_pd as A


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    root, here = A.S.ROOT, A.S.HERE
    preservation = A.S.preserve()
    binary = root / '03_original/x86/binaries/mach_kernel'
    assert sha(binary) == '33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890'
    files = {binary, *here.glob('*.py')}
    for entry in ('0018f40c', '0018f58c', '0018f644', '0018f69c', '00191144', '0018fb0c',
                  '0016b364', '0016b84c', '0015b54c', '00101600', '00101630'):
        base = root / '04_ghidra/exports/x86/full-pass5/functions'
        files.update(base / (entry + suffix) for suffix in ('.asm', '.c', '.json'))
        for line in (base / (entry + '.asm')).read_text().splitlines():
            address, size, _ = line.split('\t', 2)
            ins = A.A.instruction(int(address, 16))
            assert ins.address == int(address, 16) and ins.size == int(size)
    files.update(root / ('01_resources/upstream/darwin01/kernel/' + name) for name in
                 ('machdep/i386/pmap.c', 'machdep/i386/pmap_private.h', 'kern/zalloc.c', 'kern/zalloc.h'))
    opcodes = {}
    for pc in (0x16b3b7, 0x16b3c6, 0x16b8d4, 0x18f431, 0x18f453, 0x18f461, 0x18f476,
               0x18f484, 0x18f62e, 0x18f75a, 0x18f797, 0x1911fe, 0x191220, 0x19124b,
               0x18fcbe, 0x18fcc5, 0x18fcd4, 0x18fcd8):
        ins = A.A.instruction(pc)
        assert bytes(ins.bytes) == A.A.original(pc, ins.size)
        opcodes[hex(pc)] = {'bytes': bytes(ins.bytes).hex(), 'mnemonic': ins.mnemonic, 'operands': ins.op_str}
    failure = here / 'failed-create-slot1-zone-seed.json'
    identity = json.loads((here / 'zone-seed-failure-identity.json').read_text())
    assert sha(failure) == identity['failure_sha256'] == 'e6dbe2e6f8e751f3cfc22f4bececc772feda929ba7d65ee7841dc5d4126e7ba2'
    failed = json.loads(failure.read_text())
    assert failed['label'] == 'create_slot1' and failed['failure'] == "AssertionError(('unexpected path', '0x16b3df'))"
    rows = [{'path': str(p.relative_to(root)), 'size': p.stat().st_size, 'sha256': sha(p)} for p in sorted(files)]
    A.S.save('source-basis.json', {'inputs': rows, 'opcodes': opcodes,
        'preservation_sha256': A.S.canonical(preservation), 'failure_sha256': sha(failure),
        'whole_goal_complete': False, 'scope': 'pinned inputs and raw opcode/listing correspondence; not a GCC build'})
    print(json.dumps({'basis_inputs': len(rows), 'selected_opcodes': len(opcodes)}))


if __name__ == '__main__':
    main()
