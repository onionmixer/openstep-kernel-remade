#!/usr/bin/env python3
"""Gate before booting the analysis-baseline kernel on the i386 VM.  Read-only.

usage: verify_i386_kernel_add.py DISK [--report FILE]

Passes (exit 0) only if all hold on the i386 VM disk (QEMU must be stopped):
  * label and UFS structure are consistent (installed_kernel_identity.UFS);
  * whole-file-system audit: no duplicate fragment references, no referenced
    fragment marked free, every reachable inode marked used, every cylinder
    group's maps equal its cg_cs, no per-inode error;
  * /mach_kernel.183.34.4 is a regular file equal to 03_original/x86 (SHA-256);
  * /mach_kernel.183.34.4.pic equals make_i386_pic_kernel.py's output (12 bytes
    differ from the baseline, for QEMU's PIC);
  * /mach_kernel is unchanged (the 1997 kernel with the PIC fix).
Plan: 02_plan/EMULATION_PLATFORM_PLAN.md, "i386 VM 에 분석 기준 커널 추가 계획".
"""
import argparse, hashlib, importlib.util, json, os, sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..'))
_spec = importlib.util.spec_from_file_location('ik', os.path.join(HERE, 'installed_kernel_identity.py'))
ik = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(ik)

NEW_NAME = 'mach_kernel.183.34.4'
BASELINE = '03_original/x86/binaries/mach_kernel'
OLD_NAME = 'mach_kernel'
PIC_NAME = 'mach_kernel.183.34.4.pic'
PIC_SHA256 = '304cb696924f4e389c8365371d386bfa8ea0fa56ea8aac4bb4fc546dc735250f'   # make_i386_pic_kernel.py
OLD_SHA256 = '00e498922d59204ae32bc858eab14327b86cf5fa56c4ef4761a3a1a54eb6beb0'   # 09_validation/runtime/installed-kernel-identity-20261001.json


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('disk')
    ap.add_argument('--report')
    a = ap.parse_args()
    base = open(os.path.join(REPO, BASELINE), 'rb').read()
    checks = {}
    img = ik.Image(a.disk)
    fs = ik.UFS(img, ik.read_label(img))
    au = ik.audit(fs)
    checks['audit_clean'] = (au['duplicate_refs'] == 0 and au['referenced_but_free'] == 0
                             and au['reachable_inode_not_iused'] == 0 and au['error_count'] == 0)
    root = {n: i for i, n in fs.readdir(fs.inode(ik.ROOTINO))}
    files = {}
    for name, want in ((NEW_NAME, hashlib.sha256(base).hexdigest()), (PIC_NAME, PIC_SHA256),
                       (OLD_NAME, OLD_SHA256)):
        rec = dict(present=name in root, expected_sha256=want)
        if rec['present']:
            node = fs.inode(root[name])
            rec.update(ino=node['ino'], mode='%o' % node['mode'], nlink=node['nlink'])
            if node['mode'] & ik.S_IFMT == ik.S_IFREG:
                data, _ = fs.read_regular(node)
                rec.update(size=len(data), sha256=hashlib.sha256(data).hexdigest(),
                           versions=ik.versions(data))
        rec['ok'] = rec.get('sha256') == want and rec.get('mode') == '100444'
        files['/' + name] = rec
        checks['/%s matches' % name] = rec['ok']
    out = dict(disk=os.path.basename(a.disk), audit=au, files=files, checks=checks,
               passed=all(checks.values()))
    text = json.dumps(out, indent=1, ensure_ascii=False)
    print(text)
    if a.report:
        with open(a.report, 'w') as o:
            o.write(text + '\n')
    sys.exit(0 if out['passed'] else 1)


if __name__ == '__main__':
    try:
        main()
    except ik.Bad as e:
        sys.exit('STOP: %s' % e)
