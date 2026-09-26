
/* WARNING: Removing unreachable block (ram,0xf00c6d00) */
/* WARNING: Removing unreachable block (ram,0xf00c6cd4) */
/* WARNING: Removing unreachable block (ram,0xf00c6ca8) */
/* WARNING: Removing unreachable block (ram,0xf00c6c7c) */
/* WARNING: Removing unreachable block (ram,0xf00c6c4c) */
/* WARNING: Removing unreachable block (ram,0xf00c6c68) */
/* WARNING: Removing unreachable block (ram,0xf00c6c94) */
/* WARNING: Removing unreachable block (ram,0xf00c6cc0) */
/* WARNING: Removing unreachable block (ram,0xf00c6ce8) */
/* WARNING: Removing unreachable block (ram,0xf00c6d10) */
/* WARNING: Removing unreachable block (ram,0xf00c6c3c) */

sqword -[IOLogicalDisk connectToPhysicalDisk:](int param_1,uint param_2,undefined4 param_3)

{
  undefined (*pauVar1) [17];
  undefined (*pauVar2) [19];
  undefined (*pauVar3) [22];
  undefined (*pauVar4) [14];
  undefined4 uVar5;
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
  *(undefined4 *)(param_1 + 0x184) = param_3;
  _objc_msgSend(param_1,paSetisphysical,0);
  uVar5 = param_3;
  _objc_msgSend(param_3,paBlocksize);
  *(undefined4 *)(param_1 + 0x18c) = uVar5;
  pauVar4 = paSetremovable;
  uVar5 = param_3;
  _objc_msgSend(param_3,paIsremovable);
  _objc_msgSend(param_1,pauVar4,(int)(char)uVar5);
  pauVar3 = paSetformattedin;
  uVar5 = param_3;
  _objc_msgSend(param_3,paIsformatted);
  _objc_msgSend(param_1,pauVar3,(int)(char)uVar5);
  pauVar2 = paSetwriteprotec;
  uVar5 = param_3;
  _objc_msgSend(param_3,paIswriteprotect);
  _objc_msgSend(param_1,pauVar2,(int)(char)uVar5);
  _objc_msgSend(param_1,paSetlogicaldisk,0);
  pauVar1 = paSetdevandidinf;
  _objc_msgSend(param_3,paDevandidinfo_0);
  _objc_msgSend(param_1,pauVar1,param_3);
  return (qword)param_2 << 0x20;
}

