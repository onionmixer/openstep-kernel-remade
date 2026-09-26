
/* WARNING: Control flow encountered bad instruction data */

void gen_except(undefined4 param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  sword sVar3;
  undefined *puVar4;
  undefined4 *unaff_A6;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  uint in_FPSR;
  undefined4 uVar9;
  char in_stack_00000001;
  undefined4 in_stack_00000024;
  uint in_stack_00000034;
  undefined4 in_stack_00000040;
  uint in_stack_00000048;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_00000060;
  char acStack_8 [8];
  
  if (in_stack_00000001 != '\0') {
    puVar7 = (undefined4 *)register0x0000003c;
    if ((in_stack_00000001 == '(') || (in_stack_00000001 == '0')) {
      if (in_stack_00000001 == '(') {
        puVar4 = &stack0x000000ec;
      }
      else {
        if (in_stack_00000001 != '0') {
          return;
        }
        puVar4 = &stack0x000000f4;
      }
      *(undefined4 *)(puVar4 + -0xe4) = unaff_A6[-0x39];
      unaff_A6[-0x1f] = in_FPSR | unaff_A6[-0x1f];
    }
    else {
      if (in_stack_00000001 != '`') {
        return;
      }
      in_stack_00000058 = unaff_A6[-0x33];
      in_stack_0000005c = unaff_A6[-0x32];
      in_stack_00000060 = unaff_A6[-0x31];
      in_stack_00000040 = unaff_A6[-0x39];
      in_stack_00000034 =
           ((unaff_A6[-0x39] & 0x3fffff) >> 0x13) << 0x12 |
           ((unaff_A6[-0x39] & 0x7ffff) >> 0x12) << 0x15 | unaff_A6[-0x39] & 0x3c30000;
      unaff_A6[-0x1f] = in_FPSR | unaff_A6[-0x1f];
      in_stack_00000024 = unaff_A6[-0x1f];
      in_stack_00000048 = in_stack_00000048 | 0x1800000;
    }
    goto loc_409C064;
  }
  puVar6 = &param_1;
  puVar7 = &param_1;
  unaff_A6[-0x1f] = in_FPSR | unaff_A6[-0x1f];
  if (param_1._1_1_ == '`') {
    *(undefined2 *)(unaff_A6 + -0x3b) = 0;
    if ((*(byte *)(unaff_A6 + -0x39) & 0x20) == 0) {
      unaff_A6[-0x40] = unaff_A6[-0x1f];
      unaff_A6[-0x37] = unaff_A6[-0x37] | 0x1800000;
    }
  }
  else if (param_1._1_1_ != '(') {
    *(undefined2 *)(unaff_A6 + -0x3b) = 0;
  }
  bVar1 = *(byte *)((int)unaff_A6 + -0x7a) & *(byte *)((int)unaff_A6 + -0x7e);
  switch((bVar1 != 0) * (char)LZCOUNT((uint)bVar1 << 0x18) + (bVar1 == 0) * ' ') {
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    break;
  case :
  case :
  case :
    *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 4;
    goto loc_409BF32;
  case :
  case :
loc_409BF8A:
    if (*(char *)((int)unaff_A6 + -0x47) == '\0') {
      *(char *)((int)unaff_A6 + -0x45) = param_1._0_1_;
      if (param_1._1_1_ != '`') {
        if (param_1._0_1_ == '@') {
          sVar3 = 0xd;
        }
        else {
          if (param_1._0_1_ != 'A') {
            return;
          }
          sVar3 = 0xb;
        }
        param_1 = 0;
        puVar7 = &param_1;
        do {
          puVar5 = (undefined *)puVar7;
          puVar6 = (undefined4 *)(puVar5 + -4);
          *(undefined4 *)(puVar5 + -4) = 0;
          sVar3 = sVar3 + -1;
          puVar7 = (undefined4 *)(puVar5 + -4);
        } while (sVar3 != -1);
        puVar5[-4] = *(undefined *)((int)unaff_A6 + -0x45);
        puVar5[-3] = 0x60;
      }
      unaff_A6[-0x43] = unaff_A6[-0x1d];
      unaff_A6[-0x42] = unaff_A6[-0x1c];
      unaff_A6[-0x41] = unaff_A6[-0x1b];
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 2;
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) & 0xfb;
      *(byte *)((int)unaff_A6 + -0xdb) = *(byte *)((int)unaff_A6 + -0xdb) & 0xdf;
      unaff_A6[-0x40] = unaff_A6[-0x1f];
      unaff_A6[-0x37] = unaff_A6[-0x37] | 0x1800000;
      unaff_A6[-0x3c] =
           ((unaff_A6[-0x39] & 0x3fffff) >> 0x13) << 0x12 |
           ((unaff_A6[-0x39] & 0x7ffff) >> 0x12) << 0x15 | unaff_A6[-0x39] & 0x3c30000;
      puVar7 = puVar6;
    }
    else {
      if (*(char *)((int)unaff_A6 + -0x46) == '\0') goto loc_409BEF6;
      *(undefined *)(unaff_A6 + -0x47) = 0;
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 4;
      *(undefined2 *)(unaff_A6 + -0x36) = *(undefined2 *)(unaff_A6 + -0x33);
      unaff_A6[-0x35] = unaff_A6[-0x32];
      unaff_A6[-0x34] = unaff_A6[-0x31];
      *(byte *)(unaff_A6 + -0x38) = *(byte *)(unaff_A6 + -0x38) | 0x10;
      *(byte *)((int)unaff_A6 + -0xdb) = *(byte *)((int)unaff_A6 + -0xdb) & 0xdf;
      puVar7 = &param_1;
    }
    break;
  case :
  case :
    if (*(char *)((int)unaff_A6 + -0x47) == '\0') {
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 2;
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) & 0xfb;
    }
    else {
loc_409BEF6:
      if (*(char *)((int)unaff_A6 + -0x49) == '\0') {
        *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) | 2;
      }
      *(byte *)(unaff_A6 + -0x37) = *(byte *)(unaff_A6 + -0x37) & 0xfb;
      unaff_A6[-0x3c] =
           ((unaff_A6[-0x39] & 0x3fffff) >> 0x13) << 0x12 |
           ((unaff_A6[-0x39] & 0x7ffff) >> 0x12) << 0x15 | unaff_A6[-0x39] & 0x3c30000;
    }
