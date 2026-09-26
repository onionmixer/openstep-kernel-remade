
/* WARNING: Removing unreachable block (ram,0xf006b3b4) */
/* WARNING: Removing unreachable block (ram,0xf006b32c) */
/* WARNING: Removing unreachable block (ram,0xf006b2b8) */
/* WARNING: Removing unreachable block (ram,0xf006b278) */
/* WARNING: Removing unreachable block (ram,0xf006b268) */
/* WARNING: Removing unreachable block (ram,0xf006b290) */
/* WARNING: Removing unreachable block (ram,0xf006b308) */
/* WARNING: Removing unreachable block (ram,0xf006b358) */
/* WARNING: Removing unreachable block (ram,0xf006b3bc) */
/* WARNING: Removing unreachable block (ram,0xf006b254) */

undefined8 sub_F006B20C(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
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
  int iVar7;
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
  pcVar5 = (char *)(param_1 + *(int *)(param_1 + 8));
  pcVar4 = pcVar5;
  do {
    if ((char *)(param_1 + *(int *)(param_1 + 4)) <= pcVar4) {
      pcVar5 = (char *)0x2;
      goto locret_F006B3C4;
    }
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  sub_F006B3CC(pcVar5,(undefined *)((int)register0x00000038 + -0x28),
               (undefined *)((int)register0x00000038 + -0x44),
               (undefined *)((int)register0x00000038 + -0x48),
               (undefined *)((int)register0x00000038 + -0x4c));
  if (pcVar5 != (char *)0x0) goto locret_F006B3C4;
  iVar2 = *(int *)((int)register0x00000038 + -0x48);
  _pmap_create();
  _vm_map_create();
  _memset((undefined *)((int)register0x00000038 + -0x40),0,0x14);
  *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
  pcVar5 = *(char **)((int)register0x00000038 + -0x4c);
  sub_F006A83C(pcVar5,iVar2,(undefined *)((int)register0x00000038 + -0x28),
               *(undefined4 *)((int)register0x00000038 + -0x44),
               *(undefined4 *)((int)register0x00000038 + -0x48),param_3,0,
               (undefined *)((int)register0x00000038 + -0x40));
  if (pcVar5 == (char *)0x0) {
    if (*(int *)(iVar2 + 0x1c) < 1) {
      pcVar5 = (char *)0x4;
    }
    else {
      iVar7 = *(int *)(*(int *)(iVar2 + 0x10) + 8);
      iVar6 = *(int *)(*(int *)(iVar2 + 0xc) + 0xc);
      *(int *)((int)register0x00000038 + -0x50) = iVar7;
      iVar6 = iVar6 - iVar7;
      iVar3 = param_2;
      _vm_map_find(param_2,0,0,(undefined *)((int)register0x00000038 + -0x50),iVar6,0);
      if ((iVar3 == 0) ||
         (iVar3 = param_2,
         _vm_map_find(param_2,0,0,(undefined *)((int)register0x00000038 + -0x50),iVar6,1),
         iVar3 == 0)) {
        iVar3 = param_2;
        _vm_map_copy(param_2,iVar2,*(undefined4 *)((int)register0x00000038 + -0x50),iVar6,iVar7,0,0)
        ;
        iVar6 = *(int *)((int)register0x00000038 + -0x50);
        if (iVar3 != 0) goto loc_F006B370;
      }
      else {
loc_F006B370:
        pcVar5 = (char *)0x5;
        iVar6 = *(int *)((int)register0x00000038 + -0x50);
      }
      if (iVar6 != iVar7) {
        *(int *)((int)register0x00000038 + -0x3c) =
             *(int *)((int)register0x00000038 + -0x3c) + (iVar6 - iVar7);
      }
    }
    if (pcVar5 == (char *)0x0) {
      *(uint *)(param_4 + 0x10) = *(uint *)(param_4 + 0x10) | 0x40000000;
      *(undefined4 *)(param_4 + 4) = *(undefined4 *)((int)register0x00000038 + -0x3c);
    }
  }
  _vm_map_deallocate(iVar2);
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
locret_F006B3C4:
  return CONCAT44(param_2,pcVar5);
}
