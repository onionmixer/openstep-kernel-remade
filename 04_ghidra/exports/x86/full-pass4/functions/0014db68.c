/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014db68 */

undefined4 _ipc_right_reverse(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  do {
    do {
    } while (*param_2 != 0);
    LOCK();
    iVar2 = *param_2;
    *param_2 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (param_2[2] < 0) {
    if (param_2[3] == param_1) {
      iVar2 = param_2[4];
      uVar1 = _ipc_entry_lookup(param_1,iVar2);
      *param_3 = iVar2;
      *param_4 = uVar1;
    }
    else {
      iVar2 = _ipc_hash_lookup(param_1,param_2,param_3,param_4);
      if (iVar2 == 0) goto LAB_0014dbb9;
    }
    uVar1 = 1;
  }
  else {
LAB_0014dbb9:
    LOCK();
    *param_2 = 0;
    UNLOCK();
    uVar1 = 0;
  }
  return uVar1;
}

