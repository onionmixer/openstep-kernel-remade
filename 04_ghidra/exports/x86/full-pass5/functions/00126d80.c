/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00126d80 */

int _ip_srcroute(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((_ip_nhops == 0) || (iVar2 = _m_get(0,10), iVar2 == 0)) {
    iVar2 = 0;
  }
  else {
    iVar1 = _ip_nhops * 4;
    *(short *)(iVar2 + 8) = (short)iVar1 + 4;
    *(undefined4 *)(*(int *)(iVar2 + 4) + iVar2) = *(undefined4 *)(&DAT_001e5908 + iVar1);
    DAT_001e5908 = 1;
    _bcopy(&DAT_001e5908,(void *)(iVar2 + *(int *)(iVar2 + 4) + 4),4);
    puVar3 = (undefined4 *)(iVar2 + *(int *)(iVar2 + 4) + 8);
    for (puVar4 = (undefined4 *)(&DAT_001e5904 + iVar1); (undefined4 *)0x1e590b < puVar4;
        puVar4 = puVar4 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
    }
  }
  return iVar2;
}

