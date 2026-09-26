/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117590 */

void _sendit(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  int local_8;
  
  iVar2 = _getsock(param_1);
  if (iVar2 == 0) {
    return;
  }
  local_1c = param_2[2];
  local_18 = param_2[3];
  local_10 = 0;
  local_14 = 0;
  local_8 = 0;
  local_c = 0;
  puVar6 = (undefined4 *)param_2[2];
  iVar5 = 0;
  if (0 < param_2[3]) {
    piVar4 = puVar6 + 1;
    do {
      iVar3 = *piVar4;
      if (iVar3 < 0) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
        return;
      }
      if (iVar3 != 0) {
        iVar3 = _useracc(*puVar6,iVar3,1);
        if (iVar3 == 0) {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0xe;
          return;
        }
        local_8 = local_8 + *piVar4;
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 2;
      puVar6 = puVar6 + 2;
    } while (iVar5 < param_2[3]);
  }
  if (*param_2 == 0) {
    local_20 = 0;
  }
  else {
    uVar1 = _sockargs(&local_20,*param_2,param_2[1],8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') {
      return;
    }
  }
  if (param_2[4] == 0) {
    local_24 = 0;
  }
  else {
    uVar1 = _sockargs(&local_24,param_2[4],param_2[5],0xc);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') goto LAB_00117704;
  }
  iVar5 = local_8;
  uVar1 = _sosend(*(undefined4 *)(iVar2 + 0x18),local_20,&local_1c,param_3,local_24);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
  *(int *)(DAT_001e875c + 0x60) = iVar5 - local_8;
  if (local_24 != 0) {
    _m_freem(local_24);
  }
LAB_00117704:
  if (local_20 != 0) {
    _m_freem(local_20);
  }
  return;
}

