
undefined4 _sbappendrights(word *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  word wVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = 0;
  puVar3 = param_2;
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSbappendrights);
  }
  for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    iVar6 = *(sword *)(puVar3 + 2) + iVar6;
  }
  iVar4 = (uint)param_1[1] - (uint)*param_1;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)((uint)param_1[1] - (uint)*param_1)) {
    iVar4 = (uint)param_1[3] - (uint)param_1[2];
  }
  if ((iVar4 < *(sword *)(param_3 + 8) + iVar6) ||
     (iVar6 = _m_copy(param_3,0,(int)*(sword *)(param_3 + 8)), iVar6 == 0)) {
    uVar5 = 0;
  }
  else {
    *param_1 = *(sword *)(iVar6 + 8) + *param_1;
    wVar2 = param_1[2];
    param_1[2] = wVar2 + 0x80;
    if (0x7c < *(uint *)(iVar6 + 4)) {
      param_1[2] = wVar2 + 0x480;
    }
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 == 0) {
      *(int *)(param_1 + 6) = iVar6;
    }
    else {
      iVar1 = *(int *)(iVar4 + 0x7c);
      while (iVar1 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar1 = *(int *)(iVar4 + 0x7c);
      }
      *(int *)(iVar4 + 0x7c) = iVar6;
    }
    if (param_2 != (undefined4 *)0x0) {
      _sbcompress(param_1,param_2,iVar6);
    }
    uVar5 = 1;
  }
  return uVar5;
}
