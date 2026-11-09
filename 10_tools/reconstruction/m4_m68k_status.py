#!/usr/bin/env python3
"""m4_m68k_status.py -- plan 500 (M4-6): table of the accepted m68k M4 objects.

  python3 10_tools/reconstruction/m4_m68k_status.py OUT.tsv RECORD.json

Reads the accepted final records of m4_m68k_probe.py listed in ACCEPTED (path, SHA-256) and re-checks
each of their objects now (any failure stops before writing): record hash and gate.ok; the spec
(08_build/artifacts/m4p<plan>/spec.json) hash equals the record's spec_sha256; the 07 source hash
equals the record's source_sha256; the run's compile line for that source is unique; the run object
exists with the recorded SHA-256; the REF hash equals the spec and REF equality (canon, obj_sig) holds;
the range recomputed from the plan 495 inventory (m4_m68k_probe.span) has the object's __text size and
the L1 output (08_build/artifacts/m4p<plan>/<run>/l1-<name>-<V>.json, input hash checked) places
__TEXT,__text at its start with verdict OBJECT_MATCH; the evidence document exists; plan 506: for every
NeXTMach-only header the spec's base stage manifest lists in m4_headers, the current 07 origin hash equals
the manifest hash (plan 649, D149: only the m4_headers in the object's dependency list -- the run's single
-M command for its source, whose output stage/_log/NN.out (NN counts RUN lines from 0) has the run's
output.manifest hash, names the source first, maps every path onto a stage manifest key after the leading
src/, and whose -D/-I options equal the compile line's; -imacros src/generated/meta_features.h is not in
-M output, its closure holds generated configuration headers only).  Plan 526 (D113): an ACCEPTED entry may carry a third and fourth value, the
m5_m68k_zerofill.py objs record and its SHA-256; that object is accepted as CODE+BSS_INFERRED instead of
OBJECT_MATCH: L1 verdict NOT_MATCH with reasons exactly ['__DATA,__bss: unverified'] (__text placed as
above), the record's summary has no not_ok and no overlaps, and its row for the object (same object name,
object SHA-256) is ok with conclusion reference-inferred(-single).  Across objects:
no duplicate name, no row covered twice, no overlapping address range.
Plan 537: an explicit range may split rows ("partial"); they are listed in partial_rows and not counted
as covered (plan 639, D145: except an exact row whose accepted pieces cover it without a gap, listed in rows_tiled).  Counts: accepted objects (and per acceptance class), covered plan 495 rows of 188, bytes of the M4 minimum bytes; the M5 set
(plan 429) is not counted here.  Read-only apart from the two output files.
"""
import sys, os, json, hashlib, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import m4_m68k_probe as P

