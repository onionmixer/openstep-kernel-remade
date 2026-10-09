#!/usr/bin/env python3
"""m0_abi_probe.py -- plan 412 (M0-3): check the m68k ABI probe runs and record what they show.

  python3 10_tools/reconstruction/m0_abi_probe.py RUN1 RUN2 OTOOL_DIR TOOLS_PRE TOOLS_POST REPORT.json

RUN1, RUN2   published kr_run directories (08_build/runs/m0p412-abi1, -abi2), same inputs
OTOOL_DIR    `otool -tv` listings of RUN1's m68k objects, taken on the real machine (<stem>.txt)
TOOLS_PRE/POST  krsha256 lines of the toolchain files before and after the runs
Checks (412.1): a determinism, b llvm-objdump cross-check (STAB-only differences classified),
c layout tables and value instances read twice (macho_obj and llvm-objdump hex), d disassembly
of compiler -S vs otool vs capstone, e ObjC sections, f .s preprocessing, g MIG output,
h designated symbols present, i tool hashes.  Every number is computed here.
"""
import sys, os, re, json, hashlib, subprocess, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import check_macho_obj

LLVM = 'llvm-objdump-14'
CROSS = '09_validation/reconstruction/m0-toolchain-cross-20261009.json'
I386_LAYOUT = '09_validation/reconstruction/toolchain/c-layout-probe-20261001.json'
LAYOUT_KEYS = None     # taken from the 2026-10-01 record (same order as c_layout.c)
ABI_KEYS = (['marker', 'char_is_signed', 'sizeof long long', 'sizeof long double', 'sizeof int(*)(void)'] +
            ['alignof ' + t for t in ('char', 'short', 'int', 'long', 'float', 'double', 'char*', 'long long',
                                      'long double', 'struct{char}', 'struct{char;int;short}', 'union{char;short}')] +
            ['sizeof struct{char}', 'sizeof struct{char[3]}', 'sizeof struct{short;char}', 'sizeof union{char;short}',
             'sizeof struct{char;struct{char}}', 'off .in',
             'sizeof struct{char;union{char;short};char}', 'off .u', 'off .d',
             'sizeof struct{char[3]}[2]', 'sizeof struct{short;char}[3]'] +
            ['off {char;%s}' % t for t in ('short', 'int', 'long', 'float', 'double', 'char*', 'long long',
                                            'long double', 'int(*)(void)')] +
            ['sizeof {char;double}', 'sizeof {char;long long}', 'sizeof {char;long double}',
             'sizeof bf{u:3,u:5,u:9;char}', 'off bf.x', 'sizeof bf{u:12,u:12,u:12}',
             'sizeof bf{char;int:4}', 'sizeof bf{u:4;int:0;u:4}', 'sizeof bf{ushort:4,ushort:4}', 'sizeof bf{char;u:9}',
             'sizeof enum{0,1}', 'sizeof enum{-1,1}', 'sizeof enum{0x7fffffff}', 'enum{-1,1} signed', 'end'])
INSTANCES = ['_kr_v_bfa', '_kr_v_bfb', '_kr_v_bfc', '_kr_v_bfd', '_kr_v_bfe', '_kr_v_bff', '_kr_v_s1', '_kr_v_od',
             '_kr_v_ll', '_kr_v_ld', '_kr_v_f']
GLOBALS = ['_kr_g_c1', '_kr_g_i', '_kr_g_c2', '_kr_g_s', '_kr_g_c3', '_kr_g_d', '_kr_g_c4', '_kr_g_sc', '_kr_g_c5']
# c: field hypotheses for the value instances: (width, value, signed, bit offset m68k, bit offset i386).
# m68k is read MSB-first from a big-endian integer, i386 LSB-first from a little-endian one; every
# field must decode to its initializer at the given offset.
FIELDS = {
    '_kr_v_bfa': [(3, 5, 0, 0, 0), (5, 17, 0, 3, 3), (9, 300, 0, 8, 8), (8, 0x5a, 0, 24, 24)],
    '_kr_v_bfb': [(12, 0xabc, 0, 0, 0), (12, 0x123, 0, 12, 12), (12, 0x456, 0, 24, 32)],
    '_kr_v_bfc': [(8, 0x11, 0, 0, 0), (4, -3, 1, 8, 8)],
    '_kr_v_bfd': [(4, 9, 0, 0, 0), (4, 6, 0, 16, 32)],
    '_kr_v_bfe': [(4, 3, 0, 0, 0), (4, 12, 0, 4, 4)],
    '_kr_v_bff': [(8, 0x22, 0, 0, 0), (9, 0x1a5, 0, 8, 8)],
    '_kr_v_s1': [(8, 0x11, 0, 0, 0), (32, 0x22334455, 0, 16, 32), (16, 0x6677, 0, 48, 64)],
    '_kr_v_ll': [(64, 0x0102030405060708, 0, 0, 0)],
}


