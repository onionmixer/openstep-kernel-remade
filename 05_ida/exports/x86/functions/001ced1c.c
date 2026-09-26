/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ced1c. */
Class __cdecl objc_getClass(const char *name)
{
  objc_class *v1; // ebx
  _BYTE data[8]; // [esp+Ch] [ebp-28h] BYREF
  const char *v4; // [esp+14h] [ebp-20h]

  v4 = name; /*0x1ced28*/
  v1 = (objc_class *)NXHashGet(dword_1E5600, data); /*0x1ced3b*/
  if ( !v1 && off_1E561C((int)name) ) /*0x1ced4a*/
    return (Class)NXHashGet(dword_1E5600, data); /*0x1ced60*/
  return v1; /*0x1ced67*/
}
