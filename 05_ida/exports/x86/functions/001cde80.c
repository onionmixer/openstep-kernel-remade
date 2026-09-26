/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cde80. */
int __stdcall NXPtrValueMapPrototype(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)(a1, a2, a3, a4, a5, a6, a7);
}
