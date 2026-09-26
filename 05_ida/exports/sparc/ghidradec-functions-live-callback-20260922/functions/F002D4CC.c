
/* WARNING: Removing unreachable block (ram,0xf002d550) */
/* WARNING: Removing unreachable block (ram,0xf002d4f0) */

undefined8 _arptimer(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  byte *pbVar5;
  undefined4 unaff_l1;
  undefined *puVar6;
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
  _timeout(_arptimer,0,_hz * 0x3c);
  puVar6 = _arptab;
  pbVar5 = _arptab + 0xb;
  do {
    if ((*pbVar5 != 0) && ((*pbVar5 & 4) == 0)) {
      bVar2 = pbVar5[-1];
      pbVar5[-1] = bVar2 + 1;
      uVar4 = (uint)(byte)(bVar2 + 1);
      if ((*pbVar5 & 2) == 0) {
        iVar1 = 2;
        iVar3 = uVar4 - 2;
      }
      else {
        iVar1 = 0x13;
        iVar3 = uVar4 - 0x13;
      }
      if (iVar3 != 0 && iVar3 < 0 == SBORROW4(uVar4,iVar1)) {
        _arptfree(puVar6);
      }
    }
    iVar7 = iVar7 + 1;
    pbVar5 = pbVar5 + 0x14;
    puVar6 = puVar6 + 0x14;
  } while (iVar7 < 0xab);
  return CONCAT44(param_2,param_1);
}

