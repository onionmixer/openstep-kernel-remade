
void b1238_fix(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  byte bVar4;
  sword sVar3;
  byte bVar5;
  int unaff_A6;
  undefined *puVar6;
  undefined *puVar7;
  unkbyte10 in_FP0;
  unkbyte10 in_FP1;
  unkbyte10 unaff_FP2;
  unkbyte10 unaff_FP3;
  undefined4 in_stack_00000000;
  undefined4 auStack_c [3];
  
  if ((param_1._0_1_ == '@') && ((*(byte *)(unaff_A6 + -0x11c) & 0xfe) != 0)) {
    if ((*(word *)(unaff_A6 + -0xe4) & 0xe000) == 0) {
      bVar5 = (byte)((uint)(*(int *)(unaff_A6 + -0xf0) << 6) >> 0x1d);
      if ((bVar5 == (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 3) >> 0x1d)) ||
         (bVar4 = (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 6) >> 0x1d), bVar5 == bVar4)) {
        fmovem(*(undefined4 *)(unaff_A6 + -0xcc),
               1 << (7 - ((*(uint *)(unaff_A6 + -0xe4) & 0x1fffffff) >> 0x1a) & 0x1f));
        *(uint *)(unaff_A6 + -0xe4) = *(uint *)(unaff_A6 + -0xe4) & 0x3ffffff | 0x48000000;
        if ((*(byte *)(unaff_A6 + -0xcc) & 0x40) == 0) {
          *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) | 0x10;
        }
        else {
          *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) & 0xef;
        }
      }
      else {
        bVar5 = (byte)((uint)(*(int *)(unaff_A6 + -0xf4) << 6) >> 0x1d);
        if ((bVar5 == bVar4) || (bVar5 == (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 3) >> 0x1d)))
        {
          *(undefined4 *)(unaff_A6 + -0x54) = *(undefined4 *)(unaff_A6 + -0xe8);
          *(undefined4 *)(unaff_A6 + -0x50) = *(undefined4 *)(unaff_A6 + -0xe4);
          *(undefined4 *)(unaff_A6 + -0x44) = *(undefined4 *)(unaff_A6 + -0xe0);
          *(uint *)(unaff_A6 + -0x44) = *(uint *)(unaff_A6 + -0x44) & 0xe0000000;
          *(undefined *)(unaff_A6 + -0x11c) = 0;
          restoreFPUStateFrame(param_1);
          saveFPUStateFrame(param_1);
          if (param_1._0_2_ == 0x4060) {
            fpsp_fmt_error();
            return;
          }
          uVar1 = (*(uint *)(unaff_A6 + -0xf4) & 0x3ffffff) >> 0x17;
          if (uVar1 < 4) {
            if (uVar1 == 3) {
              *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
            }
            else if (uVar1 == 0) {
              *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
            }
            else if (uVar1 == 1) {
              *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
            }
            else {
              *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
            }
          }
          sVar3 = 0x16;
          puVar2 = &param_1;
          do {
            puVar6 = (undefined *)puVar2;
            *(undefined4 *)(puVar6 + -4) = 0;
            sVar3 = sVar3 + -1;
            puVar2 = (undefined4 *)(puVar6 + -4);
          } while (sVar3 != -1);
          *(undefined4 *)(puVar6 + -8) = 0x40600000;
          *(undefined4 *)(unaff_A6 + -0xe8) = *(undefined4 *)(unaff_A6 + -0x54);
          *(undefined4 *)(unaff_A6 + -0xe4) = *(undefined4 *)(unaff_A6 + -0x50);
          *(undefined4 *)(unaff_A6 + -0xe0) = *(undefined4 *)(unaff_A6 + -0x44);
          *(undefined *)(unaff_A6 + -0x11c) = 6;
          *(undefined4 *)(puVar6 + -0xc) = in_stack_00000000;
          fmovem(*(undefined4 *)(unaff_A6 + -0xcc),
                 1 << (7 - ((*(uint *)(unaff_A6 + -0xe4) & 0x1fffffff) >> 0x1a) & 0x1f));
          *(uint *)(unaff_A6 + -0xe4) = *(uint *)(unaff_A6 + -0xe4) & 0x3ffffff | 0x48000000;
          if ((*(byte *)(unaff_A6 + -0xcc) & 0x40) == 0) {
            *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) | 0x10;
          }
          else {
            *(byte *)(unaff_A6 + -0xe8) = *(byte *)(unaff_A6 + -0xe8) & 0xef;
          }
        }
      }
    }
    else if ((*(word *)(unaff_A6 + -0xe4) & 0xfc00) == 0x4400) {
      bVar5 = (byte)((uint)(*(int *)(unaff_A6 + -0xe4) << 6) >> 0x1d);
      if ((byte)((uint)(*(int *)(unaff_A6 + -0xf0) << 6) >> 0x1d) != bVar5) {
        if ((byte)((uint)(*(int *)(unaff_A6 + -0xf4) << 6) >> 0x1d) != bVar5) {
          return;
        }
        *(undefined4 *)(unaff_A6 + -0x54) = *(undefined4 *)(unaff_A6 + -0xe8);
        *(undefined4 *)(unaff_A6 + -0x50) = *(undefined4 *)(unaff_A6 + -0xe4);
        *(undefined4 *)(unaff_A6 + -0x44) = *(undefined4 *)(unaff_A6 + -0xe0);
        *(uint *)(unaff_A6 + -0x44) = *(uint *)(unaff_A6 + -0x44) & 0xe0000000;
        *(undefined *)(unaff_A6 + -0x11c) = 0;
        *(undefined4 *)(unaff_A6 + -100) = *(undefined4 *)(unaff_A6 + -0xcc);
        *(undefined4 *)(unaff_A6 + -0x60) = *(undefined4 *)(unaff_A6 + -200);
        *(undefined4 *)(unaff_A6 + -0x5c) = *(undefined4 *)(unaff_A6 + -0xc4);
        restoreFPUStateFrame(param_1);
        saveFPUStateFrame(param_1);
        if (param_1._0_2_ == 0x4060) {
          fpsp_fmt_error();
          return;
        }
        uVar1 = (*(uint *)(unaff_A6 + -0xf4) & 0x3ffffff) >> 0x17;
        if (uVar1 < 4) {
          if (uVar1 == 3) {
            *(unkbyte10 *)(unaff_A6 + -0x8c) = unaff_FP3;
          }
          else if (uVar1 == 0) {
            *(unkbyte10 *)(unaff_A6 + -0xb0) = in_FP0;
          }
          else if (uVar1 == 1) {
            *(unkbyte10 *)(unaff_A6 + -0xa4) = in_FP1;
          }
          else {
            *(unkbyte10 *)(unaff_A6 + -0x98) = unaff_FP2;
          }
        }
        sVar3 = 0x16;
        puVar2 = &param_1;
        do {
          puVar7 = (undefined *)puVar2;
          *(undefined4 *)(puVar7 + -4) = 0;
          sVar3 = sVar3 + -1;
          puVar2 = (undefined4 *)(puVar7 + -4);
        } while (sVar3 != -1);
        *(undefined4 *)(puVar7 + -8) = 0x40600000;
        *(undefined4 *)(unaff_A6 + -0xe8) = *(undefined4 *)(unaff_A6 + -0x54);
        *(undefined4 *)(unaff_A6 + -0xe4) = *(undefined4 *)(unaff_A6 + -0x50);
        *(undefined4 *)(unaff_A6 + -0xe0) = *(undefined4 *)(unaff_A6 + -0x44);
        *(undefined *)(unaff_A6 + -0x11c) = 6;
        *(undefined4 *)(unaff_A6 + -0xcc) = *(undefined4 *)(unaff_A6 + -100);
        *(undefined4 *)(unaff_A6 + -200) = *(undefined4 *)(unaff_A6 + -0x60);
        *(undefined4 *)(unaff_A6 + -0xc4) = *(undefined4 *)(unaff_A6 + -0x5c);
        *(undefined4 *)(puVar7 + -0xc) = in_stack_00000000;
      }
      *(uint *)(unaff_A6 + -0xe4) = *(uint *)(unaff_A6 + -0xe4) & 0x3ffffff | 0x54000000;
      if (*(sword *)(unaff_A6 + -0xcc) == 0x407f) {
        *(undefined2 *)(unaff_A6 + -0xcc) = 0x43ff;
      }
      else if (*(sword *)(unaff_A6 + -0xcc) == -0x3f81) {
        *(undefined2 *)(unaff_A6 + -0xcc) = 0xc3ff;
      }
      else if (*(sword *)(unaff_A6 + -0xcc) == 0x3f80) {
        *(undefined2 *)(unaff_A6 + -0xcc) = 0x3c00;
      }
      else if (*(sword *)(unaff_A6 + -0xcc) == -0x4080) {
        *(undefined2 *)(unaff_A6 + -0xcc) = 0xbc00;
      }
    }
  }
  return;
}
