
/* WARNING: Removing unreachable block (ram,0xf00ae158) */
/* WARNING: Removing unreachable block (ram,0xf00ae120) */
/* WARNING: Removing unreachable block (ram,0xf00ae1b4) */
/* WARNING: Removing unreachable block (ram,0xf00ae18c) */
/* WARNING: Removing unreachable block (ram,0xf00ae024) */
/* WARNING: Removing unreachable block (ram,0xf00ae084) */
/* WARNING: Removing unreachable block (ram,0xf00ae198) */
/* WARNING: Removing unreachable block (ram,0xf00ae104) */
/* WARNING: Removing unreachable block (ram,0xf00ae138) */
/* WARNING: Removing unreachable block (ram,0xf00ae1e0) */
/* WARNING: Removing unreachable block (ram,0xf00ae050) */

undefined8 __fp_pack(uint *param_1,undefined *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar4;
  undefined4 unaff_i2;
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
  if (param_4 == 1) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x10);
    sub_F00AD810(param_1,param_2,puVar3);
    uVar1 = param_1[3] & *param_1;
joined_r0xf00ae064:
    if (uVar1 != 0) goto locret_F00AE254;
  }
  else {
    if (param_4 < 2) {
      puVar3 = (undefined *)((int)register0x00000038 + -0xc);
      sub_F00AD718(param_1,param_2,puVar3);
      uVar1 = param_1[3] & *param_1;
      goto joined_r0xf00ae064;
    }
    if (param_4 == 2) {
      puVar3 = (undefined *)((int)register0x00000038 + -0x18);
      sub_F00ADABC(param_1,param_2,(undefined *)((int)register0x00000038 + -0x14),puVar3);
      param_2 = puVar3;
      if ((param_1[3] & *param_1) != 0) goto locret_F00AE254;
      (*(code *)param_1[6])((undefined *)((int)register0x00000038 + -0x14),param_3 & 0xfffe,param_1)
      ;
      param_3 = (param_3 & 0xfffe) + 1;
    }
    else {
      if (param_4 != 3) goto locret_F00AE254;
      uVar1 = param_1[2];
      if (uVar1 == 2) {
        sub_F00ADABC(param_1,param_2,(undefined *)((int)register0x00000038 + -0x4c),
                     (undefined *)((int)register0x00000038 + -0x50));
        param_2 = (undefined *)((int)register0x00000038 + -0x40);
        *(undefined4 *)((int)register0x00000038 + -0x48) =
             *(undefined4 *)((int)register0x00000038 + -0x4c);
        _unpackdouble(param_1,param_2,(undefined *)((int)register0x00000038 + -0x48),
                      *(undefined4 *)((int)register0x00000038 + -0x50));
      }
      else if (uVar1 < 3) {
        if (uVar1 == 1) {
          sub_F00AD810(param_1,param_2,(undefined *)((int)register0x00000038 + -0x44));
          param_2 = (undefined *)((int)register0x00000038 + -0x40);
          *(undefined4 *)((int)register0x00000038 + -0x48) =
               *(undefined4 *)((int)register0x00000038 + -0x44);
          _unpacksingle(param_1,param_2,(undefined *)((int)register0x00000038 + -0x48));
        }
      }
      else if (uVar1 == 3) {
        if (*(int *)(param_2 + 8) + 0x3fff < 0) {
          iVar2 = 0x31 - (*(int *)(param_2 + 8) + 0x3fff);
        }
        else {
          iVar2 = 0x31;
        }
        _fpu_rightshift(param_2,0x31);
        sub_F00AD5F8(param_1,param_2);
        *(undefined4 *)(param_2 + 0x1c) = 0;
        *(undefined4 *)(param_2 + 0x20) = 0;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + iVar2;
        _fpu_normalize(param_2);
      }
      puVar4 = (undefined *)((int)register0x00000038 + -0x58);
      puVar3 = (undefined *)((int)register0x00000038 + -0x60);
      sub_F00ADD98(param_1,param_2,(undefined *)((int)register0x00000038 + -0x54),puVar4,
                   (undefined *)((int)register0x00000038 + -0x5c),puVar3);
      param_2 = puVar4;
      if ((param_1[3] & *param_1) != 0) goto locret_F00AE254;
      param_3 = param_3 & 0xfffc;
      (*(code *)param_1[6])((undefined *)((int)register0x00000038 + -0x54),param_3,param_1);
      (*(code *)param_1[6])(puVar4,param_3 + 1,param_1);
      (*(code *)param_1[6])((undefined *)((int)register0x00000038 + -0x5c),param_3 + 2,param_1);
      param_3 = param_3 + 3;
    }
  }
  (*(code *)param_1[6])(puVar3,param_3,param_1);
locret_F00AE254:
  return CONCAT44(param_2,param_1);
}
