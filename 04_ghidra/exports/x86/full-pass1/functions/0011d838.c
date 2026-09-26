/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d838 */

ssize_t _readlink(char *param_1,char *param_2,size_t param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  uVar2 = _lookupname(*puVar1,0,0,0,&local_20);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  iVar3 = DAT_001e875c;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    if (*(int *)(local_20 + 0x28) == 5) {
      local_28 = puVar1[1];
      local_24 = puVar1[2];
      local_1c = &local_28;
      local_18 = 1;
      local_14 = 0;
      local_10 = 0;
      local_8 = puVar1[2];
      uVar2 = (**(code **)(*(int *)(local_20 + 0x1c) + 0x44))
                        (local_20,&local_1c,*(undefined4 *)(_active_u + 0x1c));
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    }
    _vn_rele(local_20);
    iVar3 = DAT_001e875c;
    *(int *)(DAT_001e875c + 0x60) = puVar1[2] - local_8;
  }
  return iVar3;
}

