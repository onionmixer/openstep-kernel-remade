#!/usr/bin/env python3
"""Differential check for the l1_compare.sect_of change (plan 71): runs compare() on every object named in
09_validation/reconstruction/*-l1-*.json with the old predicate (zero-size section = 1 byte) and with the
current l1_compare.sect_of, same inputs (placements_from_image, by_symbol = all, ranges None), and writes the
objects whose full results differ.  Usage: check_sectof_diff.py OUT.json (run from the repository root)."""
import json,glob,sys,os,hashlib
sys.path.insert(0,'10_tools/reconstruction'); import l1_compare as L
NEWFILE=L.sect_of
def OLD(obj, addr):
    for s in obj['sections']:
        if s['addr'] <= addr < s['addr'] + max(s['size'], 1):
            return s['index']
    return None
img=L.Image('03_original/x86/binaries/mach_kernel')
objs=sorted({json.load(open(f))['object'] for f in glob.glob('09_validation/reconstruction/*-l1-*.json')})
def run(fn,o):
    L.sect_of=fn
    pl=L.placements_from_image(img,o); bs=set(pl)
    r=L.compare(img,o,pl,None,bs)
    return json.loads(json.dumps(dict(pl={str(k):v for k,v in pl.items()},r=r),default=str,sort_keys=True))
out=[]; nd=0
for o in objs:
    try: a=run(OLD,o); b=run(NEWFILE,o)
    except Exception as e: out.append(dict(object=o,error=repr(e))); continue
    if a!=b:
        nd+=1
        fa={','.join(f['names']):f['verdict'] for f in a['r']['functions']}; fb={','.join(f['names']):f['verdict'] for f in b['r']['functions']}
        out.append(dict(object=o,verdict=[a['r']['object_verdict'],b['r']['object_verdict']],functions={k:[fa.get(k),fb.get(k)] for k in set(fa)|set(fb) if fa.get(k)!=fb.get(k)},pl_changed=a['pl']!=b['pl'],sections={k:[a['r']['sections'].get(k),b['r']['sections'].get(k)] for k in set(a['r']['sections'])|set(b['r']['sections']) if a['r']['sections'].get(k)!=b['r']['sections'].get(k)}))
L.sect_of=NEWFILE
res=dict(objects=len(objs),differing=nd,errors=sum('error' in x for x in out),details=out)
json.dump(res,open(sys.argv[1],'w'),indent=1,default=str)
print(len(objs),'objects; differing',nd,'errors',res['errors'])
for x in out:
    if 'error' in x: print('ERR',x['object'],x['error'][:120])
    else: print(x['object'],x['verdict'],x['functions'],list(x['sections']))
