/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e570 */

void FUN_0016e570(int *param_1,int param_2)

{
  int iVar1;
  processor_set_t pVar2;
  processor_t processor;
  kern_return_t kVar3;
  processor_set_t new_set;
  boolean_t wait;
  
  if ((((param_1[1] == 0x28) && (*param_1 < 0)) && ((param_1[6] & 0x3fffffffU) == 0x10012011)) &&
     (param_1[8] == DAT_001e0144)) {
    pVar2 = _convert_port_to_pset(param_1[7]);
    wait = param_1[9];
    new_set = pVar2;
    processor = _convert_port_to_processor(param_1[2]);
    kVar3 = _processor_assign(processor,new_set,wait);
    *(kern_return_t *)(param_2 + 0x1c) = kVar3;
    _pset_deallocate(pVar2);
    if (((*(int *)(param_2 + 0x1c) == 0) && (iVar1 = param_1[7], iVar1 != 0)) && (iVar1 != -1)) {
      _ipc_port_release_send(iVar1);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

