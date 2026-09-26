
/* WARNING: Removing unreachable block (ram,0xf0098324) */
/* WARNING: Removing unreachable block (ram,0xf009828c) */
/* WARNING: Removing unreachable block (ram,0xf0098254) */
/* WARNING: Removing unreachable block (ram,0xf0098240) */
/* WARNING: Removing unreachable block (ram,0xf0098224) */
/* WARNING: Removing unreachable block (ram,0xf009824c) */
/* WARNING: Removing unreachable block (ram,0xf0098274) */
/* WARNING: Removing unreachable block (ram,0xf009829c) */
/* WARNING: Removing unreachable block (ram,0xf009832c) */
/* WARNING: Removing unreachable block (ram,0xf00981d4) */

undefined8 sub_F00981D0(int param_1,int param_2,undefined *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar6;
  undefined *puVar7;
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
  undefined auStack_30 [48];
  
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
  iVar2 = param_1;
  _prom_childnode();
  puVar6 = (undefined *)((int)register0x00000038 + -0x30);
  if (iVar2 != 0) {
    puVar7 = (undefined *)((int)register0x00000038 + -0xd0);
    do {
      puVar4 = (undefined *)((int)register0x00000038 + -0x30);
      iVar3 = 0x27;
      do {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
        bVar1 = 0 < iVar3;
        iVar3 = iVar3 + -1;
      } while (bVar1);
      iVar3 = iVar2;
      _prom_getprop(iVar2,&_psname,puVar6);
      if (iVar3 != -1) {
        sub_F0098348(iVar2,param_2,param_3,puVar6);
      }
      param_1 = iVar2;
      _prom_getproplen(iVar2,&_psrange);
      udiv();
      iVar3 = param_2;
      puVar4 = param_3;
      if (param_1 - 1U < 7) {
        _prom_getprop(iVar2,&_psrange,puVar7);
        _apply_range_to_range(puVar6,param_2,param_3,param_1,puVar7);
        puVar4 = puVar6;
        _strcmp(puVar6,&aSbus);
        if ((puVar4 == (undefined *)0x0) && (iVar3 = 0, _sbus_numslots = param_1, 0 < param_1)) {
          iVar5 = 0;
          puVar4 = puVar7;
          do {
            iVar3 = iVar3 + 1;
            *(uint *)(_sbus_basepage + iVar5) =
                 *(int *)(puVar4 + 8) << 0x14 | *(uint *)((int)register0x00000038 + -0xc4) >> 0xc;
            *(undefined4 *)(_sbus_slotsize + iVar5) = *(undefined4 *)(puVar4 + 0x10);
            puVar4 = puVar4 + 0x14;
            iVar5 = iVar5 + 4;
          } while (iVar3 < param_1);
        }
        iVar3 = param_1;
        puVar4 = (undefined *)((int)register0x00000038 + -0xd0);
      }
      sub_F00981D0(iVar2,iVar3,puVar4);
      _prom_nextnode();
    } while (iVar2 != 0);
  }
  return CONCAT44(param_2,param_1);
}

