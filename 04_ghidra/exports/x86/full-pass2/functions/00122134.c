/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00122134 */

void _arpwhohas(undefined4 param_1,void *param_2,undefined4 param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  undefined2 local_14;
  undefined1 local_12 [14];
  
  iVar1 = _m_get(0,1);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    local_14 = 0x806;
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    _bcopy(&local_14,local_12 + (uint)DAT_001db968 * 2,2);
    _bcopy((void *)(DAT_001db969 + 0x1db96c + (uint)DAT_001db968),local_12,(uint)DAT_001db968);
    iVar2 = 0x7c - *(short *)(iVar1 + 8);
    *(int *)(iVar1 + 4) = iVar2;
    puVar3 = (ushort *)(iVar2 + iVar1);
    _bcopy(&_arpethertempl,puVar3,(int)*(short *)(iVar1 + 8));
    _bcopy(param_2,puVar3 + 4,(uint)DAT_001db968);
    _bcopy(&param_3,(void *)((int)puVar3 + DAT_001db968 + 8),(uint)DAT_001db969);
    _bcopy(param_4,(void *)(DAT_001db969 + 8 + (uint)DAT_001db968 * 2 + (int)puVar3),
           (uint)DAT_001db969);
    *puVar3 = *puVar3 >> 8 | *puVar3 << 8;
    puVar3[1] = puVar3[1] >> 8 | puVar3[1] << 8;
    puVar3[3] = puVar3[3] >> 8 | puVar3[3] << 8;
    local_14 = 0;
    _if_output_mbuf(param_1,iVar1,&local_14);
  }
  return;
}

