/* GHIDRADEC_FUNCTION index=1975 start=0xf00921d0 */

/* WARNING: Removing unreachable block (ram,0xf00921fc) */
/* WARNING: Removing unreachable block (ram,0xf0092244) */
/* WARNING: Removing unreachable block (ram,0xf00921d8) */

undefined8 _sdclose(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined (*pauVar3) [20];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  uVar1 = (uint)(sword)param_1;
  sub_F0092E34();
  if (uVar1 == 0) {
loc_F0092214:
    uVar4 = 6;
  }
  else {
    if ((param_1 & 7) != 7) {
      uVar2 = uVar1;
      _objc_msgSend(uVar1,paIsinstanceopen);
      if ((uVar2 & 0xff) == 0) goto loc_F0092214;
      pauVar3 = (undefined (*) [20])paSetrawdeviceop;
      if ((param_1 & 0xffff) >> 8 == dword_F0131240) {
        pauVar3 = paSetblockdevice;
      }
      _objc_msgSend(uVar1,pauVar3,0);
    }
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1976 start=0xf0092258 */

/* WARNING: Removing unreachable block (ram,0xf009239c) */
/* WARNING: Removing unreachable block (ram,0xf0092380) */
/* WARNING: Removing unreachable block (ram,0xf0092320) */
/* WARNING: Removing unreachable block (ram,0xf00922e0) */
/* WARNING: Removing unreachable block (ram,0xf00922a4) */
/* WARNING: Removing unreachable block (ram,0xf0092280) */
/* WARNING: Removing unreachable block (ram,0xf00922d0) */
/* WARNING: Removing unreachable block (ram,0xf0092308) */
/* WARNING: Removing unreachable block (ram,0xf009234c) */
/* WARNING: Removing unreachable block (ram,0xf00923b4) */
/* WARNING: Removing unreachable block (ram,0xf00923c0) */
/* WARNING: Removing unreachable block (ram,0xf0092264) */

undefined8 _sdread(uint param_1,undefined4 *param_2)

{
  undefined (*pauVar1) [11];
  undefined (*pauVar2) [10];
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  uint *puVar6;
  int iVar7;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  uint uVar10;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  code *pcVar11;
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
  uVar9 = (uint)(sword)param_1;
  uVar3 = uVar9;
  sub_F0092E34();
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  uVar4 = uVar9;
  sub_F0092EB0();
  if (uVar3 == 0) {
    pcVar11 = (code *)0x6;
  }
  else {
    uVar8 = uVar3;
    _objc_msgSend(uVar3,paIsformatted);
    pauVar1 = paController;
    if ((uVar8 & 0xff) == 0) {
      pcVar11 = (code *)0x16;
    }
    else {
      puVar6 = (uint *)*param_2;
      _objc_msgSend(uVar4,paController);
      _objc_msgSend();
      if (_forceSdPageAlign != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x18) = _page_size;
      }
      _objc_msgSend(uVar4,pauVar1);
      _objc_msgSend();
      uVar10 = *puVar6;
      uVar8 = puVar6[1];
      *puVar6 = uVar4;
      pauVar2 = paBlocksize;
      iVar7 = param_2[3];
      param_2[3] = 1;
      _objc_msgSend(uVar3,pauVar2);
      pcVar11 = _sdstrategy;
      _physio(_sdstrategy,*(undefined4 *)(unk_F01123A8 + ((param_1 & 0xff) >> 3) * 4),uVar9,1,
              sub_F0092E0C,param_2,uVar3);
      if (iVar7 == 1) {
        _bcopy(uVar4,uVar10,uVar8);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x1c);
      }
      else {
        _copyout(uVar4,uVar10,uVar8);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x1c);
      }
      _IOFree(uVar5,*(undefined4 *)((int)register0x00000038 + -0x20));
    }
  }
  return CONCAT44(param_2,pcVar11);
}
/* GHIDRADEC_FUNCTION index=1977 start=0xf00923d0 */

