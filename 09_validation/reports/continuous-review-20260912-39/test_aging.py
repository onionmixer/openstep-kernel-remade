"""Corrupt recorded boundary evidence; these are not executed fault injections."""
import copy
import json
import audit_aging as A
import inputs as I


def main():
    rows=json.loads((I.HERE/'aging-cases.json').read_text())
    def select(delta,age):
        return next(r for r in rows if r['input']['kind']=='all_age_bytes' and
                    r['input']['tick']-r['input']['last']==delta and r['input']['age']==age)
    keep=select(256,0);remove=select(1,8)
    negative=next(r for r in rows if r['input']['last']==1 and r['input']['tick']==0 and r['input']['active'])
    invalid=next(r for r in rows if r['outcome']=='execution_error')
    controls=[]
    def reject(name,base,change):
        row=copy.deepcopy(base);change(row)
        try:A.check(row)
        except AssertionError:controls.append({'name':name,'rejected':True})
        else:raise AssertionError('accepted corruption: '+name)
    reject('256_elapsed_forced_remove',keep,lambda r:r.__setitem__('outcome','remove_decision'))
    reject('256_age_incremented',keep,lambda r:r['after'].__setitem__('age',1))
    reject('decision_pretends_RET',remove,lambda r:r.__setitem__('outcome','returned'))
    reject('decision_advances_last',remove,lambda r:r['after'].__setitem__('last',r['input']['tick']))
    reject('negative_index_clamped',negative,lambda r:r['threshold_reads'][0].__setitem__('address',0x1e2600))
    reject('negative_value_fabricated',negative,lambda r:r['threshold_reads'][0].__setitem__('value',8))
    reject('missing_invalid_read',invalid,lambda r:r.__setitem__('invalid',[]))
    reject('wrong_invalid_width',invalid,lambda r:r['invalid'][0].__setitem__('width',1))
    reject('missing_threshold_read',keep,lambda r:r.__setitem__('threshold_reads',[]))
    reject('missing_CMP_point',keep,lambda r:r.__setitem__('points',[p for p in r['points'] if p['pc']!=0x191174]))
    reject('wrong_CMP_signed_flag',keep,lambda r:next(p for p in r['points'] if p['pc']==0x191174)['cpu'].__setitem__('eflags',0))
    reject('changed_branch_head',keep,lambda r:r['trace'].__setitem__(1,0x191147))
    reject('extra_trace_head',keep,lambda r:r['trace'].append(0x1913ea))
    reject('missing_stack_write',keep,lambda r:r['writes'].pop(0))
    reject('extra_stack_write',keep,lambda r:r['writes'].append(dict(r['writes'][0])))
    reject('wrong_stack_value',keep,lambda r:r['writes'][0].__setitem__('value',0))
    reject('wrong_stack_capture',keep,lambda r:r['after'].__setitem__('stack','00'*0x2c))
    reject('callee_saved_changed',keep,lambda r:r['cpu'].__setitem__('ebx',0))
    reject('second_PDE_changed',keep,lambda r:r['after'].__setitem__('second_pde',0))
    reject('invented_second_PDE_read',keep,lambda r:r['pde_reads'].append({'pc':0x1912ba,'address':0x60000c,'width':1,'value':3}))
    reject('missing_owner_dereference',keep,lambda r:r.__setitem__('owner_reads',[]))
    reject('extended_wired_width',keep,lambda r:r['input'].__setitem__('wired',0x10000))
    for name,pc,key,value in (
        ('threshold_EA_register_mismatch',0x191276,'edx',0),
        ('CMP_AL_register_mismatch',0x1912eb,'eax',0x123400ff),
        ('selected_PDE_pointer_mismatch',0x1912af,'edx',0x60000c),
        ('checkpoint_ESP_mismatch',0x1913db,'esp',0xdeadbeef),
        ('checkpoint_EIP_mismatch',0x191274,'eip',0xdeadbeef)):
        reject(name,keep,lambda r,pc=pc,key=key,value=value:next(p for p in r['points'] if p['pc']==pc)['cpu'].__setitem__(key,value))
    reject('decision_final_stack_mismatch',remove,lambda r:r['cpu'].update(esp=0xdeadbeef,ebp=0xdeadbeef))
    reject('error_final_stack_mismatch',invalid,lambda r:r['cpu'].update(esp=0xdeadbeef,ebp=0xdeadbeef))
    reject('negative_threshold_EBX_mismatch',negative,lambda r:next(p for p in r['points'] if p['pc']==0x191283)['cpu'].__setitem__('ebx',0))
    reject('equal_flags_wrong_delta_operand',keep,lambda r:next(p for p in r['points'] if p['pc']==0x191174)['cpu'].__setitem__('ebx',512))
    reject('wrong_last_ADD_source_operand',keep,lambda r:next(p for p in r['points'] if p['pc']==0x1913db)['cpu'].__setitem__('ebx',0))
    out={'controls':controls,'all_rejected':True,'scope':'record corruptions, not CPU input mutations',
         'whole_goal_complete':False}
    (I.HERE/'negative-controls.json').write_text(json.dumps(out,indent=2)+'\n')
    print(json.dumps({'rejected':len(controls)}))


if __name__=='__main__':main()