def field(b, order, width, off):
    n = len(b) * 8
    v = int.from_bytes(b, order)
    return (v >> (n - off - width)) & ((1 << width) - 1) if order == 'big' else (v >> off) & ((1 << width) - 1)


def check_fields(name, b, order):
    res = []
    for w, val, sg, om, oi in FIELDS.get(name, []):
        off = om if order == 'big' else oi
        got = field(b, order, w, off)
        if sg and got >> (w - 1):
            got -= 1 << w
        res.append(dict(width=w, offset=off, expect=val, got=got, ok=(got == val)))
    return res


def floats(name, b, order):
    """IEEE single/double via struct; extended: m68k 96-bit (exp16, pad16, mant64), i386 80-bit in 12 bytes"""
    import struct
    e = '>' if order == 'big' else '<'
    if name == '_kr_v_f':
        return struct.unpack(e + 'f', b)[0]
    if name == '_kr_v_od':
        return [b[0], struct.unpack(e + 'd', b[2:10] if order == 'big' else b[4:12])[0],
                'double at byte %d' % (2 if order == 'big' else 4)]
    if name == '_kr_v_ld':
        if order == 'big':
            se, pad, mant = int.from_bytes(b[0:2], 'big'), int.from_bytes(b[2:4], 'big'), int.from_bytes(b[4:12], 'big')
        else:
            mant, se, pad = int.from_bytes(b[0:8], 'little'), int.from_bytes(b[8:10], 'little'), int.from_bytes(b[10:12], 'little')
        from fractions import Fraction
        val = Fraction(mant, 1 << 63) * Fraction(2) ** ((se & 0x7fff) - 16383) * (-1 if se >> 15 else 1)
        return [float(val), 'pad=%#x' % pad, 'explicit integer bit=%d' % (mant >> 63)]
    return None


# h: symbols each probe object must define (optimization must not have removed them)
DEFINES = {
    'c_abi': ['_kr_abi'] + INSTANCES + GLOBALS,
    'c_layout': ['_kr_layout'],
    'c_call': ['_kr_c_narrow', '_kr_c_mixed', '_kr_c_ll', '_kr_c_var', '_kr_c_old', '_kr_c_structs', '_kr_c_rets',
               '_kr_r_sc', '_kr_r_uc', '_kr_r_s', '_kr_r_us', '_kr_r_p', '_kr_r_f', '_kr_r_d', '_kr_r_ll', '_kr_r_ld',
               '_kr_a_narrow', '_kr_a_mixed', '_kr_r_sc1', '_kr_r_si', '_kr_r_sii', '_kr_r_si3', '_kr_r_sd',
               '_kr_old_def', '_kr_bf_plain', '_kr_bf_uns', '_kr_pressure', '_kr_h_llmul', '_kr_h_lldiv',
               '_kr_h_ullmod', '_kr_h_llshl', '_kr_h_d2i', '_kr_h_d2u', '_kr_h_ll2d', '_kr_h_d2ll', '_kr_h_idiv',
               '_kr_h_udiv'],
    'c_iasm': ['_kr_ia_fp', '_kr_ia_ret', '_kr_ia_getsr', '_kr_ia_setsr', '_kr_ia_setsr_k', '_kr_ia_clob'],
    'c_str': ['_kr_s1', '_kr_s2', '_kr_s3', '_kr_s_arr', '_kr_s_ptr'],
    'c_vararg': ['_kr_vsum'],
    'asm_pp_m68k': ['_kr_pp', '_kr_pp_data'],
}


