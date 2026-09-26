/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a0d8. */
int ipc_marequest_init()
{
  int v0; // ecx
  int v1; // eax
  _DWORD *v2; // eax
  unsigned int v3; // edx
  unsigned int i; // ecx

  if ( !ipc_marequest_size ) /*0x14a0e3*/
  {
    ipc_marequest_size = ipc_marequest_max >> 8; /*0x14a0ed*/
    if ( (unsigned int)(ipc_marequest_max >> 8) <= 0xF ) /*0x14a0f5*/
      ipc_marequest_size = 16; /*0x14a0f7*/
  }
  ipc_marequest_mask = ipc_marequest_size - 1; /*0x14a109*/
  if ( (ipc_marequest_size & (ipc_marequest_size - 1)) != 0 ) /*0x14a111*/
  {
    v0 = 1; /*0x14a113*/
    v1 = ipc_marequest_size - 1; /*0x14a118*/
    LOBYTE(v1) = (ipc_marequest_size - 1) | 1; /*0x14a11a*/
    while ( 1 ) /*0x14a129*/
    {
      ipc_marequest_mask = v1; /*0x14a129*/
      ipc_marequest_size = v1 + 1; /*0x14a131*/
      if ( ((v1 + 1) & v1) == 0 ) /*0x14a139*/
        break; /*0x14a139*/
      v0 *= 2; /*0x14a120*/
      v1 = v0 | ipc_marequest_mask; /*0x14a127*/
    }
  }
  v2 = (_DWORD *)kalloc(8 * ipc_marequest_size); /*0x14a149*/
  ipc_marequest_table = (int)v2; /*0x14a14e*/
  v3 = 0; /*0x14a153*/
  for ( i = ipc_marequest_size; v3 < i; ++v3 ) /*0x14a160*/
  {
    *v2 = 0; /*0x14a164*/
    v2[1] = 0; /*0x14a16a*/
    v2 += 2; /*0x14a171*/
  }
  ipc_marequest_zone = zinit(16, 16 * ipc_marequest_max, 16, 0, aIpcMsgAccepted); /*0x14a192*/
  return zchange(ipc_marequest_zone, 0, 0, 1, 0); /*0x14a1a5*/
}
