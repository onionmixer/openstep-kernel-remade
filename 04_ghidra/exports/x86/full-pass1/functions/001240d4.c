/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001240d4 */

void _in_delmulti(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined1 local_24 [16];
  undefined2 local_14;
  undefined4 local_10;
  
  uVar4 = _splnet();
  iVar2 = param_1[3];
  param_1[3] = iVar2 + -1;
  if (iVar2 == 1) {
    _igmp_leavegroup(param_1);
    piVar1 = (int *)(param_1[2] + 0x44);
    puVar3 = *(undefined4 **)(param_1[2] + 0x44);
    while (puVar3 != param_1) {
      iVar2 = *piVar1;
      piVar1 = (int *)(iVar2 + 0x14);
      puVar3 = *(undefined4 **)(iVar2 + 0x14);
    }
    *piVar1 = *(int *)(*piVar1 + 0x14);
    local_14 = 2;
    local_10 = *param_1;
    _if_ioctl(param_1[1],0x80206932,local_24);
    _m_free((uint)param_1 & 0xffffff80);
  }
  _splx(uVar4);
  return;
}

