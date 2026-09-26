/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136b64 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=orphan_instruction_fragment.
   Context recorded in gap-actions.json. */

void __regparm3 __analysis_fragment_00136b64(undefined4 param_1,uint *param_2,int param_3)

{
  uint uVar1;
  
  *param_2 = 0;
  uVar1 = *param_2;
  if (uVar1 == 7) {
    param_2[1] = *(uint *)(param_3 + 0x10);
  }
  else {
    if (uVar1 < 8) {
      if (uVar1 != 6) {
        return;
      }
      param_2[1] = *(uint *)(param_3 + 0x10);
      uVar1 = *(uint *)(param_3 + 0x14);
    }
    else {
      if (uVar1 != 9) {
        return;
      }
      param_2[1] = *(uint *)(param_3 + 0x1c);
      uVar1 = *(uint *)(param_3 + 0x20);
    }
    param_2[2] = uVar1;
  }
  return;
}

