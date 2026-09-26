#!/usr/bin/env python3
"""Read NeXT 32-bit Objective-C metadata using the locally mirrored SDK layouts."""
import hashlib
import json
import struct
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'03_original/x86/inventory/objc.json'

def main():
    meta=json.loads((ROOT/'03_original/x86/inventory/macho.json').read_text())
    binary=(ROOT/'03_original/x86/binaries/mach_kernel').read_bytes()
    sections=meta['sections']; text=next(s for s in sections if s['name']=='__text')
    lo=int(text['address'],16); hi=lo+text['size']
    def offset(va,length=1):
        for s in sections:
            start=int(s['address'],16)
            if int(s['flags'],16)&0xff==1:continue
            if start<=va and va+length<=start+s['size']:
                return s['file_offset']+va-start
        raise ValueError(f'VA not in file-backed section: {va:#x}, length={length}')
    def read(va,fmt):return struct.unpack_from('<'+fmt,binary,offset(va,struct.calcsize('<'+fmt)))
    def string(va):
        if not va:return None
        pos=offset(va);end=binary.index(b'\0',pos)
        offset(va,end-pos+1)
        return binary[pos:end].decode('utf-8','replace')
    methods=[]; classes=[]; categories=[]; modules=[]; lists=set()
    def method_list(va,owner,kind):
        if not va:return
        if (va,owner,kind) in lists:return
        lists.add((va,owner,kind))
        obsolete,count=read(va,'II')
        if count>10000:raise ValueError('Implausible method list count')
        for i in range(count):
            entry=va+8+i*12;name,types,imp=read(entry,'III')
            if not lo<=imp<hi:raise ValueError(f'IMP outside text: {imp:#x}')
            methods.append(dict(owner=owner,kind=kind,selector=string(name),types=string(types),
                                imp=hex(imp),metadata_address=hex(entry),list_address=hex(va)))
    def klass(va,kind='instance'):
        fields=read(va,'10I');isa,superclass,name,version,info,size,ivars,mp,cache,protocols=fields
        cname=string(name)
        classes.append(dict(address=hex(va),kind=kind,name=cname,isa=hex(isa),
                            superclass=hex(superclass),info=info,instance_size=size,ivars=hex(ivars),methods=hex(mp)))
        if info&0x100:
            for i in range(1024):
                p,=read(mp+i*4,'I')
                if p in (0,0xffffffff):break
                method_list(p,cname,kind)
            else:raise ValueError('Unterminated class method array')
        else:method_list(mp,cname,kind)
        if kind=='instance':klass(isa,'class')
    modsec=next(s for s in sections if s['name']=='__module_info')
    va=int(modsec['address'],16); end=va+modsec['size']; seen_classes=set();seen_cats=set()
    while va<end:
        version,size,name,symtab=read(va,'IIII')
        if size<16 or va+size>end:raise ValueError('Bad module record size')
        refs_count,refs,class_count,cat_count=read(symtab,'IIHH')
        modules.append(dict(address=hex(va),version=version,name=string(name),symbol_table=hex(symtab),
                            class_count=class_count,category_count=cat_count,selector_ref_count=refs_count))
        for i in range(class_count):
            p,=read(symtab+12+i*4,'I')
            if p not in seen_classes:klass(p);seen_classes.add(p)
        for i in range(cat_count):
            p,=read(symtab+12+(class_count+i)*4,'I')
            if p in seen_cats:continue
            seen_cats.add(p)
            name,owner,inst,clsm,protocols=read(p,'IIIII')
            cname=string(owner);cat=string(name)
            categories.append(dict(address=hex(p),name=cat,owner=cname))
            method_list(inst,cname+'('+cat+')','instance')
            method_list(clsm,cname+'('+cat+')','class')
        va+=size
    functions=json.loads((ROOT/'04_ghidra/exports/x86/full-pass1/functions.json').read_text())
    found={int(f['address'],16) for f in functions}
    missing=[m for m in methods if int(m['imp'],16) not in found]
    headers=[]
    for name in ('objc-class.h','objc-runtime.h'):
        path=ROOT.parent/'ref/openstep/headers/NextDeveloper/Headers/objc'/name
        headers.append(dict(path=str(path),sha256=hashlib.sha256(path.read_bytes()).hexdigest()))
    result=dict(binary_sha256=meta['sha256'],layout_headers=headers,modules=modules,classes=classes,
                categories=categories,methods=methods,missing_ghidra_method_entries=missing)
    OUT.write_text(json.dumps(result,indent=2)+'\n')
    print(dict(modules=len(modules),classes=len(seen_classes),categories=len(categories),methods=len(methods),
               unique_imps=len({m['imp'] for m in methods}),missing_ghidra_imps=len(missing)))
    print(missing[:15])

if __name__=='__main__':main()
