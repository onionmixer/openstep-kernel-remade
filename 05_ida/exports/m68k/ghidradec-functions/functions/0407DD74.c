
void sub_407DD74(int *param_1,int param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if (iVar4 == 0) {
    iVar4 = param_1[1];
    param_1[1] = 0;
  }
  puVar2 = (uint *)_disksort_first(iVar4 + 0x60);
  if (puVar2 != (uint *)0x0) {
    puVar2[10] = param_2 + puVar2[10];
    *puVar2 = param_3 | *puVar2;
    if ((param_3 & 4) != 0) {
      if (param_4 == 0x10) {
        *(undefined2 *)(puVar2 + 7) = 6;
      }
      else if (param_4 == 0x11) {
        *(undefined2 *)(puVar2 + 7) = 0x1e;
      }
      else {
        *(undefined2 *)(puVar2 + 7) = 5;
      }
    }
    _disksort_remove(iVar4 + 0x60,puVar2);
    if ((uint *)(iVar4 + 0x18) == puVar2) {
      iVar3 = *(int *)(iVar4 + 0x5c);
      *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x14) - param_2;
      *(int *)(iVar3 + 0x1c) = param_4;
      if (param_4 == 2) {
        *(undefined *)(iVar3 + 0x20) = 2;
        puVar1 = *(undefined4 **)(iVar4 + 0xc6);
        *(undefined4 *)(iVar3 + 0x22) = *puVar1;
        *(undefined4 *)(iVar3 + 0x26) = puVar1[1];
        *(undefined4 *)(iVar3 + 0x2a) = puVar1[2];
        *(undefined4 *)(iVar3 + 0x2e) = puVar1[3];
        *(undefined4 *)(iVar3 + 0x32) = puVar1[4];
        *(undefined4 *)(iVar3 + 0x36) = puVar1[5];
        *(undefined2 *)(iVar3 + 0x3a) = *(undefined2 *)(puVar1 + 6);
      }
      else {
        *(undefined *)(iVar3 + 0x20) = *(undefined *)(param_1[2] + 0x4e);
      }
    }
    *(undefined *)(param_1 + 4) = 0;
    iVar3 = _disksort_first(iVar4 + 0x60);
    if (iVar3 == 0) {
      *(word *)(iVar4 + 10) = *(word *)(iVar4 + 10) & 0xfeff;
    }
    else {
      sub_407D376(iVar4);
    }
    _biodone(puVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aSddoneNoBufOnS_0);
}
