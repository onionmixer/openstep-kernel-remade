/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d690 */

int _access(char *param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  int local_8;
  
  puVar3 = *(undefined4 **)(DAT_001e875c + 0x24);
  uVar5 = _lookupname(*puVar3,0,1,0,&local_8);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return DAT_001e875c;
  }
  iVar6 = *(int *)(_active_u + 0x1c);
  uVar1 = *(undefined2 *)(iVar6 + 2);
  uVar2 = *(undefined2 *)(iVar6 + 4);
  *(undefined2 *)(iVar6 + 2) = *(undefined2 *)(iVar6 + 6);
  *(undefined2 *)(*(int *)(_active_u + 0x1c) + 4) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 8);
  uVar7 = 0;
  uVar4 = puVar3[1];
  if (uVar4 != 0) {
    if ((uVar4 & 4) != 0) {
      uVar7 = 0x100;
    }
    if ((uVar4 & 2) != 0) {
      iVar6 = _isrofile(local_8);
      if (iVar6 != 0) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0x1e;
        goto LAB_0011d75e;
      }
      uVar7 = uVar7 | 0x80;
    }
    if ((*(byte *)(puVar3 + 1) & 1) != 0) {
      uVar7 = uVar7 | 0x40;
    }
    uVar5 = (**(code **)(*(int *)(local_8 + 0x1c) + 0x1c))
                      (local_8,uVar7,*(undefined4 *)(_active_u + 0x1c));
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
  }
LAB_0011d75e:
  _vn_rele(local_8);
  *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2) = uVar1;
  iVar6 = *(int *)(_active_u + 0x1c);
  *(undefined2 *)(iVar6 + 4) = uVar2;
  return iVar6;
}

