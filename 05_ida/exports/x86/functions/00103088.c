/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103088. */
__int16 sysacct()
{
  int *v0; // ebx
  int v1; // eax
  char v2; // dl
  int v3; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  v0 = *(int **)(dword_1E875C + 36); /*0x103095*/
  v1 = suser(); /*0x103098*/
  if ( !v1 ) /*0x10309f*/
    return v1; /*0x10309f*/
  if ( savacctp ) /*0x1030ac*/
  {
    acctp = savacctp; /*0x1030ae*/
    savacctp = 0; /*0x1030b3*/
  }
  if ( !*v0 ) /*0x1030bd*/
  {
    v1 = acctp; /*0x1030c3*/
    v5 = acctp; /*0x1030c8*/
    if ( acctp ) /*0x1030cd*/
    {
      acctp = 0; /*0x1030d3*/
      LOWORD(v1) = vn_rele(v1); /*0x1030de*/
    }
    return v1; /*0x1030e3*/
  }
  v2 = lookupname(*v0, 0, 1, 0, (int)&v5); /*0x1030f8*/
  LOWORD(v1) = dword_1E875C; /*0x1030fa*/
  *(_BYTE *)(dword_1E875C + 104) = v2; /*0x1030ff*/
  if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x10310b*/
    return v1; /*0x10310f*/
  if ( *(_DWORD *)(v5 + 40) != 1 ) /*0x103118*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 13; /*0x10311a*/
LABEL_12:
    LOWORD(v1) = vn_rele(v5); /*0x10312d*/
    return v1; /*0x103136*/
  }
  if ( (*(_BYTE *)(*(_DWORD *)(v5 + 36) + 12) & 1) != 0 ) /*0x103127*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 30; /*0x103129*/
    goto LABEL_12; /*0x103129*/
  }
  v3 = acctp; /*0x103138*/
  if ( acctp ) /*0x10313f*/
  {
    acctp = v5; /*0x103141*/
    vn_rele(v3); /*0x103148*/
  }
  else
  {
    acctp = v5; /*0x103154*/
  }
  if ( acctcred ) /*0x103161*/
    crfree(acctcred); /*0x103164*/
  v1 = crdup(*(_DWORD *)(active_u + 28)); /*0x103175*/
  acctcred = v1; /*0x10317a*/
  return v1; /*0x103182*/
}
