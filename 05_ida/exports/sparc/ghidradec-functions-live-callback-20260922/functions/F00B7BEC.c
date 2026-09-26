
/* WARNING: Removing unreachable block (ram,0xf00b7c54) */
/* WARNING: Removing unreachable block (ram,0xf00b7c1c) */
/* WARNING: Removing unreachable block (ram,0xf00b7c4c) */
/* WARNING: Removing unreachable block (ram,0xf00b7c7c) */
/* WARNING: Removing unreachable block (ram,0xf00b7c14) */

undefined8
_esplog(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
       undefined4 param_6)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
  undefined8 in_l4_5;
  undefined8 uVar6;
  undefined4 unaff_l6;
  undefined4 uVar7;
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
    *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)in_l4_5 >> 0x20);
    *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)in_l4_5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar6 = *(undefined8 *)((int)register0x00000038 + 0x60);
  puVar2 = (undefined *)((int)register0x00000038 + -0x48);
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x6c);
  uVar3 = *(undefined4 *)((int)register0x00000038 + 0x70);
  _sprintf(puVar2,&aEspD,*(undefined *)(param_1 + 0x30));
  puVar1 = puVar2;
  _strlen(puVar2);
  _sprintf(puVar2 + (int)puVar1,param_3,param_4,param_5,param_6,uVar7,(int)((qword)uVar6 >> 0x20),
           (int)uVar6,uVar5,uVar4,uVar3);
  puVar1 = puVar2;
  _strlen();
  ((undefined *)((int)register0x00000038 + -8) + (int)puVar1)[-0x40] = 10;
  ((undefined *)((int)register0x00000038 + -8) + (int)puVar1)[-0x3f] = 0;
  _log(param_2,puVar2);
  return CONCAT44(param_2,param_1);
}

