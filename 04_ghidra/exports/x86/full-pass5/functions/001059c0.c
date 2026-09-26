/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001059c0 */

int _check_exec_access(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_44 [4];
  byte local_40;
  
  iVar2 = _active_u[7];
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))(param_1,local_44,iVar2);
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40,iVar2), iVar1 == 0)) {
    if (((*(byte *)(*_active_u + 0x28) & 0x10) != 0) &&
       (iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x100,iVar2), iVar2 != 0)) {
      return iVar2;
    }
    if ((*(int *)(param_1 + 0x28) == 1) && ((local_40 & 0x49) != 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}

