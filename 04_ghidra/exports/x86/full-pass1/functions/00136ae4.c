/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136ae4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __seterr_reply(void)

{
  uint uVar1;
  int in_stack_00000004;
  uint *in_stack_00000008;
  
  if (*(int *)(in_stack_00000004 + 8) == 0) {
    uVar1 = *(uint *)(in_stack_00000004 + 0x18);
    if (uVar1 == 0) {
      *in_stack_00000008 = 0;
      return;
    }
    switch(uVar1) {
    case 1:
      *in_stack_00000008 = 8;
      break;
    case 2:
      *in_stack_00000008 = 9;
      break;
    case 3:
      *in_stack_00000008 = 10;
      break;
    case 4:
      *in_stack_00000008 = 0xb;
      break;
    case 5:
      *in_stack_00000008 = 0xc;
      break;
    default:
      *in_stack_00000008 = 0x10;
      in_stack_00000008[1] = 0;
      in_stack_00000008[2] = uVar1;
    }
  }
  else if (*(int *)(in_stack_00000004 + 8) == 1) {
    uVar1 = *(uint *)(in_stack_00000004 + 0xc);
    if (uVar1 == 0) {
      *in_stack_00000008 = 6;
    }
    else if (uVar1 == 1) {
      *in_stack_00000008 = 7;
    }
    else {
      *in_stack_00000008 = 0x10;
      in_stack_00000008[1] = 1;
      in_stack_00000008[2] = uVar1;
    }
  }
  else {
    *in_stack_00000008 = 0x10;
    in_stack_00000008[1] = *(uint *)(in_stack_00000004 + 8);
  }
  uVar1 = *in_stack_00000008;
  if (uVar1 == 7) {
    in_stack_00000008[1] = *(uint *)(in_stack_00000004 + 0x10);
  }
  else {
    if (uVar1 < 8) {
      if (uVar1 != 6) {
        return;
      }
      in_stack_00000008[1] = *(uint *)(in_stack_00000004 + 0x10);
      uVar1 = *(uint *)(in_stack_00000004 + 0x14);
    }
    else {
      if (uVar1 != 9) {
        return;
      }
      in_stack_00000008[1] = *(uint *)(in_stack_00000004 + 0x1c);
      uVar1 = *(uint *)(in_stack_00000004 + 0x20);
    }
    in_stack_00000008[2] = uVar1;
  }
  return;
}

