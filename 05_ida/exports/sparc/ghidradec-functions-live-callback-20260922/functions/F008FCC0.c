
/* WARNING: Removing unreachable block (ram,0xf008fe34) */
/* WARNING: Removing unreachable block (ram,0xf008fe18) */
/* WARNING: Removing unreachable block (ram,0xf008fde0) */
/* WARNING: Removing unreachable block (ram,0xf008fd54) */
/* WARNING: Removing unreachable block (ram,0xf008fd14) */
/* WARNING: Removing unreachable block (ram,0xf008fd08) */
/* WARNING: Removing unreachable block (ram,0xf008fd38) */
/* WARNING: Removing unreachable block (ram,0xf008fd74) */
/* WARNING: Removing unreachable block (ram,0xf008fdf4) */
/* WARNING: Removing unreachable block (ram,0xf008fe28) */
/* WARNING: Removing unreachable block (ram,0xf008fcf0) */
/* WARNING: Removing unreachable block (ram,0xf008fcd4) */

undefined8
-[KernDeviceDescription _parseRangeResourceByKey:value:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined5 *puVar3;
  int iVar4;
  undefined (*pauVar5) [14];
  undefined *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined5 *puVar7;
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
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  _objc_msgSend(iVar1,paLookupresource,param_3);
  if (iVar1 == 0) {
    _printf(aSCouldnTLocate,param_3);
    puVar7 = (undefined5 *)0x0;
  }
  else {
    puVar7 = paList;
    _objc_msgSend(paList,paAlloc);
    _objc_msgSend();
    *(int *)((int)register0x00000038 + -0x14) = param_4;
    if (param_4 != 0) {
      _objc_msgSend(param_1,paIsshared,param_3);
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
      while (sub_F008FA58(iVar2,(undefined *)((int)register0x00000038 + -0x14),
                          (undefined *)((int)register0x00000038 + -0x18)), iVar2 != 0) {
        iVar2 = *(int *)((int)register0x00000038 + -0x14) + 1;
        *(int *)((int)register0x00000038 + -0x14) = iVar2;
        sub_F008FA58(iVar2,(undefined *)((int)register0x00000038 + -0x14),
                     (undefined *)((int)register0x00000038 + -0x1c));
        iVar4 = *(int *)((int)register0x00000038 + -0x18);
        if (iVar2 == 0) break;
        *(int *)((int)register0x00000038 + -0x30) = iVar4;
        iVar2 = (*(int *)((int)register0x00000038 + -0x1c) - iVar4) + 1;
        *(int *)((int)register0x00000038 + -0x2c) = iVar2;
        *(int *)((int)register0x00000038 + -0x28) = iVar4;
        *(int *)((int)register0x00000038 + -0x24) = iVar2;
        if ((char)param_1 == '\0') {
          *(int *)((int)register0x00000038 + -0x38) = iVar4;
          *(int *)((int)register0x00000038 + -0x34) = iVar2;
          puVar6 = (undefined *)((int)register0x00000038 + -0x38);
          pauVar5 = paReserverange;
        }
        else {
          *(int *)((int)register0x00000038 + -0x30) = iVar4;
          *(int *)((int)register0x00000038 + -0x2c) = iVar2;
          puVar6 = (undefined *)((int)register0x00000038 + -0x30);
          pauVar5 = (undefined (*) [14])paSharerange;
        }
        iVar2 = iVar1;
        _objc_msgSend(iVar1,pauVar5,puVar6);
        puVar3 = puVar7;
        _objc_msgSend(puVar7,paAddobject,iVar2);
        if (puVar3 == (undefined5 *)0x0) {
          _printf(aSCouldnTReserv,param_3,*(undefined4 *)((int)register0x00000038 + -0x18),
                  *(undefined4 *)((int)register0x00000038 + -0x1c));
          _objc_msgSend(puVar7,paFreeobjects);
          _objc_msgSend();
          break;
        }
        iVar2 = *(int *)((int)register0x00000038 + -0x14);
      }
    }
  }
  return CONCAT44(param_2,puVar7);
}

