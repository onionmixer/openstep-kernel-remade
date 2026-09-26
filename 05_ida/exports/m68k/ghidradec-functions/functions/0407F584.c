
word _sfa_abort(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  word wVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  if ((*(byte *)((int)param_2 + 0x13) & 1) == 0) {
    piVar1 = *(int **)(param_1 + 6);
    piVar4 = (int *)(param_1 + 6);
    iVar5 = (int)piVar1 - (int)piVar4;
    while( true ) {
      bVar7 = iVar5 < 0;
      bVar9 = SBORROW4((int)piVar1,(int)piVar4);
      bVar10 = piVar1 < piVar4;
      bVar8 = true;
      if (piVar1 == piVar4) break;
      if (param_2 == piVar1) {
        piVar2 = (int *)piVar1[2];
        piVar1 = (int *)piVar1[3];
        if (piVar2 == piVar4) {
          *(int **)(param_1 + 10) = piVar1;
        }
        else {
          piVar2[3] = (int)piVar1;
        }
        if (piVar1 == piVar4) {
          *piVar4 = (int)piVar2;
        }
        else {
          piVar1[2] = (int)piVar2;
        }
        bVar3 = *(byte *)(param_1 + 4);
        bVar10 = bVar3 == 0;
        bVar9 = SBORROW1(bVar3,'\x01');
        *(byte *)(param_1 + 4) = bVar3 - 1;
        bVar7 = (int)((uint)(byte)(bVar3 - 1) << 0x18) < 0;
        bVar8 = (*(byte *)((int)param_2 + 0x13) & 4) == 0;
        if (!bVar8) {
          iVar5 = *(int *)(param_1 + 0x16);
          bVar10 = iVar5 == 0;
          bVar9 = SBORROW4(iVar5,1);
          iVar5 = iVar5 + -1;
          *(int *)(param_1 + 0x16) = iVar5;
          bVar7 = iVar5 < 0;
          bVar8 = iVar5 == 0;
        }
        break;
      }
      piVar1 = (int *)piVar1[2];
      iVar5 = (int)piVar1 - (int)piVar4;
    }
    wVar6 = (word)(byte)(bVar10 << 4 | bVar7 << 3 | bVar8 << 2 | bVar9 << 1 | bVar10);
  }
  else {
    wVar6 = _sfa_relinquish(param_1,param_2,param_3);
  }
  return wVar6;
}
