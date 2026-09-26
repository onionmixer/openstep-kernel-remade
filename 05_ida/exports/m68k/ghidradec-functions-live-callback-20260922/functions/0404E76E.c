
undefined8 _timeval_to_ns_time(int *param_1)

{
  uint uVar1;
  sqword sVar2;
  int iVar3;
  
  sVar2 = (sqword)*param_1 * 1000000 + CONCAT44((int)-(param_1[1] < 0),param_1[1]);
  uVar1 = (uint)sVar2;
  iVar3 = (int)((qword)sVar2 >> 0x20);
  sVar2 = sVar2 + CONCAT44((((iVar3 << 5 | uVar1 >> 0x1b) - ((uint)(uVar1 * 0x20 < uVar1) + iVar3))
                            * 2 + (uint)CARRY4(uVar1 * 0x1f,uVar1 * 0x1f)) * 2 +
                           (uint)CARRY4(uVar1 * 0x3e,uVar1 * 0x3e),uVar1 * 0x7c);
  uVar1 = (uint)sVar2;
  return CONCAT44((((int)((qword)sVar2 >> 0x20) * 2 + (uint)CARRY4(uVar1,uVar1)) * 2 +
                  (uint)CARRY4(uVar1 * 2,uVar1 * 2)) * 2 + (uint)CARRY4(uVar1 * 4,uVar1 * 4),
                  uVar1 * 8);
}

