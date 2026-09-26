/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c9b0 */

int _vnode_pager_allocpage(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int local_c;
  
  _lock_write(param_1 + 0x34);
  if (*(int *)(param_1 + 0x18) == 0) {
    _lock_done(param_1 + 0x34);
    iVar2 = -1;
  }
  else {
    iVar2 = 0;
    local_c = *(int *)(param_1 + 0x24);
    if (local_c < 0) {
      local_c = local_c + 7;
    }
    local_c = local_c >> 3;
    while( true ) {
      iVar3 = *(int *)(param_1 + 0x14) + 7;
      if (iVar3 < 0) {
        iVar3 = *(int *)(param_1 + 0x14) + 0xe;
      }
      if (iVar3 >> 3 <= local_c) goto LAB_0017ca54;
      if (*(char *)(local_c + *(int *)(param_1 + 0x10)) != -1) break;
      local_c = local_c + 1;
    }
    iVar2 = 0;
    do {
      iVar3 = iVar2;
      if (iVar2 < 0) {
        iVar3 = iVar2 + 7;
      }
    } while ((((uint)(int)*(char *)((iVar3 >> 3) + local_c + *(int *)(param_1 + 0x10)) >>
               (iVar2 + (iVar3 >> 3) * -8 & 0x1fU) & 1) != 0) && (iVar2 = iVar2 + 1, iVar2 < 8));
LAB_0017ca54:
    iVar2 = iVar2 + local_c * 8;
    if (*(int *)(param_1 + 0x14) <= iVar2) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vnode_pager_allocpage_001e0e5c);
    }
    if (*(int *)(param_1 + 0x20) < iVar2) {
      *(int *)(param_1 + 0x20) = iVar2;
    }
    iVar3 = iVar2;
    if (iVar2 < 0) {
      iVar3 = iVar2 + 7;
    }
    pbVar1 = (byte *)((iVar3 >> 3) + *(int *)(param_1 + 0x10));
    *pbVar1 = *pbVar1 | (byte)(1 << ((char)iVar2 + (char)(iVar3 >> 3) * -8 & 0x1fU));
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    *(int *)(param_1 + 0x24) = iVar2;
    _lock_done(param_1 + 0x34);
  }
  return iVar2;
}

