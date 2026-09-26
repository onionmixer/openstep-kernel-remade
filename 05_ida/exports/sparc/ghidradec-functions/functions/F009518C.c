
/* WARNING: Removing unreachable block (ram,0xf0095208) */
/* WARNING: Removing unreachable block (ram,0xf00951f8) */

void _fp_exception(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined in_fq0 [16];
  undefined4 in_fsr;
  
  iVar1 = _fp_ctxp;
  *(undefined4 *)(_fp_ctxp + 0x80) = in_fsr;
  uVar3 = (*(uint *)(iVar1 + 0x80) & 0x1c000) >> 0xe;
  uVar2 = 0;
  while ((*(uint *)(iVar1 + 0x80) & 0x2000) != 0) {
    *(undefined (*) [16])(iVar1 + 0x90 + uVar2) = in_fq0;
    uVar2 = uVar2 + 8;
    *(undefined4 *)(iVar1 + 0x80) = in_fsr;
  }
  if (3 < uVar3) {
    _panic(aUnexpectedFloa,uVar3);
  }
  *(uint *)(iVar1 + 0x8c) = uVar2 >> 3;
  _fp_runq(&stack0x0000005c);
  *(uint *)(iVar1 + 0x80) = *(uint *)(iVar1 + 0x80) & 0xfffe1fff;
  sys_rtt();
  return;
}
