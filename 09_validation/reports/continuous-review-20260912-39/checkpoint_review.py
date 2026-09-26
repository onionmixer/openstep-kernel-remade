"""Current scoped evidence, source hashes and prior checkpoint preservation."""
import hashlib
import json
from pathlib import Path
import audit_aging as A
import inputs as I


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    prior=I.preserve()
    rows=json.loads((I.HERE/'aging-cases.json').read_text())
    assert [r['input'] for r in rows]==I.matrix(False)
    models=[A.check(r) for r in rows]
    basis=json.loads((I.HERE/'source-basis.json').read_text())
    for item in basis['inputs']:
        path=I.ROOT/item['path']
        assert path.stat().st_size==item['size'] and sha(path)==item['sha256'],path
    repro=json.loads((I.HERE/'reproducibility.json').read_text())
    assert repro['equal'] and repro['before']==repro['after']
    for name,value in repro['after'].items():assert sha(I.HERE/name)==value,name
    for command in repro['commands']:assert command['returncode']==0
    assert repro['prior_checkpoint_sha256']==basis['prior_checkpoint_sha256']==prior
    examples=json.loads((I.HERE/'boundary-examples.json').read_text())
    lookup={json.dumps(r['input'],sort_keys=True):(r,m) for r,m in zip(rows,models)}
    for item in examples:
        row,model=lookup[json.dumps(item['input'],sort_keys=True)]
        assert item['model']==model and item['outcome']==row['outcome']
        assert item['after']=={k:row['after'][k] for k in ('age','last','pde','second_pde')}
        assert item['threshold_offset_hex']==hex(model['address'])
        assert item['hypothetical_high_DS_linear']==hex((0xc0000000+model['address'])&A.MASK)
    entries=[]
    for path in sorted(I.HERE.rglob('*')):
        if path.is_file() and path.name!='checkpoint.json' and '__pycache__' not in path.parts:
            entries.append({'path':str(path.relative_to(I.HERE)),'size':path.stat().st_size,'sha256':sha(path)})
    result={'files':entries,'cases_checked':len(rows),'examples_checked':len(examples),
        'prior_checkpoint_sha256':prior,'source_input_hashes_rechecked':True,
        'original_remove_executed':False,'full_CPU_semantics_verified':False,
        'report_finalized':False,'whole_goal_complete':False}
    (I.HERE/'checkpoint.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'checkpoint_files':len(entries),'cases_checked':len(rows),'examples_checked':len(examples)}))


if __name__=='__main__':main()