/* WARNING: Removing unreachable block (ram,0xf00924ec) */
/* WARNING: Removing unreachable block (ram,0xf00924d4) */
/* WARNING: Removing unreachable block (ram,0xf0092480) */
/* WARNING: Removing unreachable block (ram,0xf0092448) */
/* WARNING: Removing unreachable block (ram,0xf00923f8) */
/* WARNING: Removing unreachable block (ram,0xf009241c) */
/* WARNING: Removing unreachable block (ram,0xf0092458) */
/* WARNING: Removing unreachable block (ram,0xf0092498) */
/* WARNING: Removing unreachable block (ram,0xf00924c0) */
/* WARNING: Removing unreachable block (ram,0xf0092524) */
/* WARNING: Removing unreachable block (ram,0xf009253c) */
/* WARNING: Removing unreachable block (ram,0xf00923dc) */

undefined8 _sdwrite(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  uint *puVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  code *pcVar6;
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
  uVar4 = (uint)(sword)param_1;
  uVar2 = uVar4;
  sub_F0092E34();
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  sub_F0092EB0();
  if (uVar2 == 0) {
    pcVar6 = (code *)0x6;
  }
  else {
    uVar3 = uVar2;
    _objc_msgSend(uVar2,paIsformatted);
    uVar1 = paController;
    if ((uVar3 & 0xff) == 0) {
      pcVar6 = (code *)0x16;
    }
    else {
      puVar5 = (uint *)*param_2;
      _objc_msgSend(uVar4,paController);
      _objc_msgSend();
      if (_forceSdPageAlign != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x14) = _page_size;
      }
      _objc_msgSend(uVar4,uVar1);
      _objc_msgSend();
      uVar3 = *puVar5;
      *puVar5 = uVar4;
      if (param_2[3] == 1) {
        _bcopy(uVar3,uVar4,puVar5[1]);
      }
      else {
        _copyin(uVar3,uVar4,puVar5[1]);
        param_2[3] = 1;
      }
      _objc_msgSend(uVar2,paBlocksize);
      pcVar6 = _sdstrategy;
      _physio(_sdstrategy,*(undefined4 *)(unk_F01123A8 + ((param_1 & 0xff) >> 3) * 4),
              (int)(sword)param_1,0,sub_F0092E0C,param_2,uVar2);
      _IOFree(*(undefined4 *)((int)register0x00000038 + -0x1c),
              *(undefined4 *)((int)register0x00000038 + -0x20));
    }
  }
  return CONCAT44(param_2,pcVar6);
}
/* GHIDRADEC_FUNCTION index=1978 start=0xf009254c */

/* WARNING: Removing unreachable block (ram,0xf0092614) */
/* WARNING: Removing unreachable block (ram,0xf00925a0) */
/* WARNING: Removing unreachable block (ram,0xf00925f4) */
/* WARNING: Removing unreachable block (ram,0xf009262c) */
/* WARNING: Removing unreachable block (ram,0xf0092550) */

