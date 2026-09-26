/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a10d8 */

int _PCldt(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 local_8;
  
  iVar1 = _suser();
  if (iVar1 == 0) {
    iVar1 = 5;
  }
  else {
    iVar1 = _object_copyin(*(undefined4 *)(_active_threads + 0xc),param_1,6,0,&local_8);
    if (iVar1 != 0) {
      iVar1 = _convert_port_to_thread(local_8);
      _port_release(local_8);
      if (iVar1 != 0) {
        iVar3 = *(int *)(*(int *)(iVar1 + 0x28) + 0x70);
        if (iVar3 == 0) {
          puVar2 = (undefined2 *)_thread_user_state(iVar1);
        }
        else {
          puVar2 = (undefined2 *)(iVar3 + 0x84);
        }
        if ((param_2 == -1) && (param_3 == -1)) {
          iVar3 = _task_default_ldt(*(undefined4 *)(iVar1 + 0xc));
        }
        else {
          iVar3 = _task_locate_ldt(*(undefined4 *)(iVar1 + 0xc),param_2,param_3);
        }
        if (iVar3 == 0) {
          puVar2[0x1e] = 99;
          puVar2[0x24] = 0x6b;
          puVar2[6] = 0x6b;
          puVar2[4] = 0x6b;
          puVar2[2] = 0;
          *puVar2 = 0;
        }
        _thread_deallocate(iVar1);
        return iVar3;
      }
    }
    iVar1 = 4;
  }
  return iVar1;
}

