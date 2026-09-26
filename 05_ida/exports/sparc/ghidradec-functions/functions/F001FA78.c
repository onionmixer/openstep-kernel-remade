
/* WARNING: Removing unreachable block (ram,0xf001fcd4) */
/* WARNING: Removing unreachable block (ram,0xf001fc68) */

undefined8 _sosetopt(int param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
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
  undefined4 uVar2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(int *)((int)register0x00000038 + 0x50) = param_4;
  uVar2 = 0;
  if (param_2 != 0xffff) {
    if (*(int *)(param_1 + 0xc) == 0) {
      uVar2 = 0x2a;
    }
    else {
      pcVar1 = *(code **)(*(int *)(param_1 + 0xc) + 0x18);
      uVar2 = 1;
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)(1,param_1,param_2,param_3,(undefined *)((int)register0x00000038 + 0x50));
        goto locret_F001FCE0;
      }
      uVar2 = 0x2a;
    }
    goto loc_F001FCCC;
  }
  if (param_3 == 0x20) {
loc_F001FBA4:
    if (param_4 == 0) {
      uVar2 = 0x16;
    }
    else if (*(word *)(param_4 + 8) < 4) {
      uVar2 = 0x16;
    }
    else if (*(int *)(param_4 + *(int *)(param_4 + 4)) == 0) {
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) & ~(word)param_3;
    }
    else {
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | (word)param_3;
    }
  }
  else {
    if (0x20 < param_3) {
      if (param_3 != 0x100) {
        if (param_3 < 0x101) {
          if (param_3 == 0x40) goto loc_F001FBA4;
          if (param_3 == 0x80) {
            if (param_4 == 0) {
              uVar2 = 0x16;
            }
            else {
              if (*(sword *)(param_4 + 8) == 8) {
                *(sword *)(param_1 + 4) =
                     (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4) + 4);
                goto loc_F001FBA4;
              }
              uVar2 = 0x16;
            }
          }
          else {
            uVar2 = 0x2a;
          }
        }
        else if (param_3 < 0x1007) {
          if (param_3 < 0x1001) {
            uVar2 = 0x2a;
          }
          else if (param_4 == 0) {
            uVar2 = 0x16;
          }
          else if (*(word *)(param_4 + 8) < 4) {
            uVar2 = 0x16;
          }
          else {
            switch(param_3) {
            case :
            case :
              if (param_3 == 0x1001) {
                param_1 = param_1 + 0x3c;
              }
              else {
                param_1 = param_1 + 0x24;
              }
              _sbreserve(param_1,*(undefined4 *)(param_4 + *(int *)(param_4 + 4)));
              if (param_1 == 0) {
                uVar2 = 0x37;
              }
              break;
            case :
              *(sword *)(param_1 + 0x44) = (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4));
              break;
            case :
              *(sword *)(param_1 + 0x2c) = (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4));
              break;
            case :
              *(sword *)(param_1 + 0x46) = (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4));
              break;
            case :
              *(sword *)(param_1 + 0x2e) = (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4));
            }
          }
        }
        else {
          uVar2 = 0x2a;
        }
        goto loc_F001FCCC;
      }
      goto loc_F001FBA4;
    }
    if (param_3 == 4) goto loc_F001FBA4;
    if (param_3 < 5) {
      if (param_3 == 1) goto loc_F001FBA4;
      uVar2 = 0x2a;
    }
    else {
      if ((param_3 == 8) || (param_3 == 0x10)) goto loc_F001FBA4;
      uVar2 = 0x2a;
    }
  }
loc_F001FCCC:
  if (param_4 != 0) {
    _m_free(param_4);
  }
locret_F001FCE0:
  return CONCAT44(param_2,uVar2);
}
