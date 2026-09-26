"""Read-only audit of native-IDT diagnostic records; RF failure stays a failure."""
import hashlib
import json
from pathlib import Path
import re
import struct
import capstone

HERE = Path(__file__).resolve().parent
CS = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
CS.detail = True
GEOMETRY = {'BASE': 0xc0000000, 'HW': 0x1000, 'PD': 0x1000, 'GDT': 0x2000, 'IDT': 0x3000,
    'PT': 0x4000, 'UPT': 0x8000, 'ENTRY': 0x100000, 'HANDLER': 0x101000, 'FATAL': 0x102000,
    'STACK': 0x180000, 'RECORD': 0x190000, 'RESULT': 0x190100, 'POINTER': 0x198000,
    'POSTFLAGS': 0x198004, 'DATA': 0x200000, 'USER': 0x600100, 'PTE': 0x8800, 'GDTR': 0x2f00, 'IDTR': 0x2f10}


def bios_check(raw):
    # Independently decoded 16-bit reset path: PIC/NMI masking, physical LGDT,
    # CR0.PE, operand-size-32 far jump to flat CS18:100000. No producer import.
    boot = bytes.fromhex('fa31c08ed88ed0bc0070b0ffe621e6a1b080e670'
        '2e0f011600010f20c06683c8010f22c066ea000010001800')
    wanted = bytearray([0xff]) * 0x10000
    wanted[:len(boot)] = boot
    struct.pack_into('<HI', wanted, 0x100, 0x57, 0x2000)
    wanted[0xfff0:0xfff5] = bytes.fromhex('ea000000f0')
    assert raw == wanted, 'reset/bootstrap ROM mismatch'


def fixture_check(raw, row):
    # Fixed, manually decoded fixture contract, not a second CPU emulator.
    # Pin prefixes, lengths, immediates, branch displacements and all padding.
    # Expectations do not call images() or read an expected generated image.
    assert row['labels'] == {'high': 0x100026, 'fault': 0x1000f6, 'store': 0x1000fb}
    assert row['code_lengths'] == {'boot': 44, 'program': 262, 'handler': 70, 'fatal': 19}
    flags = struct.pack('<I', row['flags']).hex()
    program = bytes.fromhex('''
        66b82000 8ed8 8ec0 8ed0 bc00001800
        b800100000 0f22d8 b811000080 0f22c0 ea260010000800
        66b81000 8ed8 8ec0 8ed0 66b85000 8ee0 8ee8
        0f0115002f0000 0f011d102f0000 c7050080190000001900
        bbe4000000 68 FLAGS 9d e896000000
        a1ff002000 a300011900 a104801900 a304011900
        a100880000 a308011900 89e0 a30c011900
        c7050088000000000000 b900016000 640f0139
        bbf5000000 68 FLAGS 9d e84e000000
        a1ff002000 a310011900 a104801900 a314011900
        a100880000 a318011900 89e0 a31c011900
        fc 66bae900 be00001900 b940000000 f36e
        be00011900 b920000000 f36e b810000000 66baf400 ef fa f4
        b900016000 648819 9c 58 a304801900 c3
        '''.replace('FLAGS', flags))
    handler = bytes.fromhex('609c588b3d00801900894718c7070e0000008d442420894704'
        '0f20d089471c8d7424208d7f08b904000000fcf3a58d7f08893d00801900'
        'c70500880000070020006183c404cf')
    fatal = bytes.fromhex('66bae900b0eeeeb82000000066baf400effaf4')
    wanted = bytearray(0x3000)
    for offset, block in ((0, program), (0x1000, handler), (0x2000, fatal)):
        wanted[offset:offset + len(block)] = block
        decoded = list(CS.disasm(block, 0x100000 + offset))
        assert sum(i.size for i in decoded) == len(block)
    assert raw == wanted, 'fixed fixture instruction/padding mismatch'
    # Frame includes CPU words and CALL return; scratch is below the frame.
    ranges = [(0x17ffc8, 0x17ffec), (0x17ffec, 0x180000),
              (0x190000, 0x190000 + 2 * 32),
              (0x190100, 0x190100 + 2 * 16), (0x198000, 0x198008)]
    for index, (start, end) in enumerate(ranges):
        for other_start, other_end in ranges[index + 1:]:
            assert end <= other_start or other_end <= start