# d: calling-convention observations, each tied to a line of the compiler's own assembly (RUN1 out/);
# the tool fails if the cited line does not contain the quoted text.
OBS = [
    ('args pushed right to left, each in a 4-byte slot; char/short constants widened', 'm68k_O_c_call.s', 7, 'pea 112:w'),
    ('  (last argument pushed first, first argument last before the call)', 'm68k_O_c_call.s', 13, 'pea -2:w'),
    ('prototyped float argument passed as 4-byte float (4.5f = 0x40900000)', 'm68k_O_c_call.s', 23, 'movel #0x40900000,sp@-'),
    ('unprototyped call promotes float to double (3.5 high word 0x400c0000 = 1074528256)', 'm68k_O_c_call.s', 74, 'movel #1074528256,sp@-'),
    ('long double argument: 12 bytes on the stack', 'm68k_O_c_call.s', 42, 'fmovex fp0,sp@-'),
    ('callee reads char argument at the low byte of its slot a6@(11)', 'm68k_O_c_call.s', 169, 'moveb a6@(11),d0'),
    ('callee reads short argument at a6@(10)', 'm68k_O_c_call.s', 187, 'movew a6@(10),d0'),
    ('signed char result sign-extended to 32 bits by the callee', 'm68k_O_c_call.s', 170, 'extbl d0'),
    ('unsigned char result zero-extended by the callee', 'm68k_O_c_call.s', 178, 'clrl d0'),
    ('pointer result in d0', 'm68k_O_c_call.s', 205, 'movel a6@(8),d0'),
    ('float result in d0 (not fp0)', 'm68k_O_c_call.s', 216, 'fmoves fp0,d0'),
    ('double result in d0:d1 (high word in d0)', 'm68k_O_c_call.s', 227, 'movel sp@+,d0'),
    ('long long result in d0:d1 (high in d0); argument high word at a6@(8)', 'm68k_O_c_call.s', 241, 'addxl d2,d0'),
    ('long double result stored through a1, a1 copied to d0', 'm68k_O_c_call.s', 252, 'fmovex fp0,a1@'),
    ('  (address returned in d0)', 'm68k_O_c_call.s', 253, 'movel a1,d0'),
    ('mixed args: double at a6@(12) after a char slot (no 8-byte alignment)', 'm68k_O_c_call.s', 280, 'fmoved a6@(12),fp0'),
    ('mixed args: float at a6@(24) stays 4 bytes', 'm68k_O_c_call.s', 293, 'fmoves a6@(24),fp0'),
    ('old-style definition: float parameter arrives as double at a6@(16)', 'm68k_O_c_call.s', 371, 'fmoved a6@(16),fp1'),
    ('struct{char} (2 bytes) passed right-justified in a 4-byte slot', 'm68k_O_c_call.s', 312, 'movew a6@(10),d0'),
    ('struct{char} result in d0', 'm68k_O_c_call.s', 316, 'bfins d1,d0{#16:#8}'),
    ('struct{int,int} result in d0:d1', 'm68k_O_c_call.s', 334, 'movel a6@(12),d1'),
    ('struct{int[3]} result through a1 (address also in d0)', 'm68k_O_c_call.s', 343, 'movel a1,d0'),
    ('struct{double} (8 bytes) result through a1, not d0:d1', 'm68k_O_c_call.s', 359, 'movel a6@(8),a1@'),
    ('caller passes the result buffer in a1', 'm68k_O_c_call.s', 143, 'lea a6@(-12),a1'),
    ('plain int bitfield is signed (bfexts)', 'm68k_O_c_call.s', 397, 'bfexts a0@{#0:#3},d0'),
    ('callee-saved: d2-d7, a2-a5 (moveml predecrement mask 0x3f3c)', 'm68k_O_c_call.s', 414, 'moveml #0x3f3c,sp@-'),
    ('callee-saved FP: fp2, fp3 used and saved (fmovem predecrement mask 0xc)', 'm68k_O_c_call.s', 413, 'fmovem #0xc,sp@-'),
    ('double to int: FPCR rounding set to toward-zero around fmovel', 'm68k_O_c_call.s', 156, 'andw #-33,d3'),
    ('external call is jbsr (assembled as bsr.l, 68020 32-bit displacement)', 'm68k_O_c_call.s', 434, 'jbsr _ext_opaque'),
    ('frame: pea a6@ / movel sp,a6 instead of link when no locals', 'm68k_O_c_call.s', 167, 'pea a6@'),
    ('varargs callee: promoted char at a6@(12), short at a6@(16)', 'm68k_H_c_vararg.s', 38, 'faddl a6@(12),fp2'),
    ('varargs: double at a6@(20), long long at a6@(28) (4-byte slots, no 8-byte alignment)', 'm68k_H_c_vararg.s', 44, 'movel a6@(28),d0'),
    ('varargs: 4-byte struct at a6@(40)', 'm68k_H_c_vararg.s', 56, 'movel a6@(40),d0'),
    ('inline asm "=a" -> a0', 'm68k_O_c_iasm.s', 8, 'movl a6,a0'),
    ('inline asm "=dm" -> d0', 'm68k_O_c_iasm.s', 31, 'movw sr,d0'),
    ('inline asm "Jdm" with constant 0x2700 -> immediate', 'm68k_O_c_iasm.s', 53, 'movw #9984,sr'),
    ('-fwritable-strings: each literal in __data, no merging', 'm68k_O_c_str.s', 15, '.ascii "kr-same\\0"'),
]


