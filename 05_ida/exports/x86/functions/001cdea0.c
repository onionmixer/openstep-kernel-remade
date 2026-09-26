/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdea0. */
int __usercall NXObjectMapPrototype@<eax>(int a1@<ecx>, int a2@<ebx>)
{
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  *(_BYTE *)(a2 + 8 * a1) += a2; /*0x1cdea3*/
  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}
