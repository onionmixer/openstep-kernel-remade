
undefined8
_in_pcbnotify(int *param_1,sword *param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  byte bVar1;
  sword *psVar2;
  undefined4 unaff_l0;
  int *piVar3;
  int *piVar4;
  undefined4 unaff_l1;
  code *pcVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar6;
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
  iVar6 = *param_4;
  pcVar5 = *(code **)((int)register0x00000038 + 0x5c);
  if ((param_6 < 0x16) && (*param_2 == 2)) {
    param_2 = *(sword **)(param_2 + 2);
    if (param_2 != (sword *)0x0) {
      if (((param_6 - 0xe < 4) || (param_6 == 6)) || (param_6 == 1)) {
        param_3 = 0;
        param_5 = 0;
        iVar6 = 0;
        if (param_6 != 6) {
          pcVar5 = _in_rtchange;
        }
      }
      piVar3 = (int *)*param_1;
      bVar1 = _inetctlerrmap[param_6];
      if (piVar3 != param_1) {
        psVar2 = (sword *)piVar3[3];
        do {
          if (psVar2 == param_2) {
            if (piVar3[7] == 0) {
loc_F0030E98:
              piVar4 = (int *)*piVar3;
            }
            else if (((param_5 & 0xffff) == 0) ||
                    ((uint)*(word *)(piVar3 + 6) == (param_5 & 0xffff))) {
              if ((iVar6 == 0) || (piVar3[5] == iVar6)) {
                if (((param_3 & 0xffff) != 0) && ((uint)*(word *)(piVar3 + 4) != (param_3 & 0xffff))
                   ) goto loc_F0030E98;
                if (bVar1 != 0) {
                  *(word *)(piVar3[7] + 0x56) = (word)bVar1;
                }
                piVar4 = (int *)*piVar3;
                if (pcVar5 != (code *)0x0) {
                  (*pcVar5)(piVar3);
                }
              }
              else {
                piVar4 = (int *)*piVar3;
              }
            }
            else {
              piVar4 = (int *)*piVar3;
            }
          }
          else {
            piVar4 = (int *)*piVar3;
          }
          if (piVar4 == param_1) break;
          psVar2 = (sword *)piVar4[3];
          piVar3 = piVar4;
        } while( true );
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
