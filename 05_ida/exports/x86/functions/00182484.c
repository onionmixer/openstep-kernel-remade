/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182484. */
int __cdecl kern_IOGetDriverConfig(int a1, int a2, size_t a3, void *a4, _DWORD *a5)
{
  size_t v5; // ebx
  const char *BootConfigString; // edx
  unsigned int v8; // kr04_4

  v5 = a3; /*0x18248a*/
  if ( !a1 ) /*0x182494*/
    return -705; /*0x182496*/
  if ( a3 > 0xFFF ) /*0x1824a6*/
    v5 = 4095; /*0x1824a8*/
  BootConfigString = (const char *)findBootConfigString(a2); /*0x1824b6*/
  if ( !BootConfigString ) /*0x1824bd*/
    return -704; /*0x1824bf*/
  v8 = strlen(BootConfigString) + 1; /*0x1824d2*/
  if ( v5 > v8 - 1 ) /*0x1824db*/
    v5 = v8 - 1; /*0x1824dd*/
  bcopy(BootConfigString, a4, v5); /*0x1824e2*/
  *((_BYTE *)a4 + v5) = 0; /*0x1824e7*/
  *a5 = v5 + 1; /*0x1824ef*/
  return 0; /*0x1824f6*/
}
