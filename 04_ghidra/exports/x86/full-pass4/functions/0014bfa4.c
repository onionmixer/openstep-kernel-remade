/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014bfa4 */

undefined4 _ipc_object_copyout_dest(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_8;
  
  uVar4 = 0;
  iVar1 = param_2[1];
  param_2[1] = iVar1 + -1;
  if (param_3 == 0x11) {
    iVar3 = 0;
    local_8 = 0;
    iVar1 = param_2[7];
    param_2[7] = iVar1 + -1;
    if ((iVar1 == 1) && (iVar3 = param_2[9], iVar3 != 0)) {
      param_2[9] = 0;
      local_8 = param_2[6];
    }
    uVar4 = 0;
    if (param_2[3] == param_1) {
      uVar4 = param_2[4];
    }
    LOCK();
    uVar2 = *param_2;
    *param_2 = 0;
    UNLOCK();
    if (iVar3 != 0) {
      uVar2 = _ipc_notify_no_senders(iVar3,local_8);
    }
  }
  else {
    if (param_3 != 0x12) {
                    /* WARNING: Subroutine does not return */
      _panic(s_ipc_object_copyout_dest__strange_001de903);
    }
    if (param_2[3] == param_1) {
      param_2[8] = param_2[8] + -1;
      uVar4 = param_2[4];
      LOCK();
      uVar2 = *param_2;
      *param_2 = 0;
      UNLOCK();
    }
    else {
      param_2[1] = iVar1;
      LOCK();
      *param_2 = 0;
      UNLOCK();
      uVar2 = _ipc_notify_send_once(param_2);
    }
  }
  *param_4 = uVar4;
  return uVar2;
}

