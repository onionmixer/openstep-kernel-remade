/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101630 */

void * _memset(void *param_1,int param_2,size_t param_3)

{
  undefined1 uVar1;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  uint *puVar6;
  int iVar7;
  undefined2 uVar2;
  
  uVar3 = param_2 << 8 | param_2;
  uVar4 = uVar3 | uVar3 << 0x10;
  uVar1 = (undefined1)param_2;
  uVar2 = (undefined2)uVar3;
  if (0x1f < (int)param_3) {
    uVar3 = (uint)param_1 & 7;
    pvVar5 = param_1;
    if (uVar3 == 0) goto LAB_001018e6;
    iVar7 = -uVar3 + 8;
    if (0x1e < -uVar3 + 7) goto LAB_001018e2;
    switch(uVar3) {
    case 1:
      *(undefined1 *)((int)param_1 + 6) = uVar1;
    case 2:
      *(undefined2 *)((int)param_1 + 4) = uVar2;
      break;
    case 3:
      *(undefined1 *)((int)param_1 + 4) = uVar1;
      break;
    case 5:
      *(undefined1 *)((int)param_1 + 2) = uVar1;
    case 6:
      *(undefined2 *)param_1 = uVar2;
      goto LAB_001018e2;
    case 7:
      *(undefined1 *)param_1 = uVar1;
      goto LAB_001018e2;
    }
    *(uint *)param_1 = uVar4;
LAB_001018e2:
    param_3 = param_3 - iVar7;
    pvVar5 = (void *)((int)param_1 + iVar7);
LAB_001018e6:
    puVar6 = (uint *)(((param_3 & 0x1c) - 0x20) + (int)pvVar5);
    switch(param_3 & 0x1c) {
    case 0:
      while( true ) {
        puVar6 = puVar6 + 8;
        param_3 = param_3 - 0x20;
        if ((int)param_3 < 0) break;
        *puVar6 = uVar4;
switchD_001018f8_caseD_1c:
        puVar6[1] = uVar4;
switchD_001018f8_caseD_18:
        puVar6[2] = uVar4;
switchD_001018f8_caseD_14:
        puVar6[3] = uVar4;
switchD_001018f8_caseD_10:
        puVar6[4] = uVar4;
switchD_001018f8_caseD_c:
        puVar6[5] = uVar4;
switchD_001018f8_caseD_8:
        puVar6[6] = uVar4;
switchD_001018f8_caseD_4:
        puVar6[7] = uVar4;
      }
      param_3 = param_3 & 3;
      break;
    case 4:
      goto switchD_001018f8_caseD_4;
    case 8:
      goto switchD_001018f8_caseD_8;
    case 0xc:
      goto switchD_001018f8_caseD_c;
    case 0x10:
      goto switchD_001018f8_caseD_10;
    case 0x14:
      goto switchD_001018f8_caseD_14;
    case 0x18:
      goto switchD_001018f8_caseD_18;
    case 0x1c:
      goto switchD_001018f8_caseD_1c;
    }
    if (param_3 != 2) {
      if ((int)param_3 < 3) {
        if (param_3 != 1) {
          return param_1;
        }
        goto switchD_00101669_caseD_1;
      }
      if (param_3 != 3) {
        return param_1;
      }
      *(undefined1 *)((int)puVar6 + 2) = uVar1;
    }
    *(undefined1 *)((int)puVar6 + 1) = uVar1;
switchD_00101669_caseD_1:
    *(undefined1 *)puVar6 = uVar1;
    return param_1;
  }
  puVar6 = param_1;
  switch(param_3) {
  case 1:
    goto switchD_00101669_caseD_1;
  case 2:
    goto switchD_00101669_caseD_2;
  case 3:
    *(undefined1 *)((int)param_1 + 2) = uVar1;
switchD_00101669_caseD_2:
    *(undefined2 *)param_1 = uVar2;
    return param_1;
  case 4:
    goto switchD_00101669_caseD_4;
  case 5:
    *(undefined1 *)((int)param_1 + 4) = uVar1;
    goto switchD_00101669_caseD_4;
  case 6:
    goto switchD_00101669_caseD_6;
  case 7:
    *(undefined1 *)((int)param_1 + 6) = uVar1;
switchD_00101669_caseD_6:
    *(undefined2 *)((int)param_1 + 4) = uVar2;
    goto switchD_00101669_caseD_4;
  case 8:
    goto switchD_00101669_caseD_8;
  case 9:
    *(undefined1 *)((int)param_1 + 8) = uVar1;
    goto switchD_00101669_caseD_8;
  case 10:
    goto switchD_00101669_caseD_a;
  case 0xb:
    *(undefined1 *)((int)param_1 + 10) = uVar1;
switchD_00101669_caseD_a:
    *(undefined2 *)((int)param_1 + 8) = uVar2;
    goto switchD_00101669_caseD_8;
  case 0xc:
    goto switchD_00101669_caseD_c;
  case 0xd:
    *(undefined1 *)((int)param_1 + 0xc) = uVar1;
    goto switchD_00101669_caseD_c;
  case 0xe:
    goto switchD_00101669_caseD_e;
  case 0xf:
    *(undefined1 *)((int)param_1 + 0xe) = uVar1;
switchD_00101669_caseD_e:
    *(undefined2 *)((int)param_1 + 0xc) = uVar2;
    goto switchD_00101669_caseD_c;
  case 0x10:
    goto switchD_00101669_caseD_10;
  case 0x11:
    *(undefined1 *)((int)param_1 + 0x10) = uVar1;
    goto switchD_00101669_caseD_10;
  case 0x12:
    goto switchD_00101669_caseD_12;
  case 0x13:
    *(undefined1 *)((int)param_1 + 0x12) = uVar1;
switchD_00101669_caseD_12:
    *(undefined2 *)((int)param_1 + 0x10) = uVar2;
    goto switchD_00101669_caseD_10;
  case 0x14:
    goto switchD_00101669_caseD_14;
  case 0x15:
    *(undefined1 *)((int)param_1 + 0x14) = uVar1;
    goto switchD_00101669_caseD_14;
  case 0x16:
    goto switchD_00101669_caseD_16;
  case 0x17:
    *(undefined1 *)((int)param_1 + 0x16) = uVar1;
switchD_00101669_caseD_16:
    *(undefined2 *)((int)param_1 + 0x14) = uVar2;
    goto switchD_00101669_caseD_14;
  case 0x18:
    break;
  case 0x19:
    *(undefined1 *)((int)param_1 + 0x18) = uVar1;
    break;
  case 0x1a:
    goto switchD_00101669_caseD_1a;
  case 0x1b:
    *(undefined1 *)((int)param_1 + 0x1a) = uVar1;
switchD_00101669_caseD_1a:
    *(undefined2 *)((int)param_1 + 0x18) = uVar2;
    break;
  case 0x1c:
    goto switchD_00101669_caseD_1c;
  case 0x1d:
    *(undefined1 *)((int)param_1 + 0x1c) = uVar1;
    goto switchD_00101669_caseD_1c;
  case 0x1e:
    goto switchD_00101669_caseD_1e;
  case 0x1f:
    *(undefined1 *)((int)param_1 + 0x1e) = uVar1;
switchD_00101669_caseD_1e:
    *(undefined2 *)((int)param_1 + 0x1c) = uVar2;
switchD_00101669_caseD_1c:
    *(uint *)((int)param_1 + 0x18) = uVar4;
    break;
  default:
    goto switchD_00101669_default;
  }
  *(uint *)((int)param_1 + 0x14) = uVar4;
switchD_00101669_caseD_14:
  *(uint *)((int)param_1 + 0x10) = uVar4;
switchD_00101669_caseD_10:
  *(uint *)((int)param_1 + 0xc) = uVar4;
switchD_00101669_caseD_c:
  *(uint *)((int)param_1 + 8) = uVar4;
switchD_00101669_caseD_8:
  *(uint *)((int)param_1 + 4) = uVar4;
switchD_00101669_caseD_4:
  *(uint *)param_1 = uVar4;
switchD_00101669_default:
  return param_1;
}

