"""Reproduce diagnostic evidence without turning its RF failure into a pass."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

HERE=Path(__file__).resolve().parent
PRIOR=HERE.parent/'continuous-review-20260912-36'


def hash_files(paths):
    return {str(p.relative_to(HERE)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}


def preservation():
    checkpoint=json.loads((PRIOR/'checkpoint.json').read_text())
    for row in checkpoint['files']:
        p=PRIOR/row['name']
        assert p.stat().st_size==row['size'] and hashlib.sha256(p.read_bytes()).hexdigest()==row['sha256'],p
    return hashlib.sha256((PRIOR/'checkpoint.json').read_bytes()).hexdigest()


def main():
    paths=sorted(p for p in HERE.glob('case-*/*') if p.is_file())
    paths += [HERE/n for n in ('native-probe.json','diagnostic-audit.json','negative-controls.json')]
    before,prior=hash_files(paths),preservation()
    commands=[]
    for name,args,expected in (('native_probe.py',['--collect-diagnostics'],0),('audit_native.py',[],0),
                               ('test_native.py',[],0),('native_probe.py',['--single'],1)):
        result=subprocess.run([sys.executable,'-B',str(HERE/name),*args],cwd=HERE,text=True,capture_output=True,timeout=60)
        commands.append({'script':name,'args':args,'returncode':result.returncode,'stdout':result.stdout,'stderr':result.stderr})
        assert result.returncode==expected,commands[-1]
        if expected:
            assert 'saved_eflags' in result.stderr and 'AssertionError' in result.stderr
    after=hash_files(paths)
    assert before==after and preservation()==prior
    out={'before':before,'after':after,'equal':True,'commands':commands,'prior_checkpoint_sha256':prior,
         'strict_RF_command_still_fails':True,'RF_contract_passed':False,'whole_goal_complete':False}
    (HERE/'reproducibility.json').write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps({'reproduced_files':len(paths),'strict_RF_command_still_fails':True}))


if __name__ == '__main__':
    main()
