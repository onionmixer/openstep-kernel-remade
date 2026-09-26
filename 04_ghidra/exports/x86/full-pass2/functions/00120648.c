/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00120648 */

undefined4 FUN_00120648(undefined4 param_1,char *param_2,short *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = _if_private(param_1);
  uVar2 = *(undefined4 *)(iVar1 + 0x14);
  iVar1 = _strcmp(param_2,"autoaddr");
  if (iVar1 == 0) {
    if (*param_3 == 2) {
      iVar1 = _if_private(param_1);
      uVar2 = _in_bootp(param_1,param_3,iVar1 + 8);
      return uVar2;
    }
  }
  else {
    iVar1 = _strcmp(param_2,"setaddr");
    if (iVar1 != 0) {
      uVar2 = _if_control(uVar2,param_2,param_3);
      return uVar2;
    }
    if (*param_3 == 2) {
      uVar3 = _if_flags(param_1);
      _if_flags_set(param_1,uVar3 | 0x8001);
      iVar1 = _if_init(uVar2);
      if (iVar1 == 0) {
        uVar3 = _if_flags(param_1);
        _if_flags_set(param_1,uVar3 | 0x40);
      }
      iVar1 = _if_private(param_1);
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_3 + 2);
      uVar3 = _if_flags(param_1);
      if ((uVar3 & 0x4000) == 0) {
        iVar1 = _if_private(param_1,param_3 + 2);
        iVar1 = _if_private(param_1,*(undefined4 *)(iVar1 + 0x10));
        _arpwhohas(param_1,iVar1 + 8);
      }
      return 0;
    }
  }
  return 0x2f;
}

