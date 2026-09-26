
/* WARNING: Removing unreachable block (ram,0xf0037258) */

undefined8 _tcp_template(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  iVar3 = *(int *)(param_1 + 0x20);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = 0;
    _m_get(0,2);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto locret_F0037300;
    }
    *(undefined4 *)(iVar1 + 4) = 0x54;
    *(undefined2 *)(iVar1 + 8) = 0x28;
    puVar2 = (undefined4 *)(iVar1 + *(int *)(iVar1 + 4));
  }
  puVar2[1] = 0;
  *puVar2 = 0;
  *(undefined *)(puVar2 + 2) = 0;
  *(undefined *)((int)puVar2 + 9) = 6;
  *(undefined2 *)((int)puVar2 + 10) = 0x14;
  puVar2[3] = *(undefined4 *)(iVar3 + 0x14);
  puVar2[4] = *(undefined4 *)(iVar3 + 0xc);
  *(undefined2 *)(puVar2 + 5) = *(undefined2 *)(iVar3 + 0x18);
  *(undefined2 *)((int)puVar2 + 0x16) = *(undefined2 *)(iVar3 + 0x10);
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = puVar2[8] & 0xffffff | 0x50000000;
  *(undefined *)((int)puVar2 + 0x21) = 0;
  *(undefined2 *)((int)puVar2 + 0x22) = 0;
  *(undefined2 *)(puVar2 + 9) = 0;
  *(undefined2 *)((int)puVar2 + 0x26) = 0;
locret_F0037300:
  return CONCAT44(param_2,puVar2);
}

