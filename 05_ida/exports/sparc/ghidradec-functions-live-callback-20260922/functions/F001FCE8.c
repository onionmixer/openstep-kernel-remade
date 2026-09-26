
/* WARNING: Removing unreachable block (ram,0xf001ff04) */
/* WARNING: Removing unreachable block (ram,0xf001fd3c) */

undefined8 _sogetopt(sword *param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  iVar1 = 1;
  if (param_2 != 0xffff) {
    if (*(int *)(param_1 + 6) == 0) {
      uVar4 = 0x2a;
      goto locret_F001FF1C;
    }
    pcVar3 = *(code **)(*(int *)(param_1 + 6) + 0x18);
    uVar4 = 0;
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(0,param_1,param_2,param_3,param_4);
      goto locret_F001FF1C;
    }
loc_F001FF0C:
    uVar4 = 0x2a;
    goto locret_F001FF1C;
  }
  _m_get(1,10);
  *(undefined2 *)(iVar1 + 8) = 4;
  if (param_3 == 0x100) {
loc_F001FE84:
    uVar2 = (uint)param_1[1];
loc_F001FE88:
    *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = uVar2 & param_3;
  }
  else {
    if ((int)param_3 < 0x101) {
      if (param_3 == 0x10) {
        uVar2 = (uint)param_1[1];
      }
      else {
        if (0x10 < (int)param_3) {
          if (param_3 == 0x40) goto loc_F001FE84;
          if ((int)param_3 < 0x41) {
            if (param_3 == 0x20) {
              uVar2 = (uint)param_1[1];
              goto loc_F001FE88;
            }
          }
          else if (param_3 == 0x80) {
            *(undefined2 *)(iVar1 + 8) = 8;
            *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (word)param_1[1] & 0x80;
            *(int *)(iVar1 + *(int *)(iVar1 + 4) + 4) = (int)param_1[2];
            goto loc_F001FF14;
          }
          goto loc_F001FF04;
        }
        if (param_3 != 4) {
          if ((int)param_3 < 5) {
            if (param_3 == 1) {
              uVar2 = (uint)param_1[1];
              goto loc_F001FE88;
            }
          }
          else if (param_3 == 8) {
            uVar2 = (uint)param_1[1];
            goto loc_F001FE88;
          }
loc_F001FF04:
          _m_free(iVar1);
          goto loc_F001FF0C;
        }
        uVar2 = (uint)param_1[1];
      }
      goto loc_F001FE88;
    }
    if (param_3 == 0x1004) {
      *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x16];
    }
    else if ((int)param_3 < 0x1005) {
      if (param_3 == 0x1002) {
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x13];
      }
      else if ((int)param_3 < 0x1003) {
        if (param_3 != 0x1001) goto loc_F001FF04;
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x1f];
      }
      else {
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x22];
      }
    }
    else if (param_3 == 0x1006) {
      *(int *)(iVar1 + *(int *)(iVar1 + 4)) = (int)param_1[0x17];
    }
    else if ((int)param_3 < 0x1006) {
      *(int *)(iVar1 + *(int *)(iVar1 + 4)) = (int)param_1[0x23];
    }
    else if (param_3 == 0x1007) {
      *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x2b];
      param_1[0x2b] = 0;
    }
    else {
      if (param_3 != 0x1008) goto loc_F001FF04;
      *(int *)(iVar1 + *(int *)(iVar1 + 4)) = (int)*param_1;
    }
  }
loc_F001FF14:
  *param_4 = iVar1;
  uVar4 = 0;
locret_F001FF1C:
  return CONCAT44(param_2,uVar4);
}

