#!/usr/bin/env python3
"""Index preserved per-function MCP responses without hiding per-database failures."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'05_ida/exports/x86'

def main():
    index={};counts={}
    for directory, database in (('full-pass1','ps2 snapshot'),('alternate-db','matrox snapshot')):
        rows=[(r,p) for p in sorted((OUT/directory).glob('batch-*.json')) for r in json.loads(p.read_text())]
        counts[directory]={'attempts':len(rows),'successful':sum(bool(r.get('code')) for r,p in rows)}
        for row,path in rows:
            key=hex(int(row['requested_address'],16))
            entry=index.setdefault(key,{'address':key,'attempts':[]})
            entry['attempts'].append({'database':database,'raw_response':str(path.relative_to(ROOT)),
                                      'success':bool(row.get('code')),'error':row.get('error')})
            if row.get('code') and not entry.get('pseudocode'):
                stem=f'{int(key,16):08x}'
                target=OUT/'functions'/f'{stem}.c';target.parent.mkdir(exist_ok=True)
                target.write_text('/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.\n'
                                  f' * Database: {database}; requested VA: {key}. */\n'+row['code']+'\n')
                entry['pseudocode']=str(target.relative_to(ROOT))
                entry['sha256']=hashlib.sha256(target.read_bytes()).hexdigest()
    failures=[v for v in index.values() if not v.get('pseudocode')]
    manifest={'by_database':counts,'unique_requested_addresses':len(index),
              'successful_addresses':len(index)-len(failures),'failed_addresses':len(failures),
              'enumeration_basis':'Ghidra full-pass1 entries plus binary-confirmed pass2 repairs',
              'limitations':['IDA function enumeration and assembly export MCP calls were denied by approval policy.',
                             'These are per-address decompile results, not an exhaustive independent IDA function inventory.',
                             'DB input paths matched the recorded original files; internal byte patches were not independently audited.'],
              'functions':list(index.values())}
    (OUT/'index.json').write_text(json.dumps(manifest,indent=2)+'\n')
    (OUT/'failures.json').write_text(json.dumps(failures,indent=2)+'\n')
    print({k:v for k,v in manifest.items() if k!='functions'})

if __name__=='__main__':main()
