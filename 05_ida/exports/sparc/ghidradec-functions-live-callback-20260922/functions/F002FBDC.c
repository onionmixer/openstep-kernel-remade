
/* WARNING: Removing unreachable block (ram,0xf002fc84) */
/* WARNING: Removing unreachable block (ram,0xf002fbec) */
/* WARNING: Removing unreachable block (ram,0xf002fc98) */
/* WARNING: Removing unreachable block (ram,0xf002fbe0) */

undefined8 sub_F002FBDC(undefined4 param_1,int param_2,undefined4 param_3)

{
  sword sVar1;
  uint *puVar2;
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
  puVar2 = (uint *)0x148;
  _kalloc();
  _bzero();
  *puVar2 = *puVar2 & 0xffffff | 0x45000000;
  sVar1 = _ip_id + 1;
  *(sword *)(puVar2 + 1) = _ip_id;
  _ip_id = sVar1;
  *(undefined *)(puVar2 + 2) = 0xff;
  *(undefined *)((int)puVar2 + 9) = 0x11;
  puVar2[3] = *(uint *)(param_2 + 4);
  puVar2[4] = 0xffffffff;
  *(undefined2 *)(puVar2 + 5) = 0x44;
  *(undefined2 *)((int)puVar2 + 0x16) = 0x43;
  *(undefined2 *)((int)puVar2 + 0x1a) = 0;
  *(undefined *)(puVar2 + 7) = 1;
  *(undefined *)((int)puVar2 + 0x1d) = 1;
  *(undefined *)((int)puVar2 + 0x1e) = 6;
  puVar2[10] = 0;
  _bcopy(param_3,puVar2 + 0xe,6);
  _bcopy(&aNext_0,puVar2 + 0x42,4);
  *(undefined *)(puVar2 + 0x43) = 1;
  *(undefined *)((int)puVar2 + 0x10e) = 0;
  *(undefined2 *)(puVar2 + 6) = 0x134;
  *(undefined2 *)((int)puVar2 + 2) = 0x148;
  *(undefined2 *)((int)puVar2 + 10) = 0;
  return CONCAT44(param_2,puVar2);
}

