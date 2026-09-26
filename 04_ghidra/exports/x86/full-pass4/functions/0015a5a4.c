/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a5a4 */

void _object_copyout(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_object_copyout_001ded08);
  }
  if (param_3 == 5) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 0x11;
  }
  if ((param_2 != 0) &&
     (iVar1 = _ipc_object_copyout_compat(*(undefined4 *)(param_1 + 0x88),param_2,uVar2,param_4),
     iVar1 == 0)) {
    return;
  }
  *param_4 = 0;
  return;
}