def provenance_check(row, directory):
    directory = directory.resolve()
    assert directory == HERE / ('case-' + format(row['flags'], 'x'))
    required = {'bios.bin', 'tables.bin', 'code.bin', 'data.bin', 'output.bin', 'qemu.log', 'run.json'}
    assert set(row['hashes']) == required, 'mandatory evidence hashes missing/extra'
    command = ['/usr/bin/qemu-system-i386', '-machine', 'pc-i440fx-6.2,accel=tcg',
        '-cpu', 'qemu32', '-smp', '1', '-m', '16M', '-nodefaults', '-no-user-config',
        '-display', 'none', '-serial', 'none', '-monitor', 'none', '-nic', 'none', '-no-reboot',
        '-bios', str(directory / 'bios.bin'), '-chardev', 'file,id=diag,path=' + str(directory / 'output.bin'),
        '-device', 'isa-debugcon,iobase=0xe9,chardev=diag',
        '-device', 'isa-debug-exit,iobase=0xf4,iosize=4',
        '-d', 'int,cpu_reset', '-D', str(directory / 'qemu.log')]
    for name, address in (('tables.bin', 0), ('code.bin', 0x100000), ('data.bin', 0x200000)):
        command.extend(['-device', 'loader,file=' + str(directory / name) + ',addr=' + hex(address) + ',force-raw=on'])
    assert row['command'] == command, 'recorded command differs from fixture contract'
    assert row['original_opcodes'] == {'0x189d1b': '648819', '0x186d7c': 'cf'}
    metadata = ('flags', 'geometry', 'labels', 'code_lengths', 'original_opcodes',
                'command', 'returncode', 'stdout', 'stderr')
    assert json.loads((directory / 'run.json').read_text()) == {k: row[k] for k in metadata}, 'run metadata mismatch'


def table_check(raw):
    wanted = bytearray(0x9000)
    for selector, base, access in ((8, 0xc0000000, 0x9b), (0x10, 0xc0000000, 0x93), (0x18, 0, 0x9b), (0x20, 0, 0x93), (0x50, 0, 0x93)):
        descriptor = 0xffff | ((base & 0xffff) << 16) | (((base >> 16) & 0xff) << 32) | (access << 40) | (0xcf << 48) | ((base >> 24) << 56)
        struct.pack_into('<Q', wanted, 0x2000 + selector, descriptor)
    struct.pack_into('<HI', wanted, 0x2f00, 0x57, 0xc0002000)
    struct.pack_into('<HI', wanted, 0x2f10, 0x7ff, 0xc0003000)
    for vector in range(256):
        offset = 0x101000 if vector == 14 else 0x102000
        gate = (offset & 0xffff) | (8 << 16) | (0x8f << 40) | ((offset >> 16) << 48)
        struct.pack_into('<Q', wanted, 0x3000 + vector * 8, gate)
    for address, value in ((0x1000, 0x4003), (0x1004, 0x8007), (0x1c00, 0x4003)):
        struct.pack_into('<I', wanted, address, value)
    for i in range(1024):
        struct.pack_into('<I', wanted, 0x4000 + i * 4, i * 0x1000 | 3)
    assert raw == wanted, 'descriptor/table image mismatch'
    def walk(linear):
        pde = struct.unpack_from('<I', raw, 0x1000 + (linear >> 22) * 4)[0]
        assert pde & 1 and not pde & 0x80
        pte = struct.unpack_from('<I', raw, (pde & ~0xfff) + ((linear >> 12) & 0x3ff) * 4)[0]
        return None if not pte & 1 else (pte & ~0xfff) + (linear & 0xfff)
    for physical in (0x100000, 0x101000, 0x102000, 0x2000, 0x3000, 0x17ffec, 0x17fff8, 0x190000, 0x198000):
        assert walk(0xc0000000 + physical) == physical
    assert walk(0x600100) is None