def check_obs(out):
    res = []
    for what, f, ln, text in OBS:
        lines = open(os.path.join(out, f)).read().splitlines()
        res.append(dict(what=what, at='%s:%d' % (f, ln), text=text, ok=(ln <= len(lines) and text in lines[ln - 1])))
    return res


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def llvm(args, path):
    r = subprocess.run([LLVM] + args + [path], capture_output=True, text=True)
    assert r.returncode == 0, (args, path, r.stderr)
    return r.stdout.splitlines()


def products(run):
    out = os.path.join(run, 'out')
    res = {}
    for dp, dns, fns in os.walk(out):
        for n in fns:
            rel = os.path.relpath(os.path.join(dp, n), out)
            if rel == 'run.json' or rel.startswith('_log' + os.sep):
                continue
            res[rel] = sha(os.path.join(out, rel))
    return res


def stem(rel):
    """m68k_O_c_abi.o -> ('m68k', 'O', 'c_abi', '.o')"""
    m = re.match(r'^(m68k|i386)_([DOGHW])_(.+?)(\.[osi])$', rel)
    return m.groups() if m else None


# ---- c: tables and instances, two independent readers ----
def sym_index(o):
    return {y['name']: y for y in o['symbols'] if not y['stab'] and y['kind'] == 'SECT'}


def read_mine(o, path, name, size=None):
    """bytes of symbol NAME via macho_obj: file offset = section offset + value - section address"""
    y = sym_index(o)[name]
    s = o['sections'][y['sect'] - 1]
    assert s['offset'] and not (s['flags'] & 0xff) in (1, 0xc), ('zero-fill', name)
    if size is None:
        later = sorted(z['value'] for z in sym_index(o).values() if z['sect'] == y['sect'] and z['value'] > y['value'])
        size = (later[0] if later else s['addr'] + s['size']) - y['value']
    off = s['offset'] + y['value'] - s['addr']
    b = open(path, 'rb').read()
    assert y['value'] + size <= s['addr'] + s['size']
    relocs = [r for r in s['relocs'] if r['type'] != 1 and
              y['value'] - s['addr'] < r['address'] + (1 << r['length']) and r['address'] < y['value'] - s['addr'] + size]
    return b[off:off + size], y['value'], '%s,%s' % (s['segname'], s['sectname']), len(relocs)


