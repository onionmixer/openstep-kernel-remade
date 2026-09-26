/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125bd0 */

void _icmp_reflect(byte *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short local_8;
  
  iVar4 = 0;
  iVar1 = (*param_1 & 0xf) * 4 + -0x14;
  iVar2 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
  iVar3 = _in_ifaddr;
  if (_in_ifaddr != 0) {
    while (*(int *)(iVar3 + 4) != iVar2) {
      if ((((*(byte *)(*(int *)(iVar3 + 0x20) + 0xc) & 2) != 0) && (*(int *)(iVar3 + 0x14) == iVar2)
          ) || (iVar3 = *(int *)(iVar3 + 0x40), iVar3 == 0)) break;
    }
    if (iVar3 != 0) goto LAB_00125c36;
  }
  iVar3 = _ifptoia(param_2);
  if (iVar3 == 0) {
    iVar3 = _in_ifaddr;
  }
LAB_00125c36:
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar3 + 4);
  param_1[8] = 0xff;
  if (0 < iVar1) {
    iVar4 = _ip_srcroute();
    local_8 = (short)iVar1;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) - local_8;
    _ip_stripoptions(param_1,0);
  }
  _icmp_send(param_1,iVar4);
  if (iVar4 != 0) {
    _m_free(iVar4);
  }
  return;
}

