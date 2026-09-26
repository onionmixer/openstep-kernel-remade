"""Diagnostic corruption controls and a non-executed RF model positive control."""
import copy
import json
from pathlib import Path
import struct
import audit_native as A
import native_probe as P

HERE = Path(__file__).resolve().parent


def main():
    data = json.loads((HERE / 'native-probe.json').read_text())
    controls, positives = [], []
    def reject(name, callback):
        try:
            callback()
        except AssertionError:
            controls.append({'name':name,'rejected':True})
        else:
            raise AssertionError('accepted corruption: ' + name)
    for row in data['cases']:
        directory = HERE / ('case-' + format(row['flags'],'x'))
        A.check(row,directory)
        raw = bytes.fromhex(row['raw_output_hex'])
        reject('strict_RF_failure_' + str(row['flags']),lambda: P.decode(raw,row))
        # In-memory model counterfactual only. No guest/source/output file is modified.
        altered = bytearray(raw)
        for index in range(2):
            struct.pack_into('<I',altered,index*32+5*4,row['flags'] | (1 << 16))
        P.decode(altered,row)
        positives.append({'name':'hypothetical_RF_present_' + str(row['flags']),'executed_on_CPU':False})
    base = data['cases'][0]
    directory = HERE / 'case-2'
    def alter_row(name, change):
        row = copy.deepcopy(base)
        change(row)
        reject(name,lambda: A.check(row,directory))
    alter_row('misclaim_strict_pass',lambda r:r.__setitem__('strict_contract_passed',True))
    alter_row('wrong_CR3_geometry',lambda r:r['geometry'].__setitem__('PD',0x2000))
    alter_row('wrong_store_label',lambda r:r['labels'].__setitem__('store',r['labels']['store']+1))
    alter_row('truncated_output',lambda r:r.__setitem__('raw_output_hex',r['raw_output_hex'][:-2]))
    alter_row('forged_output_hash',lambda r:r['hashes'].__setitem__('output.bin','0'*64))
    alter_row('empty_hash_set',lambda r:r.__setitem__('hashes',{}))
    alter_row('missing_BIOS_hash',lambda r:r['hashes'].pop('bios.bin'))
    alter_row('unexpected_hash_name',lambda r:r['hashes'].__setitem__('extra.bin','0'*64))
    alter_row('invented_command',lambda r:r.__setitem__('command',['not-the-recorded-command']))
    alter_row('wrong_loader_address',lambda r:r['command'].__setitem__(-1,r['command'][-1].replace('0x200000','0x210000')))
    alter_row('wrong_CPU_model',lambda r:r['command'].__setitem__(r['command'].index('qemu32'),'pentium'))
    alter_row('wrong_program_length',lambda r:r['code_lengths'].__setitem__('program',263))
    alter_row('wrong_opcode_provenance',lambda r:r['original_opcodes'].__setitem__('0x189d1b','908819'))
    tables = (directory/'tables.bin').read_bytes()
    for name,offset,value in (('PF_gate_not_present',0x3000+14*8+5,0xf),
        ('PF_interrupt_gate_substitution',0x3000+14*8+5,0x8e),('wrong_CS_base',0x2000+8+7,0),
        ('user_PTE_already_present',0x8800,7),('missing_high_PDE',0x1c00,0)):
        raw = bytearray(tables);raw[offset]=value
        reject(name,lambda: A.table_check(raw))
    code = (directory/'code.bin').read_bytes()
    for name,address,value in (('initial_ESP_changed',0x10000b,0x180100),
        ('record_pointer_aliases_saved_flags',0x10004c,0x17ffe0),
        ('PTE_clear_keeps_present',0x10008b,0x200007),
        ('record_output_reads_stack',0x1000d3,0x17ffec)):
        raw=bytearray(code)
        struct.pack_into('<I',raw,address-0x100000,value)
        reject(name,lambda: A.code_check(raw,base))
    for name,offset,value in (('wrong_ES_register',0x10002d-0x100000,0xd8),
        ('changed_program_padding',0x800,0x90),('changed_fatal_exit',0x2008,0x10)):
        raw=bytearray(code);raw[offset]=value
        reject(name,lambda: A.code_check(raw,base))
    bios=(directory/'bios.bin').read_bytes()
    for name,offset in (('reset_jump_changed',0xfff1),('bootstrap_GDTR_changed',0x102),
                        ('PIC_mask_changed',0xb),('bootstrap_PE_changed',0x20),
                        ('bootstrap_far_selector_changed',0x2a),('ROM_padding_changed',0x200)):
        raw=bytearray(bios);raw[offset]^=1
        reject(name,lambda: A.bios_check(raw))
    # Exhaustive single-byte perturbation of the executed main/helper contract.
    # This is fixture sensitivity testing, not exhaustive CPU behavior testing.
    for offset in range(base['code_lengths']['program']):
        raw=bytearray(code);raw[offset]^=1
        reject('program_byte_' + hex(offset),lambda: A.code_check(raw,base))
    for name,offset,value in (('remove_FS_override',base['labels']['store']-0x100000,0x90),
        ('wrong_frame_source_offset',0x10101f-0x100000+3,0x1c),
        ('missing_error_word_discard',0x101042-0x100000+2,8),('replace_IRETD',0x101045-0x100000,0xc3)):
        raw=bytearray(code);raw[offset]=value
        reject(name,lambda: A.code_check(raw,base))
    out={'controls':controls,'all_rejected':True,'model_positives':positives,
         'RF_contract_passed':False,'scope':'record integrity/model controls; hypothetical RF positives were never executed'}
    (HERE/'negative-controls.json').write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps({'rejected':len(controls),'nonexecuted_model_positives':len(positives),'RF_contract_passed':False}))


if __name__ == '__main__':
    main()
