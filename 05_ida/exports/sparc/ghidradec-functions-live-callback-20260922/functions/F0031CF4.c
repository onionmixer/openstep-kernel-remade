
/* WARNING: Removing unreachable block (ram,0xf0031d18) */
/* WARNING: Removing unreachable block (ram,0xf0031e24) */
/* WARNING: Removing unreachable block (ram,0xf0031d00) */

undefined8 _ip_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined uVar3;
  sword *psVar4;
  undefined4 unaff_l0;
  undefined (*pauVar5) [336];
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
  iVar1 = 2;
  _pffindproto(2,0xff,3);
  if (iVar1 == 0) {
    _panic(&aIpInit);
  }
  puVar2 = &DAT_f013671f;
  uVar3 = (undefined)((iVar1 + 0xfef3a60) * -0x55555555 >> 4);
  DAT_f013671f = uVar3;
  while (puVar2 = puVar2 + -1, -0xfec99e1 < (int)puVar2) {
    *puVar2 = uVar3;
  }
  if (off_F010C704 < (uint)DAT_f010c708._0_4_) {
    psVar4 = (sword *)(*off_F010C704 + 8);
    pauVar5 = off_F010C704;
    do {
      if (((**(int **)(psVar4 + -2) == 2) && (iVar1 = (int)*psVar4, iVar1 != 0)) && (iVar1 != 0xff))
      {
        _ip_protox[iVar1] = (char)((int)(pauVar5[0xc23fb] + 0xf0) * -0x55555555 >> 4);
      }
      pauVar5 = (undefined (*) [336])(*pauVar5 + 0x30);
      psVar4 = psVar4 + 0x18;
    } while (pauVar5 < (uint)DAT_f010c708._0_4_);
  }
  DAT_f01364b4._0_4_ = &_ipq;
  _ipq = &_ipq;
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  _ip_id = (sword)*(undefined4 *)((int)register0x00000038 + -0x10);
  dword_F013648C = _ipqmaxlen;
  return CONCAT44(param_2,param_1);
}

