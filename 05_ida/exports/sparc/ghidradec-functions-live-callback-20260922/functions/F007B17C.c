
/* WARNING: Removing unreachable block (ram,0xf007b27c) */
/* WARNING: Removing unreachable block (ram,0xf007b244) */
/* WARNING: Removing unreachable block (ram,0xf007b2a4) */
/* WARNING: Removing unreachable block (ram,0xf007b22c) */
/* WARNING: Removing unreachable block (ram,0xf007b194) */

undefined8 sub_F007B17C(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  undefined4 unaff_l3;
  int iVar7;
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
  if (*(int *)(param_1 + 0x14) == 0x41) {
    iVar3 = 0;
    if ((undefined4 **)dword_F0130F54 != &dword_F0130F54) {
      iVar3 = *(int *)(param_1 + 0x1c);
      puVar5 = dword_F0130F54;
      do {
        puVar6 = (undefined4 *)*puVar5;
        if (iVar3 == puVar5[3]) {
          puVar2 = (undefined4 *)puVar5[1];
          puVar4 = puVar6;
          puVar1 = puVar2;
          if ((undefined4 **)puVar6 != &dword_F0130F54) {
            puVar6[1] = puVar2;
            puVar1 = dword_F0130F58;
          }
loc_F007B268:
          dword_F0130F58 = puVar1;
          if ((undefined4 **)puVar2 != &dword_F0130F54) {
            *puVar2 = puVar4;
            puVar4 = dword_F0130F54;
          }
          dword_F0130F54 = puVar4;
          _kfree(puVar5,0x14);
          iVar7 = iVar7 + 1;
        }
        else if (iVar3 == puVar5[2]) {
          *(undefined4 *)(param_1 + 0x10) = puVar5[3];
          *(undefined4 *)(param_1 + 0xc) = 0;
          *(undefined *)(param_1 + 3) = 1;
          *(undefined *)(param_1 + 0x18) = 2;
          *(undefined *)(param_1 + 0x19) = 0x20;
          *(undefined4 *)(param_1 + 0x1c) = puVar5[4];
          iVar3 = param_1;
          _msg_send(param_1,1,0);
          if (iVar3 == 0) {
            puVar4 = (undefined4 *)*puVar5;
          }
          else {
            _printf(aPnNotifyMsgSen,iVar3);
            puVar4 = (undefined4 *)*puVar5;
          }
          puVar2 = (undefined4 *)puVar5[1];
          puVar1 = puVar2;
          if ((undefined4 **)puVar4 != &dword_F0130F54) {
            puVar4[1] = puVar2;
            puVar1 = dword_F0130F58;
          }
          goto loc_F007B268;
        }
        iVar3 = iVar7;
        if ((undefined4 **)puVar6 == &dword_F0130F54) break;
        iVar3 = *(int *)(param_1 + 0x1c);
        puVar5 = puVar6;
      } while( true );
    }
    if (iVar3 == 0) {
      _printf(aPnNotifyPortNo);
    }
  }
  else {
    _printf(aPnNotifyMsgIdD);
  }
  return CONCAT44(param_2,param_1);
}