def code_check(raw, row):
    fixture_check(raw, row)
    start = row['labels']['store']
    initial = list(CS.disasm(raw[:row['code_lengths']['program']], 0x100000))
    jump = next(i for i in initial if i.mnemonic == 'ljmp')
    assert jump.operands[0].imm == 8
    assert row['labels']['high'] == jump.operands[1].imm == jump.address + jump.size
    assert row['labels']['store'] == row['labels']['fault'] + 5
    assert raw[start - 0x100000:start - 0x100000 + 3] == bytes.fromhex('648819')
    helper = list(CS.disasm(raw[row['labels']['fault'] - 0x100000:row['code_lengths']['program']], row['labels']['fault']))
    assert [(i.mnemonic, i.op_str) for i in helper] == [
        ('mov', 'ecx, 0x600100'), ('mov', 'byte ptr fs:[ecx], bl'), ('pushfd', ''), ('pop', 'eax'),
        ('mov', 'dword ptr [0x198004], eax'), ('ret', '')]
    handler = list(CS.disasm(raw[0x1000:0x1000 + row['code_lengths']['handler']], 0x101000))
    expected = [('pushal',''),('pushfd',''),('pop','eax'),('mov','edi, dword ptr [0x198000]'),
        ('mov','dword ptr [edi + 0x18], eax'),('mov','dword ptr [edi], 0xe'),('lea','eax, [esp + 0x20]'),
        ('mov','dword ptr [edi + 4], eax'),('mov','eax, cr2'),('mov','dword ptr [edi + 0x1c], eax'),
        ('lea','esi, [esp + 0x20]'),('lea','edi, [edi + 8]'),('mov','ecx, 4'),('cld',''),
        ('rep movsd','dword ptr es:[edi], dword ptr [esi]'),('lea','edi, [edi + 8]'),
        ('mov','dword ptr [0x198000], edi'),('mov','dword ptr [0x8800], 0x200007'),
        ('popal',''),('add','esp, 4'),('iretd','')]
    assert [(i.mnemonic,i.op_str) for i in handler] == expected, 'handler source/read/frame semantics changed'
    assert handler[-1].bytes == bytes.fromhex('cf')
    program = list(CS.disasm(raw[:row['code_lengths']['program']], 0x100000))
    assert sum(i.size for i in program) == row['code_lengths']['program']
    assert [i.operands[0].imm for i in program if i.mnemonic == 'call'] == [row['labels']['fault']] * 2
    assert [(i.bytes.hex(), i.op_str) for i in program if i.mnemonic == 'invlpg'] == [('640f0139','byte ptr fs:[ecx]')]
    assert [i.operands[0].imm for i in program if i.mnemonic == 'push'] == [row['flags']] * 2
    assert [i.operands[1].imm for i in program if i.mnemonic == 'mov' and i.op_str.startswith('ebx,')] == [0xe4, 0xf5]
    assert not any(i.mnemonic in ('int', 'int3', 'into') for i in program + handler)
    # CPU's frame lies above all handler scratch writes. REP copies, never edits it.
    esp = 0x180000 - 4 - 16
    pushad_sp = esp - 8 * 4
    pushfd_scratch = pushad_sp - 4
    assert pushfd_scratch + 4 <= pushad_sp < esp
    assert pushad_sp + 32 == esp and esp + 12 == 0x17fff8