def read_llvm(path, name, size):
    """the same bytes from llvm-objdump: symbol address from -t, contents from -s"""
    addr = sect = None
    for l in llvm(['-t'], path):
        m = re.match(r'^([0-9a-f]{8}) .{7} (\S+)\s+(\S+)$', l)
        if m and m.group(3) == name:
            addr, sect = int(m.group(1), 16), m.group(2)
    assert addr is not None, name
    mem, cur = {}, None
    for l in llvm(['--macho', '-s'], path):
        m = re.match(r'^Contents of section (\S+):$', l)
        if m:
            cur = m.group(1)
            continue
        m = re.match(r'^ ([0-9a-f]{4,8}) ((?:[0-9a-f]{2,8} ?){1,4})', l)
        if m and cur == sect:
            a = int(m.group(1), 16)
            for byte in bytes.fromhex(m.group(2).replace(' ', '')):
                mem[a] = byte
                a += 1
    return bytes(mem[addr + k] for k in range(size)), addr


def words(b, order):
    assert len(b) % 4 == 0
    return [int.from_bytes(b[k:k + 4], order) for k in range(0, len(b), 4)]


def table(path, name, keys, order):
    o = macho_obj.read(path)
    assert o['endian'] == order
    b, addr, sect, nrel = read_mine(o, path, name)
    w = words(b, order)
    end = w.index(0x454e4421) + 1
    b2, addr2 = read_llvm(path, name, 4 * end)
    w2 = words(b2, 'big' if path.split('/')[-1].startswith('m68k') else 'little')
    assert len(keys) == end, (name, len(keys), end)
    return dict(zip(keys, w[:end])), dict(section=sect, address=addr, relocations_in_table=nrel,
                                          llvm_same=(w2 == w[:end] and addr2 == addr))


# ---- d: disassembly ----
def s_functions(path):
    """compiler assembly: instruction lines per global function (labels, directives excluded)"""
    funcs, cur, data = {}, None, {}
    for l in open(path).read().splitlines():
        m = re.match(r'^(_[A-Za-z0-9_]+):$', l)
        if m:
            cur = m.group(1)
            funcs[cur], data[cur] = [], []
            continue
        if re.match(r'^\.(text|const|data|cstring|literal\d*)\b', l.strip()) and not l.startswith('\t'):
            cur = None if l.strip() != '.text' else cur
            continue
        if cur is None or not l.startswith('\t') or re.match(r'^[A-Za-z0-9_]+:', l):
            continue
        t = l.strip()
        (data if t.startswith('.') else funcs)[cur].append(t)
    return {k: v for k, v in funcs.items()}, {k: v for k, v in data.items() if v}


def otool_functions(path):
    funcs, cur = {}, None
    for l in open(path).read().splitlines():
        m = re.match(r'^(_[A-Za-z0-9_]+):$', l)
        if m:
            cur = m.group(1)
            funcs[cur] = []
            continue
        m = re.match(r'^([0-9a-f]{8})\t(\S+)\t?(.*)$', l)
        if m and cur:
            funcs[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))
    return funcs


def capstone_functions(path):
    import capstone
    o = macho_obj.read(path)
    text = [s for s in o['sections'] if s['sectname'] == '__text']
    if not text or not text[0]['size']:
        return {}
    t = text[0]
    b = open(path, 'rb').read()[t['offset']:t['offset'] + t['size']]
    starts = sorted({(y['value'], y['name']) for y in o['symbols']
                     if not y['stab'] and y['kind'] == 'SECT' and y['sect'] == t['index']})
    md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN | capstone.CS_MODE_M68K_040)
    res = {}
    for k, (a, n) in enumerate(starts):
        e = starts[k + 1][0] if k + 1 < len(starts) else t['addr'] + t['size']
        ins, pos = [], a
        for i in md.disasm(b[a - t['addr']:e - t['addr']], a):
            ins.append((i.address, i.size, i.mnemonic, i.op_str, bytes(i.bytes).hex()))
            pos = i.address + i.size
        res[n] = dict(range=[a, e], ins=ins, complete=(pos == e))
    return res


def fpx(hexbytes):
    """68881 general op (first word 0xf2__ with type 000) whose command word has R/M = 1 and
    source format 010 (extended precision): command word & 0x5c00 == 0x4800"""
    if len(hexbytes) < 8 or hexbytes[:2] != 'f2' or (int(hexbytes[:4], 16) >> 6) & 7:
        return False
    return int(hexbytes[4:8], 16) & 0x5c00 == 0x4800


