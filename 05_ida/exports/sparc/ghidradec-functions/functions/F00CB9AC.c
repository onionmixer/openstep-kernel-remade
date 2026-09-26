
/* WARNING: Removing unreachable block (ram,0xf00cba6c) */
/* WARNING: Removing unreachable block (ram,0xf00cba38) */
/* WARNING: Removing unreachable block (ram,0xf00cba58) */
/* WARNING: Removing unreachable block (ram,0xf00cb9c0) */
/* WARNING: Removing unreachable block (ram,0xf00cb9cc) */

sqword -[IOEthernet outputPacket:address:]
                 (int param_1,uint param_2,undefined *param_3,undefined *param_4)

{
  undefined *puVar1;
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
  if (*(char *)(param_1 + 0x128) == '\0') {
    _nb_free(param_3);
  }
  else {
    puVar1 = param_3;
    _nb_map();
    *puVar1 = *param_4;
    puVar1[1] = param_4[1];
    puVar1[2] = param_4[2];
    puVar1[3] = param_4[3];
    puVar1[4] = param_4[4];
    puVar1[5] = param_4[5];
    puVar1[6] = *(undefined *)(param_1 + 0x150);
    puVar1[7] = *(undefined *)(param_1 + 0x151);
    puVar1[8] = *(undefined *)(param_1 + 0x152);
    puVar1[9] = *(undefined *)(param_1 + 0x153);
    puVar1[10] = *(undefined *)(param_1 + 0x154);
    puVar1[0xb] = *(undefined *)(param_1 + 0x155);
    puVar1 = param_3;
    _nb_size();
    if ((int)puVar1 < 0x3c) {
      _nb_grow_bot(param_3,0x3c - (int)puVar1);
    }
    _objc_msgSend(param_1,paTransmit,param_3);
  }
  return (qword)param_2 << 0x20;
}
