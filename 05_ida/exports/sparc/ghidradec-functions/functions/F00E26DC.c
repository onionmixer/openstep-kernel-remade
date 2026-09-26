
/* WARNING: Removing unreachable block (ram,0xf00e2758) */
/* WARNING: Removing unreachable block (ram,0xf00e26f4) */

undefined8 _audio_makeIMuLawTab(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
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
  undefined auStackX_0 [92];
  sword asStack_808 [512];
  int aiStack_408 [258];
  
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
  if (dword_F012EF60 == 0) {
    iVar1 = 0x4000;
    _IOMalloc();
    iVar5 = 0;
    iVar4 = 0;
    puVar2 = (undefined2 *)((int)register0x00000038 + -0x808);
    puVar3 = (undefined *)((int)register0x00000038 + -8);
    do {
      *(undefined2 **)(puVar3 + -0x400) = puVar2;
      *puVar2 = (sword)iVar5;
      puVar3 = puVar3 + 4;
      iVar5 = iVar5 + 1;
      puVar2[1] = *(sword *)(_audio_muLaw + iVar4) >> 2;
      iVar4 = iVar4 + 2;
      puVar2 = puVar2 + 2;
    } while (iVar5 < 0x100);
    dword_F012EF60 = iVar1;
    _qsort((undefined *)((int)register0x00000038 + -0x408),0x100,4,sub_F00E2890);
    iVar1 = 0;
    iVar4 = -0x2000;
    puVar3 = (undefined *)((int)register0x00000038 + -8);
    do {
      puVar2 = *(undefined2 **)(puVar3 + -0x400);
      if ((int)puVar3 <= (int)((int)register0x00000038 + 0x3f0)) {
        if ((0 < iVar4 - (sword)puVar2[1]) &&
           (*(sword *)(*(int *)(puVar3 + -0x3fc) + 2) - iVar4 < iVar4 - (sword)puVar2[1])) {
          puVar3 = puVar3 + 4;
        }
        puVar2 = *(undefined2 **)(puVar3 + -0x400);
      }
      *(char *)(dword_F012EF60 + iVar1) = (char)*puVar2;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar1 < 0x4000);
  }
  return CONCAT44(param_2,param_1);
}
