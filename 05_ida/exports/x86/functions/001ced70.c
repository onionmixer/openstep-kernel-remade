/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ced70. */
Class __cdecl objc_lookUpClass(const char *name)
{
  _BYTE data[8]; // [esp+0h] [ebp-28h] BYREF
  const char *v3; // [esp+8h] [ebp-20h]

  v3 = name; /*0x1ced79*/
  return (Class)NXHashGet(dword_1E5600, data); /*0x1ced8c*/
}
