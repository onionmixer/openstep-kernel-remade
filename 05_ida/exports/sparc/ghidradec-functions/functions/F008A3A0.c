
/* WARNING: Removing unreachable block (ram,0xf008a454) */
/* WARNING: Removing unreachable block (ram,0xf008a3e0) */
/* WARNING: Removing unreachable block (ram,0xf008a3ec) */
/* WARNING: Removing unreachable block (ram,0xf008a47c) */
/* WARNING: Removing unreachable block (ram,0xf008a3c4) */

undefined8
_vm_object_special(sword param_1,code *param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  uint uVar8;
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
  iVar7 = 0;
  uVar1 = param_5 + _page_mask & ~_page_mask;
  uVar8 = uVar1 >> ((byte)_page_shift & 0x1f);
  _vm_object_allocate();
  puVar5 = (undefined4 *)(uVar8 * 0x30 + 0x10);
  puVar2 = puVar5;
  _kalloc();
  _bzero();
  *puVar2 = 1;
  puVar2[1] = uVar1;
  puVar2[2] = puVar2;
  puVar2[3] = puVar5;
  puVar5 = puVar2 + 4;
  if (0 < (int)uVar8) {
    piVar6 = puVar2 + 0xd;
    do {
      *(undefined2 *)(piVar6 + -2) = 1;
      iVar3 = (int)param_1;
      (*param_2)(iVar3,param_4 + (iVar7 << ((byte)_page_shift & 0x1f)),param_3);
      bVar4 = (byte)_page_shift;
      *piVar6 = iVar3 << (bVar4 & 0x1f);
      _vm_page_insert(puVar5,uVar1,iVar7 << (bVar4 & 0x1f));
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 0xc;
      puVar5 = puVar5 + 0xc;
    } while (iVar7 < (int)uVar8);
  }
  _vm_object_setpager(uVar1,puVar2,0,0);
  return CONCAT44(param_2,uVar1);
}
