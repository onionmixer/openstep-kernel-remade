
/* WARNING: Removing unreachable block (ram,0xf0031a64) */
/* WARNING: Removing unreachable block (ram,0xf0031a30) */

undefined8 _icmp_send(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
  int iVar4;
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
  uVar2 = (uint)param_1 & 0xffffff80;
  uVar3 = *param_1 & 0xf;
  *(uint *)(uVar2 + 4) = *(int *)(uVar2 + 4) + uVar3 * 4;
  *(sword *)(uVar2 + 8) = *(sword *)(uVar2 + 8) + (sword)uVar3 * -4;
  iVar4 = uVar2 + *(int *)(uVar2 + 4);
  *(undefined2 *)(iVar4 + 2) = 0;
  uVar1 = uVar2;
  _in_cksum(uVar2,(int)*(sword *)(param_1 + 2) + uVar3 * -4);
  *(sword *)(iVar4 + 2) = (sword)uVar1;
  *(uint *)(uVar2 + 4) = *(int *)(uVar2 + 4) + uVar3 * -4;
  *(sword *)(uVar2 + 8) = *(sword *)(uVar2 + 8) + (sword)(uVar3 * 4);
  _ip_output(uVar2,param_2,0,0,0);
  return CONCAT44(param_2,param_1);
}