def disasm(out, otool_dir, stems):
    res = {}
    for st in stems:
        obj = os.path.join(out, st + '.o')
        S, Sdata = s_functions(os.path.join(out, st + '.s')) if os.path.exists(os.path.join(out, st + '.s')) else ({}, {})
        ot = otool_functions(os.path.join(otool_dir, st + '.txt'))
        cs = capstone_functions(obj)
        rows = {}
        for n in sorted(set(cs) | set(ot)):
            c = cs.get(n, {})
            oaddr = [x[0] for x in ot.get(n, [])]
            caddr = [x[0] for x in c.get('ins', [])]
            # otool lengths from consecutive addresses (last one to the function end)
            end = c.get('range', [0, 0])[1]
            olen = [b - a for a, b in zip(oaddr, oaddr[1:] + [end])] if oaddr else []
            clen = [x[1] for x in c.get('ins', [])]
            mism = [hex(a) for a in sorted(set(oaddr) ^ set(caddr))]
            # first divergence: the capstone instruction before it had the wrong length; classify its opcode
            culprit = None
            for k in range(min(len(oaddr), len(caddr))):
                if oaddr[k] != caddr[k]:
                    x = c['ins'][k - 1]
                    op = x[4][:4]
                    kind = ('Bcc/BSR/BRA.L (0x6_ff, 68020 32-bit displacement)' if op[0] == '6' and op[2:] == 'ff' else
                            'FPU op with extended (.x) memory source' if fpx(x[4]) else 'other')
                    culprit = dict(address=hex(x[0]), capstone=x[2] + ' ' + x[3], bytes=x[4], kind=kind)
                    break
            if culprit is None and not c.get('complete', True):
                x = c['ins'][-1]
                culprit = dict(address=hex(x[0]), capstone=x[2] + ' ' + x[3], bytes=x[4],
                               kind='FPU op with extended (.x) memory source' if fpx(x[4]) else 'other (stopped)')
            rows[n] = dict(range=[hex(x) for x in c.get('range', [])],
                           otool_count=len(oaddr), capstone_count=len(caddr), compiler_s_count=len(S.get(n, [])),
                           compiler_s_data=Sdata.get(n, []),
                           capstone_complete=c.get('complete'), boundaries_equal=(oaddr == caddr), culprit=culprit,
                           lengths_equal=(olen == clen), boundary_mismatch=mism[:8],
                           capstone_invalid=[x for x in c.get('ins', []) if 'invalid' in x[3]][:4],
                           s_vs_otool_count_equal=(len(S.get(n, [])) == len(oaddr)) if S else None)
        res[st] = rows
    return res


def stab_only(path):
    """b: check_macho_obj differences of a -g object, each classified; True only if all are STAB lines"""
    o, fails = check_macho_obj.check(path)
    if not fails:
        return 'AGREE', []
    mine = {y['name'] for y in o['symbols'] if not y['stab']}
    nstab = sum(1 for y in o['symbols'] if y['stab'])
    stabnames = {y['name'] for y in o['symbols'] if y['stab']}
    other = [f for f in fails if not (f.startswith('unparsed symbol line') and re.match(
        r"^unparsed symbol line '[0-9a-f]{8}\s+d\s+\*UND\*\s*'$", f)) and not f.startswith('symbols differ')]
    # redo the symbol comparison: llvm entries that are not ours must all be STAB strings (contain ':')
    # or nameless 'd *UND*' lines, and their number must equal macho_obj's STAB count
    extra = 0
    theirs = set()
    for l in llvm(['--macho', '-t'], path):
        if re.match(r'^[0-9a-f]{8}\s+d\s+\*UND\*\s*$', l):
            extra += 1
            continue
        m = re.match(r'^([0-9a-f]{8}) (.{7}) (\S+)\s+(.+)$', l)
        if not m:
            continue
        name = m.group(4)
        if m.group(3) == '*UND*' and name not in mine and (':' in name or name in stabnames):
            extra += 1
        elif '*COM*' not in l:
            theirs.add(name)
    if not theirs <= mine | {y['name'] for y in o['symbols']}:
        other.append('llvm names not in macho_obj: %s' % sorted(theirs - mine)[:4])
    if extra != nstab:
        other.append('STAB count: llvm %d, macho_obj %d' % (extra, nstab))
    return ('STAB_ONLY' if not other else 'DIFF'), other


