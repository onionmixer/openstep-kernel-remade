"""Close raw-audit assignment for every no-exit terminal candidate without semantic claims."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPORT = ROOT / '09_validation/reports/multiarch-input-20260921'


def read_tsv(path):
    with path.open(encoding='utf-8', newline='') as handle:
        return list(csv.DictReader(handle, delimiter='\t'))


def load_json(name):
    return json.loads((REPORT / name).read_text())


def main():
    direct_branch = load_json('noexit-terminal-direct-branch-audit.json')['targets']
    transfer = load_json('noexit-terminal-jump-call-transfer-audit.json')['targets']
    audits = {
        'm68k': {
            'terminal_bsr': load_json('m68k-noexit-terminal-bsr-fallthrough-audit.json'),
            'terminal_rte': load_json('m68k-noexit-rte-window-audit.json'),
            'terminal_jsr': load_json('m68k-noexit-terminal-jsr-fallthrough-audit.json'),
            'remaining': load_json('m68k-remaining-noexit-terminal-window-audit.json'),
        },
        'sparc': {
            'restore_return': load_json('sparc-noexit-restore-return-window-audit.json'),
            'nop': load_json('sparc-noexit-nop-window-audit.json'),
            'illtrap': load_json('sparc-noexit-illtrap-terminal-audit.json'),
            'remaining': load_json('sparc-remaining-noexit-terminal-window-audit.json'),
        },
    }
    results = {}
    for architecture in ('m68k', 'sparc'):
        binary = (ROOT / '03_original' / architecture / 'binaries/mach_kernel').read_bytes()
        terminals = read_tsv(ROOT / '05_ida/exports' / architecture / 'noexit-candidate-terminal-items.tsv')
        assignments = Counter()
        unassigned = []
        for terminal in terminals:
            mnemonic = terminal['terminal_mnemonic']
            if architecture == 'm68k':
                if mnemonic in {'bra.l', 'bra.s', 'bra.w'}:
                    assignment = 'direct_branch'
                elif mnemonic == 'jmp':
                    assignment = 'terminal_jmp'
                elif mnemonic == 'bsr.l':
                    assignment = 'terminal_bsr'
                elif mnemonic == 'rte':
                    assignment = 'terminal_rte'
                elif mnemonic == 'jsr':
                    assignment = 'terminal_jsr'
                else:
                    assignment = 'remaining_window'
            else:
                if mnemonic == 'ba,a':
                    assignment = 'direct_branch'
                elif mnemonic == 'call':
                    assignment = 'terminal_call'
                elif mnemonic in {'restore', 'return'}:
                    assignment = 'restore_return'
                elif mnemonic == 'nop':
                    assignment = 'nop_window'
                elif mnemonic == 'illtrap':
                    assignment = 'illtrap'
                else:
                    assignment = 'remaining_window'
            if not assignment:
                unassigned.append(terminal)
            assignments[assignment] += 1
        if architecture == 'm68k':
            assert assignments == Counter({
                'direct_branch': direct_branch['m68k']['verified_terminal_direct_branch_count'],
                'terminal_jmp': transfer['m68k']['terminal_transfer_count'],
                'terminal_bsr': audits['m68k']['terminal_bsr']['terminal_bsr_long_count'],
                'terminal_rte': audits['m68k']['terminal_rte']['terminal_rte_candidate_count'],
                'terminal_jsr': audits['m68k']['terminal_jsr']['terminal_jsr_count'],
                'remaining_window': audits['m68k']['remaining']['remaining_terminal_window_count'],
            })
        else:
            assert assignments == Counter({
                'direct_branch': direct_branch['sparc']['verified_terminal_direct_branch_count'],
                'terminal_call': transfer['sparc']['terminal_transfer_count'],
                'restore_return': audits['sparc']['restore_return']['terminal_restore_or_return_count'],
                'nop_window': audits['sparc']['nop']['terminal_nop_count'],
                'illtrap': audits['sparc']['illtrap']['terminal_illtrap_candidate_count'],
                'remaining_window': audits['sparc']['remaining']['remaining_terminal_window_count'],
            })
        assert not unassigned
        results[architecture] = {
            'original_sha256_recomputed_with_python': hashlib.sha256(binary).hexdigest(),
            'noexit_terminal_candidate_count': len(terminals),
            'raw_audit_assignment_counts': dict(assignments),
            'unassigned_terminal_candidate_count': len(unassigned),
            'all_terminal_candidates_assigned_to_a_raw_audit': True,
        }
    output = {
        'schema': 1,
        'architectures': results,
        'interpretation_limit': ('assignment closure means each terminal candidate has raw encoding or bounded-window '
                                'evidence; it does not establish transfer semantics, path reachability, function '
                                'boundaries, calling convention, ABI, return behavior, or function behavior'),
    }
    (REPORT / 'noexit-terminal-raw-coverage-closure-audit.json').write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({architecture: {
        'noexit_terminal_candidate_count': data['noexit_terminal_candidate_count'],
        'unassigned_terminal_candidate_count': data['unassigned_terminal_candidate_count'],
    } for architecture, data in results.items()}))


if __name__ == '__main__':
    main()
