#!/usr/bin/env python3
"""Extract verified Darwin references into a new directory; preserve source archives."""
import hashlib
import json
import tarfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

def sha(path):
    h = hashlib.sha256()
    with path.open('rb') as f:
        for b in iter(lambda: f.read(1024*1024), b''):
            h.update(b)
    return h.hexdigest()

def main():
    manifest = json.loads((ROOT/'01_resources/manifests/acquisition.json').read_text())
    destination = ROOT/'01_resources/upstream/darwin01'
    destination.mkdir()  # Refuse to merge with or overwrite an existing tree.
    records = []
    for row in manifest['sources']:
        if row['kind'] != 'archive':
            continue
        archive = ROOT/row['path']
        assert row['status'] == 'acquired' and sha(archive) == row['sha256']
        with tarfile.open(archive, 'r:*') as tf:
            members = tf.getmembers()
            # Reject special files and escaping paths; do not execute source build scripts.
            for member in members:
                tarfile.data_filter(member, str(destination))
            tf.extractall(destination, filter='data')
        records.append({'source': row['id'], 'sha256':row['sha256'], 'members':len(members)})
    files=[]
    for path in sorted(destination.rglob('*')):
        if path.is_file():
            files.append({'path':str(path.relative_to(destination)), 'size':path.stat().st_size,'sha256':sha(path)})
    (ROOT/'01_resources/manifests/darwin-extraction.json').write_text(json.dumps({'sources':records,'files':files},indent=2)+'\n')
    for row in manifest['sources']:
        if row['kind']=='archive':
            row['extracted']=True
    (ROOT/'01_resources/manifests/acquisition.json').write_text(json.dumps(manifest,indent=2,ensure_ascii=False)+'\n')
    print(f'Extracted {len(records)} archives, hashed {len(files)} files')

if __name__=='__main__':
    main()
