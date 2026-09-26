
/* WARNING: Removing unreachable block (ram,0xf00d0b98) */
/* WARNING: Removing unreachable block (ram,0xf00d0ae8) */
/* WARNING: Removing unreachable block (ram,0xf00d0ad4) */
/* WARNING: Removing unreachable block (ram,0xf00d0b80) */
/* WARNING: Removing unreachable block (ram,0xf00d0be8) */
/* WARNING: Removing unreachable block (ram,0xf00d0ac4) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00d0b98 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[SCSIGeneric getSense:](void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 in_o0_1;
  undefined8 uVar3;
  qword qVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined8 in_o2_3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
  undefined4 uVar8;
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
  
  puVar6 = (undefined4 *)((qword)in_o2_3 >> 0x20);
  puVar1 = (undefined4 *)((qword)in_o0_1 >> 0x20);
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
  puVar7 = (uint *)((int)register0x00000038 + -0x6c);
  _objc_msgSend();
  _bzero((undefined *)((int)register0x00000038 + -0x70));
  _objc_msgSend();
  *(char *)((int)register0x00000038 + -0x70) = (char)*(undefined8 *)(puVar1 + 0x42);
  uVar3 = *(undefined8 *)(puVar1 + 0x44);
  *(char *)((int)register0x00000038 + -0x6f) = (char)uVar3;
  *(undefined *)((int)register0x00000038 + -0x60) = 1;
  if (*(uint *)((int)register0x00000038 + -0x78) < 2) {
    uVar3 = 0x1c00000000;
  }
  *(int *)((int)register0x00000038 + -0x5c) = (int)((qword)uVar3 >> 0x20);
  *(undefined4 *)((int)register0x00000038 + -0x58) = 10;
  *(uint *)((int)register0x00000038 + -0x54) =
       *(uint *)((int)register0x00000038 + -0x54) & 0x7fffffff;
  *(undefined *)puVar7 = 3;
  uVar3 = *(undefined8 *)(puVar1 + 0x44);
  qVar4 = CONCAT44((int)uVar3,*puVar7) & 0x7ff1fffff;
  iVar2 = (int)(qVar4 >> 0x20);
  uVar5 = (uint)qVar4;
  *puVar7 = uVar5 | iVar2 << 0x15;
  *(undefined *)((int)register0x00000038 + -0x68) = 0x1c;
  uVar8 = puVar1[0x4a];
  _IOVmTaskSelf();
  _objc_msgSend(uVar8,uVar5,(undefined *)((int)register0x00000038 + -0x70),(int)uVar3,iVar2);
  if (iVar2 == 0) {
    *puVar6 = *puVar1;
    puVar6[1] = puVar1[1];
    puVar6[2] = puVar1[2];
    puVar6[3] = puVar1[3];
    puVar6[4] = puVar1[4];
    puVar6[5] = puVar1[5];
    puVar6[6] = puVar1[6];
  }
  _IOFree();
  return iVar2;
}

