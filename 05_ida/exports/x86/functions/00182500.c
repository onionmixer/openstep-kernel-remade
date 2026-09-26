/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182500. */
int __cdecl kern_IOGetSystemConfig(int a1, size_t a2, void *a3, _DWORD *a4)
{
  size_t v4; // ebx
  const char *BootConfigString; // edx
  unsigned int v7; // kr04_4

  v4 = a2; /*0x182509*/
  if ( !a1 ) /*0x182510*/
    return -705; /*0x182512*/
  if ( a2 > 0xFFF ) /*0x182522*/
    v4 = 4095; /*0x182524*/
  BootConfigString = (const char *)findBootConfigString(0); /*0x182530*/
  if ( !BootConfigString ) /*0x182537*/
    return -704; /*0x182539*/
  v7 = strlen(BootConfigString) + 1; /*0x18254a*/
  if ( v4 > v7 - 1 ) /*0x182553*/
    v4 = v7 - 1; /*0x182555*/
  bcopy(BootConfigString, a3, v4); /*0x18255a*/
  *((_BYTE *)a3 + v4) = 0; /*0x18255f*/
  *a4 = v4 + 1; /*0x182567*/
  return 0; /*0x18256e*/
}