def main():
    run1, run2, otool_dir, tpre, tpost, rep = sys.argv[1:7]
    R = {'plan': 412, 'runs': [run1, run2]}
    out = os.path.join(run1, 'out')
    # a
    p1, p2 = products(run1), products(run2)
    R['a_determinism'] = dict(files=len(p1), same_set=(set(p1) == set(p2)),
                              differing=sorted(k for k in p1 if p1[k] != p2.get(k)))
    # i
    rd = lambda p: {l.split()[2]: l.split()[0] for l in open(p).read().splitlines() if re.match(r'^[0-9a-f]{64} \d+ /', l)}
    pre, post = rd(tpre), rd(tpost)
    cross = json.load(open(CROSS))['target_sha256']
    R['i_tools'] = dict(files=len(pre), pre_equals_post=(pre == post),
                        vs_409={k: (cross[k]['sha256'] == v if k in cross else None) for k, v in sorted(pre.items())})
    # b
    objs = sorted(f for f in p1 if f.endswith('.o') and '/' not in f)
    R['b_llvm'] = {}
    for f in objs:
        v, why = stab_only(os.path.join(out, f))
        R['b_llvm'][f] = dict(verdict=v, other=why)
    # c
    global LAYOUT_KEYS
    old = json.load(open(I386_LAYOUT))
    LAYOUT_KEYS = [k for k in old['s1a-probes-kernel-2'] if k != 'sha256']
    c = {}
    for f in objs:
        a, s, n, _ = stem(f)
        order = 'big' if a == 'm68k' else 'little'
        if n == 'c_layout':
            c[f] = table(os.path.join(out, f), '_kr_layout', LAYOUT_KEYS, order)
        elif n == 'c_abi':
            c[f] = table(os.path.join(out, f), '_kr_abi', ABI_KEYS, order)
            o = macho_obj.read(os.path.join(out, f))
            inst = {}
            for name in INSTANCES:
                b, addr, sect, nrel = read_mine(o, os.path.join(out, f), name)
                b2, addr2 = read_llvm(os.path.join(out, f), name, len(b))
                inst[name] = dict(hex=b.hex(), size=len(b), address=addr, llvm_same=(b == b2 and addr == addr2),
                                  relocations=nrel, fields=check_fields(name, b, order), float=floats(name, b, order))
            ix = sym_index(o)
            glob = {name: dict(address=ix[name]['value'],
                               section='%s,%s' % (o['sections'][ix[name]['sect'] - 1]['segname'],
                                                  o['sections'][ix[name]['sect'] - 1]['sectname']))
                    for name in GLOBALS}
            c[f] = c[f] + (inst, glob)
    R['c_tables'] = {}
    for f, v in c.items():
        R['c_tables'][f] = dict(values=v[0], where=v[1])
        if len(v) > 2:
            R['c_tables'][f]['instances'] = v[2]
            R['c_tables'][f]['globals'] = v[3]
    sets = collections.defaultdict(dict)
    for f, v in R['c_tables'].items():
        a, s, n, _ = stem(f)
        sets[(a, n)][s] = v
    R['c_set_equal'] = {}
    for (a, n), d in sorted(sets.items()):
        vals = {s: json.dumps([x['values'], x.get('instances') and {k: y['hex'] for k, y in x['instances'].items()},
                                x.get('globals')], sort_keys=True) for s, x in d.items()}
        R['c_set_equal']['%s %s' % (a, n)] = dict(sets=sorted(d), equal=(len(set(vals.values())) == 1))
    il = R['c_tables'].get('i386_O_c_layout.o')
    R['c_i386_layout_vs_20261001'] = (il is not None and
                                     all(il['values'][k] == old['s1a-probes-kernel-2'][k] for k in LAYOUT_KEYS))
    # d
    R['d_disasm'] = disasm(out, otool_dir, ['m68k_O_c_codegen', 'm68k_O_c_call', 'm68k_O_c_iasm', 'm68k_O_c_str',
                                            'm68k_H_c_vararg', 'm68k_H_asm_pp_m68k'])
    tot = collections.Counter()
    for st, rows in R['d_disasm'].items():
        for n, r in rows.items():
            tot['functions'] += 1
            tot['boundaries_equal'] += r['boundaries_equal']
            tot['lengths_equal'] += r['lengths_equal']
            tot['capstone_complete'] += bool(r['capstone_complete'])
            tot['s_vs_otool_equal'] += bool(r['s_vs_otool_count_equal'])
            tot['with_s'] += r['s_vs_otool_count_equal'] is not None
    for st, rows in R['d_disasm'].items():
        for n, r in rows.items():
            if r['culprit']:
                tot['culprit ' + r['culprit']['kind']] += 1
    R['d_summary'] = dict(tot)
    # undefined helper symbols per m68k O object (compiler support routines)
    R['d_undefined'] = {}
    for f in objs:
        if f.startswith('m68k_O_') or f.startswith('i386_O_'):
            o = macho_obj.read(os.path.join(out, f))
            R['d_undefined'][f] = sorted(y['name'] for y in o['symbols'] if not y['stab'] and y['kind'] == 'UNDF')
    # e
    R['e_objc'] = {}
    for f in ('m68k_D_objc_probe.o', 'm68k_H_objc_probe.o', 'i386_H_objc_probe.o'):
        o = macho_obj.read(os.path.join(out, f))
        R['e_objc'][f] = [['%s,%s' % (s['segname'], s['sectname']), s['size'], s['align'], len(s['relocs'])]
                          for s in o['sections']]
    nm = lambda f: {x[0] for x in R['e_objc'][f]}
    R['e_objc_section_sets'] = dict(m68k_H_eq_i386_H=(nm('m68k_H_objc_probe.o') == nm('i386_H_objc_probe.o')),
                                    only_m68k=sorted(nm('m68k_H_objc_probe.o') - nm('i386_H_objc_probe.o')),
                                    only_i386=sorted(nm('i386_H_objc_probe.o') - nm('m68k_H_objc_probe.o')))
    # f
    o = macho_obj.read(os.path.join(out, 'm68k_H_asm_pp_m68k.o'))
    b = open(os.path.join(out, 'm68k_H_asm_pp_m68k.o'), 'rb').read()
    secs = {s['sectname']: s for s in o['sections']}
    t, d = secs['__text'], secs['__data']
    R['f_asm'] = dict(text=b[t['offset']:t['offset'] + t['size']].hex(), data=b[d['offset']:d['offset'] + d['size']].hex(),
                      undefined=sorted(y['name'] for y in o['symbols'] if y['kind'] == 'UNDF'),
                      relocs={k: [dict(address=r['address'], pcrel=r['pcrel'], length=r['length'], extern=r['extern'],
                                       type=r['type'], scattered=r['scattered']) for r in s['relocs']]
                              for k, s in secs.items()})
    # g
    R['g_mig'] = {}
    for fn in ('krprobe.h', 'krprobeUser.c', 'krprobeServer.c'):
        a = open(os.path.join(out, 'mig_m68k', fn)).read().splitlines()
        i = open(os.path.join(out, 'mig_i386', fn)).read().splitlines()
        diff = [(k + 1, x, y) for k, (x, y) in enumerate(zip(a, i)) if x != y]
        R['g_mig'][fn] = dict(lines_m68k=len(a), lines_i386=len(i), differing=diff[:20], n_differing=len(diff))
    # h
    R['h_defined'] = {}
    for f in objs:
        a, s, n, _ = stem(f)
        if n in DEFINES:
            o = macho_obj.read(os.path.join(out, f))
            have = {y['name'] for y in o['symbols'] if not y['stab'] and y['kind'] == 'SECT'}
            R['h_defined'][f] = sorted(set(DEFINES[n]) - have)
    R['d_observations'] = check_obs(out)
    R['tool_sha256'] = sha(os.path.abspath(__file__))
    open(rep, 'w').write(json.dumps(R, indent=1) + '\n')
    print(json.dumps({k: R[k] for k in ('a_determinism', 'd_summary', 'c_set_equal', 'c_i386_layout_vs_20261001',
                                        'e_objc_section_sets')}, indent=1))


if __name__ == '__main__':
    main()
