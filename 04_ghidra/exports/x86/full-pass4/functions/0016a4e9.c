/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a4e9 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0016a4e9(void)

{
  byte bVar1;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  uint uVar2;
  int unaff_EDI;
  uint uVar3;
  
  if (unaff_ESI == 0) {
    unaff_ESI = _page_size;
  }
  if (*(int *)(unaff_EBP + 8) == 0) {
    *(undefined4 *)(unaff_EBP + 8) = 4;
  }
  *(uint *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0xfU & 0xfffffff0;
  uVar3 = _page_mask + unaff_EDI & ~_page_mask;
  uVar2 = _page_mask + unaff_ESI & ~_page_mask;
  if (uVar3 < uVar2) {
    uVar3 = uVar2;
  }
  unaff_EBX[4] = 0;
  unaff_EBX[3] = 0;
  unaff_EBX[5] = 0;
  unaff_EBX[6] = uVar3;
  unaff_EBX[7] = *(undefined4 *)(unaff_EBP + 8);
  unaff_EBX[8] = uVar2;
  *(byte *)(unaff_EBX + 0xb) = *(byte *)(unaff_EBX + 0xb) & 0xfe | *(byte *)(unaff_EBP + 0x14) & 1;
  unaff_EBX[10] = *(undefined4 *)(unaff_EBP + 0x18);
  unaff_EBX[2] = 0;
  unaff_EBX[9] = 0;
  bVar1 = *(byte *)(unaff_EBX + 0xb);
  *(byte *)(unaff_EBX + 0xb) = bVar1 & 0xf9 | 8;
  if ((bVar1 & 1) == 0) {
    *unaff_EBX = 0;
  }
  else {
    _lock_init(unaff_EBX + 0xc);
  }
  FUN_0016af6c();
  unaff_EBX[0x10] = 0;
  do {
  } while (_all_zones_lock != 0);
  LOCK();
  UNLOCK();
  *_last_zone = unaff_EBX;
  _last_zone = unaff_EBX + 0x10;
  _num_zones = _num_zones + 1;
  LOCK();
  _all_zones_lock = 0;
  UNLOCK();
  return;
}