def check(row, directory):
    assert row['geometry'] == GEOMETRY and row['flags'] in (2, 0x202, 0x402, 0x602)
    assert row['returncode'] == 33 and row['stdout'] == row['stderr'] == ''
    assert row['strict_contract_passed'] is False and row['strict_failure'].startswith('AssertionError(')
    assert row['observations'] is None
    provenance_check(row, directory)
    for name, expected in row['hashes'].items():
        assert hashlib.sha256((directory / name).read_bytes()).hexdigest() == expected, name
    table_check((directory / 'tables.bin').read_bytes())
    bios_check((directory / 'bios.bin').read_bytes())
    code_check((directory / 'code.bin').read_bytes(), row)
    assert (directory / 'data.bin').read_bytes() == bytes([0x55]) * 0x1000
    raw = bytes.fromhex(row['raw_output_hex'])
    assert raw == (directory / 'output.bin').read_bytes() and len(raw) == 96
    log = (directory / 'qemu.log').read_text()
    pattern = r'^\s*\d+: v=([0-9a-f]+) e=([0-9a-f]+) i=(\d+) cpl=(\d+) IP=([0-9a-f]+):([0-9a-f]+) pc=([0-9a-f]+) SP=([0-9a-f]+):([0-9a-f]+) CR2=([0-9a-f]+)$'
    events = [[int(v, 16) for v in m] for m in re.findall(pattern, log, re.M)]
    store = row['labels']['store']
    assert events == [[14,2,0,0,8,store,0xc0000000 + store,0x10,0x17fffc,0x600100]] * 2
    assert re.findall(r'check_exception old: (\S+) new (\S+)', log) == [('0xffffffff','0xe')] * 2
    assert 'Triple fault' not in log
    event_blocks = re.split(r'^\s*\d+: v=', log, flags=re.M)[1:]
    for block in event_blocks:
        eip, eflags = re.search(r'EIP=([0-9a-f]+) EFL=([0-9a-f]+)', block).groups()
        assert int(eip,16) == store and int(eflags,16) == row['flags']
        for name, selector, base in (('CS',8,0xc0000000),('DS',0x10,0xc0000000),('ES',0x10,0xc0000000),('SS',0x10,0xc0000000),('FS',0x50,0),('GS',0x50,0)):
            match = re.search(r'^' + name + r'\s*=([0-9a-f]+) ([0-9a-f]+)', block, re.M)
            assert tuple(int(v,16) for v in match.groups()) == (selector,base)
        assert 'GDT=     c0002000 00000057' in block and 'IDT=     c0003000 000007ff' in block
        assert 'CR0=80000011 CR2=00600100 CR3=00001000 CR4=00000000' in block
    frames, retries = [], []
    for i,payload in enumerate((0xe4,0xf5)):
        frame = list(struct.unpack_from('<8I',raw,i*32))
        wanted = [14,0x180000-4-16,2,store,8,row['flags'],row['flags'],0x600100]
        assert frame == wanted, 'observed frame diagnostic differs'
        required_rf_flags = row['flags'] | (1 << 16)
        assert frame[5] != required_rf_flags and frame[5] & (1 << 16) == 0
        result = list(struct.unpack_from('<4I',raw,64+i*16))
        expected_window = int.from_bytes(bytes((0x55,payload,0x55,0x55)),'little')
        assert result == [expected_window,row['flags'],0x200067,0x180000]
        frames.append({'observed_saved_flags':frame[5], 'required_saved_flags':required_rf_flags,'rf_contract_passed':False})
        retries.append({'sentinel_window':result[0],'pte':result[2],'esp':result[3]})
    return {'flags':row['flags'],'vectors':[e[0] for e in events],'frames':frames,'retries':retries,
            'diagnostic_record_consistent':True,'strict_RF_contract_passed':False}


def main():
    data = json.loads((HERE / 'native-probe.json').read_text())
    assert len(data['cases']) == 4 and {r['flags'] for r in data['cases']} == {2,0x202,0x402,0x602}
    for key in ('openstep_handler_executed','actual_gc_fault_reentry_verified','physical_cpu_verified','whole_goal_complete','all_strict_contracts_passed'):
        assert data[key] is False
    assert hashlib.sha256(Path('/usr/bin/qemu-system-i386').read_bytes()).hexdigest() == data['qemu_sha256']
    results = [check(r,HERE / ('case-' + format(r['flags'],'x'))) for r in data['cases']]
    out = {'cases':results,'diagnostic_records_consistent':True,'RF_contract_passed':False,
        'openstep_handler_executed':False,'whole_goal_complete':False,
        'scope':'fixed ROM/code/table/record/command consistency audit; not independent execution provenance, complete CPU semantics, physical CPU or original handler verification'}
    (HERE / 'diagnostic-audit.json').write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps({'cases':len(results),'observed_faults':sum(len(r['vectors']) for r in results),'RF_contract_passed':False}))


if __name__ == '__main__':
    main()
