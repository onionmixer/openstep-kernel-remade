
/* WARNING: Removing unreachable block (ram,0xf00258dc) */
/* WARNING: Removing unreachable block (ram,0xf00258a8) */
/* WARNING: Removing unreachable block (ram,0xf00257cc) */
/* WARNING: Removing unreachable block (ram,0xf0025890) */
/* WARNING: Removing unreachable block (ram,0xf00258c0) */
/* WARNING: Removing unreachable block (ram,0xf0025910) */
/* WARNING: Removing unreachable block (ram,0xf0025774) */

undefined8 _dnlc_enter(int param_1,char *param_2,int param_3,sword *param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (_doingcache != 0) {
    pcVar5 = param_2;
    _strlen();
    if ((int)pcVar5 < 0x21) {
      cVar1 = (pcVar5 + (int)param_2)[-1];
      cVar2 = *param_2;
      iVar6 = param_1;
      sub_F0025EC0(param_1,param_2,pcVar5,(uint)(pcVar5 + param_1 + (int)cVar2 + (int)cVar1) & 0x3f,
                   param_4);
      piVar4 = dword_F01355D8;
      if (iVar6 == 0) {
        if (dword_F01355D8 == (int *)&_nc_lru) {
          DAT_f0135600._8_4_ = DAT_f0135600._8_4_ + 1;
        }
        else {
          *(int *)(dword_F01355D8[3] + 8) = dword_F01355D8[2];
          *(int *)(piVar4[2] + 0xc) = piVar4[3];
          *(int *)(*piVar4 + 4) = piVar4[1];
          *(int *)piVar4[1] = *piVar4;
          iVar6 = piVar4[4];
          if (piVar4[5] != 0) {
            if (iVar6 != 0) {
              DAT_f0135600._16_4_ = DAT_f0135600._16_4_ + -1;
            }
            if (piVar4[5] == 0) {
              iVar6 = piVar4[4];
            }
            else {
              _vn_rele();
              iVar6 = piVar4[4];
            }
          }
          if (iVar6 == 0) {
            iVar6 = piVar4[0xf];
          }
          else {
            _vn_rele();
            iVar6 = piVar4[0xf];
          }
          if (iVar6 == 0) {
            cVar3 = *(char *)(piVar4 + 0x11);
          }
          else {
            _crfree();
            cVar3 = *(char *)(piVar4 + 0x11);
          }
          if (cVar3 == '\0') {
            piVar4[5] = param_1;
          }
          else {
            _kfree(piVar4[0x10],(int)*(sword *)((int)piVar4 + 0x46));
            piVar4[5] = param_1;
          }
          *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
          piVar4[4] = param_3;
          *(sword *)(param_3 + 6) = *(sword *)(param_3 + 6) + 1;
          *(char *)(piVar4 + 6) = (char)pcVar5;
          _bcopy(param_2,(int)piVar4 + 0x19);
          *(undefined *)(piVar4 + 0x11) = 0;
          *(undefined2 *)((int)piVar4 + 0x46) = 0;
          piVar4[0x10] = 0;
          piVar4[0xf] = (int)param_4;
          if (param_4 != (sword *)0x0) {
            *param_4 = *param_4 + 1;
          }
          iVar6 = dword_F01355DC;
          iVar7 = *(int *)(dword_F01355DC + 8);
          iVar8 = ((uint)(pcVar5 + param_1 + (int)cVar2 + (int)cVar1) & 0x3f) * 8;
          *(int **)(dword_F01355DC + 8) = piVar4;
          piVar4[2] = iVar7;
          *(int **)(iVar7 + 0xc) = piVar4;
          piVar4[3] = iVar6;
          *piVar4 = *(int *)(_nc_hash + iVar8);
          piVar4[1] = (int)(_nc_hash + iVar8);
          *(int **)(*(int *)(_nc_hash + iVar8) + 4) = piVar4;
          *(int **)(_nc_hash + iVar8) = piVar4;
          DAT_f0135600._16_4_ = DAT_f0135600._16_4_ + 1;
          DAT_f01355f8._0_4_ = DAT_f01355f8._0_4_ + 1;
        }
      }
      else {
        DAT_f01355fc._0_4_ = DAT_f01355fc._0_4_ + 1;
      }
    }
    else {
      DAT_f0135600._0_4_ = DAT_f0135600._0_4_ + 1;
    }
  }
  return CONCAT44(param_2,param_1);
}
