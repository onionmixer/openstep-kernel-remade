"""Re-execute the same bounded cases, preserving original inputs and prior reports."""
import hashlib
import json
import subprocess
import sys
import inputs as I


def hashes(names):
    return {name:hashlib.sha256((I.HERE/name).read_bytes()).hexdigest() for name in names}


def main():
    names=('aging-cases.json','aging-summary.json','aging-audit.json','negative-controls.json','source-basis.json')
    before=hashes(names);prior=I.preserve();commands=[]
    for script in ('verify_basis.py','run_aging.py','audit_aging.py','test_aging.py'):
        r=subprocess.run([sys.executable,'-B',str(I.HERE/script)],cwd=I.HERE,
                         capture_output=True,text=True,timeout=55)
        commands.append({'script':script,'returncode':r.returncode,'stdout':r.stdout,'stderr':r.stderr})
        assert r.returncode==0,commands[-1]
    after=hashes(names)
    assert before==after and I.preserve()==prior
    (I.HERE/'reproducibility.json').write_text(json.dumps({'before':before,'after':after,'equal':True,
        'commands':commands,'prior_checkpoint_sha256':prior,'whole_goal_complete':False,
        'scope':'same original bytes and Unicorn backend; includes expected unmapped failures, not native equivalence'},indent=2)+'\n')
    print(json.dumps({'reproduced_files':len(names),'all_equal':True}))


if __name__=='__main__':main()