loc_409BF32:
    *(byte *)((int)unaff_A6 + -0xdb) = *(byte *)((int)unaff_A6 + -0xdb) & 0xdf;
    puVar7 = &param_1;
    break;
  case :
    if (((*(byte *)((int)unaff_A6 + -0x7e) & 2) != 0) &&
       ((*(byte *)((int)unaff_A6 + -0x7a) & 0x10) != 0)) goto loc_409BF8A;
    if ((*(char *)((int)unaff_A6 + -0x47) == '\0') ||
       (puVar7 = &param_1, *(char *)((int)unaff_A6 + -0x49) == '\0')) {
      uVar9 = *(undefined4 *)(unaff_A6[-0x20] + 0x18);
      goto loc_409C0E2;
    }
    break;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
    return;
  case :
    return;
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case :
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
loc_409C064:
  if (*(char *)((int)puVar7 + 1) == '(') {
    sVar3 = 0xd;
loc_409C086:
    *(undefined *)((int)unaff_A6 + -0x45) = *(undefined *)puVar7;
    *puVar7 = 0;
    puVar2 = puVar7;
    do {
      puVar8 = (undefined *)puVar2;
      puVar7 = (undefined4 *)(puVar8 + -4);
      *(undefined4 *)(puVar8 + -4) = 0;
      sVar3 = sVar3 + -1;
      puVar2 = (undefined4 *)(puVar8 + -4);
    } while (sVar3 != -1);
    puVar8[-4] = *(undefined *)((int)unaff_A6 + -0x45);
    puVar8[-3] = 0x60;
    *(undefined4 *)(puVar8 + 0x14) = unaff_A6[-0x1d];
    *(undefined4 *)(puVar8 + 0x18) = unaff_A6[-0x1c];
    *(undefined4 *)(puVar8 + 0x1c) = unaff_A6[-0x1b];
    *(uint *)(puVar8 + 0x35) =
         *(uint *)(puVar8 + 0x35) & 0xf0ffffff | ((unaff_A6[-0x1f] & 0x7fff) >> 0xb) << 0x18;
    *(undefined4 *)(puVar8 + 0x20) = unaff_A6[-0x1f];
    *(uint *)(puVar8 + 0x44) = *(uint *)(puVar8 + 0x44) | 0x1800000;
  }
  else if (*(char *)((int)puVar7 + 1) == '0') {
    sVar3 = 0xb;
    goto loc_409C086;
  }
  uVar9 = *(undefined4 *)(unaff_A6[-0x20] + 0x18);
  restoreFPUStateFrame(*puVar7);
loc_409C0E2:
  if (((*(byte *)(unaff_A6 + 1) & 0x80) == 0) && ((*(byte *)(unaff_A6 + 1) & 0x40) == 0)) {
    fpsp_done();
    return;
  }
  puVar7 = unaff_A6 + 1;
  if (*(uint *)((int)unaff_A6 + 10) >> 0x1c == 0) {
    *unaff_A6 = unaff_A6[1];
    unaff_A6[1] = unaff_A6[2];
    saveFPUStateFrame(unaff_A6[-0x19]);
    unaff_A6[2] = uVar9;
    restoreFPUStateFrame(unaff_A6[-0x19]);
    puVar7 = unaff_A6;
  }
  *(undefined2 *)((int)puVar7 + 6) = 0x2024;
  real_trace();
  return;
}
