
undefined4 _stopen(word param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  uVar2 = (param_1 & 0xff) >> 3;
  iVar3 = uVar2 * 0x166;
  piVar5 = (int *)(_st_std + iVar3);
  puVar1 = *(undefined **)(_st_std + iVar3 + 0xc);
  if ((_st_std[iVar3 + 0x67] & 0x10) != 0) {
    return 0x10;
  }
  if ((1 < uVar2) || (*piVar5 == 0)) {
    return 6;
  }
  sub_408856E(*piVar5);
  iVar4 = sub_40887EA(piVar5,1);
  if ((iVar4 == 0) || (iVar4 = sub_40887EA(piVar5,1), iVar4 == 0)) {
    if ((param_1 & 2) == 0) {
loc_408871C:
      *(word *)(_st_std + iVar3 + 0x66) = *(word *)(_st_std + iVar3 + 0x66) | 0x10;
      return 0;
    }
    iVar4 = sub_4089510(piVar5,0,0);
    if (iVar4 == 0) {
      *(word *)(_st_std + iVar3 + 0x66) = *(word *)(_st_std + iVar3 + 0x66) | 0x20;
      *(undefined4 *)(puVar1 + 0x3c) = 0x11;
      iVar4 = sub_40889C2(piVar5,*(undefined4 *)(_st_std + iVar3 + 0xc),0);
      if (iVar4 == 0) {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = puVar1[2] & 0x7f;
        puVar1[3] = 8;
        *(uint *)(puVar1 + 8) = *(uint *)(puVar1 + 8) & 0xff000000;
        *(uint *)(puVar1 + 4) = *(uint *)(puVar1 + 4) & 0xff000000;
        puVar1[2] = puVar1[2] & 0x9f | 0x10;
        puVar1[0xc] = puVar1[0xc] & 0xdf | 0xe;
        iVar4 = sub_4088958(piVar5,*(undefined4 *)(_st_std + iVar3 + 0xc),0);
        if (iVar4 == 0) goto loc_408871C;
      }
    }
  }
  return 5;
}

