/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012deb4 */

void FUN_0012deb4(int param_1,int *param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint **ppuVar5;
  int iStack_18;
  uint *puStack_14;
  
  if ((*(char **)(param_1 + 0x40) == (char *)0x0) || (**(char **)(param_1 + 0x40) == '\0')) {
    *param_2 = 0xd;
    return;
  }
  puStack_14 = param_3;
  iStack_18 = param_1;
  puVar1 = (uint *)FUN_0012dc2c();
  if (puVar1 == (uint *)0x0) {
    *param_2 = 0x46;
    return;
  }
  puStack_14 = param_3;
  iStack_18 = param_1 + 0x20;
  iVar2 = FUN_0012dc2c();
  if (iVar2 == 0) {
    *param_2 = 0x46;
    ppuVar5 = &puStack_14;
    puStack_14 = puVar1;
    goto LAB_0012dfac;
  }
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) != 0) {
      puStack_14 = param_3 + 6;
      iStack_18 = param_4[7] + 0x10;
      iVar3 = FUN_0012dc70();
      if (iVar3 == 0) goto LAB_0012df4c;
    }
    puStack_14 = *(uint **)(_active_u + 0x1c);
    iStack_18 = *(int *)(param_1 + 0x40);
    iVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x2c))(puVar1,iVar2);
    if (iVar3 == 0x11) {
      puStack_14 = param_4;
      iStack_18 = 0x12df82;
      iVar4 = _svckudp_dup();
      if (iVar4 != 0) {
        iVar3 = 0;
      }
    }
    else if (iVar3 == 0) {
      puStack_14 = param_4;
      iStack_18 = 0x12df9d;
      _svckudp_dupsave();
    }
  }
  else {
LAB_0012df4c:
    iVar3 = 0x1e;
  }
  *param_2 = iVar3;
  iStack_18 = 0x12dfab;
  puStack_14 = puVar1;
  _vn_rele();
  ppuVar5 = (uint **)&iStack_18;
  iStack_18 = iVar2;
LAB_0012dfac:
  *(undefined4 *)((int)ppuVar5 + -4) = 0x12dfb1;
  _vn_rele();
  return;
}

