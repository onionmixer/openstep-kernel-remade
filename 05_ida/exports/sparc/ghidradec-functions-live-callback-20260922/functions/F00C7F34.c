
/* WARNING: Removing unreachable block (ram,0xf00c80b4) */
/* WARNING: Removing unreachable block (ram,0xf00c8088) */
/* WARNING: Removing unreachable block (ram,0xf00c8068) */
/* WARNING: Removing unreachable block (ram,0xf00c8040) */
/* WARNING: Removing unreachable block (ram,0xf00c8014) */
/* WARNING: Removing unreachable block (ram,0xf00c7fec) */
/* WARNING: Removing unreachable block (ram,0xf00c7fc0) */
/* WARNING: Removing unreachable block (ram,0xf00c7f94) */
/* WARNING: Removing unreachable block (ram,0xf00c7f6c) */
/* WARNING: Removing unreachable block (ram,0xf00c7f80) */
/* WARNING: Removing unreachable block (ram,0xf00c7fac) */
/* WARNING: Removing unreachable block (ram,0xf00c7fd8) */
/* WARNING: Removing unreachable block (ram,0xf00c8004) */
/* WARNING: Removing unreachable block (ram,0xf00c802c) */
/* WARNING: Removing unreachable block (ram,0xf00c805c) */
/* WARNING: Removing unreachable block (ram,0xf00c8074) */
/* WARNING: Removing unreachable block (ram,0xf00c809c) */
/* WARNING: Removing unreachable block (ram,0xf00c80d0) */
/* WARNING: Removing unreachable block (ram,0xf00c7f50) */

undefined8
-[IODiskPartition _initPartition:disktab:](int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined (*pauVar1) [9];
  undefined (*pauVar2) [19];
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  iVar7 = param_3 * 0x30 + 0x94;
  iVar3 = param_1;
  _objc_msgSend(param_1,paPhysicaldisk_0);
  iVar6 = iVar3;
  _objc_msgSend();
  _sprintf((undefined *)((int)register0x00000038 + -0x30),&aSC,iVar6,param_3 + 0x61);
  _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x30));
  _objc_msgSend(param_1,paSetdrivename,aIodiskpartitio_0);
  _objc_msgSend(param_1,paSetlocation,0);
  _objc_msgSend(param_1,paSetdisksize,*(undefined4 *)(param_4 + iVar7 + 4));
  _objc_msgSend(param_1,paSetblocksize,*(undefined4 *)(param_4 + 0x30));
  pauVar1 = paSetunit;
  iVar6 = iVar3;
  _objc_msgSend(iVar3,paUnit_0);
  _objc_msgSend(param_1,pauVar1,iVar6);
  pauVar2 = paSetwriteprotec;
  _objc_msgSend(iVar3,paIswriteprotect);
  _objc_msgSend(param_1,pauVar2,(int)(char)iVar3);
  iVar6 = *(int *)(param_4 + iVar7) + (int)*(sword *)(param_4 + 0x44);
  iVar3 = param_1;
  _objc_msgSend(param_1,paPhysicalblocks_0);
  uVar4 = *(undefined4 *)(param_4 + 0x30);
  udiv(uVar4,iVar3);
  umul(iVar6,uVar4);
  _objc_msgSend(param_1,paSetpartitionba,iVar6);
  *(int *)(param_1 + 0x1a4) = param_3;
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar5 = aIologicaldisk;
  _objc_getOrigClass();
  *(undefined **)((int)register0x00000038 + -0xc) = puVar5;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paSetformattedin,1);
  *(undefined *)(param_1 + 0x1a8) = 1;
  _objc_msgSend(param_1,paRegisterunixdi,param_3);
  return CONCAT44(param_2,param_1);
}

