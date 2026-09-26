
void _od_setup(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined2 uVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_2 + 8);
  if ((uint *)(iVar1 + 0x6a) == param_3) {
    if (((*(byte *)(param_2 + 0x18) & 0x40) != 0) || (*(sword *)(iVar1 + 0xd4) == 0xf0))
    goto loc_4075986;
    *(undefined2 *)(iVar1 + 0x86) = 6;
  }
  else {
    if (*(sword *)(param_2 + 0x18) < 0) {
loc_4075986:
      iVar2 = *(int *)(iVar1 + 0xae);
      piVar3 = (int *)((sword)(*(word *)((int)param_3 + 0x1e) & 7) * 0x2e + 0xbe + iVar2);
      *(uint *)(param_1 + 0x230) = param_3[9];
      *(uint *)(param_1 + 0x214) = param_3[8];
      if ((*param_3 & 0x4000010) == 0x10) {
        uVar4 = *(undefined4 *)(*(int *)(*(int *)(param_3[0xb] + 0x66) + 8) + 0x20);
      }
      else {
        uVar4 = _pmap_kernel();
      }
      *(undefined4 *)(param_1 + 0x218) = uVar4;
      iVar7 = (int)(*(int *)(iVar2 + 0x5c) + (param_3[5] - 1)) / *(int *)(iVar2 + 0x5c);
      if ((uint *)(iVar1 + 0x6a) == param_3) {
        *(undefined2 *)(param_1 + 0x248) = *(undefined2 *)(iVar1 + 0xd4);
        *(int *)(param_1 + 0x23c) = iVar7;
        uVar5 = *(uint *)(param_1 + 0x220) | 0x80000;
      }
      else {
        *(int *)(param_1 + 0x230) = *piVar3 + *(int *)(param_1 + 0x230);
        uVar6 = 1;
        if ((*param_3 & 1) != 0) {
          uVar6 = 2;
        }
        *(undefined2 *)(param_1 + 0x248) = uVar6;
        iVar1 = piVar3[1] - param_3[9];
        if (iVar1 < iVar7) {
          iVar7 = iVar1;
        }
        *(int *)(param_1 + 0x23c) = iVar7;
        uVar5 = *(uint *)(param_1 + 0x220) & 0xfff7ffff;
      }
      *(uint *)(param_1 + 0x220) = uVar5;
      param_3[10] = param_3[5] - *(int *)(iVar2 + 0x5c) * *(int *)(param_1 + 0x23c);
      *(undefined *)(param_1 + 0x25f) = 0;
      *(undefined *)(param_1 + 0x25e) = *(undefined *)(param_1 + 0x25f);
      *(undefined *)(param_1 + 0x266) = 0;
      *(undefined *)(param_1 + 0x265) = *(undefined *)(param_1 + 0x266);
      *(undefined *)(*(int *)(param_1 + 0x210) + 0xc) = *(undefined *)(param_1 + 0x26f);
      *(undefined *)(param_1 + 0x271) = 0;
      _od_fsm(param_1,param_2,1);
      _microboot(param_2);
      return;
    }
    *(undefined2 *)(param_3 + 7) = 6;
  }
  *param_3 = *param_3 | 4;
  sub_4075AC0((&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2]);
  return;
}