undefined8 _sdstrategy(uint *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined (*pauVar4) [43];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar1 = (int)*(sword *)((int)param_1 + 0x1e);
  sub_F0092E34();
  if (iVar1 == 0) {
    uVar3 = 6;
  }
  else {
    uVar5 = _kernel_map;
    if ((*param_1 & 0x4000010) == 0x10) {
      uVar5 = *(undefined4 *)(*(int *)(param_1[0xb] + 0x68) + 0xc);
    }
    iVar2 = iVar1;
    _objc_msgSend(iVar1,paBlocksize);
    if (iVar2 == 0) {
      uVar3 = 6;
    }
    else {
      pauVar4 = paWriteasyncatLe;
      if ((*param_1 & 1) != 0) {
        pauVar4 = (undefined (*) [43])paReadasyncatLen;
      }
      iVar2 = iVar1;
      _objc_msgSend(iVar1,pauVar4,param_1[9],param_1[5],param_1[8],param_1,uVar5);
      if (iVar2 == 0) {
        uVar5 = 0;
        goto locret_F0092638;
      }
      _objc_msgSend(iVar1,paErrnofromretur,iVar2);
      uVar3 = (undefined2)iVar1;
    }
  }
  *(undefined2 *)(param_1 + 7) = uVar3;
  *param_1 = *param_1 | 4;
  _biodone();
  uVar5 = 0xffffffff;
locret_F0092638:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1979 start=0xf0092640 */

/* WARNING: Removing unreachable block (ram,0xf0092d48) */
/* WARNING: Removing unreachable block (ram,0xf0092c64) */
/* WARNING: Removing unreachable block (ram,0xf0092b5c) */
/* WARNING: Removing unreachable block (ram,0xf0092b1c) */
/* WARNING: Removing unreachable block (ram,0xf0092aac) */
/* WARNING: Removing unreachable block (ram,0xf009293c) */
/* WARNING: Removing unreachable block (ram,0xf009290c) */
/* WARNING: Removing unreachable block (ram,0xf00928e8) */
/* WARNING: Removing unreachable block (ram,0xf00928b8) */
/* WARNING: Removing unreachable block (ram,0xf0092a74) */
/* WARNING: Removing unreachable block (ram,0xf00929a8) */
/* WARNING: Removing unreachable block (ram,0xf009296c) */
/* WARNING: Removing unreachable block (ram,0xf0092950) */
/* WARNING: Removing unreachable block (ram,0xf0092d74) */
/* WARNING: Removing unreachable block (ram,0xf0092d88) */
/* WARNING: Removing unreachable block (ram,0xf0092960) */
/* WARNING: Removing unreachable block (ram,0xf009297c) */
/* WARNING: Removing unreachable block (ram,0xf009289c) */
/* WARNING: Removing unreachable block (ram,0xf0092884) */
/* WARNING: Removing unreachable block (ram,0xf00928d0) */
/* WARNING: Removing unreachable block (ram,0xf00928f8) */
/* WARNING: Removing unreachable block (ram,0xf009292c) */
/* WARNING: Removing unreachable block (ram,0xf0092a98) */
/* WARNING: Removing unreachable block (ram,0xf0092afc) */
/* WARNING: Removing unreachable block (ram,0xf0092b4c) */
/* WARNING: Removing unreachable block (ram,0xf0092b70) */
/* WARNING: Removing unreachable block (ram,0xf0092ce4) */
/* WARNING: Removing unreachable block (ram,0xf0092db0) */
/* WARNING: Removing unreachable block (ram,0xf0092d5c) */
/* WARNING: Removing unreachable block (ram,0xf0092a58) */
/* WARNING: Removing unreachable block (ram,0xf0092a3c) */

undefined8 _sdioctl(uint param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  undefined uVar3;
  uint *puVar4;
  undefined *puVar5;
  undefined (*pauVar6) [9];
  undefined (*pauVar7) [26];
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar12;
  uint uVar13;
  undefined4 unaff_l3;
  uint uVar14;
  undefined4 unaff_l4;
  uint uVar15;
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
  bool bVar16;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  int aiStack_80 [32];
  
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
  uVar15 = 0;
  uVar14 = 0;
  uVar8 = (param_1 & 0xff) >> 3;
  uVar13 = *param_3;
  if (uVar8 < 0x11) {
    if ((param_1 & 0xffff) >> 8 != dword_F0131244) {
      uVar8 = 6;
      goto locret_F0092DC8;
    }
    puVar4 = (uint *)(unk_F0131000 + uVar8 * 0x24);
    if (param_2 == 0x20006415) {
loc_F009276C:
      param_1 = param_1 & 7;
      if (param_1 == 7) {
        param_1 = 0;
      }
      uVar12 = puVar4[param_1 + 1];
    }
    else if ((int)param_2 < 0x20006416) {
      if (param_2 != 0xc0587301) {
        if ((int)param_2 < -0x3fa78cfe) {
          uVar8 = 0x80046417;
loc_F009272C:
          if (param_2 != uVar8) {
            uVar8 = 0x16;
            goto locret_F0092DC8;
          }
        }
        else {
          uVar8 = 0x16;
          if ((0x20006401 < (int)param_2) || ((int)param_2 < 0x20006400)) goto locret_F0092DC8;
        }
        goto loc_F009276C;
      }
      uVar12 = *puVar4;
    }
    else if ((int)param_2 < 0x4004641a) {
      if ((int)param_2 < 0x40046418) {
        uVar8 = 0x40046417;
        goto loc_F009272C;
      }
      uVar12 = *puVar4;
    }
    else if (param_2 == 0x40087305) {
      uVar12 = *puVar4;
    }
    else {
      if (param_2 != 0x40306405) {
        uVar8 = 0x16;
        goto locret_F0092DC8;
      }
      uVar12 = *puVar4;
    }
    if (uVar12 != 0) {
      if (param_2 == 0x20006415) {
        uVar13 = uVar12;
        _objc_msgSend(uVar12,paIsremovable);
        if ((uVar13 & 0xff) != 0) {
          uVar14 = uVar12;
          _objc_msgSend(uVar12,paEject_1);
        }
        goto loc_F0092D9C;
      }
      if ((int)param_2 < 0x20006416) {
        if (param_2 == 0xc0587301) {
          if (param_3[5] == 0) {
            param_2 = 0;
            uVar13 = 0;
loc_F0092B48:
            _bzero((undefined *)((int)register0x00000038 + -0x68),0x60);
            uVar14 = uVar12;
            _objc_msgSend(uVar12,paTarget);
            *(char *)((int)register0x00000038 + -0x68) = (char)uVar14;
            uVar14 = uVar12;
            _objc_msgSend(uVar12,paLun);
            *(char *)((int)register0x00000038 + -0x67) = (char)uVar14;
            *(uint *)((int)register0x00000038 + -100) = *param_3;
            *(uint *)((int)register0x00000038 + -0x60) = param_3[1];
            *(uint *)((int)register0x00000038 + -0x5c) = param_3[2];
            uVar10 = *(uint *)((int)register0x00000038 + -0x4c);
            *(char *)((int)register0x00000038 + -0x58) = '\x01' - (param_3[3] != 0);
            *(uint *)((int)register0x00000038 + -0x54) = param_2;
            *(uint *)((int)register0x00000038 + -0x50) = param_3[6];
            uVar14 = (param_3[0x13] >> 0x17 ^ 1) << 0x1f;
            *(uint *)((int)register0x00000038 + -0x4c) = uVar10 & 0x7fffffff | uVar14;
            uVar8 = (param_3[0x13] >> 0x16 & 1) << 0x1e;
            *(uint *)((int)register0x00000038 + -0x4c) = uVar10 & 0x3fffffff | uVar14 | uVar8;
            uVar2 = (param_3[0x13] >> 0x15 & 1) << 0x1d;
            *(uint *)((int)register0x00000038 + -0x4c) =
                 uVar10 & 0x1fffffff | uVar14 | uVar8 | uVar2;
            *(uint *)((int)register0x00000038 + -0x4c) =
                 uVar10 & 0x1ffffff0 | uVar14 | uVar8 | uVar2 | *(byte *)(param_3 + 0x13) & 0xf;
            pauVar7 = (undefined (*) [26])paSdcdbreadBuffe;
            if (param_3[3] == 1) {
              pauVar7 = paSdcdbwriteBuff;
            }
            uVar14 = uVar12;
            _objc_msgSend(uVar12,pauVar7,(undefined *)((int)register0x00000038 + -0x68),uVar13,
                          _kernel_map);
            uVar8 = *(uint *)((int)register0x00000038 + -0x48);
            param_3[7] = uVar8;
            if (uVar8 == 0xd) {
              uVar3 = *(undefined *)((int)register0x00000038 + -0x44);
              if (*(char *)((int)register0x00000038 + -0x44) == '\x02') {
                param_3[7] = 3;
                goto loc_F0092C98;
              }
            }
            else {
loc_F0092C98:
              uVar3 = *(undefined *)((int)register0x00000038 + -0x44);
            }
            *(undefined *)(param_3 + 8) = uVar3;
            uVar8 = *(uint *)((int)register0x00000038 + -0x40);
            param_3[0x10] = uVar8;
            if ((int)param_3[5] < (int)uVar8) {
              param_3[0x10] = param_3[5];
            }
            param_3[0x12] = 0;
            param_3[0x11] = 0;
            if (param_3[3] == 0) {
              if (*(int *)((int)register0x00000038 + -0x40) != 0) {
                _copyout(uVar13,param_3[4],param_3[0x10]);
                uVar15 = uVar13;
                goto loc_F0092CF0;
              }
              uVar13 = param_3[7];
            }
            else {
loc_F0092CF0:
              uVar13 = param_3[7];
            }
            if (uVar13 == 2) {
              param_3[9] = *(uint *)((int)register0x00000038 + -0x28);
              param_3[10] = *(uint *)((int)register0x00000038 + -0x24);
              param_3[0xb] = *(uint *)((int)register0x00000038 + -0x20);
              param_3[0xc] = *(uint *)((int)register0x00000038 + -0x1c);
              param_3[0xd] = *(uint *)((int)register0x00000038 + -0x18);
              param_3[0xe] = *(uint *)((int)register0x00000038 + -0x14);
              param_3[0xf] = *(uint *)((int)register0x00000038 + -0x10);
              goto loc_F0092D38;
            }
            uVar13 = param_3[5];
          }
          else {
            uVar13 = *puVar4;
            _objc_msgSend(uVar13,paController);
            _objc_msgSend();
            uVar8 = *(uint *)((int)register0x00000038 + -0xa0);
            if (param_3[3] == 1) {
              uVar8 = *(uint *)((int)register0x00000038 + -0x9c);
            }
            if (uVar8 < 2) {
              param_2 = param_3[5];
            }
            else {
              param_2 = (param_3[5] + uVar8) - 1 & -uVar8;
            }
            _objc_msgSend(uVar13,paAllocatebuffer,param_2,
                          (undefined *)((int)register0x00000038 + -0xac),
                          (undefined *)((int)register0x00000038 + -0xb0));
            if (param_3[3] != 1) goto loc_F0092B48;
            uVar15 = param_3[4];
            _copyin(uVar15,uVar13,param_3[5]);
            if (uVar15 == 0) goto loc_F0092B48;
            param_3[7] = 9;
loc_F0092D38:
            uVar13 = param_3[5];
          }
          if (uVar13 == 0) goto loc_F0092D9C;
          _IOFree(*(undefined4 *)((int)register0x00000038 + -0xac),
                  *(undefined4 *)((int)register0x00000038 + -0xb0));
          bVar16 = uVar14 == 0;
        }
        else {
          if ((int)param_2 < -0x3fa78cfe) {
            if (param_2 != 0x80046417) {
              uVar8 = 0x16;
              goto locret_F0092DC8;
            }
            uVar14 = uVar12;
            _objc_msgSend(uVar12,paSetformatted_0,(int)(char)*param_3);
            goto loc_F0092D9C;
          }
          if (param_2 == 0x20006400) {
            uVar8 = 0x1c5c;
            _IOMalloc(0x1c5c);
            uVar14 = uVar12;
            _objc_msgSend(uVar12,paReadlabel,uVar8);
            if (uVar14 == 0) {
              uVar15 = uVar8;
              _copyout(uVar8,uVar13,0x1c5c);
            }
          }
          else {
            bVar16 = param_2 != 0x20006401;
            param_2 = 0x1c00;
            if (bVar16) {
              uVar8 = 0x16;
              goto locret_F0092DC8;
            }
            uVar8 = 0x1c5c;
            _IOMalloc(0x1c5c);
            _copyin(uVar13,uVar8,0x1c5c);
            uVar15 = uVar13;
            if (uVar13 == 0) {
              uVar14 = uVar12;
              _objc_msgSend(uVar12,paWritelabel_0,uVar8);
            }
          }
          param_2 = 0x1c00;
          _IOFree(uVar8,0x1c5c);
          bVar16 = uVar14 == 0;
        }
      }
      else {
        pauVar6 = paDisksize;
        if (param_2 == 0x40046419) {
loc_F0092A74:
          uVar13 = uVar12;
          _objc_msgSend(uVar12,pauVar6);
          *param_3 = uVar13;
        }
        else if ((int)param_2 < 0x4004641a) {
          if (param_2 != 0x40046417) {
            pauVar6 = paBlocksize;
            if (param_2 != 0x40046418) {
              uVar8 = 0x16;
              goto locret_F0092DC8;
            }
            goto loc_F0092A74;
          }
          uVar13 = uVar12;
          _objc_msgSend(uVar12,paIsformatted);
          *param_3 = (int)(char)uVar13;
        }
        else if (param_2 == 0x40087305) {
          uVar14 = uVar12;
          _objc_msgSend(uVar12,paUpdatephysical);
          bVar16 = uVar14 == 0;
          if (!bVar16) goto loc_F0092DA0;
          uVar13 = uVar12;
          _objc_msgSend(uVar12,paBlocksize);
          uVar8 = uVar12;
          _objc_msgSend(uVar12,paDisksize);
          param_3[1] = uVar13;
          *param_3 = uVar8 - 1;
        }
        else {
          if (param_2 != 0x40306405) {
            uVar8 = 0x16;
            goto locret_F0092DC8;
          }
          _bzero((undefined *)((int)register0x00000038 + -0x98),0x30);
          uVar13 = uVar12;
          _objc_msgSend(uVar12,paDrivename);
          _strcpy((undefined *)((int)register0x00000038 + -0x98),uVar13);
          uVar13 = uVar12;
          _objc_msgSend(uVar12,paBlocksize);
          *(uint *)((int)register0x00000038 + -0x70) = uVar13;
          *(undefined4 *)((int)register0x00000038 + -0x6c) = dword_F0131248;
          if (uVar13 != 0) {
            iVar1 = uVar13 + 0x1c5b;
            .udiv();
            iVar11 = 0;
            iVar9 = 0;
            puVar5 = (undefined *)((int)register0x00000038 + -8);
            do {
              *(int *)(puVar5 + -0x78) = iVar9;
              iVar9 = iVar9 + iVar1;
              iVar11 = iVar11 + 1;
              puVar5 = puVar5 + 4;
            } while (iVar11 < 4);
          }
          *param_3 = *(uint *)((int)register0x00000038 + -0x98);
          param_3[1] = *(uint *)((int)register0x00000038 + -0x94);
          param_3[2] = *(uint *)((int)register0x00000038 + -0x90);
          param_3[3] = *(uint *)((int)register0x00000038 + -0x8c);
          param_3[4] = *(uint *)((int)register0x00000038 + -0x88);
          param_3[5] = *(uint *)((int)register0x00000038 + -0x84);
          param_3[6] = *(uint *)((int)register0x00000038 + -0x80);
          param_3[7] = *(uint *)((int)register0x00000038 + -0x7c);
          param_3[8] = *(uint *)((int)register0x00000038 + -0x78);
          param_3[9] = *(uint *)((int)register0x00000038 + -0x74);
          param_3[10] = *(uint *)((int)register0x00000038 + -0x70);
          param_3[0xb] = *(uint *)((int)register0x00000038 + -0x6c);
        }
loc_F0092D9C:
        bVar16 = uVar14 == 0;
      }
loc_F0092DA0:
      uVar8 = uVar15;
      if (!bVar16) {
        _objc_msgSend(uVar12,paErrnofromretur,uVar14);
        uVar8 = uVar12;
      }
      goto locret_F0092DC8;
    }
  }
  uVar8 = 6;
locret_F0092DC8:
  return CONCAT44(param_2,uVar8);
}

