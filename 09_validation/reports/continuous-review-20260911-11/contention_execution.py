"""Original global lock acquisition windows under deterministic contention."""
import collections
import json
from wait_execution import HERE, R, D, U, X


def case(site, mode):
    ins = R.function_instructions(int(site['owner'], 16))
    condition = ins[int(site['condition']['address'], 16)]
    branch = ins[int(site['branch']['address'], 16)]
    start = ins[int(site['load']['address'], 16)] if site['kind'] == 'register_only' else condition
    exchange = ins[int(next(i['address'] for i in site['following_window'] if i['mnemonic'] == 'xchg'), 16)]
    assert exchange.operands[0].type == R.X86_OP_MEM
    mem = exchange.operands[0].mem
    assert not mem.base and not mem.index and not mem.segment
    lock = mem.disp
    cursor = exchange.address + exchange.size
    following = []
    while len(following) < 6:
        op = ins[cursor]
        following.append(op)
        if op.mnemonic == 'je':
            break
        cursor += op.size
    retry = following[-1]
    assert retry.mnemonic == 'je' and retry.operands[0].imm == start.address
    end = retry.address + retry.size
    uc, trace, _ = D.fixture(0x603, 'unlocked', 'hit')
    D.put(uc, lock, 0)
    visits = collections.Counter()
    events = []

    def hook(engine, pc, size, unused):
        visits[pc] += 1
        if pc == exchange.address and visits[pc] == 1 and mode != 'no_race':
            D.put(engine, lock, 1)
            events.append({'address': hex(pc), 'kind': 'competitor_acquires_before_xchg'})
        if pc == retry.address and visits[pc] == 1 and mode == 'release_before_retry_load':
            D.put(engine, lock, 0)
            events.append({'address': hex(pc), 'kind': 'competitor_releases_before_reload'})
        if pc == branch.address and visits[pc] == 2 and mode == 'release_after_retry_load':
            D.put(engine, lock, 0)
            events.append({'address': hex(pc), 'kind': 'competitor_releases_after_reload'})

    uc.hook_add(U.UC_HOOK_CODE, hook)
    uc.emu_start(start.address, end, timeout=1000000, count=80)
    escaped = uc.reg_read(X.UC_X86_REG_EIP) == end
    expected = mode in ('no_race', 'release_before_retry_load') or (mode == 'release_after_retry_load' and site['kind'] == 'memory_poll')
    assert escaped == expected, (site, mode)
    assert visits[retry.address] >= 1
    assert visits[exchange.address] == (2 if expected and mode != 'no_race' else 1)
    assert all(bytes(uc.mem_read(addr, ins[addr].size)) == ins[addr].bytes for addr in set(trace))
    return {'site': site['branch']['address'], 'owner': site['owner'], 'kind': site['kind'], 'mode': mode,
            'retry_branch': hex(retry.address), 'retry_visits': visits[retry.address],
            'exchange_visits': visits[exchange.address], 'acquired_window_exit': escaped,
            'lock_final': D.words(uc, lock, 1)[0], 'events': events, 'trace': [hex(a) for a in trace]}


def main():
    scan = json.loads((HERE / 'scan.json').read_text())
    selected = {'0010ca7f', '0015ec12', '001ca96f', '001cae3f'}
    rows = [case(s, mode) for s in scan['sites'] if s['branch']['address'] in selected
            for mode in ('no_race', 'keep_busy', 'release_before_retry_load', 'release_after_retry_load')]
    assert {r['site'] for r in rows} == selected
    summary = {'sites': len(selected), 'cases': len(rows), 'failures': 0,
               'note': 'Actual xchg/retry instructions, synthetic competitor writes; no physical concurrency or full function run.'}
    (HERE / 'contention-execution.json').write_text(json.dumps({'summary': summary, 'cases': rows}, indent=2) + '\n')
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
