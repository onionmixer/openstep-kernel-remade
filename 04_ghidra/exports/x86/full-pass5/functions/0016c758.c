/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016c758 */

int FUN_0016c758(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_c;
  
  local_c = -200;
  if (param_2 == 0) {
    return -0x12f;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_2 + 0x4ac) == iVar1) {
    local_c = -0x12f;
    goto LAB_0016c8ab;
  }
  if (*(int *)(param_2 + 0x4b0) == iVar1) {
    iVar1 = param_2 + 0x18c + *(int *)(param_2 + 0x4b4) * 0x10;
    if (*(int *)(iVar1 + 0xc) == 0) {
      local_c = (**(code **)(iVar1 + 4))(param_1,*(undefined4 *)(iVar1 + 8));
      goto LAB_0016c8ab;
    }
    iVar2 = _kalloc(0x2000);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 8);
    (**(code **)(iVar1 + 4))(param_1,iVar2);
    iVar1 = *(int *)(iVar2 + 0x1c);
  }
  else {
    iVar2 = 0;
    iVar3 = 0;
    do {
      if (*(int *)(iVar3 + 0x18c + param_2) == iVar1) break;
      iVar3 = iVar3 + 0x10;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x32);
    if (iVar2 == 0x32) goto LAB_0016c8ab;
    *(int *)(param_2 + 0x4b0) = iVar1;
    *(int *)(param_2 + 0x4b4) = iVar2;
    iVar1 = param_2 + 0x18c + iVar2 * 0x10;
    if (*(int *)(iVar1 + 0xc) == 0) {
      local_c = (**(code **)(iVar1 + 4))(param_1,*(undefined4 *)(iVar1 + 8));
      goto LAB_0016c8ab;
    }
    iVar2 = _kalloc(0x2000);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 8);
    (**(code **)(iVar1 + 4))(param_1,iVar2);
    iVar1 = *(int *)(iVar2 + 0x1c);
  }
  if (iVar1 == -0x131) {
    local_c = 0;
  }
  else {
    local_c = _msg_send(iVar2,0,0);
  }
  _kfree(iVar2,0x2000);
LAB_0016c8ab:
  if (local_c == -200) {
    *(undefined4 *)(param_2 + 0x4ac) = *(undefined4 *)(param_1 + 0xc);
    local_c = -0x12f;
  }
  return local_c;
}

