/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b060 */

undefined4 _tcp_ctloutput(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = *(int *)(*(int *)(param_2 + 8) + 0x20);
  if (param_3 == 6) {
    if (param_1 == 0) {
      iVar2 = _m_get(1,10);
      *param_5 = iVar2;
      *(undefined2 *)(iVar2 + 8) = 4;
      if (param_4 == 1) {
        *(uint *)(*(int *)(iVar2 + 4) + iVar2) = *(byte *)(iVar1 + 0x1b) & 4;
      }
      else if (param_4 == 2) {
        *(uint *)(*(int *)(iVar2 + 4) + iVar2) = (uint)*(ushort *)(iVar1 + 0x18);
      }
      else {
        local_8 = 0x16;
      }
    }
    else if (param_1 == 1) {
      iVar2 = *param_5;
      if (((param_4 == 1) && (iVar2 != 0)) && (3 < *(ushort *)(iVar2 + 8))) {
        if (*(int *)(*(int *)(iVar2 + 4) + iVar2) == 0) {
          *(byte *)(iVar1 + 0x1b) = *(byte *)(iVar1 + 0x1b) & 0xfb;
        }
        else {
          *(byte *)(iVar1 + 0x1b) = *(byte *)(iVar1 + 0x1b) | 4;
        }
      }
      else {
        local_8 = 0x16;
      }
      if (iVar2 != 0) {
        _m_free(iVar2);
      }
    }
  }
  else {
    local_8 = _ip_ctloutput(param_1,param_2,param_3,param_4,param_5);
  }
  return local_8;
}

