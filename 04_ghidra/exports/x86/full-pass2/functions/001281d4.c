/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001281d4 */

void _ip_mloopback(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = _m_copy(param_2,0,1000000000);
  if (iVar2 != 0) {
    pbVar3 = (byte *)(iVar2 + *(int *)(iVar2 + 4));
    *(ushort *)(pbVar3 + 2) = *(ushort *)(pbVar3 + 2) >> 8 | *(ushort *)(pbVar3 + 2) << 8;
    *(ushort *)(pbVar3 + 6) = *(ushort *)(pbVar3 + 6) >> 8 | *(ushort *)(pbVar3 + 6) << 8;
    pbVar3[10] = 0;
    pbVar3[0xb] = 0;
    uVar1 = _in_cksum(iVar2,(*pbVar3 & 0xf) << 2);
    *(undefined2 *)(pbVar3 + 10) = uVar1;
    _looutput(param_1,iVar2,param_3);
  }
  return;
}

