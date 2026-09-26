"""Original accounting compress versus a signed-32-bit Python instruction model."""
import importlib.util
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('fixtures', HERE.parent / 'continuous-review-20260911-06/dispatch_execution.py')
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)
R, U, X = D.R, D.U, D.X


def signed32(v):
    v &= 0xffffffff
    return v if v < 0x80000000 else v - 0x100000000


def model(t, ut):
    value = signed32(t << 6)
    if ut:
        quotient = abs(ut) // 0x3d09
        if ut < 0:
            quotient = -quotient
        value = signed32(value + quotient)
    exponent, rounding = 0, 0
    while value > 0x1fff:
        exponent += 1
        rounding = value & 4
        value >>= 3
    if rounding:
        value = signed32(value + 1)
        if value > 0x1fff:
            value >>= 3
            exponent += 1
    return (value + (exponent << 13)) & 0xffffffff


def main():
    rows = []
    seconds = [-2, -1, 0, 1, 127, 128, 129, 1023, 1024, 1025, 0x1ffffff, 0x2000000, 0x7fffffff]
    microseconds = [-0x80000000, -1, 0, 1, 15624, 15625, 999999, 1000000, 0x7fffffff]
    for t in seconds:
        for ut in microseconds:
            for seed in (0, 0x13579bdf, 0xffffffff):
                uc, trace, _ = D.fixture(0x600, 'unlocked', 'hit')
                D.put(uc, D.STACK, D.STOP, t & 0xffffffff, ut & 0xffffffff, seed, seed ^ 0xffffffff)
                uc.reg_write(X.UC_X86_REG_EBX, seed)
                uc.reg_write(X.UC_X86_REG_ESI, seed ^ 0xa5a5a5a5)
                reads = []

                def on_read(engine, access, address, size, value, unused):
                    if D.STACK + D.WORD <= address < D.STACK + D.WORD * 5:
                        reads.append({'address': hex(address), 'size': size})

                uc.hook_add(U.UC_HOOK_MEM_READ, on_read)
                D.run_to(uc, R.NAMES['_compress'], D.STOP)
                actual = uc.reg_read(X.UC_X86_REG_EAX)
                assert actual == model(t, ut)
                assert {r['address'] for r in reads} == {hex(D.STACK + D.WORD), hex(D.STACK + D.WORD * 2)}
                assert all(r['size'] == D.WORD for r in reads)
                assert uc.reg_read(X.UC_X86_REG_EBX) == seed
                assert uc.reg_read(X.UC_X86_REG_ESI) == seed ^ 0xa5a5a5a5
                assert uc.reg_read(X.UC_X86_REG_ESP) == D.STACK + D.WORD
                for n in ('edi', 'ebp'):
                    reg, value = D.REGS[n]
                    assert uc.reg_read(reg) == value
                rows.append({'seconds': t, 'microseconds': ut, 'ambient_seed': hex(seed),
                             'result': hex(actual), 'argument_reads': reads, 'trace': [hex(a) for a in trace]})
    result = {'count': len(rows), 'tests': rows, 'unicorn_version': U.__version__,
              'scope': 'Original function only; synthetic stack, no mocks. Edge/overflow cases model machine instructions, not undefined signed-overflow C behavior or valid accounting inputs.'}
    (HERE / 'compress-execution.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'cases': len(rows), 'mismatches': []}, indent=2))


if __name__ == '__main__':
    main()
