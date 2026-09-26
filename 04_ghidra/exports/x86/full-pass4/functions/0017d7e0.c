/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d7e0 */

int _mach_swapon(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  int *local_18;
  int local_14;
  undefined1 local_10 [4];
  char *local_c;
  size_t local_8;
  
  iVar1 = _suser();
  if (iVar1 == 0) {
    return 0xd;
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 0;
  local_14 = 0;
  iVar1 = _pn_get(param_1,0,local_10);
  if (iVar1 != 0) {
    return 0x16;
  }
  pcVar2 = (char *)_kalloc(local_8 + 1);
  _strncpy(pcVar2,local_c,local_8);
  pcVar2[local_8] = '\0';
  iVar1 = _lookuppn(local_10,1,0,&local_14);
  _pn_free(local_10);
  if (iVar1 == 0) {
    if (*(int *)(local_14 + 0x28) == 1) {
      local_18 = DAT_001e7288;
      if ((int **)DAT_001e7288 != &DAT_001e7288) {
        do {
          if (local_18[2] == local_14) break;
          local_18 = (int *)*local_18;
        } while ((int **)local_18 != &DAT_001e7288);
        if ((int **)local_18 != &DAT_001e7288) {
          iVar1 = 0x10;
          goto LAB_0017d8e7;
        }
      }
      iVar1 = _vnode_pager_file_init(&local_18,local_14,param_3,param_4);
      if (iVar1 == 0) {
        local_18[0xb] = param_2 & 1;
        local_18[10] = (int)pcVar2;
        pcVar2 = (char *)0x0;
      }
    }
    else {
      iVar1 = 0x16;
    }
  }
LAB_0017d8e7:
  if (local_14 != 0) {
    _vn_rele(local_14);
  }
  if (pcVar2 != (char *)0x0) {
    _kfree(pcVar2,local_8 + 1);
  }
  return iVar1;
}

