
/* WARNING: Removing unreachable block (ram,0xf00c41f0) */
/* WARNING: Removing unreachable block (ram,0xf00c41cc) */
/* WARNING: Removing unreachable block (ram,0xf00c4190) */
/* WARNING: Removing unreachable block (ram,0xf00c416c) */
/* WARNING: Removing unreachable block (ram,0xf00c4134) */
/* WARNING: Removing unreachable block (ram,0xf00c4104) */
/* WARNING: Removing unreachable block (ram,0xf00c40c8) */
/* WARNING: Removing unreachable block (ram,0xf00c40ec) */
/* WARNING: Removing unreachable block (ram,0xf00c411c) */
/* WARNING: Removing unreachable block (ram,0xf00c4154) */
/* WARNING: Removing unreachable block (ram,0xf00c4184) */
/* WARNING: Removing unreachable block (ram,0xf00c41b4) */
/* WARNING: Removing unreachable block (ram,0xf00c41d8) */
/* WARNING: Removing unreachable block (ram,0xf00c4208) */
/* WARNING: Removing unreachable block (ram,0xf00c408c) */

undefined8 -[SPARCKernBus init](int param_1,undefined4 param_2)

{
  undefined6 *puVar1;
  undefined6 *puVar2;
  undefined (*pauVar3) [34];
  undefined (*pauVar4) [25];
  undefined (*pauVar5) [27];
  undefined (*pauVar6) [32];
  undefined (*pauVar7) [20];
  undefined (*pauVar8) [22];
  undefined (*pauVar9) [21];
  undefined (*pauVar10) [19];
  int iVar11;
  int iVar12;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141e20;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  *(undefined *)(param_1 + 0x8f) = 0;
  iVar11 = param_1 + 0x7f;
  while (pauVar4 = paInsertresource, puVar1 = paAlloc, param_1 <= iVar11 + -1) {
    *(undefined *)(iVar11 + 0xf) = 0;
    iVar11 = iVar11 + -1;
  }
  pauVar7 = paKernbusitemres;
  _objc_msgSend(paKernbusitemres,paAlloc);
  pauVar3 = paInitwithitemco;
  puVar2 = paClass;
  pauVar8 = paSparckernbusin;
  _objc_msgSend(paSparckernbusin,paClass);
  _objc_msgSend(pauVar7,pauVar3,0x80,pauVar8,param_1);
  _objc_msgSend(param_1,pauVar4,pauVar7,aIrqLevels_3);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  pauVar9 = paKernbusrangere;
  _objc_msgSend(paKernbusrangere,puVar1);
  pauVar5 = paInitwithextent;
  pauVar10 = paKernbusmemoryr_0;
  _objc_msgSend(paKernbusmemoryr_0,puVar2);
  _objc_msgSend(pauVar9,pauVar5,(undefined *)((int)register0x00000038 + -0x18),pauVar10,param_1);
  _objc_msgSend(param_1,pauVar4,pauVar9,aMemoryMaps_3);
  iVar11 = param_1;
  _objc_msgSend(param_1,puVar2);
  pauVar6 = paRegisterbusins;
  iVar12 = param_1;
  _objc_msgSend(param_1,paBusid_0);
  _objc_msgSend(iVar11,pauVar6,param_1,&aSparc_3,iVar12);
  _printf(aSparcBusSuppor);
  _objc_msgSend(dword_F013302C,paAddobject,param_1);
  _walk_devs(_top_devinfo,_checkSharedIrqLevels,param_1 + 0x10);
  return CONCAT44(param_2,param_1);
}

