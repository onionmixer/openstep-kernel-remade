/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117258 */

int _socketpair(int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _useracc(puVar1[3],8,0);
  iVar4 = DAT_001e875c;
  if (iVar3 == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0xe;
    return iVar4;
  }
  uVar2 = _socreate(*puVar1,&local_8,puVar1[1],puVar1[2]);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return DAT_001e875c;
  }
  uVar2 = _socreate(*puVar1,&local_c,puVar1[1],puVar1[2]);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    iVar4 = _falloc();
    if (iVar4 != 0) {
      local_14 = *(int *)(DAT_001e875c + 0x60);
      *(undefined4 *)(iVar4 + 8) = 3;
      *(undefined2 *)(iVar4 + 0xc) = 2;
      *(undefined ***)(iVar4 + 0x14) = &_socketops;
      *(undefined4 *)(iVar4 + 0x18) = local_8;
      *(int *)(*(int *)(_active_u + 0x150) + *(int *)(DAT_001e875c + 0x60) * 4) = iVar4;
      iVar3 = _falloc();
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 8) = 3;
        *(undefined2 *)(iVar3 + 0xc) = 2;
        *(undefined ***)(iVar3 + 0x14) = &_socketops;
        *(undefined4 *)(iVar3 + 0x18) = local_c;
        *(int *)(*(int *)(_active_u + 0x150) + *(int *)(DAT_001e875c + 0x60) * 4) = iVar3;
        local_10 = *(int *)(DAT_001e875c + 0x60);
        uVar2 = _soconnect2(local_8,local_c);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
        if (*(char *)(DAT_001e875c + 0x68) == '\0') {
          if (puVar1[1] != 2) {
LAB_001173d2:
            *(undefined4 *)(DAT_001e875c + 0x60) = 0;
            iVar4 = _copyout(&local_14,puVar1[3],8);
            return iVar4;
          }
          uVar2 = _soconnect2(local_c,local_8);
          *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
          if (*(char *)(DAT_001e875c + 0x68) == '\0') goto LAB_001173d2;
        }
        *(undefined2 *)(iVar3 + 0xe) = 0;
        *(undefined4 *)(*(int *)(_active_u + 0x150) + local_10 * 4) = 0;
      }
      *(undefined2 *)(iVar4 + 0xe) = 0;
      *(undefined4 *)(*(int *)(_active_u + 0x150) + local_14 * 4) = 0;
    }
    _soclose(local_c);
  }
  iVar4 = _soclose(local_8);
  return iVar4;
}

