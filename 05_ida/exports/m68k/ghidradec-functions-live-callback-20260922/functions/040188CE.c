
int _dnlc_lookup(int param_1,char *param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (_doingcache == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = _strlen(param_2);
    if (iVar4 < 0x21) {
      uVar2 = param_1 + iVar4 + (int)param_2[iVar4 + -1] + (int)*param_2 & 0x3f;
      piVar5 = (int *)sub_4018BAE(param_1,param_2,iVar4,uVar2,param_3);
      if (piVar5 == (int *)0x0) {
        dword_40B6D78 = dword_40B6D78 + 1;
        iVar4 = 0;
      }
      else {
        _ncstats = _ncstats + 1;
        *(int *)(piVar5[3] + 8) = piVar5[2];
        *(int *)(piVar5[2] + 0xc) = piVar5[3];
        iVar3 = dword_40B6D6C;
        iVar4 = *(int *)(dword_40B6D6C + 8);
        *(int **)(dword_40B6D6C + 8) = piVar5;
        piVar5[2] = iVar4;
        *(int **)(iVar4 + 0xc) = piVar5;
        piVar5[3] = iVar3;
        if (&_nc_hash + uVar2 * 2 != (undefined4 *)piVar5[1]) {
          *(undefined4 **)(*piVar5 + 4) = (undefined4 *)piVar5[1];
          *(int *)piVar5[1] = *piVar5;
          piVar1 = *(int **)(piVar5[1] + 4);
          *piVar5 = *piVar1;
          piVar5[1] = (int)piVar1;
          *(int **)(*piVar1 + 4) = piVar5;
          *piVar1 = (int)piVar5;
        }
        iVar4 = piVar5[4];
      }
    }
    else {
      dword_40B6D88 = dword_40B6D88 + 1;
      iVar4 = 0;
    }
  }
  return iVar4;
}

