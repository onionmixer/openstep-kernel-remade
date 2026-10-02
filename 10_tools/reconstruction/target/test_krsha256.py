#!/usr/bin/env python3
"""Fixtures and checks for krsha256 (plan section 11 A1 / 11.1 QS2).

usage:
  test_krsha256.py make DIR            write fixtures into DIR (refuses an existing DIR)
  test_krsha256.py check DIR OUTFILE   compare a krsha256 run's output with hashlib

The run to produce OUTFILE (on the host or the OPENSTEP target), from DIR:
  krsha256 <every fixture in CASES order> > OUTFILE 2> OUTFILE.err ; echo $? > OUTFILE.rc
  krsha256 missing.bin                  > OUTFILE.missing 2>&1 ; echo $? > OUTFILE.missing.rc
  krsha256 big-over-limit.bin           > OUTFILE.big 2>&1     ; echo $? > OUTFILE.big.rc
(`commands DIR BINARY OUTFILE` prints exactly these lines for sh.)
"""
import hashlib, os, random, sys

LIMIT = 268435456          # KR_MAXSIZE in krsha256.c


def fixtures():
    nist448 = b'abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq'
    rnd = random.Random(20261001)
    allbytes = bytes(range(256)) * 300 + bytes(range(255, -1, -1)) * 3
    cases = [
        ('empty.bin', b''),
        ('abc.bin', b'abc'),
        ('nist448.bin', nist448),
        ('million_a.bin', b'a' * 1000000),
    ]
    for n in (55, 56, 63, 64, 65, 119, 120, 127, 128, 1009, 8191, 8192, 8193):
        cases.append(('len%d.bin' % n, bytes(rnd.randrange(256) for _ in range(n))))
    cases.append(('allbytes.bin', allbytes))
    cases.append(('random_1m.bin', bytes(rnd.randrange(256) for _ in range(1048576 + 777))))
    return cases


KNOWN = {   # published SHA-256 test vectors (FIPS 180-2 examples)
    'empty.bin': 'e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855',
    'abc.bin': 'ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad',
    'nist448.bin': '248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1',
    'million_a.bin': 'cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0',
}


def order():
    names = [n for n, _ in fixtures()]
    # several files in one run, with an empty file between non-empty ones
    return names + ['abc.bin', 'empty.bin', 'len65.bin']


def make(d):
    if os.path.exists(d):
        sys.exit('refusing: %s exists' % d)
    os.makedirs(d)
    for name, data in fixtures():
        with open(os.path.join(d, name), 'wb') as f:
            f.write(data)
    with open(os.path.join(d, 'big-over-limit.bin'), 'wb') as f:
        f.truncate(LIMIT + 1)              # sparse: reads as zeros
    with open(os.path.join(d, 'ORDER'), 'w') as f:
        f.write('\n'.join(order()) + '\n')
    print('fixtures in', d, len(fixtures()), 'files + big-over-limit.bin')


def commands(d, binary, out):
    files = ' '.join(order())
    print('cd %s' % d)
    print('%s %s > %s 2> %s.err ; echo $? > %s.rc' % (binary, files, out, out, out))
    print('%s missing.bin > %s.missing 2>&1 ; echo $? > %s.missing.rc' % (binary, out, out))
    print('%s big-over-limit.bin > %s.big 2>&1 ; echo $? > %s.big.rc' % (binary, out, out))


def check(d, out):
    fails = []
    for name, want in KNOWN.items():            # the fixture generator itself
        got = hashlib.sha256(open(os.path.join(d, name), 'rb').read()).hexdigest()
        if got != want:
            fails.append('fixture %s does not match the published vector' % name)
    lines = open(out).read().splitlines()
    names = order()
    if len(lines) != len(names):
        fails.append('line count %d != %d' % (len(lines), len(names)))
    for name, line in zip(names, lines):
        data = open(os.path.join(d, name), 'rb').read()
        parts = line.split(' ')
        if len(parts) != 3 or parts[2] != name:
            fails.append('bad line for %s: %r' % (name, line))
            continue
        if parts[0] != hashlib.sha256(data).hexdigest():
            fails.append('digest mismatch %s' % name)
        if parts[1] != str(len(data)):
            fails.append('size mismatch %s: %s != %d' % (name, parts[1], len(data)))
    rc = open(out + '.rc').read().strip()
    if rc != '0':
        fails.append('main run exit %s' % rc)
    if open(out + '.err').read():
        fails.append('main run wrote to stderr')
    for tag in ('missing', 'big'):
        rc = open('%s.%s.rc' % (out, tag)).read().strip()
        text = open('%s.%s' % (out, tag)).read()
        if rc == '0':
            fails.append('%s: exit 0, expected failure' % tag)
        if any(len(t.split(' ')) == 3 and len(t.split(' ')[0]) == 64 for t in text.splitlines()):
            fails.append('%s: printed a digest line' % tag)
    print('checked %d digests + missing + over-limit: %s' % (len(names), 'PASS' if not fails else 'FAIL'))
    for f in fails:
        print('  ', f)
    return not fails


if __name__ == '__main__':
    a = sys.argv[1:]
    if a[:1] == ['make'] and len(a) == 2:
        make(a[1])
    elif a[:1] == ['commands'] and len(a) == 4:
        commands(a[1], a[2], a[3])
    elif a[:1] == ['check'] and len(a) == 3:
        sys.exit(0 if check(a[1], a[2]) else 1)
    else:
        sys.exit(__doc__)