ACCEPTED = [
    ('09_validation/reconstruction/m4-m68k-p497-final-20261024.json', 'eefdb8424d310857770fdee84ded0867bbbb2608696e779549f96e223fa6cfc8'),
    ('09_validation/reconstruction/m4-m68k-p500-final-20261024.json', 'b994bb01d74e0f544c7b0e15da77e59a6c69a09b7635802e27923cf68599e98b'),
    ('09_validation/reconstruction/m4-m68k-p502-final-20261024.json', '86a2f93903a5125e9d1cbd960a73892582109f9ca29c8d0eed3ae1585de762dc'),
    ('09_validation/reconstruction/m4-m68k-p504-final-20261024.json', 'fb3c933e77cc9c14b3015c7f7ee2343111c3539e5633663ef8d33591cdf03017'),
    ('09_validation/reconstruction/m4-m68k-p506-final-20261024.json', 'f64b2a69110ce776c81e5018f74b9e402d23ec8890851e3fb24e056296bb1ab1'),
    ('09_validation/reconstruction/m4-m68k-p508-final-20261024.json', '8ecb385e2dc3a836a8850f9b1b1e35c1ed0d5d55e4f6a2454bada0e8ff5fdb8e'),
    ('09_validation/reconstruction/m4-m68k-p510-final-20261024.json', '7cdd7e9a47cecc763bf9b9dc6862cdb98bae944e8fb78b63e33e7eca1201d47f'),
    ('09_validation/reconstruction/m4-m68k-p512-final-20261024.json', 'b1194545b5937709d0662380b0b0db538d82b526b59acc1d5249609585d60be7'),
    ('09_validation/reconstruction/m4-m68k-p514-final-20261024.json', 'c30016d32daacb04b8a73f5b73515d8e0fad7bc8f318b3c8cd5fb0f97d963c1c'),
    ('09_validation/reconstruction/m4-m68k-p520-final-20261026.json', 'ac636406c93cef82539c181dab3bcb5ed8d9845455bbd491db1f931fb87d884b'),
    ('09_validation/reconstruction/m4-m68k-p523-final-20261026.json', '2a7809fcf40047d81fb9123060c9b82038033d1fba83759dabf8b895a62ae266'),
    ('09_validation/reconstruction/m4-m68k-p529-final-20261026.json', '4e706ca996eee7530524e37c6878805596d79266b2a5cc5e16042f56a0810e95'),
    ('09_validation/reconstruction/m4-m68k-p531-final-20261026.json', '4dade7b15934b0bcb57cbfbaefff51a36994ccf300e78c87b5483c662474ae05'),
    ('09_validation/reconstruction/m4-m68k-p538-final-20261026.json', 'cec457ea6c507f67fe2891774158efe087b8f27c4f9be1bfad0d600bb69b6628',   # plan 538 (D117): CODE+BSS_INFERRED, partial row m68k-306
     '09_validation/reconstruction/m4-m68k-zerofill-p538-20261026.json', '22c85ba647a56903fd4afdd0c07923b68d8b053fa9ecd9d49349d2d3c8ef2bcc'),
    ('09_validation/reconstruction/m4-m68k-p542-final-20261026.json', 'b9497c084decd054f5f2ed45bad23160a21efcdfb597280c6b2285bd739c762b',   # plan 542 (D118): CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p542-20261026.json', '3410b32178ca8457fd18dce6f3fa93134df3c52ededbd64477e875f1dfe463a8'),
    ('09_validation/reconstruction/m4-m68k-p547-final-20261029.json', 'd561550d175e904558f811913804ea25307162db560b97363cf5f706c21e7889',   # plan 547 (D120): CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p547-20261029.json', 'fa3d47a9ed2b8ea3d8a849ef450ba9ec2710045b8d526554a4a408549d12b8f2'),
    ('09_validation/reconstruction/m4-m68k-p549-final-20261030.json', '570fd1905b237e99702f4b3bcd08a38424aab10989ff54114753f77799280375'),   # plan 549 (D121)
    # plan 559 (D125): snd_dspcmd, and snd_reply and snd_rcv again with the plan 559 driverkit/snd_msgs.h; replaces the
    # plan 554 (D123) record m4-m68k-p554-final-a2-20261030.json, whose base stage has the plan 554 snd_msgs.h (plan 506 check)
    ('09_validation/reconstruction/m4-m68k-p559-final-20261030.json', '103df590386209ea5a3c286aa4b1a27a46750c2cec1eded86798a1715dcfb013'),
    # plan 560 (D125): snd_device again with the plan 559 headers; replaces the plan 556 (D124) record m4-m68k-p556-final-20261030.json
    ('09_validation/reconstruction/m4-m68k-p560-final-20261030.json', 'cebc7917acdde25592207f952dbc91083a8ad72758593028016a5db604f2702f',   # plan 560 (D125): CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p560-20261030.json', '9b33527b722564cc9dc07dba070b28b66622d77e3e1313573c01b2dbc16b91e1'),
    ('09_validation/reconstruction/m4-m68k-p563-final-20261030.json', '9ffd1ba36e7986911a7f70b54975b4d7c99b1a204feda91e726526ce7ac2b202'),   # plan 563 (D126): partial rows m68k-244, m68k-245
    ('09_validation/reconstruction/m4-m68k-p566-final-20261030.json', 'c440277eb0c181cc50dbfa6b5b0d729f9dd6282f51484631eb5e66984adf07b7',   # plan 566 (D127): CODE+BSS_INFERRED, partial rows m68k-245, m68k-246
     '09_validation/reconstruction/m4-m68k-zerofill-p566-20261030.json', 'e95fab150b4e1f136373da3b24a346b0879aa500716cdff473ab595c24ee41b1'),
    ('09_validation/reconstruction/m4-m68k-p570-final-20261030.json', 'a8343381f0cf03f4475bf59a17cc6f2cb469d29433874d1a99ef0d715bc9ef7a',   # plan 570 (D128): CODE+BSS_INFERRED, row m68k-222
     '09_validation/reconstruction/m4-m68k-zerofill-p570-20261030.json', '0f5a2ce73b29da6dc30b3ab976688c2a60f309bedc18a88e8737d1b3cd078e5d'),
    ('09_validation/reconstruction/m4-m68k-p573-final-20261030.json', '1abd0cc6f7557ed2d61915ca51dbca047ab180ebc4431b0aee2f7d6df86aa3a7'),   # plan 573 (D129): row m68k-221
    ('09_validation/reconstruction/m4-m68k-p576-final-20261030.json', '4dd53115ed1f5d194ba34ce7d84051596d93046ef7c32411cca80e9b06a536ba'),   # plan 576 (D130): row m68k-220
    ('09_validation/reconstruction/m4-m68k-p579-final-20261030.json', '2f66b8c7b202aeba2ceb0164e9a9bc2ef95442446e391a24a45d6c1b0090cc70'),   # plan 579 (D131): explicit range, partial row m68k-219
    ('09_validation/reconstruction/m4-m68k-p602-final-20261030.json', 'df9e2ff41b5a5cde9d6c5f58c42d11b22af2cf993b811be76048b868b71706cf'),   # plan 602 (D135): miniMonMachdep (row m68k-300), next_exception (row m68k-301)
    ('09_validation/reconstruction/m4-m68k-p604-final-20261030.json', 'dec87ebb3ad93a279cc1d9db5aabbcaae3f11e994913ddf8add701e918f7ab85'),   # plan 604 (D136): APM (row m68k-263), Darwin ppc APM.c verbatim
    ('09_validation/reconstruction/m4-m68k-p614-final-20261030.json', '14fec4a50be28838042457190170d3c8905092f674ec34fa2b6dce06f08e702f'),   # plan 614 (D139): shutdown (row m68k-313)
    ('09_validation/reconstruction/m4-m68k-p618-final-20261030.json', '2e3a6a9053364661f3a7659d6e11af27cc2be12cbef773cb986f0ccd7225b608'),   # plan 618 (D141): vm_machdep pagemove (explicit range, partial rows m68k-323, m68k-324)
    ('09_validation/reconstruction/m4-m68k-p627-final-20261031.json', 'f2dee8e47e0e9c9653ea95f2bb676f4a84f28f2ecc5c5a26a3b27b3c8ad354ff'),   # plan 627 (D143): pcb (rows m68k-308, m68k-309)
    ('09_validation/reconstruction/m4-m68k-p636-final-20261031.json', '4e5404019af2dc3060a30c4667450e922f67eb4c2fafc8ed96a3d88fa1701030'),   # plan 636 (D144): trap (rows m68k-315 .. m68k-320)
    ('09_validation/reconstruction/m4-m68k-p639-final-20261031.json', '26e09799e79f008c066d3634c5ba30dda586196008805c988f2394b7f18b183d'),   # plan 639 (D145): ashldi3, bdiv, lshldi3, lshrdi3, udivdi3, umoddi3 (exact rows m68k-264, m68k-291, m68k-322 split)
    ('09_validation/reconstruction/m4-m68k-p642-final-20261031.json', 'c02240e6ca3ea64a5ec3143887005c2eccd1f129bc4475d7980cf53a28787f9c'),   # plan 642 (D146): kernel_pmon (row m68k-276)
    ('09_validation/reconstruction/m4-m68k-p644-final-20261031.json', 'b768d45ff3151eb78be0d121c66c76e5bacebb0f17ca3e213f928f40528104da'),   # plan 644 (D147): snd_stream (explicit range, partial rows m68k-252, m68k-253)
    ('09_validation/reconstruction/m4-m68k-p646-final-20261031.json', '42656cb547e66c1014b2dfa6862c70bec57d99235d277673b6cc567cad24fe01'),   # plan 646 (D148): snd_unix (explicit range, partial rows m68k-253, m68k-254)
    ('09_validation/reconstruction/m4-m68k-p657-final-20261031.json', 'd13dd4115379f0aad433d2c189377b07f2ac10c5d51e138cd351eeacf0b1c8a8'),   # plan 657 (D152): sf_access (explicit range, partial row m68k-240)
    ('09_validation/reconstruction/m4-m68k-p670-final-20261101.json', '87ac3d78b29abbeb301a1a1e1d2afc4c16273e1aed2704b97f7ff1116c3ce688'),   # plan 670 (D155): st and sg re-accepted with the 1997 scsi_5390_ctrl in the 07 scvar.h (replaces plan 663)
    ('09_validation/reconstruction/m4-m68k-p671-final-20261101.json', '622636425940746b5e12ab12087f75e7714442b03195fda3ada93a4d4cdb5fa1',   # plan 671 (D155): autoconf, sd, scsi re-accepted (replace plans 664, 667) and sc (explicit range, partial rows m68k-235/236/237), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p671-20261101.json', '91f08d157c2c9af9ffa6c4bff02b5347f0c850577a45b3d7add0ada40aa3490a'),
    ('09_validation/reconstruction/m4-m68k-p676-final-20261101.json', '879c58b7c13639b390c7658e70afa84d0cc4ccad32c0db471f8aba2603acd9f2'),   # plan 676 (D157): if_bus (explicit range, partial rows m68k-258/259/260)
    ('09_validation/reconstruction/m4-m68k-p679-final-20261101.json', '4e4905b184e365ab1dba1d67a8fbd97ec0c6a557b954c31103c45bfdc70440fb'),   # plan 679 (D158): km (rows m68k-223..226) and clock, machdep, zscom re-accepted with the 07 kmreg.h ioctl names (replace plans 585, 600, 674)
    ('09_validation/reconstruction/m4-m68k-p683-final-20261101.json', 'd9e05fe3b444f73b3f6d45310dc00b07cd9133faed5e39cd1cfa9dda14cc7c38',   # plan 683 (D159): od (row m68k-234, partial rows m68k-235/236) and swapgeneric re-accepted (replaces plan 612; NOD 2/NOC 1), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p683-20261101.json', 'a17a3d2c58f89abf9a253cee3ee0d24fef308e0f5a1f7a60b1a2f5e5b0d96a54'),
    ('09_validation/reconstruction/m4-m68k-p684-final-20261101.json', 'cf1bf6777dd4614c62d85275eb9e560d9841de14a6114ed18dc5bef300ad3365'),   # plan 684 (D159): machargs re-accepted (replaces plan 517; NOD 2 comment)
    ('09_validation/reconstruction/m4-m68k-p687-final-a2-20261102.json', 'ccf97e1ab510eb96ec3d9a9987b76624353bb24fbc8d681713f58adab8b8d35e'),   # plan 687 (D160): pmap (rows m68k-310..312; run m4p687-a2)
    ('09_validation/reconstruction/m4-m68k-p724-final-20261102.json', '3f2b99f62adf3804876a414a887da097b1de31a5e06def9a45cb3a623851b0de'),   # plan 724 (D162): ev_ioctl (row m68k-214, partial row m68k-215; run m4p724-a1)
    ('09_validation/reconstruction/m4-m68k-p729-final-20261103.json', '40ab97b48930843e98dd2b12a50352d6d601212374839760f437bbc4f59bf690'),   # plan 729 (D164): ev_kbd (partial row m68k-215; run m4p729-a1)
    ('09_validation/reconstruction/m4-m68k-p736-final-20261105.json', '3b78b5ba26f81357cf5b517dec4052219d3a30f10a90bec0b28343c166a8dc7a',   # plan 736 (D165): ev_mouse (rows m68k-216, m68k-217, m68k-218, partial row m68k-219; run m4p736-a1), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p736-20261105.json', '927c6c5b68b67b9fe47f96df1010daee1480032aa36a69f6b8d5125ed41ac07e'),
    ('09_validation/reconstruction/m4-m68k-p754-final-20261106.json', '306f233fbd1534ef6869cbcd2ef20bd86405ba4a37daa92dec0e1dbaf440fbd3'),   # plan 754 (D167, D168): locore (rows m68k-001 .. m68k-006; run m4p754-a1), OBJECT_MATCH with __data 464 B
    ('09_validation/reconstruction/m4-m68k-p758-final-20261106.json', '5bbd3b336c47e73db39b8c6f24651663375aa175e82c07d9e4eeeb3e2eb35799',   # plan 758 (D170): snd_link re-accepted with the corrected snd_audio.h (replaces plan 756; partial row m68k-246; run m4p758-a1), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p758-20261106.json', 'b7bb0920f9967a3636d6b77bc24c364ed1f2dd190e079d55b44fe9a56b582157'),
    ('09_validation/reconstruction/m4-m68k-p759-final-20261106.json', 'cda332fa2e120adc0cb774634673e47d6be13a55c7fa4feef9c7003ceb418ae0'),   # plan 759 (D170): snd_server (rows m68k-249, m68k-250, m68k-251, partial row m68k-252; run m4p759-a1), OBJECT_MATCH
    ('09_validation/reconstruction/m4-m68k-p761-final-20261107.json', '12e1124404867eab72fe9a8e6a3ebd668f70798d35a9e30ab7bb1ad8f90491e9',   # plan 761 (D171): video (explicit range, partial rows m68k-255/256), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p761-20261107.json', 'ecaf8820c502c57a753570676fa8efd711f49691efbea5e6f6c4088bdf1b40b0'),
    ('09_validation/reconstruction/m4-m68k-p763-final-20261107.json', '6034340d2eeb30e6045febd24d19686f8e59ae36318219915e6b79f6f19ff12b',   # plan 763 (D172): zs (explicit range, row m68k-257, partial row m68k-256), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p763-20261107.json', '41efd66221340d9113e6fcf603bc30f2acc59a3b3a928fe79a57eb81640a1198'),
    ('09_validation/reconstruction/m4-m68k-p764-final-20261107.json', '9e54be01d72cb9ec33883fe527d12066ad1085c1fee2d68ed509830be9dc5d28',   # plan 764: tty_pty (m68k overlay with the tail; explicit range, row m68k-036), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p764-20261107.json', '03e91fbd9d843176bc9decb2431503e0393c6ca09a8665f78233ea252cae4f3d'),
    ('09_validation/reconstruction/m4-m68k-p766-final-20261107.json', 'e0950997542828b1592562a2b9b225458d27e3ef7949c2ecdc9cb3278d4c0dad',   # plan 766 (D173): adb (explicit range, row m68k-209; project authored, provisional names), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p766-20261107.json', '3a3a1fba8149d9a750d2e25f5bb12aace1ecd77dc53950876f9d4e5b86665326'),
    ('09_validation/reconstruction/m4-m68k-p779-final-20261109.json', 'd0e75cd3799bc4cb7fcccafaa631d5d7e75a5499c69fb7c807542daa54d8a368',   # plan 779 (D178): ev, if_en, m68k_init, nextdbg re-accepted with the __common declarations (replace plans 689, 727, 680, 739), CODE+BSS_INFERRED
     '09_validation/reconstruction/m4-m68k-zerofill-p779-20261109.json', 'e03eb72af99c0c6f6e29d225de47cab5cf0177bb4334a3669be78bdaa5a0d4d7'),
    ('09_validation/reconstruction/m4-m68k-p780-final-20261109.json', '0dbea0288b2822e1f73a86c338431d140d554531695fe895f21b8d1e401a701b'),   # plan 780 (D178): fpsp re-accepted with its nine counters as __data (replaces plan 770), OBJECT_MATCH
]
COLS = ['name', 'source', 'rows', 'partial_rows', 'groups', 'kinds', 'start', 'end', 'bytes', 'plan', 'record', 'l1', 'acceptance', 'obj_sha256', 'evidence']


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def tiled_rows(inv, out):
    """plan 639 (D145): the exact rows that accepted objects split ("partial") and that their ranges,
    cut to the row's half-open range, cover without a gap; read after every record (any record order)"""
    tiled = []
    for i in sorted({i for x in out for i in x['partial_rows'].split(',') if i}):
        if inv[i]['exact'] != '1':
            continue
        s, e = int(inv[i]['start_lo'], 16), int(inv[i]['end_hi'], 16)
        iv = sorted((max(s, int(x['start'], 16)), min(e, int(x['end'], 16))) for x in out if i in x['partial_rows'].split(','))
        assert all(a < b for a, b in iv) and all(a[1] <= b[0] for a, b in zip(iv, iv[1:])), ('overlap', i)
        if iv[0][0] == s and iv[-1][1] == e and all(a[1] == b[0] for a, b in zip(iv, iv[1:])):
            tiled.append(i)
    return tiled


def dep_headers(rid, runcmd, rel, cline, mf, m4h):
    """plan 649 (D149): the m4_headers among the dependencies of src/<rel> in run rid (see the module text)"""
    runs = [l for l in runcmd if l.startswith('RUN ')]
    idx = [i for i, l in enumerate(runs) if ' -M ' in l and ' src/src/%s ' % rel in l + ' ']
    assert len(idx) == 1, ('deps command', rid, rel, len(idx))
    dline = runs[idx[0]].split()
    opts = lambda w: [x for x in w if x.startswith(('-D', '-I'))]
    assert opts(dline) == opts(cline.split()), ('deps options', rid, rel)
    out = 'stage/_log/%02d.out' % idx[0]
    om = dict((l.split(' ', 2)[2], l.split(' ', 2)[0]) for l in open(os.path.join('08_build/runs', rid, 'output.manifest')).read().splitlines())
    p = os.path.join('08_build/runs', rid, out)
    assert out in om and sha(p) == om[out], ('deps output', rid, out)
    words = open(p).read().replace('\\\n', ' ').split()
    assert words[0].endswith('.o:') and words[1] == 'src/src/' + rel, ('deps rule', rid, out, words[:2])
    deps = set()
    for w in words[1:]:
        assert w.startswith('src/') and w[len('src/'):] in mf, ('deps path', rid, out, w)
        deps.add(w[len('src/'):])
    return sorted(deps & set(m4h))


def main(out_tsv, out_json):
    import m3_m68k_diag as D
    import l2_prefix_diff as PD
    rows = [l.split('\t') for l in open(P.INV).read().split('\n') if l and not l.startswith('#')]
    inv = {r[0]: dict(zip(rows[0], r)) for r in rows[1:]}
    out, seen_rows, spans = [], {}, []
    for ent in ACCEPTED:
        path, want = ent[0], ent[1]
        zf = None
        if len(ent) == 4:                     # plan 526 (D113): bss place by m5_m68k_zerofill.py objs
            assert sha(ent[2]) == ent[3], ('zerofill record changed', ent[2])
            zf = json.load(open(ent[2]))
            assert zf['summary']['not_ok'] == [] and zf['summary']['overlaps'] == [], (ent[2], zf['summary'])
        else:
            assert len(ent) == 2, ent
        assert sha(path) == want, ('record changed', path)
        rec = json.load(open(path))
        assert rec['gate']['ok'] is True, path
        plan, rid = rec['plan'], rec['run']
        spec = '08_build/artifacts/m4p%d/spec.json' % plan
        assert sha(spec) == rec['spec_sha256'], spec
        s = P.load(spec)
        man = json.load(open(s['base'] + '.manifest.json'))   # plan 506: staged NeXTMach-only headers still current
        mf = {e[0]: e for e in man['files']}
        m4h = man.get('m4_headers', [])                     # plan 649 (D149): checked per object below
        objs = {o['name']: o for o in s['objects']}
        runcmd = open(os.path.join('08_build/runs', rid, 'run.cmd')).read().splitlines()
        for r in [x for x in rec['objects'] if 'variant' in x]:
            o = objs[r['object']]
            rel = r['source'][len('src/'):]
            src = os.path.join('07_kernel/src', rel)
            ov = os.path.join('07_kernel/v183.34/m68k/src', rel)   # plan 764: an m68k overlay of a 07 main file, taken only when the stage manifest names it as the origin
            if mf.get('src/' + rel, [None, None])[1] == ov:
                src = ov
            assert sha(src) == r['source_sha256'], ('source changed', src)
            obj = 'Q%d__%s_%s.o' % (plan, r['object'], r['variant'])
            lines = [l for l in runcmd if ' -c src/src/%s ' % rel in l + ' ' and ('stage/' + obj) in l]
            assert len(lines) == 1, (rid, rel, len(lines))
            for dst in dep_headers(rid, runcmd, rel, lines[0], mf, m4h):   # plan 649 (D149)
                assert sha(mf[dst][1]) == mf[dst][2], ('header changed', mf[dst][1])
            op = os.path.join('08_build/runs', rid, 'stage', obj)
            assert sha(op) == r['obj_sha256'], op
            ref, rsha = s['refs'][r['object']]
            assert sha(ref) == rsha and D.canon(op) == D.canon(ref) and PD.obj_sig(op) == PD.obj_sig(ref), ('ref', r['object'])
            lo, hi, ids = P.span(inv, o['m4_id'])
            assert r['text_size'] == hi - lo, (r['object'], r['text_size'], hi - lo)
            l1p = '08_build/artifacts/m4p%d/%s/l1-%s-%s.json' % (plan, rid, r['object'], r['variant'])
            d = json.load(open(l1p))
            if zf is None:
                assert d['inputs'][op] == r['obj_sha256'] and d['object_verdict'] == 'OBJECT_MATCH', l1p
                acc = 'OBJECT_MATCH'
            else:                             # plan 526 (D113)
                assert d['inputs'][op] == r['obj_sha256'] and d['object_verdict'] == 'NOT_MATCH', l1p
                assert d.get('object_reasons') == ['__DATA,__bss: unverified'], (l1p, d.get('object_reasons'))
                zr = [x for x in zf['rows'] if x['object'] == r['object'] and x['obj_sha256'] == r['obj_sha256']]
                assert len(zr) == 1 and zr[0]['ok'] is True and zr[0]['l1_reasons'] == ['__DATA,__bss: unverified'], ('zerofill row', r['object'])
                assert zr[0]['conclusion'] in ('reference-inferred', 'reference-inferred-single'), zr[0]['conclusion']
                acc = 'CODE+BSS_INFERRED'
            assert d['sections']['__TEXT,__text']['address'] == lo, (l1p, d['sections']['__TEXT,__text']['address'], lo)
            ev = '06_reconstruction/evidence/m68k-%s.md' % r['object']
            assert os.path.isfile(ev), ev
            assert r['object'] not in {x['name'] for x in out}, ('duplicate', r['object'])
            for i in ids:
                assert i not in seen_rows, ('row twice', i)
                seen_rows[i] = r['object']
            assert all(hi <= a or b <= lo for a, b in spans), ('overlap', r['object'])
            spans.append((lo, hi))
            out.append(dict(name=r['object'], source=src, rows=','.join(ids), partial_rows=','.join(P.partial_rows(o['m4_id'])), groups=','.join(inv[i]['group'] for i in ids),
                            kinds=','.join(inv[i]['kind'] for i in ids), start=hex(lo), end=hex(hi), bytes=hi - lo, plan=plan,
                            record=path, l1=d['object_verdict'], acceptance=acc, obj_sha256=r['obj_sha256'], evidence=ev))
    out.sort(key=lambda x: int(x['start'], 16))
    tiled = tiled_rows(inv, out)          # plan 639 (D145): exact rows split among accepted objects
    for i in tiled:
        assert i not in seen_rows, ('row twice', i)
        seen_rows[i] = ','.join(x['name'] for x in out if i in x['partial_rows'].split(','))
    updated = max(x['plan'] for x in out)   # plan 502: latest accepted record
    m4min = sum(int(r['bytes_min'] or 0) for r in inv.values())
    covered_bytes = sum(int(inv[i]['bytes_min']) for i in seen_rows)
    summ = collections.OrderedDict(objects=len(out), object_match=sum(1 for x in out if x['acceptance'] == 'OBJECT_MATCH'),
                                   code_bss_inferred=sum(1 for x in out if x['acceptance'] == 'CODE+BSS_INFERRED'), rows_covered=len(seen_rows), rows_total=len(inv), bytes_covered=covered_bytes,
                                   m4_min_bytes=m4min, percent=round(100.0 * covered_bytes / m4min, 2),
                                   partial_rows=sorted({i for x in out for i in x['partial_rows'].split(',') if i}),
                                   object_bytes=sum(x['bytes'] for x in out),
                                   rows_unassigned_before=sorted(i for i in seen_rows if inv[i]['kind'] == 'unassigned'),
                                   rows_tiled=tiled)   # plan 639 (D145)
    with open(out_tsv, 'w') as w:
        w.write('# plan 500 (updated plan %d): accepted m68k M4 objects (m4_m68k_status.py); rows = plan 495 inventory rows covered; M5 (plan 429) not included\n' % updated)
        w.write('\t'.join(COLS) + '\n')
        for x in out:
            w.write('\t'.join(str(x[c]) for c in COLS) + '\n')
    json.dump(collections.OrderedDict(plan=500, updated_plan=updated, tool='10_tools/reconstruction/m4_m68k_status.py', tool_sha256=sha(os.path.abspath(__file__)),
                                      accepted=ACCEPTED, inventory=P.INV, inventory_sha256=sha(P.INV), summary=summ, objects=out,
                                      output=out_tsv, output_sha256=sha(out_tsv)), open(out_json, 'w'), indent=1)
    print(json.dumps(summ))
    for x in out:
        print(x['name'], x['rows'], x['start'], x['end'], x['bytes'], x['l1'], x['acceptance'])


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
