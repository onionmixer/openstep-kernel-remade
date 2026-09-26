/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e9dc */

void FUN_0016e9dc(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if ((((param_1[1] == 0x28) && (*param_1 < 0)) && ((param_1[6] & 0x3fffffffU) == 0x10012011)) &&
     (param_1[8] == DAT_001e0170)) {
    uVar2 = _convert_port_to_thread(param_1[2]);
    uVar3 = _convert_port_to_pset(param_1[7]);
    uVar4 = _thread_max_priority(uVar2,uVar3,param_1[9]);
    *(undefined4 *)(param_2 + 0x1c) = uVar4;
    _pset_deallocate(uVar3);
    _thread_deallocate(uVar2);
    if (((*(int *)(param_2 + 0x1c) == 0) && (iVar1 = param_1[7], iVar1 != 0)) && (iVar1 != -1)) {
      _ipc_port_release_send(iVar1);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

