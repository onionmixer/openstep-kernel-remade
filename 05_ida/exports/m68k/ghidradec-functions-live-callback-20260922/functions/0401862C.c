
void _dnlc_enter(int param_1,char *param_2,int param_3,sword *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (_doingcache != 0) {
    iVar4 = _strlen(param_2);
    if (iVar4 < 0x21) {
      uVar2 = param_1 + iVar4 + (int)param_2[iVar4 + -1] + (int)*param_2 & 0x3f;
      iVar5 = sub_4018BAE(param_1,param_2,iVar4,uVar2,param_4);
      piVar3 = dword_40B6D68;
      if (iVar5 == 0) {
        if (dword_40B6D68 == (int *)&_nc_lru) {
          dword_40B6D8C = dword_40B6D8C + 1;
        }
        else {
          *(int *)(dword_40B6D68[3] + 8) = dword_40B6D68[2];
          *(int *)(piVar3[2] + 0xc) = piVar3[3];
          *(int *)(*piVar3 + 4) = piVar3[1];
          *(int *)piVar3[1] = *piVar3;
          if (piVar3[5] != 0) {
            if (piVar3[4] != 0) {
              dword_40B6D94 = dword_40B6D94 + -1;
            }
            if (piVar3[5] != 0) {
              _vn_rele(piVar3[5]);
            }
          }
          if (piVar3[4] != 0) {
            _vn_rele(piVar3[4]);
          }
          if (*(int *)((int)piVar3 + 0x3a) != 0) {
            _crfree(*(int *)((int)piVar3 + 0x3a));
          }
          if (*(char *)((int)piVar3 + 0x42) != '\0') {
            _kfree(*(undefined4 *)((int)piVar3 + 0x3e),(int)*(sword *)(piVar3 + 0x11));
          }
          piVar3[5] = param_1;
          *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
          piVar3[4] = param_3;
          *(sword *)(param_3 + 6) = *(sword *)(param_3 + 6) + 1;
          *(char *)(piVar3 + 6) = (char)iVar4;
          _bcopy(param_2,(int)piVar3 + 0x19,iVar4);
          *(undefined *)((int)piVar3 + 0x42) = 0;
          *(undefined2 *)(piVar3 + 0x11) = 0;
          *(undefined4 *)((int)piVar3 + 0x3e) = 0;
          *(sword **)((int)piVar3 + 0x3a) = param_4;
          if (param_4 != (sword *)0x0) {
            *param_4 = *param_4 + 1;
          }
          iVar5 = dword_40B6D6C;
          iVar4 = *(int *)(dword_40B6D6C + 8);
          *(int **)(dword_40B6D6C + 8) = piVar3;
          piVar3[2] = iVar4;
          *(int **)(iVar4 + 0xc) = piVar3;
          piVar3[3] = iVar5;
          piVar1 = &_nc_hash + uVar2 * 2;
          *piVar3 = *piVar1;
          piVar3[1] = (int)piVar1;
          *(int **)(*piVar1 + 4) = piVar3;
          *piVar1 = (int)piVar3;
          dword_40B6D94 = dword_40B6D94 + 1;
          dword_40B6D7C = dword_40B6D7C + 1;
        }
      }
      else {
        dword_40B6D80 = dword_40B6D80 + 1;
      }
    }
    else {
      dword_40B6D84 = dword_40B6D84 + 1;
    }
  }
  return;
}

